/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "Viewport.h"

#include "OpenInfraPlatform/DataManagement/Data.h"
#include "OpenInfraPlatform/DataManagement/Command/SelectAlignment.h"
#include "TerrainMeshBuilder.h"
#include "CoordinateSystem.h"
#include "OpenInfraPlatform/Infrastructure/Import/LandXmlImport.h"
#include "buw.BlueEngine.h"
#include "buw.BlueImageProcessing.color.h"
#include "buw.BlueImageProcessing.colorConstants.h"
BLUE_DROP_COMPILER_LEVEL_TO_3
#include <QTimer>
BLUE_RESTORE_COMPILER_WARNING_LEVEL
#include <QtXml>
#include <QtXmlPatterns>
#include <iomanip>
#include "OpenInfraPlatform/Benchmark.h"

namespace buw
{
	buw::matrix44f createAutodeskToGLMatrix()
	{
		buw::matrix44f m = buw::createIdentity44f();

		m.set(1, 0, 0, 0,
			0, 0, 1, 0,
			0, -1, 0, 0,
			0, 0, 0, 1);

		return m;
	}
}

OpenInfraPlatform::UserInterface::Viewport::Viewport(const buw::renderWindowsDescription& rwd, QWidget* parent /*= 0*/) :
renderSystem_(nullptr),
renderContext_(nullptr),
infraCamera_(),
infraCameraController_(),
bContinuousRendering_(true),
view_(buw::eView::ThreeDimensional),
drawSkybox_(false),
showCrossSection_(false),
showDesignCrossSection_(false),
connectCrossSections_(false),
doSolidCrossSections_(false),
drawRoadTexture_(false),
bTerrainTextured_(false),
bTerrainUseColorRamp_(false),
bTerrainDisplayIsoLines_(false),
bCreatePoints_(false),
bHighlightDifferentAlignmentElements_(false),
clearColor_(0.3f, 0.5f, 0.9f),
gradientClear_(true),
projectionType_(buw::eProjectionType::Perspective),
blueMap_(nullptr),
enableBlueMap_(false),
pickColor(0, 0, 0, 1),
selectedAlignmentIndex_(0),
hoveredAlignmentIndex_(-1),
bHighlightSelectedAlignmentSegment_(true),
skybox_(nullptr),
bShowViewCube_(true),
pointSize_(3),
bUseUniformPointColor_(false),
bUseUniformPointSize_(false),
bShowFrameTimes_(false)
{
	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_MSWindowsUseDirect3D, true);
	setFocusPolicy(Qt::StrongFocus);

	// mouse move event should also occur if the user doesn't press a mouse button
	setMouseTracking(true);

	createRenderSystem(rwd);

	createGraphicResources();

	// create 3D UI Element
	// create3DUIElement();

	// setup camera
	infraCamera_ = buw::InfraCamera::create();
	viewCube_ = std::make_shared<buw::ViewCube>(renderSystem_);

	std::function<void()> startConinuous = std::bind(&OpenInfraPlatform::UserInterface::Viewport::startContinuousRendering, this);
	std::function<void()> stopConinuous = std::bind(&OpenInfraPlatform::UserInterface::Viewport::stopContinuousRendering, this);

	infraCameraController_ = buw::InfraCameraController::create(startConinuous, stopConinuous);
	infraCameraController_->setCamera(infraCamera_);
	infraCameraController_->gotoDefault();

	updateFrustumProjection();
	
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().Change.connect(boost::bind(&Viewport::onChange, this));
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().Clear.connect(boost::bind(&Viewport::onClear, this));
	
	triangleShader_ = renderSystem_->createShader("Shader/VertexCacheTriangle.be");
	vertexCacheAlignmentTriangle_ = std::make_shared<buw::VertexCacheTriangle>(renderSystem_, triangleShader_, 1000000);
	vertexCacheAlignmentTriangle_->setColor(0.0f, 1.0f, 0.0f);

	vertexCacheIfcGeometry_ = std::make_shared<buw::VertexCacheTriangleT<VertexLayout>>(renderSystem_, triangleShader_, 10000000);
	vertexCacheIfcPolylines_ = std::make_shared<buw::RoadDesignVCL>(renderSystem_, "Shader/VertexCacheLineAlignment.be","Shader/VertexCacheLineAlignmentPick.be", 2000000);
	vertexCacheIfcPolylines_->setColor(1.0f, 1.0f, 1.0f);


	triangleShaderP3C3N3UV2_ = renderSystem_->createShader("Shader/VertexCacheTriangleTextured.be");
	triangleCacheP3C3N3UV2_ = std::make_shared<buw::VertexCacheTriangleT<buw::VertexPosition3Color3Normal3Texture2>>(renderSystem_, triangleShaderP3C3N3UV2_, 100000);

	vertexCacheAlignmentLine_ = std::make_shared<buw::RoadDesignVCL>(renderSystem_, "Shader/VertexCacheLineAlignment.be", "Shader/VertexCacheLineAlignmentPick.be", 2000000);
	vertexCacheAlignmentLine_->setColor(0.0f, 1.0f, 0.0f);

	vertexCacheAlignmentPoint_ = std::make_shared<buw::RoadDesignVCP>(renderSystem_, "Shader/VertexCachePoint.be", 2000000);
	vertexCacheAlignmentPoint_->setColor(1.0f, 0.0f, 0.0f);

	shaderLaserScan_ = renderSystem_->createShader("Shader/LaserScanPoint.be");
	shaderLaserScan_->setValue("bUseUniformPointColor", false);
	shaderLaserScan_->setValue("bUseUniformPointSize", false);
	vertexCachePointLaserScan_ = std::make_shared<buw::VertexCachePointT<buw::VertexPosition3Color3>>(renderSystem_, shaderLaserScan_, 100);

	bDrawTerrainWireframe_ = false;
	bHideTerrain_ = false;

	fillVertexCacheUIElements();
	
	drawNextFrame();

	createDeferredRenderTargets();
	createPickBufferRenderTarget();
	createCpuReadTexture();

	// createViewCube
	viewCube_->SelectionChanged.connect(
		boost::bind(&Viewport::onViewCubeSelectionChanged, this, _1)
	);

	toolManager_ = std::make_shared<ToolManager>(vertexCachePointDebug_);
}

OpenInfraPlatform::UserInterface::Viewport::~Viewport()
{
	viewCube_ = nullptr;

	vertexCachePointLaserScan_ = nullptr;
	vertexCacheLineUIElements = nullptr;
	vertexCacheAlignmentPoint_ = nullptr;
	vertexCacheAlignmentLine_ = nullptr;
	vertexCacheAlignmentTriangle_ = nullptr;
	vertexCacheIfcGeometry_ = nullptr;
	vertexCacheIfcPolylines_ = nullptr;

	shaderGradientQuad_ = nullptr;
	triangleShader_ = nullptr;
	shaderDigitalElevationModel_ = nullptr;
	shaderDigitalElevationModelColorRamp_ = nullptr;
	shaderDigitalElevationModelColorRamp_ = nullptr;
	shaderLaserScan_ = nullptr;
	cpuReadTexture_ = nullptr;
	terrainTexture_ = nullptr;
}

void OpenInfraPlatform::UserInterface::Viewport::paintEvent(QPaintEvent * paintEvent)
{
	long long preFrame = performanceTimer_.getElapsedMicroseconds();

	// setup matrices
	buw::matrix44f projection = infraCamera_->getProjectionMatrix();
	buw::matrix44f rotation = infraCamera_->getViewRotationMatrix();
	buw::matrix44f world = buw::createScale44f(0.02f) *	buw::createAutodeskToGLMatrix();
	buw::matrix44f worldIT = (buw::createInverse44f(world)).transpose();
	buw::matrix44f viewProjection = infraCamera_->getViewProjectionMatrix(); //infraCamera_->getProjectionMatrixRS() * getWorldSpaceToViewSpaceTransformationEx();

	buw::vertexCacheLineShaderData vcsd;
	vcsd.frustum = buw::vector4f(
		infraCamera_->frustum().width(),
		infraCamera_->frustum().height(),
		infraCamera_->frustum().nearPlane(),
		infraCamera_->frustum().farPlane()
		);
	vcsd.world = world;
	vcsd.viewport = buw::vector2f(width(), height());
	vcsd.view = infraCamera_->getViewMatrix(); //getWorldSpaceToViewSpaceTransformationEx();
	vcsd.projection = projection;
	vcsd.ortho = infraCamera_->frustum().projection() == buw::InfraCamera::CameraFrustum::ProjectionType::ORTHOGRAPHIC;;

	buw::pointVertexCacheShaderData vcpsd;
	vcpsd.world = world;
	vcpsd.viewport = buw::vector2f(width(), height());
	vcpsd.view = infraCamera_->getViewMatrix(); // getWorldSpaceToViewSpaceTransformationEx();
	vcpsd.projection = projection;


	// clear
	clearColor_ = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getClearColor();

	float color[] = { clearColor_.red(), clearColor_.green(), clearColor_.blue(), 0.0f };

	auto viewCubeProjection = BlueFramework::Core::Math::createD3DLikeMatrixPerspectiveFovRH(buw::degreeToRadian(55.0f), 1.0f, 0.01f, 1000.0f);
	auto viewCubeView = buw::createTranslation44f(0, 0, -20) *
		rotation *
		buw::createScale44f(5.0f * 0.375f);
	auto viewCubeWorld = buw::createIdentity44f();

	// set pick buffer
	renderContext_->setRenderTarget(renderTargetPickBuffer_);

	// now render to pick buffer
	clearPickColor = buw::vector4f(1.0f, 0.5f, 0.9f, 0.0f);
	renderContext_->clear(buw::eClearFlags::Color | buw::eClearFlags::Depth, &(clearPickColor[0]));

	renderContext_->setViewport(
		(width() - 100),
		0,
		width() - (width() - 100),
		height() - (height() - 100));

	if (bShowViewCube_)
	{
		viewCube_->renderPickBuffer(
			viewCubeWorld,
			viewCubeProjection,
			viewCubeView,
			renderContext_);
	}

	renderContext_->setViewport(width(), height());
	vertexCacheAlignmentLine_->flushPickShader(vcsd);


	//-------------------------------------------------------------------------
	// now render to back buffer
	renderContext_->setRenderTarget(renderContext_->getBackBufferRenderTarget());
	renderContext_->clear(buw::eClearFlags::Color | buw::eClearFlags::Depth, color);
	if (gradientClear_)
	{
		renderContext_->setDepthStencilState(ddsDisableDepthWrite_);
		drawFullScreenQuad();
		renderContext_->setDepthStencilState(dssDefault_);
	}

	// Store pick buffer as 
	//buw::ReferenceCounted<buw::IDebugVisualizer> dv = renderSystem_->createDebugVisualizer();
	//dv->saveAs("test.png", renderTargetPickBuffer_);	

	if (drawSkybox_)
	{
		// https://github.com/SimonWallner/kocmoc-demo/tree/RTVIS
		buw::matrix44f world2 =
			rotation *
			buw::createScale44f(0.02f);

		if (skybox_ == nullptr)
		{
			createSkyboxResources();
		}

		skybox_->render(infraCamera_->getProjectionMatrix() * rotation * buw::createScale44f(12), buw::vector3f(0, 0, 0) /*frustum_.GetPosition()*/);
	}

	// draw DigitalElevationModel   
	if (!bHideTerrain_)
	{
		if (bDrawTerrainWireframe_)
		{
			renderContext_->setRasterizerState(rsWireframeFill_);
		}

		drawTerrain();

		if (bDrawTerrainWireframe_)
		{
			renderContext_->setRasterizerState(rsSolidFill_);
		}
	}
	

	// draw alignment lines
	int index = bHighlightSelectedAlignmentSegment_ ? selectedAlignmentIndex_ : -1;
	vertexCacheAlignmentLine_->flush(vcsd, index, hoveredAlignmentIndex_);

	// draw alignment points
	vertexCacheAlignmentPoint_->flush(vcpsd);

	// draw triangles
	if (vertexCacheAlignmentTriangle_->getCurrentVertexCount() > 0)
	{
		triangleShader_->setValue("World", world);
		triangleShader_->setValue("WorldIT", worldIT);
		triangleShader_->setValue("WorldViewProjection", viewProjection * world);
		triangleShader_->setValue("g_EyePosition", infraCamera_->getEyePosition().xyz()); // needs to be a vector3f since HLSL/GLSL expects this
		vertexCacheAlignmentTriangle_->flush(triangleShader_);
	}

	// draw ifc lines
	vertexCacheIfcPolylines_->flush(vcsd, -1, -1);

	// draw ifc triangles
	if (vertexCacheIfcGeometry_->getMaxVerticesCount() > 0)
	{
		triangleShader_->setValue("World", world);
		triangleShader_->setValue("WorldIT", worldIT);
		triangleShader_->setValue("WorldViewProjection", viewProjection * world);
		triangleShader_->setValue("g_EyePosition", infraCamera_->getEyePosition().xyz()); // needs to be a vector3f since HLSL/GLSL expects this
		vertexCacheIfcGeometry_->flush(triangleShader_);
	}

	// draw new triangles
	if (triangleCacheP3C3N3UV2_->getMaxVerticesCount() > 0)
	{
		triangleShaderP3C3N3UV2_->setValue("World", world);
		triangleShaderP3C3N3UV2_->setValue("WorldIT", worldIT);
		triangleShaderP3C3N3UV2_->setValue("WorldViewProjection", viewProjection * world);
		triangleShaderP3C3N3UV2_->setSampler("sampler_", sampler_);
		triangleShaderP3C3N3UV2_->setValue("g_EyePosition", infraCamera_->getEyePosition().xyz());
		triangleShaderP3C3N3UV2_->setValue("bTextured", drawRoadTexture_);

		if (drawRoadTexture_)
			triangleShaderP3C3N3UV2_->setValue("texDiffuseMap", roadTexture_);

		triangleCacheP3C3N3UV2_->flush(triangleShaderP3C3N3UV2_);
	}
	
	if (bCreatePoints_)
	{
		vertexCacheAlignmentEditorPoint_->flush(vcpsd);
		vertexCacheAlignmentEditorLine_->flush(vcsd, -1, -1);
	}

	// draw laser scan points
	if (vertexCachePointLaserScan_->getCurrentVertexCount() > 0)
	{
		shaderLaserScan_->setValue("World", world);
		shaderLaserScan_->setValue("Viewport", buw::vector2f(width(), height()));
		shaderLaserScan_->setValue("View", infraCamera_->getViewMatrix());
		shaderLaserScan_->setValue("Projection", projection);

		buw::vector4f positions[4];
		positions[0] = buw::vector4f(-0.5, 0.5, 0, 0);
		positions[1] = buw::vector4f(0.5, 0.5, 0, 0);
		positions[2] = buw::vector4f(-0.5, -0.5, 0, 0);
		positions[3] = buw::vector4f(0.5, -0.5, 0, 0);

		shaderLaserScan_->setValue("Positions", &positions[0], 4);

		shaderLaserScan_->setValue("bUseUniformPointColor", bUseUniformPointColor_);

		shaderLaserScan_->setValue("pointSize", pointSize_);
		shaderLaserScan_->setValue("bUseUniformPointSize", bUseUniformPointSize_);

		vertexCachePointLaserScan_->flush(shaderLaserScan_);
	}

	// draw breakLines
	for (buw::ReferenceCounted<buw::VertexCacheLine> vcl : vertexCacheLineBreakLines_)
	{
		vcl->flush(vcsd);
	}

	//-------------------------------------------------------------------------
	// draw debug buffer
	buw::pointVertexCacheShaderData pvcsdD;
	pvcsdD.world = world;
	pvcsdD.projection = infraCamera_->getProjectionMatrix();
	pvcsdD.view = infraCamera_->getViewMatrix(); // getWorldSpaceToViewSpaceTransformation();
	pvcsdD.viewport = buw::vector2f(width(), height());

	vertexCachePointDebug_->flush(pvcsdD);

	buw::vertexCacheLineShaderData vcsdD;
	vcsdD.world = world;
	vcsdD.projection = infraCamera_->getProjectionMatrix();
	vcsdD.view = infraCamera_->getViewMatrix(); // getWorldSpaceToViewSpaceTransformation();
	vcsdD.viewport = buw::vector2f(width(), height());
	vcsdD.ortho = infraCamera_->frustum().projection() == buw::InfraCamera::CameraFrustum::ProjectionType::ORTHOGRAPHIC;
	vcsdD.frustum = buw::vector4f(
		infraCamera_->frustum().width(),
		infraCamera_->frustum().height(),
		infraCamera_->frustum().nearPlane(),
		infraCamera_->frustum().farPlane()
		);

	vertexCacheLineDebug_->flush(vcsdD);

	// draw coordinate system and grid
	vcsd.frustum = buw::vector4f(
		infraCamera_->frustum().width(),
		infraCamera_->frustum().height(),
		infraCamera_->frustum().nearPlane(),
		infraCamera_->frustum().farPlane()
		);
	vcsd.projection = projection;
	vcsd.view = infraCamera_->getViewMatrix(); // getWorldSpaceToViewSpaceTransformationEx();
	vcsd.viewport = buw::vector2f(width(), height());
	vcsd.world = buw::createScale44f(0.02f);
	vertexCacheLineUIElements->flush(vcsd);

	if (bShowHud)
	{
		hud_->render(width(), height());
	}

	if (enableBlueMap_)
	{
		blueMap_->draw(width(), height());
	}

	// Render text
	if (bShowFrameTimes_)
	{
		buw::matrix44f m;

		m = buw::createTranslation44f(-1.0f, 1.0f, 0.0f) *
			buw::createScale44f(2.0f / width(), -2.0f / height(), 1.0f);

		std::wstringstream t;
		t << "Frame time: " << frameTime_ << " ms\nTime between two frames: " << sinceLastFrame_ << " ms";
		text_->setText(t.str());

		text_->draw(m);
	}

	RenderBridge();

	//-------------------------------------------------------------------------
	// Draw view cube in left top corner

	if (bShowViewCube_)
	{
		renderContext_->setDepthStencilState(ddsDisableDepthTest_);
		renderContext_->setRasterizerState(rsCullBackFaces_);
		renderContext_->setViewport(
			(width() - 100),
			0,
			width() - (width() - 100),
			height() - (height() - 100));

		viewCube_->render(
			viewCubeWorld,
			viewCubeProjection,
			viewCubeView,
			renderContext_);

		renderContext_->setDepthStencilState(dssDefault_);
		renderContext_->setRasterizerState(rsDefault_);
	}

	renderContext_->setRenderTarget(renderTargetGBuffer_);
	float color3 [] = { 1, 0, 0, 0 };
	renderContext_->clear(buw::eClearFlags::Color | buw::eClearFlags::Depth, color3);
	renderContext_->setViewport(width(), height());
	fillGBuffer();
	
	// flip
	renderSystem_->swap();

	long long postFrame = performanceTimer_.getElapsedMicroseconds();

	frameTime_ = (postFrame - preFrame) / 1000.0;
	sinceLastFrame_ = (preFrame - lastPreFrame_) / 1000.0;

	lastPreFrame_ = preFrame;
}

void OpenInfraPlatform::UserInterface::Viewport::startContinuousRendering()
{
	if (!bContinuousRendering_)
	{
		bContinuousRendering_ = true;
		lastTick_ = GetTickCount();

		drawNextFrame();
	}
}

void OpenInfraPlatform::UserInterface::Viewport::stopContinuousRendering()
{
	bContinuousRendering_ = false;

	repaint(); // also needed! - do never ever remove this line!!!
}

void OpenInfraPlatform::UserInterface::Viewport::drawNextFrame()
{
	unsigned long tick = GetTickCount();
	double delta = (tick - lastTick_) / 1000.f;

	infraCameraController_->tick(delta);
	lastTick_ = tick;

	repaint();

	if (bContinuousRendering_)
	{
		QTimer::singleShot(0, this, SLOT(drawNextFrame()));
	}
}

void OpenInfraPlatform::UserInterface::Viewport::forceRepaint()
{
	if (!bContinuousRendering_)
	{
		repaint();
		repaint(); // This is not a mistake. Needs to be called two times - do never ever remove this line!!!

#ifdef DETECTED_OS_APPLE
		QCoreApplication::processEvents();
#endif
	}
}

QPaintEngine* OpenInfraPlatform::UserInterface::Viewport::paintEngine() const
{
	return nullptr;
}

void OpenInfraPlatform::UserInterface::Viewport::resizeEvent(QResizeEvent *)
{
	int width = this->width();
	int height = this->height();

	if (width == 0)
	{
		width = 1;
	}

	if (height == 0)
	{
		height = 1;
	}

	createPickBufferRenderTarget();
	createDeferredRenderTargets();

	renderContext_->setViewport(0, 0, width, height);
	renderContext_->setRenderTarget(renderContext_->getBackBufferRenderTarget());
	renderContext_->resizeRenderTarget(width, height);

	updateFrustumProjection();

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::onChange()
{
	onChange(OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getLatesChangeFlag());
}

void OpenInfraPlatform::UserInterface::Viewport::onChange(ChangeFlag changeFlag)
{	
	auto& data = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData();

	if (changeFlag & ChangeFlag::Preferences)
	{
		gradientClear_ = data.isGradientClearEnabled();
		bShowViewCube_ = data.isViewCubeEnabled();
		drawSkybox_ = data.isSkyboxEnabled();
		selectedAlignmentIndex_ = data.getSelectedAlignment();

		showFrameTimes(data.showFrameTimes());

		fillVertexCacheUIElements();
	}

	if (changeFlag & ChangeFlag::DigitalElevationModel)
	{
		createDigitalElevationModel();
	}

	if (changeFlag & ChangeFlag::AlignmentModel)
	{
		createAlignment();
	}


	// fixme: Simple assumtion: Only update when point count changed - of course this does not work always -- Fixed
	if (changeFlag & ChangeFlag::PointCloud)
	{
		vertexCachePointLaserScan_->clear();

		vertexCachePointLaserScan_ = std::make_shared<buw::VertexCachePointT<buw::VertexPosition3Color3>>(renderSystem_, shaderLaserScan_, data.getPointCloudPointCount() + 100);
		const std::vector<buw::LaserPoint>& x = data.getPointCloud();
		
		buw::vector3d offset = getOffset();

		int progressstep = data.getPointCloudPointCount() / 100;

		for (int i = 0; i < data.getPointCloudPointCount(); i++)
		{
			buw::VertexPosition3Color3 point;
			point.position = buw::vector3f(x[i].position - offset);
			point.color = x[i].color;

			vertexCachePointLaserScan_->drawPoint(point);

			if (i % progressstep == 0)
				printf("done %f percent\n", i * 100.f / data.getPointCloudPointCount());
		}
	}

	if (changeFlag & ChangeFlag::IfcGeometry)
	{
		auto ifcGeometryModel = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getIfcGeometryModel();
		if (ifcGeometryModel != nullptr) { createIfcGeometry(ifcGeometryModel); }
	}

	forceRepaint();
}

float OpenInfraPlatform::UserInterface::Viewport::getAspectRatio() const
{
	if (height() == 0)
	{
		return width();
	}

	return static_cast<float>(width()) / static_cast<float>(height());
}

void OpenInfraPlatform::UserInterface::Viewport::createRenderSystem(const buw::renderWindowsDescription& rwd)
{
	try
	{
		// create render system
		buw::renderSystemDescription rsd;
		rsd.enableMSAA = rwd.enableMSAA;
		rsd.sampleCount = rwd.sampleCount;
		rsd.height = height();
		rsd.width = width();
		rsd.windowId = (int)this->winId();
		rsd.majorVersion = rwd.majorVersion;
		rsd.miniorVersion = rwd.miniorVersion;
		rsd.enableDebugLayer = true;// rwd.enableDebugLayer;
		rsd.enableMultithreading = rwd.enableMultithreading;
		rsd.renderSystem = rwd.renderSystem;
		rsd.d3dFeatureLevel = rwd.d3dFeatureLevel;
		rsd.windowed = true;

		renderSystem_ = buw::createRenderSystem(rsd);

		renderContext_ = renderSystem_->getImmediateContext();
	}
	catch (... /*buw::Exception& e*/)
	{
		// try to create a render system using FeatureLevel 10_0
		buw::renderSystemDescription rsd;
		rsd.enableMSAA = rwd.enableMSAA;
		rsd.sampleCount = rwd.sampleCount;
		rsd.height = height();
		rsd.width = width();
		rsd.windowId = (int)this->winId();
		rsd.majorVersion = 11;
		rsd.miniorVersion = 0;
		rsd.enableMultithreading = false;
		rsd.enableDebugLayer = false;//true;//
		rsd.renderSystem = buw::eRenderSystem::Direct3D11;
		rsd.d3dFeatureLevel = buw::eD3D11FeatureLevel::FeatureLevel10_0;
		rsd.windowed = true;

		renderSystem_ = buw::createRenderSystem(rsd);

		renderContext_ = renderSystem_->getImmediateContext();

		// todo add fallback to opengl
	}
}

void OpenInfraPlatform::UserInterface::Viewport::mousePressEvent(QMouseEvent *event)
{
	toolManager_->mousePressEvent(event);

	viewCube_->mousePressEvent(pickColor);

	if (event->button() & Qt::LeftButton)
	{
		if (event->modifiers() & Qt::CTRL)
		{
			if (bCreatePoints_)
			{
				buw::vector3f vStart, vEnd;
				pick(event->x(), event->y(), vStart, vEnd);

				buw::plane3d p(buw::vector3d(0, 0, 1), buw::vector3d(0, 0, 0));
				BlueFramework::Core::Math::ray3d pickRay(
					buw::vector3d(vStart.x(), vStart.y(), vStart.z()),
					buw::vector3d((vEnd - vStart).x(), (vEnd - vStart).y(), (vEnd - vStart).z())
				);

				buw::vector3d intersectionPoint = buw::Intersect(pickRay, p);

				vertexCacheAlignmentEditorPoint_->setPointSize(5.0f);
				vertexCacheAlignmentEditorPoint_->setColor(buw::colorConstants3f::orangered());
				vertexCacheAlignmentEditorPoint_->drawPoint(intersectionPoint);

				alignmentEditorPoints_.push_back(intersectionPoint);

				if (alignmentEditorPoints_.size() > 1)
				{
					vertexCacheAlignmentEditorLine_->drawLine(alignmentEditorPoints_[alignmentEditorPoints_.size() - 2].xy(), intersectionPoint.xy());
				}
			}
		}
		else
		{
			if (hoveredAlignmentIndex_ != -1 && hoveredAlignmentIndex_ != selectedAlignmentIndex_)
			{
				buw::ReferenceCounted<buw::SelectAlignment> actionSelectAlignment = std::make_shared<buw::SelectAlignment>(hoveredAlignmentIndex_);
				OpenInfraPlatform::DataManagement::DocumentManager::getInstance().execute(actionSelectAlignment);
			}
		}
	}

	if (event->button() & Qt::RightButton)
	{
		buw::vector3f targetPoint = getGBufferColor(event->x(), event->y()).xyz();

		if (targetPoint == buw::vector3f(1.0f, 0.0f, 0.0f))
		{
			targetPoint = infraCamera_->getPosition(buw::InfraCamera::TARGET);
		}
		infraCameraController_->setPanTarget(targetPoint);
	}

	if (event->buttons() & Qt::LeftButton && event->modifiers() & Qt::ALT)
	{
		repositionCameraTarget();
	}

	lastMousePos_ = buw::vector2f(event->x(), event->y());

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::mouseMoveEvent(QMouseEvent *event)
{
	{
		// draw Debug target
		auto targetPoint = getGBufferColor(event->x(), event->y()).xyz();
		buw::matrix44f world = buw::createScale44f(0.02f) *	buw::createAutodeskToGLMatrix();
		buw::matrix44f worldI = buw::createInverse44f(world);
		targetPoint = worldI * targetPoint;

		toolManager_->setTargetPoint(targetPoint);
	}
	
	toolManager_->mouseMoveEvent(event);

	pickColor = getPickBufferColor(event->x(), event->y());
	viewCube_->mouseMoveEvent(pickColor);

	hoveredAlignmentIndex_ = -1;
	if (pickColor != clearPickColor && bHighlightSelectedAlignmentSegment_)
	{
		if (pickColor.yzw() == buw::vector3f(0.f))
		{
			hoveredAlignmentIndex_ = (int)(pickColor.x() * 117);
		}
	}

	if (bShowHud)
	{
		hud_->mouseMoveEvent(width(), height(), event->x(), event->y());
	}

	if (event->buttons())
	{
		// Normalize mouse movement 
		buw::vector2f mouse = buw::vector2f(event->x(), event->y());
		buw::vector2f delta = lastMousePos_ - mouse;
		delta[0] /= width() / 2.f;
		delta[1] /= height() / -2.f;
		lastMousePos_ = mouse;

		if (event->buttons() & Qt::LeftButton)
		{
			infraCameraController_->mouseMove(buw::InfraCameraController::MouseBehavior::Rotate, delta, event->modifiers() & Qt::ALT);

			if (event->modifiers() & Qt::ALT)
			{
				// draw Debug target
				buw::matrix44f world = buw::createScale44f(0.02f) *	buw::createAutodeskToGLMatrix();

				vertexCachePointDebug_->clear();
				vertexCachePointDebug_->setColor(buw::colorConstants3f::yellow());
				vertexCachePointDebug_->drawPoint(buw::createInverse44f(world) * infraCamera_->getPosition(buw::InfraCamera::TARGET));
			}
		}
		else if (event->buttons() & Qt::RightButton)
		{
			infraCameraController_->mouseMove(buw::InfraCameraController::MouseBehavior::Pan, delta, false);
		}
	}

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::wheelEvent(QWheelEvent * event)
{
	repositionCameraTarget();
	infraCameraController_->mouseWheel(event->delta());

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
		infraCameraController_->keyPressed(buw::InfraCameraController::KeyBehavior::Move_Forward);
	if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
		infraCameraController_->keyPressed(buw::InfraCameraController::KeyBehavior::Move_Left);
	if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
		infraCameraController_->keyPressed(buw::InfraCameraController::KeyBehavior::Move_Backward);
	if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
		infraCameraController_->keyPressed(buw::InfraCameraController::KeyBehavior::Move_Right);
	if (event->key() == Qt::Key_Space)
		infraCameraController_->keyPressed(buw::InfraCameraController::KeyBehavior::Move_Up);
	if (event->key() == Qt::Key_Shift)
		infraCameraController_->keyPressed(buw::InfraCameraController::KeyBehavior::Move_Down);

	if (event->key() == Qt::Key_Plus)
	{
		float nearPlane = infraCamera_->frustum().nearPlane();
		infraCamera_->frustum().nearPlane(nearPlane * 1.1);
		forceRepaint();
	}
	if (event->key() == Qt::Key_Minus)
	{
		float nearPlane = infraCamera_->frustum().nearPlane();
		infraCamera_->frustum().nearPlane(nearPlane / 1.1);
		forceRepaint();
	}

	if (event->key() == Qt::Key_U)
	{
		buw::ReferenceCounted<buw::IDebugVisualizer> debugTextureVisualizer = renderSystem_->createDebugVisualizer();

		debugTextureVisualizer->saveAs("pickbuffer.bmp", renderTargetPickBuffer_);
	}
}

void OpenInfraPlatform::UserInterface::Viewport::keyReleaseEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
		infraCameraController_->keyReleased(buw::InfraCameraController::KeyBehavior::Move_Forward);
	if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
		infraCameraController_->keyReleased(buw::InfraCameraController::KeyBehavior::Move_Left);
	if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
		infraCameraController_->keyReleased(buw::InfraCameraController::KeyBehavior::Move_Backward);
	if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
		infraCameraController_->keyReleased(buw::InfraCameraController::KeyBehavior::Move_Right);
	if (event->key() == Qt::Key_Space)
		infraCameraController_->keyReleased(buw::InfraCameraController::KeyBehavior::Move_Up);
	if (event->key() == Qt::Key_Shift)
		infraCameraController_->keyReleased(buw::InfraCameraController::KeyBehavior::Move_Down);
}

void OpenInfraPlatform::UserInterface::Viewport::mouseReleaseEvent(QMouseEvent *event)
{
	vertexCachePointDebug_->clear();
}

void  OpenInfraPlatform::UserInterface::Viewport::viewDirection(const buw::vector3f& direction)
{
	infraCameraController_->setViewDirection(direction);
}

void OpenInfraPlatform::UserInterface::Viewport::repositionCameraTarget()
{
	buw::vector3f center = getGBufferColor(width() / 2.f, height() / 2.f).xyz();
	if (center != buw::vector3f(1.0f, 0.0f, 0.0f))
		infraCameraController_->repositionCameraTarget(center);
}

void OpenInfraPlatform::UserInterface::Viewport::generatePickRay(int sx, int sy, buw::vector3f& o_start, buw::vector3f& o_end)
{
	o_start = screenToWorld(sx, sy, 0.0f);
	o_end = screenToWorld(sx, sy, 1.0f);
}

void OpenInfraPlatform::UserInterface::Viewport::createDigitalElevationModel()
{
	auto digitalEvaluationModel =
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getDigitalElevationModel();

	meshesDigitalElevationModel_.clear();

	buw::vector3d offsetViewArea = getOffset();

	int surfaceCount = digitalEvaluationModel->getSurfaceCount();

	for (int si = 0; si < surfaceCount; si++)
	{
		if (digitalEvaluationModel->getSurface(si)->getPointCount() == 0)
		{
			// skip this surface, because it has now points
			continue;
		}
		auto simpleMesh = ConvertToSimpleMesh(digitalEvaluationModel->getSurface(si).get());

		// Create a vertex and index buffer for each chunk
		buw::indexedMeshDescription imd;
		imd.vertexLayout = vertexLayoutDigitalElevationModel_;
		typedef buw::VertexPosition3Normal3Texture2 VFormat;

		for (int i = 0; i < simpleMesh->GetVertexCount(); ++i)
		{
			VFormat vtx;
			simpleMesh->GetVertex(i, vtx);

			// push vertex vtx to an vertex buffer
			imd.vertexBuffer.push_back(vtx);
		}

		for (int i = 0; i < simpleMesh->GetVertexCount(); ++i)
		{
			imd.vertexBuffer[i].position -= buw::vector3f(offsetViewArea.x(), offsetViewArea.y(), offsetViewArea.z());
		}

		// create an index buffer
		imd.indexBuffer.resize(simpleMesh->GetIndexCount());

		// copy data to index buffer
		memcpy(&imd.indexBuffer[0],
			simpleMesh->GetIndexDataPointer(),
			simpleMesh->GetIndexCount() * sizeof(std::uint32_t));

		buw::ReferenceCounted<buw::IndexedMesh> im = std::make_shared<buw::IndexedMesh>(renderSystem_, imd);

		meshesDigitalElevationModel_.push_back(im);
	} // end for

	for (buw::ReferenceCounted<buw::VertexCacheLine> vcl : vertexCacheLineBreakLines_)
	{
		vcl->clear();
	}

	vertexCacheLineBreakLines_.clear();

	for (const std::vector<buw::vector3d>& breakLine : digitalEvaluationModel->getBreakLines())
	{
		auto vertexCacheLine = std::make_shared<buw::VertexCacheLine>(renderSystem_, "Shader/VertexCacheLine.be");
		vertexCacheLine->setColor(0.1, 0.2, 0.8);

		for (int i = 1; i < breakLine.size(); i++)
		{
			buw::vector3d start = breakLine[i - 1];
			buw::vector3d end = breakLine[i];

			start -= buw::vector3d(offsetViewArea.x(), offsetViewArea.y(), offsetViewArea.z());
			end -= buw::vector3d(offsetViewArea.x(), offsetViewArea.y(), offsetViewArea.z());;

			vertexCacheLine->drawLine(start, end);
		}

		vertexCacheLineBreakLines_.push_back(vertexCacheLine);
	}
}

void OpenInfraPlatform::UserInterface::Viewport::createAlignment()
{
	vertexCacheAlignmentTriangle_->clear();
	vertexCacheAlignmentLine_->clear();
	vertexCacheAlignmentPoint_->clear();
	triangleCacheP3C3N3UV2_->clear();

	auto& data = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData();
	vertexCacheAlignmentLine_->setWidth(data.getAlignmentLineWidth());

	auto alignmentModel = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel();

	// draw 3d track
	switch (view_)
	{
	case OpenInfraPlatform::UserInterface::eView::HorizontalAlignment:
		createAlignmentHorizontal(alignmentModel);
		break;
	case OpenInfraPlatform::UserInterface::eView::VerticalAlignment:
		createAlignmentVertical(alignmentModel);
		break;
	case OpenInfraPlatform::UserInterface::eView::ThreeDimensional:
		createAlignmentThreeDimensional();
		break;
	default:
		BLUE_ASSERT(false, "View type not implemented.")
		break;
	}
}

void OpenInfraPlatform::UserInterface::Viewport::createGraphicResources()
{
	// create a font
	signedDistanceFont_ = std::make_shared<buw::SignedDistanceFont>();
	signedDistanceFont_->create("Data/CalibriRegular.sdff.txt", "Data/CalibriRegular.sdff.png", renderSystem_);
	text_ = std::make_shared<buw::Text>(renderSystem_);

	text_->setFont(signedDistanceFont_);
	text_->setFontSize(12.0f);
	text_->setBoundary(buw::Text::LINE);

	// create hud
	if (bShowHud)
	{
		hud_ = std::make_shared<Hud>(renderSystem_, renderContext_);
	}

	shaderGradientQuad_ = renderSystem_->createShader("Shader/GradientQuad.be");

	// Create depth stencil states
	buw::depthStencilStateDescription dsDesc;

	dssDefault_ = renderSystem_->createDepthStencilState(dsDesc);

	dsDesc.depthEnable = true;
	dsDesc.depthWrite = false;
	dsDesc.stencilEnable = false;
	ddsDisableDepthWrite_ = renderSystem_->createDepthStencilState(dsDesc);

	dsDesc.depthEnable = false;
	dsDesc.depthWrite = false;
	dsDesc.stencilEnable = false;
	ddsDisableDepthTest_ = renderSystem_->createDepthStencilState(dsDesc);

	buw::rasterizerStateDescription rs;
	rsDefault_ = renderSystem_->createRasterizerState(rs);
	rs.cullMode = buw::eCullMode::Back;
	rsCullBackFaces_ = renderSystem_->createRasterizerState(rs);

	shaderDigitalElevationModel_ = renderSystem_->createShader("Shader/DigitalElevationModel.be");

	gBufferShader_ = renderSystem_->createShader("Shader/GBuffer.be");

	vertexCacheAlignmentEditorLine_ = std::make_shared<buw::RoadDesignVCL>(renderSystem_,
		"Shader/VertexCacheLineAlignment.be",
		"Shader/VertexCacheLineAlignmentPick.be",
		20000);
	vertexCacheAlignmentEditorPoint_ = std::make_shared<buw::RoadDesignVCP>(renderSystem_,
		"Shader/VertexCachePoint.be");

	vertexCacheLineUIElements = std::make_shared<buw::VertexCacheLine>(renderSystem_,
		"Shader/VertexCacheLine.be");

	vertexCachePointDebug_ = std::make_shared<buw::VertexCachePoint>(renderSystem_, "Shader/VertexCachePoint.be");
	vertexCacheLineDebug_ = std::make_shared<buw::VertexCacheLine>(renderSystem_, "Shader/VertexCacheLine.be");

	vertexLayoutDigitalElevationModel_ = renderSystem_->createVertexLayout(
		buw::VertexPosition3Normal3Texture2::getVertexLayoutDescription(),
		buw::VertexPosition3Normal3Texture2::getVertexLayoutElementCount(),
		shaderDigitalElevationModel_);

	buw::rasterizerStateDescription rsdSolidFill;
	rsdSolidFill.fillMode = buw::eFillMode::Solid;
	rsSolidFill_ = renderSystem_->createRasterizerState(rsdSolidFill);

	buw::rasterizerStateDescription rsdWireframeFill;
	rsdWireframeFill.fillMode = buw::eFillMode::Wireframe;
	rsWireframeFill_ = renderSystem_->createRasterizerState(rsdWireframeFill);

	buw::samplerStateDescription samplerStateDesc;
	samplerStateDesc.textureAddressModeU = buw::eTextureAddressMode::Wrap;
	samplerStateDesc.textureAddressModeV = buw::eTextureAddressMode::Wrap;
	samplerStateDesc.textureAddressModeW = buw::eTextureAddressMode::Wrap;
	samplerStateDesc.minificationFilter = buw::eFilter::Anisotropic;
	samplerStateDesc.magnificationFilter = buw::eFilter::Anisotropic;
	samplerStateDesc.mipLevelFilter = buw::eFilter::Anisotropic;
	sampler_ = renderSystem_->createSamplerState(samplerStateDesc);

	{
		buw::samplerStateDescription samplerStateDesc;
		samplerStateDesc.minificationFilter = buw::eFilter::Linear;
		samplerStateDesc.magnificationFilter = buw::eFilter::Linear;
		samplerStateDesc.mipLevelFilter = buw::eFilter::None;
		samplerStateDesc.textureAddressModeU = buw::eTextureAddressMode::Clamp;
		samplerStateDesc.textureAddressModeV = buw::eTextureAddressMode::Clamp;
		samplerStateDesc.textureAddressModeW = buw::eTextureAddressMode::Clamp;
		colorRampSampler_ = renderSystem_->createSamplerState(samplerStateDesc);
	}

	terrainTexture_ = buw::loadTexture(renderSystem_, "Data/terrain.jpg");

	{
		buw::ReferenceCounted<buw::Image_4f> image = buw::loadImageFromFile<buw::Image_4f>("Data/GradientRamp.png");

		buw::texture1DDescription t1d;
		t1d.format = buw::eTextureFormat::R32G32B32A32_Float;
		t1d.width = image->getWidth();
		t1d.data = (unsigned char*) image->getData();

		gradientRampTexture_ = renderSystem_->createTexture1D(t1d);

		//auto dv = renderSystem_->createDebugVisualizer();
		//dv->saveAs("gradient3.png", gradientRampTexture_);
	}
}

void OpenInfraPlatform::UserInterface::Viewport::setDrawTerrainWireframe(const bool enable)
{
	bDrawTerrainWireframe_ = enable;

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::setHideTerrain(const bool checked)
{
	bHideTerrain_ = checked;

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::enableTerrainGradientRamp(const bool enable)
{
	bTerrainUseColorRamp_ = enable;

	if (enable)
	{
		auto digitalEvaluationModel =
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getDigitalElevationModel();

		heightRange_[0] = digitalEvaluationModel->getMinimumHeight();
		heightRange_[1] = digitalEvaluationModel->getMaximumHeight();
	}

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::enableIsoLines(const bool enable)
{
	bTerrainDisplayIsoLines_ = enable;
	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::drawTerrain()
{
	for (int i = 0; i < meshesDigitalElevationModel_.size(); i++)
	{
		buw::matrix44f world = buw::createScale44f(0.02f) *	buw::createAutodeskToGLMatrix();
		buw::matrix44f worldIT = (buw::createInverse44f(world)).transpose();
		buw::matrix44f viewprojection = infraCamera_->getViewProjectionMatrix();

		shaderDigitalElevationModel_->setValue("WorldViewProjection", viewprojection * world);
		shaderDigitalElevationModel_->setValue("World", world);
		shaderDigitalElevationModel_->setValue("WorldIT", worldIT);
		shaderDigitalElevationModel_->setValue("g_EyePosition", infraCamera_->getEyePosition().xyz());
		shaderDigitalElevationModel_->setSampler("sampler_", sampler_);
		shaderDigitalElevationModel_->setValue("bTerrainTextured", bTerrainTextured_);
		shaderDigitalElevationModel_->setValue("bTerrainUseColorRamp", bTerrainUseColorRamp_);
		shaderDigitalElevationModel_->setValue("bTerrainDisplayIsoLines", bTerrainDisplayIsoLines_);

		shaderDigitalElevationModel_->setValue("texDiffuseMap", terrainTexture_);
		shaderDigitalElevationModel_->setValue("colorRamp", gradientRampTexture_);

		if (bTerrainUseColorRamp_)
		{
			shaderDigitalElevationModel_->setValue("heightRange", heightRange_);
			shaderDigitalElevationModel_->setSampler("colorRampSampler", colorRampSampler_);
		}

		meshesDigitalElevationModel_[i]->render(renderContext_, shaderDigitalElevationModel_);
	}
}

void OpenInfraPlatform::UserInterface::Viewport::setUseUniformPointColor(const bool useUniformColor)
{
	bUseUniformPointColor_ = useUniformColor;
	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::setUseUniformPointSize(const bool useUniformSize)
{
	bUseUniformPointSize_ = useUniformSize;
	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::setPointSize(const float pointSize)
{
	pointSize_ = pointSize;
	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::fillGBuffer()
{
	for (int i = 0; i < meshesDigitalElevationModel_.size(); i++)
	{
		buw::matrix44f world = buw::createScale44f(0.02f) *	buw::createAutodeskToGLMatrix();
		buw::matrix44f worldIT = (buw::createInverse44f(world)).transpose();
		buw::matrix44f viewprojection = infraCamera_->getViewProjectionMatrix();

		gBufferShader_->setValue("WorldViewProjection", viewprojection * world);
		gBufferShader_->setValue("World", world);
		gBufferShader_->setValue("WorldIT", worldIT);
		gBufferShader_->setSampler("sampler_", sampler_);
		gBufferShader_->setValue("bTerrainTextured", bTerrainTextured_);

		gBufferShader_->setValue("texDiffuseMap", terrainTexture_);


		meshesDigitalElevationModel_[i]->render(renderContext_, gBufferShader_);
	}
}

void OpenInfraPlatform::UserInterface::Viewport::fillVertexCacheUIElements()
{
	vertexCacheLineUIElements->clear();

	bool drawCoordinateSystem = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().isShowReferenceCoordinateSystemEnabled();

	if (drawCoordinateSystem)
	{
		buw::drawCoordinateSystem(vertexCacheLineUIElements);
	}

	if (OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().isDrawGridEnabled())
	{
		buw::drawGridDescription dgd;
		dgd.width = 400.0f;
		dgd.height = 400.0f;
		dgd.center = buw::vector3f(0, 0, 0);
		dgd.widthSegments = 40;
		dgd.heightSegments = 40;
		dgd.orientation = buw::eGridOrientation::POSITIV_Y_ORIENTATION;
		dgd.leaveCoodinateSystemBlank = drawCoordinateSystem;

		buw::drawGrid(
			vertexCacheLineUIElements,
			dgd
			);
	}
}

buw::vector3d OpenInfraPlatform::UserInterface::Viewport::getOffset() const
{
	return OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getOffset();
}

void OpenInfraPlatform::UserInterface::Viewport::setView(eView val)
{
	view_ = val;

	createAlignment();

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::showCrossSection(const bool showCrossSection)
{
	showCrossSection_ = showCrossSection;

	createAlignment();

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::showDesignCrossSection(const bool showDesignCrossSection)
{
	showDesignCrossSection_ = showDesignCrossSection;

	createAlignment();

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::connectCrossSections(const bool connectCrossSections)
{
	connectCrossSections_ = connectCrossSections;

	createAlignment();

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::doSolidCrossSections(const bool doSolidCrossSections)
{
	doSolidCrossSections_ = doSolidCrossSections;

	createAlignment();

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::drawRoadTexture(const bool drawRoadTexture)
{

	if (drawRoadTexture && roadTexture_ == nullptr)
	{
		roadTexture_ = buw::loadTexture(renderSystem_, "Data/Road.png");
	}

	drawRoadTexture_ = drawRoadTexture;

	createAlignment();

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::enableTerrainTextured(const bool checked)
{
	bTerrainTextured_ = checked;

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::enableCreatePoints(bool checked)
{
	bCreatePoints_ = checked;
}

buw::vector3f OpenInfraPlatform::UserInterface::Viewport::unproject(const buw::vector3f &point)
{
	buw::matrix44f world = buw::createScale44f(0.02f) *	buw::createAutodeskToGLMatrix();
	buw::matrix44f view = infraCamera_->getViewMatrix();
	buw::matrix44f projection = infraCamera_->getProjectionMatrix();

	buw::rectangle<int> viewport = buw::rectangle<int>(0, 0, width(), height());

	buw::matrix44f mvp = projection * view * world;

	return buw::unproject(point, mvp, viewport);
}

buw::vector3f OpenInfraPlatform::UserInterface::Viewport::screenToWorld(const float x, const float y, const float z/*=0.0f*/)
{
	BLUE_ASSERT(z >= 0.0f, "Invalid z value.");
	BLUE_ASSERT(z <= 1.0f, "Invalid z value.");

	buw::rectangle<int> viewport = buw::rectangle<int>(0, 0, width(), height());

	buw::vector3f p = buw::vector3f(x, y, z);

	// adjust y (0,0 is lower left corner in OpenGL) 
	p.y() = (viewport.height() - p.y());

	// near plane intersection
	p.z() = 0.0f;
	buw::vector3f p0 = unproject(p);

	// far plane intersection
	p.z() = 1.0f;
	buw::vector3f p1 = unproject(p);

	// find (x, y) coordinates
	float t = z;
	p.x() = (p0.x() + t * (p1.x() - p0.x()));
	p.y() = (p0.y() + t * (p1.y() - p0.y()));
	p.z() = (1 - z) * p0.z() + z * p1.z();
	return p;
}

void OpenInfraPlatform::UserInterface::Viewport::pick(int sx, int sy, buw::vector3f& o_start, buw::vector3f& o_end)
{
	o_start = screenToWorld(sx, sy, 0.0f);
	o_end = screenToWorld(sx, sy, 1.0f);
}

void OpenInfraPlatform::UserInterface::Viewport::setHighlightDifferentAlignmentElements(const bool enable)
{
	bHighlightDifferentAlignmentElements_ = enable;
	onChange(ChangeFlag::AlignmentModel);
}

void OpenInfraPlatform::UserInterface::Viewport::setHighlightSelectedAlignmentSegment(const bool enable)
{
	bHighlightSelectedAlignmentSegment_ = enable;
	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::setClearColor(const buw::color3f& color)
{
	clearColor_ = color;
	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::drawFullScreenQuad()
{
	buw::drawCommand dc;
	dc.primitveType = buw::ePrimitveType::TriangleStrip;
	dc.vertexCount = 4;
	BLUE_ASSERT(dc.validate(), "Invalid draw command.");

	renderContext_->bind(shaderGradientQuad_);
	renderContext_->draw(dc);
	renderContext_->unbind(shaderGradientQuad_);
}

void OpenInfraPlatform::UserInterface::Viewport::saveAsScreenshot(const std::string& filename)
{
	forceRepaint();

	buw::ReferenceCounted<buw::IDebugVisualizer> debugTextureVisualizer_ = renderSystem_->createDebugVisualizer();

	auto backBufferTarget = renderSystem_->getImmediateContext()->getBackBufferRenderTarget();

	debugTextureVisualizer_->saveAs(
		filename.c_str(),
		backBufferTarget);
}

std::vector<buw::vector3d> OpenInfraPlatform::UserInterface::Viewport::getAlignmentPoints()
{
	auto tmp = alignmentEditorPoints_;

	alignmentEditorPoints_.clear();
	vertexCacheAlignmentEditorLine_->clear();
	vertexCacheAlignmentEditorPoint_->clear();

	return tmp;
}

buw::vector2i OpenInfraPlatform::UserInterface::Viewport::getSize() const
{
	return buw::vector2i(width(), height());
}


void OpenInfraPlatform::UserInterface::Viewport::setProjectionType(const buw::eProjectionType::Enum type)
{
	projectionType_ = type;

	updateFrustumProjection();

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::updateFrustumProjection()
{
	infraCamera_->frustum().width(width());
	infraCamera_->frustum().height(height());
	infraCamera_->frustum().nearPlane(0.05f);
	infraCamera_->frustum().farPlane(500.f);

	if (projectionType_ == buw::eProjectionType::Perspective)
	{
		infraCamera_->frustum().projection(buw::InfraCamera::CameraFrustum::ProjectionType::PERSPECTIVE);

		infraCamera_->frustum().fieldOfView(M_PI / 3.f);
	}
	else
	{
		infraCameraController_->setControlMode(buw::InfraCameraController::ControlMode::Orbiting);

		infraCamera_->frustum().projection(buw::InfraCamera::CameraFrustum::ProjectionType::ORTHOGRAPHIC);
		infraCamera_->frustum().scale(0.01f, 0.01f, 1.0f);
	}
}

void OpenInfraPlatform::UserInterface::Viewport::enableBlueMap(const bool checked)
{
	if (blueMap_ == nullptr)
	{
		blueMap_ = std::make_shared<buw::BlueMap>(renderSystem_, renderContext_);
	}

	enableBlueMap_ = checked;

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::applyBlueMapProperties(const buw::PropertySet& ps)
{
	if (blueMap_)
	{
		blueMap_->applyProperties(ps);
	}
}

void OpenInfraPlatform::UserInterface::Viewport::createPickBufferRenderTarget()
{
	buw::renderTargetTexture2DDescriptor rtd(width(), height());

	if (rtd.height == 0)
		rtd.height = 1;

	if (rtd.width == 0)
		rtd.width = 1;

	rtd.addRenderTarget(buw::eTextureFormat::R32G32B32A32_Float); // Color buffer
	rtd.createDepthStencil(buw::eTextureFormat::D32_Float);
	rtd.name = "renderTargetComposing";
	renderTargetPickBuffer_ = renderSystem_->createRenderTargetTexture2D(rtd);
}

void OpenInfraPlatform::UserInterface::Viewport::createDeferredRenderTargets()
{
	// create geometry buffer render target
	buw::renderTargetTexture2DDescriptor rtd(width(), height());
	rtd.addRenderTarget(buw::eTextureFormat::R8G8B8A8_UnsignedNormalizedInt);	// Color buffer
	rtd.addRenderTarget(buw::eTextureFormat::R32G32B32A32_Float);	// Normal buffer
	rtd.addRenderTarget(buw::eTextureFormat::R32G32B32A32_Float);	// World position buffer
	rtd.createDepthStencil(buw::eTextureFormat::D32_Float);			// Depth buffer
	rtd.name = "renderTargetGBuffer";
	renderTargetGBuffer_ = renderSystem_->createRenderTargetTexture2D(rtd);
}

void OpenInfraPlatform::UserInterface::Viewport::createCpuReadTexture()
{
	buw::texture2DDescription t2d;
	t2d.width = 1;
	t2d.height = 1;
	t2d.format = buw::eTextureFormat::R32G32B32A32_Float;
	t2d.flags = buw::eTextureBindFlags::None;
	t2d.data = nullptr;
	t2d.mipMapCount = 1;
	t2d.accessMode = buw::eRenderResourceAccessMode::CpuRead;
	cpuReadTexture_ = renderSystem_->createTexture2D(t2d);
}

buw::vector4f OpenInfraPlatform::UserInterface::Viewport::getPickBufferColor(const int x, const int y)
{
	// read pick buffer
	buw::rectangle<int> source_rc(x + 0, y + 0, x + 1, y + 1);

	if (source_rc.left < 0)
	{
		return buw::vector4f(0, 0, 0, 1);
	}

	if (source_rc.right >= width())
	{
		return buw::vector4f(0, 0, 0, 1);
	}

	if (source_rc.bottom >= height())
	{
		return buw::vector4f(0, 0, 0, 1);
	}

	if (source_rc.top < 0)
	{
		return buw::vector4f(0, 0, 0, 1);
	}

	renderContext_->copyTexture(renderTargetPickBuffer_, source_rc, cpuReadTexture_, buw::vector2i(0, 0));

	buw::vector4f *data = nullptr;

	cpuReadTexture_->map(renderSystem_.get(), buw::eRenderResourceAccessMode::CpuRead, 0, reinterpret_cast<void**>(&data));

	buw::vector4f pickColor = data[0];

	cpuReadTexture_->unmap(renderSystem_.get(), 0);

	return pickColor;
}

void OpenInfraPlatform::UserInterface::Viewport::storePickBuffer()
{
	buw::ReferenceCounted<buw::IDebugVisualizer> dtv = renderSystem_->createDebugVisualizer();
	dtv->saveAs("RenderTarget_0_PickBuffer.png", renderTargetPickBuffer_, 0);
}

buw::vector4f OpenInfraPlatform::UserInterface::Viewport::getGBufferColor(const int x, const int y)
{
	// read pick buffer
	buw::rectangle<int> source_rc(x + 0, y + 0, x + 1, y + 1);

	if (source_rc.left < 0)
	{
		return buw::vector4f(0, 0, 0, 1);
	}

	if (source_rc.right >= width())
	{
		return buw::vector4f(0, 0, 0, 1);
	}

	if (source_rc.bottom >= height())
	{
		return buw::vector4f(0, 0, 0, 1);
	}

	if (source_rc.top < 0)
	{
		return buw::vector4f(0, 0, 0, 1);
	}

	renderContext_->copyTexture(renderTargetGBuffer_, source_rc, cpuReadTexture_, buw::vector2i(0, 0), 2);

	buw::vector4f *data = nullptr;

	cpuReadTexture_->map(renderSystem_.get(), buw::eRenderResourceAccessMode::CpuRead, 0, reinterpret_cast<void**>(&data));

	buw::vector4f pickColor = data[0];

	cpuReadTexture_->unmap(renderSystem_.get(), 0);

	return pickColor;
}

void OpenInfraPlatform::UserInterface::Viewport::storeGBuffer()
{
	buw::ReferenceCounted<buw::IDebugVisualizer> dtv = renderSystem_->createDebugVisualizer();
	dtv->saveAs("RenderTarget_0_ColorBuffer.png", renderTargetGBuffer_, 0);
	dtv->saveAs("RenderTarget_1_NormalBuffer.png", renderTargetGBuffer_, 1);
	dtv->saveAs("RenderTarget_2_WorldPosition.png", renderTargetGBuffer_, 2);
}


void OpenInfraPlatform::UserInterface::Viewport::onViewCubeSelectionChanged(buw::eViewCubeOrientation::Enum state)
{
	ViewCubeSelectionChanged(state);
}

void OpenInfraPlatform::UserInterface::Viewport::setInfraCameraController(buw::ReferenceCounted<buw::InfraCameraController> controller)
{
	infraCameraController_ = controller;
}

buw::ReferenceCounted<buw::InfraCameraController> OpenInfraPlatform::UserInterface::Viewport::getInfraCameraController()
{
	return infraCameraController_;
}

void OpenInfraPlatform::UserInterface::Viewport::createAlignmentHorizontal(
	 buw::ReferenceCounted<buw::AlignmentModel> alignmentModel)
{
	buw::vector3d offsetViewArea = getOffset();
	buw::color3f c = buw::colorConstants3f::lightgreen();

	if (bHighlightDifferentAlignmentElements_)
	{
		for (int alignmentIndex = 0; alignmentIndex < alignmentModel->getAlignmentCount(); alignmentIndex++)
		{
			if (alignmentModel->getAlignment(alignmentIndex)->getType() != buw::e3DAlignmentType::e2DBased)
			{
				continue;
			}

			vertexCacheAlignmentLine_->setID(alignmentIndex);

			buw::ReferenceCounted<buw::Alignment2DBased3D> a = std::static_pointer_cast<buw::Alignment2DBased3D>(alignmentModel->getAlignment(alignmentIndex));

			buw::ReferenceCounted<buw::HorizontalAlignment2D> h = a->getHorizontalAlignment();

			for (int ei = 0; ei < h->getAlignmentElementCount(); ei++)
			{
				buw::ReferenceCounted<buw::HorizontalAlignmentElement2D> e = h->getAlignmentElementByIndex(ei);

				auto lastPosition = e->getPosition(0.0f);

				for (float s = 0.0f; s <= 1.0f; s += 0.1f)
				{
					auto position = e->getPosition(s);

					switch (e->getAlignmentType())
					{
					case buw::eHorizontalAlignmentType::Line:
						vertexCacheAlignmentLine_->setColor(buw::colorConstants3f::lightgreen());
						break;
					case buw::eHorizontalAlignmentType::Arc:
						vertexCacheAlignmentLine_->setColor(buw::colorConstants3f::red());
						break;
					case buw::eHorizontalAlignmentType::Clothoid:
						vertexCacheAlignmentLine_->setColor(buw::colorConstants3f::deeppink());
					default:
						vertexCacheAlignmentLine_->setColor(buw::colorConstants3f::yellow());
						break;
					}

					vertexCacheAlignmentLine_->drawLine(lastPosition - offsetViewArea.xy(), position - offsetViewArea.xy());

					lastPosition = position;
				}

				auto position = e->getPosition(1.0f);
				vertexCacheAlignmentLine_->drawLine(lastPosition - offsetViewArea.xy(), position - offsetViewArea.xy());
			}
		}
	}
	else
	{
		for (int alignmentIndex = 0; alignmentIndex < alignmentModel->getAlignmentCount(); alignmentIndex++)
		{
			if (alignmentModel->getAlignment(alignmentIndex)->getType() != buw::e3DAlignmentType::e2DBased)
			{
				continue;
			}
			vertexCacheAlignmentLine_->setID(alignmentIndex);

			buw::ReferenceCounted<buw::Alignment2DBased3D> a = std::static_pointer_cast<buw::Alignment2DBased3D>(alignmentModel->getAlignment(alignmentIndex));

			buw::ReferenceCounted<buw::HorizontalAlignment2D> h = a->getHorizontalAlignment();

			auto lastPosition = h->getPosition(h->getStartStation());

			for (double s = h->getStartStation(); s < h->getEndStation(); s += 0.8)
			{
				auto position = h->getPosition(s);

				auto al = h->getLength();

				vertexCacheAlignmentLine_->setColor(c);

				vertexCacheAlignmentLine_->drawLine(lastPosition - offsetViewArea.xy(), position - offsetViewArea.xy());

				lastPosition = position;
			}
		}
	}
}

void OpenInfraPlatform::UserInterface::Viewport::createAlignmentThreeDimensional()
{
	auto alignmentModel = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel();

	buw::vector3d offsetViewArea = getOffset();

	buw::color3f c = buw::colorConstants3f::lightgreen();

	if (bHighlightDifferentAlignmentElements_)
	{
		for (int alignmentIndex = 0; alignmentIndex < alignmentModel->getAlignmentCount(); alignmentIndex++)
		{
			vertexCacheAlignmentLine_->setID(alignmentIndex);

			buw::ReferenceCounted<buw::IAlignment3D> a = alignmentModel->getAlignment(alignmentIndex);

			auto lastPosition = a->getPosition(a->getStartStation());

			for (double s = a->getStartStation(); s < a->getEndStation(); s += 0.8)
			{
				auto position = a->getPosition(s);

				if (a->getType() == buw::e3DAlignmentType::e2DBased)
				{
					auto a2d = std::static_pointer_cast<buw::Alignment2DBased3D>(a);

					if (a2d->hasHorizontalAlignment())
					{
						auto he = a2d->getHorizontalAlignment()->getAlignmentElementByStationing(s);

						if (he != nullptr)
						{
							switch (he->getAlignmentType())
							{
							case buw::eHorizontalAlignmentType::Line:
								vertexCacheAlignmentLine_->setColor(buw::colorConstants3f::lightgreen());
								break;
							case buw::eHorizontalAlignmentType::Arc:
								vertexCacheAlignmentLine_->setColor(buw::colorConstants3f::red());
								break;
							default:
								vertexCacheAlignmentLine_->setColor(buw::colorConstants3f::yellow());
								break;
							}
						}
					}
				}
				else
				{
					vertexCacheAlignmentLine_->setColor(buw::colorConstants3f::lightblue());
				}

				vertexCacheAlignmentLine_->drawLine(lastPosition - offsetViewArea, position - offsetViewArea);

				vertexCacheAlignmentPoint_->setColor(buw::colorConstants3f::red());

				lastPosition = position;
			}
		}
	}
	else
	{
		for (int alignmentIndex = 0; alignmentIndex < alignmentModel->getAlignmentCount(); alignmentIndex++)
		{
			vertexCacheAlignmentLine_->setID(alignmentIndex);
			vertexCacheAlignmentLine_->setColor(c);

			buw::ReferenceCounted<buw::IAlignment3D> a = alignmentModel->getAlignment(alignmentIndex);

			buw::vector3d lastPosition, position;
			lastPosition = a->getPosition(a->getStartStation());
			for (double s = a->getStartStation(); s <= a->getEndStation(); s += 0.8)
			{
				position = a->getPosition(s);
				if (position != lastPosition)
					vertexCacheAlignmentLine_->drawLine(lastPosition - offsetViewArea, position - offsetViewArea);

				lastPosition = position;
			}
		}
	}

	createAlignmentThreeDimensional_CrossSection();
}

void OpenInfraPlatform::UserInterface::Viewport::createAlignmentVertical(
	buw::ReferenceCounted<buw::AlignmentModel> alignmentModel)
{
	// draw vertical alignment
	buw::AxisAlignedBoundingBox3d aabb = alignmentModel->getVerticalAlignmentExtends();
	buw::vector3d ce = aabb.getCenter();

	for (int i = 0; i < alignmentModel->getAlignmentCount(); i++)
	{
		if (alignmentModel->getAlignment(i)->getType() != buw::e3DAlignmentType::e2DBased)
		{
			continue;
		}
		vertexCacheAlignmentLine_->setID(i);

		buw::ReferenceCounted<buw::Alignment2DBased3D> a = std::static_pointer_cast<buw::Alignment2DBased3D>(alignmentModel->getAlignment(selectedAlignmentIndex_));

		buw::ReferenceCounted<buw::VerticalAlignment2D> v = a->getVerticalAlignment();

		if (v != nullptr)
		{
			auto lastPosition = v->getPosition(v->getStartStation());

			for (double s = v->getStartStation(); s < v->getEndStation(); s += 0.8)
			{
				auto position = v->getPosition(s);

				vertexCacheAlignmentLine_->setColor(buw::colorConstants3f::orangered());
				vertexCacheAlignmentLine_->drawLine(
					buw::vector3d(lastPosition.x(), 0, lastPosition.y()) - ce,
					buw::vector3d(position.x(), 0, position.y()) - ce);

				lastPosition = position;
			}

			// Draw start and end points of para curves
			for (int ai = 0; ai < v->getAlignmentElementCount(); ai++)
			{
				if (v->getAlignmentElementByIndex(ai)->getAlignmentType() == buw::eVerticalAlignmentType::Parabola)
				{
					auto ve = v->getAlignmentElementByIndex(ai);

					buw::vector2d start;
					ve->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);

					buw::vector2d end;
					ve->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition, &end);

					buw::vector2d pvi;
					ve->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::PVI, &pvi);


					vertexCacheAlignmentPoint_->setPointSize(6.0f);
					vertexCacheAlignmentPoint_->setColor(buw::colorConstants3f::green());
					vertexCacheAlignmentPoint_->drawPointXZ(start - ce.xz());
					vertexCacheAlignmentPoint_->setColor(buw::colorConstants3f::yellow());
					vertexCacheAlignmentPoint_->drawPointXZ(end - ce.xz());

					vertexCacheAlignmentPoint_->setColor(buw::colorConstants3f::royalblue());
					vertexCacheAlignmentPoint_->drawPointXZ(pvi - ce.xz());
				}
			}
		}

		break;
	}
}

void OpenInfraPlatform::UserInterface::Viewport::createIfcGeometry(buw::ReferenceCounted<OpenInfraPlatform::IfcGeometryConverter::IfcGeometryModel> ifcGeometryModel)
{
	vertexCacheIfcGeometry_->clear();
	vertexCacheIfcPolylines_->clear();

	auto& meshDescription = ifcGeometryModel->meshDescription_;
	auto& polylineDescription = ifcGeometryModel->polylineDescription_;

	buw::vector3f offset = (buw::vector3f)getOffset();

	for (int i = 0; i < meshDescription.indices.size();)
	{
		if (meshDescription.indices.size() - 1 < i + 2) break;

		VertexLayout v0 = meshDescription.vertices[meshDescription.indices[i++]];
		VertexLayout v1 = meshDescription.vertices[meshDescription.indices[i++]];
		VertexLayout v2 = meshDescription.vertices[meshDescription.indices[i++]];

		v0.position -= offset;
		v1.position -= offset;
		v2.position -= offset;

		vertexCacheIfcGeometry_->drawTriangleSafe(v0, v1, v2);
	}

	for (int i = 0; i < polylineDescription.indices.size();)
	{
		if (meshDescription.indices.size() - 1 < i + 1) break;

		buw::vector3f v0 = polylineDescription.vertices[polylineDescription.indices[i++]];
		buw::vector3f v1 = polylineDescription.vertices[polylineDescription.indices[i++]];

		v0 -= offset;
		v1 -= offset;

		vertexCacheIfcPolylines_->drawLine(v0, v1);
	}
}

void OpenInfraPlatform::UserInterface::Viewport::onClear()
{
	selectedAlignmentIndex_ = 0;
}

void OpenInfraPlatform::UserInterface::Viewport::leaveEvent(QEvent *)
{
	// unselect view cube
	viewCube_->mouseMoveEvent(buw::vector4f(0, 0, 0, 0));

	forceRepaint();
}

void OpenInfraPlatform::UserInterface::Viewport::createSkyboxResources()
{
	// create SkyBox
	buw::skyboxDescription skyDesc;
	skyDesc.right = "Data/sky/right.png";
	skyDesc.left = "Data/sky/left.png";
	skyDesc.top = "Data/sky/top.png";
	skyDesc.bottom = "Data/sky/bottom.png";
	skyDesc.front = "Data/sky/front.png";
	skyDesc.back = "Data/sky/back.png";
	skyDesc.shaderFilename = "Shader/skyboxPT.be";

	skybox_ = buw::ReferenceCounted<buw::Skybox>(new buw::Skybox(renderSystem_, skyDesc));
}

void OpenInfraPlatform::UserInterface::Viewport::reloadShader()
{
	try
	{
		shaderDigitalElevationModel_ = renderSystem_->createShader("Shader/DigitalElevationModel.be");
		shaderLaserScan_ = renderSystem_->createShader("Shader/LaserScanPoint.be");
		triangleShader_ = renderSystem_->createShader("Shader/VertexCacheTriangle.be");
		triangleShaderP3C3N3UV2_ = renderSystem_->createShader("Shader/VertexCacheTriangleTextured.be");
	}
	catch (const buw::Exception& ex)
	{
	}
}

bool OpenInfraPlatform::UserInterface::Viewport::getDrawTerrainWireframe() const
{
	return bDrawTerrainWireframe_;
}

OpenInfraPlatform::UserInterface::eView OpenInfraPlatform::UserInterface::Viewport::getView() const
{
	return view_;
}

void OpenInfraPlatform::UserInterface::Viewport::showFrameTimes(const bool show)
{
	bShowFrameTimes_ = show;
}

void OpenInfraPlatform::UserInterface::Viewport::LoadBridge()
{
	mesh_ = std::make_shared<buw::SkinnedMesh>(renderSystem_,
		shaderDigitalElevationModel_);
	mesh_->LoadMesh("testdata/STL/test.stl");
	bBridgeLoaded = true;
}

void OpenInfraPlatform::UserInterface::Viewport::RenderBridge()
{
	if (bBridgeLoaded)
	{
		buw::matrix44f world = buw::createScale44f(0.02f) *	buw::createAutodeskToGLMatrix();
		buw::matrix44f worldIT = (buw::createInverse44f(world)).transpose();
		buw::matrix44f viewprojection = infraCamera_->getViewProjectionMatrix();

		shaderDigitalElevationModel_->setValue("WorldViewProjection", viewprojection * world);
		shaderDigitalElevationModel_->setValue("World", world);
		shaderDigitalElevationModel_->setValue("WorldIT", worldIT);
		shaderDigitalElevationModel_->setValue("g_EyePosition", infraCamera_->getEyePosition().xyz());
		shaderDigitalElevationModel_->setSampler("sampler_", sampler_);
		shaderDigitalElevationModel_->setValue("bTerrainTextured", false);
		shaderDigitalElevationModel_->setValue("bTerrainUseColorRamp", false);
		shaderDigitalElevationModel_->setValue("bTerrainDisplayIsoLines", false);
		
		mesh_->Render(shaderDigitalElevationModel_);
	}
}
