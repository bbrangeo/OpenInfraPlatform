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
		// TYPE IfcEngineTypeEnum = ENUMERATION OF	(EXTERNALCOMBUSTION	,INTERNALCOMBUSTION	,USERDEFINED	,NOTDEFINED);
		class IfcEngineTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcEngineTypeEnumEnum
			{
				ENUM_EXTERNALCOMBUSTION,
				ENUM_INTERNALCOMBUSTION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcEngineTypeEnum();
			IfcEngineTypeEnum( IfcEngineTypeEnumEnum e ) { m_enum = e; }
			~IfcEngineTypeEnum();
			virtual const char* classname() const { return "IfcEngineTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcEngineTypeEnum> readStepData( std::string& arg );
			IfcEngineTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

