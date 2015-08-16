/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../model/IfcBridgeException.h"
#include "include/IfcPresentationStyleSelect.h"
#include "include/IfcNullStyle.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcNullStyle 
		IfcNullStyle::IfcNullStyle() {}
		IfcNullStyle::~IfcNullStyle() {}
		void IfcNullStyle::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCNULLSTYLE("; }
			if( m_enum == ENUM_ENUM_NULL )
			{
				stream << ".ENUM_NULL.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcNullStyle> IfcNullStyle::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcNullStyle>(); }
			shared_ptr<IfcNullStyle> type_object( new IfcNullStyle() );
			if( _stricmp( arg.c_str(), ".ENUM_NULL." ) == 0 )
			{
				type_object->m_enum = IfcNullStyle::ENUM_ENUM_NULL;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
