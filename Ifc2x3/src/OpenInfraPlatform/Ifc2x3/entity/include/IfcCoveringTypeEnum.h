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
		// TYPE IfcCoveringTypeEnum = ENUMERATION OF	(CEILING	,FLOORING	,CLADDING	,ROOFING	,INSULATION	,MEMBRANE	,SLEEVING	,WRAPPING	,USERDEFINED	,NOTDEFINED);
		class IfcCoveringTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcCoveringTypeEnumEnum
			{
				ENUM_CEILING,
				ENUM_FLOORING,
				ENUM_CLADDING,
				ENUM_ROOFING,
				ENUM_INSULATION,
				ENUM_MEMBRANE,
				ENUM_SLEEVING,
				ENUM_WRAPPING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCoveringTypeEnum();
			IfcCoveringTypeEnum( IfcCoveringTypeEnumEnum e ) { m_enum = e; }
			~IfcCoveringTypeEnum();
			virtual const char* classname() const { return "IfcCoveringTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCoveringTypeEnum> readStepData( std::string& arg );
			IfcCoveringTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

