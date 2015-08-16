/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../model/IfcBridgeException.h"
#include "include/IfcLayerSetDirectionEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcLayerSetDirectionEnum 
		IfcLayerSetDirectionEnum::IfcLayerSetDirectionEnum() {}
		IfcLayerSetDirectionEnum::~IfcLayerSetDirectionEnum() {}
		void IfcLayerSetDirectionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCLAYERSETDIRECTIONENUM("; }
			if( m_enum == ENUM_AXIS1 )
			{
				stream << ".AXIS1.";
			}
			else if( m_enum == ENUM_AXIS2 )
			{
				stream << ".AXIS2.";
			}
			else if( m_enum == ENUM_AXIS3 )
			{
				stream << ".AXIS3.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcLayerSetDirectionEnum> IfcLayerSetDirectionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLayerSetDirectionEnum>(); }
			shared_ptr<IfcLayerSetDirectionEnum> type_object( new IfcLayerSetDirectionEnum() );
			if( _stricmp( arg.c_str(), ".AXIS1." ) == 0 )
			{
				type_object->m_enum = IfcLayerSetDirectionEnum::ENUM_AXIS1;
			}
			else if( _stricmp( arg.c_str(), ".AXIS2." ) == 0 )
			{
				type_object->m_enum = IfcLayerSetDirectionEnum::ENUM_AXIS2;
			}
			else if( _stricmp( arg.c_str(), ".AXIS3." ) == 0 )
			{
				type_object->m_enum = IfcLayerSetDirectionEnum::ENUM_AXIS3;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
