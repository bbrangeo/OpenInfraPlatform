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
#include "IfcMeasureValue.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcCountMeasure = NUMBER;
		class IfcCountMeasure : public IfcMeasureValue, public IfcRoadType
		{
		public:
			IfcCountMeasure();
			IfcCountMeasure( int value );
			~IfcCountMeasure();
			virtual const char* classname() const { return "IfcCountMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCountMeasure> readStepData( std::string& arg );
			int m_value;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

