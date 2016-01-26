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
		// TYPE IfcDuctSegmentTypeEnum = ENUMERATION OF	(RIGIDSEGMENT	,FLEXIBLESEGMENT	,USERDEFINED	,NOTDEFINED);
		class IfcDuctSegmentTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

