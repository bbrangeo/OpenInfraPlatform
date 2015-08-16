/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcElectricDistributionBoardTypeEnum = ENUMERATION OF	(CONSUMERUNIT	,DISTRIBUTIONBOARD	,MOTORCONTROLCENTRE	,SWITCHBOARD	,USERDEFINED	,NOTDEFINED);
		class IfcElectricDistributionBoardTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

