/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "../../model/shared_ptr.h"
#include "../../model/IfcBridgeObject.h"
#include "IfcValue.h"

// TYPE IfcMeasureValue = SELECT	(IfcAmountOfSubstanceMeasure	,IfcAreaMeasure	,IfcComplexNumber	,IfcContextDependentMeasure	,IfcCountMeasure	,IfcDescriptiveMeasure	,IfcElectricCurrentMeasure	,IfcLengthMeasure	,IfcLuminousIntensityMeasure	,IfcMassMeasure	,IfcNonNegativeLengthMeasure	,IfcNormalisedRatioMeasure	,IfcNumericMeasure	,IfcParameterValue	,IfcPlaneAngleMeasure	,IfcPositiveLengthMeasure	,IfcPositivePlaneAngleMeasure	,IfcPositiveRatioMeasure	,IfcRatioMeasure	,IfcSolidAngleMeasure	,IfcThermodynamicTemperatureMeasure	,IfcTimeMeasure	,IfcVolumeMeasure);
namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcMeasureValue : public IfcValue
		{
		public:
			IfcMeasureValue();
			~IfcMeasureValue();
			virtual const char* classname() const { return "IfcMeasureValue"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcMeasureValue> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

