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
		// TYPE IfcEngineTypeEnum = ENUMERATION OF	(EXTERNALCOMBUSTION	,INTERNALCOMBUSTION	,USERDEFINED	,NOTDEFINED);
		class IfcEngineTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

