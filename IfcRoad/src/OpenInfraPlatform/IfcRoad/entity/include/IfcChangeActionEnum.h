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
		// TYPE IfcChangeActionEnum = ENUMERATION OF	(NOCHANGE	,MODIFIED	,ADDED	,DELETED	,NOTDEFINED);
		class IfcChangeActionEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcChangeActionEnumEnum
			{
				ENUM_NOCHANGE,
				ENUM_MODIFIED,
				ENUM_ADDED,
				ENUM_DELETED,
				ENUM_NOTDEFINED
			};

			IfcChangeActionEnum();
			IfcChangeActionEnum( IfcChangeActionEnumEnum e ) { m_enum = e; }
			~IfcChangeActionEnum();
			virtual const char* classname() const { return "IfcChangeActionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcChangeActionEnum> readStepData( std::string& arg );
			IfcChangeActionEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

