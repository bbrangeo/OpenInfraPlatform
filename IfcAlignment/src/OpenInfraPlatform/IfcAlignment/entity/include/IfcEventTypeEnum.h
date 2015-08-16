/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcEventTypeEnum = ENUMERATION OF	(STARTEVENT	,ENDEVENT	,INTERMEDIATEEVENT	,USERDEFINED	,NOTDEFINED);
		class IfcEventTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcEventTypeEnumEnum
			{
				ENUM_STARTEVENT,
				ENUM_ENDEVENT,
				ENUM_INTERMEDIATEEVENT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcEventTypeEnum();
			IfcEventTypeEnum( IfcEventTypeEnumEnum e ) { m_enum = e; }
			~IfcEventTypeEnum();
			virtual const char* classname() const { return "IfcEventTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcEventTypeEnum> readStepData( std::string& arg );
			IfcEventTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

