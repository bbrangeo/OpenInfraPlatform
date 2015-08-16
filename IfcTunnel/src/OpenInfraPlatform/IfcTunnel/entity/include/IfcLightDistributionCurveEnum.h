/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcLightDistributionCurveEnum = ENUMERATION OF	(TYPE_A	,TYPE_B	,TYPE_C	,NOTDEFINED);
		class IfcLightDistributionCurveEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

