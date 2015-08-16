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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcStructuralCurveMemberTypeEnum = ENUMERATION OF	(RIGID_JOINED_MEMBER	,PIN_JOINED_MEMBER	,CABLE	,TENSION_MEMBER	,COMPRESSION_MEMBER	,USERDEFINED	,NOTDEFINED);
		class IfcStructuralCurveMemberTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcStructuralCurveMemberTypeEnumEnum
			{
				ENUM_RIGID_JOINED_MEMBER,
				ENUM_PIN_JOINED_MEMBER,
				ENUM_CABLE,
				ENUM_TENSION_MEMBER,
				ENUM_COMPRESSION_MEMBER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcStructuralCurveMemberTypeEnum();
			IfcStructuralCurveMemberTypeEnum( IfcStructuralCurveMemberTypeEnumEnum e ) { m_enum = e; }
			~IfcStructuralCurveMemberTypeEnum();
			virtual const char* classname() const { return "IfcStructuralCurveMemberTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStructuralCurveMemberTypeEnum> readStepData( std::string& arg );
			IfcStructuralCurveMemberTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

