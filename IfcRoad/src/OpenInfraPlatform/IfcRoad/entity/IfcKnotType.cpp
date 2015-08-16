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
#include "include/IfcKnotType.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcKnotType 
		IfcKnotType::IfcKnotType() {}
		IfcKnotType::~IfcKnotType() {}
		void IfcKnotType::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCKNOTTYPE("; }
			if( m_enum == ENUM_UNIFORM_KNOTS )
			{
				stream << ".UNIFORM_KNOTS.";
			}
			else if( m_enum == ENUM_QUASI_UNIFORM_KNOTS )
			{
				stream << ".QUASI_UNIFORM_KNOTS.";
			}
			else if( m_enum == ENUM_PIECEWISE_BEZIER_KNOTS )
			{
				stream << ".PIECEWISE_BEZIER_KNOTS.";
			}
			else if( m_enum == ENUM_UNSPECIFIED )
			{
				stream << ".UNSPECIFIED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcKnotType> IfcKnotType::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcKnotType>(); }
			shared_ptr<IfcKnotType> type_object( new IfcKnotType() );
			if( _stricmp( arg.c_str(), ".UNIFORM_KNOTS." ) == 0 )
			{
				type_object->m_enum = IfcKnotType::ENUM_UNIFORM_KNOTS;
			}
			else if( _stricmp( arg.c_str(), ".QUASI_UNIFORM_KNOTS." ) == 0 )
			{
				type_object->m_enum = IfcKnotType::ENUM_QUASI_UNIFORM_KNOTS;
			}
			else if( _stricmp( arg.c_str(), ".PIECEWISE_BEZIER_KNOTS." ) == 0 )
			{
				type_object->m_enum = IfcKnotType::ENUM_PIECEWISE_BEZIER_KNOTS;
			}
			else if( _stricmp( arg.c_str(), ".UNSPECIFIED." ) == 0 )
			{
				type_object->m_enum = IfcKnotType::ENUM_UNSPECIFIED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
