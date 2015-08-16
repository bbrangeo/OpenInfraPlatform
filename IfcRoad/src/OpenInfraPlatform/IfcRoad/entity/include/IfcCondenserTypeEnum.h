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
		// TYPE IfcCondenserTypeEnum = ENUMERATION OF	(AIRCOOLED	,EVAPORATIVECOOLED	,WATERCOOLED	,WATERCOOLEDBRAZEDPLATE	,WATERCOOLEDSHELLCOIL	,WATERCOOLEDSHELLTUBE	,WATERCOOLEDTUBEINTUBE	,USERDEFINED	,NOTDEFINED);
		class IfcCondenserTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcCondenserTypeEnumEnum
			{
				ENUM_AIRCOOLED,
				ENUM_EVAPORATIVECOOLED,
				ENUM_WATERCOOLED,
				ENUM_WATERCOOLEDBRAZEDPLATE,
				ENUM_WATERCOOLEDSHELLCOIL,
				ENUM_WATERCOOLEDSHELLTUBE,
				ENUM_WATERCOOLEDTUBEINTUBE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCondenserTypeEnum();
			IfcCondenserTypeEnum( IfcCondenserTypeEnumEnum e ) { m_enum = e; }
			~IfcCondenserTypeEnum();
			virtual const char* classname() const { return "IfcCondenserTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCondenserTypeEnum> readStepData( std::string& arg );
			IfcCondenserTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

