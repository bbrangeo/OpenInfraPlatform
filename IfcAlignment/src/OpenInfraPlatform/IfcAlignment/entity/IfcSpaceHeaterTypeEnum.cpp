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
#include "include/IfcSpaceHeaterTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcSpaceHeaterTypeEnum 
		IfcSpaceHeaterTypeEnum::IfcSpaceHeaterTypeEnum() {}
		IfcSpaceHeaterTypeEnum::~IfcSpaceHeaterTypeEnum() {}
		void IfcSpaceHeaterTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSPACEHEATERTYPEENUM("; }
			if( m_enum == ENUM_CONVECTOR )
			{
				stream << ".CONVECTOR.";
			}
			else if( m_enum == ENUM_RADIATOR )
			{
				stream << ".RADIATOR.";
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
		shared_ptr<IfcSpaceHeaterTypeEnum> IfcSpaceHeaterTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSpaceHeaterTypeEnum>(); }
			shared_ptr<IfcSpaceHeaterTypeEnum> type_object( new IfcSpaceHeaterTypeEnum() );
			if( _stricmp( arg.c_str(), ".CONVECTOR." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_CONVECTOR;
			}
			else if( _stricmp( arg.c_str(), ".RADIATOR." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_RADIATOR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
