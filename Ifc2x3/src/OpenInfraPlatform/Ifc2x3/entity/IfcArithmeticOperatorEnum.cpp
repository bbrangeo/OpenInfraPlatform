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
#include "include/IfcArithmeticOperatorEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcArithmeticOperatorEnum 
		IfcArithmeticOperatorEnum::IfcArithmeticOperatorEnum() {}
		IfcArithmeticOperatorEnum::~IfcArithmeticOperatorEnum() {}
		void IfcArithmeticOperatorEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCARITHMETICOPERATORENUM("; }
			if( m_enum == ENUM_ADD )
			{
				stream << ".ADD.";
			}
			else if( m_enum == ENUM_DIVIDE )
			{
				stream << ".DIVIDE.";
			}
			else if( m_enum == ENUM_MULTIPLY )
			{
				stream << ".MULTIPLY.";
			}
			else if( m_enum == ENUM_SUBTRACT )
			{
				stream << ".SUBTRACT.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcArithmeticOperatorEnum> IfcArithmeticOperatorEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcArithmeticOperatorEnum>(); }
			shared_ptr<IfcArithmeticOperatorEnum> type_object( new IfcArithmeticOperatorEnum() );
			if( _stricmp( arg.c_str(), ".ADD." ) == 0 )
			{
				type_object->m_enum = IfcArithmeticOperatorEnum::ENUM_ADD;
			}
			else if( _stricmp( arg.c_str(), ".DIVIDE." ) == 0 )
			{
				type_object->m_enum = IfcArithmeticOperatorEnum::ENUM_DIVIDE;
			}
			else if( _stricmp( arg.c_str(), ".MULTIPLY." ) == 0 )
			{
				type_object->m_enum = IfcArithmeticOperatorEnum::ENUM_MULTIPLY;
			}
			else if( _stricmp( arg.c_str(), ".SUBTRACT." ) == 0 )
			{
				type_object->m_enum = IfcArithmeticOperatorEnum::ENUM_SUBTRACT;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
