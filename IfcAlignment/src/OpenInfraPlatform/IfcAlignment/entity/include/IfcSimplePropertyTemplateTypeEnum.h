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
		// TYPE IfcSimplePropertyTemplateTypeEnum = ENUMERATION OF	(P_SINGLEVALUE	,P_ENUMERATEDVALUE	,P_BOUNDEDVALUE	,P_LISTVALUE	,P_TABLEVALUE	,P_REFERENCEVALUE	,Q_LENGTH	,Q_AREA	,Q_VOLUME	,Q_COUNT	,Q_WEIGHT	,Q_TIME);
		class IfcSimplePropertyTemplateTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcSimplePropertyTemplateTypeEnumEnum
			{
				ENUM_P_SINGLEVALUE,
				ENUM_P_ENUMERATEDVALUE,
				ENUM_P_BOUNDEDVALUE,
				ENUM_P_LISTVALUE,
				ENUM_P_TABLEVALUE,
				ENUM_P_REFERENCEVALUE,
				ENUM_Q_LENGTH,
				ENUM_Q_AREA,
				ENUM_Q_VOLUME,
				ENUM_Q_COUNT,
				ENUM_Q_WEIGHT,
				ENUM_Q_TIME
			};

			IfcSimplePropertyTemplateTypeEnum();
			IfcSimplePropertyTemplateTypeEnum( IfcSimplePropertyTemplateTypeEnumEnum e ) { m_enum = e; }
			~IfcSimplePropertyTemplateTypeEnum();
			virtual const char* classname() const { return "IfcSimplePropertyTemplateTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSimplePropertyTemplateTypeEnum> readStepData( std::string& arg );
			IfcSimplePropertyTemplateTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

