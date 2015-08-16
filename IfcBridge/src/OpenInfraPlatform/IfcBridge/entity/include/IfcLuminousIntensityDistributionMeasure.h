/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcBridgeObject.h"
#include "IfcDerivedMeasureValue.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcLuminousIntensityDistributionMeasure = REAL;
		class IfcLuminousIntensityDistributionMeasure : public IfcDerivedMeasureValue, public IfcBridgeType
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

