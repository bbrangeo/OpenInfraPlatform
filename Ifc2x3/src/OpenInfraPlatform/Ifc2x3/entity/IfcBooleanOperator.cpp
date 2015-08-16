/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/Ifc2x3Exception.h"
#include "include/IfcBooleanOperator.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcBooleanOperator 
		IfcBooleanOperator::IfcBooleanOperator() {}
		IfcBooleanOperator::~IfcBooleanOperator() {}
		void IfcBooleanOperator::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBOOLEANOPERATOR("; }
			if( m_enum == ENUM_UNION )
			{
				stream << ".UNION.";
			}
			else if( m_enum == ENUM_INTERSECTION )
			{
				stream << ".INTERSECTION.";
			}
			else if( m_enum == ENUM_DIFFERENCE )
			{
				stream << ".DIFFERENCE.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcBooleanOperator> IfcBooleanOperator::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBooleanOperator>(); }
			shared_ptr<IfcBooleanOperator> type_object( new IfcBooleanOperator() );
			if( _stricmp( arg.c_str(), ".UNION." ) == 0 )
			{
				type_object->m_enum = IfcBooleanOperator::ENUM_UNION;
			}
			else if( _stricmp( arg.c_str(), ".INTERSECTION." ) == 0 )
			{
				type_object->m_enum = IfcBooleanOperator::ENUM_INTERSECTION;
			}
			else if( _stricmp( arg.c_str(), ".DIFFERENCE." ) == 0 )
			{
				type_object->m_enum = IfcBooleanOperator::ENUM_DIFFERENCE;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
