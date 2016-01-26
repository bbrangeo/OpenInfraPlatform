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
		// TYPE IfcSpaceHeaterTypeEnum = ENUMERATION OF	(CONVECTOR	,RADIATOR	,USERDEFINED	,NOTDEFINED);
		class IfcSpaceHeaterTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcSpaceHeaterTypeEnumEnum
			{
				ENUM_CONVECTOR,
				ENUM_RADIATOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSpaceHeaterTypeEnum();
			IfcSpaceHeaterTypeEnum( IfcSpaceHeaterTypeEnumEnum e ) { m_enum = e; }
			~IfcSpaceHeaterTypeEnum();
			virtual const char* classname() const { return "IfcSpaceHeaterTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSpaceHeaterTypeEnum> readStepData( std::string& arg );
			IfcSpaceHeaterTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

