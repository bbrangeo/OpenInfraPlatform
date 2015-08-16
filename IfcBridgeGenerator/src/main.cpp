#include "UserInterface/BridgeGeneratorWindow.h"
#include "buw.BlueCore.h"

BLUE_DROP_COMPILER_LEVEL_TO_3
#include <QtGui>
#include <QtCore>
#include <QLabel>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
BLUE_RESTORE_COMPILER_WARNING_LEVEL

int main(int argc,char *argv[])
{
	std::ofstream logfile;
	logfile.open("log.txt");
	buw::LogManager::getInstance().addOutputStream(&logfile);

	buw::LifetimeManager lm;

	// log file should be outputted in XML format
	buw::logMangerSettings settings;
	settings.outputAsXML = true;
	settings.colorConsoleOutput = true;
	buw::LogManager::getInstance().setSettings(settings);
	buw::LogManager::getInstance().LogCPUInfo();
	buw::LogManager::getInstance().LogOSInfo();
	buw::LogManager::getInstance().LogGPUInfo();
		
	QApplication application(argc,argv);
	std::string basePath = "Style/appleseed_mod.qss";

	QFile styleSheet(basePath.c_str());

 	if (!styleSheet.open(QIODevice::ReadOnly))
 	{
 		qWarning("Unable to open stylesheet");
 	}
 	else
 	{
 		application.setStyleSheet(styleSheet.readAll());
 	}

	BlueIfcBridgeViewer::UserInterface::BridgeGeneratorWindow bgw;
	bgw.show();

	return application.exec();
}
