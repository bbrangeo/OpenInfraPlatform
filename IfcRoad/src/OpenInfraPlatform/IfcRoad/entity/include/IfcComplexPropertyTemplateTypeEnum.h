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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcComplexPropertyTemplateTypeEnum = ENUMERATION OF	(P_COMPLEX	,Q_COMPLEX);
		class IfcComplexPropertyTemplateTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcComplexPropertyTemplateTypeEnumEnum
			{
				ENUM_P_COMPLEX,
				ENUM_Q_COMPLEX
			};

			IfcComplexPropertyTemplateTypeEnum();
			IfcComplexPropertyTemplateTypeEnum( IfcComplexPropertyTemplateTypeEnumEnum e ) { m_enum = e; }
			~IfcComplexPropertyTemplateTypeEnum();
			virtual const char* classname() const { return "IfcComplexPropertyTemplateTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcComplexPropertyTemplateTypeEnum> readStepData( std::string& arg );
			IfcComplexPropertyTemplateTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

