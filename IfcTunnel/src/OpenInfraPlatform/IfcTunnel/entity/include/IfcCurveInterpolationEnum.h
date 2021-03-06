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
		// TYPE IfcCurveInterpolationEnum = ENUMERATION OF	(LINEAR	,LOG_LINEAR	,LOG_LOG	,NOTDEFINED);
		class IfcCurveInterpolationEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcCurveInterpolationEnumEnum
			{
				ENUM_LINEAR,
				ENUM_LOG_LINEAR,
				ENUM_LOG_LOG,
				ENUM_NOTDEFINED
			};

			IfcCurveInterpolationEnum();
			IfcCurveInterpolationEnum( IfcCurveInterpolationEnumEnum e ) { m_enum = e; }
			~IfcCurveInterpolationEnum();
			virtual const char* classname() const { return "IfcCurveInterpolationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCurveInterpolationEnum> readStepData( std::string& arg );
			IfcCurveInterpolationEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

