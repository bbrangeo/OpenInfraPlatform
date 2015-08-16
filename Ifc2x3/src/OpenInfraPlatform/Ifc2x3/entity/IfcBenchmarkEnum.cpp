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
#include "include/IfcBenchmarkEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcBenchmarkEnum 
		IfcBenchmarkEnum::IfcBenchmarkEnum() {}
		IfcBenchmarkEnum::~IfcBenchmarkEnum() {}
		void IfcBenchmarkEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBENCHMARKENUM("; }
			if( m_enum == ENUM_GREATERTHAN )
			{
				stream << ".GREATERTHAN.";
			}
			else if( m_enum == ENUM_GREATERTHANOREQUALTO )
			{
				stream << ".GREATERTHANOREQUALTO.";
			}
			else if( m_enum == ENUM_LESSTHAN )
			{
				stream << ".LESSTHAN.";
			}
			else if( m_enum == ENUM_LESSTHANOREQUALTO )
			{
				stream << ".LESSTHANOREQUALTO.";
			}
			else if( m_enum == ENUM_EQUALTO )
			{
				stream << ".EQUALTO.";
			}
			else if( m_enum == ENUM_NOTEQUALTO )
			{
				stream << ".NOTEQUALTO.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcBenchmarkEnum> IfcBenchmarkEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBenchmarkEnum>(); }
			shared_ptr<IfcBenchmarkEnum> type_object( new IfcBenchmarkEnum() );
			if( _stricmp( arg.c_str(), ".GREATERTHAN." ) == 0 )
			{
				type_object->m_enum = IfcBenchmarkEnum::ENUM_GREATERTHAN;
			}
			else if( _stricmp( arg.c_str(), ".GREATERTHANOREQUALTO." ) == 0 )
			{
				type_object->m_enum = IfcBenchmarkEnum::ENUM_GREATERTHANOREQUALTO;
			}
			else if( _stricmp( arg.c_str(), ".LESSTHAN." ) == 0 )
			{
				type_object->m_enum = IfcBenchmarkEnum::ENUM_LESSTHAN;
			}
			else if( _stricmp( arg.c_str(), ".LESSTHANOREQUALTO." ) == 0 )
			{
				type_object->m_enum = IfcBenchmarkEnum::ENUM_LESSTHANOREQUALTO;
			}
			else if( _stricmp( arg.c_str(), ".EQUALTO." ) == 0 )
			{
				type_object->m_enum = IfcBenchmarkEnum::ENUM_EQUALTO;
			}
			else if( _stricmp( arg.c_str(), ".NOTEQUALTO." ) == 0 )
			{
				type_object->m_enum = IfcBenchmarkEnum::ENUM_NOTEQUALTO;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
