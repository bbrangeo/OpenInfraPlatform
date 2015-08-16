/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcKnotType.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
