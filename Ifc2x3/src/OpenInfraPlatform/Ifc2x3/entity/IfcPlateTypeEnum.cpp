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
#include "include/IfcPlateTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcPlateTypeEnum 
		IfcPlateTypeEnum::IfcPlateTypeEnum() {}
		IfcPlateTypeEnum::~IfcPlateTypeEnum() {}
		void IfcPlateTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPLATETYPEENUM("; }
			if( m_enum == ENUM_CURTAIN_PANEL )
			{
				stream << ".CURTAIN_PANEL.";
			}
			else if( m_enum == ENUM_SHEET )
			{
				stream << ".SHEET.";
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
		shared_ptr<IfcPlateTypeEnum> IfcPlateTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPlateTypeEnum>(); }
			shared_ptr<IfcPlateTypeEnum> type_object( new IfcPlateTypeEnum() );
			if( _stricmp( arg.c_str(), ".CURTAIN_PANEL." ) == 0 )
			{
				type_object->m_enum = IfcPlateTypeEnum::ENUM_CURTAIN_PANEL;
			}
			else if( _stricmp( arg.c_str(), ".SHEET." ) == 0 )
			{
				type_object->m_enum = IfcPlateTypeEnum::ENUM_SHEET;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPlateTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPlateTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
