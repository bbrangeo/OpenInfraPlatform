#pragma once
#include "OpenInfraPlatform/IfcBridge/model/shared_ptr.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <map>
#include <vector>

struct bridgeDescription
{
	bridgeDescription()
	{
		length = 100.0;
		width  = 15.0;
	}

	double length;
	double width;
};

class IfcBridgeParamter 
{
public:
	IfcBridgeParamter(const bridgeDescription& bd);
	~IfcBridgeParamter();
	
	struct Point
	{
		double coordinates[3];
	};

	struct CrossSection 
	{
		Point points[9];
	};

	struct ReferenceCurve 
	{
		Point points[2];
	};

	struct AbutmentGroundSketch
	{
		Point points[9];
		Point foundationPoint;
		Point subtractionPoints[5];
		Point subtractionPoint;
		double extrusionDepth;
	};

	struct AbutmentFoundation
	{
		Point points[9];
		Point foundationPoint;
		double thickness;
	};

	struct Foundation
	{
		Point points[4];
		Point foundationPoint;
		double extrusionDepth;
	};

	struct Pier
	{
		Point points[4];
		Point foundationPoint;
		double extrusionDepth;
		Foundation foundation;
	};
	
	struct CrossSectionsPosition
	{
		double abscissa;
		Point axis;
		Point refDirection;
	};
	
	void createReferenceCurve();
	void createCrossSection();
	void createCrossSectionPosition(double, Point, Point);
	void createAbutmentGroundSketch(Point, std::string position);
	void createAbutmentFoundations();
	void createPier();

	ReferenceCurve								getReferenceCurve() {return referenceCurve;}
	std::map<int, CrossSection>					getCrossSectionsSet(){return this->crossSectionsSet;}
	std::map<int, CrossSectionsPosition>		getCrossSectionsPositionsSet(){return this->crossSectionsPositionsSet;}
	std::map<std::string, AbutmentGroundSketch> getAbutments(){return this->abutmentsSet;}
	std::map<std::string, AbutmentFoundation>	getAbutmentFoundations(){return this->abutmentFoundationsSet;}
	std::vector<Pier>							getPierSet(){return this->pierSet;}
	
	Point										start_point, 
												end_point, 
												foundationPointStart, 
												foundationPointEnd;
	Point										normal_x, 
												normal_z,
												normal_y,
												negative_z;

	double										length, 
												width, 
												thickness;
	double										overlapAbutmentDeck;
	ReferenceCurve								referenceCurve;

	std::vector<Pier>							pierSet;
	std::map<std::string, std::string>			bridgeProperties;
	std::map<int, CrossSection>					crossSectionsSet;
	std::map<int, CrossSectionsPosition>		crossSectionsPositionsSet;
	std::map<int, int>							pos_cs_table;
	std::map<std::string, AbutmentGroundSketch> abutmentsSet;
	std::map<std::string, AbutmentFoundation>	abutmentFoundationsSet;
};

