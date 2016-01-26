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
		// TYPE IfcElectricDistributionBoardTypeEnum = ENUMERATION OF	(CONSUMERUNIT	,DISTRIBUTIONBOARD	,MOTORCONTROLCENTRE	,SWITCHBOARD	,USERDEFINED	,NOTDEFINED);
		class IfcElectricDistributionBoardTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcElectricDistributionBoardTypeEnumEnum
			{
				ENUM_CONSUMERUNIT,
				ENUM_DISTRIBUTIONBOARD,
				ENUM_MOTORCONTROLCENTRE,
				ENUM_SWITCHBOARD,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElectricDistributionBoardTypeEnum();
			IfcElectricDistributionBoardTypeEnum( IfcElectricDistributionBoardTypeEnumEnum e ) { m_enum = e; }
			~IfcElectricDistributionBoardTypeEnum();
			virtual const char* classname() const { return "IfcElectricDistributionBoardTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElectricDistributionBoardTypeEnum> readStepData( std::string& arg );
			IfcElectricDistributionBoardTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

