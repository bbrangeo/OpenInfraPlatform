/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcBooleanOperator.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
