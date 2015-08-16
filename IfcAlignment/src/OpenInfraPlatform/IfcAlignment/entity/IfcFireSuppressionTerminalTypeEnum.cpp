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
#include "include/IfcFireSuppressionTerminalTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcFireSuppressionTerminalTypeEnum 
		IfcFireSuppressionTerminalTypeEnum::IfcFireSuppressionTerminalTypeEnum() {}
		IfcFireSuppressionTerminalTypeEnum::~IfcFireSuppressionTerminalTypeEnum() {}
		void IfcFireSuppressionTerminalTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCFIRESUPPRESSIONTERMINALTYPEENUM("; }
			if( m_enum == ENUM_BREECHINGINLET )
			{
				stream << ".BREECHINGINLET.";
			}
			else if( m_enum == ENUM_FIREHYDRANT )
			{
				stream << ".FIREHYDRANT.";
			}
			else if( m_enum == ENUM_HOSEREEL )
			{
				stream << ".HOSEREEL.";
			}
			else if( m_enum == ENUM_SPRINKLER )
			{
				stream << ".SPRINKLER.";
			}
			else if( m_enum == ENUM_SPRINKLERDEFLECTOR )
			{
				stream << ".SPRINKLERDEFLECTOR.";
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
		shared_ptr<IfcFireSuppressionTerminalTypeEnum> IfcFireSuppressionTerminalTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFireSuppressionTerminalTypeEnum>(); }
			shared_ptr<IfcFireSuppressionTerminalTypeEnum> type_object( new IfcFireSuppressionTerminalTypeEnum() );
			if( _stricmp( arg.c_str(), ".BREECHINGINLET." ) == 0 )
			{
				type_object->m_enum = IfcFireSuppressionTerminalTypeEnum::ENUM_BREECHINGINLET;
			}
			else if( _stricmp( arg.c_str(), ".FIREHYDRANT." ) == 0 )
			{
				type_object->m_enum = IfcFireSuppressionTerminalTypeEnum::ENUM_FIREHYDRANT;
			}
			else if( _stricmp( arg.c_str(), ".HOSEREEL." ) == 0 )
			{
				type_object->m_enum = IfcFireSuppressionTerminalTypeEnum::ENUM_HOSEREEL;
			}
			else if( _stricmp( arg.c_str(), ".SPRINKLER." ) == 0 )
			{
				type_object->m_enum = IfcFireSuppressionTerminalTypeEnum::ENUM_SPRINKLER;
			}
			else if( _stricmp( arg.c_str(), ".SPRINKLERDEFLECTOR." ) == 0 )
			{
				type_object->m_enum = IfcFireSuppressionTerminalTypeEnum::ENUM_SPRINKLERDEFLECTOR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFireSuppressionTerminalTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFireSuppressionTerminalTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
