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
#include "include/IfcBridgeContactType.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcBridgeContactType 
		IfcBridgeContactType::IfcBridgeContactType() {}
		IfcBridgeContactType::~IfcBridgeContactType() {}
		void IfcBridgeContactType::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBRIDGECONTACTTYPE("; }
			if( m_enum == ENUM_GLUE )
			{
				stream << ".GLUE.";
			}
			else if( m_enum == ENUM_RIVET )
			{
				stream << ".RIVET.";
			}
			else if( m_enum == ENUM_CONNECTOR )
			{
				stream << ".CONNECTOR.";
			}
			else if( m_enum == ENUM_WELD )
			{
				stream << ".WELD.";
			}
			else if( m_enum == ENUM_RESUMPTION_OF_CONCRETE )
			{
				stream << ".RESUMPTION_OF_CONCRETE.";
			}
			else if( m_enum == ENUM_SLIDING )
			{
				stream << ".SLIDING.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcBridgeContactType> IfcBridgeContactType::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBridgeContactType>(); }
			shared_ptr<IfcBridgeContactType> type_object( new IfcBridgeContactType() );
			if( _stricmp( arg.c_str(), ".GLUE." ) == 0 )
			{
				type_object->m_enum = IfcBridgeContactType::ENUM_GLUE;
			}
			else if( _stricmp( arg.c_str(), ".RIVET." ) == 0 )
			{
				type_object->m_enum = IfcBridgeContactType::ENUM_RIVET;
			}
			else if( _stricmp( arg.c_str(), ".CONNECTOR." ) == 0 )
			{
				type_object->m_enum = IfcBridgeContactType::ENUM_CONNECTOR;
			}
			else if( _stricmp( arg.c_str(), ".WELD." ) == 0 )
			{
				type_object->m_enum = IfcBridgeContactType::ENUM_WELD;
			}
			else if( _stricmp( arg.c_str(), ".RESUMPTION_OF_CONCRETE." ) == 0 )
			{
				type_object->m_enum = IfcBridgeContactType::ENUM_RESUMPTION_OF_CONCRETE;
			}
			else if( _stricmp( arg.c_str(), ".SLIDING." ) == 0 )
			{
				type_object->m_enum = IfcBridgeContactType::ENUM_SLIDING;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
