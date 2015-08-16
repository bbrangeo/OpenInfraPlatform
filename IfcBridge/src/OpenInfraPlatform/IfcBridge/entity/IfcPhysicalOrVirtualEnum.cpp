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
#include "include/IfcPhysicalOrVirtualEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcPhysicalOrVirtualEnum 
		IfcPhysicalOrVirtualEnum::IfcPhysicalOrVirtualEnum() {}
		IfcPhysicalOrVirtualEnum::~IfcPhysicalOrVirtualEnum() {}
		void IfcPhysicalOrVirtualEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPHYSICALORVIRTUALENUM("; }
			if( m_enum == ENUM_PHYSICAL )
			{
				stream << ".PHYSICAL.";
			}
			else if( m_enum == ENUM_VIRTUAL )
			{
				stream << ".VIRTUAL.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcPhysicalOrVirtualEnum> IfcPhysicalOrVirtualEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPhysicalOrVirtualEnum>(); }
			shared_ptr<IfcPhysicalOrVirtualEnum> type_object( new IfcPhysicalOrVirtualEnum() );
			if( _stricmp( arg.c_str(), ".PHYSICAL." ) == 0 )
			{
				type_object->m_enum = IfcPhysicalOrVirtualEnum::ENUM_PHYSICAL;
			}
			else if( _stricmp( arg.c_str(), ".VIRTUAL." ) == 0 )
			{
				type_object->m_enum = IfcPhysicalOrVirtualEnum::ENUM_VIRTUAL;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPhysicalOrVirtualEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
