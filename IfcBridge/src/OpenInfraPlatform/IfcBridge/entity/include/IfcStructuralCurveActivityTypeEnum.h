/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcStructuralCurveActivityTypeEnum = ENUMERATION OF	(CONST	,LINEAR	,POLYGONAL	,EQUIDISTANT	,SINUS	,PARABOLA	,DISCRETE	,USERDEFINED	,NOTDEFINED);
		class IfcStructuralCurveActivityTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

