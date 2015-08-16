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
#include "include/IfcColumnTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcColumnTypeEnum 
		IfcColumnTypeEnum::IfcColumnTypeEnum() {}
		IfcColumnTypeEnum::~IfcColumnTypeEnum() {}
		void IfcColumnTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOLUMNTYPEENUM("; }
			if( m_enum == ENUM_COLUMN )
			{
				stream << ".COLUMN.";
			}
			else if( m_enum == ENUM_PILASTER )
			{
				stream << ".PILASTER.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcColumnTypeEnum> IfcColumnTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcColumnTypeEnum>(); }
			shared_ptr<IfcColumnTypeEnum> type_object( new IfcColumnTypeEnum() );
			if( _stricmp( arg.c_str(), ".COLUMN." ) == 0 )
			{
				type_object->m_enum = IfcColumnTypeEnum::ENUM_COLUMN;
			}
			else if( _stricmp( arg.c_str(), ".PILASTER." ) == 0 )
			{
				type_object->m_enum = IfcColumnTypeEnum::ENUM_PILASTER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcColumnTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcColumnTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
