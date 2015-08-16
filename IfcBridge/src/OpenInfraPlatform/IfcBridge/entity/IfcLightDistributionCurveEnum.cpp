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
#include "include/IfcLightDistributionCurveEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcLightDistributionCurveEnum 
		IfcLightDistributionCurveEnum::IfcLightDistributionCurveEnum() {}
		IfcLightDistributionCurveEnum::~IfcLightDistributionCurveEnum() {}
		void IfcLightDistributionCurveEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCLIGHTDISTRIBUTIONCURVEENUM("; }
			if( m_enum == ENUM_TYPE_A )
			{
				stream << ".TYPE_A.";
			}
			else if( m_enum == ENUM_TYPE_B )
			{
				stream << ".TYPE_B.";
			}
			else if( m_enum == ENUM_TYPE_C )
			{
				stream << ".TYPE_C.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcLightDistributionCurveEnum> IfcLightDistributionCurveEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLightDistributionCurveEnum>(); }
			shared_ptr<IfcLightDistributionCurveEnum> type_object( new IfcLightDistributionCurveEnum() );
			if( _stricmp( arg.c_str(), ".TYPE_A." ) == 0 )
			{
				type_object->m_enum = IfcLightDistributionCurveEnum::ENUM_TYPE_A;
			}
			else if( _stricmp( arg.c_str(), ".TYPE_B." ) == 0 )
			{
				type_object->m_enum = IfcLightDistributionCurveEnum::ENUM_TYPE_B;
			}
			else if( _stricmp( arg.c_str(), ".TYPE_C." ) == 0 )
			{
				type_object->m_enum = IfcLightDistributionCurveEnum::ENUM_TYPE_C;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcLightDistributionCurveEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
