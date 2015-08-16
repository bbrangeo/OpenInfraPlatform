/*! \verbatim
 *  \copyright		Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author			Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\author			Daniel Below <daniel.below@tum.de>
 *	\brief			This file is part of the BlueFramework.
 *	\endverbatim
 */

#include "OpenInfraPlatform/Benchmark.h"
#include "OpenInfraPlatform/UserInterface/MainWindow.h"
#include "OpenInfraPlatform/UserInterface/CodeEditorWindow.h"
#include "buw.BlueCore.h"
#include "fvupdater.h"
#include <QtGui>
#include <QtCore>
#include <QMainWindow>
#include <QDockWidget>
#include <QApplication>
#include <sstream>
#include <string>
#include <sstream>

#include "version.h"

void compile();

int main(int argc,char *argv[])
{
	std::ofstream logfile;
	logfile.open("log.txt");
	buw::LogManager::getInstance().addOutputStream(&logfile);

	// log file should be outputted in XML format
	buw::logMangerSettings settings;
	settings.outputAsXML = true;
	settings.colorConsoleOutput = true;
	buw::LogManager::getInstance().setSettings(settings);

	buw::LifetimeManager lm;
	
	OpenInfraPlatform::Benchmark::getInstance().beginStartup();

	// check if we have an appropriate BlueFramework
	if (!buw::isAtLeast(2, 4, 618))
	{
		BLUE_LOG_STREAM_EX("main", buw::eLogSeverityLevel::Error) 
			<< "Please switch to BlueFramework 2.4.508 or newer!";
		system("pause");
	}

	if (buw::getBlueCoreRevisionVersion() != buw::VERSION_REVISION)
	{
		BLUE_LOG_STREAM_EX("main", buw::eLogSeverityLevel::Error) << "Invalid BlueCore DLL found!";
	}

	if (!true)
	{
		compile();
		return 0;
	}
	
	buw::LogManager::getInstance().LogCPUInfo();
	buw::LogManager::getInstance().LogOSInfo();
	buw::LogManager::getInstance().LogGPUInfo();

	QApplication application(argc,argv);
	
	QApplication::setApplicationName("TUM Open Infra Platform 2015");
	QApplication::setApplicationVersion(OpenInfraPlatform::VERSION_STR.c_str());
	QApplication::setOrganizationName("Technische Universitaet Muenchen Chair of Computational Modeling and Simulation");
	QApplication::setOrganizationDomain("cms.bv.tum.de");

	// Set this to your own appcast URL, of course
	FvUpdater::sharedUpdater()->SetFeedURL("http://vertexwahn.de/OpenInfraPlatform/Appcast.xml");

	// Check for updates silently -- this will not block the initialization of
	// your application, just start a HTTP request and return immediately.
	FvUpdater::sharedUpdater()->CheckForUpdatesSilent();

	std::string basePath = "Style/blueform.qss";//":Resources/Style/blueform.qss";//

	QFile styleSheet(basePath.c_str());

	if (!styleSheet.open(QIODevice::ReadOnly))
	{
		qWarning("Unable to open stylesheet");
	}
	else
	{
		application.setStyleSheet(styleSheet.readAll());
	}

	// check if we are in beta phase
	QDate expirationDate(2018, 4, 1);
	if ( expirationDate < QDate::currentDate() )
	{
		QString desc = QString(
			"The Beta phase has ended. Please visit our website for a new version:<br/> <a href=\"https://www.cms.bgu.tum.de/de/component/content/article/31-forschung/projekte/397-tum-open-infra-platform\"><font color=\"#48B7E7\">http://www.cms.bgu.tum.de</font></a><br/>"
		);

		QMessageBox::information(nullptr, "Beta Phase ended", desc );

		return 0;
	}
	
	QTranslator translator;
	translator.load("English", "Data/translations");
	application.installTranslator(&translator);

	if (true)
	{
		try
		{
			OpenInfraPlatform::UserInterface::MainWindow mainWindow;
			mainWindow.setAttribute(Qt::WA_QuitOnClose);
			mainWindow.show();
			return application.exec();
		}
		catch (const buw::FileNotFoundException& e)
		{
			std::stringstream ss;
			ss << "An unexpected error occurred:\nCould not find file \"" << e.getFilename().c_str() << "\"";
			QMessageBox::information(nullptr,  QApplication::applicationName(), ss.str().c_str() );
		}
	}
	else
	{
		OpenInfraPlatform::UserInterface::CodeEditorWindow CodeEditor;
		CodeEditor.show();
		return application.exec();
	}
}
