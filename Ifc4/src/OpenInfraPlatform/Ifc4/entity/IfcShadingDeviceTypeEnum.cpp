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
#include "include/IfcShadingDeviceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcShadingDeviceTypeEnum 
		IfcShadingDeviceTypeEnum::IfcShadingDeviceTypeEnum() {}
		IfcShadingDeviceTypeEnum::~IfcShadingDeviceTypeEnum() {}
		void IfcShadingDeviceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSHADINGDEVICETYPEENUM("; }
			if( m_enum == ENUM_JALOUSIE )
			{
				stream << ".JALOUSIE.";
			}
			else if( m_enum == ENUM_SHUTTER )
			{
				stream << ".SHUTTER.";
			}
			else if( m_enum == ENUM_AWNING )
			{
				stream << ".AWNING.";
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
		shared_ptr<IfcShadingDeviceTypeEnum> IfcShadingDeviceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcShadingDeviceTypeEnum>(); }
			shared_ptr<IfcShadingDeviceTypeEnum> type_object( new IfcShadingDeviceTypeEnum() );
			if( _stricmp( arg.c_str(), ".JALOUSIE." ) == 0 )
			{
				type_object->m_enum = IfcShadingDeviceTypeEnum::ENUM_JALOUSIE;
			}
			else if( _stricmp( arg.c_str(), ".SHUTTER." ) == 0 )
			{
				type_object->m_enum = IfcShadingDeviceTypeEnum::ENUM_SHUTTER;
			}
			else if( _stricmp( arg.c_str(), ".AWNING." ) == 0 )
			{
				type_object->m_enum = IfcShadingDeviceTypeEnum::ENUM_AWNING;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcShadingDeviceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcShadingDeviceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
