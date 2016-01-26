/*! \verbatim
 *  \copyright		Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author			Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\author			Daniel Below <daniel.below@tum.de>
 *	\brief			This file is part of the BlueFramework.
 *	\endverbatim
 */

#include "View.h"
#include <qpushbutton.h>
#include <qaction.h>
#include <qlabel.h>

OpenInfraPlatform::UserInterface::View::View() : QDockWidget() // no parent
{
	buw::renderWindowsDescription rwd =  buw::loadRenderWindowsSettings("Data/settings.xml");
	viewport_ = new Viewport(rwd);

	viewport_->ViewCubeSelectionChanged.connect(
		boost::bind(&View::onViewCubeSelectionChanged, this, _1)
		);

	setWidget(viewport_);
	setViewportSize(650, 453);

	QMenuBar* pMenuBar = new QMenuBar(nullptr);

	// view menu
	menuView_ = new QMenu(tr("View"));
	pMenuBar->addMenu(menuView_);
	
	
	actionTop_ = menuView_->addAction(tr("Top"));
	actionBottom_ = menuView_->addAction(tr("Bottom"));
	actionLeft_ = menuView_->addAction(tr("Left"));
	actionRight_ = menuView_->addAction(tr("Right"));
	actionFront_ = menuView_->addAction(tr("Front"));
	actionBack_ = menuView_->addAction(tr("Back"));
	
	menuView_->addSeparator();
	menuAxonometric_ = menuView_->addMenu(tr("Axonometric"));
	actionIsometric_ = menuAxonometric_->addAction(tr("Isometric"));

	// projection menu
	menuProjection_ = new QMenu(tr("Projection"));
	pMenuBar->addMenu(menuProjection_);

	actionPerspective_ = menuProjection_->addAction(tr("Perspective"));
	actionPerspective_->setCheckable(true);
	actionPerspective_->setChecked(true);
	actionOrthographic_ = menuProjection_->addAction(tr("Orthographic"));
	actionOrthographic_->setCheckable(true);

	// home menu
	homeAction_ = new QAction("", nullptr);
	homeAction_->setShortcut(QKeySequence(Qt::Key_H));

	auto homeIcon = QIcon("Data/home.ico");
	if (homeIcon.isNull())
	{
		buw::LogManager::getInstance().Log("Could not load icon from 'Data/home.ico'.");
	}
	else
	{
		homeAction_->setIcon(homeIcon);
	}

	controlAction_ = new QAction("", nullptr);
	controlAction_->setShortcut(QKeySequence(Qt::Key_T));

	QMenuBar* rightBar = new QMenuBar();
	rightBar->setObjectName("transparent");

	rightBar->addAction(homeAction_);
	rightBar->addAction(controlAction_);

	pMenuBar->setCornerWidget(rightBar);

	setTitleBarWidget(pMenuBar);

	std::function<void()> callback = std::bind(&OpenInfraPlatform::UserInterface::View::cameraControlModeChanged, this);
	getInfraCameraController()->addControlModeChanged(callback);

	cameraControlModeChanged();

	QObject::connect(homeAction_, &QAction::triggered, this, &View::on_home);
	QObject::connect(controlAction_, &QAction::triggered, this, &View::on_actionToggleControlMode);

	setFeatures(DockWidgetFeature::NoDockWidgetFeatures);

	QObject::connect(actionPerspective_, &QAction::triggered, this, &View::on_actionPerspective);
	QObject::connect(actionOrthographic_, &QAction::triggered, this, &View::on_actionOrthographic);
	QObject::connect(actionLeft_, &QAction::triggered, this, &View::on_actionLeft);
	QObject::connect(actionRight_, &QAction::triggered, this, &View::on_actionRight);
	QObject::connect(actionFront_, &QAction::triggered, this, &View::on_actionFront);
	QObject::connect(actionBack_, &QAction::triggered, this, &View::on_actionBack);
	QObject::connect(actionTop_, &QAction::triggered, this, &View::on_actionTop);
	QObject::connect(actionBottom_, &QAction::triggered, this, &View::on_actionBottom);
	QObject::connect(actionIsometric_, &QAction::triggered, this, &View::on_actionIsometric);
}

OpenInfraPlatform::UserInterface::View::~View()
{
	delete viewport_;
}

void OpenInfraPlatform::UserInterface::View::changeEvent(QEvent* evt)
{
	if (evt->type() == QEvent::LanguageChange)
	{
		retranslateView();
	}
	else
	{
		// remember to call base class implementation
		QDockWidget::changeEvent(evt);
	}
}

void OpenInfraPlatform::UserInterface::View::retranslateView()
{
	menuView_->setTitle(tr("View"));

	actionTop_->setText(tr("Top"));
	actionBottom_->setText(tr("Bottom"));
	actionLeft_->setText(tr("Left"));
	actionRight_->setText(tr("Right"));
	actionFront_->setText(tr("Front"));
	actionBack_->setText(tr("Back"));

	menuAxonometric_->setTitle(tr("Axonometric"));
	actionIsometric_->setText(tr("Isometric"));

	menuProjection_->setTitle(tr("Projection"));

	actionPerspective_->setText(tr("Perspective"));
	actionOrthographic_->setText(tr("Orthographic"));
}

void OpenInfraPlatform::UserInterface::View::on_actionIsometric()
{
	viewport_->viewDirection(buw::vector3f(1, 1, 1));
}

void OpenInfraPlatform::UserInterface::View::on_actionBottom()
{
	viewport_->viewDirection(buw::vector3f(0, -1, 0));
}

void OpenInfraPlatform::UserInterface::View::on_actionTop()
{
	viewport_->viewDirection(buw::vector3f(0, 1, 0));
}

void OpenInfraPlatform::UserInterface::View::on_actionBack()
{
	viewport_->viewDirection(buw::vector3f(0, 0, -1));
}

void OpenInfraPlatform::UserInterface::View::on_actionFront()
{
	viewport_->viewDirection(buw::vector3f(0, 0, 1));
}

void OpenInfraPlatform::UserInterface::View::on_actionRight()
{
	viewport_->viewDirection(buw::vector3f(1, 0, 0));
}

void OpenInfraPlatform::UserInterface::View::on_actionLeft()
{
	viewport_->viewDirection(buw::vector3f(-1, 0, 0));
}

void OpenInfraPlatform::UserInterface::View::on_actionOrthographic()
{
	actionPerspective_->setChecked(false);
	actionOrthographic_->setChecked(true);
	viewport_->setProjectionType(buw::eProjectionType::Orthographic);
}

void OpenInfraPlatform::UserInterface::View::on_actionPerspective()
{
	actionPerspective_->setChecked(true);
	actionOrthographic_->setChecked(false);
	viewport_->setProjectionType(buw::eProjectionType::Perspective);
}

int OpenInfraPlatform::UserInterface::View::getViewportHeight() const
{
	return viewport_->height();
}

int OpenInfraPlatform::UserInterface::View::getViewportWidth() const
{
	return viewport_->width();
}

buw::vector2i OpenInfraPlatform::UserInterface::View::getSize() const
{
	return viewport_->getSize();
}

void OpenInfraPlatform::UserInterface::View::setViewportSize(const int width, const int height)
{
	viewport_->resize(width, height);
}

void OpenInfraPlatform::UserInterface::View::saveAsScreenshot( const std::string& filename )
{
	viewport_->saveAsScreenshot(filename);
}

buw::vector3d OpenInfraPlatform::UserInterface::View::getOffset() const
{
	return viewport_->getOffset();
}

void OpenInfraPlatform::UserInterface::View::setHighlightDifferentAlignmentElements( const bool enable )
{
	viewport_->setHighlightDifferentAlignmentElements(enable);
}

void OpenInfraPlatform::UserInterface::View::setHighlightSelectedAlignmentSegment( const bool enable )
{
	viewport_->setHighlightSelectedAlignmentSegment(enable);
}

void OpenInfraPlatform::UserInterface::View::setUseUniformPointColor(const bool useUniformColor)
{
	viewport_->setUseUniformPointColor(useUniformColor);
}

void OpenInfraPlatform::UserInterface::View::setUseUniformPointSize(const bool useUniformSize)
{
	viewport_->setUseUniformPointSize(useUniformSize);
}

void OpenInfraPlatform::UserInterface::View::setPointSize(const float pointSize)
{
	viewport_->setPointSize(pointSize);
}


std::vector<buw::vector3d> OpenInfraPlatform::UserInterface::View::getAlignmentPoints()
{
	return viewport_->getAlignmentPoints();
}

void OpenInfraPlatform::UserInterface::View::enableCreatePoints( const bool enable )
{
	viewport_->enableCreatePoints(enable);
}

void OpenInfraPlatform::UserInterface::View::enableTerrainTextured( const bool enable )
{
	viewport_->enableTerrainTextured( enable );
}

void OpenInfraPlatform::UserInterface::View::enableTerrainGradientRamp(const bool enable)
{
	viewport_->enableTerrainGradientRamp(enable);
}

void OpenInfraPlatform::UserInterface::View::enableIsoLines(const bool enable)
{
	viewport_->enableIsoLines(enable);
}

void OpenInfraPlatform::UserInterface::View::showCrossSection( const bool showCrossSection )
{
	viewport_->showCrossSection(showCrossSection);
}

void OpenInfraPlatform::UserInterface::View::showDesignCrossSection(const bool showDesignCrossSection)
{
	viewport_->showDesignCrossSection(showDesignCrossSection);
}

void OpenInfraPlatform::UserInterface::View::connectCrossSections(const bool connectCrossSections)
{
	viewport_->connectCrossSections(connectCrossSections);
}

void OpenInfraPlatform::UserInterface::View::doSolidCrossSections(const bool solidCrossSections)
{
	viewport_->doSolidCrossSections(solidCrossSections);
}

void OpenInfraPlatform::UserInterface::View::drawRoadTexture(const bool drawRoadTexture)
{
	viewport_->drawRoadTexture(drawRoadTexture);
}

void OpenInfraPlatform::UserInterface::View::setView( eView viewType )
{
	viewport_->setView(viewType);
}

void OpenInfraPlatform::UserInterface::View::enableHideTerrain( const bool enable )
{
	viewport_->setHideTerrain(enable);
}

void OpenInfraPlatform::UserInterface::View::storeGBuffer()
{
	viewport_->storeGBuffer();
}

void OpenInfraPlatform::UserInterface::View::enableDrawTerrainWireframe( const bool enable )
{
	viewport_->setDrawTerrainWireframe(enable);
}

void OpenInfraPlatform::UserInterface::View::enableBlueMap( const bool checked )
{
	viewport_->enableBlueMap( checked );
}

void OpenInfraPlatform::UserInterface::View::applyBlueMapProperties( const buw::PropertySet& ps )
{
	viewport_->applyBlueMapProperties( ps );
}

void OpenInfraPlatform::UserInterface::View::onViewCubeSelectionChanged(buw::eViewCubeOrientation::Enum state)
{
	switch (state)
	{
	case BlueFramework::Engine::eViewCubeOrientation::Unselected:
		break;
	case BlueFramework::Engine::eViewCubeOrientation::TopLeftFrontView:
		{
			viewport_->viewDirection(buw::vector3f(-1, 1, 1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::TopFrontView:
		{
			viewport_->viewDirection(buw::vector3f(0, 1, 1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::TopFrontRightView:
		{
			viewport_->viewDirection(buw::vector3f(1, 1, 1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::FrontLeftView:
		{
			viewport_->viewDirection(buw::vector3f(-1, 0, 1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::FrontView:
		{
			on_actionFront();
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::FrontRightView:
		{
			viewport_->viewDirection(buw::vector3f(1, 0, 1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::FrontLeftBottomView:
		{
			viewport_->viewDirection(buw::vector3f(-1, -1, 1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::FrontBottomView:
		{
			viewport_->viewDirection(buw::vector3f(0, -1, 1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::FrontRightBottomView:
		{
			viewport_->viewDirection(buw::vector3f(1, -1, 1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::TopRightView:
		{
			viewport_->viewDirection(buw::vector3f(1, 1, 0));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::TopRightBackView:
		{
			viewport_->viewDirection(buw::vector3f(1, 1, -1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::RightView:
		{
			on_actionRight();
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::RightBackView:
		{
			viewport_->viewDirection(buw::vector3f(1, 0, -1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::RightBottomView:
		{
			viewport_->viewDirection(buw::vector3f(1, -1, 0));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::RightBottomBackView:
		{
			viewport_->viewDirection(buw::vector3f(1, -1, -1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::TopBackView:
		{
			viewport_->viewDirection(buw::vector3f(0, 1, -1));			
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::TopLeftBackView:
		{
			viewport_->viewDirection(buw::vector3f(-1, 1, -1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::BackView:
		{
			on_actionBack();
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::BackLeftView:
		{
			viewport_->viewDirection(buw::vector3f(-1, 0, -1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::BackBottomView:
		{
			viewport_->viewDirection(buw::vector3f(0, -1, -1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::BackLeftBottomView:
		{
			viewport_->viewDirection(buw::vector3f(-1, -1, -1));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::TopLeftView:
		{
			viewport_->viewDirection(buw::vector3f(-1, 1, 0));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::LeftView:
		{
			on_actionLeft();
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::LeftBottomView:
		{
			viewport_->viewDirection(buw::vector3f(-1, -1, 0));
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::TopView:
		{
			on_actionTop();
		}
		break;
	case BlueFramework::Engine::eViewCubeOrientation::BottomView:
		{
			on_actionBottom();
		}
		break;
	default:
		break;
	}
}

void OpenInfraPlatform::UserInterface::View::setInfraCameraController(buw::ReferenceCounted<buw::InfraCameraController> controller)
{
	viewport_->setInfraCameraController(controller);
}

buw::ReferenceCounted<buw::InfraCameraController> OpenInfraPlatform::UserInterface::View::getInfraCameraController() const
{
	return viewport_->getInfraCameraController();
}


void OpenInfraPlatform::UserInterface::View::reloadShader()
{
	viewport_->reloadShader();
}

void OpenInfraPlatform::UserInterface::View::on_home()
{
	getInfraCameraController()->gotoDefault();
}

void OpenInfraPlatform::UserInterface::View::on_actionToggleControlMode()
{
	getInfraCameraController()->switchControlMode();	
}

void OpenInfraPlatform::UserInterface::View::cameraControlModeChanged()
{
	auto icon = QIcon { (getInfraCameraController()->getControlMode() == buw::InfraCameraController::ControlMode::Flying) ? "Data/ghost_selected.ico" : "Data/ghost_unselected.ico" };
	if (icon.isNull())
	{
		buw::LogManager::getInstance().Log("Could not load flying/orbiting icon.");
	}
	else
	{
		controlAction_->setIcon(icon);
	}
}

void OpenInfraPlatform::UserInterface::View::showFrameTimes(const bool show)
{
	viewport_->showFrameTimes(show);
}

void OpenInfraPlatform::UserInterface::View::LoadBridge()
{
	viewport_->LoadBridge();
}
