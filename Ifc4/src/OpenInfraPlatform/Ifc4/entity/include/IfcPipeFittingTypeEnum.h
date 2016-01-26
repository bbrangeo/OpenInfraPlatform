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
		// TYPE IfcPipeFittingTypeEnum = ENUMERATION OF	(BEND	,CONNECTOR	,ENTRY	,EXIT	,JUNCTION	,OBSTRUCTION	,TRANSITION	,USERDEFINED	,NOTDEFINED);
		class IfcPipeFittingTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcPipeFittingTypeEnumEnum
			{
				ENUM_BEND,
				ENUM_CONNECTOR,
				ENUM_ENTRY,
				ENUM_EXIT,
				ENUM_JUNCTION,
				ENUM_OBSTRUCTION,
				ENUM_TRANSITION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPipeFittingTypeEnum();
			IfcPipeFittingTypeEnum( IfcPipeFittingTypeEnumEnum e ) { m_enum = e; }
			~IfcPipeFittingTypeEnum();
			virtual const char* classname() const { return "IfcPipeFittingTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPipeFittingTypeEnum> readStepData( std::string& arg );
			IfcPipeFittingTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

