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
#include "include/IfcConstructionMaterialResourceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcConstructionMaterialResourceTypeEnum 
		IfcConstructionMaterialResourceTypeEnum::IfcConstructionMaterialResourceTypeEnum() {}
		IfcConstructionMaterialResourceTypeEnum::~IfcConstructionMaterialResourceTypeEnum() {}
		void IfcConstructionMaterialResourceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCONSTRUCTIONMATERIALRESOURCETYPEENUM("; }
			if( m_enum == ENUM_AGGREGATES )
			{
				stream << ".AGGREGATES.";
			}
			else if( m_enum == ENUM_CONCRETE )
			{
				stream << ".CONCRETE.";
			}
			else if( m_enum == ENUM_DRYWALL )
			{
				stream << ".DRYWALL.";
			}
			else if( m_enum == ENUM_FUEL )
			{
				stream << ".FUEL.";
			}
			else if( m_enum == ENUM_GYPSUM )
			{
				stream << ".GYPSUM.";
			}
			else if( m_enum == ENUM_MASONRY )
			{
				stream << ".MASONRY.";
			}
			else if( m_enum == ENUM_METAL )
			{
				stream << ".METAL.";
			}
			else if( m_enum == ENUM_PLASTIC )
			{
				stream << ".PLASTIC.";
			}
			else if( m_enum == ENUM_WOOD )
			{
				stream << ".WOOD.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcConstructionMaterialResourceTypeEnum> IfcConstructionMaterialResourceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcConstructionMaterialResourceTypeEnum>(); }
			shared_ptr<IfcConstructionMaterialResourceTypeEnum> type_object( new IfcConstructionMaterialResourceTypeEnum() );
			if( _stricmp( arg.c_str(), ".AGGREGATES." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_AGGREGATES;
			}
			else if( _stricmp( arg.c_str(), ".CONCRETE." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_CONCRETE;
			}
			else if( _stricmp( arg.c_str(), ".DRYWALL." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_DRYWALL;
			}
			else if( _stricmp( arg.c_str(), ".FUEL." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_FUEL;
			}
			else if( _stricmp( arg.c_str(), ".GYPSUM." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_GYPSUM;
			}
			else if( _stricmp( arg.c_str(), ".MASONRY." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_MASONRY;
			}
			else if( _stricmp( arg.c_str(), ".METAL." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_METAL;
			}
			else if( _stricmp( arg.c_str(), ".PLASTIC." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_PLASTIC;
			}
			else if( _stricmp( arg.c_str(), ".WOOD." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_WOOD;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_NOTDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcConstructionMaterialResourceTypeEnum::ENUM_USERDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
