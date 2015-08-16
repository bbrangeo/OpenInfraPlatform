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
		// TYPE IfcAnalysisTheoryTypeEnum = ENUMERATION OF	(FIRST_ORDER_THEORY	,SECOND_ORDER_THEORY	,THIRD_ORDER_THEORY	,FULL_NONLINEAR_THEORY	,USERDEFINED	,NOTDEFINED);
		class IfcAnalysisTheoryTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcAnalysisTheoryTypeEnumEnum
			{
				ENUM_FIRST_ORDER_THEORY,
				ENUM_SECOND_ORDER_THEORY,
				ENUM_THIRD_ORDER_THEORY,
				ENUM_FULL_NONLINEAR_THEORY,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAnalysisTheoryTypeEnum();
			IfcAnalysisTheoryTypeEnum( IfcAnalysisTheoryTypeEnumEnum e ) { m_enum = e; }
			~IfcAnalysisTheoryTypeEnum();
			virtual const char* classname() const { return "IfcAnalysisTheoryTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAnalysisTheoryTypeEnum> readStepData( std::string& arg );
			IfcAnalysisTheoryTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

