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
		// TYPE IfcCableSegmentTypeEnum = ENUMERATION OF	(BUSBARSEGMENT	,CABLESEGMENT	,CONDUCTORSEGMENT	,CORESEGMENT	,USERDEFINED	,NOTDEFINED);
		class IfcCableSegmentTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcCableSegmentTypeEnumEnum
			{
				ENUM_BUSBARSEGMENT,
				ENUM_CABLESEGMENT,
				ENUM_CONDUCTORSEGMENT,
				ENUM_CORESEGMENT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCableSegmentTypeEnum();
			IfcCableSegmentTypeEnum( IfcCableSegmentTypeEnumEnum e ) { m_enum = e; }
			~IfcCableSegmentTypeEnum();
			virtual const char* classname() const { return "IfcCableSegmentTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCableSegmentTypeEnum> readStepData( std::string& arg );
			IfcCableSegmentTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

