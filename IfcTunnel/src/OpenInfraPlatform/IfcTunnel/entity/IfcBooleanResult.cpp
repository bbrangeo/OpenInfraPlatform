/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcBooleanOperand.h"
#include "include/IfcBooleanOperator.h"
#include "include/IfcBooleanResult.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcBooleanResult 
		IfcBooleanResult::IfcBooleanResult() { m_entity_enum = IFCBOOLEANRESULT; }
		IfcBooleanResult::IfcBooleanResult( int id ) { m_id = id; m_entity_enum = IFCBOOLEANRESULT; }
		IfcBooleanResult::~IfcBooleanResult() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBooleanResult::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcBooleanResult> other = dynamic_pointer_cast<IfcBooleanResult>(other_entity);
			if( !other) { return; }
			m_Operator = other->m_Operator;
			m_FirstOperand = other->m_FirstOperand;
			m_SecondOperand = other->m_SecondOperand;
		}
		void IfcBooleanResult::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOOLEANRESULT" << "(";
			if( m_Operator ) { m_Operator->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FirstOperand ) { m_FirstOperand->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_SecondOperand ) { m_SecondOperand->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBooleanResult::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBooleanResult::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBooleanResult, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcBooleanResult, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Operator = IfcBooleanOperator::readStepData( args[0] );
			m_FirstOperand = IfcBooleanOperand::readStepData( args[1], map );
			m_SecondOperand = IfcBooleanOperand::readStepData( args[2], map );
		}
		void IfcBooleanResult::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBooleanResult::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
