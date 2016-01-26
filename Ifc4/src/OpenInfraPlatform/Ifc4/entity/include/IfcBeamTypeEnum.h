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
		// TYPE IfcBeamTypeEnum = ENUMERATION OF	(BEAM	,JOIST	,HOLLOWCORE	,LINTEL	,SPANDREL	,T_BEAM	,USERDEFINED	,NOTDEFINED);
		class IfcBeamTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

