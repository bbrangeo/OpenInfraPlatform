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
#include "include/IfcBeamTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcBeamTypeEnum 
		IfcBeamTypeEnum::IfcBeamTypeEnum() {}
		IfcBeamTypeEnum::~IfcBeamTypeEnum() {}
		void IfcBeamTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBEAMTYPEENUM("; }
			if( m_enum == ENUM_BEAM )
			{
				stream << ".BEAM.";
			}
			else if( m_enum == ENUM_JOIST )
			{
				stream << ".JOIST.";
			}
			else if( m_enum == ENUM_LINTEL )
			{
				stream << ".LINTEL.";
			}
			else if( m_enum == ENUM_T_BEAM )
			{
				stream << ".T_BEAM.";
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
		shared_ptr<IfcBeamTypeEnum> IfcBeamTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBeamTypeEnum>(); }
			shared_ptr<IfcBeamTypeEnum> type_object( new IfcBeamTypeEnum() );
			if( _stricmp( arg.c_str(), ".BEAM." ) == 0 )
			{
				type_object->m_enum = IfcBeamTypeEnum::ENUM_BEAM;
			}
			else if( _stricmp( arg.c_str(), ".JOIST." ) == 0 )
			{
				type_object->m_enum = IfcBeamTypeEnum::ENUM_JOIST;
			}
			else if( _stricmp( arg.c_str(), ".LINTEL." ) == 0 )
			{
				type_object->m_enum = IfcBeamTypeEnum::ENUM_LINTEL;
			}
			else if( _stricmp( arg.c_str(), ".T_BEAM." ) == 0 )
			{
				type_object->m_enum = IfcBeamTypeEnum::ENUM_T_BEAM;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBeamTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBeamTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
