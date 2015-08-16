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
		// TYPE IfcDiscreteAccessoryTypeEnum = ENUMERATION OF	(ANCHORPLATE	,BRACKET	,SHOE	,USERDEFINED	,NOTDEFINED);
		class IfcDiscreteAccessoryTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcDiscreteAccessoryTypeEnumEnum
			{
				ENUM_ANCHORPLATE,
				ENUM_BRACKET,
				ENUM_SHOE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDiscreteAccessoryTypeEnum();
			IfcDiscreteAccessoryTypeEnum( IfcDiscreteAccessoryTypeEnumEnum e ) { m_enum = e; }
			~IfcDiscreteAccessoryTypeEnum();
			virtual const char* classname() const { return "IfcDiscreteAccessoryTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDiscreteAccessoryTypeEnum> readStepData( std::string& arg );
			IfcDiscreteAccessoryTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

