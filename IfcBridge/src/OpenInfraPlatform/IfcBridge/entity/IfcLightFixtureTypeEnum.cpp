/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../model/IfcBridgeException.h"
#include "include/IfcLightFixtureTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcLightFixtureTypeEnum 
		IfcLightFixtureTypeEnum::IfcLightFixtureTypeEnum() {}
		IfcLightFixtureTypeEnum::~IfcLightFixtureTypeEnum() {}
		void IfcLightFixtureTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCLIGHTFIXTURETYPEENUM("; }
			if( m_enum == ENUM_POINTSOURCE )
			{
				stream << ".POINTSOURCE.";
			}
			else if( m_enum == ENUM_DIRECTIONSOURCE )
			{
				stream << ".DIRECTIONSOURCE.";
			}
			else if( m_enum == ENUM_SECURITYLIGHTING )
			{
				stream << ".SECURITYLIGHTING.";
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
		shared_ptr<IfcLightFixtureTypeEnum> IfcLightFixtureTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLightFixtureTypeEnum>(); }
			shared_ptr<IfcLightFixtureTypeEnum> type_object( new IfcLightFixtureTypeEnum() );
			if( _stricmp( arg.c_str(), ".POINTSOURCE." ) == 0 )
			{
				type_object->m_enum = IfcLightFixtureTypeEnum::ENUM_POINTSOURCE;
			}
			else if( _stricmp( arg.c_str(), ".DIRECTIONSOURCE." ) == 0 )
			{
				type_object->m_enum = IfcLightFixtureTypeEnum::ENUM_DIRECTIONSOURCE;
			}
			else if( _stricmp( arg.c_str(), ".SECURITYLIGHTING." ) == 0 )
			{
				type_object->m_enum = IfcLightFixtureTypeEnum::ENUM_SECURITYLIGHTING;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcLightFixtureTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcLightFixtureTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
