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
#include "include/IfcElectricTimeControlTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcElectricTimeControlTypeEnum 
		IfcElectricTimeControlTypeEnum::IfcElectricTimeControlTypeEnum() {}
		IfcElectricTimeControlTypeEnum::~IfcElectricTimeControlTypeEnum() {}
		void IfcElectricTimeControlTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELECTRICTIMECONTROLTYPEENUM("; }
			if( m_enum == ENUM_TIMECLOCK )
			{
				stream << ".TIMECLOCK.";
			}
			else if( m_enum == ENUM_TIMEDELAY )
			{
				stream << ".TIMEDELAY.";
			}
			else if( m_enum == ENUM_RELAY )
			{
				stream << ".RELAY.";
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
		shared_ptr<IfcElectricTimeControlTypeEnum> IfcElectricTimeControlTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElectricTimeControlTypeEnum>(); }
			shared_ptr<IfcElectricTimeControlTypeEnum> type_object( new IfcElectricTimeControlTypeEnum() );
			if( _stricmp( arg.c_str(), ".TIMECLOCK." ) == 0 )
			{
				type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_TIMECLOCK;
			}
			else if( _stricmp( arg.c_str(), ".TIMEDELAY." ) == 0 )
			{
				type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_TIMEDELAY;
			}
			else if( _stricmp( arg.c_str(), ".RELAY." ) == 0 )
			{
				type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_RELAY;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
