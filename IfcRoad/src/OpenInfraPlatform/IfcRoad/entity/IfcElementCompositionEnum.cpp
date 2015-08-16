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
#include "include/IfcElementCompositionEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcElementCompositionEnum 
		IfcElementCompositionEnum::IfcElementCompositionEnum() {}
		IfcElementCompositionEnum::~IfcElementCompositionEnum() {}
		void IfcElementCompositionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELEMENTCOMPOSITIONENUM("; }
			if( m_enum == ENUM_COMPLEX )
			{
				stream << ".COMPLEX.";
			}
			else if( m_enum == ENUM_ELEMENT )
			{
				stream << ".ELEMENT.";
			}
			else if( m_enum == ENUM_PARTIAL )
			{
				stream << ".PARTIAL.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcElementCompositionEnum> IfcElementCompositionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElementCompositionEnum>(); }
			shared_ptr<IfcElementCompositionEnum> type_object( new IfcElementCompositionEnum() );
			if( _stricmp( arg.c_str(), ".COMPLEX." ) == 0 )
			{
				type_object->m_enum = IfcElementCompositionEnum::ENUM_COMPLEX;
			}
			else if( _stricmp( arg.c_str(), ".ELEMENT." ) == 0 )
			{
				type_object->m_enum = IfcElementCompositionEnum::ENUM_ELEMENT;
			}
			else if( _stricmp( arg.c_str(), ".PARTIAL." ) == 0 )
			{
				type_object->m_enum = IfcElementCompositionEnum::ENUM_PARTIAL;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
