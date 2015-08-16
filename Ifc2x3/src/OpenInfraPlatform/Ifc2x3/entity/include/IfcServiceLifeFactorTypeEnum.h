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
		// TYPE IfcServiceLifeFactorTypeEnum = ENUMERATION OF	(A_QUALITYOFCOMPONENTS	,B_DESIGNLEVEL	,C_WORKEXECUTIONLEVEL	,D_INDOORENVIRONMENT	,E_OUTDOORENVIRONMENT	,F_INUSECONDITIONS	,G_MAINTENANCELEVEL	,USERDEFINED	,NOTDEFINED);
		class IfcServiceLifeFactorTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcServiceLifeFactorTypeEnumEnum
			{
				ENUM_A_QUALITYOFCOMPONENTS,
				ENUM_B_DESIGNLEVEL,
				ENUM_C_WORKEXECUTIONLEVEL,
				ENUM_D_INDOORENVIRONMENT,
				ENUM_E_OUTDOORENVIRONMENT,
				ENUM_F_INUSECONDITIONS,
				ENUM_G_MAINTENANCELEVEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcServiceLifeFactorTypeEnum();
			IfcServiceLifeFactorTypeEnum( IfcServiceLifeFactorTypeEnumEnum e ) { m_enum = e; }
			~IfcServiceLifeFactorTypeEnum();
			virtual const char* classname() const { return "IfcServiceLifeFactorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcServiceLifeFactorTypeEnum> readStepData( std::string& arg );
			IfcServiceLifeFactorTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

