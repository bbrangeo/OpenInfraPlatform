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
		// TYPE IfcProjectOrderRecordTypeEnum = ENUMERATION OF	(CHANGE	,MAINTENANCE	,MOVE	,PURCHASE	,WORK	,USERDEFINED	,NOTDEFINED);
		class IfcProjectOrderRecordTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcProjectOrderRecordTypeEnumEnum
			{
				ENUM_CHANGE,
				ENUM_MAINTENANCE,
				ENUM_MOVE,
				ENUM_PURCHASE,
				ENUM_WORK,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcProjectOrderRecordTypeEnum();
			IfcProjectOrderRecordTypeEnum( IfcProjectOrderRecordTypeEnumEnum e ) { m_enum = e; }
			~IfcProjectOrderRecordTypeEnum();
			virtual const char* classname() const { return "IfcProjectOrderRecordTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProjectOrderRecordTypeEnum> readStepData( std::string& arg );
			IfcProjectOrderRecordTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

