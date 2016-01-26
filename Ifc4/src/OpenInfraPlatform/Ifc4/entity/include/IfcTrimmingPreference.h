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
		// TYPE IfcTrimmingPreference = ENUMERATION OF	(CARTESIAN	,PARAMETER	,UNSPECIFIED);
		class IfcTrimmingPreference : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

