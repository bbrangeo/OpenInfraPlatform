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
#include "include/IfcRibPlateDirectionEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcRibPlateDirectionEnum 
		IfcRibPlateDirectionEnum::IfcRibPlateDirectionEnum() {}
		IfcRibPlateDirectionEnum::~IfcRibPlateDirectionEnum() {}
		void IfcRibPlateDirectionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCRIBPLATEDIRECTIONENUM("; }
			if( m_enum == ENUM_DIRECTION_X )
			{
				stream << ".DIRECTION_X.";
			}
			else if( m_enum == ENUM_DIRECTION_Y )
			{
				stream << ".DIRECTION_Y.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcRibPlateDirectionEnum> IfcRibPlateDirectionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcRibPlateDirectionEnum>(); }
			shared_ptr<IfcRibPlateDirectionEnum> type_object( new IfcRibPlateDirectionEnum() );
			if( _stricmp( arg.c_str(), ".DIRECTION_X." ) == 0 )
			{
				type_object->m_enum = IfcRibPlateDirectionEnum::ENUM_DIRECTION_X;
			}
			else if( _stricmp( arg.c_str(), ".DIRECTION_Y." ) == 0 )
			{
				type_object->m_enum = IfcRibPlateDirectionEnum::ENUM_DIRECTION_Y;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
