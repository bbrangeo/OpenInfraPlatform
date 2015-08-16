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
		// TYPE IfcHeatExchangerTypeEnum = ENUMERATION OF	(PLATE	,SHELLANDTUBE	,USERDEFINED	,NOTDEFINED);
		class IfcHeatExchangerTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

