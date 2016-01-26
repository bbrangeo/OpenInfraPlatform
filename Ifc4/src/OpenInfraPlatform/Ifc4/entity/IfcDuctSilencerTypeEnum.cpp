/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcDuctSilencerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcDuctSilencerTypeEnum 
		IfcDuctSilencerTypeEnum::IfcDuctSilencerTypeEnum() {}
		IfcDuctSilencerTypeEnum::~IfcDuctSilencerTypeEnum() {}
		void IfcDuctSilencerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDUCTSILENCERTYPEENUM("; }
			if( m_enum == ENUM_FLATOVAL )
			{
				stream << ".FLATOVAL.";
			}
			else if( m_enum == ENUM_RECTANGULAR )
			{
				stream << ".RECTANGULAR.";
			}
			else if( m_enum == ENUM_ROUND )
			{
				stream << ".ROUND.";
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
		shared_ptr<IfcDuctSilencerTypeEnum> IfcDuctSilencerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDuctSilencerTypeEnum>(); }
			shared_ptr<IfcDuctSilencerTypeEnum> type_object( new IfcDuctSilencerTypeEnum() );
			if( _stricmp( arg.c_str(), ".FLATOVAL." ) == 0 )
			{
				type_object->m_enum = IfcDuctSilencerTypeEnum::ENUM_FLATOVAL;
			}
			else if( _stricmp( arg.c_str(), ".RECTANGULAR." ) == 0 )
			{
				type_object->m_enum = IfcDuctSilencerTypeEnum::ENUM_RECTANGULAR;
			}
			else if( _stricmp( arg.c_str(), ".ROUND." ) == 0 )
			{
				type_object->m_enum = IfcDuctSilencerTypeEnum::ENUM_ROUND;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDuctSilencerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDuctSilencerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
