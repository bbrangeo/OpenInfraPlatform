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
		// TYPE IfcSIPrefix = ENUMERATION OF	(EXA	,PETA	,TERA	,GIGA	,MEGA	,KILO	,HECTO	,DECA	,DECI	,CENTI	,MILLI	,MICRO	,NANO	,PICO	,FEMTO	,ATTO);
		class IfcSIPrefix : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcSIPrefixEnum
			{
				ENUM_EXA,
				ENUM_PETA,
				ENUM_TERA,
				ENUM_GIGA,
				ENUM_MEGA,
				ENUM_KILO,
				ENUM_HECTO,
				ENUM_DECA,
				ENUM_DECI,
				ENUM_CENTI,
				ENUM_MILLI,
				ENUM_MICRO,
				ENUM_NANO,
				ENUM_PICO,
				ENUM_FEMTO,
				ENUM_ATTO
			};

			IfcSIPrefix();
			IfcSIPrefix( IfcSIPrefixEnum e ) { m_enum = e; }
			~IfcSIPrefix();
			virtual const char* classname() const { return "IfcSIPrefix"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSIPrefix> readStepData( std::string& arg );
			IfcSIPrefixEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

