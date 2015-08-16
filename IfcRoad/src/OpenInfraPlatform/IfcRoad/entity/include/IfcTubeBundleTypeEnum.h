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
		// TYPE IfcTubeBundleTypeEnum = ENUMERATION OF	(FINNED	,USERDEFINED	,NOTDEFINED);
		class IfcTubeBundleTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcTubeBundleTypeEnumEnum
			{
				ENUM_FINNED,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTubeBundleTypeEnum();
			IfcTubeBundleTypeEnum( IfcTubeBundleTypeEnumEnum e ) { m_enum = e; }
			~IfcTubeBundleTypeEnum();
			virtual const char* classname() const { return "IfcTubeBundleTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTubeBundleTypeEnum> readStepData( std::string& arg );
			IfcTubeBundleTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

