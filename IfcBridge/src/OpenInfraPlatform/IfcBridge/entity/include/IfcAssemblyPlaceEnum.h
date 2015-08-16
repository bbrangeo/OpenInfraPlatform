/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcAssemblyPlaceEnum = ENUMERATION OF	(SITE	,FACTORY	,NOTDEFINED);
		class IfcAssemblyPlaceEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

