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
#include "include/IfcStructuralCurveActivityTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcStructuralCurveActivityTypeEnum 
		IfcStructuralCurveActivityTypeEnum::IfcStructuralCurveActivityTypeEnum() {}
		IfcStructuralCurveActivityTypeEnum::~IfcStructuralCurveActivityTypeEnum() {}
		void IfcStructuralCurveActivityTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTRUCTURALCURVEACTIVITYTYPEENUM("; }
			if( m_enum == ENUM_CONST )
			{
				stream << ".CONST.";
			}
			else if( m_enum == ENUM_LINEAR )
			{
				stream << ".LINEAR.";
			}
			else if( m_enum == ENUM_POLYGONAL )
			{
				stream << ".POLYGONAL.";
			}
			else if( m_enum == ENUM_EQUIDISTANT )
			{
				stream << ".EQUIDISTANT.";
			}
			else if( m_enum == ENUM_SINUS )
			{
				stream << ".SINUS.";
			}
			else if( m_enum == ENUM_PARABOLA )
			{
				stream << ".PARABOLA.";
			}
			else if( m_enum == ENUM_DISCRETE )
			{
				stream << ".DISCRETE.";
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
		shared_ptr<IfcStructuralCurveActivityTypeEnum> IfcStructuralCurveActivityTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStructuralCurveActivityTypeEnum>(); }
			shared_ptr<IfcStructuralCurveActivityTypeEnum> type_object( new IfcStructuralCurveActivityTypeEnum() );
			if( _stricmp( arg.c_str(), ".CONST." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveActivityTypeEnum::ENUM_CONST;
			}
			else if( _stricmp( arg.c_str(), ".LINEAR." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveActivityTypeEnum::ENUM_LINEAR;
			}
			else if( _stricmp( arg.c_str(), ".POLYGONAL." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveActivityTypeEnum::ENUM_POLYGONAL;
			}
			else if( _stricmp( arg.c_str(), ".EQUIDISTANT." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveActivityTypeEnum::ENUM_EQUIDISTANT;
			}
			else if( _stricmp( arg.c_str(), ".SINUS." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveActivityTypeEnum::ENUM_SINUS;
			}
			else if( _stricmp( arg.c_str(), ".PARABOLA." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveActivityTypeEnum::ENUM_PARABOLA;
			}
			else if( _stricmp( arg.c_str(), ".DISCRETE." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveActivityTypeEnum::ENUM_DISCRETE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveActivityTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralCurveActivityTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
