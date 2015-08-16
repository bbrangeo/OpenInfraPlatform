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
#include "include/IfcBridgeStructureIndicator.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcBridgeStructureIndicator 
		IfcBridgeStructureIndicator::IfcBridgeStructureIndicator() {}
		IfcBridgeStructureIndicator::~IfcBridgeStructureIndicator() {}
		void IfcBridgeStructureIndicator::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBRIDGESTRUCTUREINDICATOR("; }
			if( m_enum == ENUM_COMPOSITE )
			{
				stream << ".COMPOSITE.";
			}
			else if( m_enum == ENUM_COATED )
			{
				stream << ".COATED.";
			}
			else if( m_enum == ENUM_HOMOGENEOUS )
			{
				stream << ".HOMOGENEOUS.";
			}
			else if( m_enum == ENUM_OTHER )
			{
				stream << ".OTHER.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcBridgeStructureIndicator> IfcBridgeStructureIndicator::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBridgeStructureIndicator>(); }
			shared_ptr<IfcBridgeStructureIndicator> type_object( new IfcBridgeStructureIndicator() );
			if( _stricmp( arg.c_str(), ".COMPOSITE." ) == 0 )
			{
				type_object->m_enum = IfcBridgeStructureIndicator::ENUM_COMPOSITE;
			}
			else if( _stricmp( arg.c_str(), ".COATED." ) == 0 )
			{
				type_object->m_enum = IfcBridgeStructureIndicator::ENUM_COATED;
			}
			else if( _stricmp( arg.c_str(), ".HOMOGENEOUS." ) == 0 )
			{
				type_object->m_enum = IfcBridgeStructureIndicator::ENUM_HOMOGENEOUS;
			}
			else if( _stricmp( arg.c_str(), ".OTHER." ) == 0 )
			{
				type_object->m_enum = IfcBridgeStructureIndicator::ENUM_OTHER;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
