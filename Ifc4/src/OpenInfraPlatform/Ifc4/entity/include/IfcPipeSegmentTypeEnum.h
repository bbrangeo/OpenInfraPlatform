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
		// TYPE IfcPipeSegmentTypeEnum = ENUMERATION OF	(CULVERT	,FLEXIBLESEGMENT	,RIGIDSEGMENT	,GUTTER	,SPOOL	,USERDEFINED	,NOTDEFINED);
		class IfcPipeSegmentTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcPipeSegmentTypeEnumEnum
			{
				ENUM_CULVERT,
				ENUM_FLEXIBLESEGMENT,
				ENUM_RIGIDSEGMENT,
				ENUM_GUTTER,
				ENUM_SPOOL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPipeSegmentTypeEnum();
			IfcPipeSegmentTypeEnum( IfcPipeSegmentTypeEnumEnum e ) { m_enum = e; }
			~IfcPipeSegmentTypeEnum();
			virtual const char* classname() const { return "IfcPipeSegmentTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPipeSegmentTypeEnum> readStepData( std::string& arg );
			IfcPipeSegmentTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

