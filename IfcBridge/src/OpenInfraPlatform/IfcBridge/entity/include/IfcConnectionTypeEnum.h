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
		// TYPE IfcConnectionTypeEnum = ENUMERATION OF	(ATPATH	,ATSTART	,ATEND	,NOTDEFINED);
		class IfcConnectionTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcConnectionTypeEnumEnum
			{
				ENUM_ATPATH,
				ENUM_ATSTART,
				ENUM_ATEND,
				ENUM_NOTDEFINED
			};

			IfcConnectionTypeEnum();
			IfcConnectionTypeEnum( IfcConnectionTypeEnumEnum e ) { m_enum = e; }
			~IfcConnectionTypeEnum();
			virtual const char* classname() const { return "IfcConnectionTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcConnectionTypeEnum> readStepData( std::string& arg );
			IfcConnectionTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

