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
#include "include/IfcPumpTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcPumpTypeEnum 
		IfcPumpTypeEnum::IfcPumpTypeEnum() {}
		IfcPumpTypeEnum::~IfcPumpTypeEnum() {}
		void IfcPumpTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPUMPTYPEENUM("; }
			if( m_enum == ENUM_CIRCULATOR )
			{
				stream << ".CIRCULATOR.";
			}
			else if( m_enum == ENUM_ENDSUCTION )
			{
				stream << ".ENDSUCTION.";
			}
			else if( m_enum == ENUM_SPLITCASE )
			{
				stream << ".SPLITCASE.";
			}
			else if( m_enum == ENUM_SUBMERSIBLEPUMP )
			{
				stream << ".SUBMERSIBLEPUMP.";
			}
			else if( m_enum == ENUM_SUMPPUMP )
			{
				stream << ".SUMPPUMP.";
			}
			else if( m_enum == ENUM_VERTICALINLINE )
			{
				stream << ".VERTICALINLINE.";
			}
			else if( m_enum == ENUM_VERTICALTURBINE )
			{
				stream << ".VERTICALTURBINE.";
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
		shared_ptr<IfcPumpTypeEnum> IfcPumpTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPumpTypeEnum>(); }
			shared_ptr<IfcPumpTypeEnum> type_object( new IfcPumpTypeEnum() );
			if( _stricmp( arg.c_str(), ".CIRCULATOR." ) == 0 )
			{
				type_object->m_enum = IfcPumpTypeEnum::ENUM_CIRCULATOR;
			}
			else if( _stricmp( arg.c_str(), ".ENDSUCTION." ) == 0 )
			{
				type_object->m_enum = IfcPumpTypeEnum::ENUM_ENDSUCTION;
			}
			else if( _stricmp( arg.c_str(), ".SPLITCASE." ) == 0 )
			{
				type_object->m_enum = IfcPumpTypeEnum::ENUM_SPLITCASE;
			}
			else if( _stricmp( arg.c_str(), ".SUBMERSIBLEPUMP." ) == 0 )
			{
				type_object->m_enum = IfcPumpTypeEnum::ENUM_SUBMERSIBLEPUMP;
			}
			else if( _stricmp( arg.c_str(), ".SUMPPUMP." ) == 0 )
			{
				type_object->m_enum = IfcPumpTypeEnum::ENUM_SUMPPUMP;
			}
			else if( _stricmp( arg.c_str(), ".VERTICALINLINE." ) == 0 )
			{
				type_object->m_enum = IfcPumpTypeEnum::ENUM_VERTICALINLINE;
			}
			else if( _stricmp( arg.c_str(), ".VERTICALTURBINE." ) == 0 )
			{
				type_object->m_enum = IfcPumpTypeEnum::ENUM_VERTICALTURBINE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPumpTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPumpTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
