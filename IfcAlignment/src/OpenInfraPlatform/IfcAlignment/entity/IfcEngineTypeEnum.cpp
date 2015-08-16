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
#include "include/IfcEngineTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcEngineTypeEnum 
		IfcEngineTypeEnum::IfcEngineTypeEnum() {}
		IfcEngineTypeEnum::~IfcEngineTypeEnum() {}
		void IfcEngineTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCENGINETYPEENUM("; }
			if( m_enum == ENUM_EXTERNALCOMBUSTION )
			{
				stream << ".EXTERNALCOMBUSTION.";
			}
			else if( m_enum == ENUM_INTERNALCOMBUSTION )
			{
				stream << ".INTERNALCOMBUSTION.";
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
		shared_ptr<IfcEngineTypeEnum> IfcEngineTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcEngineTypeEnum>(); }
			shared_ptr<IfcEngineTypeEnum> type_object( new IfcEngineTypeEnum() );
			if( _stricmp( arg.c_str(), ".EXTERNALCOMBUSTION." ) == 0 )
			{
				type_object->m_enum = IfcEngineTypeEnum::ENUM_EXTERNALCOMBUSTION;
			}
			else if( _stricmp( arg.c_str(), ".INTERNALCOMBUSTION." ) == 0 )
			{
				type_object->m_enum = IfcEngineTypeEnum::ENUM_INTERNALCOMBUSTION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEngineTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEngineTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
