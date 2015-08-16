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
#include "include/IfcBridgeMechanicalRoleType.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcBridgeMechanicalRoleType 
		IfcBridgeMechanicalRoleType::IfcBridgeMechanicalRoleType() {}
		IfcBridgeMechanicalRoleType::~IfcBridgeMechanicalRoleType() {}
		void IfcBridgeMechanicalRoleType::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBRIDGEMECHANICALROLETYPE("; }
			if( m_enum == ENUM_LONGITUDINAL )
			{
				stream << ".LONGITUDINAL.";
			}
			else if( m_enum == ENUM_TRANSVERSAL )
			{
				stream << ".TRANSVERSAL.";
			}
			else if( m_enum == ENUM_COMPLETE )
			{
				stream << ".COMPLETE.";
			}
			else if( m_enum == ENUM_NONE )
			{
				stream << ".NONE.";
			}
			else if( m_enum == ENUM_UNDEFINED )
			{
				stream << ".UNDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcBridgeMechanicalRoleType> IfcBridgeMechanicalRoleType::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBridgeMechanicalRoleType>(); }
			shared_ptr<IfcBridgeMechanicalRoleType> type_object( new IfcBridgeMechanicalRoleType() );
			if( _stricmp( arg.c_str(), ".LONGITUDINAL." ) == 0 )
			{
				type_object->m_enum = IfcBridgeMechanicalRoleType::ENUM_LONGITUDINAL;
			}
			else if( _stricmp( arg.c_str(), ".TRANSVERSAL." ) == 0 )
			{
				type_object->m_enum = IfcBridgeMechanicalRoleType::ENUM_TRANSVERSAL;
			}
			else if( _stricmp( arg.c_str(), ".COMPLETE." ) == 0 )
			{
				type_object->m_enum = IfcBridgeMechanicalRoleType::ENUM_COMPLETE;
			}
			else if( _stricmp( arg.c_str(), ".NONE." ) == 0 )
			{
				type_object->m_enum = IfcBridgeMechanicalRoleType::ENUM_NONE;
			}
			else if( _stricmp( arg.c_str(), ".UNDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBridgeMechanicalRoleType::ENUM_UNDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
