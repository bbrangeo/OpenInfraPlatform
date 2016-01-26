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
#include "include/IfcAirTerminalTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcAirTerminalTypeEnum 
		IfcAirTerminalTypeEnum::IfcAirTerminalTypeEnum() {}
		IfcAirTerminalTypeEnum::~IfcAirTerminalTypeEnum() {}
		void IfcAirTerminalTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCAIRTERMINALTYPEENUM("; }
			if( m_enum == ENUM_DIFFUSER )
			{
				stream << ".DIFFUSER.";
			}
			else if( m_enum == ENUM_GRILLE )
			{
				stream << ".GRILLE.";
			}
			else if( m_enum == ENUM_LOUVRE )
			{
				stream << ".LOUVRE.";
			}
			else if( m_enum == ENUM_REGISTER )
			{
				stream << ".REGISTER.";
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
			if( _stricmp( arg.c_str(), ".DIFFUSER." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_DIFFUSER;
			}
			else if( _stricmp( arg.c_str(), ".GRILLE." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_GRILLE;
			}
			else if( _stricmp( arg.c_str(), ".LOUVRE." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_LOUVRE;
			}
			else if( _stricmp( arg.c_str(), ".REGISTER." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalTypeEnum::ENUM_REGISTER;
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
