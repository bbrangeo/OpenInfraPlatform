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
#include "include/IfcStructuralSurfaceActivityTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcStructuralSurfaceActivityTypeEnum 
		IfcStructuralSurfaceActivityTypeEnum::IfcStructuralSurfaceActivityTypeEnum() {}
		IfcStructuralSurfaceActivityTypeEnum::~IfcStructuralSurfaceActivityTypeEnum() {}
		void IfcStructuralSurfaceActivityTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTRUCTURALSURFACEACTIVITYTYPEENUM("; }
			if( m_enum == ENUM_CONST )
			{
				stream << ".CONST.";
			}
			else if( m_enum == ENUM_BILINEAR )
			{
				stream << ".BILINEAR.";
			}
			else if( m_enum == ENUM_DISCRETE )
			{
				stream << ".DISCRETE.";
			}
			else if( m_enum == ENUM_ISOCONTOUR )
			{
				stream << ".ISOCONTOUR.";
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
		shared_ptr<IfcStructuralSurfaceActivityTypeEnum> IfcStructuralSurfaceActivityTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStructuralSurfaceActivityTypeEnum>(); }
			shared_ptr<IfcStructuralSurfaceActivityTypeEnum> type_object( new IfcStructuralSurfaceActivityTypeEnum() );
			if( _stricmp( arg.c_str(), ".CONST." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceActivityTypeEnum::ENUM_CONST;
			}
			else if( _stricmp( arg.c_str(), ".BILINEAR." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceActivityTypeEnum::ENUM_BILINEAR;
			}
			else if( _stricmp( arg.c_str(), ".DISCRETE." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceActivityTypeEnum::ENUM_DISCRETE;
			}
			else if( _stricmp( arg.c_str(), ".ISOCONTOUR." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceActivityTypeEnum::ENUM_ISOCONTOUR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceActivityTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceActivityTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
