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
#include "include/IfcPropertySetTemplateTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPropertySetTemplateTypeEnum 
		IfcPropertySetTemplateTypeEnum::IfcPropertySetTemplateTypeEnum() {}
		IfcPropertySetTemplateTypeEnum::~IfcPropertySetTemplateTypeEnum() {}
		void IfcPropertySetTemplateTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROPERTYSETTEMPLATETYPEENUM("; }
			if( m_enum == ENUM_PSET_TYPEDRIVENONLY )
			{
				stream << ".PSET_TYPEDRIVENONLY.";
			}
			else if( m_enum == ENUM_PSET_TYPEDRIVENOVERRIDE )
			{
				stream << ".PSET_TYPEDRIVENOVERRIDE.";
			}
			else if( m_enum == ENUM_PSET_OCCURRENCEDRIVEN )
			{
				stream << ".PSET_OCCURRENCEDRIVEN.";
			}
			else if( m_enum == ENUM_PSET_PERFORMANCEDRIVEN )
			{
				stream << ".PSET_PERFORMANCEDRIVEN.";
			}
			else if( m_enum == ENUM_QTO_TYPEDRIVENONLY )
			{
				stream << ".QTO_TYPEDRIVENONLY.";
			}
			else if( m_enum == ENUM_QTO_TYPEDRIVENOVERRIDE )
			{
				stream << ".QTO_TYPEDRIVENOVERRIDE.";
			}
			else if( m_enum == ENUM_QTO_OCCURRENCEDRIVEN )
			{
				stream << ".QTO_OCCURRENCEDRIVEN.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcPropertySetTemplateTypeEnum> IfcPropertySetTemplateTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPropertySetTemplateTypeEnum>(); }
			shared_ptr<IfcPropertySetTemplateTypeEnum> type_object( new IfcPropertySetTemplateTypeEnum() );
			if( _stricmp( arg.c_str(), ".PSET_TYPEDRIVENONLY." ) == 0 )
			{
				type_object->m_enum = IfcPropertySetTemplateTypeEnum::ENUM_PSET_TYPEDRIVENONLY;
			}
			else if( _stricmp( arg.c_str(), ".PSET_TYPEDRIVENOVERRIDE." ) == 0 )
			{
				type_object->m_enum = IfcPropertySetTemplateTypeEnum::ENUM_PSET_TYPEDRIVENOVERRIDE;
			}
			else if( _stricmp( arg.c_str(), ".PSET_OCCURRENCEDRIVEN." ) == 0 )
			{
				type_object->m_enum = IfcPropertySetTemplateTypeEnum::ENUM_PSET_OCCURRENCEDRIVEN;
			}
			else if( _stricmp( arg.c_str(), ".PSET_PERFORMANCEDRIVEN." ) == 0 )
			{
				type_object->m_enum = IfcPropertySetTemplateTypeEnum::ENUM_PSET_PERFORMANCEDRIVEN;
			}
			else if( _stricmp( arg.c_str(), ".QTO_TYPEDRIVENONLY." ) == 0 )
			{
				type_object->m_enum = IfcPropertySetTemplateTypeEnum::ENUM_QTO_TYPEDRIVENONLY;
			}
			else if( _stricmp( arg.c_str(), ".QTO_TYPEDRIVENOVERRIDE." ) == 0 )
			{
				type_object->m_enum = IfcPropertySetTemplateTypeEnum::ENUM_QTO_TYPEDRIVENOVERRIDE;
			}
			else if( _stricmp( arg.c_str(), ".QTO_OCCURRENCEDRIVEN." ) == 0 )
			{
				type_object->m_enum = IfcPropertySetTemplateTypeEnum::ENUM_QTO_OCCURRENCEDRIVEN;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPropertySetTemplateTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
