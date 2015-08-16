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
		// TYPE IfcRibPlateDirectionEnum = ENUMERATION OF	(DIRECTION_X	,DIRECTION_Y);
		class IfcRibPlateDirectionEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcRibPlateDirectionEnumEnum
			{
				ENUM_DIRECTION_X,
				ENUM_DIRECTION_Y
			};

			IfcRibPlateDirectionEnum();
			IfcRibPlateDirectionEnum( IfcRibPlateDirectionEnumEnum e ) { m_enum = e; }
			~IfcRibPlateDirectionEnum();
			virtual const char* classname() const { return "IfcRibPlateDirectionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRibPlateDirectionEnum> readStepData( std::string& arg );
			IfcRibPlateDirectionEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

