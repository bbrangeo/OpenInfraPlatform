/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcMaterialDefinition.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcProperty.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcMaterialProperties 
		IfcMaterialProperties::IfcMaterialProperties() { m_entity_enum = IFCMATERIALPROPERTIES; }
		IfcMaterialProperties::IfcMaterialProperties( int id ) { m_id = id; m_entity_enum = IFCMATERIALPROPERTIES; }
		IfcMaterialProperties::~IfcMaterialProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialProperties::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcMaterialProperties> other = dynamic_pointer_cast<IfcMaterialProperties>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Properties = other->m_Properties;
			m_Material = other->m_Material;
		}
		void IfcMaterialProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALPROPERTIES" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Properties );
			stream << ",";
			if( m_Material ) { stream << "#" << m_Material->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialProperties, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcMaterialProperties, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcIdentifier::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReferenceList( args[2], m_Properties, map );
			readEntityReference( args[3], m_Material, map );
		}
		void IfcMaterialProperties::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcExtendedProperties::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcMaterialProperties> ptr_self = dynamic_pointer_cast<IfcMaterialProperties>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcMaterialProperties::setInverseCounterparts: type mismatch" ); }
			if( m_Material )
			{
				m_Material->m_HasProperties_inverse.push_back( ptr_self );
			}
		}
		void IfcMaterialProperties::unlinkSelf()
		{
			IfcExtendedProperties::unlinkSelf();
			if( m_Material )
			{
				std::vector<weak_ptr<IfcMaterialProperties> >& HasProperties_inverse = m_Material->m_HasProperties_inverse;
				std::vector<weak_ptr<IfcMaterialProperties> >::iterator it_HasProperties_inverse;
				for( it_HasProperties_inverse = HasProperties_inverse.begin(); it_HasProperties_inverse != HasProperties_inverse.end(); ++it_HasProperties_inverse)
				{
					shared_ptr<IfcMaterialProperties> self_candidate( *it_HasProperties_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasProperties_inverse.erase( it_HasProperties_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
