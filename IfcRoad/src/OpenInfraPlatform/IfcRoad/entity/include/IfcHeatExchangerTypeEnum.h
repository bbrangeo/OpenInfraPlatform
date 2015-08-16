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
		// TYPE IfcHeatExchangerTypeEnum = ENUMERATION OF	(PLATE	,SHELLANDTUBE	,USERDEFINED	,NOTDEFINED);
		class IfcHeatExchangerTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcHeatExchangerTypeEnumEnum
			{
				ENUM_PLATE,
				ENUM_SHELLANDTUBE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcHeatExchangerTypeEnum();
			IfcHeatExchangerTypeEnum( IfcHeatExchangerTypeEnumEnum e ) { m_enum = e; }
			~IfcHeatExchangerTypeEnum();
			virtual const char* classname() const { return "IfcHeatExchangerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcHeatExchangerTypeEnum> readStepData( std::string& arg );
			IfcHeatExchangerTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

