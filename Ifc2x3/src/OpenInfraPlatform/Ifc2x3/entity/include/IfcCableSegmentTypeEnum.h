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
		// TYPE IfcCableSegmentTypeEnum = ENUMERATION OF	(CABLESEGMENT	,CONDUCTORSEGMENT	,USERDEFINED	,NOTDEFINED);
		class IfcCableSegmentTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcCableSegmentTypeEnumEnum
			{
				ENUM_CABLESEGMENT,
				ENUM_CONDUCTORSEGMENT,
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

