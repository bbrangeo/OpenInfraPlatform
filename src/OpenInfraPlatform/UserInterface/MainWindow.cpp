/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \author			Daniel Below <daniel.below@tum.de>
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "OpenInfraPlatform/UserInterface/MainWindow.h"
#include "ui_mainwindow.h"
#include "resource.h"
#include "OpenInfraPlatform/DataManagement/Command/DeleteAlignment.h"
#include "OpenInfraPlatform/DataManagement/Command/DeleteSurface.h"
#include "OpenInfraPlatform/Benchmark.h"
#include "OpenInfraPlatform/UserInterface/HelpBrowser.h"
#include "ColorPicker/colorpickerwidget.h"
#include "buw.BlueInfrastructure.h"
#include "buw.BlueImageProcessing.h"
#include "BlueFramework/Core/platform.h"
#include "fvupdater.h"
#include <QLabel>
#include <QLineEdit>
#include <QSettings>
#include <QInputDialog>
#include <QUuid>
#include <iostream>

#include "OpenInfraPlatform/DataManagement/AsyncJob.h"

#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DClothoid.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DClothoid_old.h"

const QRegExp OpenInfraPlatform::UserInterface::MainWindow::titleRegex = QRegExp { "^TUM Open Infra Platform \\d{4} \\(.*\\)\\s+-\\s+\\[(.*)\\]$" };

OpenInfraPlatform::UserInterface::MainWindow::MainWindow( QWidget *parent /*= nullptr*/ ) : 
	BlueFramework::Application::UserInterface::MainWindowBase(&OpenInfraPlatform::DataManagement::DocumentManager::getInstance(), parent),
	ui_(new Ui::MainWindow),
	verticalAlignmentWindow_(nullptr),
	curvatureWindow_(nullptr)
{
	ui_->setupUi(this);
	variantEditor_ = new QtTreePropertyBrowser();

	variantManager_ = new QtVariantPropertyManager();
	
	propertyHorizontalAlignment_ = variantManager_->addProperty(QtVariantPropertyManager::groupTypeId());
	propertyVerticalAlignment_ = variantManager_->addProperty(QtVariantPropertyManager::groupTypeId());
	
	itemStartStation_ = variantManager_->addProperty(QVariant::Double);
	itemStartStation_->setValue(0);
	itemEndStation_ = variantManager_->addProperty(QVariant::Double);
	itemStartStation_->setValue(0);
	itemLength_ = variantManager_->addProperty(QVariant::Double);
	itemLength_->setValue(0);
	
	variantEditor_->setStyleSheet("");
	variantEditor_->setFactoryForManager(variantManager_, new QtVariantEditorFactory());
	variantEditor_->addProperty(itemStartStation_);
	variantEditor_->addProperty(itemEndStation_);
	variantEditor_->addProperty(itemLength_);
	variantEditor_->setPropertiesWithoutValueMarked(true);
	variantEditor_->setRootIsDecorated(false);
	variantEditor_->addProperty(propertyHorizontalAlignment_);
	variantEditor_->addProperty(propertyVerticalAlignment_);
				
	ui_->verticalLayoutAlignment->addWidget( variantEditor_ );

	view_ = new View();
	addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, view_, Qt::Orientation::Horizontal);

	updateWindowTitle("Untitled");

	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().Change.connect(boost::bind(&MainWindow::onChange, this));
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().RedoStackChanged.connect(boost::bind(&MainWindow::updateActionRedo, this, _1));
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().UndoStackChanged.connect(boost::bind(&MainWindow::updateActionUndo, this, _1));
	
	OpenInfraPlatform::AsyncJob::getInstance().jobStarted.connect(boost::bind(&MainWindow::jobStarted, this, _1));
	OpenInfraPlatform::AsyncJob::getInstance().jobRunning.connect(boost::bind(&MainWindow::jobRunning, this, _1, _2, _3));
	OpenInfraPlatform::AsyncJob::getInstance().jobFinishing.connect(boost::bind(&MainWindow::jobFinishing, this, _1, _2));
	OpenInfraPlatform::AsyncJob::getInstance().jobFinished.connect(boost::bind(&MainWindow::jobFinished, this, _1, _2));

	preferencesDialog_ = new PreferencesDialog(view_, this);
	XYZImportDialog_ = new XYZImportDialog(this);
	generateTerrainDialog_ = new GenerateTerrainDialog(this);
	verticalAlignmentWindow_ = new VerticalAlignmentWindow(ui_->actionVertical_alignment);
	curvatureWindow_ = new CurvatureWindow(ui_->actionCurvature);
	exportP6AlignmentDialog_ = new ExportIfcAlignmentDialog(this);
	exportIfcZipDialog_ = new ExportIfcZipDialog(this);
	exportExcelDialog_ = new ExportExcelDialog(this);
	createLineClothoidClothoidLineDialog_ = new CreateLineClothoidClothoidLineDialog(this);
	createLineClothoidArcClothoidLineDialog_ = new CreateLineClothoidArcClothoidLineDialog(this);
	createLineArcArcLineDialog_ = new CreateLineArcArcLineDialog(this);
	createLineArcArcArcLineDialog_ = new CreateLineArcArcArcLineDialog(this);
	createArcClothoidArcDialog_ = new CreateArcClothoidArcDialog(this);
	createArcClothoidClothoidArcDialog_ = new CreateArcClothoidClothoidArcDialog(this);
	createClothoidDialog_ = new CreateClothoidDialog(this);
	createArcClothoidArcMeth2Dialog_ = new CreateArcClothoidArcMeth2Dialog(this);
	createArcClothoidClothoidArcMeth2Dialog_ = new CreateArcClothoidClothoidArcMeth2Dialog(this);
	createClothoidParallelDialog_ = new CreateClothoidParallelDialog(this);

	updateRecentFileActions();

#ifdef _DEBUG
	// Show debug menu only in debug mode

	QMenu* menuDebug = new QMenu("Debug");
	ui_->menuBar->addMenu(menuDebug);

	QAction* imageQualityBasedUnitTesting = menuDebug->addAction(tr("Image Quality Based Unit Testing"));
	QAction* actionGetCameraState = menuDebug->addAction(tr("Get Camera State"));
	QAction* actionShowMap = menuDebug->addAction(tr("Show/Hide Map"));
	QAction* actionReloadShader = menuDebug->addAction(tr("Reload shader"));
	QAction* actionAboutQt = menuDebug->addAction(tr("About Qt"));
	QAction* actionStoreGBuffer = menuDebug->addAction(tr("Store GBuffer"));
	QAction* actionCreateClothoid = menuDebug->addAction(tr("Create Clothoid"));
	QAction* actionShowVerticalAlignment3D = menuDebug->addAction(tr("Vertical alignment 3D"));
	QAction* actionLoadBridge = menuDebug->addAction(tr("Load Bridge"));
	QAction* actionPrecisionTest = menuDebug->addAction(tr("Precision Test"));

	QObject::connect(imageQualityBasedUnitTesting, &QAction::triggered, this, &MainWindow::ImageQualityBasedUnitTesting);
	QObject::connect(actionGetCameraState, &QAction::triggered, this, &MainWindow::actionGetCameraState);
	QObject::connect(actionShowMap, &QAction::triggered, this, &MainWindow::showMap);
	QObject::connect(actionReloadShader, &QAction::triggered, this, &MainWindow::reloadShader);
	QObject::connect(actionShowMap, &QAction::triggered, this, &MainWindow::showMap);
	QObject::connect(variantEditor_, &QtTreePropertyBrowser::currentItemChanged, this, &MainWindow::on_variantEditor_currentItemChanged);
	QObject::connect(actionAboutQt, &QAction::triggered, this, &MainWindow::aboutQt);
	QObject::connect(actionStoreGBuffer, &QAction::triggered, this, &MainWindow::storeGBuffer);
	QObject::connect(actionCreateClothoid, &QAction::triggered, this, &MainWindow::createClothoid);
	QObject::connect(actionShowVerticalAlignment3D, &QAction::triggered, this, &MainWindow::on_actionVertical_alignment_3D_triggered);
	QObject::connect(actionLoadBridge, &QAction::triggered, this, &MainWindow::on_actionLoad_Bridge);
	QObject::connect(actionPrecisionTest, &QAction::triggered, this, &MainWindow::on_actionPrecisionTest);


#endif

	ui_->comboBoxMapSize->addItem(  "1:1" );
	ui_->comboBoxMapSize->addItem(  "1:2" );
	ui_->comboBoxMapSize->addItem(  "1:4" );
	ui_->comboBoxMapSize->addItem(  "1:8" );

	ui_->tabMap->setVisible(false);

	Benchmark::getInstance().finishStartup();
	Benchmark::getInstance().print();

	// show data progress
	progressBar_ = new QProgressBar(ui_->statusBar);
	ui_->statusBar->addPermanentWidget(progressBar_);
	progressBar_->hide();

	progressDialog_ = new QProgressDialog(this);
	progressDialog_->setWindowTitle(tr("Please wait"));
	progressDialog_->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
	progressDialog_->setMinimumWidth(500);
	progressDialog_->setAutoClose(false);
	progressDialog_->setAutoReset(false);
	progressDialog_->hide();
	QObject::connect(progressDialog_, SIGNAL(canceled()), this, SLOT(cancelJob()));
	QObject::disconnect(progressDialog_, SIGNAL(canceled()), progressDialog_, SLOT(cancel()));

	ui_->doubleSpinBoxPointSize->setValue(3.0);
	on_doubleSpinBoxPointSize_valueChanged(3.0);

	retranslatePropertyBrowser();

	// "testdata/LandXML/CityCad/Sito_Tie.xml"
	// "testdata/Okstra/entwurf_s_achse-1_g_l_1014/Entwurf_S_Achse-1_G_L_1014.xml"
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/Mainbruecke_Klingenberg.xml");

	updater = std::make_unique<QSimpleUpdater>(this);

	// set version and urls
	updater->setApplicationVersion(QApplication::applicationVersion());
	updater->setReferenceUrl("http://Server:Port/.../current_version.txt");
	updater->setDownloadUrl("http://Server:Port/.../OpenInfraPlatform.msi");

	connect(updater.get(), SIGNAL(checkingFinished()), this, SLOT(onCheckingFinished()));
	
	checkForUpdates();
}

void OpenInfraPlatform::UserInterface::MainWindow::checkForUpdates()
{	
	updater->checkForUpdates();
}

void OpenInfraPlatform::UserInterface::MainWindow::onCheckingFinished()
{
	if (updater->newerVersionAvailable())
	{
		auto updateText = tr("There is a newer version (%1) available. Do you want to download?").arg(updater->latestVersion());
		auto reply = QMessageBox::question(
			this, 
			tr("Update available"), 
			updateText,
			QMessageBox::Yes | QMessageBox::No
		);

		if (reply == QMessageBox::Yes)
		{
			updater->downloadLatestVersion();
		}
	}
}

OpenInfraPlatform::UserInterface::MainWindow::~MainWindow()
{
	delete exportExcelDialog_;
	exportExcelDialog_ = nullptr;

	delete exportP6AlignmentDialog_;
	exportP6AlignmentDialog_ = nullptr;

	delete XYZImportDialog_;
	XYZImportDialog_ = nullptr;
	
	delete preferencesDialog_;
	preferencesDialog_ = nullptr;

	delete generateTerrainDialog_;
	generateTerrainDialog_ = nullptr;

	delete createLineArcArcLineDialog_;
	createLineArcArcLineDialog_ = nullptr;

	delete createLineArcArcArcLineDialog_;
	createLineArcArcArcLineDialog_ = nullptr;

	delete createArcClothoidArcDialog_;
	createArcClothoidArcDialog_ = nullptr;

	delete createArcClothoidClothoidArcDialog_;
	createArcClothoidClothoidArcDialog_ = nullptr;

	delete createLineClothoidClothoidLineDialog_;
	createLineClothoidClothoidLineDialog_ = nullptr;

	delete createLineClothoidArcClothoidLineDialog_;
	createLineClothoidArcClothoidLineDialog_ = nullptr;

	delete createClothoidDialog_;
    createClothoidDialog_ = nullptr;

	delete verticalAlignmentWindow_;
	verticalAlignmentWindow_ = nullptr;

	delete curvatureWindow_;
	curvatureWindow_ = nullptr;
	
	delete ui_;
	ui_ = nullptr;
	
	delete createClothoidParallelDialog_;
	createClothoidParallelDialog_ = nullptr;
	
	delete createArcClothoidArcMeth2Dialog_;
	createArcClothoidArcMeth2Dialog_ = nullptr;
	
	delete createArcClothoidClothoidArcMeth2Dialog_;
	createArcClothoidClothoidArcMeth2Dialog_ = nullptr;
}

void OpenInfraPlatform::UserInterface::MainWindow::storeGBuffer()
{
	view_->storeGBuffer();
}

void OpenInfraPlatform::UserInterface::MainWindow::changeEvent(QEvent* evt)
{
	if (evt->type() == QEvent::LanguageChange)
	{	
		int pos = -1;

		std::string newTitle;

		// check if there is a match
		if ((pos = titleRegex.indexIn(this->windowTitle())) != -1)
		{
			// translate the matched string
			newTitle = tr(titleRegex.cap(1).toStdString().c_str()).toStdString();
			
		}

		// retranslate designer form (single inheritance approach)
		ui_->retranslateUi(this);	

		if (pos != -1)
		{
			// update the title after it was overwritten by the normal translation call and if there was a match
			updateWindowTitle(newTitle);
		}

		retranslatePropertyBrowser();
	}
	else
	{
		// remember to call base class implementation
		QMainWindow::changeEvent(evt);
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::retranslatePropertyBrowser()
{
	//attention: this function just works if R1>R2
	itemStartStation_->setPropertyName(tr("Start Station"));
	itemEndStation_->setPropertyName(tr("End Station"));
	itemLength_->setPropertyName(tr("Length [m]"));
	
	propertyHorizontalAlignment_->setPropertyName(tr("Horizontal Alignment"));
	propertyVerticalAlignment_->setPropertyName(tr("Vertical Alignment"));
	variantEditor_->translateHeader();
	on_comboBoxAlignment_currentIndexChanged(verticalAlignmentWindow_->getSelectedAlignment());
}

void OpenInfraPlatform::UserInterface::MainWindow::createClothoid_noInfinity(double R1, double R2, buw::vector2d theo, double A, buw::vector2d cloth_start_dir, bool clockwise)
{
	//attention R1>R2
	double L1 = A*A / R1;
	double L2 = A*A / R2;
	double L = L2 - L1;
	buw::vector2d endPoint, HendPoint1, HendPoint2, x_axis = { 1.0, 0.0 };
	HendPoint1.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A);
	HendPoint1.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A);
	HendPoint2.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A);
	HendPoint2.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A);
	double tau1 = L1 / (2 * R1);
	double tau2 = L2 / (2 * R2);
	if (clockwise == true)
	{
		HendPoint1.y() = -HendPoint1.y();
		HendPoint2.y() = -HendPoint2.y();
		tau1 = -tau1;
		tau2 = -tau2;
	}
	double lineangle = buw::calculateAngleBetweenVectors(x_axis, cloth_start_dir);
	endPoint = theo + buw::createRotationZ22d(lineangle)*HendPoint2;
	buw::vector2d startDir = buw::createRotationZ22d(tau1)*cloth_start_dir;
	buw::vector2d startPoint = theo + buw::createRotationZ22d(lineangle)*HendPoint1;
	buw::vector2d endDir = buw::createRotationZ22d(tau2)*  cloth_start_dir;
	buw::Line2d line1(startPoint, startPoint + startDir);
	buw::Line2d line2(endPoint, endPoint - endDir);
	buw::vector2d pi;
	auto PI = buw::computeIntersection(line1, line2, pi);
	buw::HorizontalAlignmentElement2DClothoid_old::Ptr c = std::make_shared<buw::HorizontalAlignmentElement2DClothoid_old>(
		startPoint,
		endPoint,
		pi,
		L,
		R1,
		R2,
		clockwise
		);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment->addElement(c);
	buw::Alignment2DBased3D::Ptr a = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(a);
}

void OpenInfraPlatform::UserInterface::MainWindow::createClothoid_negY(double R, double A, buw::vector2d startPoint, buw::vector2d cloth_start_dir, bool clockwise)
{
	double L = A*A / R;
	buw::vector2d endPoint, HendPoint, x_axis = { 1.0, 0.0 };
	HendPoint.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L, A);
	HendPoint.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L, A);
	double tau = L / (2 * R);
	if (clockwise == true)
	{
		HendPoint.y() = -HendPoint.y();
		tau = -tau;
	}
	double lineangle = buw::calculateAngleBetweenVectors(x_axis, cloth_start_dir);
	endPoint = startPoint + buw::createRotationZ22d(lineangle)*HendPoint;
	double radiusStart = std::numeric_limits<double>::infinity();
	buw::vector2d startDir = cloth_start_dir;
	buw::vector2d endDir = buw::createRotationZ22d(tau)*  cloth_start_dir;
	buw::Line2d line1(startPoint, startPoint + startDir);
	buw::Line2d line2(endPoint, endPoint - endDir);
	buw::vector2d pi;
	auto PI = buw::computeIntersection(line1, line2, pi);
	buw::HorizontalAlignmentElement2DClothoid_old::Ptr c = std::make_shared<buw::HorizontalAlignmentElement2DClothoid_old>(
		startPoint,
		endPoint,
		pi,
		L,
		radiusStart,
		R,
		clockwise
		);
	buw::HorizontalAlignment2D::Ptr horizontalClothoid = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalClothoid->addElement(c);
	buw::Alignment2DBased3D::Ptr a = std::make_shared<buw::Alignment2DBased3D>(horizontalClothoid);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(a);
}
	 
void OpenInfraPlatform::UserInterface::MainWindow::createClothoid()
{
	buw::vector2d startPoint(0.0, 0.0);
	double L = 100;
	double A = 60;
	double R = A * A / L;
	buw::vector2d endPoint;
	endPoint.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L, A);
	endPoint.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L, A);
	double radiusStart = std::numeric_limits<double>::infinity();
	double radiusEnd = R;
	bool clockwise = false;
	buw::vector2d startDir = buw::createRotationZ22d(0.0) * buw::vector2d(1.0, 0.0);
	double tau = L / 2 * R;
	buw::vector2d endDir = buw::createRotationZ22d(tau) * buw::vector2d(1.0, 0.0);
	buw::Line2d line1(startPoint, startPoint + startDir);
	buw::Line2d line2(endPoint, endPoint - endDir);
	buw::vector2d pi;
	auto PI = buw::computeIntersection(line1, line2, pi);
	buw::HorizontalAlignmentElement2DClothoid_old::Ptr c = std::make_shared<buw::HorizontalAlignmentElement2DClothoid_old>(
		startPoint,
		endPoint,
		pi,
		L,
		radiusStart,
		radiusEnd,
		clockwise
		);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment->addElement(c);
	buw::Alignment2DBased3D::Ptr a = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(a);
}

//---------------------------------------------------------------------------//
// Recent files
//---------------------------------------------------------------------------//

void OpenInfraPlatform::UserInterface::MainWindow::on_actionExit_triggered()
{
	close();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile1_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile1);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile2_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile2);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile3_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile3);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile4_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile4);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile5_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile5);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile6_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile6);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile7_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile7);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile8_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile8);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile9_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile9);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRecentFile10_triggered()
{
	openRecentFileViaAction(ui_->actionRecentFile10);
}

void OpenInfraPlatform::UserInterface::MainWindow::addToRecentFilesList(
	const QString &fileName)
{
	const int MaxRecentFiles = 10; 

	if(fileName.isEmpty())
		return;

	setWindowFilePath(fileName);

	QSettings settings;
	QStringList files = settings.value("recentFileList").toStringList();
	files.removeAll(fileName);
	files.prepend(fileName);
	while (files.size() > MaxRecentFiles)
		files.removeLast();

	settings.setValue("recentFileList", files);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionClearMenu_triggered()
{
	QSettings settings;
	QStringList files = settings.value("recentFileList").toStringList();
	files.clear();
	settings.setValue("recentFileList", files);

	ui_->actionRecentFile1->setVisible(false);
	ui_->actionRecentFile2->setVisible(false);
	ui_->actionRecentFile3->setVisible(false);
	ui_->actionRecentFile4->setVisible(false);
	ui_->actionRecentFile5->setVisible(false);
	ui_->actionRecentFile6->setVisible(false);
	ui_->actionRecentFile7->setVisible(false);
	ui_->actionRecentFile8->setVisible(false);
	ui_->actionRecentFile9->setVisible(false);
	ui_->actionRecentFile10->setVisible(false);
}

//---------------------------------------------------------------------------//
// Other
//---------------------------------------------------------------------------//
void OpenInfraPlatform::UserInterface::MainWindow::on_actionExportIIfcRoad_triggered()
{
	QString filename = QFileDialog::getSaveFileName(
		this,
		tr("Save Document"),
		QDir::currentPath(),
		tr("IfcRoad Step File (*.ifc);;Zip compressed IfcRoad Step File (*.ifczip)") );

	if( !filename.isNull() )
	{
		
		if (filename.endsWith(".ifc")) {
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportIfcRoadTUMProposal(
				filename.toStdString());
		}
		
		else if (filename.endsWith("zip")) {
			QUuid id = QUuid::createUuid();
			QString tempFilename = QDir::currentPath().append(QString("/").append(id.toString().append(".ifc")));

			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportIfcRoadTUMProposal(
				tempFilename.toStdString());

			OpenInfraPlatform::DataManagement::IfcZipper* ExportZipper = new OpenInfraPlatform::DataManagement::IfcZipper(nullptr, QString(filename.data()), tempFilename, DEFL);

			QObject::connect(&OpenInfraPlatform::AsyncJob::getInstance(), SIGNAL(finished()), ExportZipper, SLOT(start()));
			QObject::connect(ExportZipper, &OpenInfraPlatform::DataManagement::IfcZipper::finished, ExportZipper, &QObject::deleteLater);
		}
		
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionExportIfcAlignment_triggered()
{
	exportP6AlignmentDialog_->show();
}

/*new*/
void OpenInfraPlatform::UserInterface::MainWindow::on_actionExportIfcZip_triggered() {
	exportIfcZipDialog_->show();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionAbout_triggered()
{
	QString head, desc;

	head = tr( "<h2><b>TUM Open Infra Platform 2015 RTM</b><br/></h2>" );
	
	const QString copyright( tr( "Copyright &copy; 2013 - 2015" ) );

	desc = QString( "%1<br/>Technische Universit&auml;t M&uuml;nchen<br/>"
		"Faculty of Civil, Geo and Environmental Engineering<br/>"
		"Chair of Computational Modeling and Simulation<br/><br>"
		"Website: <a href=\"http://www.cms.bgu.tum.de/oip\"><font color=\"#48B7E7\">http://www.cms.bgu.tum.de/oip</font></a><br/>"
		"Please send your bug reports or support requests to Julian Amann &lt;<a href=\"mailto:julian.amann@tum.de?subject=Bug Report\"><font color=\"#48B7E7\">julian.amann@tum.de</font></a>&gt;<br/><br/>").arg( copyright );

	QMessageBox::about( this, tr( "About TUM Open Infra Platform 2015" ), head + desc );
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionHorizontal_alignment_triggered()
{
	ui_->actionHorizontal_alignment->setChecked(true);
	ui_->actionShow_Cross_Section->setEnabled(false);
	ui_->action3D->setChecked(false);

	view_->setView(eView::HorizontalAlignment);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionVertical_alignment_3D_triggered()
{
	ui_->actionHorizontal_alignment->setChecked(false);
	ui_->actionShow_Cross_Section->setEnabled(false);
	ui_->action3D->setChecked(false);


	view_->enableHideTerrain(true);
	ui_->actionTerrain_Hide->setChecked(true);
	view_->setView(eView::VerticalAlignment);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_action3D_triggered()
{
	ui_->actionHorizontal_alignment->setChecked(false);
	ui_->actionShow_Cross_Section->setEnabled(true);
	ui_->action3D->setChecked(true);

	view_->setView(eView::ThreeDimensional);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionVertical_alignment_triggered()
{
	ui_->actionVertical_alignment->setChecked(true);
	verticalAlignmentWindow_->show();
	addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, verticalAlignmentWindow_);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionCurvature_triggered()
{
	ui_->actionCurvature->setChecked(true);
	curvatureWindow_->show();
	addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea,curvatureWindow_);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionTerrain_Hide_triggered(bool checked)
{
	view_->enableHideTerrain(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionTerrain_Wireframe_triggered(bool checked)
{
	view_->enableDrawTerrainWireframe(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionTerrain_Textured_triggered(bool checked)
{
	view_->enableTerrainTextured(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionTerrain_Gradient_Ramp_triggered(bool checked)
{
	view_->enableTerrainGradientRamp(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionTerrain_Iso_Lines_triggered(bool checked)
{
	view_->enableIsoLines(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionTerrain_Import_XYZ_File_triggered()
{
	XYZImportDialog_->show();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionTerrain_Generate_Random_Terrain_triggered()
{
	generateTerrainDialog_->show();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionTerrain_Create_Terrain_from_Heightmap_triggered()
{
	QString openFile = QFileDialog::getOpenFileName(
		this,
		tr("Open File"),
		QDir::currentPath(),
		tr("Portable Network Graphics (*.png);;Bitmap (*.bmp);;JPEG (*.jpg);;TIFF (*.tif)")
		);

	if (openFile.isNull() == false)
	{
		std::string filename = openFile.toUtf8().constData();

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().createTerrainFromHeightMap(filename);
	}
}


void OpenInfraPlatform::UserInterface::MainWindow::on_actionShow_Cross_Section_triggered(bool checked)
{
	view_->showCrossSection(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionShow_Design_Cross_Section_triggered(bool checked)
{
	view_->showDesignCrossSection(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRoad_body_wireframe_triggered(bool checked)
{
	view_->connectCrossSections(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRoad_body_solid_triggered(bool checked)
{
	view_->doSolidCrossSections(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDraw_Road_Texture_triggered(bool checked)
{
	view_->drawRoadTexture(checked);
}



void OpenInfraPlatform::UserInterface::MainWindow::on_actionExportVerticalAlignment_triggered()
{
	verticalAlignmentWindow_->exportToFile();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionExportCurvature_triggered()
{
	curvatureWindow_->exportToFile();
}

void OpenInfraPlatform::UserInterface::MainWindow::updateAlignmentUI()
{
	buw::AlignmentModel::Ptr am = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel();

	ui_->comboBoxAlignment->clear();
	for (int i = 0; i < am->getAlignmentCount(); i++)
	{
		buw::IAlignment3D::Ptr alignment = am->getAlignment(i);

		ui_->comboBoxAlignment->addItem(  alignment->getName().toCString() );
	}

	if(am->getAlignmentCount() > 0)
	{
		if (am->getAlignment(0)->getType() == buw::e3DAlignmentType::e2DBased)
		{
			buw::Alignment2DBased3D::Ptr a = std::static_pointer_cast<buw::Alignment2DBased3D>(am->getAlignment(0));

			buw::Alignment2DBased3D::Ptr currentAlignment = a;

			itemStartStation_->setValue(currentAlignment->getStartStation());
			itemEndStation_->setValue(currentAlignment->getEndStation());
			itemLength_->setValue(currentAlignment->getLength());
		}
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::onChange()
{
	updateAlignmentUI();

	buw::DigitalElevationModel::Ptr dem = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getDigitalElevationModel();

	ui_->comboBoxSurfaces->clear();
	for (int i = 0; i < dem->getSurfaceCount(); i++)
	{
		buw::Surface::Ptr surface = dem->getSurface(i);

		ui_->comboBoxSurfaces->addItem(surface->getName());
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_comboBoxAlignment_currentIndexChanged( int index )
{
	// clear horizontal alignment properties
	while (propertyHorizontalAlignment_->subProperties().size() > 0)
	{
		propertyHorizontalAlignment_->removeSubProperty(propertyHorizontalAlignment_->subProperties()[0]);
	}

	// clear vertical alignment properties
	while (propertyVerticalAlignment_->subProperties().size() > 0)
	{
		propertyVerticalAlignment_->removeSubProperty(propertyVerticalAlignment_->subProperties()[0]);
	}

	buw::AlignmentModel::Ptr am = 
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel();

	if(am->getAlignmentCount() > index && index >= 0)
	{
		if (am->getAlignment(index)->getType() != buw::e3DAlignmentType::e2DBased)
		{
			buw::Alignment3DBased3D::Ptr currentAlignment = std::static_pointer_cast<buw::Alignment3DBased3D>(am->getAlignment(index));

			itemStartStation_->setValue(currentAlignment->getStartStation());
			itemEndStation_->setValue(currentAlignment->getEndStation());
			itemLength_->setValue(currentAlignment->getLength());

			return;
		}

		view_->setSelectedAlignment(index);

		if(verticalAlignmentWindow_)
			verticalAlignmentWindow_->setSelectedAlignment(index);

		if(curvatureWindow_)
			curvatureWindow_->setSelectedAlignment(index);

		buw::Alignment2DBased3D::Ptr currentAlignment = std::static_pointer_cast<buw::Alignment2DBased3D>(am->getAlignment(index));

		itemStartStation_->setValue(currentAlignment->getStartStation());
		itemEndStation_->setValue(currentAlignment->getEndStation());
		itemLength_->setValue(currentAlignment->getLength());

		if (currentAlignment->hasVerticalAlignment())
		{
			for (int k = 0; k < currentAlignment->getVerticalAlignment()->getAlignmentElementCount(); k++)
			{
				auto va = currentAlignment->getVerticalAlignment()->getAlignmentElementByIndex(k);
				std::string type = buw::verticalAlignmentTypeToString(va->getAlignmentType());
			
				auto itemVerticalAlignment = variantManager_->addProperty(
					QtVariantPropertyManager::groupTypeId(),
					tr("Vertical Alignment (%1)").arg(type.c_str()));

				propertyVerticalAlignment_->addSubProperty(itemVerticalAlignment);

				auto start = va->getStartPosition();
				auto end = va->getEndPosition();

				double length = end.x() - start.x();

				// start position
				auto itemStart = variantManager_->addProperty(QVariant::PointF, tr("Start"));
				itemStart->setValue(QPointF(start.x(), start.y()));
				itemStart->setAttribute(QLatin1String("decimals"), 4);
				itemVerticalAlignment->addSubProperty(itemStart);

				// end position
				auto itemEnd = variantManager_->addProperty(QVariant::PointF, tr("End"));
				itemEnd->setValue(QPointF(end.x(), end.y()));
				itemEnd->setAttribute(QLatin1String("decimals"), 4);
				itemVerticalAlignment->addSubProperty(itemEnd);

				// length
				auto itemLength = variantManager_->addProperty(QVariant::Double, tr("Length [m]"));
				itemLength->setValue(length);
				itemVerticalAlignment->addSubProperty(itemLength);

				// start gradient
				double startGradient = 0;
				va->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartGradient, &startGradient);
				auto itemStartGradient = variantManager_->addProperty(QVariant::Double, tr("Start gradient"));
				itemStartGradient->setValue(startGradient);
				itemVerticalAlignment->addSubProperty(itemStartGradient);
			}
		}
	
		for (int k = 0; k < currentAlignment->getHorizontalAlignment()->getAlignmentElementCount(); k++)
		{
			// current alignment segment
			auto ha = currentAlignment->getHorizontalAlignment()->getAlignmentElementByIndex(k);
			std::string type = buw::horizontalAlignmentTypeToString(ha->getAlignmentType());
						
			auto itemHorizontalAlignment = variantManager_->addProperty(
				QtVariantPropertyManager::groupTypeId(),
				tr("Horizontal Alignment (%1)").arg(tr(type.c_str())));

			propertyHorizontalAlignment_->addSubProperty(itemHorizontalAlignment);

			auto horizontalElement = currentAlignment->getHorizontalAlignment()->getAlignmentElementByIndex(k);
			auto start = horizontalElement->getStartPosition();
			auto end = horizontalElement->getEndPosition();

			// start position
			auto itemStart = variantManager_->addProperty(QVariant::PointF, tr("Start"));
			itemStart->setValue(QPointF(start.x(), start.y()));
			itemStart->setAttribute(QLatin1String("decimals"), 4);
			itemHorizontalAlignment->addSubProperty(itemStart);

			// end position
			auto itemEnd = variantManager_->addProperty(QVariant::PointF, tr("End"));
			itemEnd->setValue(QPointF(end.x(), end.y()));
			itemEnd->setAttribute(QLatin1String("decimals"), 4);
			itemHorizontalAlignment->addSubProperty(itemEnd);

			// length
			auto itemLength = variantManager_->addProperty(QVariant::Double, tr("Length [m]"));
			itemLength->setValue(ha->getLength());
			itemHorizontalAlignment->addSubProperty(itemLength);

			switch (ha->getAlignmentType())
			{
			case buw::eHorizontalAlignmentType::Arc:
				{
					double radius = 0;
					ha->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Radius, &radius);
					auto itemRadius = variantManager_->addProperty(QVariant::Double, tr("Radius [m]"));
					itemRadius->setValue(radius);
					itemHorizontalAlignment->addSubProperty(itemRadius);
					
					bool ccw = true;
					ha->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Counterclockwise, &ccw);
					auto itemCCW = variantManager_->addProperty(QVariant::Bool, tr("Counterclockwise"));
					itemCCW->setValue(ccw);
					itemHorizontalAlignment->addSubProperty(itemCCW);
				}
				break;

			case buw::eHorizontalAlignmentType::Clothoid:
				{
					// ClothoidConstant
					double  clothoidConstant = 0;
					ha->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::ClothoidConstant, &clothoidConstant);
					auto itemClothoidConstant = variantManager_->addProperty(QVariant::Double, tr("Clothoid constant (A) [m²]"));
					itemClothoidConstant->setValue(clothoidConstant);
					itemHorizontalAlignment->addSubProperty(itemClothoidConstant);

					// Radius Start
					double RadiusStart = 0;
					ha->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusStart, &RadiusStart);

					if(buw::isInfinite(RadiusStart))
					{
						auto itemRadiusStart = variantManager_->addProperty(QVariant::String, tr("Radius Start [m]"));
						itemRadiusStart->setValue( QVariant("infinite") );
						itemHorizontalAlignment->addSubProperty(itemRadiusStart);
					}
					else
					{
						auto itemRadiusStart = variantManager_->addProperty(QVariant::Double, tr("Radius Start [m]"));
						itemRadiusStart->setValue(RadiusStart);
						itemHorizontalAlignment->addSubProperty(itemRadiusStart);
					}

					// Radius End
					double RadiusEnd = 0;
					ha->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusEnd, &RadiusEnd);

					if(buw::isInfinite(RadiusEnd))
					{
						auto itemRadiusEnd = variantManager_->addProperty(QVariant::String, tr("Radius End [m]"));
						itemRadiusEnd->setValue("infinite");
						itemHorizontalAlignment->addSubProperty(itemRadiusEnd);
					}
					else
					{
						auto itemRadiusEnd = variantManager_->addProperty(QVariant::Double, tr("Radius End [m]"));
						itemRadiusEnd->setValue(RadiusEnd);
						itemHorizontalAlignment->addSubProperty(itemRadiusEnd);
					}

					bool ccw = true;
					ha->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Counterclockwise, &ccw);
					auto itemCCW = variantManager_->addProperty(QVariant::Bool, tr("Counterclockwise"));
					itemCCW->setValue(ccw);
					itemHorizontalAlignment->addSubProperty(itemCCW);

					// PI
					buw::vector2d pointOfIntersection;
					bool hasPI = ha->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::PI, &pointOfIntersection);
					auto itemPI = variantManager_->addProperty(QVariant::PointF, tr("Point of Intersection"));
					itemPI->setValue(QPointF(pointOfIntersection.x(), pointOfIntersection.y()));
					itemPI->setAttribute(QLatin1String("decimals"), 4);
					itemHorizontalAlignment->addSubProperty(itemPI);
				}
				break;

			default:
				break;
			}
		}
	}
	else
	{
		itemStartStation_->setValue(0);
		itemEndStation_->setValue(0);
		itemLength_->setValue(0);

		while (propertyHorizontalAlignment_->subProperties().size() > 0)
		{
			propertyHorizontalAlignment_->removeSubProperty(propertyHorizontalAlignment_->subProperties()[0]);
		}
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionLandXML_triggered()
{
	QString filename = QFileDialog::getSaveFileName( 
		this, 
		tr("Save Document"), 
		QDir::currentPath(), 
		tr("LandXML (*.xml)") );

	if( !filename.isNull() )
	{
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportLandXML(filename.toStdString());
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_checkBoxHighlightSelectedAlignmentSegment_clicked(bool checked)
{
	view_->setHighlightSelectedAlignmentSegment(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionSVG_triggered()
{
	QString filename = QFileDialog::getSaveFileName( 
		this, 
		tr("Save Document"), 
		QDir::currentPath(), 
		tr("Scalable Vector Graphics (*.svg)") );

	if( !filename.isNull() )
	{
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportSVG(filename.toStdString());
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionCheck_for_Updates_triggered()
{
	checkForUpdates();
	if (!updater->newerVersionAvailable())
	{
		QMessageBox::information(
			this,
			tr("No updates available"),
			tr("You already have the newest version!"),
			QMessageBox::Ok
		);
	}
	//FvUpdater::sharedUpdater()->CheckForUpdatesNotSilent();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionPreferences_triggered()
{
	preferencesDialog_->show();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_checkBoxShowMap_clicked( bool checked )
{
	view_->enableBlueMap(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionViewport_as_screenshot_triggered()
{
	QString filename = QFileDialog::getSaveFileName( 
		this, 
		tr("Save Screenshot"), 
		QDir::currentPath(), 
		tr("Portable Network Graphics (*.png);;Bitmap (*.bmp);;JPEG (*.jpg);;TIFF (*.tif)")
	);

	if( !filename.isNull() )
	{
		view_->saveAsScreenshot(filename.toStdString());
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::updateRecentFileActions()
{
	int MaxRecentFiles = 10; 
	QSettings settings;
	QStringList files = settings.value("recentFileList").toStringList();

	int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

	//buw::LogManager::getInstance().Log(files.join(" ").toStdString());

	// Updating the recent files list 
	for(int i=0; i < numRecentFiles; i++)
	{
		if(i == 0)
		{
			ui_->actionRecentFile1->setVisible(true);
			ui_->actionRecentFile1->setText(QString("1 - ") + files[i]);
		}
		if(i == 1) 
		{
			ui_->actionRecentFile2->setVisible(true);
			ui_->actionRecentFile2->setText(QString("2 - ") + files[i]);
		}
		if(i == 2)
		{
			ui_->actionRecentFile3->setVisible(true);
			ui_->actionRecentFile3->setText(QString("3 - ") + files[i]);
		}
		if(i == 3) 
		{
			ui_->actionRecentFile4->setVisible(true);
			ui_->actionRecentFile4->setText(QString("4 - ") + files[i]);
		}
		if(i == 4)
		{
			ui_->actionRecentFile5->setVisible(true);
			ui_->actionRecentFile5->setText(QString("5 - ") + files[i]);
		}
		if(i == 5) 
		{
			ui_->actionRecentFile6->setVisible(true);
			ui_->actionRecentFile6->setText(QString("6 - ") + files[i]);
		}
		if(i == 6) 
		{
			ui_->actionRecentFile7->setVisible(true);
			ui_->actionRecentFile7->setText(QString("7 - ") + files[i]);
		}
		if(i == 7) 
		{
			ui_->actionRecentFile8->setVisible(true);
			ui_->actionRecentFile8->setText(QString("8 - ") + files[i]);
		}
		if(i == 8) 
		{
			ui_->actionRecentFile9->setVisible(true);
			ui_->actionRecentFile9->setText(QString("9 - ") + files[i]);
		}
		if(i == 9) 
		{
			ui_->actionRecentFile10->setVisible(true);
			ui_->actionRecentFile10->setText(QString("10 - ") + files[i]);
		}
	}
}

QString OpenInfraPlatform::UserInterface::MainWindow::strippedName(const QString &fullFileName)
{
	return QFileInfo(fullFileName).fileName();
}

void OpenInfraPlatform::UserInterface::MainWindow::ImageQualityBasedUnitTesting()
{
	prepareTest(0);
}

void OpenInfraPlatform::UserInterface::MainWindow::prepareTest(int i)
{
	inUnitTest_ = i;

	switch (i)
	{
	case 0:
		//--------------------------------------------------------------------------
		// testdata/LandXML/Ji/B15n_Data/B15n.xml
		// --------------------------------------------------------------------------

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/B15n_Data/B15n.xml");
		break;

	case 1:
		//--------------------------------------------------------------------------
		// testdata/LandXML/Mainbruecke_Klingenberg.xml
		// --------------------------------------------------------------------------

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/Mainbruecke_Klingenberg.xml");
		break;

	case 2:

		// ###############################################################################################################################
		// testdata/LandXML/LandXMLDemo.xml
		// ###############################################################################################################################

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/AutoCAD Civil 3D/LandXMLDemo.xml");
		break;

	case 3:
		// ###############################################################################################################################
		// testdata/LandXML/ProVI/002LR.xml
		// ###############################################################################################################################

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/ProVI/002LR.xml");
		break;

	case 4:
		// ###############################################################################################################################
		// testdata/LandXML/AutoCAD Civil 3D/debug.xml
		// ###############################################################################################################################

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/AutoCAD Civil 3D/debug.xml");
		break;

	case 5:
		// ###############################################################################################################################
		// testdata/LandXML/HbfMhfZweiteStammstrecke/HbfMhfZweiteStammstrecke.xml
		// ###############################################################################################################################

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/HbfMhfZweiteStammstrecke/HbfMhfZweiteStammstrecke.xml");
		break;

	case 6:
		// ###############################################################################################################################
		// testdata/LandXML/HbfMhfZweiteStammstrecke/2teStammstreckeBeide.xml
		// ###############################################################################################################################

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/HbfMhfZweiteStammstrecke/2teStammstreckeBeide.xml");
		break;

	case 7:
		// ###############################################################################################################################
		// testdata/LandXML/CityCad/Sito_Tie.xml"
		// ###############################################################################################################################

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/CityCad/Sito_Tie.xml");
		break;

	case 8:
		// ###############################################################################################################################
		// testdata/LandXML/RIB STRATIS/BAB_A6.xml
		// ###############################################################################################################################

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/RIB STRATIS/BAB_A6.xml");
		break;

	case 9:
		// ###############################################################################################################################
		// testdata/LandXML/RIB STRATIS/St2237-Sulzkirchen.xml
		// ###############################################################################################################################

		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/RIB STRATIS/St2237-Sulzkirchen.xml");
		break;

	case 10:
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("testdata/LandXML/Mainbruecke_Klingenberg.xml");
		break;

	//// export Oktra
	//case 11:
	//	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportOkstra("Mainbruecke_Klingenberg_OKSTRA_export_1_13.xml", "1.013");
	//	break;

	//case 12:
	//	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportOkstra("Mainbruecke_Klingenberg_OKSTRA_export_1_14.xml", "1.014");
	//	break;

	//case 13:
	//	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportOkstra("Mainbruecke_Klingenberg_OKSTRA_export_1_13.cte", "1.013");
	//	break;

	//case 14:
	//	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportOkstra("Mainbruecke_Klingenberg_OKSTRA_export_1_14.cte", "1.014");
	//	break;

	//// import Okstra
	//case 15:
	//	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("Mainbruecke_Klingenberg_OKSTRA_export_1_13.xml");
	//	break;

	//case 16:
	//	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("Mainbruecke_Klingenberg_OKSTRA_export_1_14.xml");
	//	break;

	//case 17:
	//	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("Mainbruecke_Klingenberg_OKSTRA_export_1_13.cte");
	//	break;

	//case 18:
	//	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import("Mainbruecke_Klingenberg_OKSTRA_export_1_14.cte");
	//	break;

	case 11:
		// ###############################################################################################################################
		// add future tests here
		// ###############################################################################################################################

		// test finished
		if (tester.didAllTestSucceed())
		{
			BLUE_LOG_STREAM_EX("UnitTest", buw::eLogSeverityLevel::Warning) << "All unit test succeeded.";
		}
		else
		{
			BLUE_LOG_STREAM_EX("UnitTest", buw::eLogSeverityLevel::Error) << "A unit test failed.";
		}

		tester.writeTestHomepage();

		system("test_report.html");
	default:
		inUnitTest_ = -1;
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::performTest(int i)
{
	buw::testDescription td;

	view_->setViewportSize(650, 453);

	buw::InfraCameraController::Ptr controller = view_->getInfraCameraController();
	buw::InfraCamera::Ptr camera = controller->getCamera();
	camera->setTargetDistance(0, buw::InfraCamera::CAMERA);

	switch (i)
	{
	case 0:
	{
		// todo implement Camera Controller and fix ImageQualityBasedUnitTesting 

		/*buw::ZoomInputController zic(9.17751f);
		zic.setWindowSize( view__->getSize() );
		buw::PanInputController pic(buw::vector3f(10.1539, -4.112, 0));
		pic.setWindowSize( view__->getSize() );
		buw::Arcballf arcBall(view__->getSize());
		buw::quaternionf q(0.241491, 0.204704, 0.0054324, 0.948551);
		arcBall.setCurrentQuaternion(q);

		view__->setZoomInputController(zic);
		view__->setPanInputController(pic);*/

		camera->setPosition(-11.4155, 2.26471, -0.161588, buw::InfraCamera::CAMERA);

		actionGetCameraState();
	}


		view_->saveAsScreenshot("B15n_solid.png");

		view_->enableDrawTerrainWireframe(true);
		view_->saveAsScreenshot("B15n_wireframe.png");

		view_->enableHideTerrain(true);
		view_->saveAsScreenshot("B15n_hide.png");

		view_->showCrossSection(true);
		view_->saveAsScreenshot("B15n_crossSection.png");

		view_->showDesignCrossSection(true);
		view_->saveAsScreenshot("B15n_designCrossSection.png");

		view_->connectCrossSections(true);
		view_->saveAsScreenshot("B15n_roadBody_wireframe.png");

		view_->doSolidCrossSections(true);
		view_->saveAsScreenshot("B15n_roadBody_solid.png");

		// solid
		td.LandXMLFile = "testdata/LandXML/B15n_Data/B15n.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/B15n_solid.png";
		td.screenshotImageFilename = "B15n_solid.png";
		td.differenceImageFilename = "B15n_solid_diff.png";
		tester.createTest(td);

		// wireframe
		td.LandXMLFile = "testdata/LandXML/B15n_Data/B15n.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/B15n_wireframe.png";
		td.screenshotImageFilename = "B15n_wireframe.png";
		td.differenceImageFilename = "B15n_wireframe_diff.png";
		tester.createTest(td);

		// crossSection
		td.LandXMLFile = "testdata/LandXML/B15n_Data/B15n.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/B15n_crossSection.png";
		td.screenshotImageFilename = "B15n_crossSection.png";
		td.differenceImageFilename = "B15n_crossSection_diff.png";
		tester.createTest(td);

		// designCrossSection
		td.LandXMLFile = "testdata/LandXML/B15n_Data/B15n.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/B15n_designCrossSection.png";
		td.screenshotImageFilename = "B15n_designCrossSection.png";
		td.differenceImageFilename = "B15n_designCrossSection_diff.png";
		tester.createTest(td);

		// roadBody_wireframe
		td.LandXMLFile = "testdata/LandXML/B15n_Data/B15n.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/B15n_roadBody_wireframe.png";
		td.screenshotImageFilename = "B15n_roadBody_wireframe.png";
		td.differenceImageFilename = "B15n_roadBody_wireframe_diff.png";
		tester.createTest(td);

		// roadBody_solid
		td.LandXMLFile = "testdata/LandXML/B15n_Data/B15n.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/B15n_roadBody_solid.png";
		td.screenshotImageFilename = "B15n_roadBody_solid.png";
		td.differenceImageFilename = "B15n_roadBody_solid_diff.png";
		tester.createTest(td);

		{
			/*buw::ZoomInputController zic(10.1972f);
			zic.setWindowSize( view__->getSize() );
			buw::PanInputController pic(buw::vector3f(11.7991, 1.08442, 0));
			pic.setWindowSize( view__->getSize() );
			buw::Arcballf arcBall(view__->getSize());
			buw::quaternionf q(0.0747937, 0.350785, 0.0886735, 0.929243);
			arcBall.setCurrentQuaternion(q);

			view__->setZoomInputController(zic);
			view__->setPanInputController(pic);*/

			camera->setPosition(-9.95493, 0.188848, -2.98082, buw::InfraCamera::CAMERA);
			camera->setRotation(-0.602219, -0.198517);
		}

		view_->drawRoadTexture(true);
		view_->saveAsScreenshot("B15n_roadBody_texture.png");

		// roadBody_texture
		td.LandXMLFile = "testdata/LandXML/B15n_Data/B15n.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/B15n_roadBody_texture.png";
		td.screenshotImageFilename = "B15n_roadBody_texture.png";
		td.differenceImageFilename = "B15n_roadBody_texture_diff.png";
		tester.createTest(td);

		view_->enableHideTerrain(false);
		view_->enableDrawTerrainWireframe(false);
		view_->showCrossSection(false);
		view_->showDesignCrossSection(false);
		view_->connectCrossSections(false);
		view_->doSolidCrossSections(false);
		view_->drawRoadTexture(false);
		break;

	case 1:
	{
		/*buw::ZoomInputController zic(1.59441f);
		zic.setWindowSize( view_->getSize() );
		buw::PanInputController pic(buw::vector3f(0, 0, 0));
		pic.setWindowSize( view_->getSize() );
		buw::Arcballf arcBall(view_->getSize());
		buw::quaternionf q(0.353553, 0.353553, 0.146447, 0.853553);
		arcBall.setCurrentQuaternion(q);

		view_->setZoomInputController(zic);
		view_->setPanInputController(pic);*/

		camera->setPosition(-2.22567, 3.94321, 3.06439, buw::InfraCamera::CAMERA);
		camera->setRotation(-0.433057, -0.975246);
	}

		view_->setHighlightDifferentAlignmentElements(true);
		view_->setView(eView::HorizontalAlignment);

		view_->enableDrawTerrainWireframe(true);
		view_->saveAsScreenshot("Mainbruecke_Klingenberg_wireframe.png");

		view_->enableDrawTerrainWireframe(false);
		view_->saveAsScreenshot("Mainbruecke_Klingenberg_solid.png");

		td.LandXMLFile = "testdata/LandXML/Mainbruecke_Klingenberg.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/Mainbruecke_Klingenberg_wireframe.png";
		td.screenshotImageFilename = "Mainbruecke_Klingenberg_wireframe.png";
		td.differenceImageFilename = "Mainbruecke_Klingenberg_wireframe_diff.png";
		tester.createTest(td);

		td.LandXMLFile = "testdata/LandXML/Mainbruecke_Klingenberg.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/Mainbruecke_Klingenberg_solid.png";
		td.screenshotImageFilename = "Mainbruecke_Klingenberg_solid.png";
		td.differenceImageFilename = "Mainbruecke_Klingenberg_solid_diff.png";
		tester.createTest(td);
		break;

	case 2:
	{
		/*buw::ZoomInputController zic(0.6561f);
		zic.setWindowSize( view_->getSize() );
		buw::PanInputController pic(buw::vector3f(0, 0, 0));
		pic.setWindowSize( view_->getSize() );
		buw::Arcballf arcBall(view_->getSize());
		buw::quaternionf q(0.382683, 0, 0, 0.92388);
		arcBall.setCurrentQuaternion(q);

		view_->setZoomInputController(zic);
		view_->setPanInputController(pic);*/

		camera->setPosition(1.14259, 8.25856, 10.3035, buw::InfraCamera::CAMERA);
		camera->setRotation(0, -0.785398);
	}

		view_->enableDrawTerrainWireframe(true);
		view_->saveAsScreenshot("LandXMLDemo_wireframe.png");

		view_->enableDrawTerrainWireframe(false);
		view_->saveAsScreenshot("LandXMLDemo_solid.png");

		td.LandXMLFile = "testdata/LandXML/LandXMLDemo.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/LandXMLDemo_wireframe.png";
		td.screenshotImageFilename = "LandXMLDemo_wireframe.png";
		td.differenceImageFilename = "LandXMLDemo_wireframe_diff.png";
		tester.createTest(td);

		td.LandXMLFile = "testdata/LandXML/LandXMLDemo.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/LandXMLDemo_solid.png";
		td.screenshotImageFilename = "LandXMLDemo_solid.png";
		td.differenceImageFilename = "LandXMLDemo_solid_diff.png";
		tester.createTest(td);
		break;
	case 3:
	{
		/*buw::ZoomInputController zic(4.75327f);
		zic.setWindowSize( view_->getSize() );
		buw::PanInputController pic(buw::vector3f(6.2592, 3.99767, 0));
		pic.setWindowSize( view_->getSize() );
		buw::Arcballf arcBall(view_->getSize());
		buw::quaternionf q(0.524936, 0.434153, 0.358105, 0.638525);
		arcBall.setCurrentQuaternion(q);

		view_->setZoomInputController(zic);
		view_->setPanInputController(pic);*/

		camera->setPosition(-6.46104, 1.31923, -4.42941, buw::InfraCamera::CAMERA);
		camera->setRotation(-1.32624, -1.28056);
	}

		view_->saveAsScreenshot("LR_highlight.png");

		td.LandXMLFile = "testdata/LandXML/ProVI/002LR.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/LR_highlight.png";
		td.screenshotImageFilename = "LR_highlight.png";
		td.differenceImageFilename = "LR_highlight_diff.png";
		tester.createTest(td);

		{
			/*buw::ZoomInputController zic(1.72f);
			zic.setWindowSize( view_->getSize() );
			buw::PanInputController pic(buw::vector3f(-7.43867, 1.64686, 0));
			pic.setWindowSize( view_->getSize() );
			buw::Arcballf arcBall(view_->getSize());
			buw::quaternionf q(0.707107, 0, 0, 0.707107);
			arcBall.setCurrentQuaternion(q);

			view_->setZoomInputController(zic);
			view_->setPanInputController(pic);*/

			camera->setPosition(8.5536, 4.06355, 2.05648, buw::InfraCamera::CAMERA);
			camera->setRotation(0, -1.5708);
		}

		view_->saveAsScreenshot("LR_highlight1.png");

		td.LandXMLFile = "testdata/LandXML/ProVI/002LR.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/LR_highlight1.png";
		td.screenshotImageFilename = "LR_highlight1.png";
		td.differenceImageFilename = "LR_highlight1_diff.png";
		tester.createTest(td);

		{
			/*buw::ZoomInputController zic(5.68f);
			zic.setWindowSize( view_->getSize() );
			buw::PanInputController pic(buw::vector3f(-16.1039, 8.09029, 0));
			pic.setWindowSize( view_->getSize() );
			buw::Arcballf arcBall(view_->getSize());
			buw::quaternionf q(0.707107, 0, 0, 0.707107);
			arcBall.setCurrentQuaternion(q);

			view_->setZoomInputController(zic);
			view_->setPanInputController(pic);*/

			camera->setPosition(15.9367, 1.72737, 8.01137, buw::InfraCamera::CAMERA);
			camera->setRotation(0, -1.5708);
		}

		view_->saveAsScreenshot("LR_highlight2.png");

		td.LandXMLFile = "testdata/LandXML/ProVI/002LR.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/LR_highlight2.png";
		td.screenshotImageFilename = "LR_highlight2.png";
		td.differenceImageFilename = "LR_highlight2_diff.png";
		tester.createTest(td);
		break;

	case 4:
	{
		/*buw::ZoomInputController zic(0.2235f);
		zic.setWindowSize( view_->getSize() );
		buw::PanInputController pic(buw::vector3f(0.0848, 0.544186, 0));
		pic.setWindowSize( view_->getSize() );
		buw::Arcballf arcBall(view_->getSize());
		buw::quaternionf q(0.707107, 0, 0, 0.707107);
		arcBall.setCurrentQuaternion(q);

		view_->setZoomInputController(zic);
		view_->setPanInputController(pic);*/

		camera->setPosition(0, 41.4423, -1.8115e-006, buw::InfraCamera::CAMERA);
		camera->setRotation(0, -1.5708);
	}

		view_->saveAsScreenshot("debug_solid.png");

		td.LandXMLFile = "testdata/LandXML/AutoCAD Civil 3D/debug.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/debug_solid.png";
		td.screenshotImageFilename = "debug_solid.png";
		td.differenceImageFilename = "debug_solid_diff.png";
		tester.createTest(td);
		break;

	case 5:
	{
		/*buw::ZoomInputController zic(0.4635f);
		zic.setWindowSize( view_->getSize() );
		buw::PanInputController pic(buw::vector3f(0.0848, 0.544186, 0));
		pic.setWindowSize( view_->getSize() );
		buw::Arcballf arcBall(view_->getSize());
		buw::quaternionf q(0.707107, 0, 0, 0.707107);
		arcBall.setCurrentQuaternion(q);

		view_->setZoomInputController(zic);
		view_->setPanInputController(pic);*/

		camera->setPosition(0, 20.986, -9.17325e-007, buw::InfraCamera::CAMERA);
		camera->setRotation(0, -1.5708);
	}

		view_->saveAsScreenshot("HbfMhfZweiteStammstrecke_solid.png");

		td.LandXMLFile = "testdata/LandXML/HbfMhfZweiteStammstrecke/HbfMhfZweiteStammstrecke.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/HbfMhfZweiteStammstrecke_solid.png";
		td.screenshotImageFilename = "HbfMhfZweiteStammstrecke_solid.png";
		td.differenceImageFilename = "HbfMhfZweiteStammstrecke_solid_diff.png";
		tester.createTest(td);
		break;

	case 6:
	{
		/*buw::ZoomInputController zic(0.325793f);
		zic.setWindowSize( view_->getSize() );
		buw::PanInputController pic(buw::vector3f(-54.2547, 7.44686, 0));
		pic.setWindowSize( view_->getSize() );
		buw::Arcballf arcBall(view_->getSize());
		buw::quaternionf q(0.707107, 0, 0, 0.707107);
		arcBall.setCurrentQuaternion(q);

		view_->setZoomInputController(zic);
		view_->setPanInputController(pic);*/

		camera->setPosition(48.6722, 38.1715, 8.81073, buw::InfraCamera::CAMERA);
		camera->setRotation(0, -1.5708);
	}

		view_->saveAsScreenshot("2teStammstreckeBeide_solid.png");

		td.LandXMLFile = "testdata/LandXML/HbfMhfZweiteStammstrecke/2teStammstreckeBeide.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/2teStammstreckeBeide_solid.png";
		td.screenshotImageFilename = "2teStammstreckeBeide_solid.png";
		td.differenceImageFilename = "2teStammstreckeBeide_solid_diff.png";
		tester.createTest(td);
		break;

	case 7:
	{
		/*buw::ZoomInputController zic(5.26349925994873f);
		buw::PanInputController pic(buw::vector3f(0.0848000049591064f, 0.544185996055603f,0.0f));
		buw::Arcballf arcBall(view_->getSize());
		buw::quaternionf q(0.101465873420238, 0.832729339599609f, 0.117100700736046f, 0.531558096408844f);
		arcBall.setCurrentQuaternion(q);

		view_->setZoomInputController(zic);
		view_->setPanInputController(pic);*/

		camera->setPosition(-5.05528, 0.0531676, -0.724832, buw::InfraCamera::CAMERA);
		camera->setRotation(-1.73223, -0.0722984);
	}

		view_->enableDrawTerrainWireframe(true);
		view_->saveAsScreenshot("Sito_Tie_wireframe.png");
		view_->repaint();

		view_->enableDrawTerrainWireframe(false);
		view_->saveAsScreenshot("Sito_Tie_solid.png");
		view_->repaint();

		td.LandXMLFile = "testdata/LandXML/CityCad/Sito_Tie.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/Sito_Tie_wireframe.png";
		td.screenshotImageFilename = "Sito_Tie_wireframe.png";
		td.differenceImageFilename = "Sito_Tie_wireframe_diff.png";
		tester.createTest(td);

		td.LandXMLFile = "testdata/LandXML/CityCad/Sito_Tie.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/Sito_Tie_solid.png";
		td.screenshotImageFilename = "Sito_Tie_solid.png";
		td.differenceImageFilename = "Sito_Tie_solid_diff.png";
		tester.createTest(td);
		break;

	case 8:
	{
		/*buw::ZoomInputController zic(0.0618648f);
		zic.setWindowSize( view_->getSize() );
		buw::PanInputController pic(buw::vector3f(0, 0, 0));
		pic.setWindowSize( view_->getSize() );
		buw::Arcballf arcBall(view_->getSize());
		buw::quaternionf q(0.357112, -0.0255371, 0.00388029, 0.933704);
		arcBall.setCurrentQuaternion(q);

		view_->setZoomInputController(zic);
		view_->setPanInputController(pic);*/

		camera->setPosition(-32.6753, 116.124, 120.469, buw::InfraCamera::CAMERA);
		camera->setRotation(0.263894, -0.785398);
	}

		view_->saveAsScreenshot("BAB_A6_solid.png");

		td.LandXMLFile = "testdata/LandXML/RIB STRATIS/BAB_A6.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/BAB_A6_solid.png";
		td.screenshotImageFilename = "BAB_A6_solid.png";
		td.differenceImageFilename = "BAB_A6_solid_diff.png";
		tester.createTest(td);

		{
			/*buw::ZoomInputController zic(0.253603f);
			zic.setWindowSize( view_->getSize() );
			buw::PanInputController pic(buw::vector3f(-42.7497, -9.97028, 0));
			pic.setWindowSize( view_->getSize() );
			buw::Arcballf arcBall(view_->getSize());
			buw::quaternionf q(0.357112, -0.0255371, 0.00388029, 0.933704);
			arcBall.setCurrentQuaternion(q);

			view_->setZoomInputController(zic);
			view_->setPanInputController(pic);*/

			camera->setPosition(-24.4327, 23.6264, 45.2104, buw::InfraCamera::CAMERA);
			camera->setRotation(-0.101497, -0.562088);
		}

		view_->saveAsScreenshot("BAB_A6_solid2.png");

		td.LandXMLFile = "testdata/LandXML/RIB STRATIS/BAB_A6.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/BAB_A6_solid2.png";
		td.screenshotImageFilename = "BAB_A6_solid2.png";
		td.differenceImageFilename = "BAB_A6_solid2_diff.png";
		tester.createTest(td);

		view_->enableDrawTerrainWireframe(true);
		view_->saveAsScreenshot("BAB_A6_wireframe.png");

		td.LandXMLFile = "testdata/LandXML/RIB STRATIS/BAB_A6.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/BAB_A6_wireframe.png";
		td.screenshotImageFilename = "BAB_A6_wireframe.png";
		td.differenceImageFilename = "BAB_A6_wireframe_diff.png";
		tester.createTest(td);
		break;

	case 9:
		{
			/*buw::ZoomInputController zic(0.297273f);
			zic.setWindowSize( view_->getSize() );
			buw::PanInputController pic(buw::vector3f(-5.8896, 0.218605, 0));
			pic.setWindowSize( view_->getSize() );
			buw::Arcballf arcBall(view_->getSize());
			buw::quaternionf q(0.553946, -0.0107373, 0.0469264, 0.831159);
			arcBall.setCurrentQuaternion(q);

			view_->setZoomInputController(zic);
			view_->setPanInputController(pic);*/

			camera->setPosition(4.91942, 22.8379, 21.5173, buw::InfraCamera::CAMERA);
			camera->setRotation(-0.0067665, -0.832903);
		}

		view_->enableDrawTerrainWireframe(false);
		view_->saveAsScreenshot("St2237-Sulzkirchen_solid.png");

		td.LandXMLFile = "testdata/LandXML/RIB STRATIS/St2237-Sulzkirchen.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/St2237-Sulzkirchen_solid.png";
		td.screenshotImageFilename = "St2237-Sulzkirchen_solid.png";
		td.differenceImageFilename = "St2237-Sulzkirchen_solid_diff.png";
		tester.createTest(td);

		view_->enableDrawTerrainWireframe(true);
		view_->saveAsScreenshot("St2237-Sulzkirchen_wireframe.png");

		td.LandXMLFile = "testdata/LandXML/RIB STRATIS/St2237-Sulzkirchen.xml";
		td.referenceImageFilename = "UnitTesting/ReferenceImages/St2237-Sulzkirchen_wireframe.png";
		td.screenshotImageFilename = "St2237-Sulzkirchen_wireframe.png";
		td.differenceImageFilename = "St2237-Sulzkirchen_wireframe_diff.png";
		tester.createTest(td);
		break;
	case 10:
		camera->setPosition(-2.22567, 3.94321, 3.06439, buw::InfraCamera::CAMERA);
		camera->setRotation(-0.433057, -0.975246);

		view_->saveAsScreenshot("Mainbruecke_Klingenberg_ref_okstra.png");
		break;

	case 15:
		camera->setPosition(-2.22567, 3.94321, 3.06439, buw::InfraCamera::CAMERA);
		camera->setRotation(-0.433057, -0.975246);

		view_->saveAsScreenshot("Mainbruecke_Klingenberg_okstra_1_13_XML.png");

		td.LandXMLFile = "testdata/LandXML/Mainbruecke_Klingenberg.xml";
		td.referenceImageFilename = "Mainbruecke_Klingenberg_ref_okstra.png";
		td.screenshotImageFilename = "Mainbruecke_Klingenberg_okstra_1_13_XML.png";
		td.differenceImageFilename = "Mainbruecke_Klingenberg_okstra_diff_1_13_XML.png";
		tester.createTest(td);
		break;
	case 16:
		camera->setPosition(-2.22567, 3.94321, 3.06439, buw::InfraCamera::CAMERA);
		camera->setRotation(-0.433057, -0.975246);

		view_->saveAsScreenshot("Mainbruecke_Klingenberg_okstra_1_14_XML.png");

		td.LandXMLFile = "testdata/LandXML/Mainbruecke_Klingenberg.xml";
		td.referenceImageFilename = "Mainbruecke_Klingenberg_ref_okstra.png";
		td.screenshotImageFilename = "Mainbruecke_Klingenberg_okstra_1_14_XML.png";
		td.differenceImageFilename = "Mainbruecke_Klingenberg_okstra_diff_1_14_XML.png";
		tester.createTest(td);
		break;
	case 17:
		camera->setPosition(-2.22567, 3.94321, 3.06439, buw::InfraCamera::CAMERA);
		camera->setRotation(-0.433057, -0.975246);

		view_->saveAsScreenshot("Mainbruecke_Klingenberg_okstra_1_13_CTE.png");

		td.LandXMLFile = "testdata/LandXML/Mainbruecke_Klingenberg.xml";
		td.referenceImageFilename = "Mainbruecke_Klingenberg_ref_okstra.png";
		td.screenshotImageFilename = "Mainbruecke_Klingenberg_okstra_1_13_CTE.png";
		td.differenceImageFilename = "Mainbruecke_Klingenberg_okstra_diff_1_13_CTE.png";
		tester.createTest(td);
		break;
	case 18:
		camera->setPosition(-2.22567, 3.94321, 3.06439, buw::InfraCamera::CAMERA);
		camera->setRotation(-0.433057, -0.975246);

		view_->saveAsScreenshot("Mainbruecke_Klingenberg_okstra_1_14_CTE.png");

		td.LandXMLFile = "testdata/LandXML/Mainbruecke_Klingenberg.xml";
		td.referenceImageFilename = "Mainbruecke_Klingenberg_ref_okstra.png";
		td.screenshotImageFilename = "Mainbruecke_Klingenberg_okstra_1_14_CTE.png";
		td.differenceImageFilename = "Mainbruecke_Klingenberg_okstra_diff_1_14_CTE.png";
		tester.createTest(td);
		break;
	default:
		break;
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionOpen_triggered()
{
	try
	{
		handle_actionOpen_triggered();

		addToRecentFilesList(OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().recentFileName);
		updateRecentFileActions();
	}
	catch (const buw::Exception& exception)
	{
		QMessageBox::warning(this, QApplication::applicationName(), tr("Cannot open the selected file."));
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionNew_triggered()
{
	handle_actionNew_triggered();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionSave_triggered()
{
	handle_actionSave_triggered();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionSaveAs_triggered()
{
	handle_actionSaveAs_triggered();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionUndo_triggered()
{
	handle_actionUndo_triggered();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionRedo_triggered()
{
	handle_actionRedo_triggered();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionImport_triggered()
{
	try
	{
		handle_actionImport_triggered();
	}
	catch (const buw::Exception& exception)
	{
		QMessageBox::warning(this, QApplication::applicationName(), tr("Cannot import the selected file."));
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::jobStarted(int id)
{
	progressDialog_->setDisabled(false);
	progressDialog_->setModal(true);
	progressDialog_->setRange(0, 0);
	progressDialog_->setLabelText("");
	progressDialog_->show();
}

void OpenInfraPlatform::UserInterface::MainWindow::jobRunning(int id, float progress, const std::string& message)
{
	if (progress > 0)
	{
		progressDialog_->setRange(0, 1000);
		progressDialog_->setValue((int)(progress * 1000));
	}

	progressDialog_->setLabelText(message.c_str());
}


void OpenInfraPlatform::UserInterface::MainWindow::jobFinishing(int id, bool completed)
{
#ifdef BLUE_DEBUG 
	progressDialog_->setLabelText(QString("magic in progress..."));
#else
	progressDialog_->setLabelText(QString("finishing up..."));
#endif // DEBUG
		
	progressDialog_->setRange(0, 1);
	progressDialog_->setValue(1);
	progressDialog_->repaint();
}

void OpenInfraPlatform::UserInterface::MainWindow::jobFinished(int id, bool comepleted)
{
	//progressBar_->hide();
	progressDialog_->hide();

	if (inUnitTest_ >= 0)
	{
		performTest(inUnitTest_);
		prepareTest(inUnitTest_ + 1);
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::cancelJob()
{
	OpenInfraPlatform::AsyncJob::getInstance().cancelJob();
	progressDialog_->setLabelText("Canceling");
	progressDialog_->setDisabled(true);
}

void OpenInfraPlatform::UserInterface::MainWindow::actionGetCameraState()
{
	auto cameraController = view_->getInfraCameraController();
	auto camera = cameraController->getCamera();

	std::ostream& out = std::cout;

	auto pos = camera->getPosition(buw::InfraCamera::CAMERA);
	auto rot = camera->getRotation();
	out << "camera->setPosition(" << pos.x() << ", " << pos.y() << ", " << pos.z() << ", buw::InfraCamera::CAMERA);" << std::endl;
	out << "camera->setRotation(" << rot.x() << ", " << rot.y() << ");" << std::endl;
}

void OpenInfraPlatform::UserInterface::MainWindow::on_ImportLASFile_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
		this,
		tr("Open Document"),
		QDir::currentPath(),
		tr("LAS cloud (*.las)")
	);

	if (!filename.isNull())
	{
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().importLAS(filename.toStdString());
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::openRecentFileViaAction( QAction *actionRecentFile )
{
	std::string fileName = actionRecentFile->text().toUtf8().constData();
	fileName = fileName.substr(4,fileName.length());

	if (boost::filesystem::exists(fileName))
	{
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().import(fileName);
		addToRecentFilesList(fileName.c_str());
		updateRecentFileActions();
		buw::Path p(fileName.c_str());
		updateWindowTitle(p.getFilename().toCString());
	}
	else
	{
		QMessageBox::warning(this, QApplication::applicationName(), tr("Cannot import the selected file. File does not exist."));
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_comboBoxMapSize_currentIndexChanged( int index )
{
	int size = 256;

	switch (index)
	{
	case 0:
		size = 256;
		break;
	case 1:
		size = 128;
		break;
	case 2:
		size = 64;
		break;
	case 3:
		size = 32;
		break;
	default:
		size = 256;
		break;
	}

	buw::PropertySet ps;
	ps.addInteger("size", size);
	view_->applyBlueMapProperties(ps);
}

void OpenInfraPlatform::UserInterface::MainWindow::showMap()
{
	static bool checked = false;
	checked = !checked;
	view_->enableBlueMap(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_variantEditor_currentItemChanged(QtBrowserItem * item)
{
	//std::cout << "Selected a Qt BrowserItem." << std::endl;
}

//---------------------------------------------------------------------------//
// Debugging
//---------------------------------------------------------------------------//

void OpenInfraPlatform::UserInterface::MainWindow::reloadShader()
{
	view_->reloadShader();
}

//---------------------------------------------------------------------------//
// Create alignment
//---------------------------------------------------------------------------//

void OpenInfraPlatform::UserInterface::MainWindow::on_actionCreate_Alignment_Points_triggered( bool checked )
{
	view_->enableCreatePoints(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionCreate_Alignment_triggered()
{
	buw::vector2d offset = view_->getOffset().xy();

	auto points = view_->getAlignmentPoints();

	if (points.size() <= 1)
	{
		return;
	}

	
	if (points.size() == 2)
	{
		buw::vector2d A = points[0].xy();
		buw::vector2d B = points[1].xy();
		
		// create horizontal alignment
		buw::vector2d start =	buw::vector2d(points[0].x(), points[0].y()) + offset;
		buw::vector2d end =		buw::vector2d(points[1].x(), points[1].y()) + offset;
		buw::HorizontalAlignmentElement2DLine::Ptr line = std::make_shared<buw::HorizontalAlignmentElement2DLine>(start, end);
		buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
		ha->addElement(line);

		// create vertical alignment
		buw::vector2d vstart =	buw::vector2d(ha->getStartStation(), 0);
		buw::vector2d vend =	buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
		buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
		buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
		va->addElement(v);

		buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);

		return;
	}
	

	buw::vector2d A = points[0].xy();
	buw::vector2d B = points[1].xy();
	buw::vector2d C = points[2].xy();

	buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
	
	//double angle = buw::calculateAngleBetweenVectors( A-B, C-B );

	for (int i = 0; i < points.size()-1; i++)
	{
		buw::vector2d start =	buw::vector2d(points[i+0].x(), points[i+0].y()) + offset;
		buw::vector2d end =		buw::vector2d(points[i+1].x(), points[i+1].y()) + offset;

		buw::HorizontalAlignmentElement2DLine::Ptr line = std::make_shared<buw::HorizontalAlignmentElement2DLine>(start, end);
		ha->addElement(line);
	}

	// create vertical alignment
	buw::vector2d vstart =	buw::vector2d(ha->getStartStation(), 0);
	buw::vector2d vend =	buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
	buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
	buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
	va->addElement(v);

	buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Parallel_Clothoid_triggered()
{
	createClothoidParallelDialog_->show();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Parallel_Clothoid_triggered()
{
	buw::vector2d startoutside, startinside,theo_start_dir, x_axis = { 1.0, 0.0 }, start, end, HendPointi, HendPointa, pi, offset = view_->getOffset().xy();
	double theo_start_angle, drawstep, L, radiusstart, radiusend, clothoidconstant, L1 = 0, L2 = 0, Li, La, width = createClothoidParallelDialog_->width, distance = createClothoidParallelDialog_->distance;
	bool clock, sameA = createClothoidParallelDialog_->sameA, exactly = createClothoidParallelDialog_->exactly;
	int index = ui_->comboBoxAlignment->currentIndex();//selected alignment
	buw::AlignmentModel::Ptr am = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel();
	if (distance <= 0.00001 && exactly == true)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert for distance a value larger than 0.00001.");
		return;
	}
	if (width <= 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert for width a value larger than zero.");
		return;
	}
	if (am->getAlignmentCount() > index && index >= 0)
	{
		buw::Alignment2DBased3D::Ptr currentAlignment = std::static_pointer_cast<buw::Alignment2DBased3D>(am->getAlignment(index));
		auto he = currentAlignment->getHorizontalAlignment()->getAlignmentElementByIndex(index);
		if (he->getAlignmentType() != buw::eHorizontalAlignmentType::Clothoid)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "At first please select a clothoid from the combo-box at the rigth sight of the window.");
			return;
		}
		he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Clockwise, &clock);
		he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::ClothoidConstant, &clothoidconstant);
		he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::PI, &pi);
		he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Length, &L);
		he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusStart, &radiusstart);
		he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusEnd, &radiusend);
		he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);
		he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition, &end);
		if (distance > L)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Please insert for distance a value smaller than the current clothoid length.");
			return;
		}
		if (sameA == true)
		{
			buw::vector2d mirror = end - start;
			buw::vector2d delta_cloth_dir = (pi - start)/(pi-start).length();//for radiusstart == infint or no radius == infinit
			if (mirror*delta_cloth_dir < 0)
			{
				delta_cloth_dir = -delta_cloth_dir;
			}
			double limited_tau = clothoidconstant*clothoidconstant / (radiusend*radiusend * 2);
			Li = L - width*L*L / (2 * clothoidconstant*clothoidconstant);
			La = L + width*L*L / (2 * clothoidconstant*clothoidconstant);
			double Ri2 = radiusend - width;
			double Ri1 = clothoidconstant*clothoidconstant / (clothoidconstant*clothoidconstant / Ri2 - Li);
			double Ra2 = radiusend + width;
			double Ra1 = clothoidconstant*clothoidconstant / (clothoidconstant*clothoidconstant / Ra2 - La);
			buw::vector2d theostart = start;//if the clothoid has either radiusstart nor radiusend == infinity theostart is !=start
			theo_start_angle = calculateAngleBetweenVectors(x_axis, delta_cloth_dir);
			if (radiusend != std::numeric_limits<double>::infinity() && radiusstart != std::numeric_limits<double>::infinity())
			{
				L1 = clothoidconstant*clothoidconstant / radiusstart;
				L2 = clothoidconstant*clothoidconstant / radiusend;
				buw::vector2d R1co, R2co;
				R1co.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, clothoidconstant);
				R1co.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L1, clothoidconstant);
				R2co.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, clothoidconstant);
				R2co.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L2, clothoidconstant);
				double R1 = sqrt(R1co.squaredLength());
				double R2 = sqrt(R2co.squaredLength());
				//source of the following three lines by walter bislins: walter.bislins.ch/blog/index.asp?page=Schnittpunkte+zweier+Kreise+berechnen+(JavaScript) ;very easy formular which is applied in this special context
				//the intersectionpoints of two arcs is computed by a coordinat-transformation. This intersectionpoint is the theoretical beginning of the clothoid
				double c = (start - end).length();
				double x_bisli = (R1*R1 + c*c - R2*R2) / (2 * c);
				double y_bisli = sqrt(R1*R1 - x_bisli*x_bisli);
				if (clock == true)
				{
					y_bisli = -y_bisli;
				}
				theostart.x() = start.x() + x_bisli;
				theostart.y() = start.y() + y_bisli;
				limited_tau=clothoidconstant*clothoidconstant / (radiusend*radiusend * 2);
				theo_start_dir = buw::createRotationZ22d(-limited_tau)*delta_cloth_dir;
				theo_start_angle = calculateAngleBetweenVectors(x_axis, theo_start_dir);
			}
			if (radiusend == std::numeric_limits<double>::infinity())
			{
				buw::vector2d swap = start;
				start = end;
				end = swap;
				buw::vector2d delta_cloth_dir = (pi - start)/(pi-start).length();
				if (mirror*delta_cloth_dir > 0)//>0 because mirror points in the old direction
				{
					delta_cloth_dir = -delta_cloth_dir;
				}
				if (clock == true)
				{
					clock = false;
				}
				else
				{
					clock = true;
				}
				limited_tau = clothoidconstant*clothoidconstant / (radiusstart*radiusstart * 2);
				theo_start_dir = buw::createRotationZ22d(limited_tau)*delta_cloth_dir;
				theo_start_angle = calculateAngleBetweenVectors(x_axis, theo_start_dir);
			}
			if (radiusend != std::numeric_limits<double>::infinity() && radiusstart != std::numeric_limits<double>::infinity() && radiusstart < radiusend) 
			{
				buw::vector2d swap = start;
				start = end;
				end = swap;
				buw::vector2d delta_cloth_dir = (pi - start) / (pi - start).length();
				if (mirror*delta_cloth_dir > 0)//>0 because mirror points in the old direction
				{
					delta_cloth_dir = -delta_cloth_dir;
				}
				if (clock == true)
				{
					clock = false;
				}
				else
				{
					clock = true;
				}
				limited_tau = clothoidconstant*clothoidconstant / (radiusend*radiusend * 2);
				theo_start_dir = buw::createRotationZ22d(limited_tau)*delta_cloth_dir;
				theo_start_angle = calculateAngleBetweenVectors(x_axis, theo_start_dir);
				double swapi = Ri1;
				Ri1 = Ri2;
				Ri2 = swapi;
				swapi = Ra2;
				Ra2 = Ra1;
				Ra1 = swapi;
			}
			double Ri = clothoidconstant*clothoidconstant / Li;
			double Ra = clothoidconstant*clothoidconstant / La;
			buw::vector2d Clothoid_End_inside = end + width*buw::createRotationZ22d(theo_start_angle + limited_tau + M_PI / 2)*x_axis;
			buw::vector2d Clothoid_End_outside = end + width*buw::createRotationZ22d(theo_start_angle + limited_tau - M_PI / 2)*x_axis;
			HendPointi.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(Li, clothoidconstant);
			HendPointi.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(Li, clothoidconstant);
			HendPointa.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(La, clothoidconstant);
			HendPointa.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(La, clothoidconstant);
			if (clock == true)
			{
				HendPointi.y() = -HendPointi.y();
				HendPointa.y() = -HendPointa.y();
				buw::vector2d swap = HendPointa;
				HendPointa = HendPointi;
				HendPointi = swap;
				double swapi = Ri;
				Ri = Ra;
				Ra = swapi;
				if (radiusend != std::numeric_limits<double>::infinity() && radiusstart != std::numeric_limits<double>::infinity())
				{
					swapi = Ra1;
					Ra1 = Ri1;
					Ri1 = swapi;
					swapi = Ra2;
					Ra2 = Ri2;
					Ri2 = swapi;
				}
			}
			//buw::vector2d startoutside =  Clothoid_End_outside - buw::createRotationZ22d(theo_start_angle)*HendPointa;
			//buw::vector2d startinside = Clothoid_End_inside - buw::createRotationZ22d(theo_start_angle)*HendPointi;
			if (radiusend != std::numeric_limits<double>::infinity() && radiusstart != std::numeric_limits<double>::infinity())
			{
				createClothoid_noInfinity(Ri1, Ri2, startinside, clothoidconstant, theo_start_dir, clock);
				createClothoid_noInfinity(Ra1, Ra2, startoutside, clothoidconstant, theo_start_dir, clock);
			}
			else
			{// the next part generates the startpoint of parallel clothoid
				double ri_square = HendPointi.length()*HendPointi.length();
				double ra_square = HendPointa.length()*HendPointa.length();
				//Geradengleichung
				buw::vector2d raybegini = start + width*buw::createRotationZ22d(M_PI / 2)*theo_start_dir;
				buw::vector2d raybegina = start + width*buw::createRotationZ22d(-M_PI / 2)*theo_start_dir;
				double vi = raybegini.x() / theo_start_dir.x() - raybegini.y() / theo_start_dir.y() - Clothoid_End_inside.x() / theo_start_dir.x() + Clothoid_End_inside.y() / theo_start_dir.y();
				double va = raybegina.x() / theo_start_dir.x() - raybegina.y() / theo_start_dir.y() - Clothoid_End_outside.x() / theo_start_dir.x() + Clothoid_End_outside.y() / theo_start_dir.y();
				double quotient = 1 /2/ (1 + theo_start_dir.y()*theo_start_dir.y() / theo_start_dir.x() / theo_start_dir.x());
				double determinanta = (va*theo_start_dir.y() / theo_start_dir.x())*(va*theo_start_dir.y() / theo_start_dir.x()) - 4*va*va*theo_start_dir.y()*theo_start_dir.y() + 4*ra_square;
				double determinanti = (vi*theo_start_dir.y() / theo_start_dir.x())*(vi*theo_start_dir.y() / theo_start_dir.x()) - 4*vi*vi*theo_start_dir.y()*theo_start_dir.y() + 4*ri_square;
				if (determinanti < 0 || determinanta < 0)
				{
					QMessageBox::warning(this, QApplication::applicationName(), "Please change your inserts because otherwise no computation posible.");
					return;
				}
				double x1i = (vi*theo_start_dir.y() / theo_start_dir.x() + sqrt(determinanti))*quotient;
				double x2i = (vi*theo_start_dir.y() / theo_start_dir.x() - sqrt(determinanti))*quotient;
				double x1a = (va*theo_start_dir.y() / theo_start_dir.x() + sqrt(determinanta))*quotient;
				double x2a = (va*theo_start_dir.y() / theo_start_dir.x() - sqrt(determinanta))*quotient;
				double xq1i = x1i + Clothoid_End_inside.x();
				double xq1a = x1a + Clothoid_End_outside.x();
				double xq2i = x2i - Clothoid_End_inside.x();
				double xq2a = x2a - Clothoid_End_outside.x();
				double yq1i = vi*theo_start_dir.y() - theo_start_dir.y()*theo_start_dir.x()*x1i + Clothoid_End_inside.y();
				double yq1a = va*theo_start_dir.y() - theo_start_dir.y()*theo_start_dir.x()*x1a + Clothoid_End_outside.y();
				double yq2i = vi*theo_start_dir.y() - theo_start_dir.y()*theo_start_dir.x()*x2i - Clothoid_End_inside.y();
				double yq2a = va*theo_start_dir.y() - theo_start_dir.y()*theo_start_dir.x()*x2a - Clothoid_End_outside.y();
				buw::vector2d vq1i = { xq1i, yq1i };
				double lengx1i = (start - vq1i).length();
				buw::vector2d vq1a = { xq1a, yq1a };
				double lengx1a = (start - vq1a).length();
				buw::vector2d vq2i = { xq2i, yq2i };
				double lengx2i = (start - vq2i).length();
				buw::vector2d vq2a = { xq2a, yq2a };
				double lengx2a = (start - vq2a).length();
				if (lengx1i<lengx2i)
				{
					startinside = vq1i;
				}
				else
				{
					startinside = vq2i;
				}
				if (lengx1a<lengx2a)
				{
					startoutside = vq1a;
				}
				else
				{
					startoutside = vq2a;
				}

				createClothoid_negY(Ri, clothoidconstant, startinside, delta_cloth_dir, clock);
				createClothoid_negY(Ra, clothoidconstant, startoutside, delta_cloth_dir, clock);
			}
		}
		if (exactly == true)
		{
			buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
			buw::HorizontalAlignment2D::Ptr hb = std::make_shared<buw::HorizontalAlignment2D>();
			drawstep = distance / L;
			double delta = 0.00001 / L;
			double loopend = 1.0f - drawstep - delta;
			for (float s = 0.0f; s <= loopend; s += drawstep)
			{
				buw::vector2d point1 = he->getPosition(s);
				buw::vector2d point3 = he->getPosition(s + delta);
				buw::vector2d pointdir1 = point3 - point1;
				double norm1 = (point3 - point1).length();
				buw::vector2d Clothoid_inside1 = point1 + width / norm1*buw::createRotationZ22d(M_PI / 2)*pointdir1;
				buw::vector2d Clothoid_outside1 = point1 + width / norm1*buw::createRotationZ22d(-M_PI / 2)*pointdir1;
				buw::vector2d point2 = he->getPosition(s + drawstep);
				buw::vector2d point4 = he->getPosition(s + drawstep + delta);
				buw::vector2d pointdir2 = point4 - point2;
				double norm2 = (point4 - point2).length();
				buw::vector2d Clothoid_inside2 = point2 + width / norm2*buw::createRotationZ22d(M_PI / 2)*pointdir2;
				buw::vector2d Clothoid_outside2 = point2 + width / norm2*buw::createRotationZ22d(-M_PI / 2)*pointdir2;
				buw::HorizontalAlignmentElement2DLine::Ptr line1 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(Clothoid_outside1, Clothoid_outside2);
				ha->addElement(line1);
				buw::HorizontalAlignmentElement2DLine::Ptr line2 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(Clothoid_inside1, Clothoid_inside2);
				hb->addElement(line2);
			}
			buw::vector2d vstart = buw::vector2d(ha->getStartStation(), 0);
			buw::vector2d vend = buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
			buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
			buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
			va->addElement(v);
			buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
			buw::vector2d vvstart = buw::vector2d(hb->getStartStation(), 0);
			buw::vector2d vvend = buw::vector2d(hb->getStartStation() + hb->getLength(), 0);
			buw::VerticalAlignmentElement2DLine::Ptr vv = std::make_shared<buw::VerticalAlignmentElement2DLine>(vvstart, vvend);
			buw::VerticalAlignment2D::Ptr vva = std::make_shared<buw::VerticalAlignment2D>();
			vva->addElement(vv);
			buw::Alignment2DBased3D::Ptr valignment = std::make_shared<buw::Alignment2DBased3D>(hb, vva);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(valignment);
		}
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Arc_Clothoid_Arc_Meth2_triggered()
{
	createArcClothoidArcMeth2Dialog_->show(); //source of the formulars: Prof.Dr.-Ing M.Baeumker from Fachhochschule Bochum Skript: Rechenverfahren der Ingenieurvermessung
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Arc_Clothoid_Arc_Meth2_triggered()
{
	auto points = view_->getAlignmentPoints();
	buw::vector2d  M1, M2, M1M2, cloth_star_dir, delta_cloth_dir, theostartPoint, Vect, offset = view_->getOffset().xy(), x_axis = { 1.0, 0.0 }, start1= { 1.0, 0.0 }, end1= { 1.0, 0.0 }, start2= { 1.0, 0.0 }, end2= { 1.0, 0.0 }, endPoint, HendPoint1, HendPoint2;
	double R, A0, gon, delta_cloth_angle=0, D, leng = 0, Dtest = 0, L1, L2, tau1, tau2, R1 = createArcClothoidArcMeth2Dialog_->R1, R2 = createArcClothoidArcMeth2Dialog_->R2, phi1 = createArcClothoidArcMeth2Dialog_->phi1, phi2 = createArcClothoidArcMeth2Dialog_->phi2, delta1 = createArcClothoidArcMeth2Dialog_->delta1, delta2 = createArcClothoidArcMeth2Dialog_->delta2;
	buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
	int sig = 1;
	if (points.size() < 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least two alignment-points and then call this function again");
		return;
	}
	if (R1 <= 0 || R2 <= 0 || phi1 <= 0 || phi2 <= 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first values, that are larger than zero, in dialog.");
		return;
	}
	if (R1 == R2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "You have inserted for R1 a value equal to R2. Please correct your inserts.");
		return;
	}
	if (delta2 < 0 || delta1 < 0 || delta2>400 || delta1>400)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please change delta1 or delta2, because all inserted angles have to be in the intervall 0 <= angle < 400 gon.");
		return;
	}
	bool clockX=false, d1 = createArcClothoidArcMeth2Dialog_->d1;
	gon = 200 / M_PI; //transformation-factor from rad to gon important for the translation from userinterface to code
	phi1 = phi1 / gon;
	phi2 = phi2 / gon;
	delta1 = delta1 / gon;
	delta2 = delta2 / gon;
	M1 = points[points.size() - 2].xy() + offset;
	M2 = points[points.size() - 1].xy() + offset;
	M1M2 = points[points.size() - 1].xy() - points[points.size() - 2].xy();
	if (R1 == R2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "You have inserted the same value for R1 and R2. Please correct your inserts.");
		return;
	}
	D = std::abs(R1 - R2) - M1M2.length();
	if (D < 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please reduce the length of drawn line or change your inserts so that |R1-R2| > length of drawn line.");
		return;
	}
	R = R1*R2 / (R1 + R2);
	A0 = sqrt(sqrt(24 * D*R*R*R));
	if (R1<R2)
	{
		clockX=true;
		buw::vector2d swapsi =start2;
		start2=end2;
		end2=swapsi;
		swapsi=start1;
		start1=end1;
		end1=swapsi;
		sig = -1;
	}
	if (d1 == true )
	{
		Vect  = R1*buw::createRotationZ22d(delta1)*x_axis;
		start1 = M1 + R1*buw::createRotationZ22d(delta1 - phi1)*x_axis;
		end1 = Vect + M1;
	}
	if (d1 == false )
	{
		Vect= M2 + R2*buw::createRotationZ22d(delta2)*x_axis;
		end2 = M2 + R2*buw::createRotationZ22d(delta2 + phi2)*x_axis;
		start2  = Vect+M2;
	}
	int count_loops = 0;
	do //the text until "while(...)" generates the values A1 and A2 for the creation of Arc-Clothoid-Arc by a differential-quotient
	{
		count_loops++;
		if (count_loops == 100)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Please change inserts because otherwise no computation posible.");
			return;
		}
		double D0 = Dtest;
		if (D0 == 0)
		{
			L1 = A0*A0 / R1;
			L2 = A0*A0 / R2;
			tau1 = A0*A0 / (R1*R1 * 2);
			tau2 = A0*A0 / (R2*R2 * 2);
			HendPoint1.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A0);
			HendPoint2.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A0);
			HendPoint1.y() = sig* buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A0);
			HendPoint2.y() = sig *buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A0);
			delta_cloth_dir = buw::createRotationZ22d(sig*M_PI / 2)*Vect;
			double delta_cloth_angle =buw::calculateAngleBetweenVectors(x_axis, delta_cloth_dir);
			if (d1 == true )
			{
				leng = (Vect - buw::createRotationZ22d(delta_cloth_angle - sig*tau1)*HendPoint1 + buw::createRotationZ22d(delta_cloth_angle - sig*tau1)*HendPoint2 + R2*buw::createRotationZ22d(delta_cloth_angle - sig*tau1 + sig*tau2 + sig* M_PI / 2)*x_axis).length();
			}
			if (d1 == false )
			{
				leng = (Vect - buw::createRotationZ22d(delta_cloth_angle - sig*tau2)*HendPoint2 - buw::createRotationZ22d(delta_cloth_angle - sig*tau2)*HendPoint1 + R1*buw::createRotationZ22d(delta_cloth_angle - sig*tau2 +sig* tau1 + sig*M_PI / 2)*x_axis).length();
			}
			D0 = R1 - R2 - leng;
		}
		A0 = A0 + 0.01;
		L1 = A0*A0 / R1;
		L2 = A0*A0 / R2;
		tau1 = A0*A0 / (R1*R1 * 2);
		tau2 = A0*A0 / (R2*R2 * 2);
		HendPoint1.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A0);
		HendPoint2.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A0);
		HendPoint1.y() = sig *buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A0);
		HendPoint2.y() = sig *buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A0);
		if (d1 == true )
		{
			leng = (Vect - buw::createRotationZ22d(delta_cloth_angle - sig*tau1)*HendPoint1 + buw::createRotationZ22d(delta_cloth_angle - sig*tau1)*HendPoint2 + R2*buw::createRotationZ22d(delta_cloth_angle - sig*tau1 + sig*tau2 + sig* M_PI / 2)*x_axis).length();
		}
		if (d1 == false )
		{
			leng = (Vect - buw::createRotationZ22d(delta_cloth_angle - sig*tau2)*HendPoint2 - buw::createRotationZ22d(delta_cloth_angle - sig*tau2)*HendPoint1 + R1*buw::createRotationZ22d(delta_cloth_angle - sig*tau2 +sig* tau1 + sig*M_PI / 2)*x_axis).length();
		}
		double D01 = R1 - R2 - leng;
		A0 = A0 + (D - D0)*0.01 / (D01 - D0);
		if (A0 < 0)
		{
			A0 = -A0;
		}
		L1 = A0*A0 / R1;
		L2 = A0*A0 / R2;
		tau1 = A0*A0 / (R1*R1 * 2);
		tau2 = A0*A0 / (R2*R2 * 2);
		HendPoint1.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A0);
		HendPoint2.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A0);
		HendPoint1.y() = sig *buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A0);
		HendPoint2.y() = sig *buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A0);
		if (d1 == true )
		{
			leng = (Vect - buw::createRotationZ22d(delta_cloth_angle - sig*tau1)*HendPoint1 + buw::createRotationZ22d(delta_cloth_angle - sig*tau1)*HendPoint2 + R2*buw::createRotationZ22d(delta_cloth_angle - sig*tau1 + sig*tau2 + sig* M_PI / 2)*x_axis).length();
		}
		if (d1 == false )
		{
			leng = (Vect - buw::createRotationZ22d(delta_cloth_angle - sig*tau2)*HendPoint2 - buw::createRotationZ22d(delta_cloth_angle - sig*tau2)*HendPoint1 + R1*buw::createRotationZ22d(delta_cloth_angle - sig*tau2 +sig* tau1 + sig*M_PI / 2)*x_axis).length();
		}
		Dtest = leng - R1 - R2;
	} while (std::abs(Dtest - D) < 0.00001);
	if (d1 == true && clockX==false)
	{
		theostartPoint = end1 - buw::createRotationZ22d(delta_cloth_angle - tau1)*HendPoint1;
		cloth_star_dir = buw::createRotationZ22d(-tau1)*delta_cloth_dir;
		start2 = theostartPoint + buw::createRotationZ22d(delta_cloth_angle - tau1)*HendPoint2;
		end2 = M2 + buw::createRotationZ22d(phi2)* (start2 - M2);
	}
	if (d1 == false && clockX==false)
	{
		theostartPoint = start2 - buw::createRotationZ22d(delta_cloth_angle - tau2)*HendPoint2;
		cloth_star_dir = buw::createRotationZ22d(-tau2)*delta_cloth_dir;
		end1 = theostartPoint + buw::createRotationZ22d(delta_cloth_angle - tau2)*HendPoint1;
		start1 = M1 + buw::createRotationZ22d(-phi1)* (end1 - M1);
	}
	if (d1 == true && clockX==true)
	{
		theostartPoint = start1 - buw::createRotationZ22d(delta_cloth_angle +tau1)*HendPoint1;
		cloth_star_dir = buw::createRotationZ22d(tau1)*delta_cloth_dir;
		end2 = theostartPoint + buw::createRotationZ22d(delta_cloth_angle + tau1)*HendPoint2;
		start2 = M2 + buw::createRotationZ22d(phi2)* (end2 - M2);
	}
	if (d1 == false && clockX==true)
	{
		theostartPoint = end2 - buw::createRotationZ22d(delta_cloth_angle + tau2)*HendPoint2;
		cloth_star_dir = buw::createRotationZ22d(tau2)*delta_cloth_dir;
		start1 = theostartPoint + buw::createRotationZ22d(delta_cloth_angle + tau2)*HendPoint1;
		end1 = M1 + buw::createRotationZ22d(-phi1)* (start1 - M1);
	}
	if (tau2 > M_PI || tau1 > M_PI)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Reduce the second radius or increase the first radius or change other inserts, because tau is larger than 180 degree.");
		return;
	}
	if (clockX==true)
	{
		double swap = R2;
		R2 = R1;
		R1 = swap;
	}
	createClothoid_noInfinity(R1, R2, theostartPoint, A0, cloth_star_dir, clockX);
	buw::HorizontalAlignmentElement2DArc::Ptr arc1 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
		M1,
		start1,
		end1,
		clockX);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment1 = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment1->addElement(arc1);
	buw::Alignment2DBased3D::Ptr arc_a1 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment1);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a1);
	buw::HorizontalAlignmentElement2DArc::Ptr arc2 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
		M2,
		start2,
		end2,
		clockX);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment2 = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment2->addElement(arc2);
	buw::Alignment2DBased3D::Ptr arc_a2 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment2);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a2);
	for (int i = 0; i < points.size() - 1; i++)
	{
		buw::vector2d start = buw::vector2d(points[i + 0].x(), points[i + 0].y()) + offset;
		buw::vector2d end = buw::vector2d(points[i + 1].x(), points[i + 1].y()) + offset;
		buw::HorizontalAlignmentElement2DLine::Ptr line = std::make_shared<buw::HorizontalAlignmentElement2DLine>(start, end);
		ha->addElement(line);
	}
	buw::HorizontalAlignmentElement2DLine::Ptr line1 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(M1, start1);
	ha->addElement(line1);
	buw::HorizontalAlignmentElement2DLine::Ptr line2 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(M1, end1);
	ha->addElement(line2);
	buw::HorizontalAlignmentElement2DLine::Ptr line3 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(M2, start2);
	ha->addElement(line3);
	buw::HorizontalAlignmentElement2DLine::Ptr line4 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(M2, end2);
	ha->addElement(line4);
	buw::vector2d vstart = buw::vector2d(ha->getStartStation(), 0);
	buw::vector2d vend = buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
	buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
	buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
	va->addElement(v);
	buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Arc_Clothoid_Clothoid_Arc_Meth2_triggered()
{
	createArcClothoidClothoidArcMeth2Dialog_->show();//source of the formulars: Prof.Dr.-Ing M.Baeumker from Fachhochschule Bochum Skript: Rechenverfahren der Ingenieurvermessung
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Arc_Clothoid_Clothoid_Arc_Meth2_triggered()
{
	auto points = view_->getAlignmentPoints();
	double D, Dtest=0, L1=0, L2=0, R1 = createArcClothoidClothoidArcMeth2Dialog_->R1, R2 = createArcClothoidClothoidArcMeth2Dialog_->R2, phi1 = createArcClothoidClothoidArcMeth2Dialog_->phi1;
	buw::vector2d S, M1, M2, M2M1, startPoint, offset = view_->getOffset().xy(), x_axis = { 1.0, 0.0 }, start1, end1, start2, end2, help1, help2;
	double tau2=0, tau1=0, A1=0, A2=0, phi2 = createArcClothoidClothoidArcMeth2Dialog_->phi2, AA1 = createArcClothoidClothoidArcMeth2Dialog_->A1, AA2 = createArcClothoidClothoidArcMeth2Dialog_->A2, psi = createArcClothoidClothoidArcMeth2Dialog_->psi;
	if (points.size() < 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least two alignment-points and then call this function again");
		return;
	}
	if (R1 <= 0 || R2 <= 0 || AA1 < 0 || AA2 < 0 || phi1 <= 0 || phi2 <= 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first values, that are larger than zero, for R1, R2, phi1 and phi2 in dialog.");
		return;
	}
	if (0>psi ||psi>400)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please change psi, because psi has to be in the intervall 0 <= angle < 400 gon.");
		return;
	}
	if (AA1 > 0 && AA2 > 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please leave A1 or A2 or both at 0.0.");
		return;
	}
	double gon = 200 / M_PI; //transformation-factor from rad to gon important for the translation from userinterface to code
	phi1 = phi1 / gon;
	phi2 = phi2 / gon;
	if (psi>=200)
	{
		psi=psi-200;
	}
	psi = psi / gon;
	buw::vector2d psi_direct = buw::createRotationZ22d(psi)*x_axis; //this vector is important to reduce the cases when we compare three angels, because angels can be larger than 2*M_PI, negative, larger than others...
	bool clockArc, clockClo;
	//use the points for the last drawn line
	M1 = points[points.size() - 2].xy() + offset;
	M2 = points[points.size() - 1].xy() + offset;
	M2M1 = points[points.size() - 1].xy() - points[points.size() - 2].xy();
	double ny = calculateAngleBetweenVectors( x_axis,M2M1);
	if (ny>=M_PI)
	{
		ny=ny-M_PI;
	}
	double delta_angle = calculateAngleBetweenVectors(psi_direct, M2M1);
	double alpha = asin((R2 + R1) / M2M1.length());// alpha always > 0 , because M2M1.length > (R2+R1)
	if (std::abs(2 * M_PI - delta_angle)<alpha || std::abs(delta_angle-M_PI)<alpha || delta_angle<alpha)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please change psi, because otherwise computation imposible.");
		return;
	}
	double R = R1*R2 / (R1 + R2);
	D = M2M1.length() - R1 - R2;
	if (D<0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please reduce the length of drawn line or change your inserts so that R1 + R2 < length of drawn line.");
		return;
	}
	double A0 = sqrt(sqrt(24 * D*R*R*R));
	A1 = AA1;
	A2 = AA2;
	if (A1 == 0 )
	{
		A1 = A0;
	}
	if (AA2 == 0)
	{
		A2 = A0;
	}
	int count_loops = 0;
	do //the text until "while(...)" generates the values A1 and A2 for the creation of Arc-Clothoid-Clothoid-Arc by a differential-quotient
	{
		count_loops++;
		if (count_loops == 1000)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Please change inserts because otherwise no computation posible.");
			return;
		}
		double D0 = Dtest;
		if (D0 == 0)
		{
			L1 = A1*A1 / R1;
			L2 = A2*A2 / R2;
			tau1 = (A1*A1) / (2 * R1*R1);
			tau2 = (A2*A2) / (2 * R2*R2);	
			help1.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A1);
			help2.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A2);
			help1.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A1);
			help2.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A2);
			S = R2*buw::createRotationZ22d(psi - M_PI / 2 + tau2)*x_axis - buw::createRotationZ22d(psi)*help2 - buw::createRotationZ22d(psi)*help1 - R1*buw::createRotationZ22d(psi + M_PI / 2 + tau1)*x_axis;
			D0 = S.length() - R1 - R2;
		}
		A0 = A0 + 0.01;
		if (AA1 == 0)
		{
			A1 = A0;
		}
		if (AA2 == 0)
		{
			A2 = A0;
		}
		L1 = A1*A1 / R1;
		L2 = A2*A2 / R2;
		tau1 = (A1*A1) / (2 * R1*R1);
		tau2 = (A2*A2) / (2 * R2*R2);
		help1.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A1);
		help2.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A2);
		help1.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A1);
		help2.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A2);
		S = R2*buw::createRotationZ22d(psi - M_PI / 2 + tau2)*x_axis - buw::createRotationZ22d(psi)*help2 - buw::createRotationZ22d(psi)*help1 - R1*buw::createRotationZ22d(psi + M_PI / 2 + tau1)*x_axis;
		double D01 = S.length() - R1 - R2;
		A0 = A0 + (D - D0)*0.01 / (D01 - D0);
		if (A0<0)
		{
			A0 = -A0;
		}
		if (AA1 == 0)
		{
			A1 = A0;
		}
		if (AA2 == 0)
		{
			A2 = A0;
		}
		L1 = A1*A1 / R1;
		L2 = A2*A2 / R2;
		tau1 = (A1*A1) / (2 * R1*R1);
		tau2 = (A2*A2) / (2 * R2*R2);
		help1.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A1);
		help2.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A2);
		help1.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A1);
		help2.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A2);
		if (tau1 > M_PI)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Increase radius 1 or change other inserts, because tau is larger than 180 degree.");
			return;
		}
		if (tau2 > M_PI)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Increase radius 2 or change other inserts, because tau is larger than 180 degree.");
			return;
		}
		S = R2*buw::createRotationZ22d(psi - M_PI / 2 + tau2)*x_axis - buw::createRotationZ22d(psi)*help2 - buw::createRotationZ22d(psi)*help1 - R1*buw::createRotationZ22d(psi+M_PI/2+tau1)*x_axis;
		Dtest = S.length() - R1 - R2;
	} while (std::abs(Dtest - D) < 0.00001);
	int sig = 1;
	clockArc= true;
	clockClo = false;
	if ( delta_angle>M_PI+alpha && delta_angle <2* M_PI-alpha)//this formular gives the borders of the s-form.
	{
		sig = -1;
		clockArc = false;
		clockClo = true;
		help2.y() = -help2.y();
		help1.y() = -help1.y();
	}
	startPoint = M2 - buw::createRotationZ22d(psi)*help2 + R2* buw::createRotationZ22d(sig*tau2 - sig*M_PI / 2 + psi)*x_axis;
	end1 = startPoint + buw::createRotationZ22d(psi + M_PI)*help1;
	end2 = startPoint + buw::createRotationZ22d(psi)*help2;
	start1 = M1 + buw::createRotationZ22d(sig*phi1)*(end1 - M1);
	start2 = M2 + buw::createRotationZ22d(sig*phi2)* (end2 - M2);
	buw::vector2d cloth_dir = buw::createRotationZ22d(psi)*x_axis;
	createClothoid_negY(R1, A1, startPoint, -cloth_dir, clockClo);
	createClothoid_negY(R2, A2, startPoint, cloth_dir, clockClo);
	buw::HorizontalAlignmentElement2DArc::Ptr arc1 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
		M1,
		start1,
		end1,
		clockArc);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment1 = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment1->addElement(arc1);
	buw::Alignment2DBased3D::Ptr arc_a1 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment1);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a1);
	buw::HorizontalAlignmentElement2DArc::Ptr arc2 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
		M2,
		start2,
		end2,
		clockArc);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment2 = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment2->addElement(arc2);
	buw::Alignment2DBased3D::Ptr arc_a2 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment2);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a2);
	buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
	// in order to help the user, the start of the clothoid is connected with the alignment which the user created
	buw::HorizontalAlignmentElement2DLine::Ptr line1 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(M1, start1);
	ha->addElement(line1);
	buw::HorizontalAlignmentElement2DLine::Ptr line2 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(M1, end1);
	ha->addElement(line2);
	buw::HorizontalAlignmentElement2DLine::Ptr line3 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(M2, start2);
	ha->addElement(line3);
	buw::HorizontalAlignmentElement2DLine::Ptr line4 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(M2, end2);
	ha->addElement(line4);

	buw::vector2d vstart = buw::vector2d(ha->getStartStation(), 0);
	buw::vector2d vend = buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
	buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
	buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
	va->addElement(v);
	buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Line_Clothoid_triggered()
{
	createClothoidDialog_->show();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Line_Clothoid_triggered()
{
	auto points = view_->getAlignmentPoints();
	double A = createClothoidDialog_->A, R = createClothoidDialog_->R, L = createClothoidDialog_->L;//here you do not need to determine between AA and A because the drawn line has no big computation influence
	bool clock = createClothoidDialog_->clock;
	buw::vector2d U, V, VU;
	buw::vector2d offset = view_->getOffset().xy();
	if (points.size() < 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least two alignment-points and then call this function again");
		return;
	}
	if (A == 0 && L == 0 && R == 0 || A < 0 || L < 0 || R < 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first two values, that are larger than zero, in dialog.");
		return;
	}
	if (A > 0 && L > 0 && R > 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "You have insert values for A, L and R, but you can just insert two values !");
		return;
	}

	U = points[points.size() - 2].xy() + offset;
	V = points[points.size() - 1].xy() + offset;
	if (R == 0)
	{
		R = A*A / L;
	}
	if (A == 0)
	{
		A = sqrt(L* R);
	}
	VU = V - U;
	double tau = L / (2 * R);
	if (tau > 3 * M_PI / 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Reduce A or L or increase R, because tau is larger than 270 degree.");
		return;
	}
	createClothoid_negY(R, A, V, VU, clock);
	buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
	for (int i = 0; i < points.size() - 1; i++)
	{
		buw::vector2d start = buw::vector2d(points[i + 0].x(), points[i + 0].y()) + offset;
		buw::vector2d end = buw::vector2d(points[i + 1].x(), points[i + 1].y()) + offset;
		buw::HorizontalAlignmentElement2DLine::Ptr line = std::make_shared<buw::HorizontalAlignmentElement2DLine>(start, end);
		ha->addElement(line);
	}	 // create vertical alignment
	buw::vector2d vstart = buw::vector2d(ha->getStartStation(), 0);
	buw::vector2d vend = buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
	buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
	buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
	va->addElement(v);
	buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Line_Clothoid_Arc_Clothoid_Line_triggered()
{
	createLineClothoidArcClothoidLineDialog_->show();//source of the formulars: Prof.Dr.-Ing M.Baeumker from Fachhochschule Bochum Skript: Rechenverfahren der Ingenieurvermessung
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Line_Clothoid_Arc_Clothoid_Line_triggered()
{
	auto points = view_->getAlignmentPoints();
	double A1 = createLineClothoidArcClothoidLineDialog_->A1, A2 = createLineClothoidArcClothoidLineDialog_->A2, R = createLineClothoidArcClothoidLineDialog_->R;
	buw::vector2d offset = view_->getOffset().xy();
	buw::vector2d U, V, W, VU, VW, VU_norm, VW_norm;
	buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
	if (points.size() <= 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least three alignment-points and then call this function again");
		return;
	}
	if (A1 <= 0 || A2 <= 0 || R <= 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first values, that are larger than zero, for A1, A2 and R in dialog.");
		return;
	}
	for (int ik = 0; ik < points.size() - 2; ik++)
	{
		U = points[ik].xy();
		V = points[ik + 1].xy();
		W = points[ik + 2].xy();
		//compute all important points
		double L1, L2, tau1, tau2, XE1, XE2, XM1, XM2, YE1, YE2, YM1, YM2, gamma, lineangle1, lineangle2, Tq, t1, t2, T1, T2, beta1, beta2;
		buw::vector2d startPoint1, startPoint2;
		L1 = A1*A1 / R;
		L2 = A2*A2 / R;
		tau1 = L1 / (2 * R);//in rad
		tau2 = L2 / (2 * R);//in rad
		XE1 = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A1);
		XE2 = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A2);
		YE1 = buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A1);
		YE2 = buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A2);
		XM1 = XE1 - R*sin(tau1);
		XM2 = XE2 - R*sin(tau2);
		YM1 = YE1 + R*cos(tau1);
		YM2 = YE2 + R*cos(tau2);
		VU = U - V;
		VU_norm = VU.normalize();
		VW = W - V;
		VW_norm = VW.normalize();
		double angle = buw::calculateAngleBetweenVectors(VU, VW);
		if (angle > M_PI)
		{
			angle = 2 * M_PI - angle;
		}
		gamma = M_PI - angle; //in rad
		if ((gamma - tau1 - tau2) < 0)//see script of Prof. Baeumker page 38
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Please increase the angle between the two lines or reduce R or increase A1 and A2, otherwise the arclength would be negative.");
		}
		else
		{
			Tq = sqrt(YM1*YM1 + YM2*YM2 - 2 * cos(gamma)*YM1*YM2);
			beta1 = asin(YM2*sin(gamma) / Tq);
			beta2 = asin(YM1*sin(gamma) / Tq);
			t1 = Tq*cos(beta2) / sin(gamma);
			t2 = Tq*cos(beta1) / sin(gamma);
			T1 = t1 + XM1;
			T2 = t2 + XM2;
			buw::vector2d x_axis = { 1.0, 0.0 };
			//calculates important parameters for the clothoids
			startPoint1 = V + T1*VU_norm + offset;
			lineangle1 = buw::calculateAngleBetweenVectors(x_axis, -VU);
			startPoint2 = V + T2*VW_norm + offset;
			lineangle2 = buw::calculateAngleBetweenVectors(x_axis, -VW);
			//draw the two clothoids and the arc
			bool clock1, clock2;
			buw::vector2d center, start, end;
			clock1 = true;
			clock2 = false;
			int sig = 1;
			if (VU.x()*VW.y() - VU.y()*VW.x() < 0)//vectorproduct determines the orientation of the clothoids
			{
				clock1 = false;
				clock2 = true;
				sig = -1;
			}
			center = V + t1*VU_norm + YM1* buw::createRotationZ22d(sig*M_PI / 2)* VU_norm + offset;
			start = V + (T1 - XE1)*VU_norm + YE1*buw::createRotationZ22d(sig*M_PI / 2)* VU_norm + offset;
			end = V + (T2 - XE2)*VW_norm + YE2* buw::createRotationZ22d(-sig* M_PI / 2)* VW_norm + offset;
			createClothoid_negY(R, A1, startPoint1, -VU_norm, clock1);
			createClothoid_negY(R, A2, startPoint2, -VW_norm, clock2);
			buw::HorizontalAlignmentElement2DArc::Ptr arc = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
				center,
				start,
				end,
				clock1);
			buw::HorizontalAlignment2D::Ptr horizontalAlignment = std::make_shared<buw::HorizontalAlignment2D>();
			horizontalAlignment->addElement(arc);
			buw::Alignment2DBased3D::Ptr arc_a = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a);
			// in order to help the user, the start of the clothoid is connected with the alignment which the user created
			buw::HorizontalAlignmentElement2DLine::Ptr line1 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(startPoint1, V + offset);
			ha->addElement(line1);
			buw::HorizontalAlignmentElement2DLine::Ptr line2 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(startPoint2, V + offset);
			ha->addElement(line2);
			// create vertical alignment
			buw::vector2d vstart = buw::vector2d(ha->getStartStation(), 0);
			buw::vector2d vend = buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
			buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
			buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
			va->addElement(v);
			buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
		}
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Line_Clothoid_Clothoid_Line_triggered()
{
	createLineClothoidClothoidLineDialog_->show();//source of the formulars: Prof.Dr.-Ing M.Baeumker from Fachhochschule Bochum Skript: Rechenverfahren der Ingenieurvermessung
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Line_Clothoid_Clothoid_Line_triggered()
{
	auto points = view_->getAlignmentPoints();//very important is to determine between RR1 and R1, because if the user wants to draw three lines different values are computed each time
	double A1 = 0, A2 = 0, R = 0, AA1 = createLineClothoidClothoidLineDialog_->A1, AA2 = createLineClothoidClothoidLineDialog_->A2, RR = createLineClothoidClothoidLineDialog_->R;
	double L1 = 0, L2 = 0, tau1 = 0, tau2 = 0, XE1 = 0, XE2 = 0, YE1 = 0, YE2 = 0, gamma = 0, lineangle1 = 0, lineangle2 = 0, t1 = 0, t2 = 0, T1 = 0, T2 = 0;
	buw::vector2d offset = view_->getOffset().xy(), startPoint1, startPoint2, U, V, W, VU, VW, VU_norm, VW_norm;
	buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
	if (points.size() <= 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least three alignment-points and then call this function again");
		return;
	}
	if (AA1 == 0 && AA2 == 0 || AA2 == 0 && RR == 0 || AA1 == 0 && RR == 0 || RR < 0 || AA1< 0 || AA2< 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first at least two values, that are larger than zero, in dialog.");
		return;
	}
	if (AA1 > 0 && AA2 > 0 && RR > 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "You have insert values for A1, A2 and R, but you can just insert two values !");
		return;
	}
	for (int ik = 0; ik < points.size() - 2; ik++)
	{
		U = points[ik].xy();
		V = points[ik + 1].xy();
		W = points[ik + 2].xy();
		//compute all important points
		VU = U - V;
		VU_norm = VU.normalize();
		VW = W - V;
		VW_norm = VW.normalize();
		double angle = buw::calculateAngleBetweenVectors(VU, VW);
		if (angle > M_PI)
		{
			angle = 2 * M_PI - angle;
		}
		gamma = M_PI - angle; //in rad
		if (AA2 == 0)	//userinterface give A1 and A2 or A1 and R //see page 35
		{
			A1 = AA1;
			R = RR;
			L1 = A1*A1 / R;
			tau1 = L1 / (2 * R);
			tau2 = gamma - tau1;
			A2 = R*sqrt(2 * tau2);
			L2 = R*(2 * tau2);
		}
		if (AA1 == 0)
		{
			A2 = AA2;
			R = RR;
			L2 = A2*A2 / R;
			tau2 = L2 / (2 * R);
			tau1 = gamma - tau2;
			A1 = R*sqrt(2 * tau1);
			L1 = R*(2 * tau1);
		}
		if (RR == 0)
		{
			A1 = AA1;
			A2 = AA2;
			R = sqrt((A1*A1 + A2*A2) / (2 * gamma));
			L1 = A1*A1 / R;
			L2 = A2*A2 / R;
			tau1 = L1 / (2 * R);
			tau2 = L2 / (2 * R);
		}
		XE1 = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A1);
		XE2 = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A2);
		YE1 = buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A1);
		YE2 = buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A2);
		double Tk1 = YE1 / sin(tau1);
		double Tk2 = YE2 / sin(tau2);
		double a1 = (Tk1 + Tk2)*sin(tau2) / sin(gamma);
		double a2 = (Tk1 + Tk2)*sin(tau1) / sin(gamma);
		t1 = XE1 - Tk1*  cos(tau1);
		t2 = XE2 - Tk2* cos(tau2);
		T1 = t1 + a1;
		T2 = t2 + a2;
		buw::vector2d x_axis = { 1.0, 0.0 };
		//calculates important parameters for the clothoids
		startPoint1 = V + T1*VU_norm + offset;
		lineangle1 = buw::calculateAngleBetweenVectors(x_axis, -VU);
		startPoint2 = V + T2*VW_norm + offset;
		lineangle2 = buw::calculateAngleBetweenVectors(x_axis, -VW);
		bool clock1 = true, clock2 = false;
		if (VU.x()*VW.y() - VU.y()*VW.x() < 0)//vectorproduct determines the orientation of the clothoids
		{
			clock1 = false;
			clock2 = true;
		}				//draw the two clothoids 
		createClothoid_negY(R, A1, startPoint1, -VU_norm, clock1);
		createClothoid_negY(R, A2, startPoint2, -VW_norm, clock2);
		// in order to help the user, the start of the clothoid is connected with the alignment which the user created
		buw::HorizontalAlignmentElement2DLine::Ptr line1 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(startPoint1, V + offset);
		ha->addElement(line1);
		buw::HorizontalAlignmentElement2DLine::Ptr line2 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(startPoint2, V + offset);
		ha->addElement(line2);
		// create vertical alignment
		buw::vector2d vstart = buw::vector2d(ha->getStartStation(), 0);
		buw::vector2d vend = buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
		buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
		buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
		va->addElement(v);
		buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Line_Arc_Arc_Line_triggered()
{
	createLineArcArcLineDialog_->show();//source of the formulars: Prof.Dr.-Ing M.Baeumker from Fachhochschule Bochum Skript: Rechenverfahren der Ingenieurvermessung
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Line_Arc_Arc_Line_triggered()
{
	buw::vector2d U, V, W, VU, VW, VU_norm, VW_norm, offset = view_->getOffset().xy(), x_axis = { 1.0, 0.0 };
	auto points = view_->getAlignmentPoints();//very important is to determine between RR1 and R1 because if the user wants to draw three lines different values are computed each time
	double R2 = 0, R1 = 0, RR2 = createLineArcArcLineDialog_->R2, RR1 = createLineArcArcLineDialog_->R1, t1 = 0, t2 = 0, alpha = 0, YM1 = 0, X1 = 0, YM2 = 0, X2 = 0, phi = 0, psi = 0;
	buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
	if (points.size() <= 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least three alignment-points and then call this function again");
		return;
	}
	if (RR2 == 0 && RR1 == 0 || RR2< 0 || RR1< 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first one value, that is larger than zero, in dialog.");
		return;
	}
	if (RR2 > 0 && RR1 > 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "You have insert values for R1 and R2, but you can just insert one value !");
		return;
	}
	for (int ik = 0; ik < points.size() - 2; ik++)
	{
		U = points[ik].xy();
		V = points[ik + 1].xy();
		W = points[ik + 2].xy();
		VU = U - V;
		t1 = VU.length();
		VU_norm = VU / t1;
		VW = W - V;
		t2 = VW.length();
		VW_norm = VW / t2;
		double beta = buw::calculateAngleBetweenVectors(VU, VW);
		if (beta > M_PI)
		{
			beta = 2 * M_PI - beta;
		}
		alpha = M_PI - beta; //in rad
		if (RR1 == 0)
		{
			R2 = RR2;
			YM2 = t2*sin(alpha) + R2*cos(alpha);
			X2 = -t2*cos(alpha) + R2*sin(alpha);
			phi = 2 * atan((YM2 - R2) / (t1 - X2));
			psi = alpha - phi;
			R1 = R2 + (t1 - X2) / sin(phi);
		}
		if (RR2 == 0)
		{
			R1 = RR1;
			YM1 = t1*sin(alpha) + R1*cos(alpha);
			X1 = R1*sin(alpha) - t1*cos(alpha) - t2;
			psi = 2 * atan((-YM1 + R1) / X1);
			phi = alpha - psi;
			R2 = R1 - X1 / sin(psi);
		}
		if (psi < 0 || phi < 0)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Change the angle between the lines or the length of the lines, otherwise one arclength would be negativ.");
		}
		else
		{
			bool clock1 = true;
			buw::vector2d center1, start1, end1, center2, start2, end2;
			int sig = 1;
			if (VU.x()*VW.y() - VU.y()*VW.x() < 0)//vectorproduct determines the orientation of the arcs
			{
				clock1 = false;
				sig = -1;
			}
			start1 = U + offset;
			center1 = start1 + R1* buw::createRotationZ22d(sig*M_PI / 2)* VU_norm;
			end1 = center1 + buw::createRotationZ22d(-sig*phi)* (start1 - center1);
			end2 = W + offset;
			center2 = end2 + R2* buw::createRotationZ22d(-sig*M_PI / 2)* VW_norm;
			start2 = center2 + buw::createRotationZ22d(sig*psi)* (end2 - center2);
			buw::HorizontalAlignmentElement2DArc::Ptr arc1 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
				center1,
				start1,
				end1,
				clock1);
			buw::HorizontalAlignment2D::Ptr horizontalAlignment1 = std::make_shared<buw::HorizontalAlignment2D>();
			horizontalAlignment1->addElement(arc1);
			buw::Alignment2DBased3D::Ptr arc_a1 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment1);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a1);
			buw::HorizontalAlignmentElement2DArc::Ptr arc2 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
				center2,
				start2,
				end2,
				clock1);
			buw::HorizontalAlignment2D::Ptr horizontalAlignment2 = std::make_shared<buw::HorizontalAlignment2D>();
			horizontalAlignment2->addElement(arc2);
			buw::Alignment2DBased3D::Ptr arc_a2 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment2);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a2);
			buw::HorizontalAlignmentElement2DLine::Ptr line1 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(start1, V + offset);
			ha->addElement(line1);
			buw::HorizontalAlignmentElement2DLine::Ptr line2 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(end2, V + offset);
			ha->addElement(line2);
			// create vertical alignment
			buw::vector2d vstart = buw::vector2d(ha->getStartStation(), 0);
			buw::vector2d vend = buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
			buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
			buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
			va->addElement(v);
			buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
		}
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Arc_Clothoid_Arc_triggered()
{
	createArcClothoidArcDialog_->show(); //source of the formulars: Prof.Dr.-Ing M.Baeumker from Fachhochschule Bochum Skript: Rechenverfahren der Ingenieurvermessung
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Arc_Clothoid_Arc_triggered()
{
	buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
	auto points = view_->getAlignmentPoints();
	buw::vector2d  cloth_star_dir, theostartPoint, Vect, offset = view_->getOffset().xy(), x_axis = { 1.0, 0.0 }, center1, start1, end1, center2, start2, end2, endPoint, HendPoint1, HendPoint2;
	double tau1, tau2, R = createArcClothoidArcDialog_->R, L = createArcClothoidArcDialog_->L, R1, R2, phi1 = createArcClothoidArcDialog_->phi1, phi2 = createArcClothoidArcDialog_->phi2, A = createArcClothoidArcDialog_->A;//make tests for deltatau > 90°
	if (points.size() < 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least two alignment-points and then call this function again");
		return;
	}
	if (R <= 0 || phi1 <= 0 || phi2 <= 0 || L < 0 || A < 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first values, that are larger than zero, in dialog.");
		return;
	}
	if (A == 0 && L == 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first values, that are larger than zero, in dialog.");
		return;
	}
	if (A > 0 && L > 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert either A or L but not both.");
		return;
	}
	bool clockX, line1 = createArcClothoidArcDialog_->Radius1;
	double gon = 200 / M_PI; //transformation-factor from rad to gon important for the translation from userinterface to code
	phi1 = phi1 / gon;
	phi2 = phi2 / gon;
	Vect = points[points.size() - 1].xy() - points[points.size() - 2].xy();
	double drawnR = Vect.length();
	R2 = drawnR;
	R1 = R;
	if (line1 == true)
	{
		R1 = drawnR;
		R2 = R;
	}
	if (A == 0 && L != 0)
	{
		A = sqrt((R1*R2 / (std::abs(R1 - R2)))*L);
	}
	double L1 = A*A / R1;
	double L2 = A*A / R2;
	tau1 = A*A / (R1*R1 * 2);
	tau2 = A*A / (R2*R2 * 2);
	HendPoint1.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A);
	HendPoint2.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A);
	if (R1 > R2)
	{
		clockX = false;
		double drawntau = buw::calculateAngleBetweenVectors(x_axis, Vect) - 3 * M_PI / 2;
		buw::vector2d  delta_cloth_dir = buw::createRotationZ22d(M_PI / 2)*Vect;
		HendPoint1.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A);
		HendPoint2.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A);
		if (line1 == true)
		{
			center1 = points[points.size() - 2].xy() + offset;
			end1 = points[points.size() - 1].xy() + offset;
			start1 = center1 + buw::createRotationZ22d(-phi1)* Vect;
			theostartPoint = end1 - buw::createRotationZ22d(drawntau - tau1)*HendPoint1;
			cloth_star_dir = buw::createRotationZ22d(-tau1)*delta_cloth_dir;
			start2 = theostartPoint + buw::createRotationZ22d(drawntau - tau1)*HendPoint2;
			center2 = start2 + R2*buw::createRotationZ22d(drawntau - tau1 + tau2 + M_PI / 2)*x_axis;
			end2 = center2 + buw::createRotationZ22d(phi2)* (start2 - center2);
		}
		else
		{
			center2 = points[points.size() - 2].xy() + offset;
			start2 = points[points.size() - 1].xy() + offset;
			end2 = center2 + buw::createRotationZ22d(phi2)* Vect;
			theostartPoint = start2 - buw::createRotationZ22d(drawntau - tau2)*HendPoint2;
			cloth_star_dir = buw::createRotationZ22d(-tau2)*delta_cloth_dir;
			end1 = theostartPoint + buw::createRotationZ22d(drawntau - tau2)*HendPoint1;
			center1 = end1 + R1*buw::createRotationZ22d(drawntau - tau2 + tau1 + M_PI / 2)*x_axis;
			start1 = center1 + buw::createRotationZ22d(-phi1)* (end1 - center1);
		}
	}
	else
	{
		clockX = true;
		double drawntau = 3 * M_PI / 2 - buw::calculateAngleBetweenVectors(x_axis, Vect);
		buw::vector2d  delta_cloth_dir = buw::createRotationZ22d(-M_PI / 2)*Vect;
		HendPoint1.y() = -buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A);
		HendPoint2.y() = -buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A);
		if (line1 == true)
		{
			center1 = points[points.size() - 2].xy() + offset;
			start1 = points[points.size() - 1].xy() + offset;
			end1 = center1 + buw::createRotationZ22d(-phi1)* Vect;
			theostartPoint = start1 + buw::createRotationZ22d(-drawntau + tau1)*HendPoint1;
			cloth_star_dir = buw::createRotationZ22d(tau1)*delta_cloth_dir;
			end2 = theostartPoint - buw::createRotationZ22d(-drawntau + tau1)*HendPoint2;
			center2 = end2 + R2*buw::createRotationZ22d(-drawntau + tau1 - tau2 + M_PI / 2)*x_axis;
			start2 = center2 + buw::createRotationZ22d(phi2)* (end2 - center2);
		}
		else
		{
			center2 = points[points.size() - 2].xy() + offset;
			end2 = points[points.size() - 1].xy() + offset;
			start2 = center2 + buw::createRotationZ22d(phi2)* Vect;
			theostartPoint = end2 + buw::createRotationZ22d(-drawntau + tau2)*HendPoint2;
			cloth_star_dir = buw::createRotationZ22d(tau2)*delta_cloth_dir;
			start1 = theostartPoint - buw::createRotationZ22d(-drawntau + tau2)*HendPoint1;
			center1 = start1 + R1*buw::createRotationZ22d(-drawntau + tau2 - tau1 + M_PI / 2)*x_axis;
			end1 = center1 + buw::createRotationZ22d(-phi1)* (start1 - center1);
		}
	}
	if (tau1 > 3 * M_PI / 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Reduce A1 or increase R1, because tau is larger than 270 degree.");
		return;
	}
	if (tau2 > 3 * M_PI / 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Reduce A2 or increase R2, because tau is larger than 270 degree.");
		return;
	}
	if (R2 > R1)
	{
		double swap = R2;
		R2 = R1;
		R1 = swap;
	}
	createClothoid_noInfinity(R1, R2, theostartPoint, A, cloth_star_dir, clockX);
	buw::HorizontalAlignmentElement2DArc::Ptr arc1 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
		center1,
		start1,
		end1,
		clockX);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment1 = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment1->addElement(arc1);
	buw::Alignment2DBased3D::Ptr arc_a1 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment1);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a1);
	buw::HorizontalAlignmentElement2DArc::Ptr arc2 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
		center2,
		start2,
		end2,
		clockX);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment2 = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment2->addElement(arc2);
	buw::Alignment2DBased3D::Ptr arc_a2 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment2);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a2);
	for (int i = 0; i < points.size() - 1; i++)
	{
		buw::vector2d start = buw::vector2d(points[i + 0].x(), points[i + 0].y()) + offset;
		buw::vector2d end = buw::vector2d(points[i + 1].x(), points[i + 1].y()) + offset;
		buw::HorizontalAlignmentElement2DLine::Ptr line = std::make_shared<buw::HorizontalAlignmentElement2DLine>(start, end);
		ha->addElement(line);
	}	 // create vertical alignment
	buw::vector2d vstart = buw::vector2d(ha->getStartStation(), 0);
	buw::vector2d vend = buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
	buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
	buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
	va->addElement(v);
	buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Arc_Clothoid_Clothoid_Arc_triggered()
{
	createArcClothoidClothoidArcDialog_->show();//source of the formulars: Prof.Dr.-Ing M.Baeumker from Fachhochschule Bochum Skript: Rechenverfahren der Ingenieurvermessung
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Arc_Clothoid_Clothoid_Arc_triggered()
{
	auto points = view_->getAlignmentPoints();
	double R1 = createArcClothoidClothoidArcDialog_->R1, R2 = createArcClothoidClothoidArcDialog_->R2, phi1 = createArcClothoidClothoidArcDialog_->phi1;
	buw::vector2d startPoint, Vect, offset = view_->getOffset().xy(), x_axis = { 1.0, 0.0 }, center1, start1, end1, center2, start2, end2, help1, help2;
	double phi2 = createArcClothoidClothoidArcDialog_->phi2, A1 = createArcClothoidClothoidArcDialog_->A1, A2 = createArcClothoidClothoidArcDialog_->A2;
	if (points.size() < 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least two alignment-points and then call this function again");
		return;
	}
	if (R1 <= 0 || R2 <= 0 || A1 <= 0 || A2 <= 0 || phi1 <= 0 || phi2 <= 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first values, that are larger than zero, in dialog.");
		return;
	}
	double gon = 200 / M_PI; //transformation-factor from rad to gon important for the translation from userinterface to code
	phi1 = phi1 / gon;
	phi2 = phi2 / gon;
	bool clockArc, clockClo, s_form = createArcClothoidClothoidArcDialog_->s_form;
	//use the points for the last drawn line
	startPoint = points[points.size() - 2].xy() + offset;
	Vect = points[points.size() - 1].xy() - points[points.size() - 2].xy();
	double beta = buw::calculateAngleBetweenVectors(x_axis, Vect);
	double L1 = A1*A1 / R1;
	double L2 = A2*A2 / R2;
	help1.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L1, A1);
	help2.x() = buw::HorizontalAlignmentElement2DClothoid::computeX(L2, A2);
	help1.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L1, A1);
	help2.y() = buw::HorizontalAlignmentElement2DClothoid::computeY(L2, A2);
	double tau1 = (A1*A1) / (2 * R1*R1);
	double tau2 = (A2*A2) / (2 * R2*R2);
	if (tau1 > 3 * M_PI / 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Reduce A1 or increase R1, because tau is larger than 270 degree.");
		return;
	}
	if (tau2 > 3 * M_PI / 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Reduce A2 or increase R2, because tau is larger than 270 degree.");
		return;
	}
	double helpangle1 = beta + tau1 + M_PI / 2;
	double helpangle2 = beta + tau2 - M_PI / 2;
	int sig = 1;
	clockArc = true;
	clockClo = false;
	if (s_form == true)
	{
		sig = -1;
		clockArc = false;
		clockClo = true;
		help2.y() = -help2.y();
		help1.y() = -help1.y();
		helpangle1 = beta - tau1 - M_PI / 2;
		helpangle2 = beta - tau2 + M_PI / 2;
	}
	end1 = startPoint + buw::createRotationZ22d(beta + M_PI)*help1;
	end2 = startPoint + buw::createRotationZ22d(beta)*help2;
	center1 = end1 - R1* buw::createRotationZ22d(helpangle1)* x_axis;
	center2 = end2 - R2* buw::createRotationZ22d(helpangle2)* x_axis;
	start1 = center1 + buw::createRotationZ22d(sig*phi1)*(end1 - center1);
	start2 = center2 + buw::createRotationZ22d(sig*phi2)* (end2 - center2);
	createClothoid_negY(R1, A1, startPoint, -Vect, clockClo);
	createClothoid_negY(R2, A2, startPoint, Vect, clockClo);
	buw::HorizontalAlignmentElement2DArc::Ptr arc1 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
		center1,
		start1,
		end1,
		clockArc);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment1 = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment1->addElement(arc1);
	buw::Alignment2DBased3D::Ptr arc_a1 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment1);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a1);
	buw::HorizontalAlignmentElement2DArc::Ptr arc2 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
		center2,
		start2,
		end2,
		clockArc);
	buw::HorizontalAlignment2D::Ptr horizontalAlignment2 = std::make_shared<buw::HorizontalAlignment2D>();
	horizontalAlignment2->addElement(arc2);
	buw::Alignment2DBased3D::Ptr arc_a2 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment2);
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a2);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionDialog_Line_Arc_Arc_Arc_Line_triggered()
{
	createLineArcArcArcLineDialog_->show();//source of the formulars: Prof.Dr.-Ing M.Baeumker from Fachhochschule Bochum Skript: Rechenverfahren der Ingenieurvermessung
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionGenerate_Line_Arc_Arc_Arc_Line_triggered()
{
	auto points = view_->getAlignmentPoints();
	double R2 = createLineArcArcArcLineDialog_->R2, R3 = 5.5*R2, R1 = 2.5*R2, alpha = 0, Y1, X1, ny, M1M3, epsilon = 0, eta = 0, delta = 0, gon = M_PI / 200, phi = 17.5*gon, psi = 22.5*gon;//phi==a1, psi==a3
	bool clock1, ral = createLineArcArcArcLineDialog_->ral, r213 = createLineArcArcArcLineDialog_->r213;
	buw::vector2d U, V, W, VU, VW, VU_norm, VW_norm, offset = view_->getOffset().xy(), x_axis = { 1.0, 0.0 }, help1, help2;
	buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
	if (points.size() <= 2)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "At first please create at least three alignment-points and then call this function again");
		return;
	}
	if (R2 <= 0)
	{
		QMessageBox::warning(this, QApplication::applicationName(), "Please insert at first values, that are larger than zero, in dialog.");
		return;
	}
	for (int ik = 0; ik < points.size() - 2; ik++)
	{
		U = points[ik].xy();
		V = points[ik + 1].xy();
		W = points[ik + 2].xy();
		VU = U - V;
		VW = W - V;
		double beta = buw::calculateAngleBetweenVectors(VU, VW);
		if (beta > M_PI)
		{
			beta = 2 * M_PI - beta;
		}
		alpha = M_PI - beta; //in rad
		if (r213 == true)
		{
			R3 = 3 * R2;
			R1 = 2 * R2;
		}
		double T1 = ((R2 + (R3 - R2)*(1 - cos(psi))) + (R2 + (R1 - R2)*(1 - cos(phi)))*cos(beta)) / sin(beta) + (R1 - R2)*sin(phi);
		double T2 = ((R2 + (R1 - R2)*(1 - cos(phi))) + (R2 + (R3 - R2)*(1 - cos(psi)))*cos(beta)) / sin(beta) + (R3 - R2)*sin(psi);
		if (T1 < 0 || T2 < 0)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Please change linelengths or R2, otherwise Line Arc Arc Arc Line can not be drawn.");
			eta = psi = phi = -1;
		}
		VW_norm = VW / VW.length();
		VU_norm = VU / VU.length();
		buw::vector2d center1, start1, end1, center2, start2, end2, center3, start3, end3;
		clock1 = true;
		int sig = 1;
		if (VU.x()*VW.y() - VU.y()*VW.x() < 0)//vectorproduct determines the orientation of the arcs
		{
			sig = -1;
			clock1 = false;
		}
		help1 = V + T1*VU_norm;
		help2 = V + T2*VW_norm;
		if (ral == false)
		{
			double t1 = VU.length();
			double t2 = VW.length();
			Y1 = t1*sin(alpha) + R1*cos(alpha);
			X1 = R1*sin(alpha) - t1*cos(alpha);
			ny = atan((R3 - Y1) / (X1 - t2));
			M1M3 = (R3 - Y1) / sin(ny);
			double etahelp = ((R3 - R2)*(R3 - R2) - M1M3*M1M3 + (R1 - R2)*(R1 - R2)) / (2 * (R3 - R2)*(R1 - R2));
			double deltahelp = ((R3 - R2)*(R3 - R2) + M1M3*M1M3 - (R1 - R2)*(R1 - R2)) / (2 * M1M3*(R3 - R2));
			if (std::abs(etahelp) > 1 || std::abs(deltahelp) > 1)
			{
				eta = psi = phi = -1;
			}
			else
			{
				eta = acos(etahelp);
				delta = acos(deltahelp);
				epsilon = M_PI - eta - delta;
				psi = delta + ny - M_PI / 2;
				phi = alpha - eta - psi;
				help1 = U;
				help2 = W;
			}
		}
		if (psi < 0 || phi < 0 || eta < 0)
		{
			QMessageBox::warning(this, QApplication::applicationName(), "Change the angle between the lines or R2 or linelengths, otherwise an arclength would be negativ.");
		}
		else
		{
			start1 = help1 + offset;
			center1 = start1 + R1* buw::createRotationZ22d(sig*M_PI / 2)* VU_norm;
			end1 = center1 + buw::createRotationZ22d(-sig*phi)* (start1 - center1);
			end3 = help2 + offset;
			center3 = end3 + R3* buw::createRotationZ22d(-sig*M_PI / 2)* VW_norm;
			start3 = center3 + buw::createRotationZ22d(sig*psi)* (end3 - center3);
			center2 = center1 + (R1 - R2)*(end1 - center1) / R1;
			start2 = end1;
			end2 = start3;
			buw::HorizontalAlignmentElement2DArc::Ptr arc1 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
				center1,
				start1,
				end1,
				clock1);
			buw::HorizontalAlignment2D::Ptr horizontalAlignment1 = std::make_shared<buw::HorizontalAlignment2D>();
			horizontalAlignment1->addElement(arc1);
			buw::Alignment2DBased3D::Ptr arc_a1 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment1);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a1);
			buw::HorizontalAlignmentElement2DArc::Ptr arc2 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
				center2,
				start2,
				end2,
				clock1);
			buw::HorizontalAlignment2D::Ptr horizontalAlignment2 = std::make_shared<buw::HorizontalAlignment2D>();
			horizontalAlignment2->addElement(arc2);
			buw::Alignment2DBased3D::Ptr arc_a2 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment2);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a2);
			buw::HorizontalAlignmentElement2DArc::Ptr arc3 = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
				center3,
				start3,
				end3,
				clock1);
			buw::HorizontalAlignment2D::Ptr horizontalAlignment3 = std::make_shared<buw::HorizontalAlignment2D>();
			horizontalAlignment3->addElement(arc3);
			buw::Alignment2DBased3D::Ptr arc_a3 = std::make_shared<buw::Alignment2DBased3D>(horizontalAlignment3);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(arc_a3);
			// in order to help the user, the start of the arc1 and the end of arc3 is connected with the alignment which the user created
			buw::HorizontalAlignmentElement2DLine::Ptr line1 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(start1, V + offset);
			ha->addElement(line1);
			buw::HorizontalAlignmentElement2DLine::Ptr line2 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(end3, V + offset);
			ha->addElement(line2);
			// create vertical alignment
			buw::vector2d vstart = buw::vector2d(ha->getStartStation(), 0);
			buw::vector2d vend = buw::vector2d(ha->getStartStation() + ha->getLength(), 0);
			buw::VerticalAlignmentElement2DLine::Ptr v = std::make_shared<buw::VerticalAlignmentElement2DLine>(vstart, vend);
			buw::VerticalAlignment2D::Ptr va = std::make_shared<buw::VerticalAlignment2D>();
			va->addElement(v);
			buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>(ha, va);
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment);
		}
	}
}
	 
void OpenInfraPlatform::UserInterface::MainWindow::aboutQt()
{
	QMessageBox::aboutQt(this);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionShow_Help_triggered()
{
	HelpBrowser::showPage("index.html");
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionOkstra_triggered()
{
	QString version;
	QString filename = QFileDialog::getSaveFileName(
		this,
		tr("Save Document"),
		QDir::currentPath(),
		tr("OKSTRA 2.016 (*.xml);;OKSTRA 1.014 (*.xml);; OKSTRA 1.013 (*.xml);; OKSTRA 1.014 (*.cte);; OKSTRA 1.013 (*.cte);; "), //tr("OKSTRA 2.016 (*.xml);; OKSTRA 1.014 (*.xml);; OKSTRA 1.013 (*.xml);; OKSTRA 2.016 (*.cte);; OKSTRA 1.014 (*.cte);; OKSTRA 1.013 (*.cte)"),
		&version);


	if (!filename.isNull())
	{
		version = version.split(" ")[1];
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().exportOkstra(filename.toStdString(), version.toStdString());
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_pushButtonDeleteSelectedAlignment_clicked()
{
	int index = ui_->comboBoxAlignment->currentIndex();

	buw::AlignmentModel::Ptr am = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getAlignmentModel();

	if (am->getAlignmentCount() > index && index >= 0)
	{
		buw::IAlignment3D::Ptr a = am->getAlignment(index);

		buw::DeleteAlignment::Ptr actionDeleteAlignment = std::make_shared<buw::DeleteAlignment>(a);
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().execute(actionDeleteAlignment);
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_pushButtonDeleteSurface_clicked()
{
	int index = ui_->comboBoxSurfaces->currentIndex();

	buw::DigitalElevationModel::Ptr dem = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getDigitalElevationModel();

	if (dem->getSurfaceCount() > index && index >= 0)
	{
		buw::Surface::Ptr s = dem->getSurface(index);

		buw::DeleteSurface::Ptr actionDeleteSurface = std::make_shared<buw::DeleteSurface>(s);
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().execute(actionDeleteSurface);
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::updateActionUndo(unsigned int numberOfUndoActions)
{
	if (numberOfUndoActions > 0)
	{
		ui_->actionUndo->setEnabled(true);
	}
	else
	{
		ui_->actionUndo->setEnabled(false);
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::updateActionRedo(unsigned int numberOfRedoActions)
{
	if (numberOfRedoActions > 0)
	{
		ui_->actionRedo->setEnabled(true);
	}
	else
	{
		ui_->actionRedo->setEnabled(false);
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionExport_Terrain_As_Heightmap_triggered()
{
	QString openFile = QFileDialog::getSaveFileName(
		this,
		tr("Save File"),
		QDir::currentPath(),
		tr("Portable Network Graphics (*.png);;Bitmap (*.bmp);;JPEG (*.jpg);;TIFF (*.tif)")
		);

	if (openFile.isNull() == false)
	{
		OpenInfraPlatform::Infrastructure::DigitalElevationModel::Ptr dem =
			OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getDigitalElevationModel();

		buw::vector3d tmin, tmax;
		dem->getSurfacesExtend(tmin, tmax);

		float width = tmax.x() - tmin.x();
		float depth = tmax.y() - tmin.y();

		float aspect = depth / width;
		
		buw::Image_3b::Ptr img = std::make_shared<buw::Image_3b>(256, 256 * aspect );

		double minHeight = 1000000000;
		double maxHeight = 0;

		for (int y = 0; y < img->getHeight(); y++)
		{
			for (int x = 0; x < img->getWidth(); x++)
			{

				buw::vector2d postiton = buw::vector2d(
					x / static_cast<float>(img->getWidth()) * width  + tmin.x(),
					y / static_cast<float>(img->getHeight()) * depth + tmin.y()
				);
				
				double dHeight = dem->getHeightAtPosition(postiton) / 128.0;

				if (dHeight > maxHeight)
				{
					maxHeight = dHeight;
				}

				if (dHeight < minHeight)
				{
					minHeight = dHeight;
				}

				int height = std::max(0, std::min(255, static_cast<int>(255 * dHeight)));
				buw::color3b c(height, height, height);
				img->setPixelColor(x, y, c);
			}
		}

		std::cout << minHeight << std::endl;
		std::cout << maxHeight << std::endl;

		buw::storeImageAsFile(openFile.toStdString().c_str(), img.get());
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionIfcAlignment_buildingSMART_P6_Excel_Comparison_triggered()
{
	exportExcelDialog_->show();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionAlignments_as_3D_Points_txt_triggered()
{
	QString filename = QFileDialog::getSaveFileName(
		this,
		tr("Save File"),
		QDir::currentPath(),
		tr("Normal text file (*.txt)")
		);

	if (filename.isNull() == false)
	{
		OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().export3DAlignmentAsTextfile(filename.toStdString());	
	}
}

void OpenInfraPlatform::UserInterface::MainWindow::on_checkBoxShowDifferentAlignmentElements_clicked( bool checked )
{
	view_->setHighlightDifferentAlignmentElements(checked);
	verticalAlignmentWindow_->setDifferentColorsForHorizontalAlignmentElements(checked);
	curvatureWindow_->setHighlightDifferentAlignmentElements(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_checkBoxDifferentColorsForVerticalAlignmentElements_clicked(bool checked)
{
	verticalAlignmentWindow_->setDifferentColorsForVerticalAlignmentElements(checked);
	curvatureWindow_->setDifferentColorsForVerticalAlignmentElements(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_checkBoxUseUniformColor_clicked(bool checked)
{
	view_->setUseUniformPointColor(checked);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_checkBoxUseUniformSize_clicked(bool checked)
{
	view_->setUseUniformPointSize(checked);
}
void OpenInfraPlatform::UserInterface::MainWindow::on_doubleSpinBoxPointSize_valueChanged(double value)
{
	double spinRange = ui_->doubleSpinBoxPointSize->maximum() - ui_->doubleSpinBoxPointSize->minimum();
	int sliderRange = ui_->horizontalSliderPointSize->maximum() - ui_->horizontalSliderPointSize->minimum();
	int sliderVal = value*sliderRange / spinRange + ui_->horizontalSliderPointSize->minimum();
	
	ui_->horizontalSliderPointSize->blockSignals(true);
	ui_->horizontalSliderPointSize->setValue(sliderVal);
	ui_->horizontalSliderPointSize->blockSignals(false);

	view_->setPointSize((float)value);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_horizontalSliderPointSize_sliderMoved(int value)
{
	double spinRange = ui_->doubleSpinBoxPointSize->maximum() - ui_->doubleSpinBoxPointSize->minimum();
	int sliderRange = ui_->horizontalSliderPointSize->maximum() - ui_->horizontalSliderPointSize->minimum();
	double spinVal = value*spinRange / sliderRange + ui_->doubleSpinBoxPointSize->minimum();
	
	ui_->doubleSpinBoxPointSize->blockSignals(true);
	ui_->doubleSpinBoxPointSize->setValue(spinVal);
	ui_->doubleSpinBoxPointSize->blockSignals(false);

	view_->setPointSize((float)spinVal);
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionLoad_Bridge()
{
	view_->LoadBridge();
}

void OpenInfraPlatform::UserInterface::MainWindow::on_actionPrecisionTest()
{
	bool ok;
	int iterations = QInputDialog::getInt(this, "Precision Test", "Number of Iterations", 5, 1, 100, 1, &ok);
	if (ok)
		precisionTest_.startTest(iterations);

	
}