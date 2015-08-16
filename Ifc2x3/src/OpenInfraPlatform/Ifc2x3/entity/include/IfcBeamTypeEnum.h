/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcBeamTypeEnum = ENUMERATION OF	(BEAM	,JOIST	,LINTEL	,T_BEAM	,USERDEFINED	,NOTDEFINED);
		class IfcBeamTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcBeamTypeEnumEnum
			{
				ENUM_BEAM,
				ENUM_JOIST,
				ENUM_LINTEL,
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

