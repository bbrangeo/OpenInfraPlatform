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
#include "IfcSimpleValue.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcLogical = LOGICAL;
		class IfcLogical : public IfcSimpleValue, public IfcRoadType
		{
		public:
			IfcLogical();
			IfcLogical( bool value );
			~IfcLogical();
			virtual const char* classname() const { return "IfcLogical"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLogical> readStepData( std::string& arg );
			bool m_value;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

