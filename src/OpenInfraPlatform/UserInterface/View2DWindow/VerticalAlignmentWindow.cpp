/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Fabian Schöttl <fabian.schoettl@tum.de> (https://www.cms.bgu.tum.de/en/)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "VerticalAlignmentWindow.h"
#include <QGraphicsTextItem>
#include <QGraphicsSceneWheelEvent>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QtSvg/QSvgGenerator>
#include <math.h>

OpenInfraPlatform::UserInterface::VerticalAlignmentScene::VerticalAlignmentScene(QObject *parent)
	: Alignment2DScene(parent),
displayPoints_(false)
{
	configureColors(A2D_DrawState::A2D_Draw);
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentScene::v_configureColors(A2D_DrawState state)
{
	switch(state)
	{
	case A2D_DrawState::A2D_Draw:
		terrainPen = QPen(Qt::yellow);
		break;

	case A2D_DrawState::A2D_Print:
		terrainPen = QPen(Qt::darkYellow);
		break;
	}
	terrainPen.setWidth(1);
	terrainPen.setCosmetic(true);
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentScene::v_drawAlignment(
	buw::Alignment2DBased3D::Ptr a, 
	std::map<buw::eHorizontalAlignmentType, QPainterPath>& horizontalPainter,
	std::map<buw::eVerticalAlignmentType, QPainterPath>& verticalPainter)
{
	buw::HorizontalAlignment2D::Ptr h = a->getHorizontalAlignment();
	buw::VerticalAlignment2D::Ptr v = a->getVerticalAlignment();

	if (v != nullptr)
	{
		auto start = v->getPosition(v->getStartStation());
		auto end = v->getPosition(v->getEndStation());
				
		bounds[0] = bounds[1] = start.x();
		bounds[2] = bounds[3] = -start.y();

		double prevX = bounds[0], prevY = bounds[2];
		buw::eHorizontalAlignmentType lastType = buw::eHorizontalAlignmentType::Unknown;
		buw::eVerticalAlignmentType lastVerticalType = buw::eVerticalAlignmentType::Unknown;

		verticalPainter[lastVerticalType].moveTo(prevX, prevY);
		horizontalPainter[lastType].moveTo(prevX, prevY);

		for (double s = v->getStartStation(); s < v->getEndStation() ; s+=0.8)
		{
			auto position = v->getPosition(s);
			double x = position.x();
			double y = -position.y();

			if (differentColorsForVerticalAlignmentElements_)
			{
				auto ve = v->getAlignmentElementByStationing(s);
				buw::eVerticalAlignmentType type = ve->getAlignmentType();

				if (ve != nullptr)
				{
					if (verticalPainter.find(type) == verticalPainter.end())
						verticalPainter[type] = QPainterPath();

					if (lastVerticalType != type)
						verticalPainter[type].moveTo(prevX, prevY);
					verticalPainter[type].lineTo(x, y);
				}

				lastVerticalType = type;				
			}
			else if (differentColorsForHorizontalAlignmentElements_)
			{
				auto he = h->getAlignmentElementByStationing(s);
				buw::eHorizontalAlignmentType type = he->getAlignmentType();

				if (horizontalPainter.find(type) == horizontalPainter.end())
					horizontalPainter[type] = QPainterPath();

				if (lastType != type)
					horizontalPainter[type].moveTo(prevX, prevY);
				horizontalPainter[type].lineTo(x, y);

				lastType = type;
			}
			else
			{
				buw::eHorizontalAlignmentType type = buw::eHorizontalAlignmentType::Unknown;
				if (horizontalPainter.find(type) == horizontalPainter.end())
					horizontalPainter[type] = QPainterPath();

				horizontalPainter[type].lineTo(x, y);

				lastType = type;
			}

			bounds[0] = std::min(bounds[0], x);
			bounds[1] = std::max(bounds[1], x);
			bounds[2] = std::min(bounds[2], y);
			bounds[3] = std::max(bounds[3], y);

			prevX = x;
			prevY = y;
		}

		arcPoints.clear();
		parabolaPoints.clear();

		for (int ai = 0; ai < v->getAlignmentElementCount(); ai++)
		{
			auto ve = v->getAlignmentElementByIndex(ai);

			if (ve->getAlignmentType() == buw::eVerticalAlignmentType::Arc)
			{
				buw::vector2d start; 
				ve->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);

				buw::vector2d end; 
				ve->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition, &end);

				start[1] *= -1;
				end[1] *= -1;

				arcPoints.push_back(std::make_tuple(ai, start, end));
			}
			if (ve->getAlignmentType() == buw::eVerticalAlignmentType::Parabola)
			{
				buw::vector2d start;
				ve->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);

				buw::vector2d end;

				ve->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition, &end);
				buw::vector2d pvi;
				ve->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::PVI, &pvi);

				start[1] *= -1;
				end[1] *= -1;
				pvi[1] *= -1;

				parabolaPoints.push_back(std::make_tuple(ai, start, end, pvi));
			}
		}
	}
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentScene::loadSurfaceProfile()
{
	clearSurfaceProfile();

	auto alignment = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel();

	buw::Alignment2DBased3D::Ptr a = std::static_pointer_cast<buw::Alignment2DBased3D>(alignment->getAlignment(selectedAlignmentIndex_));

	auto profile = model_->getSurfaceProfile(a);

	bool reset = true;	

	for(std::pair<double,double> sz : profile)
	{
		double x = std::get<0>(sz);
		double y = -std::get<1>(sz);
		if(y!=0)
		{
			if(reset)
				terrainPainter.moveTo(x, y);
			else
				terrainPainter.lineTo(x, y);
			reset = false;
		}
		else
			reset = true;
	}

	scale();
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentScene::v_drawDiagram(QPainterPath& diagPainter, QPainterPath& diagDashedPainter)
{		
	QString text;
	
	// 
	if(displayPoints_)
	{
		for(int i=0; i<arcPoints.size(); i++)
		{
			buw::vector2d start, end;
			int ai = std::get<0>(arcPoints[i]);
			start = std::get<1>(arcPoints[i]);
			end = std::get<2>(arcPoints[i]);

			text = "AA" + QString::number(ai+1);;
			auto startLabel = addText(text, diagramFont);
			startLabel->setPos(start.x() * scalingX, start.y() * scalingY - 25);
			startLabel->setDefaultTextColor(Qt::lightGray);

			diagDashedPainter.moveTo(start.x() * scalingX, start.y() * scalingY);
			diagDashedPainter.lineTo(start.x() * scalingX, bounds[3] * scalingY + 5);

			text = "AE" + QString::number(ai+1);
			auto endLabel = addText(text, diagramFont);
			endLabel->setPos(end.x() * scalingX, end.y() * scalingY - 25);
			endLabel->setDefaultTextColor(Qt::lightGray);

			diagDashedPainter.moveTo(end.x() * scalingX, end.y() * scalingY);
			diagDashedPainter.lineTo(end.x() * scalingX, bounds[3] * scalingY + 5);
		}
		for (int i = 0; i<parabolaPoints.size(); i++)
		{
			buw::vector2d start, end, pvi;
			int ai = std::get<0>(parabolaPoints[i]);
			start = std::get<1>(parabolaPoints[i]);
			end = std::get<2>(parabolaPoints[i]);
			pvi = std::get<3>(parabolaPoints[i]);

			text = "AA" + QString::number(ai + 1);;
			auto startLabel = addText(text, diagramFont);
			startLabel->setPos(start.x() * scalingX, start.y() * scalingY - 25);
			startLabel->setDefaultTextColor(Qt::lightGray);

			diagDashedPainter.moveTo(start.x() * scalingX, start.y() * scalingY);
			diagDashedPainter.lineTo(start.x() * scalingX, bounds[3] * scalingY + 5);

			text = "AE" + QString::number(ai + 1);
			auto endLabel = addText(text, diagramFont);
			endLabel->setPos(end.x() * scalingX, end.y() * scalingY - 25);
			endLabel->setDefaultTextColor(Qt::lightGray);

			diagDashedPainter.moveTo(end.x() * scalingX, end.y() * scalingY);
			diagDashedPainter.lineTo(end.x() * scalingX, bounds[3] * scalingY + 5);

			text = "VB" + QString::number(ai + 1);;
			auto pviLabel = addText(text, diagramFont);
			pviLabel->setPos(pvi.x() * scalingX, pvi.y() * scalingY - 25);
			pviLabel->setDefaultTextColor(Qt::lightGray);

			diagDashedPainter.moveTo(pvi.x() * scalingX, pvi.y() * scalingY);
			diagDashedPainter.lineTo(pvi.x() * scalingX, bounds[3] * scalingY + 5);
		}
	}

}

void OpenInfraPlatform::UserInterface::VerticalAlignmentScene::v_addPaths()
{
	addPath(scaledPainterPath(&terrainPainter,scalingX, scalingY), terrainPen, transparentBrush);
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentScene::setDigitalElevationModel(buw::DigitalElevationModel::Ptr model)
{
	model_ = model;
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentScene::displayPoints(bool display)
{
	displayPoints_ = display;
	scale();
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentScene::clearSurfaceProfile()
{
	terrainPainter = QPainterPath();
}




// Window

OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::VerticalAlignmentWindow(QAction* act) : 
	ui_(new Ui::VerticalAlignment()),
	action_(act),
	scene_(new VerticalAlignmentScene(this)),
	QDockWidget()
{
	ui_->setupUi(this);
	ui_->verticalAlignmentView->setScene(scene_);
	
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().Change.connect(boost::bind(&VerticalAlignmentWindow::onChange, this));

	onChange();
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::onChange()
{
	auto alignmentModel = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel();
	auto elevationModel = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getDigitalElevationModel();

	if(alignmentModel->getAlignmentCount() <=0)
		return;

	scene_->setAlignment(alignmentModel);
	setSelectedAlignment(0);

	scene_->setDigitalElevationModel(elevationModel);
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::setSelectedAlignment(int index)
{
	if(scene_)
	{
		scene_->clearSurfaceProfile();
		scene_->setSelectedAlignment(index)	;	
	}
	QString name = QString::fromStdWString(OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel()->getAlignment(index)->getName().toWStdString());
	setWindowTitle("Vertical Alignment - " + name);
}

int OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::getSelectedAlignment()
{
	return scene_ ? scene_->getSelectedAlignment() : 0;
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::setDifferentColorsForHorizontalAlignmentElements(const bool checked)
{
	if(scene_)
		scene_->setDifferentColorsForHorizontalAlignmentElements(checked);
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::setDifferentColorsForVerticalAlignmentElements(const bool checked)
{
	if (scene_)
		scene_->setDifferentColorsForVerticalAlignmentElements(checked);
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::on_loadSurfaceProfileButton_clicked()
{
	scene_->loadSurfaceProfile();
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::on_displayPointsCheckBox_clicked(bool checked)
{
	scene_->displayPoints(checked);
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::closeEvent(QCloseEvent *event)
{
	if (action_)
		action_->setChecked(false);
}

void OpenInfraPlatform::UserInterface::VerticalAlignmentWindow::exportToFile()
{
	scene_->exportToFile(this);
}
