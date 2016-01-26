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
#include "include/IfcElectricDistributionBoardTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcElectricDistributionBoardTypeEnum 
		IfcElectricDistributionBoardTypeEnum::IfcElectricDistributionBoardTypeEnum() {}
		IfcElectricDistributionBoardTypeEnum::~IfcElectricDistributionBoardTypeEnum() {}
		void IfcElectricDistributionBoardTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELECTRICDISTRIBUTIONBOARDTYPEENUM("; }
			if( m_enum == ENUM_CONSUMERUNIT )
			{
				stream << ".CONSUMERUNIT.";
			}
			else if( m_enum == ENUM_DISTRIBUTIONBOARD )
			{
				stream << ".DISTRIBUTIONBOARD.";
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
		shared_ptr<IfcElectricDistributionBoardTypeEnum> IfcElectricDistributionBoardTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElectricDistributionBoardTypeEnum>(); }
			shared_ptr<IfcElectricDistributionBoardTypeEnum> type_object( new IfcElectricDistributionBoardTypeEnum() );
			if( _stricmp( arg.c_str(), ".CONSUMERUNIT." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionBoardTypeEnum::ENUM_CONSUMERUNIT;
			}
			else if( _stricmp( arg.c_str(), ".DISTRIBUTIONBOARD." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionBoardTypeEnum::ENUM_DISTRIBUTIONBOARD;
			}
			else if( _stricmp( arg.c_str(), ".MOTORCONTROLCENTRE." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionBoardTypeEnum::ENUM_MOTORCONTROLCENTRE;
			}
			else if( _stricmp( arg.c_str(), ".SWITCHBOARD." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionBoardTypeEnum::ENUM_SWITCHBOARD;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionBoardTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricDistributionBoardTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
