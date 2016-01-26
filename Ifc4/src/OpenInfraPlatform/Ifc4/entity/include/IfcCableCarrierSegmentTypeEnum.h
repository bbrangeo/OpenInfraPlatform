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
		// TYPE IfcCableCarrierSegmentTypeEnum = ENUMERATION OF	(CABLELADDERSEGMENT	,CABLETRAYSEGMENT	,CABLETRUNKINGSEGMENT	,CONDUITSEGMENT	,USERDEFINED	,NOTDEFINED);
		class IfcCableCarrierSegmentTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCableCarrierSegmentTypeEnumEnum
			{
				ENUM_CABLELADDERSEGMENT,
				ENUM_CABLETRAYSEGMENT,
				ENUM_CABLETRUNKINGSEGMENT,
				ENUM_CONDUITSEGMENT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCableCarrierSegmentTypeEnum();
			IfcCableCarrierSegmentTypeEnum( IfcCableCarrierSegmentTypeEnumEnum e ) { m_enum = e; }
			~IfcCableCarrierSegmentTypeEnum();
			virtual const char* classname() const { return "IfcCableCarrierSegmentTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCableCarrierSegmentTypeEnum> readStepData( std::string& arg );
			IfcCableCarrierSegmentTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

