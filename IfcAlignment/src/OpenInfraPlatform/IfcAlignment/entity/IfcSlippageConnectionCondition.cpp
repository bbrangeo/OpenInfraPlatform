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
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcSlippageConnectionCondition.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcSlippageConnectionCondition 
		IfcSlippageConnectionCondition::IfcSlippageConnectionCondition() { m_entity_enum = IFCSLIPPAGECONNECTIONCONDITION; }
		IfcSlippageConnectionCondition::IfcSlippageConnectionCondition( int id ) { m_id = id; m_entity_enum = IFCSLIPPAGECONNECTIONCONDITION; }
		IfcSlippageConnectionCondition::~IfcSlippageConnectionCondition() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSlippageConnectionCondition::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcSlippageConnectionCondition> other = dynamic_pointer_cast<IfcSlippageConnectionCondition>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_SlippageX = other->m_SlippageX;
			m_SlippageY = other->m_SlippageY;
			m_SlippageZ = other->m_SlippageZ;
		}
		void IfcSlippageConnectionCondition::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSLIPPAGECONNECTIONCONDITION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SlippageX ) { m_SlippageX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SlippageY ) { m_SlippageY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SlippageZ ) { m_SlippageZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSlippageConnectionCondition::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSlippageConnectionCondition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSlippageConnectionCondition, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcSlippageConnectionCondition, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_SlippageX = IfcLengthMeasure::readStepData( args[1] );
			m_SlippageY = IfcLengthMeasure::readStepData( args[2] );
			m_SlippageZ = IfcLengthMeasure::readStepData( args[3] );
		}
		void IfcSlippageConnectionCondition::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcStructuralConnectionCondition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSlippageConnectionCondition::unlinkSelf()
		{
			IfcStructuralConnectionCondition::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
