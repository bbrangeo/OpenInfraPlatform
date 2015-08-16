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
#include "include/IfcVoidingFeatureTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcVoidingFeatureTypeEnum 
		IfcVoidingFeatureTypeEnum::IfcVoidingFeatureTypeEnum() {}
		IfcVoidingFeatureTypeEnum::~IfcVoidingFeatureTypeEnum() {}
		void IfcVoidingFeatureTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCVOIDINGFEATURETYPEENUM("; }
			if( m_enum == ENUM_CUTOUT )
			{
				stream << ".CUTOUT.";
			}
			else if( m_enum == ENUM_NOTCH )
			{
				stream << ".NOTCH.";
			}
			else if( m_enum == ENUM_HOLE )
			{
				stream << ".HOLE.";
			}
			else if( m_enum == ENUM_MITER )
			{
				stream << ".MITER.";
			}
			else if( m_enum == ENUM_CHAMFER )
			{
				stream << ".CHAMFER.";
			}
			else if( m_enum == ENUM_EDGE )
			{
				stream << ".EDGE.";
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
		shared_ptr<IfcVoidingFeatureTypeEnum> IfcVoidingFeatureTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcVoidingFeatureTypeEnum>(); }
			shared_ptr<IfcVoidingFeatureTypeEnum> type_object( new IfcVoidingFeatureTypeEnum() );
			if( _stricmp( arg.c_str(), ".CUTOUT." ) == 0 )
			{
				type_object->m_enum = IfcVoidingFeatureTypeEnum::ENUM_CUTOUT;
			}
			else if( _stricmp( arg.c_str(), ".NOTCH." ) == 0 )
			{
				type_object->m_enum = IfcVoidingFeatureTypeEnum::ENUM_NOTCH;
			}
			else if( _stricmp( arg.c_str(), ".HOLE." ) == 0 )
			{
				type_object->m_enum = IfcVoidingFeatureTypeEnum::ENUM_HOLE;
			}
			else if( _stricmp( arg.c_str(), ".MITER." ) == 0 )
			{
				type_object->m_enum = IfcVoidingFeatureTypeEnum::ENUM_MITER;
			}
			else if( _stricmp( arg.c_str(), ".CHAMFER." ) == 0 )
			{
				type_object->m_enum = IfcVoidingFeatureTypeEnum::ENUM_CHAMFER;
			}
			else if( _stricmp( arg.c_str(), ".EDGE." ) == 0 )
			{
				type_object->m_enum = IfcVoidingFeatureTypeEnum::ENUM_EDGE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcVoidingFeatureTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcVoidingFeatureTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
