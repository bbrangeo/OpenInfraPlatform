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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcSurfaceFeatureTypeEnum = ENUMERATION OF	(MARK	,TAG	,TREATMENT	,USERDEFINED	,NOTDEFINED);
		class IfcSurfaceFeatureTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

