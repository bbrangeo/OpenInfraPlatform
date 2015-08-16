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
#include "include/IfcCurveInterpolationEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcCurveInterpolationEnum 
		IfcCurveInterpolationEnum::IfcCurveInterpolationEnum() {}
		IfcCurveInterpolationEnum::~IfcCurveInterpolationEnum() {}
		void IfcCurveInterpolationEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCURVEINTERPOLATIONENUM("; }
			if( m_enum == ENUM_LINEAR )
			{
				stream << ".LINEAR.";
			}
			else if( m_enum == ENUM_LOG_LINEAR )
			{
				stream << ".LOG_LINEAR.";
			}
			else if( m_enum == ENUM_LOG_LOG )
			{
				stream << ".LOG_LOG.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcCurveInterpolationEnum> IfcCurveInterpolationEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCurveInterpolationEnum>(); }
			shared_ptr<IfcCurveInterpolationEnum> type_object( new IfcCurveInterpolationEnum() );
			if( _stricmp( arg.c_str(), ".LINEAR." ) == 0 )
			{
				type_object->m_enum = IfcCurveInterpolationEnum::ENUM_LINEAR;
			}
			else if( _stricmp( arg.c_str(), ".LOG_LINEAR." ) == 0 )
			{
				type_object->m_enum = IfcCurveInterpolationEnum::ENUM_LOG_LINEAR;
			}
			else if( _stricmp( arg.c_str(), ".LOG_LOG." ) == 0 )
			{
				type_object->m_enum = IfcCurveInterpolationEnum::ENUM_LOG_LOG;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCurveInterpolationEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
