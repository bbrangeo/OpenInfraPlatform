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
#include "include/IfcAlarmTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcAlarmTypeEnum 
		IfcAlarmTypeEnum::IfcAlarmTypeEnum() {}
		IfcAlarmTypeEnum::~IfcAlarmTypeEnum() {}
		void IfcAlarmTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCALARMTYPEENUM("; }
			if( m_enum == ENUM_BELL )
			{
				stream << ".BELL.";
			}
			else if( m_enum == ENUM_BREAKGLASSBUTTON )
			{
				stream << ".BREAKGLASSBUTTON.";
			}
			else if( m_enum == ENUM_LIGHT )
			{
				stream << ".LIGHT.";
			}
			else if( m_enum == ENUM_MANUALPULLBOX )
			{
				stream << ".MANUALPULLBOX.";
			}
			else if( m_enum == ENUM_SIREN )
			{
				stream << ".SIREN.";
			}
			else if( m_enum == ENUM_WHISTLE )
			{
				stream << ".WHISTLE.";
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
		shared_ptr<IfcAlarmTypeEnum> IfcAlarmTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAlarmTypeEnum>(); }
			shared_ptr<IfcAlarmTypeEnum> type_object( new IfcAlarmTypeEnum() );
			if( _stricmp( arg.c_str(), ".BELL." ) == 0 )
			{
				type_object->m_enum = IfcAlarmTypeEnum::ENUM_BELL;
			}
			else if( _stricmp( arg.c_str(), ".BREAKGLASSBUTTON." ) == 0 )
			{
				type_object->m_enum = IfcAlarmTypeEnum::ENUM_BREAKGLASSBUTTON;
			}
			else if( _stricmp( arg.c_str(), ".LIGHT." ) == 0 )
			{
				type_object->m_enum = IfcAlarmTypeEnum::ENUM_LIGHT;
			}
			else if( _stricmp( arg.c_str(), ".MANUALPULLBOX." ) == 0 )
			{
				type_object->m_enum = IfcAlarmTypeEnum::ENUM_MANUALPULLBOX;
			}
			else if( _stricmp( arg.c_str(), ".SIREN." ) == 0 )
			{
				type_object->m_enum = IfcAlarmTypeEnum::ENUM_SIREN;
			}
			else if( _stricmp( arg.c_str(), ".WHISTLE." ) == 0 )
			{
				type_object->m_enum = IfcAlarmTypeEnum::ENUM_WHISTLE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAlarmTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAlarmTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
