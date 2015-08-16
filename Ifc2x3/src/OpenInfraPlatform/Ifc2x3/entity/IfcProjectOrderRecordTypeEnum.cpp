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
#include "include/IfcProjectOrderRecordTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcProjectOrderRecordTypeEnum 
		IfcProjectOrderRecordTypeEnum::IfcProjectOrderRecordTypeEnum() {}
		IfcProjectOrderRecordTypeEnum::~IfcProjectOrderRecordTypeEnum() {}
		void IfcProjectOrderRecordTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROJECTORDERRECORDTYPEENUM("; }
			if( m_enum == ENUM_CHANGE )
			{
				stream << ".CHANGE.";
			}
			else if( m_enum == ENUM_MAINTENANCE )
			{
				stream << ".MAINTENANCE.";
			}
			else if( m_enum == ENUM_MOVE )
			{
				stream << ".MOVE.";
			}
			else if( m_enum == ENUM_PURCHASE )
			{
				stream << ".PURCHASE.";
			}
			else if( m_enum == ENUM_WORK )
			{
				stream << ".WORK.";
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
		shared_ptr<IfcProjectOrderRecordTypeEnum> IfcProjectOrderRecordTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProjectOrderRecordTypeEnum>(); }
			shared_ptr<IfcProjectOrderRecordTypeEnum> type_object( new IfcProjectOrderRecordTypeEnum() );
			if( _stricmp( arg.c_str(), ".CHANGE." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderRecordTypeEnum::ENUM_CHANGE;
			}
			else if( _stricmp( arg.c_str(), ".MAINTENANCE." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderRecordTypeEnum::ENUM_MAINTENANCE;
			}
			else if( _stricmp( arg.c_str(), ".MOVE." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderRecordTypeEnum::ENUM_MOVE;
			}
			else if( _stricmp( arg.c_str(), ".PURCHASE." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderRecordTypeEnum::ENUM_PURCHASE;
			}
			else if( _stricmp( arg.c_str(), ".WORK." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderRecordTypeEnum::ENUM_WORK;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderRecordTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderRecordTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
