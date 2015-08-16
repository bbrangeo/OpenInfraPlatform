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
		// TYPE IfcSlabTypeEnum = ENUMERATION OF	(FLOOR	,ROOF	,LANDING	,BASESLAB	,USERDEFINED	,NOTDEFINED);
		class IfcSlabTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcSlabTypeEnumEnum
			{
				ENUM_FLOOR,
				ENUM_ROOF,
				ENUM_LANDING,
				ENUM_BASESLAB,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSlabTypeEnum();
			IfcSlabTypeEnum( IfcSlabTypeEnumEnum e ) { m_enum = e; }
			~IfcSlabTypeEnum();
			virtual const char* classname() const { return "IfcSlabTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSlabTypeEnum> readStepData( std::string& arg );
			IfcSlabTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

