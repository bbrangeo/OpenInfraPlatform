/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcBoilerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
