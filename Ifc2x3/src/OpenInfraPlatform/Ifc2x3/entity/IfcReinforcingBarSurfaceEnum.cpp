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
#include "include/IfcReinforcingBarSurfaceEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcReinforcingBarSurfaceEnum 
		IfcReinforcingBarSurfaceEnum::IfcReinforcingBarSurfaceEnum() {}
		IfcReinforcingBarSurfaceEnum::~IfcReinforcingBarSurfaceEnum() {}
		void IfcReinforcingBarSurfaceEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCREINFORCINGBARSURFACEENUM("; }
			if( m_enum == ENUM_PLAIN )
			{
				stream << ".PLAIN.";
			}
			else if( m_enum == ENUM_TEXTURED )
			{
				stream << ".TEXTURED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcReinforcingBarSurfaceEnum> IfcReinforcingBarSurfaceEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcReinforcingBarSurfaceEnum>(); }
			shared_ptr<IfcReinforcingBarSurfaceEnum> type_object( new IfcReinforcingBarSurfaceEnum() );
			if( _stricmp( arg.c_str(), ".PLAIN." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarSurfaceEnum::ENUM_PLAIN;
			}
			else if( _stricmp( arg.c_str(), ".TEXTURED." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarSurfaceEnum::ENUM_TEXTURED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
