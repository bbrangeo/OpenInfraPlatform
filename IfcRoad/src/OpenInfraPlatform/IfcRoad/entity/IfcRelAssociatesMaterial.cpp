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
#include "include/IfcDefinitionSelect.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcMaterialDefinition.h"
#include "include/IfcMaterialSelect.h"
#include "include/IfcMaterialUsageDefinition.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssociatesMaterial.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcRelAssociatesMaterial 
		IfcRelAssociatesMaterial::IfcRelAssociatesMaterial() { m_entity_enum = IFCRELASSOCIATESMATERIAL; }
		IfcRelAssociatesMaterial::IfcRelAssociatesMaterial( int id ) { m_id = id; m_entity_enum = IFCRELASSOCIATESMATERIAL; }
		IfcRelAssociatesMaterial::~IfcRelAssociatesMaterial() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssociatesMaterial::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcRelAssociatesMaterial> other = dynamic_pointer_cast<IfcRelAssociatesMaterial>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatingMaterial = other->m_RelatingMaterial;
		}
		void IfcRelAssociatesMaterial::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSOCIATESMATERIAL" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_RelatedObjects, true );
			stream << ",";
			if( m_RelatingMaterial ) { m_RelatingMaterial->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssociatesMaterial::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssociatesMaterial::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssociatesMaterial, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelAssociatesMaterial, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readSelectList( args[4], m_RelatedObjects, map );
			m_RelatingMaterial = IfcMaterialSelect::readStepData( args[5], map );
		}
		void IfcRelAssociatesMaterial::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcRelAssociates::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelAssociatesMaterial> ptr_self = dynamic_pointer_cast<IfcRelAssociatesMaterial>( ptr_self_entity );
			if( !ptr_self ) { throw IfcRoadException( "IfcRelAssociatesMaterial::setInverseCounterparts: type mismatch" ); }
			shared_ptr<IfcMaterialDefinition>  RelatingMaterial_IfcMaterialDefinition = dynamic_pointer_cast<IfcMaterialDefinition>( m_RelatingMaterial );
			if( RelatingMaterial_IfcMaterialDefinition )
			{
				RelatingMaterial_IfcMaterialDefinition->m_AssociatedTo_inverse.push_back( ptr_self );
			}
			shared_ptr<IfcMaterialUsageDefinition>  RelatingMaterial_IfcMaterialUsageDefinition = dynamic_pointer_cast<IfcMaterialUsageDefinition>( m_RelatingMaterial );
			if( RelatingMaterial_IfcMaterialUsageDefinition )
			{
				RelatingMaterial_IfcMaterialUsageDefinition->m_AssociatedTo_inverse.push_back( ptr_self );
			}
		}
		void IfcRelAssociatesMaterial::unlinkSelf()
		{
			IfcRelAssociates::unlinkSelf();
			shared_ptr<IfcMaterialDefinition>  RelatingMaterial_IfcMaterialDefinition = dynamic_pointer_cast<IfcMaterialDefinition>( m_RelatingMaterial );
			if( RelatingMaterial_IfcMaterialDefinition )
			{
				std::vector<weak_ptr<IfcRelAssociatesMaterial> >& AssociatedTo_inverse = RelatingMaterial_IfcMaterialDefinition->m_AssociatedTo_inverse;
				std::vector<weak_ptr<IfcRelAssociatesMaterial> >::iterator it_AssociatedTo_inverse;
				for( it_AssociatedTo_inverse = AssociatedTo_inverse.begin(); it_AssociatedTo_inverse != AssociatedTo_inverse.end(); ++it_AssociatedTo_inverse)
				{
					shared_ptr<IfcRelAssociatesMaterial> self_candidate( *it_AssociatedTo_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						AssociatedTo_inverse.erase( it_AssociatedTo_inverse );
						break;
					}
				}
			}
			shared_ptr<IfcMaterialUsageDefinition>  RelatingMaterial_IfcMaterialUsageDefinition = dynamic_pointer_cast<IfcMaterialUsageDefinition>( m_RelatingMaterial );
			if( RelatingMaterial_IfcMaterialUsageDefinition )
			{
				std::vector<weak_ptr<IfcRelAssociatesMaterial> >& AssociatedTo_inverse = RelatingMaterial_IfcMaterialUsageDefinition->m_AssociatedTo_inverse;
				std::vector<weak_ptr<IfcRelAssociatesMaterial> >::iterator it_AssociatedTo_inverse;
				for( it_AssociatedTo_inverse = AssociatedTo_inverse.begin(); it_AssociatedTo_inverse != AssociatedTo_inverse.end(); ++it_AssociatedTo_inverse)
				{
					shared_ptr<IfcRelAssociatesMaterial> self_candidate( *it_AssociatedTo_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						AssociatedTo_inverse.erase( it_AssociatedTo_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
