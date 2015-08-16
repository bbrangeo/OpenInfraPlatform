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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPhysicalOrVirtualEnum = ENUMERATION OF	(PHYSICAL	,VIRTUAL	,NOTDEFINED);
		class IfcPhysicalOrVirtualEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcPhysicalOrVirtualEnumEnum
			{
				ENUM_PHYSICAL,
				ENUM_VIRTUAL,
				ENUM_NOTDEFINED
			};

			IfcPhysicalOrVirtualEnum();
			IfcPhysicalOrVirtualEnum( IfcPhysicalOrVirtualEnumEnum e ) { m_enum = e; }
			~IfcPhysicalOrVirtualEnum();
			virtual const char* classname() const { return "IfcPhysicalOrVirtualEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPhysicalOrVirtualEnum> readStepData( std::string& arg );
			IfcPhysicalOrVirtualEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

