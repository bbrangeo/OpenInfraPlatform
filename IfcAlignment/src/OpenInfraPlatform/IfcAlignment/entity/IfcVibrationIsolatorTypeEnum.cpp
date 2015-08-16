/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcVibrationIsolatorTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcVibrationIsolatorTypeEnum 
		IfcVibrationIsolatorTypeEnum::IfcVibrationIsolatorTypeEnum() {}
		IfcVibrationIsolatorTypeEnum::~IfcVibrationIsolatorTypeEnum() {}
		void IfcVibrationIsolatorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCVIBRATIONISOLATORTYPEENUM("; }
			if( m_enum == ENUM_COMPRESSION )
			{
				stream << ".COMPRESSION.";
			}
			else if( m_enum == ENUM_SPRING )
			{
				stream << ".SPRING.";
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
		shared_ptr<IfcVibrationIsolatorTypeEnum> IfcVibrationIsolatorTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcVibrationIsolatorTypeEnum>(); }
			shared_ptr<IfcVibrationIsolatorTypeEnum> type_object( new IfcVibrationIsolatorTypeEnum() );
			if( _stricmp( arg.c_str(), ".COMPRESSION." ) == 0 )
			{
				type_object->m_enum = IfcVibrationIsolatorTypeEnum::ENUM_COMPRESSION;
			}
			else if( _stricmp( arg.c_str(), ".SPRING." ) == 0 )
			{
				type_object->m_enum = IfcVibrationIsolatorTypeEnum::ENUM_SPRING;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcVibrationIsolatorTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcVibrationIsolatorTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
