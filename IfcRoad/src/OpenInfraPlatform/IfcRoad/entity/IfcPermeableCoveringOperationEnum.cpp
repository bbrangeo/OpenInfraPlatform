/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcPermeableCoveringOperationEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPermeableCoveringOperationEnum 
		IfcPermeableCoveringOperationEnum::IfcPermeableCoveringOperationEnum() {}
		IfcPermeableCoveringOperationEnum::~IfcPermeableCoveringOperationEnum() {}
		void IfcPermeableCoveringOperationEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPERMEABLECOVERINGOPERATIONENUM("; }
			if( m_enum == ENUM_GRILL )
			{
				stream << ".GRILL.";
			}
			else if( m_enum == ENUM_LOUVER )
			{
				stream << ".LOUVER.";
			}
			else if( m_enum == ENUM_SCREEN )
			{
				stream << ".SCREEN.";
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
		shared_ptr<IfcPermeableCoveringOperationEnum> IfcPermeableCoveringOperationEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPermeableCoveringOperationEnum>(); }
			shared_ptr<IfcPermeableCoveringOperationEnum> type_object( new IfcPermeableCoveringOperationEnum() );
			if( _stricmp( arg.c_str(), ".GRILL." ) == 0 )
			{
				type_object->m_enum = IfcPermeableCoveringOperationEnum::ENUM_GRILL;
			}
			else if( _stricmp( arg.c_str(), ".LOUVER." ) == 0 )
			{
				type_object->m_enum = IfcPermeableCoveringOperationEnum::ENUM_LOUVER;
			}
			else if( _stricmp( arg.c_str(), ".SCREEN." ) == 0 )
			{
				type_object->m_enum = IfcPermeableCoveringOperationEnum::ENUM_SCREEN;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPermeableCoveringOperationEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPermeableCoveringOperationEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
