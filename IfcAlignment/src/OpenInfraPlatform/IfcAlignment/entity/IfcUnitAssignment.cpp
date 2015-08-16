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
#include "include/IfcUnit.h"
#include "include/IfcUnitAssignment.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcUnitAssignment 
		IfcUnitAssignment::IfcUnitAssignment() { m_entity_enum = IFCUNITASSIGNMENT; }
		IfcUnitAssignment::IfcUnitAssignment( int id ) { m_id = id; m_entity_enum = IFCUNITASSIGNMENT; }
		IfcUnitAssignment::~IfcUnitAssignment() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcUnitAssignment::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcUnitAssignment> other = dynamic_pointer_cast<IfcUnitAssignment>(other_entity);
			if( !other) { return; }
			m_Units = other->m_Units;
		}
		void IfcUnitAssignment::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCUNITASSIGNMENT" << "(";
			writeTypeList( stream, m_Units, true );
			stream << ");";
		}
		void IfcUnitAssignment::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcUnitAssignment::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcUnitAssignment, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcUnitAssignment, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_Units, map );
		}
		void IfcUnitAssignment::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> )
		{
		}
		void IfcUnitAssignment::unlinkSelf()
		{
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
