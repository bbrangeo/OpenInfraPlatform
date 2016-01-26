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
#include "include/IfcBinary.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcBinary 
		IfcBinary::IfcBinary() {}
		IfcBinary::IfcBinary( const char* value ) { m_value = value; }
		IfcBinary::~IfcBinary() {}
		void IfcBinary::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBINARY("; }
			//supertype as attribute: const char* m_value
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcBinary> IfcBinary::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBinary>(); }
			shared_ptr<IfcBinary> type_object( new IfcBinary() );
			//supertype as attribute: const char* m_value
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
