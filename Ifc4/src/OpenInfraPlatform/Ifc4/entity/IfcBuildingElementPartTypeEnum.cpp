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
#include "include/IfcBuildingElementPartTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcBuildingElementPartTypeEnum 
		IfcBuildingElementPartTypeEnum::IfcBuildingElementPartTypeEnum() {}
		IfcBuildingElementPartTypeEnum::~IfcBuildingElementPartTypeEnum() {}
		void IfcBuildingElementPartTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBUILDINGELEMENTPARTTYPEENUM("; }
			if( m_enum == ENUM_INSULATION )
			{
				stream << ".INSULATION.";
			}
			else if( m_enum == ENUM_PRECASTPANEL )
			{
				stream << ".PRECASTPANEL.";
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
		shared_ptr<IfcBuildingElementPartTypeEnum> IfcBuildingElementPartTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBuildingElementPartTypeEnum>(); }
			shared_ptr<IfcBuildingElementPartTypeEnum> type_object( new IfcBuildingElementPartTypeEnum() );
			if( _stricmp( arg.c_str(), ".INSULATION." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementPartTypeEnum::ENUM_INSULATION;
			}
			else if( _stricmp( arg.c_str(), ".PRECASTPANEL." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementPartTypeEnum::ENUM_PRECASTPANEL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementPartTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementPartTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
