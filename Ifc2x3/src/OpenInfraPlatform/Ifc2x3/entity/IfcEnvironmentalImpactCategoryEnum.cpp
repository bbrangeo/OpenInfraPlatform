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
#include "include/IfcEnvironmentalImpactCategoryEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcEnvironmentalImpactCategoryEnum 
		IfcEnvironmentalImpactCategoryEnum::IfcEnvironmentalImpactCategoryEnum() {}
		IfcEnvironmentalImpactCategoryEnum::~IfcEnvironmentalImpactCategoryEnum() {}
		void IfcEnvironmentalImpactCategoryEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCENVIRONMENTALIMPACTCATEGORYENUM("; }
			if( m_enum == ENUM_COMBINEDVALUE )
			{
				stream << ".COMBINEDVALUE.";
			}
			else if( m_enum == ENUM_DISPOSAL )
			{
				stream << ".DISPOSAL.";
			}
			else if( m_enum == ENUM_EXTRACTION )
			{
				stream << ".EXTRACTION.";
			}
			else if( m_enum == ENUM_INSTALLATION )
			{
				stream << ".INSTALLATION.";
			}
			else if( m_enum == ENUM_MANUFACTURE )
			{
				stream << ".MANUFACTURE.";
			}
			else if( m_enum == ENUM_TRANSPORTATION )
			{
				stream << ".TRANSPORTATION.";
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
		shared_ptr<IfcEnvironmentalImpactCategoryEnum> IfcEnvironmentalImpactCategoryEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcEnvironmentalImpactCategoryEnum>(); }
			shared_ptr<IfcEnvironmentalImpactCategoryEnum> type_object( new IfcEnvironmentalImpactCategoryEnum() );
			if( _stricmp( arg.c_str(), ".COMBINEDVALUE." ) == 0 )
			{
				type_object->m_enum = IfcEnvironmentalImpactCategoryEnum::ENUM_COMBINEDVALUE;
			}
			else if( _stricmp( arg.c_str(), ".DISPOSAL." ) == 0 )
			{
				type_object->m_enum = IfcEnvironmentalImpactCategoryEnum::ENUM_DISPOSAL;
			}
			else if( _stricmp( arg.c_str(), ".EXTRACTION." ) == 0 )
			{
				type_object->m_enum = IfcEnvironmentalImpactCategoryEnum::ENUM_EXTRACTION;
			}
			else if( _stricmp( arg.c_str(), ".INSTALLATION." ) == 0 )
			{
				type_object->m_enum = IfcEnvironmentalImpactCategoryEnum::ENUM_INSTALLATION;
			}
			else if( _stricmp( arg.c_str(), ".MANUFACTURE." ) == 0 )
			{
				type_object->m_enum = IfcEnvironmentalImpactCategoryEnum::ENUM_MANUFACTURE;
			}
			else if( _stricmp( arg.c_str(), ".TRANSPORTATION." ) == 0 )
			{
				type_object->m_enum = IfcEnvironmentalImpactCategoryEnum::ENUM_TRANSPORTATION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEnvironmentalImpactCategoryEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEnvironmentalImpactCategoryEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
