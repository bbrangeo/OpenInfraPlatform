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
#include "include/IfcDuctSegmentTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcDuctSegmentTypeEnum 
		IfcDuctSegmentTypeEnum::IfcDuctSegmentTypeEnum() {}
		IfcDuctSegmentTypeEnum::~IfcDuctSegmentTypeEnum() {}
		void IfcDuctSegmentTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDUCTSEGMENTTYPEENUM("; }
			if( m_enum == ENUM_RIGIDSEGMENT )
			{
				stream << ".RIGIDSEGMENT.";
			}
			else if( m_enum == ENUM_FLEXIBLESEGMENT )
			{
				stream << ".FLEXIBLESEGMENT.";
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
		shared_ptr<IfcDuctSegmentTypeEnum> IfcDuctSegmentTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDuctSegmentTypeEnum>(); }
			shared_ptr<IfcDuctSegmentTypeEnum> type_object( new IfcDuctSegmentTypeEnum() );
			if( _stricmp( arg.c_str(), ".RIGIDSEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcDuctSegmentTypeEnum::ENUM_RIGIDSEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".FLEXIBLESEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcDuctSegmentTypeEnum::ENUM_FLEXIBLESEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDuctSegmentTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDuctSegmentTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
