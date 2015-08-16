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
		// TYPE IfcTrimmingPreference = ENUMERATION OF	(CARTESIAN	,PARAMETER	,UNSPECIFIED);
		class IfcTrimmingPreference : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcTrimmingPreferenceEnum
			{
				ENUM_CARTESIAN,
				ENUM_PARAMETER,
				ENUM_UNSPECIFIED
			};

			IfcTrimmingPreference();
			IfcTrimmingPreference( IfcTrimmingPreferenceEnum e ) { m_enum = e; }
			~IfcTrimmingPreference();
			virtual const char* classname() const { return "IfcTrimmingPreference"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTrimmingPreference> readStepData( std::string& arg );
			IfcTrimmingPreferenceEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

