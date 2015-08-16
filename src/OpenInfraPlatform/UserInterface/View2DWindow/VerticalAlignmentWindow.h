/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Fabian Schöttl <fabian.schoettl@tum.de> (https://www.cms.bgu.tum.de/en/)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once

#include "Alignment2DScene.h"
#include "ui_VerticalAlignmentWindow.h"
#include "OpenInfraPlatform/DataManagement/Data.h"
#include <QDockWidget>
#include <boost/noncopyable.hpp>
#include <vector>
#include <tuple>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		// Scene
		class VerticalAlignmentScene : public Alignment2DScene
		{
		public:
			VerticalAlignmentScene(QObject *parent = 0);

			void setDigitalElevationModel(buw::DigitalElevationModel::Ptr model);

			void displayPoints(bool display);

			void loadSurfaceProfile();
			void clearSurfaceProfile();

		protected:
			void v_configureColors(A2D_DrawState state) override;

			void v_drawAlignment(buw::Alignment2DBased3D::Ptr a,
				std::map<buw::eHorizontalAlignmentType, QPainterPath>& horizontalPainter,
				std::map<buw::eVerticalAlignmentType, QPainterPath>& verticalPainter) override;
			void v_drawDiagram(QPainterPath& diagPainter, QPainterPath& diagDashedPainter) override;

			void v_addPaths() override;

		private:
			buw::DigitalElevationModel::Ptr model_;

			std::vector<std::tuple<int, buw::vector2d, buw::vector2d>> arcPoints;
			std::vector<std::tuple<int, buw::vector2d, buw::vector2d, buw::vector2d>> parabolaPoints;

			bool displayPoints_;

			QPen	terrainPen;
			QPainterPath terrainPainter;

		};
		
		// Window
		class VerticalAlignmentWindow : public QDockWidget
		{
			Q_OBJECT;

		public:
			VerticalAlignmentWindow(QAction* act);	

			void setSelectedAlignment(int index);
			int getSelectedAlignment();
			void setDifferentColorsForHorizontalAlignmentElements(const bool checked);
			void setDifferentColorsForVerticalAlignmentElements(const bool checked);

			void exportToFile();;

		public Q_SLOTS:
			void on_loadSurfaceProfileButton_clicked();;

			void on_displayPointsCheckBox_clicked(bool checked);;

			void closeEvent(QCloseEvent *event);

		private:
			void onChange();

		private:
			Ui::VerticalAlignment*	ui_;
			QAction* action_;

			VerticalAlignmentScene* scene_;
		}; 
	} // end namespace UserInterface
} 

namespace buw
{
	using OpenInfraPlatform::UserInterface::VerticalAlignmentWindow;
}
