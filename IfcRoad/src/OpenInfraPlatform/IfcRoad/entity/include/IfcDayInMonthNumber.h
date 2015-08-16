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
		// TYPE IfcDayInMonthNumber = INTEGER;
		class IfcDayInMonthNumber : public IfcRoadType
		{
		public:
			IfcDayInMonthNumber();
			IfcDayInMonthNumber( int value );
			~IfcDayInMonthNumber();
			virtual const char* classname() const { return "IfcDayInMonthNumber"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDayInMonthNumber> readStepData( std::string& arg );
			int m_value;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

