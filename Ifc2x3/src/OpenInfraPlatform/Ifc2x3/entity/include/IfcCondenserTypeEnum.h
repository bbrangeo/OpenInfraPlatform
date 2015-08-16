/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcCondenserTypeEnum = ENUMERATION OF	(WATERCOOLEDSHELLTUBE	,WATERCOOLEDSHELLCOIL	,WATERCOOLEDTUBEINTUBE	,WATERCOOLEDBRAZEDPLATE	,AIRCOOLED	,EVAPORATIVECOOLED	,USERDEFINED	,NOTDEFINED);
		class IfcCondenserTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcCondenserTypeEnumEnum
			{
				ENUM_WATERCOOLEDSHELLTUBE,
				ENUM_WATERCOOLEDSHELLCOIL,
				ENUM_WATERCOOLEDTUBEINTUBE,
				ENUM_WATERCOOLEDBRAZEDPLATE,
				ENUM_AIRCOOLED,
				ENUM_EVAPORATIVECOOLED,
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

