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
		// TYPE IfcAnalysisTheoryTypeEnum = ENUMERATION OF	(FIRST_ORDER_THEORY	,SECOND_ORDER_THEORY	,THIRD_ORDER_THEORY	,FULL_NONLINEAR_THEORY	,USERDEFINED	,NOTDEFINED);
		class IfcAnalysisTheoryTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

