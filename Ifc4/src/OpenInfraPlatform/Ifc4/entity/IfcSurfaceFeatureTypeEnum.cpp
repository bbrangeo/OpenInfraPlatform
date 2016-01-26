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
#include "include/IfcSurfaceFeatureTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcSurfaceFeatureTypeEnum 
		IfcSurfaceFeatureTypeEnum::IfcSurfaceFeatureTypeEnum() {}
		IfcSurfaceFeatureTypeEnum::~IfcSurfaceFeatureTypeEnum() {}
		void IfcSurfaceFeatureTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSURFACEFEATURETYPEENUM("; }
			if( m_enum == ENUM_MARK )
			{
				stream << ".MARK.";
			}
			else if( m_enum == ENUM_TAG )
			{
				stream << ".TAG.";
			}
			else if( m_enum == ENUM_TREATMENT )
			{
				stream << ".TREATMENT.";
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
		shared_ptr<IfcSurfaceFeatureTypeEnum> IfcSurfaceFeatureTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSurfaceFeatureTypeEnum>(); }
			shared_ptr<IfcSurfaceFeatureTypeEnum> type_object( new IfcSurfaceFeatureTypeEnum() );
			if( _stricmp( arg.c_str(), ".MARK." ) == 0 )
			{
				type_object->m_enum = IfcSurfaceFeatureTypeEnum::ENUM_MARK;
			}
			else if( _stricmp( arg.c_str(), ".TAG." ) == 0 )
			{
				type_object->m_enum = IfcSurfaceFeatureTypeEnum::ENUM_TAG;
			}
			else if( _stricmp( arg.c_str(), ".TREATMENT." ) == 0 )
			{
				type_object->m_enum = IfcSurfaceFeatureTypeEnum::ENUM_TREATMENT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSurfaceFeatureTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSurfaceFeatureTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
