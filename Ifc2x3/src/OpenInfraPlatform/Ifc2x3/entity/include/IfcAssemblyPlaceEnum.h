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
		// TYPE IfcAssemblyPlaceEnum = ENUMERATION OF	(SITE	,FACTORY	,NOTDEFINED);
		class IfcAssemblyPlaceEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcAssemblyPlaceEnumEnum
			{
				ENUM_SITE,
				ENUM_FACTORY,
				ENUM_NOTDEFINED
			};

			IfcAssemblyPlaceEnum();
			IfcAssemblyPlaceEnum( IfcAssemblyPlaceEnumEnum e ) { m_enum = e; }
			~IfcAssemblyPlaceEnum();
			virtual const char* classname() const { return "IfcAssemblyPlaceEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAssemblyPlaceEnum> readStepData( std::string& arg );
			IfcAssemblyPlaceEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

