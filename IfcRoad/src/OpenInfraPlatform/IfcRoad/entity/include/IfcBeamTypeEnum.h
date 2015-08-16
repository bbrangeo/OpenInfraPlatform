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
		// TYPE IfcBeamTypeEnum = ENUMERATION OF	(BEAM	,JOIST	,HOLLOWCORE	,LINTEL	,SPANDREL	,T_BEAM	,USERDEFINED	,NOTDEFINED);
		class IfcBeamTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcBeamTypeEnumEnum
			{
				ENUM_BEAM,
				ENUM_JOIST,
				ENUM_HOLLOWCORE,
				ENUM_LINTEL,
				ENUM_SPANDREL,
				ENUM_T_BEAM,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBeamTypeEnum();
			IfcBeamTypeEnum( IfcBeamTypeEnumEnum e ) { m_enum = e; }
			~IfcBeamTypeEnum();
			virtual const char* classname() const { return "IfcBeamTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBeamTypeEnum> readStepData( std::string& arg );
			IfcBeamTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

