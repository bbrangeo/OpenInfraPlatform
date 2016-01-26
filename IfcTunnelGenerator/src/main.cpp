/*! \verbatim
*  \copyright      Copyright (c) 2015 Technische Universität München
*                  Chair of Computational Modeling and Simulation. All rights reserved.
*  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de)
*  \brief          This file is part of the TUM Open Infra Platform.
*  \endverbatim
*/
#include "UserInterface/TunnelGenerator.h"

#include <QtCore>
#include <QMainWindow>

int main(int argc, char *argv[])
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

	QApplication application(argc, argv);
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

	UserInterface::TunnelGenerator tg;
	tg.show();

	return application.exec();
}
