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
#include "include/IfcStructuralCurveMemberTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcStructuralCurveMemberTypeEnum 
		IfcStructuralCurveMemberTypeEnum::IfcStructuralCurveMemberTypeEnum() {}
		IfcStructuralCurveMemberTypeEnum::~IfcStructuralCurveMemberTypeEnum() {}
		void IfcStructuralCurveMemberTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTRUCTURALCURVEMEMBERTYPEENUM("; }
			if( m_enum == ENUM_RIGID_JOINED_MEMBER )
			{
				stream << ".RIGID_JOINED_MEMBER.";
			}
			else if( m_enum == ENUM_PIN_JOINED_MEMBER )
			{
				stream << ".PIN_JOINED_MEMBER.";
			}
			else if( m_enum == ENUM_CABLE )
			{
				stream << ".CABLE.";
			}
			else if( m_enum == ENUM_TENSION_MEMBER )
			{
				stream << ".TENSION_MEMBER.";
			}
			else if( m_enum == ENUM_COMPRESSION_MEMBER )
			{
				stream << ".COMPRESSION_MEMBER.";
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
		shared_ptr<IfcStructuralCurveMemberTypeEnum> IfcStructuralCurveMemberTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStructuralCurveMemberTypeEnum>(); }
			shared_ptr<IfcStructuralCurveMemberTypeEnum> type_object( new IfcStructuralCurveMemberTypeEnum() );
			if( _stricmp( arg.c_str(), ".RIGID_JOINED_MEMBER." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveMemberTypeEnum::ENUM_RIGID_JOINED_MEMBER;
			}
			else if( _stricmp( arg.c_str(), ".PIN_JOINED_MEMBER." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveMemberTypeEnum::ENUM_PIN_JOINED_MEMBER;
			}
			else if( _stricmp( arg.c_str(), ".CABLE." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveMemberTypeEnum::ENUM_CABLE;
			}
			else if( _stricmp( arg.c_str(), ".TENSION_MEMBER." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveMemberTypeEnum::ENUM_TENSION_MEMBER;
			}
			else if( _stricmp( arg.c_str(), ".COMPRESSION_MEMBER." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveMemberTypeEnum::ENUM_COMPRESSION_MEMBER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveMemberTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveMemberTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
