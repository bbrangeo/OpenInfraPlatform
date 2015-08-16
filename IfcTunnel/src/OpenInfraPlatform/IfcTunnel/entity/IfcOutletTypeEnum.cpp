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
#include "include/IfcOutletTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcOutletTypeEnum 
		IfcOutletTypeEnum::IfcOutletTypeEnum() {}
		IfcOutletTypeEnum::~IfcOutletTypeEnum() {}
		void IfcOutletTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCOUTLETTYPEENUM("; }
			if( m_enum == ENUM_AUDIOVISUALOUTLET )
			{
				stream << ".AUDIOVISUALOUTLET.";
			}
			else if( m_enum == ENUM_COMMUNICATIONSOUTLET )
			{
				stream << ".COMMUNICATIONSOUTLET.";
			}
			else if( m_enum == ENUM_POWEROUTLET )
			{
				stream << ".POWEROUTLET.";
			}
			else if( m_enum == ENUM_DATAOUTLET )
			{
				stream << ".DATAOUTLET.";
			}
			else if( m_enum == ENUM_TELEPHONEOUTLET )
			{
				stream << ".TELEPHONEOUTLET.";
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
		shared_ptr<IfcOutletTypeEnum> IfcOutletTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcOutletTypeEnum>(); }
			shared_ptr<IfcOutletTypeEnum> type_object( new IfcOutletTypeEnum() );
			if( _stricmp( arg.c_str(), ".AUDIOVISUALOUTLET." ) == 0 )
			{
				type_object->m_enum = IfcOutletTypeEnum::ENUM_AUDIOVISUALOUTLET;
			}
			else if( _stricmp( arg.c_str(), ".COMMUNICATIONSOUTLET." ) == 0 )
			{
				type_object->m_enum = IfcOutletTypeEnum::ENUM_COMMUNICATIONSOUTLET;
			}
			else if( _stricmp( arg.c_str(), ".POWEROUTLET." ) == 0 )
			{
				type_object->m_enum = IfcOutletTypeEnum::ENUM_POWEROUTLET;
			}
			else if( _stricmp( arg.c_str(), ".DATAOUTLET." ) == 0 )
			{
				type_object->m_enum = IfcOutletTypeEnum::ENUM_DATAOUTLET;
			}
			else if( _stricmp( arg.c_str(), ".TELEPHONEOUTLET." ) == 0 )
			{
				type_object->m_enum = IfcOutletTypeEnum::ENUM_TELEPHONEOUTLET;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcOutletTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcOutletTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
