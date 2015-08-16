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
#include "include/IfcSoundScaleEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcSoundScaleEnum 
		IfcSoundScaleEnum::IfcSoundScaleEnum() {}
		IfcSoundScaleEnum::~IfcSoundScaleEnum() {}
		void IfcSoundScaleEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSOUNDSCALEENUM("; }
			if( m_enum == ENUM_DBA )
			{
				stream << ".DBA.";
			}
			else if( m_enum == ENUM_DBB )
			{
				stream << ".DBB.";
			}
			else if( m_enum == ENUM_DBC )
			{
				stream << ".DBC.";
			}
			else if( m_enum == ENUM_NC )
			{
				stream << ".NC.";
			}
			else if( m_enum == ENUM_NR )
			{
				stream << ".NR.";
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
		shared_ptr<IfcSoundScaleEnum> IfcSoundScaleEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSoundScaleEnum>(); }
			shared_ptr<IfcSoundScaleEnum> type_object( new IfcSoundScaleEnum() );
			if( _stricmp( arg.c_str(), ".DBA." ) == 0 )
			{
				type_object->m_enum = IfcSoundScaleEnum::ENUM_DBA;
			}
			else if( _stricmp( arg.c_str(), ".DBB." ) == 0 )
			{
				type_object->m_enum = IfcSoundScaleEnum::ENUM_DBB;
			}
			else if( _stricmp( arg.c_str(), ".DBC." ) == 0 )
			{
				type_object->m_enum = IfcSoundScaleEnum::ENUM_DBC;
			}
			else if( _stricmp( arg.c_str(), ".NC." ) == 0 )
			{
				type_object->m_enum = IfcSoundScaleEnum::ENUM_NC;
			}
			else if( _stricmp( arg.c_str(), ".NR." ) == 0 )
			{
				type_object->m_enum = IfcSoundScaleEnum::ENUM_NR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSoundScaleEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSoundScaleEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
