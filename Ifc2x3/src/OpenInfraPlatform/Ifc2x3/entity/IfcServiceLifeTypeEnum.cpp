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
#include "include/IfcServiceLifeTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcServiceLifeTypeEnum 
		IfcServiceLifeTypeEnum::IfcServiceLifeTypeEnum() {}
		IfcServiceLifeTypeEnum::~IfcServiceLifeTypeEnum() {}
		void IfcServiceLifeTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSERVICELIFETYPEENUM("; }
			if( m_enum == ENUM_ACTUALSERVICELIFE )
			{
				stream << ".ACTUALSERVICELIFE.";
			}
			else if( m_enum == ENUM_EXPECTEDSERVICELIFE )
			{
				stream << ".EXPECTEDSERVICELIFE.";
			}
			else if( m_enum == ENUM_OPTIMISTICREFERENCESERVICELIFE )
			{
				stream << ".OPTIMISTICREFERENCESERVICELIFE.";
			}
			else if( m_enum == ENUM_PESSIMISTICREFERENCESERVICELIFE )
			{
				stream << ".PESSIMISTICREFERENCESERVICELIFE.";
			}
			else if( m_enum == ENUM_REFERENCESERVICELIFE )
			{
				stream << ".REFERENCESERVICELIFE.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcServiceLifeTypeEnum> IfcServiceLifeTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcServiceLifeTypeEnum>(); }
			shared_ptr<IfcServiceLifeTypeEnum> type_object( new IfcServiceLifeTypeEnum() );
			if( _stricmp( arg.c_str(), ".ACTUALSERVICELIFE." ) == 0 )
			{
				type_object->m_enum = IfcServiceLifeTypeEnum::ENUM_ACTUALSERVICELIFE;
			}
			else if( _stricmp( arg.c_str(), ".EXPECTEDSERVICELIFE." ) == 0 )
			{
				type_object->m_enum = IfcServiceLifeTypeEnum::ENUM_EXPECTEDSERVICELIFE;
			}
			else if( _stricmp( arg.c_str(), ".OPTIMISTICREFERENCESERVICELIFE." ) == 0 )
			{
				type_object->m_enum = IfcServiceLifeTypeEnum::ENUM_OPTIMISTICREFERENCESERVICELIFE;
			}
			else if( _stricmp( arg.c_str(), ".PESSIMISTICREFERENCESERVICELIFE." ) == 0 )
			{
				type_object->m_enum = IfcServiceLifeTypeEnum::ENUM_PESSIMISTICREFERENCESERVICELIFE;
			}
			else if( _stricmp( arg.c_str(), ".REFERENCESERVICELIFE." ) == 0 )
			{
				type_object->m_enum = IfcServiceLifeTypeEnum::ENUM_REFERENCESERVICELIFE;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
