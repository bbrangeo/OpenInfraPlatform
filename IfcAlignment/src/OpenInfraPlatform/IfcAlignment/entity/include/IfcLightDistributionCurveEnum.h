/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcLightDistributionCurveEnum = ENUMERATION OF	(TYPE_A	,TYPE_B	,TYPE_C	,NOTDEFINED);
		class IfcLightDistributionCurveEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcLightDistributionCurveEnumEnum
			{
				ENUM_TYPE_A,
				ENUM_TYPE_B,
				ENUM_TYPE_C,
				ENUM_NOTDEFINED
			};

			IfcLightDistributionCurveEnum();
			IfcLightDistributionCurveEnum( IfcLightDistributionCurveEnumEnum e ) { m_enum = e; }
			~IfcLightDistributionCurveEnum();
			virtual const char* classname() const { return "IfcLightDistributionCurveEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLightDistributionCurveEnum> readStepData( std::string& arg );
			IfcLightDistributionCurveEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

