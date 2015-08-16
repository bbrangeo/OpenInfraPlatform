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
#include "include/IfcObjectDefinition.h"
#include "include/IfcObjectTypeEnum.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProduct.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRelAssignsToProduct 
		IfcRelAssignsToProduct::IfcRelAssignsToProduct() { m_entity_enum = IFCRELASSIGNSTOPRODUCT; }
		IfcRelAssignsToProduct::IfcRelAssignsToProduct( int id ) { m_id = id; m_entity_enum = IFCRELASSIGNSTOPRODUCT; }
		IfcRelAssignsToProduct::~IfcRelAssignsToProduct() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssignsToProduct::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRelAssignsToProduct> other = dynamic_pointer_cast<IfcRelAssignsToProduct>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatedObjectsType = other->m_RelatedObjectsType;
			m_RelatingProduct = other->m_RelatingProduct;
		}
		void IfcRelAssignsToProduct::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSIGNSTOPRODUCT" << "(";
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
			if( m_RelatedObjectsType ) { m_RelatedObjectsType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingProduct ) { stream << "#" << m_RelatingProduct->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssignsToProduct::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssignsToProduct::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssignsToProduct, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcRelAssignsToProduct, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReferenceList( args[4], m_RelatedObjects, map );
			m_RelatedObjectsType = IfcObjectTypeEnum::readStepData( args[5] );
			readEntityReference( args[6], m_RelatingProduct, map );
		}
		void IfcRelAssignsToProduct::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRelAssigns::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelAssignsToProduct> ptr_self = dynamic_pointer_cast<IfcRelAssignsToProduct>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcRelAssignsToProduct::setInverseCounterparts: type mismatch" ); }
			if( m_RelatingProduct )
			{
				m_RelatingProduct->m_ReferencedBy_inverse.push_back( ptr_self );
			}
		}
		void IfcRelAssignsToProduct::unlinkSelf()
		{
			IfcRelAssigns::unlinkSelf();
			if( m_RelatingProduct )
			{
				std::vector<weak_ptr<IfcRelAssignsToProduct> >& ReferencedBy_inverse = m_RelatingProduct->m_ReferencedBy_inverse;
				std::vector<weak_ptr<IfcRelAssignsToProduct> >::iterator it_ReferencedBy_inverse;
				for( it_ReferencedBy_inverse = ReferencedBy_inverse.begin(); it_ReferencedBy_inverse != ReferencedBy_inverse.end(); ++it_ReferencedBy_inverse)
				{
					shared_ptr<IfcRelAssignsToProduct> self_candidate( *it_ReferencedBy_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ReferencedBy_inverse.erase( it_ReferencedBy_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
