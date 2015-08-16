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
#include "include/IfcElectricDistributionPointFunctionEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcElectricDistributionPointFunctionEnum 
		IfcElectricDistributionPointFunctionEnum::IfcElectricDistributionPointFunctionEnum() {}
		IfcElectricDistributionPointFunctionEnum::~IfcElectricDistributionPointFunctionEnum() {}
		void IfcElectricDistributionPointFunctionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELECTRICDISTRIBUTIONPOINTFUNCTIONENUM("; }
			if( m_enum == ENUM_ALARMPANEL )
			{
				stream << ".ALARMPANEL.";
			}
			else if( m_enum == ENUM_CONSUMERUNIT )
			{
				stream << ".CONSUMERUNIT.";
			}
			else if( m_enum == ENUM_CONTROLPANEL )
			{
				stream << ".CONTROLPANEL.";
			}
			else if( m_enum == ENUM_DISTRIBUTIONBOARD )
			{
				stream << ".DISTRIBUTIONBOARD.";
			}
			else if( m_enum == ENUM_GASDETECTORPANEL )
			{
				stream << ".GASDETECTORPANEL.";
			}
			else if( m_enum == ENUM_INDICATORPANEL )
			{
				stream << ".INDICATORPANEL.";
			}
			else if( m_enum == ENUM_MIMICPANEL )
			{
				stream << ".MIMICPANEL.";
			}
			else if( m_enum == ENUM_MOTORCONTROLCENTRE )
			{
				stream << ".MOTORCONTROLCENTRE.";
			}
			else if( m_enum == ENUM_SWITCHBOARD )
			{
				stream << ".SWITCHBOARD.";
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
		shared_ptr<IfcElectricDistributionPointFunctionEnum> IfcElectricDistributionPointFunctionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElectricDistributionPointFunctionEnum>(); }
			shared_ptr<IfcElectricDistributionPointFunctionEnum> type_object( new IfcElectricDistributionPointFunctionEnum() );
			if( _stricmp( arg.c_str(), ".ALARMPANEL." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_ALARMPANEL;
			}
			else if( _stricmp( arg.c_str(), ".CONSUMERUNIT." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_CONSUMERUNIT;
			}
			else if( _stricmp( arg.c_str(), ".CONTROLPANEL." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_CONTROLPANEL;
			}
			else if( _stricmp( arg.c_str(), ".DISTRIBUTIONBOARD." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_DISTRIBUTIONBOARD;
			}
			else if( _stricmp( arg.c_str(), ".GASDETECTORPANEL." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_GASDETECTORPANEL;
			}
			else if( _stricmp( arg.c_str(), ".INDICATORPANEL." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_INDICATORPANEL;
			}
			else if( _stricmp( arg.c_str(), ".MIMICPANEL." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_MIMICPANEL;
			}
			else if( _stricmp( arg.c_str(), ".MOTORCONTROLCENTRE." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_MOTORCONTROLCENTRE;
			}
			else if( _stricmp( arg.c_str(), ".SWITCHBOARD." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_SWITCHBOARD;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionPointFunctionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
