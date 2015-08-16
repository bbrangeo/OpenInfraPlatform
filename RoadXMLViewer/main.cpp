/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "buw.BlueCore.h"
#include "RoadXMLViewer.h"

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

	if (buw::getBlueCoreRevisionVersion() != buw::VERSION_REVISION)
	{
		BLUE_LOG_STREAM_EX("main", buw::eLogSeverityLevel::Error) << "Invalid BlueCore DLL found!";
	}

	buw::renderWindowsDescription rwd;
	rwd.enableMSAA = true;
	rwd.renderSystem = buw::eRenderSystem::Direct3D;
	rwd.majorVersion = 11;
	rwd.miniorVersion = 0;
	rwd.d3dFeatureLevel = buw::eD3D11FeatureLevel::FeatureLevel10_0;
	rwd.sampleCount = 4;
	rwd.resolution = buw::getResolution(buw::eResolutionType::SVGA);
	RoadXMLViewer rxv(rwd);
	rxv.run();
	return 0;
}
