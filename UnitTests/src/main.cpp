#include <string>
#include <iostream>
//#include <vld.h>
using namespace std;
#include "gtest/gtest.h"

#include "BlueFramework/Core/Diagnostics/LogManager.h"
#include "BlueFramework/Core/String.h"
#include <fstream>

int main(int argc, char **argv) 
{
	std::ofstream logfile;
	logfile.open("log.xml");
	buw::LogManager::getInstance().addOutputStream(&logfile);
	
	// log file should be outputed in XML format
	buw::logMangerSettings settings;
	settings.outputAsXML = true;
	settings.colorConsoleOutput = false;
	buw::LogManager::getInstance().setSettings(settings);

	// write CPU/OS Info into log file
	//buw::LogManager::getInstance().LogSystemInfo();
	
	int result = 0;

	try
	{
		::testing::InitGoogleTest(&argc, argv);
	
		result = RUN_ALL_TESTS();
	}
	catch (const std::exception& e)
	{
		std::cout << "Unit test crashed..." << e.what() << std::endl;
	}
	
	buw::LogManager::getInstance().removeOutputStream(&logfile);

	return result;
}
