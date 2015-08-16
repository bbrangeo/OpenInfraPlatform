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
#include "include/IfcOwnerHistory.h"
#include "include/IfcProcedure.h"
#include "include/IfcProcedureTypeEnum.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProcess.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcRelDefines.h"
#include "include/IfcRelSequence.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcProcedure 
		IfcProcedure::IfcProcedure() { m_entity_enum = IFCPROCEDURE; }
		IfcProcedure::IfcProcedure( int id ) { m_id = id; m_entity_enum = IFCPROCEDURE; }
		IfcProcedure::~IfcProcedure() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcProcedure::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcProcedure> other = dynamic_pointer_cast<IfcProcedure>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ProcedureID = other->m_ProcedureID;
			m_ProcedureType = other->m_ProcedureType;
			m_UserDefinedProcedureType = other->m_UserDefinedProcedureType;
		}
		void IfcProcedure::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROCEDURE" << "(";
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
			if( m_ProcedureID ) { m_ProcedureID->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProcedureType ) { m_ProcedureType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedProcedureType ) { m_UserDefinedProcedureType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcProcedure::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcProcedure::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcProcedure, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcProcedure, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_ProcedureID = IfcIdentifier::readStepData( args[5] );
			m_ProcedureType = IfcProcedureTypeEnum::readStepData( args[6] );
			m_UserDefinedProcedureType = IfcLabel::readStepData( args[7] );
		}
		void IfcProcedure::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcProcess::setInverseCounterparts( ptr_self_entity );
		}
		void IfcProcedure::unlinkSelf()
		{
			IfcProcess::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
