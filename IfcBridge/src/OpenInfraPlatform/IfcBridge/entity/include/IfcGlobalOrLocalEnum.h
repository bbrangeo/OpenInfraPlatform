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
		// TYPE IfcGlobalOrLocalEnum = ENUMERATION OF	(GLOBAL_COORDS	,LOCAL_COORDS);
		class IfcGlobalOrLocalEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcGlobalOrLocalEnumEnum
			{
				ENUM_GLOBAL_COORDS,
				ENUM_LOCAL_COORDS
			};

			IfcGlobalOrLocalEnum();
			IfcGlobalOrLocalEnum( IfcGlobalOrLocalEnumEnum e ) { m_enum = e; }
			~IfcGlobalOrLocalEnum();
			virtual const char* classname() const { return "IfcGlobalOrLocalEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcGlobalOrLocalEnum> readStepData( std::string& arg );
			IfcGlobalOrLocalEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

