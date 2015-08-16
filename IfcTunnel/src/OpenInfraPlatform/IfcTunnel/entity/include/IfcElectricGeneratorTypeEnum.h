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
		// TYPE IfcElectricGeneratorTypeEnum = ENUMERATION OF	(CHP	,ENGINEGENERATOR	,STANDALONE	,USERDEFINED	,NOTDEFINED);
		class IfcElectricGeneratorTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcElectricGeneratorTypeEnumEnum
			{
				ENUM_CHP,
				ENUM_ENGINEGENERATOR,
				ENUM_STANDALONE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElectricGeneratorTypeEnum();
			IfcElectricGeneratorTypeEnum( IfcElectricGeneratorTypeEnumEnum e ) { m_enum = e; }
			~IfcElectricGeneratorTypeEnum();
			virtual const char* classname() const { return "IfcElectricGeneratorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElectricGeneratorTypeEnum> readStepData( std::string& arg );
			IfcElectricGeneratorTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

