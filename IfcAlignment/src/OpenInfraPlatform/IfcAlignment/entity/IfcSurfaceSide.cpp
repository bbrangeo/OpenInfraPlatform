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
#include "include/IfcSurfaceSide.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcSurfaceSide 
		IfcSurfaceSide::IfcSurfaceSide() {}
		IfcSurfaceSide::~IfcSurfaceSide() {}
		void IfcSurfaceSide::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSURFACESIDE("; }
			if( m_enum == ENUM_POSITIVE )
			{
				stream << ".POSITIVE.";
			}
			else if( m_enum == ENUM_NEGATIVE )
			{
				stream << ".NEGATIVE.";
			}
			else if( m_enum == ENUM_BOTH )
			{
				stream << ".BOTH.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcSurfaceSide> IfcSurfaceSide::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSurfaceSide>(); }
			shared_ptr<IfcSurfaceSide> type_object( new IfcSurfaceSide() );
			if( _stricmp( arg.c_str(), ".POSITIVE." ) == 0 )
			{
				type_object->m_enum = IfcSurfaceSide::ENUM_POSITIVE;
			}
			else if( _stricmp( arg.c_str(), ".NEGATIVE." ) == 0 )
			{
				type_object->m_enum = IfcSurfaceSide::ENUM_NEGATIVE;
			}
			else if( _stricmp( arg.c_str(), ".BOTH." ) == 0 )
			{
				type_object->m_enum = IfcSurfaceSide::ENUM_BOTH;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
