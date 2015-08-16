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
#include "include/IfcAirToAirHeatRecoveryTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcAirToAirHeatRecoveryTypeEnum 
		IfcAirToAirHeatRecoveryTypeEnum::IfcAirToAirHeatRecoveryTypeEnum() {}
		IfcAirToAirHeatRecoveryTypeEnum::~IfcAirToAirHeatRecoveryTypeEnum() {}
		void IfcAirToAirHeatRecoveryTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCAIRTOAIRHEATRECOVERYTYPEENUM("; }
			if( m_enum == ENUM_FIXEDPLATECOUNTERFLOWEXCHANGER )
			{
				stream << ".FIXEDPLATECOUNTERFLOWEXCHANGER.";
			}
			else if( m_enum == ENUM_FIXEDPLATECROSSFLOWEXCHANGER )
			{
				stream << ".FIXEDPLATECROSSFLOWEXCHANGER.";
			}
			else if( m_enum == ENUM_FIXEDPLATEPARALLELFLOWEXCHANGER )
			{
				stream << ".FIXEDPLATEPARALLELFLOWEXCHANGER.";
			}
			else if( m_enum == ENUM_ROTARYWHEEL )
			{
				stream << ".ROTARYWHEEL.";
			}
			else if( m_enum == ENUM_RUNAROUNDCOILLOOP )
			{
				stream << ".RUNAROUNDCOILLOOP.";
			}
			else if( m_enum == ENUM_HEATPIPE )
			{
				stream << ".HEATPIPE.";
			}
			else if( m_enum == ENUM_TWINTOWERENTHALPYRECOVERYLOOPS )
			{
				stream << ".TWINTOWERENTHALPYRECOVERYLOOPS.";
			}
			else if( m_enum == ENUM_THERMOSIPHONSEALEDTUBEHEATEXCHANGERS )
			{
				stream << ".THERMOSIPHONSEALEDTUBEHEATEXCHANGERS.";
			}
			else if( m_enum == ENUM_THERMOSIPHONCOILTYPEHEATEXCHANGERS )
			{
				stream << ".THERMOSIPHONCOILTYPEHEATEXCHANGERS.";
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
		shared_ptr<IfcAirToAirHeatRecoveryTypeEnum> IfcAirToAirHeatRecoveryTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAirToAirHeatRecoveryTypeEnum>(); }
			shared_ptr<IfcAirToAirHeatRecoveryTypeEnum> type_object( new IfcAirToAirHeatRecoveryTypeEnum() );
			if( _stricmp( arg.c_str(), ".FIXEDPLATECOUNTERFLOWEXCHANGER." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_FIXEDPLATECOUNTERFLOWEXCHANGER;
			}
			else if( _stricmp( arg.c_str(), ".FIXEDPLATECROSSFLOWEXCHANGER." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_FIXEDPLATECROSSFLOWEXCHANGER;
			}
			else if( _stricmp( arg.c_str(), ".FIXEDPLATEPARALLELFLOWEXCHANGER." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_FIXEDPLATEPARALLELFLOWEXCHANGER;
			}
			else if( _stricmp( arg.c_str(), ".ROTARYWHEEL." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_ROTARYWHEEL;
			}
			else if( _stricmp( arg.c_str(), ".RUNAROUNDCOILLOOP." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_RUNAROUNDCOILLOOP;
			}
			else if( _stricmp( arg.c_str(), ".HEATPIPE." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_HEATPIPE;
			}
			else if( _stricmp( arg.c_str(), ".TWINTOWERENTHALPYRECOVERYLOOPS." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_TWINTOWERENTHALPYRECOVERYLOOPS;
			}
			else if( _stricmp( arg.c_str(), ".THERMOSIPHONSEALEDTUBEHEATEXCHANGERS." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_THERMOSIPHONSEALEDTUBEHEATEXCHANGERS;
			}
			else if( _stricmp( arg.c_str(), ".THERMOSIPHONCOILTYPEHEATEXCHANGERS." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_THERMOSIPHONCOILTYPEHEATEXCHANGERS;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAirToAirHeatRecoveryTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
