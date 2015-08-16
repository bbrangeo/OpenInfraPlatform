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
#include "include/IfcLogicalOperatorEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
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
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
