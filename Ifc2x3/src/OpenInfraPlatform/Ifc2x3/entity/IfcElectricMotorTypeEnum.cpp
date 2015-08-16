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
#include "include/IfcElectricMotorTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcElectricMotorTypeEnum 
		IfcElectricMotorTypeEnum::IfcElectricMotorTypeEnum() {}
		IfcElectricMotorTypeEnum::~IfcElectricMotorTypeEnum() {}
		void IfcElectricMotorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELECTRICMOTORTYPEENUM("; }
			if( m_enum == ENUM_DC )
			{
				stream << ".DC.";
			}
			else if( m_enum == ENUM_INDUCTION )
			{
				stream << ".INDUCTION.";
			}
			else if( m_enum == ENUM_POLYPHASE )
			{
				stream << ".POLYPHASE.";
			}
			else if( m_enum == ENUM_RELUCTANCESYNCHRONOUS )
			{
				stream << ".RELUCTANCESYNCHRONOUS.";
			}
			else if( m_enum == ENUM_SYNCHRONOUS )
			{
				stream << ".SYNCHRONOUS.";
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
		shared_ptr<IfcElectricMotorTypeEnum> IfcElectricMotorTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElectricMotorTypeEnum>(); }
			shared_ptr<IfcElectricMotorTypeEnum> type_object( new IfcElectricMotorTypeEnum() );
			if( _stricmp( arg.c_str(), ".DC." ) == 0 )
			{
				type_object->m_enum = IfcElectricMotorTypeEnum::ENUM_DC;
			}
			else if( _stricmp( arg.c_str(), ".INDUCTION." ) == 0 )
			{
				type_object->m_enum = IfcElectricMotorTypeEnum::ENUM_INDUCTION;
			}
			else if( _stricmp( arg.c_str(), ".POLYPHASE." ) == 0 )
			{
				type_object->m_enum = IfcElectricMotorTypeEnum::ENUM_POLYPHASE;
			}
			else if( _stricmp( arg.c_str(), ".RELUCTANCESYNCHRONOUS." ) == 0 )
			{
				type_object->m_enum = IfcElectricMotorTypeEnum::ENUM_RELUCTANCESYNCHRONOUS;
			}
			else if( _stricmp( arg.c_str(), ".SYNCHRONOUS." ) == 0 )
			{
				type_object->m_enum = IfcElectricMotorTypeEnum::ENUM_SYNCHRONOUS;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricMotorTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricMotorTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
