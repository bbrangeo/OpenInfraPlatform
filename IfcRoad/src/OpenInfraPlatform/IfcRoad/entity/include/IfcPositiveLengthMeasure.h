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
#include "IfcLengthMeasure.h"
#include "IfcHatchLineDistanceSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPositiveLengthMeasure = IfcLengthMeasure;
		class IfcPositiveLengthMeasure : public IfcLengthMeasure, public IfcHatchLineDistanceSelect
		{
		public:
			IfcPositiveLengthMeasure();
			~IfcPositiveLengthMeasure();
			virtual const char* classname() const { return "IfcPositiveLengthMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPositiveLengthMeasure> readStepData( std::string& arg );
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

