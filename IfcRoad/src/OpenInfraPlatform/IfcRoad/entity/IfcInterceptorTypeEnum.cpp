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
#include "include/IfcInterceptorTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcInterceptorTypeEnum 
		IfcInterceptorTypeEnum::IfcInterceptorTypeEnum() {}
		IfcInterceptorTypeEnum::~IfcInterceptorTypeEnum() {}
		void IfcInterceptorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCINTERCEPTORTYPEENUM("; }
			if( m_enum == ENUM_CYCLONIC )
			{
				stream << ".CYCLONIC.";
			}
			else if( m_enum == ENUM_GREASE )
			{
				stream << ".GREASE.";
			}
			else if( m_enum == ENUM_OIL )
			{
				stream << ".OIL.";
			}
			else if( m_enum == ENUM_PETROL )
			{
				stream << ".PETROL.";
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
		shared_ptr<IfcInterceptorTypeEnum> IfcInterceptorTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcInterceptorTypeEnum>(); }
			shared_ptr<IfcInterceptorTypeEnum> type_object( new IfcInterceptorTypeEnum() );
			if( _stricmp( arg.c_str(), ".CYCLONIC." ) == 0 )
			{
				type_object->m_enum = IfcInterceptorTypeEnum::ENUM_CYCLONIC;
			}
			else if( _stricmp( arg.c_str(), ".GREASE." ) == 0 )
			{
				type_object->m_enum = IfcInterceptorTypeEnum::ENUM_GREASE;
			}
			else if( _stricmp( arg.c_str(), ".OIL." ) == 0 )
			{
				type_object->m_enum = IfcInterceptorTypeEnum::ENUM_OIL;
			}
			else if( _stricmp( arg.c_str(), ".PETROL." ) == 0 )
			{
				type_object->m_enum = IfcInterceptorTypeEnum::ENUM_PETROL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcInterceptorTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcInterceptorTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
