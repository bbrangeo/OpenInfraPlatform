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
#include "include/IfcSectionTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcSectionTypeEnum 
		IfcSectionTypeEnum::IfcSectionTypeEnum() {}
		IfcSectionTypeEnum::~IfcSectionTypeEnum() {}
		void IfcSectionTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSECTIONTYPEENUM("; }
			if( m_enum == ENUM_UNIFORM )
			{
				stream << ".UNIFORM.";
			}
			else if( m_enum == ENUM_TAPERED )
			{
				stream << ".TAPERED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcSectionTypeEnum> IfcSectionTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSectionTypeEnum>(); }
			shared_ptr<IfcSectionTypeEnum> type_object( new IfcSectionTypeEnum() );
			if( _stricmp( arg.c_str(), ".UNIFORM." ) == 0 )
			{
				type_object->m_enum = IfcSectionTypeEnum::ENUM_UNIFORM;
			}
			else if( _stricmp( arg.c_str(), ".TAPERED." ) == 0 )
			{
				type_object->m_enum = IfcSectionTypeEnum::ENUM_TAPERED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
