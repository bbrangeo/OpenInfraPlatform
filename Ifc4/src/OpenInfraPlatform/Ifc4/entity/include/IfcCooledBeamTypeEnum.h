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
		// TYPE IfcCooledBeamTypeEnum = ENUMERATION OF	(ACTIVE	,PASSIVE	,USERDEFINED	,NOTDEFINED);
		class IfcCooledBeamTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCooledBeamTypeEnumEnum
			{
				ENUM_ACTIVE,
				ENUM_PASSIVE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCooledBeamTypeEnum();
			IfcCooledBeamTypeEnum( IfcCooledBeamTypeEnumEnum e ) { m_enum = e; }
			~IfcCooledBeamTypeEnum();
			virtual const char* classname() const { return "IfcCooledBeamTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCooledBeamTypeEnum> readStepData( std::string& arg );
			IfcCooledBeamTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

