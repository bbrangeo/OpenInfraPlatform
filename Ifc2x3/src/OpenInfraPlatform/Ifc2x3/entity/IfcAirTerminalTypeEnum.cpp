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
#include "include/IfcAirTerminalTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcAirTerminalTypeEnum 
		IfcAirTerminalTypeEnum::IfcAirTerminalTypeEnum() {}
		IfcAirTerminalTypeEnum::~IfcAirTerminalTypeEnum() {}
		void IfcAirTerminalTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCAIRTERMINALTYPEENUM("; }
			if( m_enum == ENUM_GRILLE )
			{
				stream << ".GRILLE.";
			}
			else if( m_enum == ENUM_REGISTER )
			{
				stream << ".REGISTER.";
			}
			else if( m_enum == ENUM_DIFFUSER )
			{
				stream << ".DIFFUSER.";
			}
			else if( m_enum == ENUM_EYEBALL )
			{
				stream << ".EYEBALL.";
			}
			else if( m_enum == ENUM_IRIS )
			{
				stream << ".IRIS.";
			}
			else if( m_enum == ENUM_LINEARGRILLE )
			{
				stream << ".LINEARGRILLE.";
			}
			else if( m_enum == ENUM_LINEARDIFFUSER )
			{
				stream << ".LINEARDIFFUSER.";
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
		shared_ptr<IfcAirTerminalTypeEnum> IfcAirTerminalTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAirTerminalTypeEnum>(); }
			shared_ptr<IfcAirTerminalTypeEnum> type_object( new IfcAirTerminalTypeEnum() );
			if( _stricmp( arg.c_str(), ".GRILLE." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_GRILLE;
			}
			else if( _stricmp( arg.c_str(), ".REGISTER." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_REGISTER;
			}
			else if( _stricmp( arg.c_str(), ".DIFFUSER." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_DIFFUSER;
			}
			else if( _stricmp( arg.c_str(), ".EYEBALL." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_EYEBALL;
			}
			else if( _stricmp( arg.c_str(), ".IRIS." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_IRIS;
			}
			else if( _stricmp( arg.c_str(), ".LINEARGRILLE." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_LINEARGRILLE;
			}
			else if( _stricmp( arg.c_str(), ".LINEARDIFFUSER." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_LINEARDIFFUSER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
