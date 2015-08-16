/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcConstructionProductResourceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcConstructionProductResourceTypeEnum 
		IfcConstructionProductResourceTypeEnum::IfcConstructionProductResourceTypeEnum() {}
		IfcConstructionProductResourceTypeEnum::~IfcConstructionProductResourceTypeEnum() {}
		void IfcConstructionProductResourceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCONSTRUCTIONPRODUCTRESOURCETYPEENUM("; }
			if( m_enum == ENUM_ASSEMBLY )
			{
				stream << ".ASSEMBLY.";
			}
			else if( m_enum == ENUM_FORMWORK )
			{
				stream << ".FORMWORK.";
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
		shared_ptr<IfcConstructionProductResourceTypeEnum> IfcConstructionProductResourceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcConstructionProductResourceTypeEnum>(); }
			shared_ptr<IfcConstructionProductResourceTypeEnum> type_object( new IfcConstructionProductResourceTypeEnum() );
			if( _stricmp( arg.c_str(), ".ASSEMBLY." ) == 0 )
			{
				type_object->m_enum = IfcConstructionProductResourceTypeEnum::ENUM_ASSEMBLY;
			}
			else if( _stricmp( arg.c_str(), ".FORMWORK." ) == 0 )
			{
				type_object->m_enum = IfcConstructionProductResourceTypeEnum::ENUM_FORMWORK;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcConstructionProductResourceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcConstructionProductResourceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
