/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann))
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "buw.BlueCore.h"

#include "buw.BlueInfrastructure.h"

#include <iomanip>

#include "tclap/CmdLine.h"

void convertLandXMLtoIfcExcelComparison(const char* inputFilename, const char* outputFilename)
{
	buw::LandXmlImport landxml_import(inputFilename);

	buw::ReferenceCounted<buw::DigitalElevationModel> dem = std::make_shared<buw::DigitalElevationModel>();

	if (landxml_import.getDigitalElevationModel())
	{
		for (int i = 0; i < landxml_import.getDigitalElevationModel()->getSurfaceCount(); i++)
		{
			dem->addSurface(landxml_import.getDigitalElevationModel()->getSurface(i));
		}
	}

	buw::ifcAlignmentExportDescription desc;
	desc.exportAlignment = true;
	desc.exportTerrain = true;
	buw::IfcAlignmentExport sfc(desc, landxml_import.getAlignmentModel(), dem, "alignment.ifc");

	buw::ExcelReport ec(
		outputFilename,
		inputFilename,
		"alignment.ifc");
}

void convertLandXMLtoIfcAlignmentP6(const std::string& inputFilename, const std::string& outputFilename)
{
	buw::LandXmlImport parser(inputFilename);
	
	buw::ReferenceCounted<buw::DigitalElevationModel> dem = std::make_shared<buw::DigitalElevationModel>();
	
	if (parser.getDigitalElevationModel())
	{
		for (int i = 0; i < parser.getDigitalElevationModel()->getSurfaceCount(); i++)
		{
			dem->addSurface(parser.getDigitalElevationModel()->getSurface(i));
		}
	}

	buw::ifcAlignmentExportDescription desc;
	desc.exportTerrain = true;
	desc.exportAlignment = true;

	buw::IfcAlignmentExport ifcExport(
		desc, 
		parser.getAlignmentModel(),
		dem,
		outputFilename
	);
}

void convertLandXMLtoSVG(const std::string& inputFilename, const std::string& outputFilename)
{
	buw::LandXmlImport parser(inputFilename);

	buw::ReferenceCounted<buw::DigitalElevationModel> dem = std::make_shared<buw::DigitalElevationModel>();

	if (parser.getDigitalElevationModel())
	{
		for (int i = 0; i < parser.getDigitalElevationModel()->getSurfaceCount(); i++)
		{
			dem->addSurface(parser.getDigitalElevationModel()->getSurface(i));
		}
	}

	buw::SVGExport svgExport(parser.getAlignmentModel(), dem, outputFilename);
}


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

	try 
	{
		buw::CmdLine cmd("TUM Open Infra Platform command line utilities", ' ', "0.1");

		// Define a value argument and add it to the command line.
		buw::ValueArg<std::string> nameOutputArg("o", "output", "Path to input file", true, "text.xml", "string");
		cmd.add(nameOutputArg);

		// Define a value argument and add it to the command line.
		buw::ValueArg<std::string> nameInputArg("i", "input", "Path to input file", true, "text.xml", "string");
		cmd.add(nameInputArg);
		
		// Parse the args.
		cmd.parse(argc, argv);

		// Get the value parsed by each arg. 
		std::string inputFilename = nameInputArg.getValue();
		std::string outputFilename = nameOutputArg.getValue();

		if (buw::endsWith(".xlsx", outputFilename))
		{
			convertLandXMLtoIfcExcelComparison(inputFilename.c_str(), outputFilename.c_str());
		}
		else if(buw::endsWith(".svg", outputFilename))
		{
			convertLandXMLtoSVG(inputFilename.c_str(), outputFilename.c_str());
		}
		else
		{
			convertLandXMLtoIfcAlignmentP6(inputFilename, outputFilename);
		}
	}
	catch (buw::ArgException &e)  // catch any exceptions
	{
		std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
	}
	
	return 0;
}
