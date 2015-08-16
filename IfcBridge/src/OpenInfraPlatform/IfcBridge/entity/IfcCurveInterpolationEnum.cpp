/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../model/IfcBridgeException.h"
#include "include/IfcCurveInterpolationEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
