/*! \verbatim
 *  \copyright		Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author			Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\brief			This file is part of the BlueFramework.
 *	\endverbatim
 */

#pragma once
#ifndef Blueform_UserInterface_Viewport_fbfab9db_0e02_4e25_a393_88c65a2ab542_h
#define Blueform_UserInterface_Viewport_fbfab9db_0e02_4e25_a393_88c65a2ab542_h

#include "../../../BlueFramework/GraphicsEngine/BlueMap.h"
#include "eView.h"
#include "Hud.h"
#include "RoadDesignVCL.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/AlignmentModel.h"
#include "BlueFramework/Engine/ViewCube/ViewCube.h"
#include "BlueFramework/Engine/Camera/InfraCamera.h"
#include "BlueFramework/Engine/Camera/InfraCameraController.h"
#include "BlueFramework/Engine/Camera/SpectatorCamera.h"
#include "BlueFramework/Rasterizer/IRenderSystem.h"
#include "OpenInfraPlatform/IfcGeometryConverter/ConverterBuw.h"
#include <QWidget>
#include <QMouseEvent>
#include "OpenInfraPlatform/UserInterface/ViewPanel/Tool.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class Viewport : public QWidget
		{
			Q_OBJECT;

		public:			
			//---------------------------------------------------------------------------//
			// Events
			//---------------------------------------------------------------------------//

			boost::signals2::signal<void(buw::eViewCubeOrientation::Enum)> ViewCubeSelectionChanged;

		public:
			Viewport(const buw::renderWindowsDescription& rwd, QWidget* parent = 0);

			virtual ~Viewport();

			//! Draws the scene.
			void	paintEvent(QPaintEvent *);

			QPaintEngine* paintEngine() const;

			void	resizeEvent(QResizeEvent *);

			void	onChange();
			void	onClear();

			void	forceRepaint();
			void    startContinuousRendering();
			void	stopContinuousRendering();
			
			eView	getView() const;
			void	setView(eView val);

			void	showCrossSection(const bool showCrossSection);
			void	showDesignCrossSection( const bool showDesignCrossSection );
			void	connectCrossSections(const bool connectCrossSections);
			void	doSolidCrossSections(const bool solidCrossSections);
			void	drawRoadTexture(const bool drawRoadTexture);

			void	enableCreatePoints( bool checked );

			std::vector<buw::vector3d> getAlignmentPoints();

			buw::vector3d	getOffset() const;

			void reloadShader();

			void storeGBuffer();

			// Quick hack for imporing bridge models
			bool bBridgeLoaded = false;
			void LoadBridge();

			void RenderBridge();

			//---------------------------------------------------------------------------//
			// Alignment
			//---------------------------------------------------------------------------//

			void	setHighlightDifferentAlignmentElements( const bool enable );
			void	setHighlightSelectedAlignmentSegment( const bool enable );
			
			//---------------------------------------------------------------------------//
			// Terrain
			//---------------------------------------------------------------------------//

			void	setHideTerrain(const bool checked );
			bool	getDrawTerrainWireframe() const;
			void	setDrawTerrainWireframe(const bool enable);
			void	enableTerrainTextured(const bool checked );
			void	enableTerrainGradientRamp(const bool enable);
			void	enableIsoLines(const bool enable);

			//---------------------------------------------------------------------------//
			// LaserScan
			//---------------------------------------------------------------------------//
			
			void	setUseUniformPointColor(const bool useUniformColor);
			void	setUseUniformPointSize(const bool useUniformSize);
			void	setPointSize(const float size);

			//---------------------------------------------------------------------------//
			// BlueMaps
			//---------------------------------------------------------------------------//

			void enableBlueMap(const bool checked);
			void applyBlueMapProperties(const buw::PropertySet& ps);

			//---------------------------------------------------------------------------//
			// Clear
			//---------------------------------------------------------------------------//

			void	setClearColor(const buw::color3f& color);	
	
			//---------------------------------------------------------------------------//
			// Common
			//---------------------------------------------------------------------------//

			buw::vector2i getSize() const;

			void setProjectionType(const buw::eProjectionType::Enum type);

			void saveAsScreenshot( const std::string& filename );

			void showFrameTimes(const bool show);

			//---------------------------------------------------------------------------//
			// Control
			//---------------------------------------------------------------------------//
			void				viewDirection(const buw::vector3f& direction);
			void				repositionCameraTarget();

			void setInfraCameraController(buw::InfraCameraController::Ptr controller);
			buw::InfraCameraController::Ptr getInfraCameraController();

			void setSelectedAlignment( const int index );

		public Q_SLOTS:

			void drawNextFrame();

		protected:
			void leaveEvent ( QEvent * );

			//! Receive mouse press events for the widget.
			void mousePressEvent(QMouseEvent *event);

			//! Receives wheel events for the widget.
			void wheelEvent(QWheelEvent  * event);
			
			void mouseMoveEvent(QMouseEvent *event);

			//! Called whenever a key is pressed.
			void keyPressEvent(QKeyEvent *event);

			//! Called whenever a key is released.
			void keyReleaseEvent(QKeyEvent *event);

			//! Receives mouse release events for the widget.
			/*
				\param[in] event	Contains parameters that describe a mouse event.
			*/
			void mouseReleaseEvent(QMouseEvent *event);

		private:		
			void			updateFrustumProjection();
			void			createGraphicResources();
			void			createSkyboxResources();
			void			createDigitalElevationModel();

			void			createAlignment();
			void			createAlignmentHorizontal(buw::AlignmentModel::Ptr alignmentModel);
			void			createAlignmentVertical(OpenInfraPlatform::Infrastructure::AlignmentModel::Ptr alignmentModel);
			void			createAlignmentThreeDimensional();
			void			createIfcGeometry(IfcGeometryConverter::IfcGeometryModel::Ptr ifcGeometryModel);
			void			createBoundingBoxes(buw::vector3d min, buw::vector3d max);

			void			createAlignmentThreeDimensional_CrossSection();

			void			generatePickRay(int sx, int sy, buw::vector3f& o_start, buw::vector3f& o_end);

			float			getAspectRatio() const;

			void			createRenderSystem(const buw::renderWindowsDescription& rwd);

			void			fillVertexCacheUIElements();

			void			drawTerrain();

			buw::vector3f	unproject(const buw::vector3f &point);
			buw::vector3f	screenToWorld(const float x, const float y, const float z/*=0.0f*/);
			void			pick(int sx, int sy, buw::vector3f& o_start, buw::vector3f& o_end);

			void			drawFullScreenQuad();

			void			createPickBufferRenderTarget();
			void			createDeferredRenderTargets();

			void			fillGBuffer();

			void			createCpuReadTexture();;

			buw::vector4f	getPickBufferColor(const int x, const int y);
			buw::vector4f	getGBufferColor(const int x, const int y);

			void			storePickBuffer();

			void			onViewCubeSelectionChanged(buw::eViewCubeOrientation::Enum state);

			// road body
			buw::matrix44d getGlobalRotationMatrixOnStation(
				buw::Alignment2DBased3D::Ptr alignment, 
				buw::Stationing station);

			void drawCrossSection(
				buw::Alignment2DBased3D::Ptr alignment,
				buw::CrossSectionStatic::Ptr cs, 
				buw::vector3d offsetViewArea);

			void drawRoadBodyBetweenStation(
				buw::Alignment2DBased3D::Ptr alignment, 
				buw::CrossSectionStatic::Ptr cs, 
				buw::CrossSectionStatic::Ptr nextCs, 
				buw::vector3d offsetViewArea);

		private:
			buw::SkinnedMesh::Ptr				mesh_;

			ToolManager::Ptr					toolManager_;

			int									selectedAlignmentIndex_;

			// ViewCube
			buw::ViewCube::Ptr					viewCube_;
			buw::IDepthStencilState::Ptr		ddsDisableDepthTest_;
			buw::IRasterizerState::Ptr          rsDefault_;
			buw::IRasterizerState::Ptr			rsCullBackFaces_;
			bool								bShowViewCube_;
			bool								bContinuousRendering_;


			buw::ITexture2D::Ptr				cpuReadTexture_;

			// PickBuffer
			buw::vector4f						pickColor;	// is updated by each mouse move event
			buw::IRenderTargetTexture2D::Ptr	renderTargetPickBuffer_;

			// GBuffer
			buw::IShader::Ptr					gBufferShader_;
			buw::IRenderTargetTexture2D::Ptr	renderTargetGBuffer_;

			// LaserScan
			bool								bUseUniformPointColor_;
			bool								bUseUniformPointSize_;
			float								pointSize_;

			// BlueMap
			buw::BlueMap::Ptr					blueMap_;
			bool								enableBlueMap_;
			
			Hud::Ptr							hud_;
			static const bool					bShowHud = false;

			// Clear
			bool								gradientClear_;
			buw::IDepthStencilState::Ptr		dssDefault_;
			buw::IDepthStencilState::Ptr		ddsDisableDepthWrite_;
			buw::IShader::Ptr					shaderGradientQuad_;
			buw::color3f						clearColor_;

			bool								bHighlightDifferentAlignmentElements_;
			bool								bHighlightSelectedAlignmentSegment_;

			// alignment editor
			bool								bCreatePoints_;
			buw::RoadDesignVCL::Ptr				vertexCacheAlignmentEditorLine_;
			buw::RoadDesignVCP::Ptr				vertexCacheAlignmentEditorPoint_;
			std::vector<buw::vector3d>			alignmentEditorPoints_;

			buw::VertexCachePointT<buw::VertexPositionColor>::Ptr	vertexCachePointLaserScan_;
			buw::IShader::Ptr					shaderLaserScan_;

			eView								view_;
			buw::eProjectionType::Enum			projectionType_;
			
			buw::IRenderSystem::Ptr				renderSystem_;
			buw::IRenderContext::Ptr			renderContext_;

			buw::VertexCacheTriangle::Ptr		vertexCacheAlignmentTriangle_;
			buw::IShader::Ptr					triangleShader_;
			buw::RoadDesignVCL::Ptr				vertexCacheAlignmentLine_;
			buw::RoadDesignVCP::Ptr				vertexCacheAlignmentPoint_;

			buw::VertexCacheTriangleT<VertexLayout>::Ptr vertexCacheIfcGeometry_;
			buw::VertexCacheLine::Ptr			vertexCacheIfcPolylines_;

			buw::VertexCacheLine::Ptr			vertexCacheLineUIElements;
			buw::VertexCachePoint::Ptr			vertexCachePointDebug_;
			buw::VertexCacheLine::Ptr			vertexCacheLineDebug_;
			
			std::vector<buw::VertexCacheLine::Ptr>	vertexCacheLineBreakLines_;

			buw::IRasterizerState::Ptr			rsSolidFill_;
			buw::IRasterizerState::Ptr			rsWireframeFill_;
			buw::ISamplerState::Ptr				sampler_;

			// DigitalElevationModel
			bool								bTerrainTextured_;
			bool								bTerrainUseColorRamp_;
			bool								bTerrainDisplayIsoLines_;
			buw::ITexture2D::Ptr				terrainTexture_;
			buw::ITexture1D::Ptr				gradientRampTexture_;
			bool								bHideTerrain_;
			bool								bDrawTerrainWireframe_;
			buw::vector2f						heightRange_;

			buw::ISamplerState::Ptr				colorRampSampler_;
			
			std::vector<buw::IndexedMesh::Ptr>	meshesDigitalElevationModel_;
			buw::IShader::Ptr					shaderDigitalElevationModel_;
			buw::IShader::Ptr					shaderDigitalElevationModelColorRamp_;
			buw::IVertexLayout::Ptr				vertexLayoutDigitalElevationModel_;

			//  Text
			buw::SignedDistanceFont::Ptr		signedDistanceFont_;
			buw::Text::Ptr						text_;
			
			//---------------------------------------------------------------------------//
			// Preferences
			//---------------------------------------------------------------------------//
			float alignmentLineWidth_;

			//---------------------------------------------------------------------------//
			// Camera control
			//---------------------------------------------------------------------------//
			buw::InfraCamera::Ptr				infraCamera_;
			buw::InfraCameraController::Ptr		infraCameraController_;
			unsigned long						lastTick_;
			buw::vector2f						lastMousePos_;

			// Skybox
			bool								drawSkybox_;
			buw::Skybox::Ptr					skybox_;

			//---------------------------------------------------------------------------//
			// CrossSections
			//---------------------------------------------------------------------------//
			bool								showCrossSection_;
			bool								showDesignCrossSection_;
			bool								connectCrossSections_;
			bool								doSolidCrossSections_;
			bool								drawRoadTexture_;

			buw::ITexture2D::Ptr															roadTexture_;
			buw::VertexCacheTriangleT<buw::VertexPosition3Color3Normal3Texture2>::Ptr		triangleCacheP3C3N3UV2_;
			buw::IShader::Ptr																triangleShaderP3C3N3UV2_;

			//---------------------------------------------------------------------------//
			// Diagnostics
			//---------------------------------------------------------------------------//
			buw::Timer	performanceTimer_;
			double		lastPreFrame_;
			long long	frameTime_;
			long long	sinceLastFrame_;
			bool		bShowFrameTimes_;
		}; // end class Viewport
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::eView;
	using OpenInfraPlatform::UserInterface::Viewport;
}

#endif // end define Blueform_UserInterface_Viewport_fbfab9db_0e02_4e25_a393_88c65a2ab542_h