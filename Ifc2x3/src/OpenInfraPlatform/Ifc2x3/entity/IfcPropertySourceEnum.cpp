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
#include "include/IfcPropertySourceEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcPropertySourceEnum 
		IfcPropertySourceEnum::IfcPropertySourceEnum() {}
		IfcPropertySourceEnum::~IfcPropertySourceEnum() {}
		void IfcPropertySourceEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROPERTYSOURCEENUM("; }
			if( m_enum == ENUM_DESIGN )
			{
				stream << ".DESIGN.";
			}
			else if( m_enum == ENUM_DESIGNMAXIMUM )
			{
				stream << ".DESIGNMAXIMUM.";
			}
			else if( m_enum == ENUM_DESIGNMINIMUM )
			{
				stream << ".DESIGNMINIMUM.";
			}
			else if( m_enum == ENUM_SIMULATED )
			{
				stream << ".SIMULATED.";
			}
			else if( m_enum == ENUM_ASBUILT )
			{
				stream << ".ASBUILT.";
			}
			else if( m_enum == ENUM_COMMISSIONING )
			{
				stream << ".COMMISSIONING.";
			}
			else if( m_enum == ENUM_MEASURED )
			{
				stream << ".MEASURED.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTKNOWN )
			{
				stream << ".NOTKNOWN.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcPropertySourceEnum> IfcPropertySourceEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPropertySourceEnum>(); }
			shared_ptr<IfcPropertySourceEnum> type_object( new IfcPropertySourceEnum() );
			if( _stricmp( arg.c_str(), ".DESIGN." ) == 0 )
			{
				type_object->m_enum = IfcPropertySourceEnum::ENUM_DESIGN;
			}
			else if( _stricmp( arg.c_str(), ".DESIGNMAXIMUM." ) == 0 )
			{
				type_object->m_enum = IfcPropertySourceEnum::ENUM_DESIGNMAXIMUM;
			}
			else if( _stricmp( arg.c_str(), ".DESIGNMINIMUM." ) == 0 )
			{
				type_object->m_enum = IfcPropertySourceEnum::ENUM_DESIGNMINIMUM;
			}
			else if( _stricmp( arg.c_str(), ".SIMULATED." ) == 0 )
			{
				type_object->m_enum = IfcPropertySourceEnum::ENUM_SIMULATED;
			}
			else if( _stricmp( arg.c_str(), ".ASBUILT." ) == 0 )
			{
				type_object->m_enum = IfcPropertySourceEnum::ENUM_ASBUILT;
			}
			else if( _stricmp( arg.c_str(), ".COMMISSIONING." ) == 0 )
			{
				type_object->m_enum = IfcPropertySourceEnum::ENUM_COMMISSIONING;
			}
			else if( _stricmp( arg.c_str(), ".MEASURED." ) == 0 )
			{
				type_object->m_enum = IfcPropertySourceEnum::ENUM_MEASURED;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPropertySourceEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTKNOWN." ) == 0 )
			{
				type_object->m_enum = IfcPropertySourceEnum::ENUM_NOTKNOWN;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
