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
#include "include/IfcBinary.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
