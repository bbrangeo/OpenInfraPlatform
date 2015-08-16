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
		// TYPE IfcDataOriginEnum = ENUMERATION OF	(MEASURED	,PREDICTED	,SIMULATED	,USERDEFINED	,NOTDEFINED);
		class IfcDataOriginEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcDataOriginEnumEnum
			{
				ENUM_MEASURED,
				ENUM_PREDICTED,
				ENUM_SIMULATED,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDataOriginEnum();
			IfcDataOriginEnum( IfcDataOriginEnumEnum e ) { m_enum = e; }
			~IfcDataOriginEnum();
			virtual const char* classname() const { return "IfcDataOriginEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDataOriginEnum> readStepData( std::string& arg );
			IfcDataOriginEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

