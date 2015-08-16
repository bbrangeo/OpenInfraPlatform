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
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcProfileTypeEnum 
		IfcProfileTypeEnum::IfcProfileTypeEnum() {}
		IfcProfileTypeEnum::~IfcProfileTypeEnum() {}
		void IfcProfileTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROFILETYPEENUM("; }
			if( m_enum == ENUM_CURVE )
			{
				stream << ".CURVE.";
			}
			else if( m_enum == ENUM_AREA )
			{
				stream << ".AREA.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcProfileTypeEnum> IfcProfileTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProfileTypeEnum>(); }
			shared_ptr<IfcProfileTypeEnum> type_object( new IfcProfileTypeEnum() );
			if( _stricmp( arg.c_str(), ".CURVE." ) == 0 )
			{
				type_object->m_enum = IfcProfileTypeEnum::ENUM_CURVE;
			}
			else if( _stricmp( arg.c_str(), ".AREA." ) == 0 )
			{
				type_object->m_enum = IfcProfileTypeEnum::ENUM_AREA;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
