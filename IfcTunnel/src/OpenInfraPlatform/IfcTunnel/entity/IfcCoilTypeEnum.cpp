/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcCoilTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcCoilTypeEnum 
		IfcCoilTypeEnum::IfcCoilTypeEnum() {}
		IfcCoilTypeEnum::~IfcCoilTypeEnum() {}
		void IfcCoilTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOILTYPEENUM("; }
			if( m_enum == ENUM_DXCOOLINGCOIL )
			{
				stream << ".DXCOOLINGCOIL.";
			}
			else if( m_enum == ENUM_ELECTRICHEATINGCOIL )
			{
				stream << ".ELECTRICHEATINGCOIL.";
			}
			else if( m_enum == ENUM_GASHEATINGCOIL )
			{
				stream << ".GASHEATINGCOIL.";
			}
			else if( m_enum == ENUM_HYDRONICCOIL )
			{
				stream << ".HYDRONICCOIL.";
			}
			else if( m_enum == ENUM_STEAMHEATINGCOIL )
			{
				stream << ".STEAMHEATINGCOIL.";
			}
			else if( m_enum == ENUM_WATERCOOLINGCOIL )
			{
				stream << ".WATERCOOLINGCOIL.";
			}
			else if( m_enum == ENUM_WATERHEATINGCOIL )
			{
				stream << ".WATERHEATINGCOIL.";
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
		shared_ptr<IfcCoilTypeEnum> IfcCoilTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCoilTypeEnum>(); }
			shared_ptr<IfcCoilTypeEnum> type_object( new IfcCoilTypeEnum() );
			if( _stricmp( arg.c_str(), ".DXCOOLINGCOIL." ) == 0 )
			{
				type_object->m_enum = IfcCoilTypeEnum::ENUM_DXCOOLINGCOIL;
			}
			else if( _stricmp( arg.c_str(), ".ELECTRICHEATINGCOIL." ) == 0 )
			{
				type_object->m_enum = IfcCoilTypeEnum::ENUM_ELECTRICHEATINGCOIL;
			}
			else if( _stricmp( arg.c_str(), ".GASHEATINGCOIL." ) == 0 )
			{
				type_object->m_enum = IfcCoilTypeEnum::ENUM_GASHEATINGCOIL;
			}
			else if( _stricmp( arg.c_str(), ".HYDRONICCOIL." ) == 0 )
			{
				type_object->m_enum = IfcCoilTypeEnum::ENUM_HYDRONICCOIL;
			}
			else if( _stricmp( arg.c_str(), ".STEAMHEATINGCOIL." ) == 0 )
			{
				type_object->m_enum = IfcCoilTypeEnum::ENUM_STEAMHEATINGCOIL;
			}
			else if( _stricmp( arg.c_str(), ".WATERCOOLINGCOIL." ) == 0 )
			{
				type_object->m_enum = IfcCoilTypeEnum::ENUM_WATERCOOLINGCOIL;
			}
			else if( _stricmp( arg.c_str(), ".WATERHEATINGCOIL." ) == 0 )
			{
				type_object->m_enum = IfcCoilTypeEnum::ENUM_WATERHEATINGCOIL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCoilTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCoilTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
