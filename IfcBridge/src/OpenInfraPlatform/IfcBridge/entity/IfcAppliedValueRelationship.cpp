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
#include "include/IfcAppliedValue.h"
#include "include/IfcAppliedValueRelationship.h"
#include "include/IfcArithmeticOperatorEnum.h"
#include "include/IfcLabel.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcAppliedValueRelationship 
		IfcAppliedValueRelationship::IfcAppliedValueRelationship() { m_entity_enum = IFCAPPLIEDVALUERELATIONSHIP; }
		IfcAppliedValueRelationship::IfcAppliedValueRelationship( int id ) { m_id = id; m_entity_enum = IFCAPPLIEDVALUERELATIONSHIP; }
		IfcAppliedValueRelationship::~IfcAppliedValueRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAppliedValueRelationship::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcAppliedValueRelationship> other = dynamic_pointer_cast<IfcAppliedValueRelationship>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ComponentOfTotal = other->m_ComponentOfTotal;
			m_Components = other->m_Components;
			m_ArithmeticOperator = other->m_ArithmeticOperator;
		}
		void IfcAppliedValueRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAPPLIEDVALUERELATIONSHIP" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ComponentOfTotal ) { stream << "#" << m_ComponentOfTotal->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Components );
			stream << ",";
			if( m_ArithmeticOperator ) { m_ArithmeticOperator->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAppliedValueRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAppliedValueRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAppliedValueRelationship, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcAppliedValueRelationship, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_ComponentOfTotal, map );
			readEntityReferenceList( args[3], m_Components, map );
			m_ArithmeticOperator = IfcArithmeticOperatorEnum::readStepData( args[4] );
		}
		void IfcAppliedValueRelationship::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcResourceLevelRelationship::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcAppliedValueRelationship> ptr_self = dynamic_pointer_cast<IfcAppliedValueRelationship>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcAppliedValueRelationship::setInverseCounterparts: type mismatch" ); }
			if( m_ComponentOfTotal )
			{
				m_ComponentOfTotal->m_ValueOfComponents_inverse.push_back( ptr_self );
			}
			for( int i=0; i<m_Components.size(); ++i )
			{
				if( m_Components[i] )
				{
					m_Components[i]->m_IsComponentIn_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcAppliedValueRelationship::unlinkSelf()
		{
			IfcResourceLevelRelationship::unlinkSelf();
			if( m_ComponentOfTotal )
			{
				std::vector<weak_ptr<IfcAppliedValueRelationship> >& ValueOfComponents_inverse = m_ComponentOfTotal->m_ValueOfComponents_inverse;
				std::vector<weak_ptr<IfcAppliedValueRelationship> >::iterator it_ValueOfComponents_inverse;
				for( it_ValueOfComponents_inverse = ValueOfComponents_inverse.begin(); it_ValueOfComponents_inverse != ValueOfComponents_inverse.end(); ++it_ValueOfComponents_inverse)
				{
					shared_ptr<IfcAppliedValueRelationship> self_candidate( *it_ValueOfComponents_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ValueOfComponents_inverse.erase( it_ValueOfComponents_inverse );
						break;
					}
				}
			}
			for( int i=0; i<m_Components.size(); ++i )
			{
				if( m_Components[i] )
				{
					std::vector<weak_ptr<IfcAppliedValueRelationship> >& IsComponentIn_inverse = m_Components[i]->m_IsComponentIn_inverse;
					std::vector<weak_ptr<IfcAppliedValueRelationship> >::iterator it_IsComponentIn_inverse;
					for( it_IsComponentIn_inverse = IsComponentIn_inverse.begin(); it_IsComponentIn_inverse != IsComponentIn_inverse.end(); ++it_IsComponentIn_inverse)
					{
						shared_ptr<IfcAppliedValueRelationship> self_candidate( *it_IsComponentIn_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							IsComponentIn_inverse.erase( it_IsComponentIn_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
