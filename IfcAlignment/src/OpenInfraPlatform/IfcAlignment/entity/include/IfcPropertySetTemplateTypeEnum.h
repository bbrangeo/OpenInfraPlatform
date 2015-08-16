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
		// TYPE IfcPropertySetTemplateTypeEnum = ENUMERATION OF	(PSET_TYPEDRIVENONLY	,PSET_TYPEDRIVENOVERRIDE	,PSET_OCCURRENCEDRIVEN	,PSET_PERFORMANCEDRIVEN	,QTO_TYPEDRIVENONLY	,QTO_TYPEDRIVENOVERRIDE	,QTO_OCCURRENCEDRIVEN	,NOTDEFINED);
		class IfcPropertySetTemplateTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcPropertySetTemplateTypeEnumEnum
			{
				ENUM_PSET_TYPEDRIVENONLY,
				ENUM_PSET_TYPEDRIVENOVERRIDE,
				ENUM_PSET_OCCURRENCEDRIVEN,
				ENUM_PSET_PERFORMANCEDRIVEN,
				ENUM_QTO_TYPEDRIVENONLY,
				ENUM_QTO_TYPEDRIVENOVERRIDE,
				ENUM_QTO_OCCURRENCEDRIVEN,
				ENUM_NOTDEFINED
			};

			IfcPropertySetTemplateTypeEnum();
			IfcPropertySetTemplateTypeEnum( IfcPropertySetTemplateTypeEnumEnum e ) { m_enum = e; }
			~IfcPropertySetTemplateTypeEnum();
			virtual const char* classname() const { return "IfcPropertySetTemplateTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPropertySetTemplateTypeEnum> readStepData( std::string& arg );
			IfcPropertySetTemplateTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

