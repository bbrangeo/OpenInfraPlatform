/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_View_05741137_3101_4ec4_bf4b_61206b15ebce_h
#define OpenInfraPlatform_UserInterface_View_05741137_3101_4ec4_bf4b_61206b15ebce_h

#include "Viewport.h"
#include "buw.BlueApplication.h"
#include "../../DataManagement/Data.h"

#include <QMenuBar>
#include <QDockWidget>
#include <QtWidgets/QVBoxLayout>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class View : public QDockWidget 
		{
			Q_OBJECT;

		public:
			View();

			virtual ~View();

			void setSelectedAlignment( const int index );

			void enableBlueMap( const bool checked );
			void applyBlueMapProperties( const buw::PropertySet& ps );

			void enableTerrainGradientRamp(const bool enable);

			void enableIsoLines(const bool enable);

			void enableDrawTerrainWireframe(const bool enable);

			void enableHideTerrain(const bool enable);

			void setView(eView viewType);

			void showCrossSection( const bool showCrossSection );
			void showDesignCrossSection( const bool showDesignCrossSection );
			void connectCrossSections(const bool connectCrossSections);
			void doSolidCrossSections(const bool solidCrossSections);
			void drawRoadTexture(const bool drawRoadTexture);

			void enableTerrainTextured( const bool enable );

			void enableCreatePoints( const bool enable );

			std::vector<buw::vector3d> getAlignmentPoints();

			void setHighlightDifferentAlignmentElements( const bool enable );
			void setHighlightSelectedAlignmentSegment( const bool enable );

			void	setUseUniformPointColor(const bool useUniformColor);
			void	setUseUniformPointSize(const bool useUniformSize);
			void	setPointSize(const float size);

			buw::vector3d getOffset() const;

			void saveAsScreenshot(const std::string& filename);

			buw::vector2i getSize() const;
			void setViewportSize(const int width, const int height);

			int getViewportWidth() const;

			int getViewportHeight() const;

			void reloadShader();

			void storeGBuffer();

			void cameraControlModeChanged();

			void showFrameTimes(const bool show);

			//---------------------------------------------------------------------------//
			// Camera Control
			//---------------------------------------------------------------------------//

			void setInfraCameraController(buw::InfraCameraController::Ptr controller);
			buw::InfraCameraController::Ptr getInfraCameraController() const;

			void onViewCubeSelectionChanged(buw::eViewCubeOrientation::Enum state);

			void LoadBridge();

		private Q_SLOTS:
			void on_actionPerspective();
			void on_actionOrthographic();
			void on_actionLeft();
			void on_actionRight();
			void on_actionFront();
			void on_actionBack();
			void on_actionTop();
			void on_actionBottom();

			void on_actionIsometric();

			void on_home();
			void on_actionToggleControlMode();
			
		private:
			QAction* actionPerspective_;
			QAction* actionOrthographic_;

			QAction* actionLeft_;
			QAction* actionRight_;
			QAction* actionFront_;
			QAction* actionBack_;
			QAction* actionTop_;
			QAction* actionBottom_;

			QAction* actionIsometric_;

			QAction* controlAction_;
			QAction* homeAction_;

			Viewport*	viewport_;
		}; // end class View
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	//using OpenInfraPlatform::UserInterface::View;
}

#endif // end define OpenInfraPlatform_UserInterface_View_05741137_3101_4ec4_bf4b_61206b15ebce_h
