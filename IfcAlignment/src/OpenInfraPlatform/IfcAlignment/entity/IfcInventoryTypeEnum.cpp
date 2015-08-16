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
#include "include/IfcInventoryTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcInventoryTypeEnum 
		IfcInventoryTypeEnum::IfcInventoryTypeEnum() {}
		IfcInventoryTypeEnum::~IfcInventoryTypeEnum() {}
		void IfcInventoryTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCINVENTORYTYPEENUM("; }
			if( m_enum == ENUM_ASSETINVENTORY )
			{
				stream << ".ASSETINVENTORY.";
			}
			else if( m_enum == ENUM_SPACEINVENTORY )
			{
				stream << ".SPACEINVENTORY.";
			}
			else if( m_enum == ENUM_FURNITUREINVENTORY )
			{
				stream << ".FURNITUREINVENTORY.";
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
		shared_ptr<IfcInventoryTypeEnum> IfcInventoryTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcInventoryTypeEnum>(); }
			shared_ptr<IfcInventoryTypeEnum> type_object( new IfcInventoryTypeEnum() );
			if( _stricmp( arg.c_str(), ".ASSETINVENTORY." ) == 0 )
			{
				type_object->m_enum = IfcInventoryTypeEnum::ENUM_ASSETINVENTORY;
			}
			else if( _stricmp( arg.c_str(), ".SPACEINVENTORY." ) == 0 )
			{
				type_object->m_enum = IfcInventoryTypeEnum::ENUM_SPACEINVENTORY;
			}
			else if( _stricmp( arg.c_str(), ".FURNITUREINVENTORY." ) == 0 )
			{
				type_object->m_enum = IfcInventoryTypeEnum::ENUM_FURNITUREINVENTORY;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcInventoryTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcInventoryTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
