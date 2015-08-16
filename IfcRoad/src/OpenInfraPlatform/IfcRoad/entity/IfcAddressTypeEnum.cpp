/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcAddressTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcAddressTypeEnum 
		IfcAddressTypeEnum::IfcAddressTypeEnum() {}
		IfcAddressTypeEnum::~IfcAddressTypeEnum() {}
		void IfcAddressTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCADDRESSTYPEENUM("; }
			if( m_enum == ENUM_OFFICE )
			{
				stream << ".OFFICE.";
			}
			else if( m_enum == ENUM_SITE )
			{
				stream << ".SITE.";
			}
			else if( m_enum == ENUM_HOME )
			{
				stream << ".HOME.";
			}
			else if( m_enum == ENUM_DISTRIBUTIONPOINT )
			{
				stream << ".DISTRIBUTIONPOINT.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcAddressTypeEnum> IfcAddressTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAddressTypeEnum>(); }
			shared_ptr<IfcAddressTypeEnum> type_object( new IfcAddressTypeEnum() );
			if( _stricmp( arg.c_str(), ".OFFICE." ) == 0 )
			{
				type_object->m_enum = IfcAddressTypeEnum::ENUM_OFFICE;
			}
			else if( _stricmp( arg.c_str(), ".SITE." ) == 0 )
			{
				type_object->m_enum = IfcAddressTypeEnum::ENUM_SITE;
			}
			else if( _stricmp( arg.c_str(), ".HOME." ) == 0 )
			{
				type_object->m_enum = IfcAddressTypeEnum::ENUM_HOME;
			}
			else if( _stricmp( arg.c_str(), ".DISTRIBUTIONPOINT." ) == 0 )
			{
				type_object->m_enum = IfcAddressTypeEnum::ENUM_DISTRIBUTIONPOINT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAddressTypeEnum::ENUM_USERDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
