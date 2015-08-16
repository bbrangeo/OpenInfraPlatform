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
		// TYPE IfcOpeningElementTypeEnum = ENUMERATION OF	(OPENING	,RECESS	,USERDEFINED	,NOTDEFINED);
		class IfcOpeningElementTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcOpeningElementTypeEnumEnum
			{
				ENUM_OPENING,
				ENUM_RECESS,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcOpeningElementTypeEnum();
			IfcOpeningElementTypeEnum( IfcOpeningElementTypeEnumEnum e ) { m_enum = e; }
			~IfcOpeningElementTypeEnum();
			virtual const char* classname() const { return "IfcOpeningElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcOpeningElementTypeEnum> readStepData( std::string& arg );
			IfcOpeningElementTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

