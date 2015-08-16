#include "buw.BlueCore.h"
#include "LandXMLViewer.h"

#include "buw.BlueInfrastructure.h"

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
	LandXMLViewer rxv(rwd);
	rxv.run();

	return 0;
}
