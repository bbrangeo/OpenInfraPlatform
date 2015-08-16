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
#include "include/IfcControllerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcControllerTypeEnum 
		IfcControllerTypeEnum::IfcControllerTypeEnum() {}
		IfcControllerTypeEnum::~IfcControllerTypeEnum() {}
		void IfcControllerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCONTROLLERTYPEENUM("; }
			if( m_enum == ENUM_FLOATING )
			{
				stream << ".FLOATING.";
			}
			else if( m_enum == ENUM_PROPORTIONAL )
			{
				stream << ".PROPORTIONAL.";
			}
			else if( m_enum == ENUM_PROPORTIONALINTEGRAL )
			{
				stream << ".PROPORTIONALINTEGRAL.";
			}
			else if( m_enum == ENUM_PROPORTIONALINTEGRALDERIVATIVE )
			{
				stream << ".PROPORTIONALINTEGRALDERIVATIVE.";
			}
			else if( m_enum == ENUM_TIMEDTWOPOSITION )
			{
				stream << ".TIMEDTWOPOSITION.";
			}
			else if( m_enum == ENUM_TWOPOSITION )
			{
				stream << ".TWOPOSITION.";
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
		shared_ptr<IfcControllerTypeEnum> IfcControllerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcControllerTypeEnum>(); }
			shared_ptr<IfcControllerTypeEnum> type_object( new IfcControllerTypeEnum() );
			if( _stricmp( arg.c_str(), ".FLOATING." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_FLOATING;
			}
			else if( _stricmp( arg.c_str(), ".PROPORTIONAL." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_PROPORTIONAL;
			}
			else if( _stricmp( arg.c_str(), ".PROPORTIONALINTEGRAL." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_PROPORTIONALINTEGRAL;
			}
			else if( _stricmp( arg.c_str(), ".PROPORTIONALINTEGRALDERIVATIVE." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_PROPORTIONALINTEGRALDERIVATIVE;
			}
			else if( _stricmp( arg.c_str(), ".TIMEDTWOPOSITION." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_TIMEDTWOPOSITION;
			}
			else if( _stricmp( arg.c_str(), ".TWOPOSITION." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_TWOPOSITION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
