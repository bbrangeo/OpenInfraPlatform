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
		// TYPE IfcGridTypeEnum = ENUMERATION OF	(RECTANGULAR	,RADIAL	,TRIANGULAR	,IRREGULAR	,USERDEFINED	,NOTDEFINED);
		class IfcGridTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcGridTypeEnumEnum
			{
				ENUM_RECTANGULAR,
				ENUM_RADIAL,
				ENUM_TRIANGULAR,
				ENUM_IRREGULAR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcGridTypeEnum();
			IfcGridTypeEnum( IfcGridTypeEnumEnum e ) { m_enum = e; }
			~IfcGridTypeEnum();
			virtual const char* classname() const { return "IfcGridTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcGridTypeEnum> readStepData( std::string& arg );
			IfcGridTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

