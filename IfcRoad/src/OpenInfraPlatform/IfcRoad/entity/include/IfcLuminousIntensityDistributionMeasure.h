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
#include "IfcDerivedMeasureValue.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcLuminousIntensityDistributionMeasure = REAL;
		class IfcLuminousIntensityDistributionMeasure : public IfcDerivedMeasureValue, public IfcRoadType
		{
		public:
			IfcLuminousIntensityDistributionMeasure();
			IfcLuminousIntensityDistributionMeasure( double value );
			~IfcLuminousIntensityDistributionMeasure();
			virtual const char* classname() const { return "IfcLuminousIntensityDistributionMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLuminousIntensityDistributionMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

