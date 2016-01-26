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
#include "include/IfcSimplePropertyTemplateTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcSimplePropertyTemplateTypeEnum 
		IfcSimplePropertyTemplateTypeEnum::IfcSimplePropertyTemplateTypeEnum() {}
		IfcSimplePropertyTemplateTypeEnum::~IfcSimplePropertyTemplateTypeEnum() {}
		void IfcSimplePropertyTemplateTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSIMPLEPROPERTYTEMPLATETYPEENUM("; }
			if( m_enum == ENUM_P_SINGLEVALUE )
			{
				stream << ".P_SINGLEVALUE.";
			}
			else if( m_enum == ENUM_P_ENUMERATEDVALUE )
			{
				stream << ".P_ENUMERATEDVALUE.";
			}
			else if( m_enum == ENUM_P_BOUNDEDVALUE )
			{
				stream << ".P_BOUNDEDVALUE.";
			}
			else if( m_enum == ENUM_P_LISTVALUE )
			{
				stream << ".P_LISTVALUE.";
			}
			else if( m_enum == ENUM_P_TABLEVALUE )
			{
				stream << ".P_TABLEVALUE.";
			}
			else if( m_enum == ENUM_P_REFERENCEVALUE )
			{
				stream << ".P_REFERENCEVALUE.";
			}
			else if( m_enum == ENUM_Q_LENGTH )
			{
				stream << ".Q_LENGTH.";
			}
			else if( m_enum == ENUM_Q_AREA )
			{
				stream << ".Q_AREA.";
			}
			else if( m_enum == ENUM_Q_VOLUME )
			{
				stream << ".Q_VOLUME.";
			}
			else if( m_enum == ENUM_Q_COUNT )
			{
				stream << ".Q_COUNT.";
			}
			else if( m_enum == ENUM_Q_WEIGHT )
			{
				stream << ".Q_WEIGHT.";
			}
			else if( m_enum == ENUM_Q_TIME )
			{
				stream << ".Q_TIME.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcSimplePropertyTemplateTypeEnum> IfcSimplePropertyTemplateTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSimplePropertyTemplateTypeEnum>(); }
			shared_ptr<IfcSimplePropertyTemplateTypeEnum> type_object( new IfcSimplePropertyTemplateTypeEnum() );
			if( _stricmp( arg.c_str(), ".P_SINGLEVALUE." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_SINGLEVALUE;
			}
			else if( _stricmp( arg.c_str(), ".P_ENUMERATEDVALUE." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_ENUMERATEDVALUE;
			}
			else if( _stricmp( arg.c_str(), ".P_BOUNDEDVALUE." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_BOUNDEDVALUE;
			}
			else if( _stricmp( arg.c_str(), ".P_LISTVALUE." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_LISTVALUE;
			}
			else if( _stricmp( arg.c_str(), ".P_TABLEVALUE." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_TABLEVALUE;
			}
			else if( _stricmp( arg.c_str(), ".P_REFERENCEVALUE." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_P_REFERENCEVALUE;
			}
			else if( _stricmp( arg.c_str(), ".Q_LENGTH." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_LENGTH;
			}
			else if( _stricmp( arg.c_str(), ".Q_AREA." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_AREA;
			}
			else if( _stricmp( arg.c_str(), ".Q_VOLUME." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_VOLUME;
			}
			else if( _stricmp( arg.c_str(), ".Q_COUNT." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_COUNT;
			}
			else if( _stricmp( arg.c_str(), ".Q_WEIGHT." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_WEIGHT;
			}
			else if( _stricmp( arg.c_str(), ".Q_TIME." ) == 0 )
			{
				type_object->m_enum = IfcSimplePropertyTemplateTypeEnum::ENUM_Q_TIME;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
