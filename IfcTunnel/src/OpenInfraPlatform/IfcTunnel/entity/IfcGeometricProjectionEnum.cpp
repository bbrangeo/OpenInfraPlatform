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
#include "include/IfcGeometricProjectionEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcGeometricProjectionEnum 
		IfcGeometricProjectionEnum::IfcGeometricProjectionEnum() {}
		IfcGeometricProjectionEnum::~IfcGeometricProjectionEnum() {}
		void IfcGeometricProjectionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCGEOMETRICPROJECTIONENUM("; }
			if( m_enum == ENUM_GRAPH_VIEW )
			{
				stream << ".GRAPH_VIEW.";
			}
			else if( m_enum == ENUM_SKETCH_VIEW )
			{
				stream << ".SKETCH_VIEW.";
			}
			else if( m_enum == ENUM_MODEL_VIEW )
			{
				stream << ".MODEL_VIEW.";
			}
			else if( m_enum == ENUM_PLAN_VIEW )
			{
				stream << ".PLAN_VIEW.";
			}
			else if( m_enum == ENUM_REFLECTED_PLAN_VIEW )
			{
				stream << ".REFLECTED_PLAN_VIEW.";
			}
			else if( m_enum == ENUM_SECTION_VIEW )
			{
				stream << ".SECTION_VIEW.";
			}
			else if( m_enum == ENUM_ELEVATION_VIEW )
			{
				stream << ".ELEVATION_VIEW.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcGeometricProjectionEnum> IfcGeometricProjectionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcGeometricProjectionEnum>(); }
			shared_ptr<IfcGeometricProjectionEnum> type_object( new IfcGeometricProjectionEnum() );
			if( _stricmp( arg.c_str(), ".GRAPH_VIEW." ) == 0 )
			{
				type_object->m_enum = IfcGeometricProjectionEnum::ENUM_GRAPH_VIEW;
			}
			else if( _stricmp( arg.c_str(), ".SKETCH_VIEW." ) == 0 )
			{
				type_object->m_enum = IfcGeometricProjectionEnum::ENUM_SKETCH_VIEW;
			}
			else if( _stricmp( arg.c_str(), ".MODEL_VIEW." ) == 0 )
			{
				type_object->m_enum = IfcGeometricProjectionEnum::ENUM_MODEL_VIEW;
			}
			else if( _stricmp( arg.c_str(), ".PLAN_VIEW." ) == 0 )
			{
				type_object->m_enum = IfcGeometricProjectionEnum::ENUM_PLAN_VIEW;
			}
			else if( _stricmp( arg.c_str(), ".REFLECTED_PLAN_VIEW." ) == 0 )
			{
				type_object->m_enum = IfcGeometricProjectionEnum::ENUM_REFLECTED_PLAN_VIEW;
			}
			else if( _stricmp( arg.c_str(), ".SECTION_VIEW." ) == 0 )
			{
				type_object->m_enum = IfcGeometricProjectionEnum::ENUM_SECTION_VIEW;
			}
			else if( _stricmp( arg.c_str(), ".ELEVATION_VIEW." ) == 0 )
			{
				type_object->m_enum = IfcGeometricProjectionEnum::ENUM_ELEVATION_VIEW;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcGeometricProjectionEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcGeometricProjectionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
