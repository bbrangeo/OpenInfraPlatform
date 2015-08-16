/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcArithmeticOperatorEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
