/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "../../model/shared_ptr.h"
#include "../../model/Ifc2x3Object.h"
#include "IfcValue.h"

// TYPE IfcDerivedMeasureValue = SELECT	(IfcVolumetricFlowRateMeasure	,IfcTimeStamp	,IfcThermalTransmittanceMeasure	,IfcThermalResistanceMeasure	,IfcThermalAdmittanceMeasure	,IfcPressureMeasure	,IfcPowerMeasure	,IfcMassFlowRateMeasure	,IfcMassDensityMeasure	,IfcLinearVelocityMeasure	,IfcKinematicViscosityMeasure	,IfcIntegerCountRateMeasure	,IfcHeatFluxDensityMeasure	,IfcFrequencyMeasure	,IfcEnergyMeasure	,IfcElectricVoltageMeasure	,IfcDynamicViscosityMeasure	,IfcCompoundPlaneAngleMeasure	,IfcAngularVelocityMeasure	,IfcThermalConductivityMeasure	,IfcMolecularWeightMeasure	,IfcVaporPermeabilityMeasure	,IfcMoistureDiffusivityMeasure	,IfcIsothermalMoistureCapacityMeasure	,IfcSpecificHeatCapacityMeasure	,IfcMonetaryMeasure	,IfcMagneticFluxDensityMeasure	,IfcMagneticFluxMeasure	,IfcLuminousFluxMeasure	,IfcForceMeasure	,IfcInductanceMeasure	,IfcIlluminanceMeasure	,IfcElectricResistanceMeasure	,IfcElectricConductanceMeasure	,IfcElectricChargeMeasure	,IfcDoseEquivalentMeasure	,IfcElectricCapacitanceMeasure	,IfcAbsorbedDoseMeasure	,IfcRadioActivityMeasure	,IfcRotationalFrequencyMeasure	,IfcTorqueMeasure	,IfcAccelerationMeasure	,IfcLinearForceMeasure	,IfcLinearStiffnessMeasure	,IfcModulusOfSubgradeReactionMeasure	,IfcModulusOfElasticityMeasure	,IfcMomentOfInertiaMeasure	,IfcPlanarForceMeasure	,IfcRotationalStiffnessMeasure	,IfcShearModulusMeasure	,IfcLinearMomentMeasure	,IfcLuminousIntensityDistributionMeasure	,IfcCurvatureMeasure	,IfcMassPerLengthMeasure	,IfcModulusOfLinearSubgradeReactionMeasure	,IfcModulusOfRotationalSubgradeReactionMeasure	,IfcRotationalMassMeasure	,IfcSectionalAreaIntegralMeasure	,IfcSectionModulusMeasure	,IfcTemperatureGradientMeasure	,IfcThermalExpansionCoefficientMeasure	,IfcWarpingConstantMeasure	,IfcWarpingMomentMeasure	,IfcSoundPowerMeasure	,IfcSoundPressureMeasure	,IfcHeatingValueMeasure	,IfcPHMeasure	,IfcIonConcentrationMeasure);
namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcDerivedMeasureValue : public IfcValue
		{
		public:
			IfcDerivedMeasureValue();
			~IfcDerivedMeasureValue();
			virtual const char* classname() const { return "IfcDerivedMeasureValue"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcDerivedMeasureValue> readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

