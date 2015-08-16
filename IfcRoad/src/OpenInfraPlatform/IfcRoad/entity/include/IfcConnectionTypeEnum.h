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
		// TYPE IfcConnectionTypeEnum = ENUMERATION OF	(ATPATH	,ATSTART	,ATEND	,NOTDEFINED);
		class IfcConnectionTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

