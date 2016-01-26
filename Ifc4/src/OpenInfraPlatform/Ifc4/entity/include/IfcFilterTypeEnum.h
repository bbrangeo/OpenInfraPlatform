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
		// TYPE IfcFilterTypeEnum = ENUMERATION OF	(AIRPARTICLEFILTER	,COMPRESSEDAIRFILTER	,ODORFILTER	,OILFILTER	,STRAINER	,WATERFILTER	,USERDEFINED	,NOTDEFINED);
		class IfcFilterTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcFilterTypeEnumEnum
			{
				ENUM_AIRPARTICLEFILTER,
				ENUM_COMPRESSEDAIRFILTER,
				ENUM_ODORFILTER,
				ENUM_OILFILTER,
				ENUM_STRAINER,
				ENUM_WATERFILTER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFilterTypeEnum();
			IfcFilterTypeEnum( IfcFilterTypeEnumEnum e ) { m_enum = e; }
			~IfcFilterTypeEnum();
			virtual const char* classname() const { return "IfcFilterTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFilterTypeEnum> readStepData( std::string& arg );
			IfcFilterTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

