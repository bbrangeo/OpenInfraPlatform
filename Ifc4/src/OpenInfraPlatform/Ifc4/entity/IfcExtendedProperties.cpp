/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcExtendedProperties.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcProperty.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcExtendedProperties 
		IfcExtendedProperties::IfcExtendedProperties() { m_entity_enum = IFCEXTENDEDPROPERTIES; }
		IfcExtendedProperties::IfcExtendedProperties( int id ) { m_id = id; m_entity_enum = IFCEXTENDEDPROPERTIES; }
		IfcExtendedProperties::~IfcExtendedProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcExtendedProperties::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcExtendedProperties> other = dynamic_pointer_cast<IfcExtendedProperties>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Properties = other->m_Properties;
		}
		void IfcExtendedProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEXTENDEDPROPERTIES" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Properties );
			stream << ");";
		}
		void IfcExtendedProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcExtendedProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcExtendedProperties, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcExtendedProperties, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcIdentifier::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReferenceList( args[2], m_Properties, map );
		}
		void IfcExtendedProperties::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPropertyAbstraction::setInverseCounterparts( ptr_self_entity );
		}
		void IfcExtendedProperties::unlinkSelf()
		{
			IfcPropertyAbstraction::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
