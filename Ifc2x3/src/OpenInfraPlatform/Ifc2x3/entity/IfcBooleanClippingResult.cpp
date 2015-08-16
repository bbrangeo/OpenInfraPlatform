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
#include "include/IfcBooleanClippingResult.h"
#include "include/IfcBooleanOperand.h"
#include "include/IfcBooleanOperator.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcBooleanClippingResult 
		IfcBooleanClippingResult::IfcBooleanClippingResult() { m_entity_enum = IFCBOOLEANCLIPPINGRESULT; }
		IfcBooleanClippingResult::IfcBooleanClippingResult( int id ) { m_id = id; m_entity_enum = IFCBOOLEANCLIPPINGRESULT; }
		IfcBooleanClippingResult::~IfcBooleanClippingResult() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBooleanClippingResult::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcBooleanClippingResult> other = dynamic_pointer_cast<IfcBooleanClippingResult>(other_entity);
			if( !other) { return; }
			m_Operator = other->m_Operator;
			m_FirstOperand = other->m_FirstOperand;
			m_SecondOperand = other->m_SecondOperand;
		}
		void IfcBooleanClippingResult::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOOLEANCLIPPINGRESULT" << "(";
			if( m_Operator ) { m_Operator->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FirstOperand ) { m_FirstOperand->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_SecondOperand ) { m_SecondOperand->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBooleanClippingResult::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBooleanClippingResult::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBooleanClippingResult, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcBooleanClippingResult, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Operator = IfcBooleanOperator::readStepData( args[0] );
			m_FirstOperand = IfcBooleanOperand::readStepData( args[1], map );
			m_SecondOperand = IfcBooleanOperand::readStepData( args[2], map );
		}
		void IfcBooleanClippingResult::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcBooleanResult::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBooleanClippingResult::unlinkSelf()
		{
			IfcBooleanResult::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
