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
#include "include/IfcTrimmingPreference.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcTrimmingPreference 
		IfcTrimmingPreference::IfcTrimmingPreference() {}
		IfcTrimmingPreference::~IfcTrimmingPreference() {}
		void IfcTrimmingPreference::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTRIMMINGPREFERENCE("; }
			if( m_enum == ENUM_CARTESIAN )
			{
				stream << ".CARTESIAN.";
			}
			else if( m_enum == ENUM_PARAMETER )
			{
				stream << ".PARAMETER.";
			}
			else if( m_enum == ENUM_UNSPECIFIED )
			{
				stream << ".UNSPECIFIED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcTrimmingPreference> IfcTrimmingPreference::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTrimmingPreference>(); }
			shared_ptr<IfcTrimmingPreference> type_object( new IfcTrimmingPreference() );
			if( _stricmp( arg.c_str(), ".CARTESIAN." ) == 0 )
			{
				type_object->m_enum = IfcTrimmingPreference::ENUM_CARTESIAN;
			}
			else if( _stricmp( arg.c_str(), ".PARAMETER." ) == 0 )
			{
				type_object->m_enum = IfcTrimmingPreference::ENUM_PARAMETER;
			}
			else if( _stricmp( arg.c_str(), ".UNSPECIFIED." ) == 0 )
			{
				type_object->m_enum = IfcTrimmingPreference::ENUM_UNSPECIFIED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
