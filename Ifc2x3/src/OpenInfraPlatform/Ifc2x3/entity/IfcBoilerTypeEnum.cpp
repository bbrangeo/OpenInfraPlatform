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
#include "include/IfcBoilerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcBoilerTypeEnum 
		IfcBoilerTypeEnum::IfcBoilerTypeEnum() {}
		IfcBoilerTypeEnum::~IfcBoilerTypeEnum() {}
		void IfcBoilerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBOILERTYPEENUM("; }
			if( m_enum == ENUM_WATER )
			{
				stream << ".WATER.";
			}
			else if( m_enum == ENUM_STEAM )
			{
				stream << ".STEAM.";
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
		shared_ptr<IfcBoilerTypeEnum> IfcBoilerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBoilerTypeEnum>(); }
			shared_ptr<IfcBoilerTypeEnum> type_object( new IfcBoilerTypeEnum() );
			if( _stricmp( arg.c_str(), ".WATER." ) == 0 )
			{
				type_object->m_enum = IfcBoilerTypeEnum::ENUM_WATER;
			}
			else if( _stricmp( arg.c_str(), ".STEAM." ) == 0 )
			{
				type_object->m_enum = IfcBoilerTypeEnum::ENUM_STEAM;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBoilerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBoilerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
