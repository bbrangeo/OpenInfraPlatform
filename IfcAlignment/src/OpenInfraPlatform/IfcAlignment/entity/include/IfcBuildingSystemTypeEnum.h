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
		// TYPE IfcBuildingSystemTypeEnum = ENUMERATION OF	(FENESTRATION	,FOUNDATION	,LOADBEARING	,OUTERSHELL	,SHADING	,TRANSPORT	,USERDEFINED	,NOTDEFINED);
		class IfcBuildingSystemTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcBuildingSystemTypeEnumEnum
			{
				ENUM_FENESTRATION,
				ENUM_FOUNDATION,
				ENUM_LOADBEARING,
				ENUM_OUTERSHELL,
				ENUM_SHADING,
				ENUM_TRANSPORT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBuildingSystemTypeEnum();
			IfcBuildingSystemTypeEnum( IfcBuildingSystemTypeEnumEnum e ) { m_enum = e; }
			~IfcBuildingSystemTypeEnum();
			virtual const char* classname() const { return "IfcBuildingSystemTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBuildingSystemTypeEnum> readStepData( std::string& arg );
			IfcBuildingSystemTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

