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
		// TYPE IfcFlowDirectionEnum = ENUMERATION OF	(SOURCE	,SINK	,SOURCEANDSINK	,NOTDEFINED);
		class IfcFlowDirectionEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcFlowDirectionEnumEnum
			{
				ENUM_SOURCE,
				ENUM_SINK,
				ENUM_SOURCEANDSINK,
				ENUM_NOTDEFINED
			};

			IfcFlowDirectionEnum();
			IfcFlowDirectionEnum( IfcFlowDirectionEnumEnum e ) { m_enum = e; }
			~IfcFlowDirectionEnum();
			virtual const char* classname() const { return "IfcFlowDirectionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFlowDirectionEnum> readStepData( std::string& arg );
			IfcFlowDirectionEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

