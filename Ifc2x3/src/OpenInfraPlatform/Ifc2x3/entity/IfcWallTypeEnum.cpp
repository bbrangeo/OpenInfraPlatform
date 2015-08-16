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
#include "include/IfcWallTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcWallTypeEnum 
		IfcWallTypeEnum::IfcWallTypeEnum() {}
		IfcWallTypeEnum::~IfcWallTypeEnum() {}
		void IfcWallTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWALLTYPEENUM("; }
			if( m_enum == ENUM_STANDARD )
			{
				stream << ".STANDARD.";
			}
			else if( m_enum == ENUM_POLYGONAL )
			{
				stream << ".POLYGONAL.";
			}
			else if( m_enum == ENUM_SHEAR )
			{
				stream << ".SHEAR.";
			}
			else if( m_enum == ENUM_ELEMENTEDWALL )
			{
				stream << ".ELEMENTEDWALL.";
			}
			else if( m_enum == ENUM_PLUMBINGWALL )
			{
				stream << ".PLUMBINGWALL.";
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
		shared_ptr<IfcWallTypeEnum> IfcWallTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWallTypeEnum>(); }
			shared_ptr<IfcWallTypeEnum> type_object( new IfcWallTypeEnum() );
			if( _stricmp( arg.c_str(), ".STANDARD." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_STANDARD;
			}
			else if( _stricmp( arg.c_str(), ".POLYGONAL." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_POLYGONAL;
			}
			else if( _stricmp( arg.c_str(), ".SHEAR." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_SHEAR;
			}
			else if( _stricmp( arg.c_str(), ".ELEMENTEDWALL." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_ELEMENTEDWALL;
			}
			else if( _stricmp( arg.c_str(), ".PLUMBINGWALL." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_PLUMBINGWALL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
