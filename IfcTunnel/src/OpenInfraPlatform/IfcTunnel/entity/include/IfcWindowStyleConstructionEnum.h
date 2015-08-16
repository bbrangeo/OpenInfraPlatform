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
		// TYPE IfcWindowStyleConstructionEnum = ENUMERATION OF	(ALUMINIUM	,HIGH_GRADE_STEEL	,STEEL	,WOOD	,ALUMINIUM_WOOD	,PLASTIC	,OTHER_CONSTRUCTION	,NOTDEFINED);
		class IfcWindowStyleConstructionEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcWindowStyleConstructionEnumEnum
			{
				ENUM_ALUMINIUM,
				ENUM_HIGH_GRADE_STEEL,
				ENUM_STEEL,
				ENUM_WOOD,
				ENUM_ALUMINIUM_WOOD,
				ENUM_PLASTIC,
				ENUM_OTHER_CONSTRUCTION,
				ENUM_NOTDEFINED
			};

			IfcWindowStyleConstructionEnum();
			IfcWindowStyleConstructionEnum( IfcWindowStyleConstructionEnumEnum e ) { m_enum = e; }
			~IfcWindowStyleConstructionEnum();
			virtual const char* classname() const { return "IfcWindowStyleConstructionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWindowStyleConstructionEnum> readStepData( std::string& arg );
			IfcWindowStyleConstructionEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

