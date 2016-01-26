/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *	\author			Daniel Below <daniel.below@tum.de>
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef Blueform_UserInterface_MainWindow_aa3f98a6_ba15_4416_ae66_87ca891307d9_h
#define Blueform_UserInterface_MainWindow_aa3f98a6_ba15_4416_ae66_87ca891307d9_h

#include "OpenInfraPlatform/UserInterface/ViewPanel/View.h"
#include "OpenInfraPlatform/UserInterface/XYZImportDialog.h"
#include "OpenInfraPlatform/UserInterface/PreferencesDialog.h"
#include "OpenInfraPlatform/UserInterface/ExportIfcAlignmentDialog.h"
#include "OpenInfraPlatform/UserInterface/ExportIfcZipDialog.h"
#include "OpenInfraPlatform/UserInterface/ExportExcelDialog.h"
#include "OpenInfraPlatform/UserInterface/GenerateTerrainDialog.h"
#include "OpenInfraPlatform/UserInterface/View2DWindow/VerticalAlignmentWindow.h"
#include "OpenInfraPlatform/UserInterface/View2DWindow/CurvatureWindow.h"
#include "OpenInfraPlatform/DataManagement/Data.h"
#include "OpenInfraPlatform/UnitTesting/ImageTester.h"
#include "OpenInfraPlatform/UserInterface/Tools/CreateArcClothoidArcMeth2Dialog.h"
#include "OpenInfraPlatform/UserInterface/Tools/CreateArcClothoidClothoidArcMeth2Dialog.h"
#include "OpenInfraPlatform/UserInterface/Tools/CreateClothoidDialog.h"
#include "OpenInfraPlatform/UserInterface/Tools/CreateLineArcArcLineDialog.h"
#include "OpenInfraPlatform/UserInterface/Tools/CreateLineArcArcArcLineDialog.h"
#include "OpenInfraPlatform/UserInterface/Tools/CreateLineClothoidArcClothoidLineDialog.h"
#include "OpenInfraPlatform/UserInterface/Tools/CreateLineClothoidClothoidLineDialog.h"
#include "OpenInfraPlatform/UserInterface/Tools/CreateArcClothoidArcDialog.h"
#include "OpenInfraPlatform/UserInterface/Tools/CreateArcClothoidClothoidArcDialog.h"
#include "OpenInfraPlatform/UserInterface/OSMImportDialog.h"

#include "qsimpleupdater.h"

#include "buw.BlueApplication.h"
#include "../../QtPropertyBrowser/qttreepropertybrowser.h"
#include "../../QtPropertyBrowser/qtvariantproperty.h"
#include <QMenuBar>
#include <QProgressBar>
#include <QProgressDialog>
#include <setjmp.h>

#include "PrecisionTest.h"
#include <QDropEvent>
#include <qmimedata>

namespace Ui 
{
	class MainWindow;
}

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class MainWindow
		//! \brief brief description
		class MainWindow : public BlueFramework::Application::UserInterface::MainWindowBase
		{
			Q_OBJECT;
			
			typedef DataManagement::ChangeFlag ChangeFlag;

		public:
			//! Default constructor.
			MainWindow(QWidget *parent = nullptr);
			
			//! Virtual destructor.
			virtual ~MainWindow();

			void showEvent(QShowEvent* event);
			void updateAlignmentUI();
			void updateAlignmentElementsUI();
			void emitPoints(QDialog*); // for the communication between menue/tools and MainWindow
			void storeGBuffer();
			virtual void changeEvent(QEvent* evt) override;

			void checkForUpdates();

		public Q_SLOTS:
			void on_actionNew_triggered();
			void on_actionSave_triggered();
			void on_actionSaveAs_triggered();
			//void on_actionImport_triggered();

			void on_actionMerge_Mesh_triggered();

			void on_actionOpen_triggered();
			void on_actionUndo_triggered();
			void on_actionRedo_triggered();
			void on_actionViewport_as_screenshot_triggered();
			void on_actionExit_triggered();
			void on_actionUsualSVG_triggered();
			void on_actionAdvancedSVG_triggered();
			void on_actionExportIIfcRoad_triggered();
			void on_actionAbout_triggered();
			void on_actionCreate_Alignment_Points_triggered(bool checked);
			void on_actionCreate_Alignment_triggered();
			void on_actionCreate_Arc_Clothoid_Arc_triggered();
			void on_actionCreate_Arc_Clothoid_Arc2_triggered();
			void on_actionCreate_Arc_Clothoid_Clothoid_Arc_triggered();
			void on_actionCreate_Arc_Clothoid_Clothoid_Arc2_triggered();
			void on_actionCreate_Line_Clothoid_Arc_Clothoid_Line_triggered();
			void on_actionCreate_Line_Clothoid_Clothoid_Line_triggered();
			void on_actionCreate_Line_Arc_Arc_Line_triggered();
			void on_actionCreate_Line_Arc_Arc_Arc_Line_triggered();
			void on_actionCreate_Line_Clothoid_triggered();
			void on_actionExportIfcAlignment_triggered();
			/*new*/
			void on_actionExportIfcZip_triggered();
			void on_actionIfcAlignment_buildingSMART_P6_Excel_Comparison_triggered();
			void on_actionOkstra_triggered();
			void on_actionLandXML_triggered();
			void on_actionHorizontal_alignment_triggered();
			void on_actionVertical_alignment_3D_triggered();
			void on_action3D_triggered();
			void on_actionVertical_alignment_triggered();
			void on_actionCurvature_triggered();

			void on_actionLoad_Bridge();
			void on_actionPrecisionTest();

			void on_actionTerrain_Hide_triggered(bool checked);
			void on_actionTerrain_Wireframe_triggered(bool checked);
			void on_actionTerrain_Textured_triggered(bool checked);
			void on_actionTerrain_Gradient_Ramp_triggered(bool checked);
			void on_actionTerrain_Iso_Lines_triggered(bool checked);
			void on_actionMerge_XYZ_File_triggered();
			void on_actionTerrain_Generate_Random_Terrain_triggered();
			void on_actionTerrain_Create_Terrain_from_Heightmap_triggered();

			void on_actionShow_Cross_Section_triggered(bool checked);
			void on_actionShow_Design_Cross_Section_triggered(bool checked);
			void on_actionRoad_body_wireframe_triggered(bool checked);
			void on_actionRoad_body_solid_triggered(bool checked);
			void on_actionDraw_Road_Texture_triggered(bool checked);

			void on_checkBoxDifferentColorsForVerticalAlignmentElements_clicked(bool checked);

		

			void on_actionExport_Terrain_As_Heightmap_triggered();

			void on_pushButtonDeleteSelectedAlignment_clicked();
			void on_pushButtonDeleteSurface_clicked();

			void on_actionShow_Help_triggered();

			void on_actionExportVerticalAlignment_triggered();
			void on_actionExportCurvature_triggered();

			void on_actionCheck_for_Updates_triggered();
			void on_actionPreferences_triggered();
			void on_checkBoxShowMap_clicked (bool checked);
			void on_checkBoxShowDifferentAlignmentElements_clicked(bool checked);

			void on_checkBoxHighlightSelectedAlignmentSegment_clicked(bool checked);

			void on_comboBoxAlignment_currentIndexChanged( int index );
			void on_actionMerge_LAS_File_triggered();
			void on_comboBoxMapSize_currentIndexChanged( int index );

			void on_variantEditor_currentItemChanged(QtBrowserItem * item);

			void on_actionAlignments_as_3D_Points_txt_triggered();

			void on_checkBoxUseUniformColor_clicked(bool checked);
			void on_checkBoxUseUniformSize_clicked(bool checked);
			void on_doubleSpinBoxPointSize_valueChanged(double value);
			void on_horizontalSliderPointSize_sliderMoved(int value);

			void on_actionImport_OSM_File_triggered();

			// Recent files
			void on_actionRecentFile1_triggered();
			void on_actionRecentFile2_triggered();
			void on_actionRecentFile3_triggered();
			void on_actionRecentFile4_triggered();
			void on_actionRecentFile5_triggered();
			void on_actionRecentFile6_triggered();
			void on_actionRecentFile7_triggered();
			void on_actionRecentFile8_triggered();
			void on_actionRecentFile9_triggered();
			void on_actionRecentFile10_triggered();
			void on_actionClearMenu_triggered();

			// updater
			void onCheckingFinished();

		private:
			void createClothoid();

			// Todo move recent files functionality to MainWindowBase
			void addToRecentFilesList(const QString &fileName);
			void updateRecentFileActions();
			QString strippedName(const QString &fullFileName);

		private Q_SLOTS:
			void ImageQualityBasedUnitTesting();
			void actionGetCameraState();

			void showMap();
			void reloadShader();

			void cancelJob();

			void aboutQt();

		private:
			void jobStarting();
			void jobRunning(int id, float progress, const std::string& message);
			void jobFinishing(int id, bool completed);
			void jobFinished(int id, bool completed);

			void prepareTest(int i);
			void performTest(int i);

			void openRecentFileViaAction( QAction *actionRecentFile );

			void	onChange();
			void	onChange(ChangeFlag changeFlag);

			void updateActionUndo( unsigned int numberOfUndoActions );

			void updateActionRedo(unsigned int numberOfRedoActions);

			void retranslatePropertyBrowser();
		private:
			// RegEx to parse the window title and capture the document state
			// RegEx matches "TUM Open Infra Platform YYYY - [Filename]", and captures "Filename"
			const QRegExp				titleRegex = QRegExp { "^TUM Open Infra Platform \\d{4} \\(.*\\)\\s+-\\s+\\[(.*)\\]$" };

			// URLs for QSimpleUpdater
			const QString				changeLogUrl { "https://www.cms.bgu.tum.de/oip/update/change_log.txt" };
			const QString				currentVersionUrl { "https://www.cms.bgu.tum.de/oip/update/current_version.txt" };
			const QString				installerUrl { "https://www.cms.bgu.tum.de/oip/update/TUM%20Open%20Infra%20Platform.msi" };

			std::unique_ptr<QSimpleUpdater> updater;

			QtProperty*					propertyHorizontalAlignment_;
			QtProperty*					propertyVerticalAlignment_;
			QtVariantPropertyManager*	variantManager_;
			QtTreePropertyBrowser*		variantEditor_;
			QtVariantProperty*			itemStartStation_;
			QtVariantProperty*			itemEndStation_;
			QtVariantProperty*			itemLength_;

			// Dialogs
			ExportExcelDialog*			exportExcelDialog_;
			ExportIfcAlignmentDialog*	exportP6AlignmentDialog_;
			/*new*/
			ExportIfcZipDialog*			exportIfcZipDialog_;
			PreferencesDialog*			preferencesDialog_;
			XYZImportDialog*			XYZImportDialog_;
			GenerateTerrainDialog*		generateTerrainDialog_;
			CreateLineArcArcLineDialog*	LAAL_;
			CreateLineArcArcArcLineDialog* LAAAL_;
			CreateLineClothoidArcClothoidLineDialog* LCACL_;
			CreateLineClothoidClothoidLineDialog* LCCL_;
			CreateArcClothoidClothoidArcDialog* ACCA_;
			CreateClothoidDialog*		LC_;
			CreateArcClothoidClothoidArcMeth2Dialog* ACCA2_;
			CreateArcClothoidArcMeth2Dialog* ACA2_;
			CreateArcClothoidArcDialog* ACA_;
			VerticalAlignmentWindow*	verticalAlignmentWindow_;
			CurvatureWindow*			curvatureWindow_;
			OSMImportDialog*			osmImportDialog_;

			QProgressBar*				progressBar_;
			QProgressDialog*			progressDialog_;

			int							inUnitTest_ = -1;
			buw::ImageTester			tester;

			View*						view_;
			Ui::MainWindow *			ui_;

			bool						loaded_;

			PrecisionTest				precisionTest_;

			protected:
				void dropEvent(QDropEvent *ev);
				void dragEnterEvent(QDragEnterEvent *ev);
			Q_SIGNALS:
			void sendPoints(std::vector<buw::vector3d> , buw::vector2d );// for the communication with the tool-dialogs like CreateArcClothoidArcDialog
		}; // end class MainWindow
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

#endif // end define Blueform_UserInterface_MainWindow_aa3f98a6_ba15_4416_ae66_87ca891307d9_h