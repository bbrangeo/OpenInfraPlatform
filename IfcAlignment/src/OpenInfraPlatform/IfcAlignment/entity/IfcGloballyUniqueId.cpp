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
#include "include/IfcGloballyUniqueId.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcGloballyUniqueId 
		IfcGloballyUniqueId::IfcGloballyUniqueId() {}
		IfcGloballyUniqueId::IfcGloballyUniqueId( std::string value ) { m_value = value; }
		IfcGloballyUniqueId::~IfcGloballyUniqueId() {}
		void IfcGloballyUniqueId::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCGLOBALLYUNIQUEID("; }
			//supertype as attribute: std::string m_value
			stream << "'" << encodeStepString( m_value ) << "'";
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcGloballyUniqueId> IfcGloballyUniqueId::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcGloballyUniqueId>(); }
			shared_ptr<IfcGloballyUniqueId> type_object( new IfcGloballyUniqueId() );
			//supertype as attribute: std::string m_value
			type_object->m_value = arg;
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
