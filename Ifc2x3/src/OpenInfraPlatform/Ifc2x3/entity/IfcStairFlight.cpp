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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPositiveLengthMeasure.h"
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
#include "include/IfcStairFlight.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcStairFlight 
		IfcStairFlight::IfcStairFlight() { m_entity_enum = IFCSTAIRFLIGHT; }
		IfcStairFlight::IfcStairFlight( int id ) { m_id = id; m_entity_enum = IFCSTAIRFLIGHT; }
		IfcStairFlight::~IfcStairFlight() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStairFlight::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcStairFlight> other = dynamic_pointer_cast<IfcStairFlight>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ObjectPlacement = other->m_ObjectPlacement;
			m_Representation = other->m_Representation;
			m_Tag = other->m_Tag;
			m_NumberOfRiser = other->m_NumberOfRiser;
			m_NumberOfTreads = other->m_NumberOfTreads;
			m_RiserHeight = other->m_RiserHeight;
			m_TreadLength = other->m_TreadLength;
		}
		void IfcStairFlight::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTAIRFLIGHT" << "(";
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
			if( m_NumberOfRiser == m_NumberOfRiser ){ stream << m_NumberOfRiser; }
			else { stream << "$"; }
			stream << ",";
			if( m_NumberOfTreads == m_NumberOfTreads ){ stream << m_NumberOfTreads; }
			else { stream << "$"; }
			stream << ",";
			if( m_RiserHeight ) { m_RiserHeight->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TreadLength ) { m_TreadLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStairFlight::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStairFlight::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStairFlight, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcStairFlight, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			readEntityReference( args[5], m_ObjectPlacement, map );
			readEntityReference( args[6], m_Representation, map );
			m_Tag = IfcIdentifier::readStepData( args[7] );
			readIntValue( args[8], m_NumberOfRiser );
			readIntValue( args[9], m_NumberOfTreads );
			m_RiserHeight = IfcPositiveLengthMeasure::readStepData( args[10] );
			m_TreadLength = IfcPositiveLengthMeasure::readStepData( args[11] );
		}
		void IfcStairFlight::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcBuildingElement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStairFlight::unlinkSelf()
		{
			IfcBuildingElement::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
