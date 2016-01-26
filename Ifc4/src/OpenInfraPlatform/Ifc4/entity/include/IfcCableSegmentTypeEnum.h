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
		// TYPE IfcCableSegmentTypeEnum = ENUMERATION OF	(BUSBARSEGMENT	,CABLESEGMENT	,CONDUCTORSEGMENT	,CORESEGMENT	,USERDEFINED	,NOTDEFINED);
		class IfcCableSegmentTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

