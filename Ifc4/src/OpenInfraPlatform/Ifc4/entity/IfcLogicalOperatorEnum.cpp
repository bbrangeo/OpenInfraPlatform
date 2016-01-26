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
#include "include/IfcLogicalOperatorEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcLogicalOperatorEnum 
		IfcLogicalOperatorEnum::IfcLogicalOperatorEnum() {}
		IfcLogicalOperatorEnum::~IfcLogicalOperatorEnum() {}
		void IfcLogicalOperatorEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCLOGICALOPERATORENUM("; }
			if( m_enum == ENUM_LOGICALAND )
			{
				stream << ".LOGICALAND.";
			}
			else if( m_enum == ENUM_LOGICALOR )
			{
				stream << ".LOGICALOR.";
			}
			else if( m_enum == ENUM_LOGICALXOR )
			{
				stream << ".LOGICALXOR.";
			}
			else if( m_enum == ENUM_LOGICALNOTAND )
			{
				stream << ".LOGICALNOTAND.";
			}
			else if( m_enum == ENUM_LOGICALNOTOR )
			{
				stream << ".LOGICALNOTOR.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcLogicalOperatorEnum> IfcLogicalOperatorEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLogicalOperatorEnum>(); }
			shared_ptr<IfcLogicalOperatorEnum> type_object( new IfcLogicalOperatorEnum() );
			if( _stricmp( arg.c_str(), ".LOGICALAND." ) == 0 )
			{
				type_object->m_enum = IfcLogicalOperatorEnum::ENUM_LOGICALAND;
			}
			else if( _stricmp( arg.c_str(), ".LOGICALOR." ) == 0 )
			{
				type_object->m_enum = IfcLogicalOperatorEnum::ENUM_LOGICALOR;
			}
			else if( _stricmp( arg.c_str(), ".LOGICALXOR." ) == 0 )
			{
				type_object->m_enum = IfcLogicalOperatorEnum::ENUM_LOGICALXOR;
			}
			else if( _stricmp( arg.c_str(), ".LOGICALNOTAND." ) == 0 )
			{
				type_object->m_enum = IfcLogicalOperatorEnum::ENUM_LOGICALNOTAND;
			}
			else if( _stricmp( arg.c_str(), ".LOGICALNOTOR." ) == 0 )
			{
				type_object->m_enum = IfcLogicalOperatorEnum::ENUM_LOGICALNOTOR;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
