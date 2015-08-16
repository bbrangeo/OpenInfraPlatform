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
#include "include/IfcAnalysisModelTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcAnalysisModelTypeEnum 
		IfcAnalysisModelTypeEnum::IfcAnalysisModelTypeEnum() {}
		IfcAnalysisModelTypeEnum::~IfcAnalysisModelTypeEnum() {}
		void IfcAnalysisModelTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCANALYSISMODELTYPEENUM("; }
			if( m_enum == ENUM_IN_PLANE_LOADING_2D )
			{
				stream << ".IN_PLANE_LOADING_2D.";
			}
			else if( m_enum == ENUM_OUT_PLANE_LOADING_2D )
			{
				stream << ".OUT_PLANE_LOADING_2D.";
			}
			else if( m_enum == ENUM_LOADING_3D )
			{
				stream << ".LOADING_3D.";
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
		shared_ptr<IfcAnalysisModelTypeEnum> IfcAnalysisModelTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAnalysisModelTypeEnum>(); }
			shared_ptr<IfcAnalysisModelTypeEnum> type_object( new IfcAnalysisModelTypeEnum() );
			if( _stricmp( arg.c_str(), ".IN_PLANE_LOADING_2D." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisModelTypeEnum::ENUM_IN_PLANE_LOADING_2D;
			}
			else if( _stricmp( arg.c_str(), ".OUT_PLANE_LOADING_2D." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisModelTypeEnum::ENUM_OUT_PLANE_LOADING_2D;
			}
			else if( _stricmp( arg.c_str(), ".LOADING_3D." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisModelTypeEnum::ENUM_LOADING_3D;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisModelTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisModelTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
