/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcFlowDirectionEnum = ENUMERATION OF	(SOURCE	,SINK	,SOURCEANDSINK	,NOTDEFINED);
		class IfcFlowDirectionEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

