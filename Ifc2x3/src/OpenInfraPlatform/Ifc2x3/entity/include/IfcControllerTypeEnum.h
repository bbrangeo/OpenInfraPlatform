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
		// TYPE IfcControllerTypeEnum = ENUMERATION OF	(FLOATING	,PROPORTIONAL	,PROPORTIONALINTEGRAL	,PROPORTIONALINTEGRALDERIVATIVE	,TIMEDTWOPOSITION	,TWOPOSITION	,USERDEFINED	,NOTDEFINED);
		class IfcControllerTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcControllerTypeEnumEnum
			{
				ENUM_FLOATING,
				ENUM_PROPORTIONAL,
				ENUM_PROPORTIONALINTEGRAL,
				ENUM_PROPORTIONALINTEGRALDERIVATIVE,
				ENUM_TIMEDTWOPOSITION,
				ENUM_TWOPOSITION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcControllerTypeEnum();
			IfcControllerTypeEnum( IfcControllerTypeEnumEnum e ) { m_enum = e; }
			~IfcControllerTypeEnum();
			virtual const char* classname() const { return "IfcControllerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcControllerTypeEnum> readStepData( std::string& arg );
			IfcControllerTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

