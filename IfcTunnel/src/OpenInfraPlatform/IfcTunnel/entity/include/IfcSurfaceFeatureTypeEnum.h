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
		// TYPE IfcSurfaceFeatureTypeEnum = ENUMERATION OF	(MARK	,TAG	,TREATMENT	,USERDEFINED	,NOTDEFINED);
		class IfcSurfaceFeatureTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

