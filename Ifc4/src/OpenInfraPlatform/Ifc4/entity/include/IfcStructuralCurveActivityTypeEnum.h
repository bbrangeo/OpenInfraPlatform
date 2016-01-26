/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcStructuralCurveActivityTypeEnum = ENUMERATION OF	(CONST	,LINEAR	,POLYGONAL	,EQUIDISTANT	,SINUS	,PARABOLA	,DISCRETE	,USERDEFINED	,NOTDEFINED);
		class IfcStructuralCurveActivityTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcStructuralCurveActivityTypeEnumEnum
			{
				ENUM_CONST,
				ENUM_LINEAR,
				ENUM_POLYGONAL,
				ENUM_EQUIDISTANT,
				ENUM_SINUS,
				ENUM_PARABOLA,
				ENUM_DISCRETE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcStructuralCurveActivityTypeEnum();
			IfcStructuralCurveActivityTypeEnum( IfcStructuralCurveActivityTypeEnumEnum e ) { m_enum = e; }
			~IfcStructuralCurveActivityTypeEnum();
			virtual const char* classname() const { return "IfcStructuralCurveActivityTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStructuralCurveActivityTypeEnum> readStepData( std::string& arg );
			IfcStructuralCurveActivityTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

