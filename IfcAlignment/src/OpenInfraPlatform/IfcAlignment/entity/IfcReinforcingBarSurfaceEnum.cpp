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
#include "include/IfcReinforcingBarSurfaceEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
