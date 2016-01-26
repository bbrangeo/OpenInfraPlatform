/*! \verbatim
*  \copyright      Copyright (c) 2015 Technische Universität München
*                  Chair of Computational Modeling and Simulation. All rights reserved.
*  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de)
*  \brief          This file is part of the TUM Open Infra Platform.
*  \endverbatim
*/
#ifndef IFC4FILEFACTORY_H
#define IFC4FILEFACTORY_H // this program generates ifc4_tunnel files and ifc4 files
#pragma once

#include "OpenInfraPlatform/IfcTunnel/entity/include/IfcSIUnit.h"
#include "OpenInfraPlatform/IfcTunnel/guid/CreateGuid_64.h"
#include "OpenInfraPlatform/IfcTunnel/IfcTunnelEntities.h"
#include "link2.h"
#include "OpenInfraPlatform/IfcTunnel/model/IfcTunnelException.h"
#include "OpenInfraPlatform/IfcTunnel/model/IfcTunnelModel.h"
#include "OpenInfraPlatform/IfcTunnel/model/UnitConverter.h"
#include "OpenInfraPlatform/IfcTunnel/reader/IfcStepReader.h"
#include "OpenInfraPlatform/IfcTunnel/reader/IfcTunnelReader.h"
#include "OpenInfraPlatform/IfcTunnel/writer/IfcStepWriter.h"
#include "buw.BlueCore.h"
#include "buw.BlueEngine.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <iomanip>
#include "OpenInfraPlatform/IfcTunnel/entity/include/IfcTunnel.h"
#include "OpenInfraPlatform/IfcTunnel/entity/include/IfcTunnelElement.h"
#include "OpenInfraPlatform/IfcTunnel/entity/include/IfcTunnelInstallationEnum.h"
#include "OpenInfraPlatform/IfcTunnel/entity/include/IfcTunnelPart.h"
#include "OpenInfraPlatform/IfcTunnel/entity/include/IfcTunnelSpace.h"
#include "OpenInfraPlatform/IfcTunnel/entity/include/IfcTunnelSpaceEnum.h"
#include "OpenInfraPlatform/IfcTunnel/entity/include/IfcTunnnelInstallation.h"


struct t_part
{
	int previous;
	int current;
	int father_pos;
	int aggregate_pos;
	std::string openName;
	bool first;
};

using namespace OpenInfraPlatform::IfcTunnel;

class TunnelGeneratorIfc4 {

public:
	TunnelGeneratorIfc4(std::vector <t_part>, std::string, bool );
	~TunnelGeneratorIfc4();
	std::shared_ptr<IfcGloballyUniqueId> createGUID();
	static std::shared_ptr<TunnelGeneratorIfc4> create(std::vector <t_part>, std::string, bool );
	void store(bool);

private:
	shared_ptr<IfcApplication> createIfcApplication(shared_ptr<IfcOrganization> applicationDeveloper);
	shared_ptr<IfcOrganization> createIfcOrganization();
	shared_ptr<IfcUnitAssignment> createIfcUnitAssignment();
	void insertAttributes(shared_ptr<IfcOwnerHistory>, std::string, shared_ptr<IfcObjectDefinition>);
	//shared_ptr<IfcSlab> createIfcSlab(shared_ptr<IfcOwnerHistory> , shared_ptr<IfcProductRepresentation> representation);
	//shared_ptr<IfcBuilding> createIfcBuilding(shared_ptr<IfcOwnerHistory> ,shared_ptr<IfcLocalPlacement> );
	shared_ptr<IfcRelContainedInSpatialStructure> createIfcRelSpat(shared_ptr<IfcOwnerHistory>, shared_ptr<IfcObjectDefinition>);
	shared_ptr<IfcRepresentationContext> createIfcRepresentationContext();
	shared_ptr<IfcPerson> createIfcPerson();
	shared_ptr<IfcPersonAndOrganization> createIfcPersonAndOrganization(shared_ptr<IfcPerson>, shared_ptr<IfcOrganization>);
	shared_ptr<IfcOwnerHistory> createIfcOwnerHistory(shared_ptr<IfcPersonAndOrganization>, shared_ptr<IfcApplication>);
	shared_ptr<IfcCartesianPoint> createIfcCartesianPoint(const float x, const float y, const float z);
	shared_ptr<IfcPolyLoop> createIfcPolyLoop(std::vector<shared_ptr<IfcCartesianPoint>>);
	shared_ptr<IfcFaceOuterBound> createIfcFaceOuterbound(shared_ptr<IfcPolyLoop>);
	shared_ptr<IfcFace> createIfcFace(shared_ptr<IfcFaceOuterBound>);
	shared_ptr<IfcDirection> createIfcDirection(const float x, const float y, const float z);
	shared_ptr<IfcClosedShell> createIfcClosedShell(std::vector<shared_ptr<IfcFace>>);
	shared_ptr<IfcShapeRepresentation> createIfcShapeRepresentation(std::vector<shared_ptr<IfcRepresentationItem>>, shared_ptr<IfcRepresentationContext>);
	shared_ptr<IfcProductDefinitionShape> createIfcProductDefinitionShape(std::vector<shared_ptr<IfcRepresentation>>);
	shared_ptr<IfcFacetedBrep> createIfcFacetedBrep(shared_ptr<IfcClosedShell>);
	shared_ptr<IfcSpace> createIfcSpace(shared_ptr<IfcOwnerHistory>, shared_ptr<IfcCartesianPoint>, std::string, shared_ptr<IfcObjectPlacement>);
	shared_ptr<IfcProxy> createIfcProxy(shared_ptr<IfcOwnerHistory>, shared_ptr<IfcCartesianPoint>, std::string, shared_ptr<IfcObjectPlacement>);
	shared_ptr<IfcRelAggregates> createIfcRelAggregates(shared_ptr<IfcOwnerHistory>, shared_ptr<IfcObjectDefinition>);
	shared_ptr<IfcGeometricRepresentationContext> createIfcGeometricRepresentationContext(shared_ptr<IfcAxis2Placement3D>);
	shared_ptr<IfcRelSpaceBoundary> createIfcRelSpace(shared_ptr<IfcOwnerHistory>, shared_ptr<IfcSpaceBoundarySelect>);
	shared_ptr<IfcAxis2Placement3D> createIfcAxis2Placement3D(shared_ptr<IfcCartesianPoint>);
	shared_ptr<IfcLocalPlacement> createIfcLocalPlacement(shared_ptr<IfcAxis2Placement3D>, shared_ptr<IfcObjectPlacement>);
	shared_ptr<IfcTunnelSpace> createIfcTunnelSpace(shared_ptr<IfcOwnerHistory>, shared_ptr<IfcLocalPlacement>, int, shared_ptr<IfcCartesianPoint>, shared_ptr<IfcObjectPlacement>);
	shared_ptr<IfcTunnnelInstallation> createIfcTunnelInstallation(shared_ptr<IfcOwnerHistory>, shared_ptr<IfcLocalPlacement>, int, shared_ptr<IfcCartesianPoint>, shared_ptr<IfcObjectPlacement>);
private:
	int id;
	shared_ptr<IfcTunnelModel> model_;
	std::string filename_;
};

#endif

