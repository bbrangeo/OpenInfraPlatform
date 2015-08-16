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
#include "include/IfcTaskDurationEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcTaskDurationEnum 
		IfcTaskDurationEnum::IfcTaskDurationEnum() {}
		IfcTaskDurationEnum::~IfcTaskDurationEnum() {}
		void IfcTaskDurationEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTASKDURATIONENUM("; }
			if( m_enum == ENUM_ELAPSEDTIME )
			{
				stream << ".ELAPSEDTIME.";
			}
			else if( m_enum == ENUM_WORKTIME )
			{
				stream << ".WORKTIME.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcTaskDurationEnum> IfcTaskDurationEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTaskDurationEnum>(); }
			shared_ptr<IfcTaskDurationEnum> type_object( new IfcTaskDurationEnum() );
			if( _stricmp( arg.c_str(), ".ELAPSEDTIME." ) == 0 )
			{
				type_object->m_enum = IfcTaskDurationEnum::ENUM_ELAPSEDTIME;
			}
			else if( _stricmp( arg.c_str(), ".WORKTIME." ) == 0 )
			{
				type_object->m_enum = IfcTaskDurationEnum::ENUM_WORKTIME;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTaskDurationEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
