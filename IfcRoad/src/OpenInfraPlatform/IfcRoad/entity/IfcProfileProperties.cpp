/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcProfileDef.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProperty.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcProfileProperties 
		IfcProfileProperties::IfcProfileProperties() { m_entity_enum = IFCPROFILEPROPERTIES; }
		IfcProfileProperties::IfcProfileProperties( int id ) { m_id = id; m_entity_enum = IFCPROFILEPROPERTIES; }
		IfcProfileProperties::~IfcProfileProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcProfileProperties::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcProfileProperties> other = dynamic_pointer_cast<IfcProfileProperties>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Properties = other->m_Properties;
			m_ProfileDefinition = other->m_ProfileDefinition;
		}
		void IfcProfileProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROFILEPROPERTIES" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Properties );
			stream << ",";
			if( m_ProfileDefinition ) { stream << "#" << m_ProfileDefinition->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcProfileProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcProfileProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcProfileProperties, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcProfileProperties, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcIdentifier::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReferenceList( args[2], m_Properties, map );
			readEntityReference( args[3], m_ProfileDefinition, map );
		}
		void IfcProfileProperties::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcExtendedProperties::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcProfileProperties> ptr_self = dynamic_pointer_cast<IfcProfileProperties>( ptr_self_entity );
			if( !ptr_self ) { throw IfcRoadException( "IfcProfileProperties::setInverseCounterparts: type mismatch" ); }
			if( m_ProfileDefinition )
			{
				m_ProfileDefinition->m_HasProperties_inverse.push_back( ptr_self );
			}
		}
		void IfcProfileProperties::unlinkSelf()
		{
			IfcExtendedProperties::unlinkSelf();
			if( m_ProfileDefinition )
			{
				std::vector<weak_ptr<IfcProfileProperties> >& HasProperties_inverse = m_ProfileDefinition->m_HasProperties_inverse;
				std::vector<weak_ptr<IfcProfileProperties> >::iterator it_HasProperties_inverse;
				for( it_HasProperties_inverse = HasProperties_inverse.begin(); it_HasProperties_inverse != HasProperties_inverse.end(); ++it_HasProperties_inverse)
				{
					shared_ptr<IfcProfileProperties> self_candidate( *it_HasProperties_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasProperties_inverse.erase( it_HasProperties_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
