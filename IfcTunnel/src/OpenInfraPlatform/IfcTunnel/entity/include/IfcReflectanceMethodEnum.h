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
		// TYPE IfcReflectanceMethodEnum = ENUMERATION OF	(BLINN	,FLAT	,GLASS	,MATT	,METAL	,MIRROR	,PHONG	,PLASTIC	,STRAUSS	,NOTDEFINED);
		class IfcReflectanceMethodEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcReflectanceMethodEnumEnum
			{
				ENUM_BLINN,
				ENUM_FLAT,
				ENUM_GLASS,
				ENUM_MATT,
				ENUM_METAL,
				ENUM_MIRROR,
				ENUM_PHONG,
				ENUM_PLASTIC,
				ENUM_STRAUSS,
				ENUM_NOTDEFINED
			};

			IfcReflectanceMethodEnum();
			IfcReflectanceMethodEnum( IfcReflectanceMethodEnumEnum e ) { m_enum = e; }
			~IfcReflectanceMethodEnum();
			virtual const char* classname() const { return "IfcReflectanceMethodEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcReflectanceMethodEnum> readStepData( std::string& arg );
			IfcReflectanceMethodEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

