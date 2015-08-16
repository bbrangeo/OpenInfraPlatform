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
#include "include/IfcProjectOrderTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcProjectOrderTypeEnum 
		IfcProjectOrderTypeEnum::IfcProjectOrderTypeEnum() {}
		IfcProjectOrderTypeEnum::~IfcProjectOrderTypeEnum() {}
		void IfcProjectOrderTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROJECTORDERTYPEENUM("; }
			if( m_enum == ENUM_CHANGEORDER )
			{
				stream << ".CHANGEORDER.";
			}
			else if( m_enum == ENUM_MAINTENANCEWORKORDER )
			{
				stream << ".MAINTENANCEWORKORDER.";
			}
			else if( m_enum == ENUM_MOVEORDER )
			{
				stream << ".MOVEORDER.";
			}
			else if( m_enum == ENUM_PURCHASEORDER )
			{
				stream << ".PURCHASEORDER.";
			}
			else if( m_enum == ENUM_WORKORDER )
			{
				stream << ".WORKORDER.";
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
		shared_ptr<IfcProjectOrderTypeEnum> IfcProjectOrderTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProjectOrderTypeEnum>(); }
			shared_ptr<IfcProjectOrderTypeEnum> type_object( new IfcProjectOrderTypeEnum() );
			if( _stricmp( arg.c_str(), ".CHANGEORDER." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_CHANGEORDER;
			}
			else if( _stricmp( arg.c_str(), ".MAINTENANCEWORKORDER." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_MAINTENANCEWORKORDER;
			}
			else if( _stricmp( arg.c_str(), ".MOVEORDER." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_MOVEORDER;
			}
			else if( _stricmp( arg.c_str(), ".PURCHASEORDER." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_PURCHASEORDER;
			}
			else if( _stricmp( arg.c_str(), ".WORKORDER." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_WORKORDER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProjectOrderTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
