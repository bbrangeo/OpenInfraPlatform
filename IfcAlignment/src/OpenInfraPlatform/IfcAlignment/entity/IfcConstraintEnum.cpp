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
#include "include/IfcConstraintEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcConstraintEnum 
		IfcConstraintEnum::IfcConstraintEnum() {}
		IfcConstraintEnum::~IfcConstraintEnum() {}
		void IfcConstraintEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCONSTRAINTENUM("; }
			if( m_enum == ENUM_HARD )
			{
				stream << ".HARD.";
			}
			else if( m_enum == ENUM_SOFT )
			{
				stream << ".SOFT.";
			}
			else if( m_enum == ENUM_ADVISORY )
			{
				stream << ".ADVISORY.";
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
		shared_ptr<IfcConstraintEnum> IfcConstraintEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcConstraintEnum>(); }
			shared_ptr<IfcConstraintEnum> type_object( new IfcConstraintEnum() );
			if( _stricmp( arg.c_str(), ".HARD." ) == 0 )
			{
				type_object->m_enum = IfcConstraintEnum::ENUM_HARD;
			}
			else if( _stricmp( arg.c_str(), ".SOFT." ) == 0 )
			{
				type_object->m_enum = IfcConstraintEnum::ENUM_SOFT;
			}
			else if( _stricmp( arg.c_str(), ".ADVISORY." ) == 0 )
			{
				type_object->m_enum = IfcConstraintEnum::ENUM_ADVISORY;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcConstraintEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcConstraintEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
