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
		// TYPE IfcDuctSegmentTypeEnum = ENUMERATION OF	(RIGIDSEGMENT	,FLEXIBLESEGMENT	,USERDEFINED	,NOTDEFINED);
		class IfcDuctSegmentTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcDuctSegmentTypeEnumEnum
			{
				ENUM_RIGIDSEGMENT,
				ENUM_FLEXIBLESEGMENT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDuctSegmentTypeEnum();
			IfcDuctSegmentTypeEnum( IfcDuctSegmentTypeEnumEnum e ) { m_enum = e; }
			~IfcDuctSegmentTypeEnum();
			virtual const char* classname() const { return "IfcDuctSegmentTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDuctSegmentTypeEnum> readStepData( std::string& arg );
			IfcDuctSegmentTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

