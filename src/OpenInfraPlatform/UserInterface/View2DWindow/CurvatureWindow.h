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
#include <QDockWidget>
#include <boost/noncopyable.hpp>
#include "ui_CurvatureWindow.h"
#include "../../DataManagement/Data.h"
#include <vector>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class CurvatureScene : public Alignment2DScene
		{
		public:
			CurvatureScene(QObject *parent = 0);

		protected:
			void v_drawAlignment(buw::ReferenceCounted<buw::Alignment2DBased3D> a,
				std::map<buw::eHorizontalAlignmentType, QPainterPath>& horizontalPainter,
				std::map<buw::eVerticalAlignmentType, QPainterPath>& verticalPainter) override;
		};



		// Window
		class CurvatureWindow : public QDockWidget
		{
			Q_OBJECT;

		public:
			CurvatureWindow(QAction* act);

			void setHighlightDifferentAlignmentElements(bool checked);
			void setDifferentColorsForVerticalAlignmentElements(bool checked);

			void exportToFile();;

			void closeEvent(QCloseEvent *event);

		private:
			void onChange();

		private:
			Ui::Curvature*	ui_;
			QAction* action_;

			CurvatureScene* scene_;
		}; 
	} 
} 

namespace buw
{
	using OpenInfraPlatform::UserInterface::CurvatureWindow;
}
