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
		// TYPE IfcSurfaceFeatureTypeEnum = ENUMERATION OF	(MARK	,TAG	,TREATMENT	,USERDEFINED	,NOTDEFINED);
		class IfcSurfaceFeatureTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcSurfaceFeatureTypeEnumEnum
			{
				ENUM_MARK,
				ENUM_TAG,
				ENUM_TREATMENT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSurfaceFeatureTypeEnum();
			IfcSurfaceFeatureTypeEnum( IfcSurfaceFeatureTypeEnumEnum e ) { m_enum = e; }
			~IfcSurfaceFeatureTypeEnum();
			virtual const char* classname() const { return "IfcSurfaceFeatureTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSurfaceFeatureTypeEnum> readStepData( std::string& arg );
			IfcSurfaceFeatureTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

