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
#include "include/IfcCooledBeamTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcCooledBeamTypeEnum 
		IfcCooledBeamTypeEnum::IfcCooledBeamTypeEnum() {}
		IfcCooledBeamTypeEnum::~IfcCooledBeamTypeEnum() {}
		void IfcCooledBeamTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOOLEDBEAMTYPEENUM("; }
			if( m_enum == ENUM_ACTIVE )
			{
				stream << ".ACTIVE.";
			}
			else if( m_enum == ENUM_PASSIVE )
			{
				stream << ".PASSIVE.";
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
		shared_ptr<IfcCooledBeamTypeEnum> IfcCooledBeamTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCooledBeamTypeEnum>(); }
			shared_ptr<IfcCooledBeamTypeEnum> type_object( new IfcCooledBeamTypeEnum() );
			if( _stricmp( arg.c_str(), ".ACTIVE." ) == 0 )
			{
				type_object->m_enum = IfcCooledBeamTypeEnum::ENUM_ACTIVE;
			}
			else if( _stricmp( arg.c_str(), ".PASSIVE." ) == 0 )
			{
				type_object->m_enum = IfcCooledBeamTypeEnum::ENUM_PASSIVE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCooledBeamTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCooledBeamTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
