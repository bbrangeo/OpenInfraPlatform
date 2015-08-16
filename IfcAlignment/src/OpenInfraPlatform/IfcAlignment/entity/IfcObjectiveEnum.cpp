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
#include "include/IfcObjectiveEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcObjectiveEnum 
		IfcObjectiveEnum::IfcObjectiveEnum() {}
		IfcObjectiveEnum::~IfcObjectiveEnum() {}
		void IfcObjectiveEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCOBJECTIVEENUM("; }
			if( m_enum == ENUM_CODECOMPLIANCE )
			{
				stream << ".CODECOMPLIANCE.";
			}
			else if( m_enum == ENUM_CODEWAIVER )
			{
				stream << ".CODEWAIVER.";
			}
			else if( m_enum == ENUM_DESIGNINTENT )
			{
				stream << ".DESIGNINTENT.";
			}
			else if( m_enum == ENUM_EXTERNAL )
			{
				stream << ".EXTERNAL.";
			}
			else if( m_enum == ENUM_HEALTHANDSAFETY )
			{
				stream << ".HEALTHANDSAFETY.";
			}
			else if( m_enum == ENUM_MERGECONFLICT )
			{
				stream << ".MERGECONFLICT.";
			}
			else if( m_enum == ENUM_MODELVIEW )
			{
				stream << ".MODELVIEW.";
			}
			else if( m_enum == ENUM_PARAMETER )
			{
				stream << ".PARAMETER.";
			}
			else if( m_enum == ENUM_REQUIREMENT )
			{
				stream << ".REQUIREMENT.";
			}
			else if( m_enum == ENUM_SPECIFICATION )
			{
				stream << ".SPECIFICATION.";
			}
			else if( m_enum == ENUM_TRIGGERCONDITION )
			{
				stream << ".TRIGGERCONDITION.";
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
		shared_ptr<IfcObjectiveEnum> IfcObjectiveEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcObjectiveEnum>(); }
			shared_ptr<IfcObjectiveEnum> type_object( new IfcObjectiveEnum() );
			if( _stricmp( arg.c_str(), ".CODECOMPLIANCE." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_CODECOMPLIANCE;
			}
			else if( _stricmp( arg.c_str(), ".CODEWAIVER." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_CODEWAIVER;
			}
			else if( _stricmp( arg.c_str(), ".DESIGNINTENT." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_DESIGNINTENT;
			}
			else if( _stricmp( arg.c_str(), ".EXTERNAL." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_EXTERNAL;
			}
			else if( _stricmp( arg.c_str(), ".HEALTHANDSAFETY." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_HEALTHANDSAFETY;
			}
			else if( _stricmp( arg.c_str(), ".MERGECONFLICT." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_MERGECONFLICT;
			}
			else if( _stricmp( arg.c_str(), ".MODELVIEW." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_MODELVIEW;
			}
			else if( _stricmp( arg.c_str(), ".PARAMETER." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_PARAMETER;
			}
			else if( _stricmp( arg.c_str(), ".REQUIREMENT." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_REQUIREMENT;
			}
			else if( _stricmp( arg.c_str(), ".SPECIFICATION." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_SPECIFICATION;
			}
			else if( _stricmp( arg.c_str(), ".TRIGGERCONDITION." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_TRIGGERCONDITION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcObjectiveEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
