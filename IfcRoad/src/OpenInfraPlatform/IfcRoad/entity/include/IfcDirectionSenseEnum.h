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
		// TYPE IfcDirectionSenseEnum = ENUMERATION OF	(POSITIVE	,NEGATIVE);
		class IfcDirectionSenseEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcDirectionSenseEnumEnum
			{
				ENUM_POSITIVE,
				ENUM_NEGATIVE
			};

			IfcDirectionSenseEnum();
			IfcDirectionSenseEnum( IfcDirectionSenseEnumEnum e ) { m_enum = e; }
			~IfcDirectionSenseEnum();
			virtual const char* classname() const { return "IfcDirectionSenseEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDirectionSenseEnum> readStepData( std::string& arg );
			IfcDirectionSenseEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

