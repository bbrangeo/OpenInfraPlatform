#pragma once

#include "EMTIfcEntityTypes.h"

namespace BlueFramework
{
	namespace Ifc4
	{
		class IfcAbsorbedDoseMeasure;
		class IfcAccelerationMeasure;
		class IfcActionRequest;
		class IfcActionSourceTypeEnum;
		class IfcActionTypeEnum;
		class IfcActor;
		class IfcActorRole;
		class IfcActorSelect;
		class IfcActuatorType;
		class IfcActuatorTypeEnum;
		class IfcAddress;
		class IfcAddressTypeEnum;
		class IfcAheadOrBehind;
		class IfcAirTerminalBoxType;
		class IfcAirTerminalBoxTypeEnum;
		class IfcAirTerminalType;
		class IfcAirTerminalTypeEnum;
		class IfcAirToAirHeatRecoveryType;
		class IfcAirToAirHeatRecoveryTypeEnum;
		class IfcAlarmType;
		class IfcAlarmTypeEnum;
		class IfcAmountOfSubstanceMeasure;
		class IfcAnalysisModelTypeEnum;
		class IfcAnalysisTheoryTypeEnum;
		class IfcAngularDimension;
		class IfcAngularVelocityMeasure;
		class IfcAnnotation;
		class IfcAnnotationCurveOccurrence;
		class IfcAnnotationFillArea;
		class IfcAnnotationFillAreaOccurrence;
		class IfcAnnotationOccurrence;
		class IfcAnnotationSurface;
		class IfcAnnotationSurfaceOccurrence;
		class IfcAnnotationSymbolOccurrence;
		class IfcAnnotationTextOccurrence;
		class IfcApplication;
		class IfcAppliedValue;
		class IfcAppliedValueRelationship;
		class IfcAppliedValueSelect;
		class IfcApproval;
		class IfcApprovalActorRelationship;
		class IfcApprovalPropertyRelationship;
		class IfcApprovalRelationship;
		class IfcArbitraryClosedProfileDef;
		class IfcArbitraryOpenProfileDef;
		class IfcArbitraryProfileDefWithVoids;
		class IfcAreaMeasure;
		class IfcArithmeticOperatorEnum;
		class IfcAssemblyPlaceEnum;
		class IfcAsset;
		class IfcAsymmetricIShapeProfileDef;
		class IfcAxis1Placement;
		class IfcAxis2Placement;
		class IfcAxis2Placement2D;
		class IfcAxis2Placement3D;
		class IfcBeam;
		class IfcBeamType;
		class IfcBeamTypeEnum;
		class IfcBenchmarkEnum;
		class IfcBezierCurve;
		class IfcBlobTexture;
		class IfcBlock;
		class IfcBoilerType;
		class IfcBoilerTypeEnum;
		class IfcBoolean;
		class IfcBooleanClippingResult;
		class IfcBooleanOperand;
		class IfcBooleanOperator;
		class IfcBooleanResult;
		class IfcBoundaryCondition;
		class IfcBoundaryEdgeCondition;
		class IfcBoundaryFaceCondition;
		class IfcBoundaryNodeCondition;
		class IfcBoundaryNodeConditionWarping;
		class IfcBoundedCurve;
		class IfcBoundedSurface;
		class IfcBoundingBox;
		class IfcBoxAlignment;
		class IfcBoxedHalfSpace;
		class IfcBSplineCurve;
		class IfcBSplineCurveForm;
		class IfcBuilding;
		class IfcBuildingElement;
		class IfcBuildingElementComponent;
		class IfcBuildingElementPart;
		class IfcBuildingElementProxy;
		class IfcBuildingElementProxyType;
		class IfcBuildingElementProxyTypeEnum;
		class IfcBuildingElementType;
		class IfcBuildingStorey;
		class IfcCableCarrierFittingType;
		class IfcCableCarrierFittingTypeEnum;
		class IfcCableCarrierSegmentType;
		class IfcCableCarrierSegmentTypeEnum;
		class IfcCableSegmentType;
		class IfcCableSegmentTypeEnum;
		class IfcCalendarDate;
		class IfcCartesianPoint;
		class IfcCartesianTransformationOperator;
		class IfcCartesianTransformationOperator2D;
		class IfcCartesianTransformationOperator2DnonUniform;
		class IfcCartesianTransformationOperator3D;
		class IfcCartesianTransformationOperator3DnonUniform;
		class IfcCenterLineProfileDef;
		class IfcChamferEdgeFeature;
		class IfcChangeActionEnum;
		class IfcCharacterStyleSelect;
		class IfcChillerType;
		class IfcChillerTypeEnum;
		class IfcCircle;
		class IfcCircleHollowProfileDef;
		class IfcCircleProfileDef;
		class IfcClassification;
		class IfcClassificationItem;
		class IfcClassificationItemRelationship;
		class IfcClassificationNotation;
		class IfcClassificationNotationFacet;
		class IfcClassificationNotationSelect;
		class IfcClassificationReference;
		class IfcClosedShell;
		class IfcCoilType;
		class IfcCoilTypeEnum;
		class IfcColour;
		class IfcColourOrFactor;
		class IfcColourRgb;
		class IfcColourSpecification;
		class IfcColumn;
		class IfcColumnType;
		class IfcColumnTypeEnum;
		class IfcComplexNumber;
		class IfcComplexProperty;
		class IfcCompositeCurve;
		class IfcCompositeCurveSegment;
		class IfcCompositeProfileDef;
		class IfcCompoundPlaneAngleMeasure;
		class IfcCompressorType;
		class IfcCompressorTypeEnum;
		class IfcCondenserType;
		class IfcCondenserTypeEnum;
		class IfcCondition;
		class IfcConditionCriterion;
		class IfcConditionCriterionSelect;
		class IfcConic;
		class IfcConnectedFaceSet;
		class IfcConnectionCurveGeometry;
		class IfcConnectionGeometry;
		class IfcConnectionPointEccentricity;
		class IfcConnectionPointGeometry;
		class IfcConnectionPortGeometry;
		class IfcConnectionSurfaceGeometry;
		class IfcConnectionTypeEnum;
		class IfcConstraint;
		class IfcConstraintAggregationRelationship;
		class IfcConstraintClassificationRelationship;
		class IfcConstraintEnum;
		class IfcConstraintRelationship;
		class IfcConstructionEquipmentResource;
		class IfcConstructionMaterialResource;
		class IfcConstructionProductResource;
		class IfcConstructionResource;
		class IfcContextDependentMeasure;
		class IfcContextDependentUnit;
		class IfcControl;
		class IfcControllerType;
		class IfcControllerTypeEnum;
		class IfcConversionBasedUnit;
		class IfcCooledBeamType;
		class IfcCooledBeamTypeEnum;
		class IfcCoolingTowerType;
		class IfcCoolingTowerTypeEnum;
		class IfcCoordinatedUniversalTimeOffset;
		class IfcCostItem;
		class IfcCostSchedule;
		class IfcCostScheduleTypeEnum;
		class IfcCostValue;
		class IfcCountMeasure;
		class IfcCovering;
		class IfcCoveringType;
		class IfcCoveringTypeEnum;
		class IfcCraneRailAShapeProfileDef;
		class IfcCraneRailFShapeProfileDef;
		class IfcCrewResource;
		class IfcCsgPrimitive3D;
		class IfcCsgSelect;
		class IfcCsgSolid;
		class IfcCShapeProfileDef;
		class IfcCurrencyEnum;
		class IfcCurrencyRelationship;
		class IfcCurtainWall;
		class IfcCurtainWallType;
		class IfcCurtainWallTypeEnum;
		class IfcCurvatureMeasure;
		class IfcCurve;
		class IfcCurveBoundedPlane;
		class IfcCurveFontOrScaledCurveFontSelect;
		class IfcCurveOrEdgeCurve;
		class IfcCurveStyle;
		class IfcCurveStyleFont;
		class IfcCurveStyleFontAndScaling;
		class IfcCurveStyleFontPattern;
		class IfcCurveStyleFontSelect;
		class IfcDamperType;
		class IfcDamperTypeEnum;
		class IfcDataOriginEnum;
		class IfcDateAndTime;
		class IfcDateTimeSelect;
		class IfcDayInMonthNumber;
		class IfcDaylightSavingHour;
		class IfcDefinedSymbol;
		class IfcDefinedSymbolSelect;
		class IfcDerivedMeasureValue;
		class IfcDerivedProfileDef;
		class IfcDerivedUnit;
		class IfcDerivedUnitElement;
		class IfcDerivedUnitEnum;
		class IfcDescriptiveMeasure;
		class IfcDiameterDimension;
		class IfcDimensionalExponents;
		class IfcDimensionCalloutRelationship;
		class IfcDimensionCount;
		class IfcDimensionCurve;
		class IfcDimensionCurveDirectedCallout;
		class IfcDimensionCurveTerminator;
		class IfcDimensionExtentUsage;
		class IfcDimensionPair;
		class IfcDirection;
		class IfcDirectionSenseEnum;
		class IfcDiscreteAccessory;
		class IfcDiscreteAccessoryType;
		class IfcDistributionChamberElement;
		class IfcDistributionChamberElementType;
		class IfcDistributionChamberElementTypeEnum;
		class IfcDistributionControlElement;
		class IfcDistributionControlElementType;
		class IfcDistributionElement;
		class IfcDistributionElementType;
		class IfcDistributionFlowElement;
		class IfcDistributionFlowElementType;
		class IfcDistributionPort;
		class IfcDocumentConfidentialityEnum;
		class IfcDocumentElectronicFormat;
		class IfcDocumentInformation;
		class IfcDocumentInformationRelationship;
		class IfcDocumentReference;
		class IfcDocumentSelect;
		class IfcDocumentStatusEnum;
		class IfcDoor;
		class IfcDoorLiningProperties;
		class IfcDoorPanelOperationEnum;
		class IfcDoorPanelPositionEnum;
		class IfcDoorPanelProperties;
		class IfcDoorStyle;
		class IfcDoorStyleConstructionEnum;
		class IfcDoorStyleOperationEnum;
		class IfcDoseEquivalentMeasure;
		class IfcDraughtingCallout;
		class IfcDraughtingCalloutElement;
		class IfcDraughtingCalloutRelationship;
		class IfcDraughtingPreDefinedColour;
		class IfcDraughtingPreDefinedCurveFont;
		class IfcDraughtingPreDefinedTextFont;
		class IfcDuctFittingType;
		class IfcDuctFittingTypeEnum;
		class IfcDuctSegmentType;
		class IfcDuctSegmentTypeEnum;
		class IfcDuctSilencerType;
		class IfcDuctSilencerTypeEnum;
		class IfcDynamicViscosityMeasure;
		class IfcEdge;
		class IfcEdgeCurve;
		class IfcEdgeFeature;
		class IfcEdgeLoop;
		class IfcElectricalBaseProperties;
		class IfcElectricalCircuit;
		class IfcElectricalElement;
		class IfcElectricApplianceType;
		class IfcElectricApplianceTypeEnum;
		class IfcElectricCapacitanceMeasure;
		class IfcElectricChargeMeasure;
		class IfcElectricConductanceMeasure;
		class IfcElectricCurrentEnum;
		class IfcElectricCurrentMeasure;
		class IfcElectricDistributionPoint;
		class IfcElectricDistributionPointFunctionEnum;
		class IfcElectricFlowStorageDeviceType;
		class IfcElectricFlowStorageDeviceTypeEnum;
		class IfcElectricGeneratorType;
		class IfcElectricGeneratorTypeEnum;
		class IfcElectricHeaterType;
		class IfcElectricHeaterTypeEnum;
		class IfcElectricMotorType;
		class IfcElectricMotorTypeEnum;
		class IfcElectricResistanceMeasure;
		class IfcElectricTimeControlType;
		class IfcElectricTimeControlTypeEnum;
		class IfcElectricVoltageMeasure;
		class IfcElement;
		class IfcElementarySurface;
		class IfcElementAssembly;
		class IfcElementAssemblyTypeEnum;
		class IfcElementComponent;
		class IfcElementComponentType;
		class IfcElementCompositionEnum;
		class IfcElementQuantity;
		class IfcElementType;
		class IfcEllipse;
		class IfcEllipseProfileDef;
		class IfcEnergyConversionDevice;
		class IfcEnergyConversionDeviceType;
		class IfcEnergyMeasure;
		class IfcEnergyProperties;
		class IfcEnergySequenceEnum;
		class IfcEnvironmentalImpactCategoryEnum;
		class IfcEnvironmentalImpactValue;
		class IfcEquipmentElement;
		class IfcEquipmentStandard;
		class IfcEvaporativeCoolerType;
		class IfcEvaporativeCoolerTypeEnum;
		class IfcEvaporatorType;
		class IfcEvaporatorTypeEnum;
		class IfcExtendedMaterialProperties;
		class IfcExternallyDefinedHatchStyle;
		class IfcExternallyDefinedSurfaceStyle;
		class IfcExternallyDefinedSymbol;
		class IfcExternallyDefinedTextFont;
		class IfcExternalReference;
		class IfcExtrudedAreaSolid;
		class IfcFace;
		class IfcFaceBasedSurfaceModel;
		class IfcFaceBound;
		class IfcFaceOuterBound;
		class IfcFaceSurface;
		class IfcFacetedBrep;
		class IfcFacetedBrepWithVoids;
		class IfcFailureConnectionCondition;
		class IfcFanType;
		class IfcFanTypeEnum;
		class IfcFastener;
		class IfcFastenerType;
		class IfcFeatureElement;
		class IfcFeatureElementAddition;
		class IfcFeatureElementSubtraction;
		class IfcFillAreaStyle;
		class IfcFillAreaStyleHatching;
		class IfcFillAreaStyleTiles;
		class IfcFillAreaStyleTileShapeSelect;
		class IfcFillAreaStyleTileSymbolWithStyle;
		class IfcFillStyleSelect;
		class IfcFilterType;
		class IfcFilterTypeEnum;
		class IfcFireSuppressionTerminalType;
		class IfcFireSuppressionTerminalTypeEnum;
		class IfcFlowController;
		class IfcFlowControllerType;
		class IfcFlowDirectionEnum;
		class IfcFlowFitting;
		class IfcFlowFittingType;
		class IfcFlowInstrumentType;
		class IfcFlowInstrumentTypeEnum;
		class IfcFlowMeterType;
		class IfcFlowMeterTypeEnum;
		class IfcFlowMovingDevice;
		class IfcFlowMovingDeviceType;
		class IfcFlowSegment;
		class IfcFlowSegmentType;
		class IfcFlowStorageDevice;
		class IfcFlowStorageDeviceType;
		class IfcFlowTerminal;
		class IfcFlowTerminalType;
		class IfcFlowTreatmentDevice;
		class IfcFlowTreatmentDeviceType;
		class IfcFluidFlowProperties;
		class IfcFontStyle;
		class IfcFontVariant;
		class IfcFontWeight;
		class IfcFooting;
		class IfcFootingTypeEnum;
		class IfcForceMeasure;
		class IfcFrequencyMeasure;
		class IfcFuelProperties;
		class IfcFurnishingElement;
		class IfcFurnishingElementType;
		class IfcFurnitureStandard;
		class IfcFurnitureType;
		class IfcGasTerminalType;
		class IfcGasTerminalTypeEnum;
		class IfcGeneralMaterialProperties;
		class IfcGeneralProfileProperties;
		class IfcGeometricCurveSet;
		class IfcGeometricProjectionEnum;
		class IfcGeometricRepresentationContext;
		class IfcGeometricRepresentationItem;
		class IfcGeometricRepresentationSubContext;
		class IfcGeometricSet;
		class IfcGeometricSetSelect;
		class IfcGloballyUniqueId;
		class IfcGlobalOrLocalEnum;
		class IfcGrid;
		class IfcGridAxis;
		class IfcGridPlacement;
		class IfcGroup;
		class IfcHalfSpaceSolid;
		class IfcHatchLineDistanceSelect;
		class IfcHeatExchangerType;
		class IfcHeatExchangerTypeEnum;
		class IfcHeatFluxDensityMeasure;
		class IfcHeatingValueMeasure;
		class IfcHourInDay;
		class IfcHumidifierType;
		class IfcHumidifierTypeEnum;
		class IfcHygroscopicMaterialProperties;
		class IfcIdentifier;
		class IfcIlluminanceMeasure;
		class IfcImageTexture;
		class IfcInductanceMeasure;
		class IfcInteger;
		class IfcIntegerCountRateMeasure;
		class IfcInternalOrExternalEnum;
		class IfcInventory;
		class IfcInventoryTypeEnum;
		class IfcIonConcentrationMeasure;
		class IfcIrregularTimeSeries;
		class IfcIrregularTimeSeriesValue;
		class IfcIShapeProfileDef;
		class IfcIsothermalMoistureCapacityMeasure;
		class IfcJunctionBoxType;
		class IfcJunctionBoxTypeEnum;
		class IfcKinematicViscosityMeasure;
		class IfcLabel;
		class IfcLaborResource;
		class IfcLampType;
		class IfcLampTypeEnum;
		class IfcLayeredItem;
		class IfcLayerSetDirectionEnum;
		class IfcLengthMeasure;
		class IfcLibraryInformation;
		class IfcLibraryReference;
		class IfcLibrarySelect;
		class IfcLightDistributionCurveEnum;
		class IfcLightDistributionData;
		class IfcLightDistributionDataSourceSelect;
		class IfcLightEmissionSourceEnum;
		class IfcLightFixtureType;
		class IfcLightFixtureTypeEnum;
		class IfcLightIntensityDistribution;
		class IfcLightSource;
		class IfcLightSourceAmbient;
		class IfcLightSourceDirectional;
		class IfcLightSourceGoniometric;
		class IfcLightSourcePositional;
		class IfcLightSourceSpot;
		class IfcLine;
		class IfcLinearDimension;
		class IfcLinearForceMeasure;
		class IfcLinearMomentMeasure;
		class IfcLinearStiffnessMeasure;
		class IfcLinearVelocityMeasure;
		class IfcLoadGroupTypeEnum;
		class IfcLocalPlacement;
		class IfcLocalTime;
		class IfcLogical;
		class IfcLogicalOperatorEnum;
		class IfcLoop;
		class IfcLShapeProfileDef;
		class IfcLuminousFluxMeasure;
		class IfcLuminousIntensityDistributionMeasure;
		class IfcLuminousIntensityMeasure;
		class IfcMagneticFluxDensityMeasure;
		class IfcMagneticFluxMeasure;
		class IfcManifoldSolidBrep;
		class IfcMappedItem;
		class IfcMassDensityMeasure;
		class IfcMassFlowRateMeasure;
		class IfcMassMeasure;
		class IfcMassPerLengthMeasure;
		class IfcMaterial;
		class IfcMaterialClassificationRelationship;
		class IfcMaterialDefinitionRepresentation;
		class IfcMaterialLayer;
		class IfcMaterialLayerSet;
		class IfcMaterialLayerSetUsage;
		class IfcMaterialList;
		class IfcMaterialProperties;
		class IfcMaterialSelect;
		class IfcMeasureValue;
		class IfcMeasureWithUnit;
		class IfcMechanicalConcreteMaterialProperties;
		class IfcMechanicalFastener;
		class IfcMechanicalFastenerType;
		class IfcMechanicalMaterialProperties;
		class IfcMechanicalSteelMaterialProperties;
		class IfcMember;
		class IfcMemberType;
		class IfcMemberTypeEnum;
		class IfcMetric;
		class IfcMetricValueSelect;
		class IfcMinuteInHour;
		class IfcModulusOfElasticityMeasure;
		class IfcModulusOfLinearSubgradeReactionMeasure;
		class IfcModulusOfRotationalSubgradeReactionMeasure;
		class IfcModulusOfSubgradeReactionMeasure;
		class IfcMoistureDiffusivityMeasure;
		class IfcMolecularWeightMeasure;
		class IfcMomentOfInertiaMeasure;
		class IfcMonetaryMeasure;
		class IfcMonetaryUnit;
		class IfcMonthInYearNumber;
		class IfcMotorConnectionType;
		class IfcMotorConnectionTypeEnum;
		class IfcMove;
		class IfcNamedUnit;
		class IfcNormalisedRatioMeasure;
		class IfcNullStyle;
		class IfcNumericMeasure;
		class IfcObject;
		class IfcObjectDefinition;
		class IfcObjective;
		class IfcObjectiveEnum;
		class IfcObjectPlacement;
		class IfcObjectReferenceSelect;
		class IfcObjectTypeEnum;
		class IfcOccupant;
		class IfcOccupantTypeEnum;
		class IfcOffsetCurve2D;
		class IfcOffsetCurve3D;
		class IfcOneDirectionRepeatFactor;
		class IfcOpeningElement;
		class IfcOpenShell;
		class IfcOpticalMaterialProperties;
		class IfcOrderAction;
		class IfcOrganization;
		class IfcOrganizationRelationship;
		class IfcOrientationSelect;
		class IfcOrientedEdge;
		class IfcOutletType;
		class IfcOutletTypeEnum;
		class IfcOwnerHistory;
		class IfcParameterizedProfileDef;
		class IfcParameterValue;
		class IfcPath;
		class IfcPerformanceHistory;
		class IfcPermeableCoveringOperationEnum;
		class IfcPermeableCoveringProperties;
		class IfcPermit;
		class IfcPerson;
		class IfcPersonAndOrganization;
		class IfcPHMeasure;
		class IfcPhysicalComplexQuantity;
		class IfcPhysicalOrVirtualEnum;
		class IfcPhysicalQuantity;
		class IfcPhysicalSimpleQuantity;
		class IfcPile;
		class IfcPileConstructionEnum;
		class IfcPileTypeEnum;
		class IfcPipeFittingType;
		class IfcPipeFittingTypeEnum;
		class IfcPipeSegmentType;
		class IfcPipeSegmentTypeEnum;
		class IfcPixelTexture;
		class IfcPlacement;
		class IfcPlanarBox;
		class IfcPlanarExtent;
		class IfcPlanarForceMeasure;
		class IfcPlane;
		class IfcPlaneAngleMeasure;
		class IfcPlate;
		class IfcPlateType;
		class IfcPlateTypeEnum;
		class IfcPoint;
		class IfcPointOnCurve;
		class IfcPointOnSurface;
		class IfcPointOrVertexPoint;
		class IfcPolygonalBoundedHalfSpace;
		class IfcPolyline;
		class IfcPolyLoop;
		class IfcPort;
		class IfcPositiveLengthMeasure;
		class IfcPositivePlaneAngleMeasure;
		class IfcPositiveRatioMeasure;
		class IfcPostalAddress;
		class IfcPowerMeasure;
		class IfcPreDefinedColour;
		class IfcPreDefinedCurveFont;
		class IfcPreDefinedDimensionSymbol;
		class IfcPreDefinedItem;
		class IfcPreDefinedPointMarkerSymbol;
		class IfcPreDefinedSymbol;
		class IfcPreDefinedTerminatorSymbol;
		class IfcPreDefinedTextFont;
		class IfcPresentableText;
		class IfcPresentationLayerAssignment;
		class IfcPresentationLayerWithStyle;
		class IfcPresentationStyle;
		class IfcPresentationStyleAssignment;
		class IfcPresentationStyleSelect;
		class IfcPressureMeasure;
		class IfcProcedure;
		class IfcProcedureTypeEnum;
		class IfcProcess;
		class IfcProduct;
		class IfcProductDefinitionShape;
		class IfcProductRepresentation;
		class IfcProductsOfCombustionProperties;
		class IfcProfileDef;
		class IfcProfileProperties;
		class IfcProfileTypeEnum;
		class IfcProject;
		class IfcProjectedOrTrueLengthEnum;
		class IfcProjectionCurve;
		class IfcProjectionElement;
		class IfcProjectOrder;
		class IfcProjectOrderRecord;
		class IfcProjectOrderRecordTypeEnum;
		class IfcProjectOrderTypeEnum;
		class IfcProperty;
		class IfcPropertyBoundedValue;
		class IfcPropertyConstraintRelationship;
		class IfcPropertyDefinition;
		class IfcPropertyDependencyRelationship;
		class IfcPropertyEnumeratedValue;
		class IfcPropertyEnumeration;
		class IfcPropertyListValue;
		class IfcPropertyReferenceValue;
		class IfcPropertySet;
		class IfcPropertySetDefinition;
		class IfcPropertySingleValue;
		class IfcPropertySourceEnum;
		class IfcPropertyTableValue;
		class IfcProtectiveDeviceType;
		class IfcProtectiveDeviceTypeEnum;
		class IfcProxy;
		class IfcPumpType;
		class IfcPumpTypeEnum;
		class IfcQuantityArea;
		class IfcQuantityCount;
		class IfcQuantityLength;
		class IfcQuantityTime;
		class IfcQuantityVolume;
		class IfcQuantityWeight;
		class IfcRadioActivityMeasure;
		class IfcRadiusDimension;
		class IfcRailing;
		class IfcRailingType;
		class IfcRailingTypeEnum;
		class IfcRamp;
		class IfcRampFlight;
		class IfcRampFlightType;
		class IfcRampFlightTypeEnum;
		class IfcRampTypeEnum;
		class IfcRatioMeasure;
		class IfcRationalBezierCurve;
		class IfcReal;
		class IfcRectangleHollowProfileDef;
		class IfcRectangleProfileDef;
		class IfcRectangularPyramid;
		class IfcRectangularTrimmedSurface;
		class IfcReferencesValueDocument;
		class IfcReflectanceMethodEnum;
		class IfcRegularTimeSeries;
		class IfcReinforcementBarProperties;
		class IfcReinforcementDefinitionProperties;
		class IfcReinforcingBar;
		class IfcReinforcingBarRoleEnum;
		class IfcReinforcingBarSurfaceEnum;
		class IfcReinforcingElement;
		class IfcReinforcingMesh;
		class IfcRelAggregates;
		class IfcRelAssigns;
		class IfcRelAssignsTasks;
		class IfcRelAssignsToActor;
		class IfcRelAssignsToControl;
		class IfcRelAssignsToGroup;
		class IfcRelAssignsToProcess;
		class IfcRelAssignsToProduct;
		class IfcRelAssignsToProjectOrder;
		class IfcRelAssignsToResource;
		class IfcRelAssociates;
		class IfcRelAssociatesAppliedValue;
		class IfcRelAssociatesApproval;
		class IfcRelAssociatesClassification;
		class IfcRelAssociatesConstraint;
		class IfcRelAssociatesDocument;
		class IfcRelAssociatesLibrary;
		class IfcRelAssociatesMaterial;
		class IfcRelAssociatesProfileProperties;
		class IfcRelationship;
		class IfcRelaxation;
		class IfcRelConnects;
		class IfcRelConnectsElements;
		class IfcRelConnectsPathElements;
		class IfcRelConnectsPorts;
		class IfcRelConnectsPortToElement;
		class IfcRelConnectsStructuralActivity;
		class IfcRelConnectsStructuralElement;
		class IfcRelConnectsStructuralMember;
		class IfcRelConnectsWithEccentricity;
		class IfcRelConnectsWithRealizingElements;
		class IfcRelContainedInSpatialStructure;
		class IfcRelCoversBldgElements;
		class IfcRelCoversSpaces;
		class IfcRelDecomposes;
		class IfcRelDefines;
		class IfcRelDefinesByProperties;
		class IfcRelDefinesByType;
		class IfcRelFillsElement;
		class IfcRelFlowControlElements;
		class IfcRelInteractionRequirements;
		class IfcRelNests;
		class IfcRelOccupiesSpaces;
		class IfcRelOverridesProperties;
		class IfcRelProjectsElement;
		class IfcRelReferencedInSpatialStructure;
		class IfcRelSchedulesCostItems;
		class IfcRelSequence;
		class IfcRelServicesBuildings;
		class IfcRelSpaceBoundary;
		class IfcRelVoidsElement;
		class IfcRepresentation;
		class IfcRepresentationContext;
		class IfcRepresentationItem;
		class IfcRepresentationMap;
		class IfcResource;
		class IfcResourceConsumptionEnum;
		class IfcRevolvedAreaSolid;
		class IfcRibPlateDirectionEnum;
		class IfcRibPlateProfileProperties;
		class IfcRightCircularCone;
		class IfcRightCircularCylinder;
		class IfcRoleEnum;
		class IfcRoof;
		class IfcRoofTypeEnum;
		class IfcRoot;
		class IfcRotationalFrequencyMeasure;
		class IfcRotationalMassMeasure;
		class IfcRotationalStiffnessMeasure;
		class IfcRoundedEdgeFeature;
		class IfcRoundedRectangleProfileDef;
		class IfcSanitaryTerminalType;
		class IfcSanitaryTerminalTypeEnum;
		class IfcScheduleTimeControl;
		class IfcSecondInMinute;
		class IfcSectionalAreaIntegralMeasure;
		class IfcSectionedSpine;
		class IfcSectionModulusMeasure;
		class IfcSectionProperties;
		class IfcSectionReinforcementProperties;
		class IfcSectionTypeEnum;
		class IfcSensorType;
		class IfcSensorTypeEnum;
		class IfcSequenceEnum;
		class IfcServiceLife;
		class IfcServiceLifeFactor;
		class IfcServiceLifeFactorTypeEnum;
		class IfcServiceLifeTypeEnum;
		class IfcShapeAspect;
		class IfcShapeModel;
		class IfcShapeRepresentation;
		class IfcShearModulusMeasure;
		class IfcShell;
		class IfcShellBasedSurfaceModel;
		class IfcSimpleProperty;
		class IfcSimpleValue;
		class IfcSIPrefix;
		class IfcSite;
		class IfcSIUnit;
		class IfcSIUnitName;
		class IfcSizeSelect;
		class IfcSlab;
		class IfcSlabType;
		class IfcSlabTypeEnum;
		class IfcSlippageConnectionCondition;
		class IfcSolidAngleMeasure;
		class IfcSolidModel;
		class IfcSoundPowerMeasure;
		class IfcSoundPressureMeasure;
		class IfcSoundProperties;
		class IfcSoundScaleEnum;
		class IfcSoundValue;
		class IfcSpace;
		class IfcSpaceHeaterType;
		class IfcSpaceHeaterTypeEnum;
		class IfcSpaceProgram;
		class IfcSpaceThermalLoadProperties;
		class IfcSpaceType;
		class IfcSpaceTypeEnum;
		class IfcSpatialStructureElement;
		class IfcSpatialStructureElementType;
		class IfcSpecificHeatCapacityMeasure;
		class IfcSpecularExponent;
		class IfcSpecularHighlightSelect;
		class IfcSpecularRoughness;
		class IfcSphere;
		class IfcStackTerminalType;
		class IfcStackTerminalTypeEnum;
		class IfcStair;
		class IfcStairFlight;
		class IfcStairFlightType;
		class IfcStairFlightTypeEnum;
		class IfcStairTypeEnum;
		class IfcStateEnum;
		class IfcStructuralAction;
		class IfcStructuralActivity;
		class IfcStructuralActivityAssignmentSelect;
		class IfcStructuralAnalysisModel;
		class IfcStructuralConnection;
		class IfcStructuralConnectionCondition;
		class IfcStructuralCurveConnection;
		class IfcStructuralCurveMember;
		class IfcStructuralCurveMemberVarying;
		class IfcStructuralCurveTypeEnum;
		class IfcStructuralItem;
		class IfcStructuralLinearAction;
		class IfcStructuralLinearActionVarying;
		class IfcStructuralLoad;
		class IfcStructuralLoadGroup;
		class IfcStructuralLoadLinearForce;
		class IfcStructuralLoadPlanarForce;
		class IfcStructuralLoadSingleDisplacement;
		class IfcStructuralLoadSingleDisplacementDistortion;
		class IfcStructuralLoadSingleForce;
		class IfcStructuralLoadSingleForceWarping;
		class IfcStructuralLoadStatic;
		class IfcStructuralLoadTemperature;
		class IfcStructuralMember;
		class IfcStructuralPlanarAction;
		class IfcStructuralPlanarActionVarying;
		class IfcStructuralPointAction;
		class IfcStructuralPointConnection;
		class IfcStructuralPointReaction;
		class IfcStructuralProfileProperties;
		class IfcStructuralReaction;
		class IfcStructuralResultGroup;
		class IfcStructuralSteelProfileProperties;
		class IfcStructuralSurfaceConnection;
		class IfcStructuralSurfaceMember;
		class IfcStructuralSurfaceMemberVarying;
		class IfcStructuralSurfaceTypeEnum;
		class IfcStructuredDimensionCallout;
		class IfcStyledItem;
		class IfcStyledRepresentation;
		class IfcStyleModel;
		class IfcSubContractResource;
		class IfcSubedge;
		class IfcSurface;
		class IfcSurfaceCurveSweptAreaSolid;
		class IfcSurfaceOfLinearExtrusion;
		class IfcSurfaceOfRevolution;
		class IfcSurfaceOrFaceSurface;
		class IfcSurfaceSide;
		class IfcSurfaceStyle;
		class IfcSurfaceStyleElementSelect;
		class IfcSurfaceStyleLighting;
		class IfcSurfaceStyleRefraction;
		class IfcSurfaceStyleRendering;
		class IfcSurfaceStyleShading;
		class IfcSurfaceStyleWithTextures;
		class IfcSurfaceTexture;
		class IfcSurfaceTextureEnum;
		class IfcSweptAreaSolid;
		class IfcSweptDiskSolid;
		class IfcSweptSurface;
		class IfcSwitchingDeviceType;
		class IfcSwitchingDeviceTypeEnum;
		class IfcSymbolStyle;
		class IfcSymbolStyleSelect;
		class IfcSystem;
		class IfcSystemFurnitureElementType;
		class IfcTable;
		class IfcTableRow;
		class IfcTankType;
		class IfcTankTypeEnum;
		class IfcTask;
		class IfcTelecomAddress;
		class IfcTemperatureGradientMeasure;
		class IfcTendon;
		class IfcTendonAnchor;
		class IfcTendonTypeEnum;
		class IfcTerminatorSymbol;
		class IfcText;
		class IfcTextAlignment;
		class IfcTextDecoration;
		class IfcTextFontName;
		class IfcTextFontSelect;
		class IfcTextLiteral;
		class IfcTextLiteralWithExtent;
		class IfcTextPath;
		class IfcTextStyle;
		class IfcTextStyleFontModel;
		class IfcTextStyleForDefinedFont;
		class IfcTextStyleSelect;
		class IfcTextStyleTextModel;
		class IfcTextStyleWithBoxCharacteristics;
		class IfcTextTransformation;
		class IfcTextureCoordinate;
		class IfcTextureCoordinateGenerator;
		class IfcTextureMap;
		class IfcTextureVertex;
		class IfcThermalAdmittanceMeasure;
		class IfcThermalConductivityMeasure;
		class IfcThermalExpansionCoefficientMeasure;
		class IfcThermalLoadSourceEnum;
		class IfcThermalLoadTypeEnum;
		class IfcThermalMaterialProperties;
		class IfcThermalResistanceMeasure;
		class IfcThermalTransmittanceMeasure;
		class IfcThermodynamicTemperatureMeasure;
		class IfcTimeMeasure;
		class IfcTimeSeries;
		class IfcTimeSeriesDataTypeEnum;
		class IfcTimeSeriesReferenceRelationship;
		class IfcTimeSeriesSchedule;
		class IfcTimeSeriesScheduleTypeEnum;
		class IfcTimeSeriesValue;
		class IfcTimeStamp;
		class IfcTopologicalRepresentationItem;
		class IfcTopologyRepresentation;
		class IfcTorqueMeasure;
		class IfcTransformerType;
		class IfcTransformerTypeEnum;
		class IfcTransitionCode;
		class IfcTransportElement;
		class IfcTransportElementType;
		class IfcTransportElementTypeEnum;
		class IfcTrapeziumProfileDef;
		class IfcTrimmedCurve;
		class IfcTrimmingPreference;
		class IfcTrimmingSelect;
		class IfcTShapeProfileDef;
		class IfcTubeBundleType;
		class IfcTubeBundleTypeEnum;
		class IfcTwoDirectionRepeatFactor;
		class IfcTypeObject;
		class IfcTypeProduct;
		class IfcUnit;
		class IfcUnitaryEquipmentType;
		class IfcUnitaryEquipmentTypeEnum;
		class IfcUnitAssignment;
		class IfcUnitEnum;
		class IfcUShapeProfileDef;
		class IfcValue;
		class IfcValveType;
		class IfcValveTypeEnum;
		class IfcVaporPermeabilityMeasure;
		class IfcVector;
		class IfcVectorOrDirection;
		class IfcVertex;
		class IfcVertexBasedTextureMap;
		class IfcVertexLoop;
		class IfcVertexPoint;
		class IfcVibrationIsolatorType;
		class IfcVibrationIsolatorTypeEnum;
		class IfcVirtualElement;
		class IfcVirtualGridIntersection;
		class IfcVolumeMeasure;
		class IfcVolumetricFlowRateMeasure;
		class IfcWall;
		class IfcWallStandardCase;
		class IfcWallType;
		class IfcWallTypeEnum;
		class IfcWarpingConstantMeasure;
		class IfcWarpingMomentMeasure;
		class IfcWasteTerminalType;
		class IfcWasteTerminalTypeEnum;
		class IfcWaterProperties;
		class IfcWindow;
		class IfcWindowLiningProperties;
		class IfcWindowPanelOperationEnum;
		class IfcWindowPanelPositionEnum;
		class IfcWindowPanelProperties;
		class IfcWindowStyle;
		class IfcWindowStyleConstructionEnum;
		class IfcWindowStyleOperationEnum;
		class IfcWorkControl;
		class IfcWorkControlTypeEnum;
		class IfcWorkPlan;
		class IfcWorkSchedule;
		class IfcYearNumber;
		class IfcZone;
		class IfcZShapeProfileDef;
	}
}

namespace emt
{
	typedef IfcEntityTypes<
		BlueFramework::Ifc4::IfcAbsorbedDoseMeasure,
		BlueFramework::Ifc4::IfcAccelerationMeasure,
		BlueFramework::Ifc4::IfcActionRequest,
		BlueFramework::Ifc4::IfcActionSourceTypeEnum,
		BlueFramework::Ifc4::IfcActionTypeEnum,
		BlueFramework::Ifc4::IfcActor,
		BlueFramework::Ifc4::IfcActorRole,
		BlueFramework::Ifc4::IfcActorSelect,
		BlueFramework::Ifc4::IfcActuatorType,
		BlueFramework::Ifc4::IfcActuatorTypeEnum,
		BlueFramework::Ifc4::IfcAddress,
		BlueFramework::Ifc4::IfcAddressTypeEnum,
		BlueFramework::Ifc4::IfcAheadOrBehind,
		BlueFramework::Ifc4::IfcAirTerminalBoxType,
		BlueFramework::Ifc4::IfcAirTerminalBoxTypeEnum,
		BlueFramework::Ifc4::IfcAirTerminalType,
		BlueFramework::Ifc4::IfcAirTerminalTypeEnum,
		BlueFramework::Ifc4::IfcAirToAirHeatRecoveryType,
		BlueFramework::Ifc4::IfcAirToAirHeatRecoveryTypeEnum,
		BlueFramework::Ifc4::IfcAlarmType,
		BlueFramework::Ifc4::IfcAlarmTypeEnum,
		BlueFramework::Ifc4::IfcAmountOfSubstanceMeasure,
		BlueFramework::Ifc4::IfcAnalysisModelTypeEnum,
		BlueFramework::Ifc4::IfcAnalysisTheoryTypeEnum,
		BlueFramework::Ifc4::IfcAngularDimension,
		BlueFramework::Ifc4::IfcAngularVelocityMeasure,
		BlueFramework::Ifc4::IfcAnnotation,
		BlueFramework::Ifc4::IfcAnnotationCurveOccurrence,
		BlueFramework::Ifc4::IfcAnnotationFillArea,
		BlueFramework::Ifc4::IfcAnnotationFillAreaOccurrence,
		BlueFramework::Ifc4::IfcAnnotationOccurrence,
		BlueFramework::Ifc4::IfcAnnotationSurface,
		BlueFramework::Ifc4::IfcAnnotationSurfaceOccurrence,
		BlueFramework::Ifc4::IfcAnnotationSymbolOccurrence,
		BlueFramework::Ifc4::IfcAnnotationTextOccurrence,
		BlueFramework::Ifc4::IfcApplication,
		BlueFramework::Ifc4::IfcAppliedValue,
		BlueFramework::Ifc4::IfcAppliedValueRelationship,
		BlueFramework::Ifc4::IfcAppliedValueSelect,
		BlueFramework::Ifc4::IfcApproval,
		BlueFramework::Ifc4::IfcApprovalActorRelationship,
		BlueFramework::Ifc4::IfcApprovalPropertyRelationship,
		BlueFramework::Ifc4::IfcApprovalRelationship,
		BlueFramework::Ifc4::IfcArbitraryClosedProfileDef,
		BlueFramework::Ifc4::IfcArbitraryOpenProfileDef,
		BlueFramework::Ifc4::IfcArbitraryProfileDefWithVoids,
		BlueFramework::Ifc4::IfcAreaMeasure,
		BlueFramework::Ifc4::IfcArithmeticOperatorEnum,
		BlueFramework::Ifc4::IfcAssemblyPlaceEnum,
		BlueFramework::Ifc4::IfcAsset,
		BlueFramework::Ifc4::IfcAsymmetricIShapeProfileDef,
		BlueFramework::Ifc4::IfcAxis1Placement,
		BlueFramework::Ifc4::IfcAxis2Placement,
		BlueFramework::Ifc4::IfcAxis2Placement2D,
		BlueFramework::Ifc4::IfcAxis2Placement3D,
		BlueFramework::Ifc4::IfcBeam,
		BlueFramework::Ifc4::IfcBeamType,
		BlueFramework::Ifc4::IfcBeamTypeEnum,
		BlueFramework::Ifc4::IfcBenchmarkEnum,
		BlueFramework::Ifc4::IfcBezierCurve,
		BlueFramework::Ifc4::IfcBlobTexture,
		BlueFramework::Ifc4::IfcBlock,
		BlueFramework::Ifc4::IfcBoilerType,
		BlueFramework::Ifc4::IfcBoilerTypeEnum,
		BlueFramework::Ifc4::IfcBoolean,
		BlueFramework::Ifc4::IfcBooleanClippingResult,
		BlueFramework::Ifc4::IfcBooleanOperand,
		BlueFramework::Ifc4::IfcBooleanOperator,
		BlueFramework::Ifc4::IfcBooleanResult,
		BlueFramework::Ifc4::IfcBoundaryCondition,
		BlueFramework::Ifc4::IfcBoundaryEdgeCondition,
		BlueFramework::Ifc4::IfcBoundaryFaceCondition,
		BlueFramework::Ifc4::IfcBoundaryNodeCondition,
		BlueFramework::Ifc4::IfcBoundaryNodeConditionWarping,
		BlueFramework::Ifc4::IfcBoundedCurve,
		BlueFramework::Ifc4::IfcBoundedSurface,
		BlueFramework::Ifc4::IfcBoundingBox,
		BlueFramework::Ifc4::IfcBoxAlignment,
		BlueFramework::Ifc4::IfcBoxedHalfSpace,
		BlueFramework::Ifc4::IfcBSplineCurve,
		BlueFramework::Ifc4::IfcBSplineCurveForm,
		BlueFramework::Ifc4::IfcBuilding,
		BlueFramework::Ifc4::IfcBuildingElement,
		BlueFramework::Ifc4::IfcBuildingElementComponent,
		BlueFramework::Ifc4::IfcBuildingElementPart,
		BlueFramework::Ifc4::IfcBuildingElementProxy,
		BlueFramework::Ifc4::IfcBuildingElementProxyType,
		BlueFramework::Ifc4::IfcBuildingElementProxyTypeEnum,
		BlueFramework::Ifc4::IfcBuildingElementType,
		BlueFramework::Ifc4::IfcBuildingStorey,
		BlueFramework::Ifc4::IfcCableCarrierFittingType,
		BlueFramework::Ifc4::IfcCableCarrierFittingTypeEnum,
		BlueFramework::Ifc4::IfcCableCarrierSegmentType,
		BlueFramework::Ifc4::IfcCableCarrierSegmentTypeEnum,
		BlueFramework::Ifc4::IfcCableSegmentType,
		BlueFramework::Ifc4::IfcCableSegmentTypeEnum,
		BlueFramework::Ifc4::IfcCalendarDate,
		BlueFramework::Ifc4::IfcCartesianPoint,
		BlueFramework::Ifc4::IfcCartesianTransformationOperator,
		BlueFramework::Ifc4::IfcCartesianTransformationOperator2D,
		BlueFramework::Ifc4::IfcCartesianTransformationOperator2DnonUniform,
		BlueFramework::Ifc4::IfcCartesianTransformationOperator3D,
		BlueFramework::Ifc4::IfcCartesianTransformationOperator3DnonUniform,
		BlueFramework::Ifc4::IfcCenterLineProfileDef,
		BlueFramework::Ifc4::IfcChamferEdgeFeature,
		BlueFramework::Ifc4::IfcChangeActionEnum,
		BlueFramework::Ifc4::IfcCharacterStyleSelect,
		BlueFramework::Ifc4::IfcChillerType,
		BlueFramework::Ifc4::IfcChillerTypeEnum,
		BlueFramework::Ifc4::IfcCircle,
		BlueFramework::Ifc4::IfcCircleHollowProfileDef,
		BlueFramework::Ifc4::IfcCircleProfileDef,
		BlueFramework::Ifc4::IfcClassification,
		BlueFramework::Ifc4::IfcClassificationItem,
		BlueFramework::Ifc4::IfcClassificationItemRelationship,
		BlueFramework::Ifc4::IfcClassificationNotation,
		BlueFramework::Ifc4::IfcClassificationNotationFacet,
		BlueFramework::Ifc4::IfcClassificationNotationSelect,
		BlueFramework::Ifc4::IfcClassificationReference,
		BlueFramework::Ifc4::IfcClosedShell,
		BlueFramework::Ifc4::IfcCoilType,
		BlueFramework::Ifc4::IfcCoilTypeEnum,
		BlueFramework::Ifc4::IfcColour,
		BlueFramework::Ifc4::IfcColourOrFactor,
		BlueFramework::Ifc4::IfcColourRgb,
		BlueFramework::Ifc4::IfcColourSpecification,
		BlueFramework::Ifc4::IfcColumn,
		BlueFramework::Ifc4::IfcColumnType,
		BlueFramework::Ifc4::IfcColumnTypeEnum,
		BlueFramework::Ifc4::IfcComplexNumber,
		BlueFramework::Ifc4::IfcComplexProperty,
		BlueFramework::Ifc4::IfcCompositeCurve,
		BlueFramework::Ifc4::IfcCompositeCurveSegment,
		BlueFramework::Ifc4::IfcCompositeProfileDef,
		BlueFramework::Ifc4::IfcCompoundPlaneAngleMeasure,
		BlueFramework::Ifc4::IfcCompressorType,
		BlueFramework::Ifc4::IfcCompressorTypeEnum,
		BlueFramework::Ifc4::IfcCondenserType,
		BlueFramework::Ifc4::IfcCondenserTypeEnum,
		BlueFramework::Ifc4::IfcCondition,
		BlueFramework::Ifc4::IfcConditionCriterion,
		BlueFramework::Ifc4::IfcConditionCriterionSelect,
		BlueFramework::Ifc4::IfcConic,
		BlueFramework::Ifc4::IfcConnectedFaceSet,
		BlueFramework::Ifc4::IfcConnectionCurveGeometry,
		BlueFramework::Ifc4::IfcConnectionGeometry,
		BlueFramework::Ifc4::IfcConnectionPointEccentricity,
		BlueFramework::Ifc4::IfcConnectionPointGeometry,
		BlueFramework::Ifc4::IfcConnectionPortGeometry,
		BlueFramework::Ifc4::IfcConnectionSurfaceGeometry,
		BlueFramework::Ifc4::IfcConnectionTypeEnum,
		BlueFramework::Ifc4::IfcConstraint,
		BlueFramework::Ifc4::IfcConstraintAggregationRelationship,
		BlueFramework::Ifc4::IfcConstraintClassificationRelationship,
		BlueFramework::Ifc4::IfcConstraintEnum,
		BlueFramework::Ifc4::IfcConstraintRelationship,
		BlueFramework::Ifc4::IfcConstructionEquipmentResource,
		BlueFramework::Ifc4::IfcConstructionMaterialResource,
		BlueFramework::Ifc4::IfcConstructionProductResource,
		BlueFramework::Ifc4::IfcConstructionResource,
		BlueFramework::Ifc4::IfcContextDependentMeasure,
		BlueFramework::Ifc4::IfcContextDependentUnit,
		BlueFramework::Ifc4::IfcControl,
		BlueFramework::Ifc4::IfcControllerType,
		BlueFramework::Ifc4::IfcControllerTypeEnum,
		BlueFramework::Ifc4::IfcConversionBasedUnit,
		BlueFramework::Ifc4::IfcCooledBeamType,
		BlueFramework::Ifc4::IfcCooledBeamTypeEnum,
		BlueFramework::Ifc4::IfcCoolingTowerType,
		BlueFramework::Ifc4::IfcCoolingTowerTypeEnum,
		BlueFramework::Ifc4::IfcCoordinatedUniversalTimeOffset,
		BlueFramework::Ifc4::IfcCostItem,
		BlueFramework::Ifc4::IfcCostSchedule,
		BlueFramework::Ifc4::IfcCostScheduleTypeEnum,
		BlueFramework::Ifc4::IfcCostValue,
		BlueFramework::Ifc4::IfcCountMeasure,
		BlueFramework::Ifc4::IfcCovering,
		BlueFramework::Ifc4::IfcCoveringType,
		BlueFramework::Ifc4::IfcCoveringTypeEnum,
		BlueFramework::Ifc4::IfcCraneRailAShapeProfileDef,
		BlueFramework::Ifc4::IfcCraneRailFShapeProfileDef,
		BlueFramework::Ifc4::IfcCrewResource,
		BlueFramework::Ifc4::IfcCsgPrimitive3D,
		BlueFramework::Ifc4::IfcCsgSelect,
		BlueFramework::Ifc4::IfcCsgSolid,
		BlueFramework::Ifc4::IfcCShapeProfileDef,
		BlueFramework::Ifc4::IfcCurrencyEnum,
		BlueFramework::Ifc4::IfcCurrencyRelationship,
		BlueFramework::Ifc4::IfcCurtainWall,
		BlueFramework::Ifc4::IfcCurtainWallType,
		BlueFramework::Ifc4::IfcCurtainWallTypeEnum,
		BlueFramework::Ifc4::IfcCurvatureMeasure,
		BlueFramework::Ifc4::IfcCurve,
		BlueFramework::Ifc4::IfcCurveBoundedPlane,
		BlueFramework::Ifc4::IfcCurveFontOrScaledCurveFontSelect,
		BlueFramework::Ifc4::IfcCurveOrEdgeCurve,
		BlueFramework::Ifc4::IfcCurveStyle,
		BlueFramework::Ifc4::IfcCurveStyleFont,
		BlueFramework::Ifc4::IfcCurveStyleFontAndScaling,
		BlueFramework::Ifc4::IfcCurveStyleFontPattern,
		BlueFramework::Ifc4::IfcCurveStyleFontSelect,
		BlueFramework::Ifc4::IfcDamperType,
		BlueFramework::Ifc4::IfcDamperTypeEnum,
		BlueFramework::Ifc4::IfcDataOriginEnum,
		BlueFramework::Ifc4::IfcDateAndTime,
		BlueFramework::Ifc4::IfcDateTimeSelect,
		BlueFramework::Ifc4::IfcDayInMonthNumber,
		BlueFramework::Ifc4::IfcDaylightSavingHour,
		BlueFramework::Ifc4::IfcDefinedSymbol,
		BlueFramework::Ifc4::IfcDefinedSymbolSelect,
		BlueFramework::Ifc4::IfcDerivedMeasureValue,
		BlueFramework::Ifc4::IfcDerivedProfileDef,
		BlueFramework::Ifc4::IfcDerivedUnit,
		BlueFramework::Ifc4::IfcDerivedUnitElement,
		BlueFramework::Ifc4::IfcDerivedUnitEnum,
		BlueFramework::Ifc4::IfcDescriptiveMeasure,
		BlueFramework::Ifc4::IfcDiameterDimension,
		BlueFramework::Ifc4::IfcDimensionalExponents,
		BlueFramework::Ifc4::IfcDimensionCalloutRelationship,
		BlueFramework::Ifc4::IfcDimensionCount,
		BlueFramework::Ifc4::IfcDimensionCurve,
		BlueFramework::Ifc4::IfcDimensionCurveDirectedCallout,
		BlueFramework::Ifc4::IfcDimensionCurveTerminator,
		BlueFramework::Ifc4::IfcDimensionExtentUsage,
		BlueFramework::Ifc4::IfcDimensionPair,
		BlueFramework::Ifc4::IfcDirection,
		BlueFramework::Ifc4::IfcDirectionSenseEnum,
		BlueFramework::Ifc4::IfcDiscreteAccessory,
		BlueFramework::Ifc4::IfcDiscreteAccessoryType,
		BlueFramework::Ifc4::IfcDistributionChamberElement,
		BlueFramework::Ifc4::IfcDistributionChamberElementType,
		BlueFramework::Ifc4::IfcDistributionChamberElementTypeEnum,
		BlueFramework::Ifc4::IfcDistributionControlElement,
		BlueFramework::Ifc4::IfcDistributionControlElementType,
		BlueFramework::Ifc4::IfcDistributionElement,
		BlueFramework::Ifc4::IfcDistributionElementType,
		BlueFramework::Ifc4::IfcDistributionFlowElement,
		BlueFramework::Ifc4::IfcDistributionFlowElementType,
		BlueFramework::Ifc4::IfcDistributionPort,
		BlueFramework::Ifc4::IfcDocumentConfidentialityEnum,
		BlueFramework::Ifc4::IfcDocumentElectronicFormat,
		BlueFramework::Ifc4::IfcDocumentInformation,
		BlueFramework::Ifc4::IfcDocumentInformationRelationship,
		BlueFramework::Ifc4::IfcDocumentReference,
		BlueFramework::Ifc4::IfcDocumentSelect,
		BlueFramework::Ifc4::IfcDocumentStatusEnum,
		BlueFramework::Ifc4::IfcDoor,
		BlueFramework::Ifc4::IfcDoorLiningProperties,
		BlueFramework::Ifc4::IfcDoorPanelOperationEnum,
		BlueFramework::Ifc4::IfcDoorPanelPositionEnum,
		BlueFramework::Ifc4::IfcDoorPanelProperties,
		BlueFramework::Ifc4::IfcDoorStyle,
		BlueFramework::Ifc4::IfcDoorStyleConstructionEnum,
		BlueFramework::Ifc4::IfcDoorStyleOperationEnum,
		BlueFramework::Ifc4::IfcDoseEquivalentMeasure,
		BlueFramework::Ifc4::IfcDraughtingCallout,
		BlueFramework::Ifc4::IfcDraughtingCalloutElement,
		BlueFramework::Ifc4::IfcDraughtingCalloutRelationship,
		BlueFramework::Ifc4::IfcDraughtingPreDefinedColour,
		BlueFramework::Ifc4::IfcDraughtingPreDefinedCurveFont,
		BlueFramework::Ifc4::IfcDraughtingPreDefinedTextFont,
		BlueFramework::Ifc4::IfcDuctFittingType,
		BlueFramework::Ifc4::IfcDuctFittingTypeEnum,
		BlueFramework::Ifc4::IfcDuctSegmentType,
		BlueFramework::Ifc4::IfcDuctSegmentTypeEnum,
		BlueFramework::Ifc4::IfcDuctSilencerType,
		BlueFramework::Ifc4::IfcDuctSilencerTypeEnum,
		BlueFramework::Ifc4::IfcDynamicViscosityMeasure,
		BlueFramework::Ifc4::IfcEdge,
		BlueFramework::Ifc4::IfcEdgeCurve,
		BlueFramework::Ifc4::IfcEdgeFeature,
		BlueFramework::Ifc4::IfcEdgeLoop,
		BlueFramework::Ifc4::IfcElectricalBaseProperties,
		BlueFramework::Ifc4::IfcElectricalCircuit,
		BlueFramework::Ifc4::IfcElectricalElement,
		BlueFramework::Ifc4::IfcElectricApplianceType,
		BlueFramework::Ifc4::IfcElectricApplianceTypeEnum,
		BlueFramework::Ifc4::IfcElectricCapacitanceMeasure,
		BlueFramework::Ifc4::IfcElectricChargeMeasure,
		BlueFramework::Ifc4::IfcElectricConductanceMeasure,
		BlueFramework::Ifc4::IfcElectricCurrentEnum,
		BlueFramework::Ifc4::IfcElectricCurrentMeasure,
		BlueFramework::Ifc4::IfcElectricDistributionPoint,
		BlueFramework::Ifc4::IfcElectricDistributionPointFunctionEnum,
		BlueFramework::Ifc4::IfcElectricFlowStorageDeviceType,
		BlueFramework::Ifc4::IfcElectricFlowStorageDeviceTypeEnum,
		BlueFramework::Ifc4::IfcElectricGeneratorType,
		BlueFramework::Ifc4::IfcElectricGeneratorTypeEnum,
		BlueFramework::Ifc4::IfcElectricHeaterType,
		BlueFramework::Ifc4::IfcElectricHeaterTypeEnum,
		BlueFramework::Ifc4::IfcElectricMotorType,
		BlueFramework::Ifc4::IfcElectricMotorTypeEnum,
		BlueFramework::Ifc4::IfcElectricResistanceMeasure,
		BlueFramework::Ifc4::IfcElectricTimeControlType,
		BlueFramework::Ifc4::IfcElectricTimeControlTypeEnum,
		BlueFramework::Ifc4::IfcElectricVoltageMeasure,
		BlueFramework::Ifc4::IfcElement,
		BlueFramework::Ifc4::IfcElementarySurface,
		BlueFramework::Ifc4::IfcElementAssembly,
		BlueFramework::Ifc4::IfcElementAssemblyTypeEnum,
		BlueFramework::Ifc4::IfcElementComponent,
		BlueFramework::Ifc4::IfcElementComponentType,
		BlueFramework::Ifc4::IfcElementCompositionEnum,
		BlueFramework::Ifc4::IfcElementQuantity,
		BlueFramework::Ifc4::IfcElementType,
		BlueFramework::Ifc4::IfcEllipse,
		BlueFramework::Ifc4::IfcEllipseProfileDef,
		BlueFramework::Ifc4::IfcEnergyConversionDevice,
		BlueFramework::Ifc4::IfcEnergyConversionDeviceType,
		BlueFramework::Ifc4::IfcEnergyMeasure,
		BlueFramework::Ifc4::IfcEnergyProperties,
		BlueFramework::Ifc4::IfcEnergySequenceEnum,
		BlueFramework::Ifc4::IfcEnvironmentalImpactCategoryEnum,
		BlueFramework::Ifc4::IfcEnvironmentalImpactValue,
		BlueFramework::Ifc4::IfcEquipmentElement,
		BlueFramework::Ifc4::IfcEquipmentStandard,
		BlueFramework::Ifc4::IfcEvaporativeCoolerType,
		BlueFramework::Ifc4::IfcEvaporativeCoolerTypeEnum,
		BlueFramework::Ifc4::IfcEvaporatorType,
		BlueFramework::Ifc4::IfcEvaporatorTypeEnum,
		BlueFramework::Ifc4::IfcExtendedMaterialProperties,
		BlueFramework::Ifc4::IfcExternallyDefinedHatchStyle,
		BlueFramework::Ifc4::IfcExternallyDefinedSurfaceStyle,
		BlueFramework::Ifc4::IfcExternallyDefinedSymbol,
		BlueFramework::Ifc4::IfcExternallyDefinedTextFont,
		BlueFramework::Ifc4::IfcExternalReference,
		BlueFramework::Ifc4::IfcExtrudedAreaSolid,
		BlueFramework::Ifc4::IfcFace,
		BlueFramework::Ifc4::IfcFaceBasedSurfaceModel,
		BlueFramework::Ifc4::IfcFaceBound,
		BlueFramework::Ifc4::IfcFaceOuterBound,
		BlueFramework::Ifc4::IfcFaceSurface,
		BlueFramework::Ifc4::IfcFacetedBrep,
		BlueFramework::Ifc4::IfcFacetedBrepWithVoids,
		BlueFramework::Ifc4::IfcFailureConnectionCondition,
		BlueFramework::Ifc4::IfcFanType,
		BlueFramework::Ifc4::IfcFanTypeEnum,
		BlueFramework::Ifc4::IfcFastener,
		BlueFramework::Ifc4::IfcFastenerType,
		BlueFramework::Ifc4::IfcFeatureElement,
		BlueFramework::Ifc4::IfcFeatureElementAddition,
		BlueFramework::Ifc4::IfcFeatureElementSubtraction,
		BlueFramework::Ifc4::IfcFillAreaStyle,
		BlueFramework::Ifc4::IfcFillAreaStyleHatching,
		BlueFramework::Ifc4::IfcFillAreaStyleTiles,
		BlueFramework::Ifc4::IfcFillAreaStyleTileShapeSelect,
		BlueFramework::Ifc4::IfcFillAreaStyleTileSymbolWithStyle,
		BlueFramework::Ifc4::IfcFillStyleSelect,
		BlueFramework::Ifc4::IfcFilterType,
		BlueFramework::Ifc4::IfcFilterTypeEnum,
		BlueFramework::Ifc4::IfcFireSuppressionTerminalType,
		BlueFramework::Ifc4::IfcFireSuppressionTerminalTypeEnum,
		BlueFramework::Ifc4::IfcFlowController,
		BlueFramework::Ifc4::IfcFlowControllerType,
		BlueFramework::Ifc4::IfcFlowDirectionEnum,
		BlueFramework::Ifc4::IfcFlowFitting,
		BlueFramework::Ifc4::IfcFlowFittingType,
		BlueFramework::Ifc4::IfcFlowInstrumentType,
		BlueFramework::Ifc4::IfcFlowInstrumentTypeEnum,
		BlueFramework::Ifc4::IfcFlowMeterType,
		BlueFramework::Ifc4::IfcFlowMeterTypeEnum,
		BlueFramework::Ifc4::IfcFlowMovingDevice,
		BlueFramework::Ifc4::IfcFlowMovingDeviceType,
		BlueFramework::Ifc4::IfcFlowSegment,
		BlueFramework::Ifc4::IfcFlowSegmentType,
		BlueFramework::Ifc4::IfcFlowStorageDevice,
		BlueFramework::Ifc4::IfcFlowStorageDeviceType,
		BlueFramework::Ifc4::IfcFlowTerminal,
		BlueFramework::Ifc4::IfcFlowTerminalType,
		BlueFramework::Ifc4::IfcFlowTreatmentDevice,
		BlueFramework::Ifc4::IfcFlowTreatmentDeviceType,
		BlueFramework::Ifc4::IfcFluidFlowProperties,
		BlueFramework::Ifc4::IfcFontStyle,
		BlueFramework::Ifc4::IfcFontVariant,
		BlueFramework::Ifc4::IfcFontWeight,
		BlueFramework::Ifc4::IfcFooting,
		BlueFramework::Ifc4::IfcFootingTypeEnum,
		BlueFramework::Ifc4::IfcForceMeasure,
		BlueFramework::Ifc4::IfcFrequencyMeasure,
		BlueFramework::Ifc4::IfcFuelProperties,
		BlueFramework::Ifc4::IfcFurnishingElement,
		BlueFramework::Ifc4::IfcFurnishingElementType,
		BlueFramework::Ifc4::IfcFurnitureStandard,
		BlueFramework::Ifc4::IfcFurnitureType,
		BlueFramework::Ifc4::IfcGasTerminalType,
		BlueFramework::Ifc4::IfcGasTerminalTypeEnum,
		BlueFramework::Ifc4::IfcGeneralMaterialProperties,
		BlueFramework::Ifc4::IfcGeneralProfileProperties,
		BlueFramework::Ifc4::IfcGeometricCurveSet,
		BlueFramework::Ifc4::IfcGeometricProjectionEnum,
		BlueFramework::Ifc4::IfcGeometricRepresentationContext,
		BlueFramework::Ifc4::IfcGeometricRepresentationItem,
		BlueFramework::Ifc4::IfcGeometricRepresentationSubContext,
		BlueFramework::Ifc4::IfcGeometricSet,
		BlueFramework::Ifc4::IfcGeometricSetSelect,
		BlueFramework::Ifc4::IfcGloballyUniqueId,
		BlueFramework::Ifc4::IfcGlobalOrLocalEnum,
		BlueFramework::Ifc4::IfcGrid,
		BlueFramework::Ifc4::IfcGridAxis,
		BlueFramework::Ifc4::IfcGridPlacement,
		BlueFramework::Ifc4::IfcGroup,
		BlueFramework::Ifc4::IfcHalfSpaceSolid,
		BlueFramework::Ifc4::IfcHatchLineDistanceSelect,
		BlueFramework::Ifc4::IfcHeatExchangerType,
		BlueFramework::Ifc4::IfcHeatExchangerTypeEnum,
		BlueFramework::Ifc4::IfcHeatFluxDensityMeasure,
		BlueFramework::Ifc4::IfcHeatingValueMeasure,
		BlueFramework::Ifc4::IfcHourInDay,
		BlueFramework::Ifc4::IfcHumidifierType,
		BlueFramework::Ifc4::IfcHumidifierTypeEnum,
		BlueFramework::Ifc4::IfcHygroscopicMaterialProperties,
		BlueFramework::Ifc4::IfcIdentifier,
		BlueFramework::Ifc4::IfcIlluminanceMeasure,
		BlueFramework::Ifc4::IfcImageTexture,
		BlueFramework::Ifc4::IfcInductanceMeasure,
		BlueFramework::Ifc4::IfcInteger,
		BlueFramework::Ifc4::IfcIntegerCountRateMeasure,
		BlueFramework::Ifc4::IfcInternalOrExternalEnum,
		BlueFramework::Ifc4::IfcInventory,
		BlueFramework::Ifc4::IfcInventoryTypeEnum,
		BlueFramework::Ifc4::IfcIonConcentrationMeasure,
		BlueFramework::Ifc4::IfcIrregularTimeSeries,
		BlueFramework::Ifc4::IfcIrregularTimeSeriesValue,
		BlueFramework::Ifc4::IfcIShapeProfileDef,
		BlueFramework::Ifc4::IfcIsothermalMoistureCapacityMeasure,
		BlueFramework::Ifc4::IfcJunctionBoxType,
		BlueFramework::Ifc4::IfcJunctionBoxTypeEnum,
		BlueFramework::Ifc4::IfcKinematicViscosityMeasure,
		BlueFramework::Ifc4::IfcLabel,
		BlueFramework::Ifc4::IfcLaborResource,
		BlueFramework::Ifc4::IfcLampType,
		BlueFramework::Ifc4::IfcLampTypeEnum,
		BlueFramework::Ifc4::IfcLayeredItem,
		BlueFramework::Ifc4::IfcLayerSetDirectionEnum,
		BlueFramework::Ifc4::IfcLengthMeasure,
		BlueFramework::Ifc4::IfcLibraryInformation,
		BlueFramework::Ifc4::IfcLibraryReference,
		BlueFramework::Ifc4::IfcLibrarySelect,
		BlueFramework::Ifc4::IfcLightDistributionCurveEnum,
		BlueFramework::Ifc4::IfcLightDistributionData,
		BlueFramework::Ifc4::IfcLightDistributionDataSourceSelect,
		BlueFramework::Ifc4::IfcLightEmissionSourceEnum,
		BlueFramework::Ifc4::IfcLightFixtureType,
		BlueFramework::Ifc4::IfcLightFixtureTypeEnum,
		BlueFramework::Ifc4::IfcLightIntensityDistribution,
		BlueFramework::Ifc4::IfcLightSource,
		BlueFramework::Ifc4::IfcLightSourceAmbient,
		BlueFramework::Ifc4::IfcLightSourceDirectional,
		BlueFramework::Ifc4::IfcLightSourceGoniometric,
		BlueFramework::Ifc4::IfcLightSourcePositional,
		BlueFramework::Ifc4::IfcLightSourceSpot,
		BlueFramework::Ifc4::IfcLine,
		BlueFramework::Ifc4::IfcLinearDimension,
		BlueFramework::Ifc4::IfcLinearForceMeasure,
		BlueFramework::Ifc4::IfcLinearMomentMeasure,
		BlueFramework::Ifc4::IfcLinearStiffnessMeasure,
		BlueFramework::Ifc4::IfcLinearVelocityMeasure,
		BlueFramework::Ifc4::IfcLoadGroupTypeEnum,
		BlueFramework::Ifc4::IfcLocalPlacement,
		BlueFramework::Ifc4::IfcLocalTime,
		BlueFramework::Ifc4::IfcLogical,
		BlueFramework::Ifc4::IfcLogicalOperatorEnum,
		BlueFramework::Ifc4::IfcLoop,
		BlueFramework::Ifc4::IfcLShapeProfileDef,
		BlueFramework::Ifc4::IfcLuminousFluxMeasure,
		BlueFramework::Ifc4::IfcLuminousIntensityDistributionMeasure,
		BlueFramework::Ifc4::IfcLuminousIntensityMeasure,
		BlueFramework::Ifc4::IfcMagneticFluxDensityMeasure,
		BlueFramework::Ifc4::IfcMagneticFluxMeasure,
		BlueFramework::Ifc4::IfcManifoldSolidBrep,
		BlueFramework::Ifc4::IfcMappedItem,
		BlueFramework::Ifc4::IfcMassDensityMeasure,
		BlueFramework::Ifc4::IfcMassFlowRateMeasure,
		BlueFramework::Ifc4::IfcMassMeasure,
		BlueFramework::Ifc4::IfcMassPerLengthMeasure,
		BlueFramework::Ifc4::IfcMaterial,
		BlueFramework::Ifc4::IfcMaterialClassificationRelationship,
		BlueFramework::Ifc4::IfcMaterialDefinitionRepresentation,
		BlueFramework::Ifc4::IfcMaterialLayer,
		BlueFramework::Ifc4::IfcMaterialLayerSet,
		BlueFramework::Ifc4::IfcMaterialLayerSetUsage,
		BlueFramework::Ifc4::IfcMaterialList,
		BlueFramework::Ifc4::IfcMaterialProperties,
		BlueFramework::Ifc4::IfcMaterialSelect,
		BlueFramework::Ifc4::IfcMeasureValue,
		BlueFramework::Ifc4::IfcMeasureWithUnit,
		BlueFramework::Ifc4::IfcMechanicalConcreteMaterialProperties,
		BlueFramework::Ifc4::IfcMechanicalFastener,
		BlueFramework::Ifc4::IfcMechanicalFastenerType,
		BlueFramework::Ifc4::IfcMechanicalMaterialProperties,
		BlueFramework::Ifc4::IfcMechanicalSteelMaterialProperties,
		BlueFramework::Ifc4::IfcMember,
		BlueFramework::Ifc4::IfcMemberType,
		BlueFramework::Ifc4::IfcMemberTypeEnum,
		BlueFramework::Ifc4::IfcMetric,
		BlueFramework::Ifc4::IfcMetricValueSelect,
		BlueFramework::Ifc4::IfcMinuteInHour,
		BlueFramework::Ifc4::IfcModulusOfElasticityMeasure,
		BlueFramework::Ifc4::IfcModulusOfLinearSubgradeReactionMeasure,
		BlueFramework::Ifc4::IfcModulusOfRotationalSubgradeReactionMeasure,
		BlueFramework::Ifc4::IfcModulusOfSubgradeReactionMeasure,
		BlueFramework::Ifc4::IfcMoistureDiffusivityMeasure,
		BlueFramework::Ifc4::IfcMolecularWeightMeasure,
		BlueFramework::Ifc4::IfcMomentOfInertiaMeasure,
		BlueFramework::Ifc4::IfcMonetaryMeasure,
		BlueFramework::Ifc4::IfcMonetaryUnit,
		BlueFramework::Ifc4::IfcMonthInYearNumber,
		BlueFramework::Ifc4::IfcMotorConnectionType,
		BlueFramework::Ifc4::IfcMotorConnectionTypeEnum,
		BlueFramework::Ifc4::IfcMove,
		BlueFramework::Ifc4::IfcNamedUnit,
		BlueFramework::Ifc4::IfcNormalisedRatioMeasure,
		BlueFramework::Ifc4::IfcNullStyle,
		BlueFramework::Ifc4::IfcNumericMeasure,
		BlueFramework::Ifc4::IfcObject,
		BlueFramework::Ifc4::IfcObjectDefinition,
		BlueFramework::Ifc4::IfcObjective,
		BlueFramework::Ifc4::IfcObjectiveEnum,
		BlueFramework::Ifc4::IfcObjectPlacement,
		BlueFramework::Ifc4::IfcObjectReferenceSelect,
		BlueFramework::Ifc4::IfcObjectTypeEnum,
		BlueFramework::Ifc4::IfcOccupant,
		BlueFramework::Ifc4::IfcOccupantTypeEnum,
		BlueFramework::Ifc4::IfcOffsetCurve2D,
		BlueFramework::Ifc4::IfcOffsetCurve3D,
		BlueFramework::Ifc4::IfcOneDirectionRepeatFactor,
		BlueFramework::Ifc4::IfcOpeningElement,
		BlueFramework::Ifc4::IfcOpenShell,
		BlueFramework::Ifc4::IfcOpticalMaterialProperties,
		BlueFramework::Ifc4::IfcOrderAction,
		BlueFramework::Ifc4::IfcOrganization,
		BlueFramework::Ifc4::IfcOrganizationRelationship,
		BlueFramework::Ifc4::IfcOrientationSelect,
		BlueFramework::Ifc4::IfcOrientedEdge,
		BlueFramework::Ifc4::IfcOutletType,
		BlueFramework::Ifc4::IfcOutletTypeEnum,
		BlueFramework::Ifc4::IfcOwnerHistory,
		BlueFramework::Ifc4::IfcParameterizedProfileDef,
		BlueFramework::Ifc4::IfcParameterValue,
		BlueFramework::Ifc4::IfcPath,
		BlueFramework::Ifc4::IfcPerformanceHistory,
		BlueFramework::Ifc4::IfcPermeableCoveringOperationEnum,
		BlueFramework::Ifc4::IfcPermeableCoveringProperties,
		BlueFramework::Ifc4::IfcPermit,
		BlueFramework::Ifc4::IfcPerson,
		BlueFramework::Ifc4::IfcPersonAndOrganization,
		BlueFramework::Ifc4::IfcPHMeasure,
		BlueFramework::Ifc4::IfcPhysicalComplexQuantity,
		BlueFramework::Ifc4::IfcPhysicalOrVirtualEnum,
		BlueFramework::Ifc4::IfcPhysicalQuantity,
		BlueFramework::Ifc4::IfcPhysicalSimpleQuantity,
		BlueFramework::Ifc4::IfcPile,
		BlueFramework::Ifc4::IfcPileConstructionEnum,
		BlueFramework::Ifc4::IfcPileTypeEnum,
		BlueFramework::Ifc4::IfcPipeFittingType,
		BlueFramework::Ifc4::IfcPipeFittingTypeEnum,
		BlueFramework::Ifc4::IfcPipeSegmentType,
		BlueFramework::Ifc4::IfcPipeSegmentTypeEnum,
		BlueFramework::Ifc4::IfcPixelTexture,
		BlueFramework::Ifc4::IfcPlacement,
		BlueFramework::Ifc4::IfcPlanarBox,
		BlueFramework::Ifc4::IfcPlanarExtent,
		BlueFramework::Ifc4::IfcPlanarForceMeasure,
		BlueFramework::Ifc4::IfcPlane,
		BlueFramework::Ifc4::IfcPlaneAngleMeasure,
		BlueFramework::Ifc4::IfcPlate,
		BlueFramework::Ifc4::IfcPlateType,
		BlueFramework::Ifc4::IfcPlateTypeEnum,
		BlueFramework::Ifc4::IfcPoint,
		BlueFramework::Ifc4::IfcPointOnCurve,
		BlueFramework::Ifc4::IfcPointOnSurface,
		BlueFramework::Ifc4::IfcPointOrVertexPoint,
		BlueFramework::Ifc4::IfcPolygonalBoundedHalfSpace,
		BlueFramework::Ifc4::IfcPolyline,
		BlueFramework::Ifc4::IfcPolyLoop,
		BlueFramework::Ifc4::IfcPort,
		BlueFramework::Ifc4::IfcPositiveLengthMeasure,
		BlueFramework::Ifc4::IfcPositivePlaneAngleMeasure,
		BlueFramework::Ifc4::IfcPositiveRatioMeasure,
		BlueFramework::Ifc4::IfcPostalAddress,
		BlueFramework::Ifc4::IfcPowerMeasure,
		BlueFramework::Ifc4::IfcPreDefinedColour,
		BlueFramework::Ifc4::IfcPreDefinedCurveFont,
		BlueFramework::Ifc4::IfcPreDefinedDimensionSymbol,
		BlueFramework::Ifc4::IfcPreDefinedItem,
		BlueFramework::Ifc4::IfcPreDefinedPointMarkerSymbol,
		BlueFramework::Ifc4::IfcPreDefinedSymbol,
		BlueFramework::Ifc4::IfcPreDefinedTerminatorSymbol,
		BlueFramework::Ifc4::IfcPreDefinedTextFont,
		BlueFramework::Ifc4::IfcPresentableText,
		BlueFramework::Ifc4::IfcPresentationLayerAssignment,
		BlueFramework::Ifc4::IfcPresentationLayerWithStyle,
		BlueFramework::Ifc4::IfcPresentationStyle,
		BlueFramework::Ifc4::IfcPresentationStyleAssignment,
		BlueFramework::Ifc4::IfcPresentationStyleSelect,
		BlueFramework::Ifc4::IfcPressureMeasure,
		BlueFramework::Ifc4::IfcProcedure,
		BlueFramework::Ifc4::IfcProcedureTypeEnum,
		BlueFramework::Ifc4::IfcProcess,
		BlueFramework::Ifc4::IfcProduct,
		BlueFramework::Ifc4::IfcProductDefinitionShape,
		BlueFramework::Ifc4::IfcProductRepresentation,
		BlueFramework::Ifc4::IfcProductsOfCombustionProperties,
		BlueFramework::Ifc4::IfcProfileDef,
		BlueFramework::Ifc4::IfcProfileProperties,
		BlueFramework::Ifc4::IfcProfileTypeEnum,
		BlueFramework::Ifc4::IfcProject,
		BlueFramework::Ifc4::IfcProjectedOrTrueLengthEnum,
		BlueFramework::Ifc4::IfcProjectionCurve,
		BlueFramework::Ifc4::IfcProjectionElement,
		BlueFramework::Ifc4::IfcProjectOrder,
		BlueFramework::Ifc4::IfcProjectOrderRecord,
		BlueFramework::Ifc4::IfcProjectOrderRecordTypeEnum,
		BlueFramework::Ifc4::IfcProjectOrderTypeEnum,
		BlueFramework::Ifc4::IfcProperty,
		BlueFramework::Ifc4::IfcPropertyBoundedValue,
		BlueFramework::Ifc4::IfcPropertyConstraintRelationship,
		BlueFramework::Ifc4::IfcPropertyDefinition,
		BlueFramework::Ifc4::IfcPropertyDependencyRelationship,
		BlueFramework::Ifc4::IfcPropertyEnumeratedValue,
		BlueFramework::Ifc4::IfcPropertyEnumeration,
		BlueFramework::Ifc4::IfcPropertyListValue,
		BlueFramework::Ifc4::IfcPropertyReferenceValue,
		BlueFramework::Ifc4::IfcPropertySet,
		BlueFramework::Ifc4::IfcPropertySetDefinition,
		BlueFramework::Ifc4::IfcPropertySingleValue,
		BlueFramework::Ifc4::IfcPropertySourceEnum,
		BlueFramework::Ifc4::IfcPropertyTableValue,
		BlueFramework::Ifc4::IfcProtectiveDeviceType,
		BlueFramework::Ifc4::IfcProtectiveDeviceTypeEnum,
		BlueFramework::Ifc4::IfcProxy,
		BlueFramework::Ifc4::IfcPumpType,
		BlueFramework::Ifc4::IfcPumpTypeEnum,
		BlueFramework::Ifc4::IfcQuantityArea,
		BlueFramework::Ifc4::IfcQuantityCount,
		BlueFramework::Ifc4::IfcQuantityLength,
		BlueFramework::Ifc4::IfcQuantityTime,
		BlueFramework::Ifc4::IfcQuantityVolume,
		BlueFramework::Ifc4::IfcQuantityWeight,
		BlueFramework::Ifc4::IfcRadioActivityMeasure,
		BlueFramework::Ifc4::IfcRadiusDimension,
		BlueFramework::Ifc4::IfcRailing,
		BlueFramework::Ifc4::IfcRailingType,
		BlueFramework::Ifc4::IfcRailingTypeEnum,
		BlueFramework::Ifc4::IfcRamp,
		BlueFramework::Ifc4::IfcRampFlight,
		BlueFramework::Ifc4::IfcRampFlightType,
		BlueFramework::Ifc4::IfcRampFlightTypeEnum,
		BlueFramework::Ifc4::IfcRampTypeEnum,
		BlueFramework::Ifc4::IfcRatioMeasure,
		BlueFramework::Ifc4::IfcRationalBezierCurve,
		BlueFramework::Ifc4::IfcReal,
		BlueFramework::Ifc4::IfcRectangleHollowProfileDef,
		BlueFramework::Ifc4::IfcRectangleProfileDef,
		BlueFramework::Ifc4::IfcRectangularPyramid,
		BlueFramework::Ifc4::IfcRectangularTrimmedSurface,
		BlueFramework::Ifc4::IfcReferencesValueDocument,
		BlueFramework::Ifc4::IfcReflectanceMethodEnum,
		BlueFramework::Ifc4::IfcRegularTimeSeries,
		BlueFramework::Ifc4::IfcReinforcementBarProperties,
		BlueFramework::Ifc4::IfcReinforcementDefinitionProperties,
		BlueFramework::Ifc4::IfcReinforcingBar,
		BlueFramework::Ifc4::IfcReinforcingBarRoleEnum,
		BlueFramework::Ifc4::IfcReinforcingBarSurfaceEnum,
		BlueFramework::Ifc4::IfcReinforcingElement,
		BlueFramework::Ifc4::IfcReinforcingMesh,
		BlueFramework::Ifc4::IfcRelAggregates,
		BlueFramework::Ifc4::IfcRelAssigns,
		BlueFramework::Ifc4::IfcRelAssignsTasks,
		BlueFramework::Ifc4::IfcRelAssignsToActor,
		BlueFramework::Ifc4::IfcRelAssignsToControl,
		BlueFramework::Ifc4::IfcRelAssignsToGroup,
		BlueFramework::Ifc4::IfcRelAssignsToProcess,
		BlueFramework::Ifc4::IfcRelAssignsToProduct,
		BlueFramework::Ifc4::IfcRelAssignsToProjectOrder,
		BlueFramework::Ifc4::IfcRelAssignsToResource,
		BlueFramework::Ifc4::IfcRelAssociates,
		BlueFramework::Ifc4::IfcRelAssociatesAppliedValue,
		BlueFramework::Ifc4::IfcRelAssociatesApproval,
		BlueFramework::Ifc4::IfcRelAssociatesClassification,
		BlueFramework::Ifc4::IfcRelAssociatesConstraint,
		BlueFramework::Ifc4::IfcRelAssociatesDocument,
		BlueFramework::Ifc4::IfcRelAssociatesLibrary,
		BlueFramework::Ifc4::IfcRelAssociatesMaterial,
		BlueFramework::Ifc4::IfcRelAssociatesProfileProperties,
		BlueFramework::Ifc4::IfcRelationship,
		BlueFramework::Ifc4::IfcRelaxation,
		BlueFramework::Ifc4::IfcRelConnects,
		BlueFramework::Ifc4::IfcRelConnectsElements,
		BlueFramework::Ifc4::IfcRelConnectsPathElements,
		BlueFramework::Ifc4::IfcRelConnectsPorts,
		BlueFramework::Ifc4::IfcRelConnectsPortToElement,
		BlueFramework::Ifc4::IfcRelConnectsStructuralActivity,
		BlueFramework::Ifc4::IfcRelConnectsStructuralElement,
		BlueFramework::Ifc4::IfcRelConnectsStructuralMember,
		BlueFramework::Ifc4::IfcRelConnectsWithEccentricity,
		BlueFramework::Ifc4::IfcRelConnectsWithRealizingElements,
		BlueFramework::Ifc4::IfcRelContainedInSpatialStructure,
		BlueFramework::Ifc4::IfcRelCoversBldgElements,
		BlueFramework::Ifc4::IfcRelCoversSpaces,
		BlueFramework::Ifc4::IfcRelDecomposes,
		BlueFramework::Ifc4::IfcRelDefines,
		BlueFramework::Ifc4::IfcRelDefinesByProperties,
		BlueFramework::Ifc4::IfcRelDefinesByType,
		BlueFramework::Ifc4::IfcRelFillsElement,
		BlueFramework::Ifc4::IfcRelFlowControlElements,
		BlueFramework::Ifc4::IfcRelInteractionRequirements,
		BlueFramework::Ifc4::IfcRelNests,
		BlueFramework::Ifc4::IfcRelOccupiesSpaces,
		BlueFramework::Ifc4::IfcRelOverridesProperties,
		BlueFramework::Ifc4::IfcRelProjectsElement,
		BlueFramework::Ifc4::IfcRelReferencedInSpatialStructure,
		BlueFramework::Ifc4::IfcRelSchedulesCostItems,
		BlueFramework::Ifc4::IfcRelSequence,
		BlueFramework::Ifc4::IfcRelServicesBuildings,
		BlueFramework::Ifc4::IfcRelSpaceBoundary,
		BlueFramework::Ifc4::IfcRelVoidsElement,
		BlueFramework::Ifc4::IfcRepresentation,
		BlueFramework::Ifc4::IfcRepresentationContext,
		BlueFramework::Ifc4::IfcRepresentationItem,
		BlueFramework::Ifc4::IfcRepresentationMap,
		BlueFramework::Ifc4::IfcResource,
		BlueFramework::Ifc4::IfcResourceConsumptionEnum,
		BlueFramework::Ifc4::IfcRevolvedAreaSolid,
		BlueFramework::Ifc4::IfcRibPlateDirectionEnum,
		BlueFramework::Ifc4::IfcRibPlateProfileProperties,
		BlueFramework::Ifc4::IfcRightCircularCone,
		BlueFramework::Ifc4::IfcRightCircularCylinder,
		BlueFramework::Ifc4::IfcRoleEnum,
		BlueFramework::Ifc4::IfcRoof,
		BlueFramework::Ifc4::IfcRoofTypeEnum,
		BlueFramework::Ifc4::IfcRoot,
		BlueFramework::Ifc4::IfcRotationalFrequencyMeasure,
		BlueFramework::Ifc4::IfcRotationalMassMeasure,
		BlueFramework::Ifc4::IfcRotationalStiffnessMeasure,
		BlueFramework::Ifc4::IfcRoundedEdgeFeature,
		BlueFramework::Ifc4::IfcRoundedRectangleProfileDef,
		BlueFramework::Ifc4::IfcSanitaryTerminalType,
		BlueFramework::Ifc4::IfcSanitaryTerminalTypeEnum,
		BlueFramework::Ifc4::IfcScheduleTimeControl,
		BlueFramework::Ifc4::IfcSecondInMinute,
		BlueFramework::Ifc4::IfcSectionalAreaIntegralMeasure,
		BlueFramework::Ifc4::IfcSectionedSpine,
		BlueFramework::Ifc4::IfcSectionModulusMeasure,
		BlueFramework::Ifc4::IfcSectionProperties,
		BlueFramework::Ifc4::IfcSectionReinforcementProperties,
		BlueFramework::Ifc4::IfcSectionTypeEnum,
		BlueFramework::Ifc4::IfcSensorType,
		BlueFramework::Ifc4::IfcSensorTypeEnum,
		BlueFramework::Ifc4::IfcSequenceEnum,
		BlueFramework::Ifc4::IfcServiceLife,
		BlueFramework::Ifc4::IfcServiceLifeFactor,
		BlueFramework::Ifc4::IfcServiceLifeFactorTypeEnum,
		BlueFramework::Ifc4::IfcServiceLifeTypeEnum,
		BlueFramework::Ifc4::IfcShapeAspect,
		BlueFramework::Ifc4::IfcShapeModel,
		BlueFramework::Ifc4::IfcShapeRepresentation,
		BlueFramework::Ifc4::IfcShearModulusMeasure,
		BlueFramework::Ifc4::IfcShell,
		BlueFramework::Ifc4::IfcShellBasedSurfaceModel,
		BlueFramework::Ifc4::IfcSimpleProperty,
		BlueFramework::Ifc4::IfcSimpleValue,
		BlueFramework::Ifc4::IfcSIPrefix,
		BlueFramework::Ifc4::IfcSite,
		BlueFramework::Ifc4::IfcSIUnit,
		BlueFramework::Ifc4::IfcSIUnitName,
		BlueFramework::Ifc4::IfcSizeSelect,
		BlueFramework::Ifc4::IfcSlab,
		BlueFramework::Ifc4::IfcSlabType,
		BlueFramework::Ifc4::IfcSlabTypeEnum,
		BlueFramework::Ifc4::IfcSlippageConnectionCondition,
		BlueFramework::Ifc4::IfcSolidAngleMeasure,
		BlueFramework::Ifc4::IfcSolidModel,
		BlueFramework::Ifc4::IfcSoundPowerMeasure,
		BlueFramework::Ifc4::IfcSoundPressureMeasure,
		BlueFramework::Ifc4::IfcSoundProperties,
		BlueFramework::Ifc4::IfcSoundScaleEnum,
		BlueFramework::Ifc4::IfcSoundValue,
		BlueFramework::Ifc4::IfcSpace,
		BlueFramework::Ifc4::IfcSpaceHeaterType,
		BlueFramework::Ifc4::IfcSpaceHeaterTypeEnum,
		BlueFramework::Ifc4::IfcSpaceProgram,
		BlueFramework::Ifc4::IfcSpaceThermalLoadProperties,
		BlueFramework::Ifc4::IfcSpaceType,
		BlueFramework::Ifc4::IfcSpaceTypeEnum,
		BlueFramework::Ifc4::IfcSpatialStructureElement,
		BlueFramework::Ifc4::IfcSpatialStructureElementType,
		BlueFramework::Ifc4::IfcSpecificHeatCapacityMeasure,
		BlueFramework::Ifc4::IfcSpecularExponent,
		BlueFramework::Ifc4::IfcSpecularHighlightSelect,
		BlueFramework::Ifc4::IfcSpecularRoughness,
		BlueFramework::Ifc4::IfcSphere,
		BlueFramework::Ifc4::IfcStackTerminalType,
		BlueFramework::Ifc4::IfcStackTerminalTypeEnum,
		BlueFramework::Ifc4::IfcStair,
		BlueFramework::Ifc4::IfcStairFlight,
		BlueFramework::Ifc4::IfcStairFlightType,
		BlueFramework::Ifc4::IfcStairFlightTypeEnum,
		BlueFramework::Ifc4::IfcStairTypeEnum,
		BlueFramework::Ifc4::IfcStateEnum,
		BlueFramework::Ifc4::IfcStructuralAction,
		BlueFramework::Ifc4::IfcStructuralActivity,
		BlueFramework::Ifc4::IfcStructuralActivityAssignmentSelect,
		BlueFramework::Ifc4::IfcStructuralAnalysisModel,
		BlueFramework::Ifc4::IfcStructuralConnection,
		BlueFramework::Ifc4::IfcStructuralConnectionCondition,
		BlueFramework::Ifc4::IfcStructuralCurveConnection,
		BlueFramework::Ifc4::IfcStructuralCurveMember,
		BlueFramework::Ifc4::IfcStructuralCurveMemberVarying,
		BlueFramework::Ifc4::IfcStructuralCurveTypeEnum,
		BlueFramework::Ifc4::IfcStructuralItem,
		BlueFramework::Ifc4::IfcStructuralLinearAction,
		BlueFramework::Ifc4::IfcStructuralLinearActionVarying,
		BlueFramework::Ifc4::IfcStructuralLoad,
		BlueFramework::Ifc4::IfcStructuralLoadGroup,
		BlueFramework::Ifc4::IfcStructuralLoadLinearForce,
		BlueFramework::Ifc4::IfcStructuralLoadPlanarForce,
		BlueFramework::Ifc4::IfcStructuralLoadSingleDisplacement,
		BlueFramework::Ifc4::IfcStructuralLoadSingleDisplacementDistortion,
		BlueFramework::Ifc4::IfcStructuralLoadSingleForce,
		BlueFramework::Ifc4::IfcStructuralLoadSingleForceWarping,
		BlueFramework::Ifc4::IfcStructuralLoadStatic,
		BlueFramework::Ifc4::IfcStructuralLoadTemperature,
		BlueFramework::Ifc4::IfcStructuralMember,
		BlueFramework::Ifc4::IfcStructuralPlanarAction,
		BlueFramework::Ifc4::IfcStructuralPlanarActionVarying,
		BlueFramework::Ifc4::IfcStructuralPointAction,
		BlueFramework::Ifc4::IfcStructuralPointConnection,
		BlueFramework::Ifc4::IfcStructuralPointReaction,
		BlueFramework::Ifc4::IfcStructuralProfileProperties,
		BlueFramework::Ifc4::IfcStructuralReaction,
		BlueFramework::Ifc4::IfcStructuralResultGroup,
		BlueFramework::Ifc4::IfcStructuralSteelProfileProperties,
		BlueFramework::Ifc4::IfcStructuralSurfaceConnection,
		BlueFramework::Ifc4::IfcStructuralSurfaceMember,
		BlueFramework::Ifc4::IfcStructuralSurfaceMemberVarying,
		BlueFramework::Ifc4::IfcStructuralSurfaceTypeEnum,
		BlueFramework::Ifc4::IfcStructuredDimensionCallout,
		BlueFramework::Ifc4::IfcStyledItem,
		BlueFramework::Ifc4::IfcStyledRepresentation,
		BlueFramework::Ifc4::IfcStyleModel,
		BlueFramework::Ifc4::IfcSubContractResource,
		BlueFramework::Ifc4::IfcSubedge,
		BlueFramework::Ifc4::IfcSurface,
		BlueFramework::Ifc4::IfcSurfaceCurveSweptAreaSolid,
		BlueFramework::Ifc4::IfcSurfaceOfLinearExtrusion,
		BlueFramework::Ifc4::IfcSurfaceOfRevolution,
		BlueFramework::Ifc4::IfcSurfaceOrFaceSurface,
		BlueFramework::Ifc4::IfcSurfaceSide,
		BlueFramework::Ifc4::IfcSurfaceStyle,
		BlueFramework::Ifc4::IfcSurfaceStyleElementSelect,
		BlueFramework::Ifc4::IfcSurfaceStyleLighting,
		BlueFramework::Ifc4::IfcSurfaceStyleRefraction,
		BlueFramework::Ifc4::IfcSurfaceStyleRendering,
		BlueFramework::Ifc4::IfcSurfaceStyleShading,
		BlueFramework::Ifc4::IfcSurfaceStyleWithTextures,
		BlueFramework::Ifc4::IfcSurfaceTexture,
		BlueFramework::Ifc4::IfcSurfaceTextureEnum,
		BlueFramework::Ifc4::IfcSweptAreaSolid,
		BlueFramework::Ifc4::IfcSweptDiskSolid,
		BlueFramework::Ifc4::IfcSweptSurface,
		BlueFramework::Ifc4::IfcSwitchingDeviceType,
		BlueFramework::Ifc4::IfcSwitchingDeviceTypeEnum,
		BlueFramework::Ifc4::IfcSymbolStyle,
		BlueFramework::Ifc4::IfcSymbolStyleSelect,
		BlueFramework::Ifc4::IfcSystem,
		BlueFramework::Ifc4::IfcSystemFurnitureElementType,
		BlueFramework::Ifc4::IfcTable,
		BlueFramework::Ifc4::IfcTableRow,
		BlueFramework::Ifc4::IfcTankType,
		BlueFramework::Ifc4::IfcTankTypeEnum,
		BlueFramework::Ifc4::IfcTask,
		BlueFramework::Ifc4::IfcTelecomAddress,
		BlueFramework::Ifc4::IfcTemperatureGradientMeasure,
		BlueFramework::Ifc4::IfcTendon,
		BlueFramework::Ifc4::IfcTendonAnchor,
		BlueFramework::Ifc4::IfcTendonTypeEnum,
		BlueFramework::Ifc4::IfcTerminatorSymbol,
		BlueFramework::Ifc4::IfcText,
		BlueFramework::Ifc4::IfcTextAlignment,
		BlueFramework::Ifc4::IfcTextDecoration,
		BlueFramework::Ifc4::IfcTextFontName,
		BlueFramework::Ifc4::IfcTextFontSelect,
		BlueFramework::Ifc4::IfcTextLiteral,
		BlueFramework::Ifc4::IfcTextLiteralWithExtent,
		BlueFramework::Ifc4::IfcTextPath,
		BlueFramework::Ifc4::IfcTextStyle,
		BlueFramework::Ifc4::IfcTextStyleFontModel,
		BlueFramework::Ifc4::IfcTextStyleForDefinedFont,
		BlueFramework::Ifc4::IfcTextStyleSelect,
		BlueFramework::Ifc4::IfcTextStyleTextModel,
		BlueFramework::Ifc4::IfcTextStyleWithBoxCharacteristics,
		BlueFramework::Ifc4::IfcTextTransformation,
		BlueFramework::Ifc4::IfcTextureCoordinate,
		BlueFramework::Ifc4::IfcTextureCoordinateGenerator,
		BlueFramework::Ifc4::IfcTextureMap,
		BlueFramework::Ifc4::IfcTextureVertex,
		BlueFramework::Ifc4::IfcThermalAdmittanceMeasure,
		BlueFramework::Ifc4::IfcThermalConductivityMeasure,
		BlueFramework::Ifc4::IfcThermalExpansionCoefficientMeasure,
		BlueFramework::Ifc4::IfcThermalLoadSourceEnum,
		BlueFramework::Ifc4::IfcThermalLoadTypeEnum,
		BlueFramework::Ifc4::IfcThermalMaterialProperties,
		BlueFramework::Ifc4::IfcThermalResistanceMeasure,
		BlueFramework::Ifc4::IfcThermalTransmittanceMeasure,
		BlueFramework::Ifc4::IfcThermodynamicTemperatureMeasure,
		BlueFramework::Ifc4::IfcTimeMeasure,
		BlueFramework::Ifc4::IfcTimeSeries,
		BlueFramework::Ifc4::IfcTimeSeriesDataTypeEnum,
		BlueFramework::Ifc4::IfcTimeSeriesReferenceRelationship,
		BlueFramework::Ifc4::IfcTimeSeriesSchedule,
		BlueFramework::Ifc4::IfcTimeSeriesScheduleTypeEnum,
		BlueFramework::Ifc4::IfcTimeSeriesValue,
		BlueFramework::Ifc4::IfcTimeStamp,
		BlueFramework::Ifc4::IfcTopologicalRepresentationItem,
		BlueFramework::Ifc4::IfcTopologyRepresentation,
		BlueFramework::Ifc4::IfcTorqueMeasure,
		BlueFramework::Ifc4::IfcTransformerType,
		BlueFramework::Ifc4::IfcTransformerTypeEnum,
		BlueFramework::Ifc4::IfcTransitionCode,
		BlueFramework::Ifc4::IfcTransportElement,
		BlueFramework::Ifc4::IfcTransportElementType,
		BlueFramework::Ifc4::IfcTransportElementTypeEnum,
		BlueFramework::Ifc4::IfcTrapeziumProfileDef,
		BlueFramework::Ifc4::IfcTrimmedCurve,
		BlueFramework::Ifc4::IfcTrimmingPreference,
		BlueFramework::Ifc4::IfcTrimmingSelect,
		BlueFramework::Ifc4::IfcTShapeProfileDef,
		BlueFramework::Ifc4::IfcTubeBundleType,
		BlueFramework::Ifc4::IfcTubeBundleTypeEnum,
		BlueFramework::Ifc4::IfcTwoDirectionRepeatFactor,
		BlueFramework::Ifc4::IfcTypeObject,
		BlueFramework::Ifc4::IfcTypeProduct,
		BlueFramework::Ifc4::IfcUnit,
		BlueFramework::Ifc4::IfcUnitaryEquipmentType,
		BlueFramework::Ifc4::IfcUnitaryEquipmentTypeEnum,
		BlueFramework::Ifc4::IfcUnitAssignment,
		BlueFramework::Ifc4::IfcUnitEnum,
		BlueFramework::Ifc4::IfcUShapeProfileDef,
		BlueFramework::Ifc4::IfcValue,
		BlueFramework::Ifc4::IfcValveType,
		BlueFramework::Ifc4::IfcValveTypeEnum,
		BlueFramework::Ifc4::IfcVaporPermeabilityMeasure,
		BlueFramework::Ifc4::IfcVector,
		BlueFramework::Ifc4::IfcVectorOrDirection,
		BlueFramework::Ifc4::IfcVertex,
		BlueFramework::Ifc4::IfcVertexBasedTextureMap,
		BlueFramework::Ifc4::IfcVertexLoop,
		BlueFramework::Ifc4::IfcVertexPoint,
		BlueFramework::Ifc4::IfcVibrationIsolatorType,
		BlueFramework::Ifc4::IfcVibrationIsolatorTypeEnum,
		BlueFramework::Ifc4::IfcVirtualElement,
		BlueFramework::Ifc4::IfcVirtualGridIntersection,
		BlueFramework::Ifc4::IfcVolumeMeasure,
		BlueFramework::Ifc4::IfcVolumetricFlowRateMeasure,
		BlueFramework::Ifc4::IfcWall,
		BlueFramework::Ifc4::IfcWallStandardCase,
		BlueFramework::Ifc4::IfcWallType,
		BlueFramework::Ifc4::IfcWallTypeEnum,
		BlueFramework::Ifc4::IfcWarpingConstantMeasure,
		BlueFramework::Ifc4::IfcWarpingMomentMeasure,
		BlueFramework::Ifc4::IfcWasteTerminalType,
		BlueFramework::Ifc4::IfcWasteTerminalTypeEnum,
		BlueFramework::Ifc4::IfcWaterProperties,
		BlueFramework::Ifc4::IfcWindow,
		BlueFramework::Ifc4::IfcWindowLiningProperties,
		BlueFramework::Ifc4::IfcWindowPanelOperationEnum,
		BlueFramework::Ifc4::IfcWindowPanelPositionEnum,
		BlueFramework::Ifc4::IfcWindowPanelProperties,
		BlueFramework::Ifc4::IfcWindowStyle,
		BlueFramework::Ifc4::IfcWindowStyleConstructionEnum,
		BlueFramework::Ifc4::IfcWindowStyleOperationEnum,
		BlueFramework::Ifc4::IfcWorkControl,
		BlueFramework::Ifc4::IfcWorkControlTypeEnum,
		BlueFramework::Ifc4::IfcWorkPlan,
		BlueFramework::Ifc4::IfcWorkSchedule,
		BlueFramework::Ifc4::IfcYearNumber,
		BlueFramework::Ifc4::IfcZone,
		BlueFramework::Ifc4::IfcZShapeProfileDef
	>
	Ifc4EntityTypes;
}
