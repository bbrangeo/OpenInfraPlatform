/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcMeasureWithUnit.h"
#include "include/IfcObjectDefinition.h"
#include "include/IfcObjectTypeEnum.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProcess.h"
#include "include/IfcProcessSelect.h"
#include "include/IfcRelAssignsToProcess.h"
#include "include/IfcText.h"
#include "include/IfcTypeProcess.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcRelAssignsToProcess 
		IfcRelAssignsToProcess::IfcRelAssignsToProcess() { m_entity_enum = IFCRELASSIGNSTOPROCESS; }
		IfcRelAssignsToProcess::IfcRelAssignsToProcess( int id ) { m_id = id; m_entity_enum = IFCRELASSIGNSTOPROCESS; }
		IfcRelAssignsToProcess::~IfcRelAssignsToProcess() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssignsToProcess::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcRelAssignsToProcess> other = dynamic_pointer_cast<IfcRelAssignsToProcess>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatedObjectsType = other->m_RelatedObjectsType;
			m_RelatingProcess = other->m_RelatingProcess;
			m_QuantityInProcess = other->m_QuantityInProcess;
		}
		void IfcRelAssignsToProcess::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSIGNSTOPROCESS" << "(";
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
			if( m_RelatingProcess ) { m_RelatingProcess->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_QuantityInProcess ) { stream << "#" << m_QuantityInProcess->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssignsToProcess::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssignsToProcess::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssignsToProcess, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcRelAssignsToProcess, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReferenceList( args[4], m_RelatedObjects, map );
			m_RelatedObjectsType = IfcObjectTypeEnum::readStepData( args[5] );
			m_RelatingProcess = IfcProcessSelect::readStepData( args[6], map );
			readEntityReference( args[7], m_QuantityInProcess, map );
		}
		void IfcRelAssignsToProcess::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcRelAssigns::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelAssignsToProcess> ptr_self = dynamic_pointer_cast<IfcRelAssignsToProcess>( ptr_self_entity );
			if( !ptr_self ) { throw IfcAlignmentP6Exception( "IfcRelAssignsToProcess::setInverseCounterparts: type mismatch" ); }
			shared_ptr<IfcProcess>  RelatingProcess_IfcProcess = dynamic_pointer_cast<IfcProcess>( m_RelatingProcess );
			if( RelatingProcess_IfcProcess )
			{
				RelatingProcess_IfcProcess->m_OperatesOn_inverse.push_back( ptr_self );
			}
			shared_ptr<IfcTypeProcess>  RelatingProcess_IfcTypeProcess = dynamic_pointer_cast<IfcTypeProcess>( m_RelatingProcess );
			if( RelatingProcess_IfcTypeProcess )
			{
				RelatingProcess_IfcTypeProcess->m_OperatesOn_inverse.push_back( ptr_self );
			}
		}
		void IfcRelAssignsToProcess::unlinkSelf()
		{
			IfcRelAssigns::unlinkSelf();
			shared_ptr<IfcProcess>  RelatingProcess_IfcProcess = dynamic_pointer_cast<IfcProcess>( m_RelatingProcess );
			if( RelatingProcess_IfcProcess )
			{
				std::vector<weak_ptr<IfcRelAssignsToProcess> >& OperatesOn_inverse = RelatingProcess_IfcProcess->m_OperatesOn_inverse;
				std::vector<weak_ptr<IfcRelAssignsToProcess> >::iterator it_OperatesOn_inverse;
				for( it_OperatesOn_inverse = OperatesOn_inverse.begin(); it_OperatesOn_inverse != OperatesOn_inverse.end(); ++it_OperatesOn_inverse)
				{
					shared_ptr<IfcRelAssignsToProcess> self_candidate( *it_OperatesOn_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						OperatesOn_inverse.erase( it_OperatesOn_inverse );
						break;
					}
				}
			}
			shared_ptr<IfcTypeProcess>  RelatingProcess_IfcTypeProcess = dynamic_pointer_cast<IfcTypeProcess>( m_RelatingProcess );
			if( RelatingProcess_IfcTypeProcess )
			{
				std::vector<weak_ptr<IfcRelAssignsToProcess> >& OperatesOn_inverse = RelatingProcess_IfcTypeProcess->m_OperatesOn_inverse;
				std::vector<weak_ptr<IfcRelAssignsToProcess> >::iterator it_OperatesOn_inverse;
				for( it_OperatesOn_inverse = OperatesOn_inverse.begin(); it_OperatesOn_inverse != OperatesOn_inverse.end(); ++it_OperatesOn_inverse)
				{
					shared_ptr<IfcRelAssignsToProcess> self_candidate( *it_OperatesOn_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						OperatesOn_inverse.erase( it_OperatesOn_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
