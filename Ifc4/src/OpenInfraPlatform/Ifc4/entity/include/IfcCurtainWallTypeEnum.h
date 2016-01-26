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
		// TYPE IfcCurtainWallTypeEnum = ENUMERATION OF	(USERDEFINED	,NOTDEFINED);
		class IfcCurtainWallTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCurtainWallTypeEnumEnum
			{
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCurtainWallTypeEnum();
			IfcCurtainWallTypeEnum( IfcCurtainWallTypeEnumEnum e ) { m_enum = e; }
			~IfcCurtainWallTypeEnum();
			virtual const char* classname() const { return "IfcCurtainWallTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCurtainWallTypeEnum> readStepData( std::string& arg );
			IfcCurtainWallTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

