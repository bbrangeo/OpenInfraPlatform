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
#include "include/IfcCompressorTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcCompressorTypeEnum 
		IfcCompressorTypeEnum::IfcCompressorTypeEnum() {}
		IfcCompressorTypeEnum::~IfcCompressorTypeEnum() {}
		void IfcCompressorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOMPRESSORTYPEENUM("; }
			if( m_enum == ENUM_DYNAMIC )
			{
				stream << ".DYNAMIC.";
			}
			else if( m_enum == ENUM_RECIPROCATING )
			{
				stream << ".RECIPROCATING.";
			}
			else if( m_enum == ENUM_ROTARY )
			{
				stream << ".ROTARY.";
			}
			else if( m_enum == ENUM_SCROLL )
			{
				stream << ".SCROLL.";
			}
			else if( m_enum == ENUM_TROCHOIDAL )
			{
				stream << ".TROCHOIDAL.";
			}
			else if( m_enum == ENUM_SINGLESTAGE )
			{
				stream << ".SINGLESTAGE.";
			}
			else if( m_enum == ENUM_BOOSTER )
			{
				stream << ".BOOSTER.";
			}
			else if( m_enum == ENUM_OPENTYPE )
			{
				stream << ".OPENTYPE.";
			}
			else if( m_enum == ENUM_HERMETIC )
			{
				stream << ".HERMETIC.";
			}
			else if( m_enum == ENUM_SEMIHERMETIC )
			{
				stream << ".SEMIHERMETIC.";
			}
			else if( m_enum == ENUM_WELDEDSHELLHERMETIC )
			{
				stream << ".WELDEDSHELLHERMETIC.";
			}
			else if( m_enum == ENUM_ROLLINGPISTON )
			{
				stream << ".ROLLINGPISTON.";
			}
			else if( m_enum == ENUM_ROTARYVANE )
			{
				stream << ".ROTARYVANE.";
			}
			else if( m_enum == ENUM_SINGLESCREW )
			{
				stream << ".SINGLESCREW.";
			}
			else if( m_enum == ENUM_TWINSCREW )
			{
				stream << ".TWINSCREW.";
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
		shared_ptr<IfcCompressorTypeEnum> IfcCompressorTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCompressorTypeEnum>(); }
			shared_ptr<IfcCompressorTypeEnum> type_object( new IfcCompressorTypeEnum() );
			if( _stricmp( arg.c_str(), ".DYNAMIC." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_DYNAMIC;
			}
			else if( _stricmp( arg.c_str(), ".RECIPROCATING." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_RECIPROCATING;
			}
			else if( _stricmp( arg.c_str(), ".ROTARY." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_ROTARY;
			}
			else if( _stricmp( arg.c_str(), ".SCROLL." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_SCROLL;
			}
			else if( _stricmp( arg.c_str(), ".TROCHOIDAL." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_TROCHOIDAL;
			}
			else if( _stricmp( arg.c_str(), ".SINGLESTAGE." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_SINGLESTAGE;
			}
			else if( _stricmp( arg.c_str(), ".BOOSTER." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_BOOSTER;
			}
			else if( _stricmp( arg.c_str(), ".OPENTYPE." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_OPENTYPE;
			}
			else if( _stricmp( arg.c_str(), ".HERMETIC." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_HERMETIC;
			}
			else if( _stricmp( arg.c_str(), ".SEMIHERMETIC." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_SEMIHERMETIC;
			}
			else if( _stricmp( arg.c_str(), ".WELDEDSHELLHERMETIC." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_WELDEDSHELLHERMETIC;
			}
			else if( _stricmp( arg.c_str(), ".ROLLINGPISTON." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_ROLLINGPISTON;
			}
			else if( _stricmp( arg.c_str(), ".ROTARYVANE." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_ROTARYVANE;
			}
			else if( _stricmp( arg.c_str(), ".SINGLESCREW." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_SINGLESCREW;
			}
			else if( _stricmp( arg.c_str(), ".TWINSCREW." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_TWINSCREW;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCompressorTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
