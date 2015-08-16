#include <iostream>
#include <fstream>
#include <memory>
#include <iomanip>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Model.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/IfcStepReader.h"
#include "OpenInfraPlatform/Ifc4/writer/IfcStepWriter.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Model.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/IfcStepReader.h"
#include "OpenInfraPlatform/Ifc4/reader/Ifc4Reader.h"
#include "OpenInfraPlatform/Ifc4/writer/IfcStepWriter.h"
#include "OpenInfraPlatform/Ifc4/model/UnitConverter.h"
#include "OpenInfraPlatform/Ifc4/entity/include/IfcSIUnit.h"
#include "OpenInfraPlatform/Ifc4/Ifc4Types.h"
#include "OpenInfraPlatform/Ifc4/Ifc4Entities.h"
#include "OpenInfraPlatform/Ifc4/guid/CreateGuid_64.h"
#include "OpenInfraPlatform/IfcTunnel/guid/CreateGuid_64.h"

#include "buw.BlueCore.h"
#include "buw.BlueEngine.h"

using namespace OpenInfraPlatform::Ifc4;

std::string replace(const std::string& str, const std::string& findWhat, const std::string& replaceWith)
{
	std::string context = str;
	size_t lookHere = 0;
	size_t foundHere;
	while((foundHere = context.find(findWhat, lookHere))
		!= std::string::npos) {
			context.replace(foundHere, findWhat.size(), replaceWith);
			lookHere = foundHere + replaceWith.size();
	}
	return context;
}

class TunnelGeneratorIfc4
{
public:
	typedef std::shared_ptr<TunnelGeneratorIfc4> Ptr;

	std::shared_ptr<IfcGloballyUniqueId> createGUID()
	{
		return std::make_shared<IfcGloballyUniqueId>(OpenInfraPlatform::IfcTunnel::CreateCompressedGuidString());
	}

	TunnelGeneratorIfc4() : 
		id(1),
		model_(nullptr)
	{
		// create model
		model_ = shared_ptr<Ifc4Model>(new Ifc4Model());

		shared_ptr<IfcOrganization> organization = createIfcOrganization();
		shared_ptr<IfcApplication> application = createIfcApplication(organization);
		
		shared_ptr<IfcProject> project = std::make_shared<IfcProject>(id++);
		project->m_Name = std::make_shared<IfcLabel>("Tunnel Project");
		project->m_UnitsInContext = createIfcUnitAssignment();
		model_->insertEntity(project);

		shared_ptr<IfcSite> site = std::make_shared<IfcSite>(id++);
		site->m_Description = std::make_shared<IfcText>("Site for a simple tunnel.");
		site->m_GlobalId = createGUID();
		model_->insertEntity(site);

		//shared_ptr<IfcTunnel> tunnel = std::make_shared<IfcTunnel>(id++);
		//model_->insertEntity(tunnel);
		//
		//shared_ptr<IfcTunnelPart> tunnelPart = std::make_shared<IfcTunnelPart>(id++);
		//model_->insertEntity(tunnelPart);


		shared_ptr<IfcAxis2Placement3D> axisPlacement = createIfcAxis2Placement3D( createIfcCartesianPoint(0, 0, 0) );
		shared_ptr<IfcLocalPlacement> localPlacement = createIfcLocalPlacement(axisPlacement);

		shared_ptr<IfcPerson> person = createIfcPerson();

		auto personAndOrganization = createIfcPersonAndOrganization(person, organization);

		shared_ptr<IfcOwnerHistory> ownerHistory = createIfcOwnerHistory(personAndOrganization, application);

		createIfcBuilding(ownerHistory, localPlacement);

		std::vector<shared_ptr<IfcFace>> faces;
		
		buw::ObjReader objReader;
		//objReader.load("data/tunnel.obj");
		objReader.load("C:/Users/no68koc/Desktop/STL/LOD2_FullTunnelSpace.obj");
		int chunkCount = objReader.getChunkCount(); // equal to group count
		buw::SimpleMesh::Ptr sm = buw::ConvertToSimpleMesh(objReader.getChunk(0));

		for (int i = 0; i < sm->GetIndexCount(); i+=3)
		{
			int i1 = sm->GetIndexDataPointer()[i];
			int i2 = sm->GetIndexDataPointer()[i+1];
			int i3 = sm->GetIndexDataPointer()[i+2];

			buw::VertexPositionNormalTexture v1, v2, v3;

			sm->GetVertex(i1, v1);
			sm->GetVertex(i2, v2);
			sm->GetVertex(i3, v3);
			
			std::vector<shared_ptr<IfcCartesianPoint>> points;

			points.push_back( createIfcCartesianPoint(v1.position.x(), v1.position.y(), v1.position.z()) );
			points.push_back( createIfcCartesianPoint(v2.position.x(), v2.position.y(), v2.position.z()) );
			points.push_back( createIfcCartesianPoint(v3.position.x(), v3.position.y(), v3.position.z()) );

			shared_ptr<IfcPolyLoop> polyLoop = createIfcPolyLoop(points);
			shared_ptr<IfcFaceOuterBound> outerBound = createIfcFaceOuterbound(polyLoop);
			faces.push_back(createIfcFace(outerBound));
		}


		shared_ptr<IfcClosedShell> closedShell = createIfcClosedShell(faces);

		std::vector<shared_ptr<IfcRepresentationItem>> representationItems;
		representationItems.push_back( createIfcFacetedBrep(closedShell) );

		auto representationContext = createIfcRepresentationContext();

		std::vector<shared_ptr<IfcRepresentation>> representation;
		representation.push_back( createIfcShapeRepresentation(representationItems, representationContext) );
		
		auto sr = createIfcProductDefinitionShape(representation);

		createIfcSlab(ownerHistory, sr);
	}

	static Ptr create()
	{
		return std::make_shared<TunnelGeneratorIfc4>();
	}

	void store()
	{
		char* fakeHeader = 

"ISO-10303-21;\n\
HEADER;\n\
/* NOTE a valid model view name has to be asserted, replacing 'notYetAssigned' ----------------- */\n\
FILE_DESCRIPTION(\n\
	( 'ViewDefinition [notYetAssigned]'\n\
	 ,'Comment [manual creation of example file]'\n\
	)\n\
	, '2;1');\n\
/* NOTE standard header information according to ISO 10303-21 ---------------------------------- */\n\
FILE_NAME(\n\
	'tunnel.ifc',\n\
	'2015-08-03T18:00:00',\n\
	('Julian Amann'),\n\
	('TUM CMS'),\n\
	'OpenInfraPlatform IFC Tunnel generator',\n\
	'OpenInfraPlatform IFC Tunnel generator',\n\
	'reference file created for the IFC Tunnel specification');\n\
/* NOTE schema name to be replaced with 'IFC4' after the final release  ------------------------ */\n\
FILE_SCHEMA(('IFC4'));\n\
ENDSEC;\n\n";

		model_->setFileHeader(fakeHeader);

		// writer
		char* filename = "MyTunnel.ifc";

		shared_ptr<IfcStepWriter> step_writer = shared_ptr<IfcStepWriter>(new IfcStepWriter());
		std::stringstream stream;
		stream << std::setprecision(9) << std::showpoint << std::fixed;
		step_writer->writeStream( stream, model_ );

		std::string content = stream.str();
		content = replace(content, "()", "$");

		std::ofstream textdatei(filename);
		textdatei << content.c_str();
		textdatei.close();
	}

private:
	shared_ptr<IfcUnitAssignment> createIfcUnitAssignment()
	{
		shared_ptr<IfcUnitAssignment> unitAssignment = std::make_shared<IfcUnitAssignment>(id++);
		model_->insertEntity(unitAssignment);

		shared_ptr<IfcSIUnit> lengthUnit = std::make_shared<IfcSIUnit>(id++);
		model_->insertEntity(lengthUnit);
		lengthUnit->m_UnitType = std::make_shared<IfcUnitEnum>(IfcUnitEnum::ENUM_LENGTHUNIT);
		lengthUnit->m_Name = std::make_shared<IfcSIUnitName>(IfcSIUnitName::ENUM_METRE);
		unitAssignment->m_Units.push_back(lengthUnit);

		shared_ptr<IfcSIUnit> areaUnit = std::make_shared<IfcSIUnit>(id++);
		model_->insertEntity(areaUnit);
		areaUnit->m_UnitType = std::make_shared<IfcUnitEnum>(IfcUnitEnum::ENUM_AREAUNIT);
		areaUnit->m_Name = std::make_shared<IfcSIUnitName>(IfcSIUnitName::ENUM_SQUARE_METRE);
		unitAssignment->m_Units.push_back(areaUnit);

		shared_ptr<IfcSIUnit> volumeUnit = std::make_shared<IfcSIUnit>(id++);
		model_->insertEntity(volumeUnit);
		volumeUnit->m_UnitType = std::make_shared<IfcUnitEnum>(IfcUnitEnum::ENUM_VOLUMEUNIT);
		volumeUnit->m_Name = std::make_shared<IfcSIUnitName>(IfcSIUnitName::ENUM_CUBIC_METRE);

		
		unitAssignment->m_Units.push_back(volumeUnit);

		return unitAssignment;
	}

	shared_ptr<IfcSlab> createIfcSlab(shared_ptr<IfcOwnerHistory> ownerHistory, shared_ptr<IfcProductRepresentation> representation)
	{
		shared_ptr<IfcSlab> slab = std::make_shared<IfcSlab>(id++);
		model_->insertEntity(slab);
		slab->m_PredefinedType = std::make_shared<IfcSlabTypeEnum>(IfcSlabTypeEnum::ENUM_ROOF);	
		slab->m_GlobalId = createGUID();
		slab->m_OwnerHistory = ownerHistory;
		slab->m_Name = std::make_shared<IfcLabel>("Tunnel");
		slab->m_Representation = representation;
		return slab;
	}

	shared_ptr<IfcBuilding> createIfcBuilding(shared_ptr<IfcOwnerHistory> ownerHistory,
		shared_ptr<IfcLocalPlacement> placemenet)
	{
		shared_ptr<IfcBuilding> building = std::make_shared<IfcBuilding>(id++);
		model_->insertEntity(building);
		building->m_GlobalId = createGUID();
		building->m_Name = std::make_shared<IfcLabel>("Tunnel Building");
		building->m_OwnerHistory = ownerHistory;
		building->m_ObjectPlacement = placemenet;
		building->m_CompositionType = std::make_shared<IfcElementCompositionEnum>(IfcElementCompositionEnum::ENUM_ELEMENT);
		return building;
	}

	shared_ptr<IfcOwnerHistory> createIfcOwnerHistory(
		shared_ptr<IfcPersonAndOrganization> personAndOrganization,
		shared_ptr<IfcApplication> application )
	{
		shared_ptr<IfcOwnerHistory> oh = std::make_shared<IfcOwnerHistory>(id++);
		model_->insertEntity(oh);
		oh->m_OwningUser = personAndOrganization;
		oh->m_OwningApplication = application;
		//oh->m_State = std::make_shared<IfcStateEnum>( IfcStateEnum::ENUM_READONLY );
		oh->m_ChangeAction = std::make_shared<IfcChangeActionEnum>( IfcChangeActionEnum::ENUM_NOCHANGE );
		oh->m_CreationDate = std::make_shared<IfcTimeStamp>(0);
		return oh;
	}

	shared_ptr<IfcPersonAndOrganization> createIfcPersonAndOrganization(shared_ptr<IfcPerson> person, shared_ptr<IfcOrganization> organization)
	{
		shared_ptr<IfcPersonAndOrganization> pao = std::make_shared<IfcPersonAndOrganization>(id++);
		model_->insertEntity(pao);
		pao->m_ThePerson = person;
		pao->m_TheOrganization = organization;
		return pao;
	}

	shared_ptr<IfcPerson> createIfcPerson()
	{
		shared_ptr<IfcPerson> person = std::make_shared<IfcPerson>(id++);
		model_->insertEntity(person);
		person->m_FamilyName = std::make_shared<IfcLabel>("Julian Amann");
		return person;
	}

	shared_ptr<IfcAxis2Placement3D> createIfcAxis2Placement3D(shared_ptr<IfcCartesianPoint> location)
	{
		shared_ptr<IfcAxis2Placement3D> ap = std::make_shared<IfcAxis2Placement3D>(id++);
		model_->insertEntity(ap);
		ap->m_Location = location;
		return ap;
	}

	shared_ptr<IfcLocalPlacement> createIfcLocalPlacement(shared_ptr<IfcAxis2Placement3D> axisPlacement)
	{
		shared_ptr<IfcLocalPlacement> lp = std::make_shared<IfcLocalPlacement>(id++);
		model_->insertEntity(lp);
		lp->m_RelativePlacement = axisPlacement;
		return lp;
	}

	shared_ptr<IfcOrganization> createIfcOrganization()
	{
		shared_ptr<IfcOrganization> organization = std::make_shared<IfcOrganization>(id++);
		model_->insertEntity(organization);
		//organization->m_Identification = std::make_shared<IfcIdentifier>("TUM");
		organization->m_Name = std::make_shared<IfcLabel>("TUM");
		//organization->m_Description = std::make_shared<IfcText>("TUM");
		return organization;
	}

	shared_ptr<IfcApplication> createIfcApplication(shared_ptr<IfcOrganization> applicationDeveloper)
	{
		shared_ptr<IfcApplication> application = std::make_shared<IfcApplication>(id++);
		model_->insertEntity(application);
		application->m_ApplicationDeveloper = applicationDeveloper;
		application->m_Version = std::make_shared<IfcLabel>("2014");
		application->m_ApplicationFullName = std::make_shared<IfcLabel>("BlueIfcTunnelGenerator");
		application->m_ApplicationIdentifier = std::make_shared<IfcIdentifier>("BlueIfcTunnelGenerator");
		return application;
	}

	shared_ptr<IfcProductDefinitionShape> createIfcProductDefinitionShape(std::vector<shared_ptr<IfcRepresentation>> representation)
	{
		shared_ptr<IfcProductDefinitionShape> productDefinitionShape = std::make_shared<IfcProductDefinitionShape>(id++);
		model_->insertEntity(productDefinitionShape);
		productDefinitionShape->m_Representations = representation;
		return productDefinitionShape;
	}

	shared_ptr<IfcRepresentationContext> createIfcRepresentationContext()
	{
		shared_ptr<IfcRepresentationContext> rc = std::make_shared<IfcRepresentationContext>(id++);
		model_->insertEntity(rc);
		return rc;
	}

	shared_ptr<IfcShapeRepresentation> createIfcShapeRepresentation(
		std::vector<shared_ptr<IfcRepresentationItem>> representationItems,
		shared_ptr<IfcRepresentationContext> context)
	{
		shared_ptr<IfcShapeRepresentation> shapeRepresentation = std::make_shared<IfcShapeRepresentation>(id++);
		model_->insertEntity(shapeRepresentation);
		shapeRepresentation->m_ContextOfItems = context;
		shapeRepresentation->m_Items = representationItems;
		shapeRepresentation->m_RepresentationIdentifier = std::make_shared<IfcLabel>("test");
		shapeRepresentation->m_RepresentationType = std::make_shared<IfcLabel>("Brep");
		return shapeRepresentation;
	}

	shared_ptr<IfcFacetedBrep> createIfcFacetedBrep(shared_ptr<IfcClosedShell> closedShell)
	{
		shared_ptr<IfcFacetedBrep> facetedBrep =  std::make_shared<IfcFacetedBrep>(id++);
		model_->insertEntity(facetedBrep);
		facetedBrep->m_Outer = closedShell;
		return facetedBrep;
	}

	shared_ptr<IfcClosedShell> createIfcClosedShell( std::vector<shared_ptr<IfcFace>> faces )
	{
		shared_ptr<IfcClosedShell> shell =  std::make_shared<IfcClosedShell>(id++);
		model_->insertEntity(shell);
		
		shell->m_CfsFaces = faces;

		return shell;
	}

	shared_ptr<IfcFace> createIfcFace(shared_ptr<IfcFaceOuterBound> outerBound)
	{
		shared_ptr<IfcFace> face =  std::make_shared<IfcFace>(id++);
		model_->insertEntity(face);
		face->m_Bounds.push_back(outerBound);
		return face;
	}

	shared_ptr<IfcFaceOuterBound> createIfcFaceOuterbound(shared_ptr<IfcPolyLoop> polyLoop)
	{
		shared_ptr<IfcFaceOuterBound> outerBound =  std::make_shared<IfcFaceOuterBound>(id++);
		model_->insertEntity(outerBound);
		outerBound->m_Bound = polyLoop;
		outerBound->m_Orientation = true;
		return outerBound;
	}

	shared_ptr<IfcPolyLoop> createIfcPolyLoop( std::vector<shared_ptr<IfcCartesianPoint>> points )
	{
		shared_ptr<IfcPolyLoop> polyLoop =  std::make_shared<IfcPolyLoop>(id++);
		polyLoop->m_Polygon = points;
		model_->insertEntity(polyLoop);
		return polyLoop;
	}

	shared_ptr<IfcCartesianPoint> createIfcCartesianPoint(
		const float x, 
		const float y, 
		const float z)
	{
		shared_ptr<IfcCartesianPoint> point =  std::make_shared<IfcCartesianPoint>(id++);
		model_->insertEntity(point);
		point->m_Coordinates.push_back ( std::make_shared<IfcLengthMeasure>( x ) );
		point->m_Coordinates.push_back ( std::make_shared<IfcLengthMeasure>( y ) );
		point->m_Coordinates.push_back ( std::make_shared<IfcLengthMeasure>( z ) );
		return point;
	}

private:
	int id;
	shared_ptr<Ifc4Model> model_;
};

int main()
{
	TunnelGeneratorIfc4::Ptr tunnel = TunnelGeneratorIfc4::create();
	tunnel->store();

	return 0;
}