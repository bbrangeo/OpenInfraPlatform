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
		// TYPE IfcDuctSilencerTypeEnum = ENUMERATION OF	(FLATOVAL	,RECTANGULAR	,ROUND	,USERDEFINED	,NOTDEFINED);
		class IfcDuctSilencerTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcDuctSilencerTypeEnumEnum
			{
				ENUM_FLATOVAL,
				ENUM_RECTANGULAR,
				ENUM_ROUND,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDuctSilencerTypeEnum();
			IfcDuctSilencerTypeEnum( IfcDuctSilencerTypeEnumEnum e ) { m_enum = e; }
			~IfcDuctSilencerTypeEnum();
			virtual const char* classname() const { return "IfcDuctSilencerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDuctSilencerTypeEnum> readStepData( std::string& arg );
			IfcDuctSilencerTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

