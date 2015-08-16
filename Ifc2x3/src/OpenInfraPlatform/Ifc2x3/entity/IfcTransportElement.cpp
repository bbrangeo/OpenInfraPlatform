/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcCountMeasure.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcMassMeasure.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelConnectsElements.h"
#include "include/IfcRelConnectsPortToElement.h"
#include "include/IfcRelConnectsStructuralElement.h"
#include "include/IfcRelConnectsWithRealizingElements.h"
#include "include/IfcRelContainedInSpatialStructure.h"
#include "include/IfcRelCoversBldgElements.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcRelDefines.h"
#include "include/IfcRelFillsElement.h"
#include "include/IfcRelProjectsElement.h"
#include "include/IfcRelReferencedInSpatialStructure.h"
#include "include/IfcRelSpaceBoundary.h"
#include "include/IfcRelVoidsElement.h"
#include "include/IfcText.h"
#include "include/IfcTransportElement.h"
#include "include/IfcTransportElementTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcTransportElement 
		IfcTransportElement::IfcTransportElement() { m_entity_enum = IFCTRANSPORTELEMENT; }
		IfcTransportElement::IfcTransportElement( int id ) { m_id = id; m_entity_enum = IFCTRANSPORTELEMENT; }
		IfcTransportElement::~IfcTransportElement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTransportElement::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcTransportElement> other = dynamic_pointer_cast<IfcTransportElement>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ObjectPlacement = other->m_ObjectPlacement;
			m_Representation = other->m_Representation;
			m_Tag = other->m_Tag;
			m_OperationType = other->m_OperationType;
			m_CapacityByWeight = other->m_CapacityByWeight;
			m_CapacityByNumber = other->m_CapacityByNumber;
		}
		void IfcTransportElement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTRANSPORTELEMENT" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Representation ) { stream << "#" << m_Representation->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Tag ) { m_Tag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OperationType ) { m_OperationType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CapacityByWeight ) { m_CapacityByWeight->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CapacityByNumber ) { m_CapacityByNumber->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTransportElement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTransportElement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<11 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTransportElement, expecting 11, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>11 ){ std::cout << "Wrong parameter count for entity IfcTransportElement, expecting 11, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			readEntityReference( args[5], m_ObjectPlacement, map );
			readEntityReference( args[6], m_Representation, map );
			m_Tag = IfcIdentifier::readStepData( args[7] );
			m_OperationType = IfcTransportElementTypeEnum::readStepData( args[8] );
			m_CapacityByWeight = IfcMassMeasure::readStepData( args[9] );
			m_CapacityByNumber = IfcCountMeasure::readStepData( args[10] );
		}
		void IfcTransportElement::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcElement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTransportElement::unlinkSelf()
		{
			IfcElement::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
