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
		// TYPE IfcGlobalOrLocalEnum = ENUMERATION OF	(GLOBAL_COORDS	,LOCAL_COORDS);
		class IfcGlobalOrLocalEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

