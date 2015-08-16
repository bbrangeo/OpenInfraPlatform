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
#include "include/IfcLabel.h"
#include "include/IfcOrientationSelect.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcRelAssociatesProfileProperties.h"
#include "include/IfcRoot.h"
#include "include/IfcShapeAspect.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRelAssociatesProfileProperties 
		IfcRelAssociatesProfileProperties::IfcRelAssociatesProfileProperties() { m_entity_enum = IFCRELASSOCIATESPROFILEPROPERTIES; }
		IfcRelAssociatesProfileProperties::IfcRelAssociatesProfileProperties( int id ) { m_id = id; m_entity_enum = IFCRELASSOCIATESPROFILEPROPERTIES; }
		IfcRelAssociatesProfileProperties::~IfcRelAssociatesProfileProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssociatesProfileProperties::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRelAssociatesProfileProperties> other = dynamic_pointer_cast<IfcRelAssociatesProfileProperties>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatingProfileProperties = other->m_RelatingProfileProperties;
			m_ProfileSectionLocation = other->m_ProfileSectionLocation;
			m_ProfileOrientation = other->m_ProfileOrientation;
		}
		void IfcRelAssociatesProfileProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSOCIATESPROFILEPROPERTIES" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedObjects );
			stream << ",";
			if( m_RelatingProfileProperties ) { stream << "#" << m_RelatingProfileProperties->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileSectionLocation ) { stream << "#" << m_ProfileSectionLocation->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileOrientation ) { m_ProfileOrientation->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssociatesProfileProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssociatesProfileProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssociatesProfileProperties, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcRelAssociatesProfileProperties, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReferenceList( args[4], m_RelatedObjects, map );
			readEntityReference( args[5], m_RelatingProfileProperties, map );
			readEntityReference( args[6], m_ProfileSectionLocation, map );
			m_ProfileOrientation = IfcOrientationSelect::readStepData( args[7], map );
		}
		void IfcRelAssociatesProfileProperties::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRelAssociates::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRelAssociatesProfileProperties::unlinkSelf()
		{
			IfcRelAssociates::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
