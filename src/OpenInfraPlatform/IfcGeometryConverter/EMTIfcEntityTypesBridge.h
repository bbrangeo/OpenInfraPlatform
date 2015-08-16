#pragma once

namespace emt
{
	template <
		typename IfcAbsorbedDoseMeasureType,
		typename IfcAccelerationMeasureType,
		typename IfcActionRequestType,
		typename IfcActionRequestTypeEnumType,
		typename IfcActionSourceTypeEnumType,
		typename IfcActionTypeEnumType,
		typename IfcActorType,
		typename IfcActorRoleType,
		typename IfcActorSelectType,
		typename IfcActuatorType,
		typename IfcActuatorTypeType,
		typename IfcActuatorTypeEnumType,
		typename IfcAddressType,
		typename IfcAddressTypeEnumType,
		typename IfcAdvancedBrepType,
		typename IfcAdvancedBrepWithVoidsType,
		typename IfcAdvancedFaceType,
		typename IfcAirTerminalType,
		typename IfcAirTerminalBoxType,
		typename IfcAirTerminalBoxTypeType,
		typename IfcAirTerminalBoxTypeEnumType,
		typename IfcAirTerminalTypeType,
		typename IfcAirTerminalTypeEnumType,
		typename IfcAirToAirHeatRecoveryType,
		typename IfcAirToAirHeatRecoveryTypeType,
		typename IfcAirToAirHeatRecoveryTypeEnumType,
		typename IfcAlarmType,
		typename IfcAlarmTypeType,
		typename IfcAlarmTypeEnumType,
		typename IfcAlignmentElementType,
		typename IfcAmountOfSubstanceMeasureType,
		typename IfcAnalysisModelTypeEnumType,
		typename IfcAnalysisTheoryTypeEnumType,
		typename IfcAngularVelocityMeasureType,
		typename IfcAnnotationType,
		typename IfcAnnotationFillAreaType,
		typename IfcApplicationType,
		typename IfcAppliedValueType,
		typename IfcAppliedValueRelationshipType,
		typename IfcAppliedValueSelectType,
		typename IfcApprovalType,
		typename IfcApprovalRelationshipType,
		typename IfcArbitraryClosedProfileDefType,
		typename IfcArbitraryOpenProfileDefType,
		typename IfcArbitraryProfileDefWithVoidsType,
		typename IfcAreaMeasureType,
		typename IfcArithmeticOperatorEnumType,
		typename IfcAssemblyPlaceEnumType,
		typename IfcAssetType,
		typename IfcAsymmetricIShapeProfileDefType,
		typename IfcAudioVisualApplianceType,
		typename IfcAudioVisualApplianceTypeType,
		typename IfcAudioVisualApplianceTypeEnumType,
		typename IfcAxis1PlacementType,
		typename IfcAxis2PlacementType,
		typename IfcAxis2Placement2DType,
		typename IfcAxis2Placement3DType,
		typename IfcBeamType,
		typename IfcBeamStandardCaseType,
		typename IfcBeamTypeType,
		typename IfcBeamTypeEnumType,
		typename IfcBenchmarkEnumType,
		typename IfcBendingParameterSelectType,
		typename IfcBlobTextureType,
		typename IfcBlockType,
		typename IfcBoilerType,
		typename IfcBoilerTypeType,
		typename IfcBoilerTypeEnumType,
		typename IfcBooleanType,
		typename IfcBooleanClippingResultType,
		typename IfcBooleanOperandType,
		typename IfcBooleanOperatorType,
		typename IfcBooleanResultType,
		typename IfcBoundaryConditionType,
		typename IfcBoundaryCurveType,
		typename IfcBoundaryEdgeConditionType,
		typename IfcBoundaryFaceConditionType,
		typename IfcBoundaryNodeConditionType,
		typename IfcBoundaryNodeConditionWarpingType,
		typename IfcBoundedCurveType,
		typename IfcBoundedSurfaceType,
		typename IfcBoundingBoxType,
		typename IfcBoxAlignmentType,
		typename IfcBoxedHalfSpaceType,
		typename IfcBridgeType,
		typename IfcBridgeContactElementType,
		typename IfcBridgeContactTypeType,
		typename IfcBridgeElementType,
		typename IfcBridgeMechanicalRoleTypeType,
		typename IfcBridgePartType,
		typename IfcBridgePrismaticElementType,
		typename IfcBridgePrismaticElementTypeType,
		typename IfcBridgeSegmentType,
		typename IfcBridgeSegmentPartType,
		typename IfcBridgeSegmentTypeType,
		typename IfcBridgeStructureElementType,
		typename IfcBridgeStructureElementTypeType,
		typename IfcBridgeStructureIndicatorType,
		typename IfcBridgeStructureTypeType,
		typename IfcBridgeSubPartTypeType,
		typename IfcBridgeTechnologicalElementTypeType,
		typename IfcBSplineCurveType,
		typename IfcBSplineCurveFormType,
		typename IfcBSplineCurveWithKnotsType,
		typename IfcBSplineSurfaceType,
		typename IfcBSplineSurfaceFormType,
		typename IfcBSplineSurfaceWithKnotsType,
		typename IfcBuildingType,
		typename IfcBuildingElementType,
		typename IfcBuildingElementPartType,
		typename IfcBuildingElementPartTypeType,
		typename IfcBuildingElementPartTypeEnumType,
		typename IfcBuildingElementProxyType,
		typename IfcBuildingElementProxyTypeType,
		typename IfcBuildingElementProxyTypeEnumType,
		typename IfcBuildingElementTypeType,
		typename IfcBuildingStoreyType,
		typename IfcBuildingSystemType,
		typename IfcBuildingSystemTypeEnumType,
		typename IfcBurnerType,
		typename IfcBurnerTypeType,
		typename IfcBurnerTypeEnumType,
		typename IfcCableCarrierFittingType,
		typename IfcCableCarrierFittingTypeType,
		typename IfcCableCarrierFittingTypeEnumType,
		typename IfcCableCarrierSegmentType,
		typename IfcCableCarrierSegmentTypeType,
		typename IfcCableCarrierSegmentTypeEnumType,
		typename IfcCableFittingType,
		typename IfcCableFittingTypeType,
		typename IfcCableFittingTypeEnumType,
		typename IfcCableSegmentType,
		typename IfcCableSegmentTypeType,
		typename IfcCableSegmentTypeEnumType,
		typename IfcCardinalPointReferenceType,
		typename IfcCartesianPointType,
		typename IfcCartesianPointListType,
		typename IfcCartesianTransformationOperatorType,
		typename IfcCartesianTransformationOperator2DType,
		typename IfcCartesianTransformationOperator2DnonUniformType,
		typename IfcCartesianTransformationOperator3DType,
		typename IfcCartesianTransformationOperator3DnonUniformType,
		typename IfcCenterLineProfileDefType,
		typename IfcChangeActionEnumType,
		typename IfcCharacterStyleSelectType,
		typename IfcChillerType,
		typename IfcChillerTypeType,
		typename IfcChillerTypeEnumType,
		typename IfcChimneyType,
		typename IfcChimneyTypeType,
		typename IfcChimneyTypeEnumType,
		typename IfcCircleType,
		typename IfcCircleHollowProfileDefType,
		typename IfcCircleProfileDefType,
		typename IfcCivilElementType,
		typename IfcCivilElementPartType,
		typename IfcCivilSheathType,
		typename IfcCivilStructureElementType,
		typename IfcCivilVoidType,
		typename IfcClassificationType,
		typename IfcClassificationReferenceType,
		typename IfcClassificationReferenceSelectType,
		typename IfcClassificationSelectType,
		typename IfcClosedShellType,
		typename IfcClothoidType,
		typename IfcCoilType,
		typename IfcCoilTypeType,
		typename IfcCoilTypeEnumType,
		typename IfcColourType,
		typename IfcColourOrFactorType,
		typename IfcColourRgbType,
		typename IfcColourRgbListType,
		typename IfcColourSpecificationType,
		typename IfcColumnType,
		typename IfcColumnStandardCaseType,
		typename IfcColumnTypeType,
		typename IfcColumnTypeEnumType,
		typename IfcCommunicationsApplianceType,
		typename IfcCommunicationsApplianceTypeType,
		typename IfcCommunicationsApplianceTypeEnumType,
		typename IfcComplexNumberType,
		typename IfcComplexPropertyType,
		typename IfcComplexPropertyTemplateType,
		typename IfcComplexPropertyTemplateTypeEnumType,
		typename IfcCompositeCurveType,
		typename IfcCompositeCurveOnSurfaceType,
		typename IfcCompositeCurveSegmentType,
		typename IfcCompositeProfileDefType,
		typename IfcCompoundPlaneAngleMeasureType,
		typename IfcCompressorType,
		typename IfcCompressorTypeType,
		typename IfcCompressorTypeEnumType,
		typename IfcCondenserType,
		typename IfcCondenserTypeType,
		typename IfcCondenserTypeEnumType,
		typename IfcConicType,
		typename IfcConnectedFaceSetType,
		typename IfcConnectionCurveGeometryType,
		typename IfcConnectionGeometryType,
		typename IfcConnectionPointEccentricityType,
		typename IfcConnectionPointGeometryType,
		typename IfcConnectionSurfaceGeometryType,
		typename IfcConnectionTypeEnumType,
		typename IfcConnectionVolumeGeometryType,
		typename IfcConstraintType,
		typename IfcConstraintEnumType,
		typename IfcConstructionEquipmentResourceType,
		typename IfcConstructionEquipmentResourceTypeType,
		typename IfcConstructionEquipmentResourceTypeEnumType,
		typename IfcConstructionMaterialResourceType,
		typename IfcConstructionMaterialResourceTypeType,
		typename IfcConstructionMaterialResourceTypeEnumType,
		typename IfcConstructionProductResourceType,
		typename IfcConstructionProductResourceTypeType,
		typename IfcConstructionProductResourceTypeEnumType,
		typename IfcConstructionResourceType,
		typename IfcConstructionResourceTypeType,
		typename IfcContextType,
		typename IfcContextDependentMeasureType,
		typename IfcContextDependentUnitType,
		typename IfcControlType,
		typename IfcControllerType,
		typename IfcControllerTypeType,
		typename IfcControllerTypeEnumType,
		typename IfcConversionBasedUnitType,
		typename IfcConversionBasedUnitWithOffsetType,
		typename IfcCooledBeamType,
		typename IfcCooledBeamTypeType,
		typename IfcCooledBeamTypeEnumType,
		typename IfcCoolingTowerType,
		typename IfcCoolingTowerTypeType,
		typename IfcCoolingTowerTypeEnumType,
		typename IfcCoordinateOperationType,
		typename IfcCoordinateReferenceSystemType,
		typename IfcCoordinateReferenceSystemSelectType,
		typename IfcCostItemType,
		typename IfcCostItemTypeEnumType,
		typename IfcCostScheduleType,
		typename IfcCostScheduleTypeEnumType,
		typename IfcCostValueType,
		typename IfcCountMeasureType,
		typename IfcCoveringType,
		typename IfcCoveringTypeType,
		typename IfcCoveringTypeEnumType,
		typename IfcCrewResourceType,
		typename IfcCrewResourceTypeType,
		typename IfcCrewResourceTypeEnumType,
		typename IfcCsgPrimitive3DType,
		typename IfcCsgSelectType,
		typename IfcCsgSolidType,
		typename IfcCShapeProfileDefType,
		typename IfcCurrencyRelationshipType,
		typename IfcCurtainWallType,
		typename IfcCurtainWallTypeType,
		typename IfcCurtainWallTypeEnumType,
		typename IfcCurvatureMeasureType,
		typename IfcCurveType,
		typename IfcCurveBoundedPlaneType,
		typename IfcCurveBoundedSurfaceType,
		typename IfcCurveFontOrScaledCurveFontSelectType,
		typename IfcCurveInterpolationEnumType,
		typename IfcCurveOnSurfaceType,
		typename IfcCurveOrEdgeCurveType,
		typename IfcCurveStyleType,
		typename IfcCurveStyleFontType,
		typename IfcCurveStyleFontAndScalingType,
		typename IfcCurveStyleFontPatternType,
		typename IfcCurveStyleFontSelectType,
		typename IfcCylindricalSurfaceType,
		typename IfcDamperType,
		typename IfcDamperTypeType,
		typename IfcDamperTypeEnumType,
		typename IfcDataOriginEnumType,
		typename IfcDateType,
		typename IfcDateTimeType,
		typename IfcDayInMonthNumberType,
		typename IfcDayInWeekNumberType,
		typename IfcDefinedSymbolType,
		typename IfcDefinedSymbolSelectType,
		typename IfcDefinitionSelectType,
		typename IfcDerivedMeasureValueType,
		typename IfcDerivedProfileDefType,
		typename IfcDerivedUnitType,
		typename IfcDerivedUnitElementType,
		typename IfcDerivedUnitEnumType,
		typename IfcDescriptiveMeasureType,
		typename IfcDimensionalExponentsType,
		typename IfcDimensionCountType,
		typename IfcDirectionType,
		typename IfcDirectionListType,
		typename IfcDirectionSenseEnumType,
		typename IfcDiscreteAccessoryType,
		typename IfcDiscreteAccessoryTypeType,
		typename IfcDiscreteAccessoryTypeEnumType,
		typename IfcDistributionChamberElementType,
		typename IfcDistributionChamberElementTypeType,
		typename IfcDistributionChamberElementTypeEnumType,
		typename IfcDistributionCircuitType,
		typename IfcDistributionControlElementType,
		typename IfcDistributionControlElementTypeType,
		typename IfcDistributionElementType,
		typename IfcDistributionElementTypeType,
		typename IfcDistributionFlowElementType,
		typename IfcDistributionFlowElementTypeType,
		typename IfcDistributionPortType,
		typename IfcDistributionSystemType,
		typename IfcDistributionSystemEnumType,
		typename IfcDocumentConfidentialityEnumType,
		typename IfcDocumentElectronicFormatType,
		typename IfcDocumentInformationType,
		typename IfcDocumentInformationRelationshipType,
		typename IfcDocumentReferenceType,
		typename IfcDocumentSelectType,
		typename IfcDocumentStatusEnumType,
		typename IfcDoorType,
		typename IfcDoorLiningPropertiesType,
		typename IfcDoorPanelOperationEnumType,
		typename IfcDoorPanelPositionEnumType,
		typename IfcDoorPanelPropertiesType,
		typename IfcDoorStandardCaseType,
		typename IfcDoorStyleType,
		typename IfcDoorStyleConstructionEnumType,
		typename IfcDoorStyleOperationEnumType,
		typename IfcDoorTypeType,
		typename IfcDoorTypeEnumType,
		typename IfcDoorTypeOperationEnumType,
		typename IfcDoseEquivalentMeasureType,
		typename IfcDraughtingPreDefinedColourType,
		typename IfcDraughtingPreDefinedCurveFontType,
		typename IfcDraughtingPreDefinedTextFontType,
		typename IfcDuctFittingType,
		typename IfcDuctFittingTypeType,
		typename IfcDuctFittingTypeEnumType,
		typename IfcDuctSegmentType,
		typename IfcDuctSegmentTypeType,
		typename IfcDuctSegmentTypeEnumType,
		typename IfcDuctSilencerType,
		typename IfcDuctSilencerTypeType,
		typename IfcDuctSilencerTypeEnumType,
		typename IfcDurationType,
		typename IfcDynamicViscosityMeasureType,
		typename IfcEdgeType,
		typename IfcEdgeCurveType,
		typename IfcEdgeLoopType,
		typename IfcElectricApplianceType,
		typename IfcElectricApplianceTypeType,
		typename IfcElectricApplianceTypeEnumType,
		typename IfcElectricCapacitanceMeasureType,
		typename IfcElectricChargeMeasureType,
		typename IfcElectricConductanceMeasureType,
		typename IfcElectricCurrentMeasureType,
		typename IfcElectricDistributionBoardType,
		typename IfcElectricDistributionBoardTypeType,
		typename IfcElectricDistributionBoardTypeEnumType,
		typename IfcElectricFlowStorageDeviceType,
		typename IfcElectricFlowStorageDeviceTypeType,
		typename IfcElectricFlowStorageDeviceTypeEnumType,
		typename IfcElectricGeneratorType,
		typename IfcElectricGeneratorTypeType,
		typename IfcElectricGeneratorTypeEnumType,
		typename IfcElectricMotorType,
		typename IfcElectricMotorTypeType,
		typename IfcElectricMotorTypeEnumType,
		typename IfcElectricResistanceMeasureType,
		typename IfcElectricTimeControlType,
		typename IfcElectricTimeControlTypeType,
		typename IfcElectricTimeControlTypeEnumType,
		typename IfcElectricVoltageMeasureType,
		typename IfcElementType,
		typename IfcElementarySurfaceType,
		typename IfcElementAssemblyType,
		typename IfcElementAssemblyTypeType,
		typename IfcElementAssemblyTypeEnumType,
		typename IfcElementComponentType,
		typename IfcElementComponentTypeType,
		typename IfcElementCompositionEnumType,
		typename IfcElementPartType,
		typename IfcElementQuantityType,
		typename IfcElementTypeType,
		typename IfcEllipseType,
		typename IfcEllipseProfileDefType,
		typename IfcEnergyConversionDeviceType,
		typename IfcEnergyConversionDeviceTypeType,
		typename IfcEnergyMeasureType,
		typename IfcEngineType,
		typename IfcEngineTypeType,
		typename IfcEngineTypeEnumType,
		typename IfcEvaporativeCoolerType,
		typename IfcEvaporativeCoolerTypeType,
		typename IfcEvaporativeCoolerTypeEnumType,
		typename IfcEvaporatorType,
		typename IfcEvaporatorTypeType,
		typename IfcEvaporatorTypeEnumType,
		typename IfcEventType,
		typename IfcEventTimeType,
		typename IfcEventTriggerTypeEnumType,
		typename IfcEventTypeType,
		typename IfcEventTypeEnumType,
		typename IfcExtendedPropertiesType,
		typename IfcExternalInformationType,
		typename IfcExternallyDefinedHatchStyleType,
		typename IfcExternallyDefinedSurfaceStyleType,
		typename IfcExternallyDefinedSymbolType,
		typename IfcExternallyDefinedTextFontType,
		typename IfcExternalReferenceType,
		typename IfcExternalReferenceRelationshipType,
		typename IfcExternalSpatialElementType,
		typename IfcExternalSpatialElementTypeEnumType,
		typename IfcExternalSpatialStructureElementType,
		typename IfcExtrudedAreaSolidType,
		typename IfcExtrudedAreaSolidTaperedType,
		typename IfcFaceType,
		typename IfcFaceBasedSurfaceModelType,
		typename IfcFaceBoundType,
		typename IfcFaceOuterBoundType,
		typename IfcFaceSurfaceType,
		typename IfcFacetedBrepType,
		typename IfcFacetedBrepWithVoidsType,
		typename IfcFailureConnectionConditionType,
		typename IfcFanType,
		typename IfcFanTypeType,
		typename IfcFanTypeEnumType,
		typename IfcFastenerType,
		typename IfcFastenerTypeType,
		typename IfcFastenerTypeEnumType,
		typename IfcFeatureElementType,
		typename IfcFeatureElementAdditionType,
		typename IfcFeatureElementSubtractionType,
		typename IfcFillAreaStyleType,
		typename IfcFillAreaStyleHatchingType,
		typename IfcFillAreaStyleTilesType,
		typename IfcFillAreaStyleTileShapeSelectType,
		typename IfcFillAreaStyleTileSymbolWithStyleType,
		typename IfcFillStyleSelectType,
		typename IfcFilterType,
		typename IfcFilterTypeType,
		typename IfcFilterTypeEnumType,
		typename IfcFireSuppressionTerminalType,
		typename IfcFireSuppressionTerminalTypeType,
		typename IfcFireSuppressionTerminalTypeEnumType,
		typename IfcFixedReferenceSweptAreaSolidType,
		typename IfcFlowControllerType,
		typename IfcFlowControllerTypeType,
		typename IfcFlowDirectionEnumType,
		typename IfcFlowFittingType,
		typename IfcFlowFittingTypeType,
		typename IfcFlowInstrumentType,
		typename IfcFlowInstrumentTypeType,
		typename IfcFlowInstrumentTypeEnumType,
		typename IfcFlowMeterType,
		typename IfcFlowMeterTypeType,
		typename IfcFlowMeterTypeEnumType,
		typename IfcFlowMovingDeviceType,
		typename IfcFlowMovingDeviceTypeType,
		typename IfcFlowSegmentType,
		typename IfcFlowSegmentTypeType,
		typename IfcFlowStorageDeviceType,
		typename IfcFlowStorageDeviceTypeType,
		typename IfcFlowTerminalType,
		typename IfcFlowTerminalTypeType,
		typename IfcFlowTreatmentDeviceType,
		typename IfcFlowTreatmentDeviceTypeType,
		typename IfcFontStyleType,
		typename IfcFontVariantType,
		typename IfcFontWeightType,
		typename IfcFootingType,
		typename IfcFootingTypeType,
		typename IfcFootingTypeEnumType,
		typename IfcForceMeasureType,
		typename IfcFrequencyMeasureType,
		typename IfcFurnishingElementType,
		typename IfcFurnishingElementTypeType,
		typename IfcFurnitureType,
		typename IfcFurnitureTypeType,
		typename IfcFurnitureTypeEnumType,
		typename IfcGeographicElementType,
		typename IfcGeographicElementTypeType,
		typename IfcGeographicElementTypeEnumType,
		typename IfcGeometricCurveSetType,
		typename IfcGeometricProjectionEnumType,
		typename IfcGeometricRepresentationContextType,
		typename IfcGeometricRepresentationItemType,
		typename IfcGeometricRepresentationSubContextType,
		typename IfcGeometricSetType,
		typename IfcGeometricSetSelectType,
		typename IfcGloballyUniqueIdType,
		typename IfcGlobalOrLocalEnumType,
		typename IfcGridType,
		typename IfcGridAxisType,
		typename IfcGridPlacementType,
		typename IfcGridPlacementDirectionSelectType,
		typename IfcGridTypeEnumType,
		typename IfcGroupType,
		typename IfcHalfSpaceSolidType,
		typename IfcHatchLineDistanceSelectType,
		typename IfcHeatExchangerType,
		typename IfcHeatExchangerTypeType,
		typename IfcHeatExchangerTypeEnumType,
		typename IfcHeatFluxDensityMeasureType,
		typename IfcHeatingValueMeasureType,
		typename IfcHumidifierType,
		typename IfcHumidifierTypeType,
		typename IfcHumidifierTypeEnumType,
		typename IfcIdentifierType,
		typename IfcIlluminanceMeasureType,
		typename IfcImageTextureType,
		typename IfcIndexedColourMapType,
		typename IfcIndexedTextureMapType,
		typename IfcIndexedTriangleTextureMapType,
		typename IfcInductanceMeasureType,
		typename IfcIntegerType,
		typename IfcIntegerCountRateMeasureType,
		typename IfcInterceptorType,
		typename IfcInterceptorTypeType,
		typename IfcInterceptorTypeEnumType,
		typename IfcInternalOrExternalEnumType,
		typename IfcInventoryType,
		typename IfcInventoryTypeEnumType,
		typename IfcIonConcentrationMeasureType,
		typename IfcIrregularTimeSeriesType,
		typename IfcIrregularTimeSeriesValueType,
		typename IfcIShapeProfileDefType,
		typename IfcIsothermalMoistureCapacityMeasureType,
		typename IfcJunctionBoxType,
		typename IfcJunctionBoxTypeType,
		typename IfcJunctionBoxTypeEnumType,
		typename IfcKinematicViscosityMeasureType,
		typename IfcKnotTypeType,
		typename IfcLabelType,
		typename IfcLaborResourceType,
		typename IfcLaborResourceTypeType,
		typename IfcLaborResourceTypeEnumType,
		typename IfcLagTimeType,
		typename IfcLampType,
		typename IfcLampTypeType,
		typename IfcLampTypeEnumType,
		typename IfcLanguageIdType,
		typename IfcLayeredItemType,
		typename IfcLayerSetDirectionEnumType,
		typename IfcLengthMeasureType,
		typename IfcLibraryInformationType,
		typename IfcLibraryReferenceType,
		typename IfcLibrarySelectType,
		typename IfcLightDistributionCurveEnumType,
		typename IfcLightDistributionDataType,
		typename IfcLightDistributionDataSourceSelectType,
		typename IfcLightEmissionSourceEnumType,
		typename IfcLightFixtureType,
		typename IfcLightFixtureTypeType,
		typename IfcLightFixtureTypeEnumType,
		typename IfcLightIntensityDistributionType,
		typename IfcLightSourceType,
		typename IfcLightSourceAmbientType,
		typename IfcLightSourceDirectionalType,
		typename IfcLightSourceGoniometricType,
		typename IfcLightSourcePositionalType,
		typename IfcLightSourceSpotType,
		typename IfcLineType,
		typename IfcLinearForceMeasureType,
		typename IfcLinearMomentMeasureType,
		typename IfcLinearStiffnessMeasureType,
		typename IfcLinearVelocityMeasureType,
		typename IfcLoadGroupTypeEnumType,
		typename IfcLocalPlacementType,
		typename IfcLogicalType,
		typename IfcLogicalOperatorEnumType,
		typename IfcLoopType,
		typename IfcLShapeProfileDefType,
		typename IfcLuminousFluxMeasureType,
		typename IfcLuminousIntensityDistributionMeasureType,
		typename IfcLuminousIntensityMeasureType,
		typename IfcMagneticFluxDensityMeasureType,
		typename IfcMagneticFluxMeasureType,
		typename IfcManifoldSolidBrepType,
		typename IfcMapConversionType,
		typename IfcMappedItemType,
		typename IfcMassDensityMeasureType,
		typename IfcMassFlowRateMeasureType,
		typename IfcMassMeasureType,
		typename IfcMassPerLengthMeasureType,
		typename IfcMaterialType,
		typename IfcMaterialClassificationRelationshipType,
		typename IfcMaterialConstituentType,
		typename IfcMaterialConstituentSetType,
		typename IfcMaterialDefinitionType,
		typename IfcMaterialDefinitionRepresentationType,
		typename IfcMaterialLayerType,
		typename IfcMaterialLayerSetType,
		typename IfcMaterialLayerSetUsageType,
		typename IfcMaterialLayerWithOffsetsType,
		typename IfcMaterialListType,
		typename IfcMaterialProfileType,
		typename IfcMaterialProfileSetType,
		typename IfcMaterialProfileSetUsageType,
		typename IfcMaterialProfileSetUsageTaperingType,
		typename IfcMaterialProfileWithOffsetsType,
		typename IfcMaterialPropertiesType,
		typename IfcMaterialRelationshipType,
		typename IfcMaterialSelectType,
		typename IfcMaterialUsageDefinitionType,
		typename IfcMeasureValueType,
		typename IfcMeasureWithUnitType,
		typename IfcMechanicalFastenerType,
		typename IfcMechanicalFastenerTypeType,
		typename IfcMechanicalFastenerTypeEnumType,
		typename IfcMedicalDeviceType,
		typename IfcMedicalDeviceTypeType,
		typename IfcMedicalDeviceTypeEnumType,
		typename IfcMemberType,
		typename IfcMemberStandardCaseType,
		typename IfcMemberTypeType,
		typename IfcMemberTypeEnumType,
		typename IfcMetricType,
		typename IfcMetricValueSelectType,
		typename IfcMirroredProfileDefType,
		typename IfcModulusOfElasticityMeasureType,
		typename IfcModulusOfLinearSubgradeReactionMeasureType,
		typename IfcModulusOfRotationalSubgradeReactionMeasureType,
		typename IfcModulusOfRotationalSubgradeReactionSelectType,
		typename IfcModulusOfSubgradeReactionMeasureType,
		typename IfcModulusOfSubgradeReactionSelectType,
		typename IfcModulusOfTranslationalSubgradeReactionSelectType,
		typename IfcMoistureDiffusivityMeasureType,
		typename IfcMolecularWeightMeasureType,
		typename IfcMomentOfInertiaMeasureType,
		typename IfcMonetaryMeasureType,
		typename IfcMonetaryUnitType,
		typename IfcMonthInYearNumberType,
		typename IfcMotorConnectionType,
		typename IfcMotorConnectionTypeType,
		typename IfcMotorConnectionTypeEnumType,
		typename IfcNamedUnitType,
		typename IfcNonNegativeLengthMeasureType,
		typename IfcNormalisedRatioMeasureType,
		typename IfcNullStyleType,
		typename IfcNumericMeasureType,
		typename IfcObjectType,
		typename IfcObjectDefinitionType,
		typename IfcObjectiveType,
		typename IfcObjectiveEnumType,
		typename IfcObjectPlacementType,
		typename IfcObjectReferenceSelectType,
		typename IfcObjectTypeEnumType,
		typename IfcOccupantType,
		typename IfcOccupantTypeEnumType,
		typename IfcOffsetCurve2DType,
		typename IfcOffsetCurve3DType,
		typename IfcOneDirectionRepeatFactorType,
		typename IfcOpeningElementType,
		typename IfcOpeningElementTypeEnumType,
		typename IfcOpeningStandardCaseType,
		typename IfcOpenShellType,
		typename IfcOrganizationType,
		typename IfcOrganizationRelationshipType,
		typename IfcOrientedEdgeType,
		typename IfcOuterBoundaryCurveType,
		typename IfcOutletType,
		typename IfcOutletTypeType,
		typename IfcOutletTypeEnumType,
		typename IfcOwnerHistoryType,
		typename IfcParameterizedProfileDefType,
		typename IfcParameterValueType,
		typename IfcPathType,
		typename IfcPcurveType,
		typename IfcPerformanceHistoryType,
		typename IfcPerformanceHistoryTypeEnumType,
		typename IfcPermeableCoveringOperationEnumType,
		typename IfcPermeableCoveringPropertiesType,
		typename IfcPermitType,
		typename IfcPermitTypeEnumType,
		typename IfcPersonType,
		typename IfcPersonAndOrganizationType,
		typename IfcPHMeasureType,
		typename IfcPhysicalComplexQuantityType,
		typename IfcPhysicalOrVirtualEnumType,
		typename IfcPhysicalQuantityType,
		typename IfcPhysicalSimpleQuantityType,
		typename IfcPileType,
		typename IfcPileConstructionEnumType,
		typename IfcPileTypeType,
		typename IfcPileTypeEnumType,
		typename IfcPipeFittingType,
		typename IfcPipeFittingTypeType,
		typename IfcPipeFittingTypeEnumType,
		typename IfcPipeSegmentType,
		typename IfcPipeSegmentTypeType,
		typename IfcPipeSegmentTypeEnumType,
		typename IfcPixelTextureType,
		typename IfcPlacementType,
		typename IfcPlanarBoxType,
		typename IfcPlanarExtentType,
		typename IfcPlanarForceMeasureType,
		typename IfcPlaneType,
		typename IfcPlaneAngleMeasureType,
		typename IfcPlateType,
		typename IfcPlateStandardCaseType,
		typename IfcPlateTypeType,
		typename IfcPlateTypeEnumType,
		typename IfcPointType,
		typename IfcPointOnCurveType,
		typename IfcPointOnSurfaceType,
		typename IfcPointOrVertexPointType,
		typename IfcPolygonalBoundedHalfSpaceType,
		typename IfcPolylineType,
		typename IfcPolyLoopType,
		typename IfcPortType,
		typename IfcPositiveLengthMeasureType,
		typename IfcPositivePlaneAngleMeasureType,
		typename IfcPositiveRatioMeasureType,
		typename IfcPostalAddressType,
		typename IfcPowerMeasureType,
		typename IfcPreDefinedColourType,
		typename IfcPreDefinedCurveFontType,
		typename IfcPreDefinedItemType,
		typename IfcPreDefinedPropertiesType,
		typename IfcPreDefinedPropertySetType,
		typename IfcPreDefinedSymbolType,
		typename IfcPreDefinedTextFontType,
		typename IfcPresentableTextType,
		typename IfcPresentationItemType,
		typename IfcPresentationLayerAssignmentType,
		typename IfcPresentationLayerWithStyleType,
		typename IfcPresentationStyleType,
		typename IfcPresentationStyleAssignmentType,
		typename IfcPresentationStyleSelectType,
		typename IfcPressureMeasureType,
		typename IfcProcedureType,
		typename IfcProcedureTypeType,
		typename IfcProcedureTypeEnumType,
		typename IfcProcessType,
		typename IfcProcessSelectType,
		typename IfcProductType,
		typename IfcProductDefinitionShapeType,
		typename IfcProductRepresentationType,
		typename IfcProductSelectType,
		typename IfcProfileDefType,
		typename IfcProfilePropertiesType,
		typename IfcProfileTypeEnumType,
		typename IfcProjectType,
		typename IfcProjectedCRSType,
		typename IfcProjectedOrTrueLengthEnumType,
		typename IfcProjectionElementType,
		typename IfcProjectionElementTypeEnumType,
		typename IfcProjectLibraryType,
		typename IfcProjectOrderType,
		typename IfcProjectOrderTypeEnumType,
		typename IfcPropertyType,
		typename IfcPropertyAbstractionType,
		typename IfcPropertyBoundedValueType,
		typename IfcPropertyDefinitionType,
		typename IfcPropertyDependencyRelationshipType,
		typename IfcPropertyEnumeratedValueType,
		typename IfcPropertyEnumerationType,
		typename IfcPropertyListValueType,
		typename IfcPropertyReferenceValueType,
		typename IfcPropertySetType,
		typename IfcPropertySetDefinitionType,
		typename IfcPropertySetTemplateType,
		typename IfcPropertySetTemplateTypeEnumType,
		typename IfcPropertySingleValueType,
		typename IfcPropertyTableValueType,
		typename IfcPropertyTemplateType,
		typename IfcPropertyTemplateDefinitionType,
		typename IfcProtectiveDeviceType,
		typename IfcProtectiveDeviceTrippingUnitType,
		typename IfcProtectiveDeviceTrippingUnitTypeType,
		typename IfcProtectiveDeviceTrippingUnitTypeEnumType,
		typename IfcProtectiveDeviceTypeType,
		typename IfcProtectiveDeviceTypeEnumType,
		typename IfcProxyType,
		typename IfcPumpType,
		typename IfcPumpTypeType,
		typename IfcPumpTypeEnumType,
		typename IfcQuantityAreaType,
		typename IfcQuantityCountType,
		typename IfcQuantityLengthType,
		typename IfcQuantitySetType,
		typename IfcQuantityTimeType,
		typename IfcQuantityVolumeType,
		typename IfcQuantityWeightType,
		typename IfcRadioActivityMeasureType,
		typename IfcRailingType,
		typename IfcRailingTypeType,
		typename IfcRailingTypeEnumType,
		typename IfcRampType,
		typename IfcRampFlightType,
		typename IfcRampFlightTypeType,
		typename IfcRampFlightTypeEnumType,
		typename IfcRampTypeType,
		typename IfcRampTypeEnumType,
		typename IfcRatioMeasureType,
		typename IfcRationalBSplineCurveWithKnotsType,
		typename IfcRationalBSplineSurfaceWithKnotsType,
		typename IfcRealType,
		typename IfcRectangleHollowProfileDefType,
		typename IfcRectangleProfileDefType,
		typename IfcRectangularPyramidType,
		typename IfcRectangularTrimmedSurfaceType,
		typename IfcRecurrencePatternType,
		typename IfcRecurrenceTypeEnumType,
		typename IfcReferenceCurveType,
		typename IfcReferenceCurve3DType,
		typename IfcReferenceCurveAlignment2DType,
		typename IfcReferenceCurvePlacementType,
		typename IfcReferenceCurvePlacementSystemType,
		typename IfcReferencedSectionedSpineType,
		typename IfcReferenceElementType,
		typename IfcReferencePlacementType,
		typename IfcReflectanceMethodEnumType,
		typename IfcRegularTimeSeriesType,
		typename IfcReinforcementBarPropertiesType,
		typename IfcReinforcementDefinitionPropertiesType,
		typename IfcReinforcingBarType,
		typename IfcReinforcingBarRoleEnumType,
		typename IfcReinforcingBarSurfaceEnumType,
		typename IfcReinforcingBarTypeType,
		typename IfcReinforcingBarTypeEnumType,
		typename IfcReinforcingElementType,
		typename IfcReinforcingElementTypeType,
		typename IfcReinforcingMeshType,
		typename IfcReinforcingMeshTypeType,
		typename IfcReinforcingMeshTypeEnumType,
		typename IfcRelAggregatesType,
		typename IfcRelAssignsType,
		typename IfcRelAssignsToActorType,
		typename IfcRelAssignsToControlType,
		typename IfcRelAssignsToGroupType,
		typename IfcRelAssignsToGroupByFactorType,
		typename IfcRelAssignsToProcessType,
		typename IfcRelAssignsToProductType,
		typename IfcRelAssignsToResourceType,
		typename IfcRelAssociatesType,
		typename IfcRelAssociatesApprovalType,
		typename IfcRelAssociatesClassificationType,
		typename IfcRelAssociatesConstraintType,
		typename IfcRelAssociatesDocumentType,
		typename IfcRelAssociatesLibraryType,
		typename IfcRelAssociatesMaterialType,
		typename IfcRelationshipType,
		typename IfcRelConnectsType,
		typename IfcRelConnectsElementsType,
		typename IfcRelConnectsPathElementsType,
		typename IfcRelConnectsPortsType,
		typename IfcRelConnectsPortToElementType,
		typename IfcRelConnectsStructuralActivityType,
		typename IfcRelConnectsStructuralMemberType,
		typename IfcRelConnectsWithEccentricityType,
		typename IfcRelConnectsWithRealizingElementsType,
		typename IfcRelContainedInSpatialStructureType,
		typename IfcRelCoversBldgElementsType,
		typename IfcRelCoversSpacesType,
		typename IfcRelDeclaresType,
		typename IfcRelDecomposesType,
		typename IfcRelDefinesType,
		typename IfcRelDefinesByObjectType,
		typename IfcRelDefinesByPropertiesType,
		typename IfcRelDefinesByTemplateType,
		typename IfcRelDefinesByTypeType,
		typename IfcRelFillsElementType,
		typename IfcRelFlowControlElementsType,
		typename IfcRelInterferesElementsType,
		typename IfcRelNestsType,
		typename IfcRelProjectsElementType,
		typename IfcRelReferencedInSpatialStructureType,
		typename IfcRelSequenceType,
		typename IfcRelServicesBuildingsType,
		typename IfcRelSpaceBoundaryType,
		typename IfcRelSpaceBoundary1stLevelType,
		typename IfcRelSpaceBoundary2ndLevelType,
		typename IfcRelVoidsElementType,
		typename IfcReparametrisedCompositeCurveSegmentType,
		typename IfcRepresentationType,
		typename IfcRepresentationContextType,
		typename IfcRepresentationItemType,
		typename IfcRepresentationMapType,
		typename IfcResourceType,
		typename IfcResourceApprovalRelationshipType,
		typename IfcResourceConstraintRelationshipType,
		typename IfcResourceConsumptionEnumType,
		typename IfcResourceCostType,
		typename IfcResourceLevelRelationshipType,
		typename IfcResourceObjectSelectType,
		typename IfcResourceSelectType,
		typename IfcResourceTimeType,
		typename IfcRevolvedAreaSolidType,
		typename IfcRevolvedAreaSolidTaperedType,
		typename IfcRightCircularConeType,
		typename IfcRightCircularCylinderType,
		typename IfcRoleEnumType,
		typename IfcRoofType,
		typename IfcRoofTypeType,
		typename IfcRoofTypeEnumType,
		typename IfcRootType,
		typename IfcRotationalFrequencyMeasureType,
		typename IfcRotationalMassMeasureType,
		typename IfcRotationalStiffnessMeasureType,
		typename IfcRotationalStiffnessSelectType,
		typename IfcRoundedRectangleProfileDefType,
		typename IfcSanitaryTerminalType,
		typename IfcSanitaryTerminalTypeType,
		typename IfcSanitaryTerminalTypeEnumType,
		typename IfcSchedulingTimeType,
		typename IfcSectionalAreaIntegralMeasureType,
		typename IfcSectionedSpineType,
		typename IfcSectionModulusMeasureType,
		typename IfcSectionPropertiesType,
		typename IfcSectionReinforcementPropertiesType,
		typename IfcSectionTypeEnumType,
		typename IfcSensorType,
		typename IfcSensorTypeType,
		typename IfcSensorTypeEnumType,
		typename IfcSequenceEnumType,
		typename IfcShadingDeviceType,
		typename IfcShadingDeviceTypeType,
		typename IfcShadingDeviceTypeEnumType,
		typename IfcShapeAspectType,
		typename IfcShapeModelType,
		typename IfcShapeRepresentationType,
		typename IfcShearModulusMeasureType,
		typename IfcShellType,
		typename IfcShellBasedSurfaceModelType,
		typename IfcSimplePropertyType,
		typename IfcSimplePropertyTemplateType,
		typename IfcSimplePropertyTemplateTypeEnumType,
		typename IfcSimpleValueType,
		typename IfcSIPrefixType,
		typename IfcSiteType,
		typename IfcSIUnitType,
		typename IfcSIUnitNameType,
		typename IfcSizeSelectType,
		typename IfcSlabType,
		typename IfcSlabElementedCaseType,
		typename IfcSlabStandardCaseType,
		typename IfcSlabTypeType,
		typename IfcSlabTypeEnumType,
		typename IfcSlippageConnectionConditionType,
		typename IfcSolarDeviceType,
		typename IfcSolarDeviceTypeType,
		typename IfcSolarDeviceTypeEnumType,
		typename IfcSolidAngleMeasureType,
		typename IfcSolidModelType,
		typename IfcSolidOrShellType,
		typename IfcSoundPowerMeasureType,
		typename IfcSoundPressureMeasureType,
		typename IfcSpaceType,
		typename IfcSpaceBoundarySelectType,
		typename IfcSpaceHeaterType,
		typename IfcSpaceHeaterTypeType,
		typename IfcSpaceHeaterTypeEnumType,
		typename IfcSpaceTypeType,
		typename IfcSpaceTypeEnumType,
		typename IfcSpatialElementType,
		typename IfcSpatialElementTypeType,
		typename IfcSpatialStructureElementType,
		typename IfcSpatialStructureElementTypeType,
		typename IfcSpatialZoneType,
		typename IfcSpatialZoneTypeType,
		typename IfcSpatialZoneTypeEnumType,
		typename IfcSpecificHeatCapacityMeasureType,
		typename IfcSpecularExponentType,
		typename IfcSpecularHighlightSelectType,
		typename IfcSpecularRoughnessType,
		typename IfcSphereType,
		typename IfcStackTerminalType,
		typename IfcStackTerminalTypeType,
		typename IfcStackTerminalTypeEnumType,
		typename IfcStairType,
		typename IfcStairFlightType,
		typename IfcStairFlightTypeType,
		typename IfcStairFlightTypeEnumType,
		typename IfcStairTypeType,
		typename IfcStairTypeEnumType,
		typename IfcStateEnumType,
		typename IfcStructuralActionType,
		typename IfcStructuralActivityType,
		typename IfcStructuralActivityAssignmentSelectType,
		typename IfcStructuralAnalysisModelType,
		typename IfcStructuralConnectionType,
		typename IfcStructuralConnectionConditionType,
		typename IfcStructuralCurveActionType,
		typename IfcStructuralCurveActivityTypeEnumType,
		typename IfcStructuralCurveConnectionType,
		typename IfcStructuralCurveMemberType,
		typename IfcStructuralCurveMemberTypeEnumType,
		typename IfcStructuralCurveMemberVaryingType,
		typename IfcStructuralCurveReactionType,
		typename IfcStructuralItemType,
		typename IfcStructuralLinearActionType,
		typename IfcStructuralLoadType,
		typename IfcStructuralLoadCaseType,
		typename IfcStructuralLoadConfigurationType,
		typename IfcStructuralLoadGroupType,
		typename IfcStructuralLoadLinearForceType,
		typename IfcStructuralLoadOrResultType,
		typename IfcStructuralLoadPlanarForceType,
		typename IfcStructuralLoadSingleDisplacementType,
		typename IfcStructuralLoadSingleDisplacementDistortionType,
		typename IfcStructuralLoadSingleForceType,
		typename IfcStructuralLoadSingleForceWarpingType,
		typename IfcStructuralLoadStaticType,
		typename IfcStructuralLoadTemperatureType,
		typename IfcStructuralMemberType,
		typename IfcStructuralPlanarActionType,
		typename IfcStructuralPointActionType,
		typename IfcStructuralPointConnectionType,
		typename IfcStructuralPointReactionType,
		typename IfcStructuralReactionType,
		typename IfcStructuralResultGroupType,
		typename IfcStructuralSurfaceActionType,
		typename IfcStructuralSurfaceActivityTypeEnumType,
		typename IfcStructuralSurfaceConnectionType,
		typename IfcStructuralSurfaceMemberType,
		typename IfcStructuralSurfaceMemberTypeEnumType,
		typename IfcStructuralSurfaceMemberVaryingType,
		typename IfcStructuralSurfaceReactionType,
		typename IfcStyleAssignmentSelectType,
		typename IfcStyledItemType,
		typename IfcStyledRepresentationType,
		typename IfcStyleModelType,
		typename IfcSubContractResourceType,
		typename IfcSubContractResourceTypeType,
		typename IfcSubContractResourceTypeEnumType,
		typename IfcSubedgeType,
		typename IfcSurfaceType,
		typename IfcSurfaceCurveSweptAreaSolidType,
		typename IfcSurfaceFeatureType,
		typename IfcSurfaceFeatureTypeEnumType,
		typename IfcSurfaceOfLinearExtrusionType,
		typename IfcSurfaceOfRevolutionType,
		typename IfcSurfaceOrFaceSurfaceType,
		typename IfcSurfaceReinforcementAreaType,
		typename IfcSurfaceSideType,
		typename IfcSurfaceStyleType,
		typename IfcSurfaceStyleElementSelectType,
		typename IfcSurfaceStyleLightingType,
		typename IfcSurfaceStyleRefractionType,
		typename IfcSurfaceStyleRenderingType,
		typename IfcSurfaceStyleShadingType,
		typename IfcSurfaceStyleWithTexturesType,
		typename IfcSurfaceTextureType,
		typename IfcSweptAreaSolidType,
		typename IfcSweptDiskSolidType,
		typename IfcSweptDiskSolidPolygonalType,
		typename IfcSweptSurfaceType,
		typename IfcSwitchingDeviceType,
		typename IfcSwitchingDeviceTypeType,
		typename IfcSwitchingDeviceTypeEnumType,
		typename IfcSymbolStyleType,
		typename IfcSymbolStyleSelectType,
		typename IfcSystemType,
		typename IfcSystemFurnitureElementType,
		typename IfcSystemFurnitureElementTypeType,
		typename IfcSystemFurnitureElementTypeEnumType,
		typename IfcTableType,
		typename IfcTableColumnType,
		typename IfcTableRowType,
		typename IfcTankType,
		typename IfcTankTypeType,
		typename IfcTankTypeEnumType,
		typename IfcTaskType,
		typename IfcTaskDurationEnumType,
		typename IfcTaskTimeType,
		typename IfcTaskTimeRecurringType,
		typename IfcTaskTypeType,
		typename IfcTaskTypeEnumType,
		typename IfcTelecomAddressType,
		typename IfcTemperatureGradientMeasureType,
		typename IfcTemperatureRateOfChangeMeasureType,
		typename IfcTendonType,
		typename IfcTendonAnchorType,
		typename IfcTendonAnchorTypeType,
		typename IfcTendonAnchorTypeEnumType,
		typename IfcTendonTypeType,
		typename IfcTendonTypeEnumType,
		typename IfcTessellatedFaceSetType,
		typename IfcTessellatedItemType,
		typename IfcTextType,
		typename IfcTextAlignmentType,
		typename IfcTextDecorationType,
		typename IfcTextFontNameType,
		typename IfcTextFontSelectType,
		typename IfcTextLiteralType,
		typename IfcTextLiteralWithExtentType,
		typename IfcTextPathType,
		typename IfcTextStyleType,
		typename IfcTextStyleFontModelType,
		typename IfcTextStyleForDefinedFontType,
		typename IfcTextStyleSelectType,
		typename IfcTextStyleTextModelType,
		typename IfcTextStyleWithBoxCharacteristicsType,
		typename IfcTextTransformationType,
		typename IfcTextureCoordinateType,
		typename IfcTextureCoordinateGeneratorType,
		typename IfcTextureMapType,
		typename IfcTextureVertexType,
		typename IfcTextureVertexListType,
		typename IfcThermalAdmittanceMeasureType,
		typename IfcThermalConductivityMeasureType,
		typename IfcThermalExpansionCoefficientMeasureType,
		typename IfcThermalResistanceMeasureType,
		typename IfcThermalTransmittanceMeasureType,
		typename IfcThermodynamicTemperatureMeasureType,
		typename IfcTimeType,
		typename IfcTimeMeasureType,
		typename IfcTimeOrRatioSelectType,
		typename IfcTimePeriodType,
		typename IfcTimeSeriesType,
		typename IfcTimeSeriesDataTypeEnumType,
		typename IfcTimeSeriesValueType,
		typename IfcTimeStampType,
		typename IfcTopologicalRepresentationItemType,
		typename IfcTopologyRepresentationType,
		typename IfcTorqueMeasureType,
		typename IfcTransformerType,
		typename IfcTransformerTypeType,
		typename IfcTransformerTypeEnumType,
		typename IfcTransitionCodeType,
		typename IfcTranslationalStiffnessSelectType,
		typename IfcTransportElementType,
		typename IfcTransportElementTypeType,
		typename IfcTransportElementTypeEnumType,
		typename IfcTrapeziumProfileDefType,
		typename IfcTriangulatedFaceSetType,
		typename IfcTrimmedCurveType,
		typename IfcTrimmingPreferenceType,
		typename IfcTrimmingSelectType,
		typename IfcTShapeProfileDefType,
		typename IfcTubeBundleType,
		typename IfcTubeBundleTypeType,
		typename IfcTubeBundleTypeEnumType,
		typename IfcTwoDirectionRepeatFactorType,
		typename IfcTypeObjectType,
		typename IfcTypeProcessType,
		typename IfcTypeProductType,
		typename IfcTypeResourceType,
		typename IfcUnitType,
		typename IfcUnitaryControlElementType,
		typename IfcUnitaryControlElementTypeType,
		typename IfcUnitaryControlElementTypeEnumType,
		typename IfcUnitaryEquipmentType,
		typename IfcUnitaryEquipmentTypeType,
		typename IfcUnitaryEquipmentTypeEnumType,
		typename IfcUnitAssignmentType,
		typename IfcUnitEnumType,
		typename IfcURIReferenceType,
		typename IfcUShapeProfileDefType,
		typename IfcValueType,
		typename IfcValveType,
		typename IfcValveTypeType,
		typename IfcValveTypeEnumType,
		typename IfcVaporPermeabilityMeasureType,
		typename IfcVectorType,
		typename IfcVectorOrDirectionType,
		typename IfcVertexType,
		typename IfcVertexLoopType,
		typename IfcVertexPointType,
		typename IfcVibrationIsolatorType,
		typename IfcVibrationIsolatorTypeType,
		typename IfcVibrationIsolatorTypeEnumType,
		typename IfcVirtualElementType,
		typename IfcVirtualGridIntersectionType,
		typename IfcVoidingFeatureType,
		typename IfcVoidingFeatureTypeEnumType,
		typename IfcVolumeMeasureType,
		typename IfcVolumetricFlowRateMeasureType,
		typename IfcWallType,
		typename IfcWallElementedCaseType,
		typename IfcWallStandardCaseType,
		typename IfcWallTypeType,
		typename IfcWallTypeEnumType,
		typename IfcWarpingConstantMeasureType,
		typename IfcWarpingMomentMeasureType,
		typename IfcWarpingStiffnessSelectType,
		typename IfcWasteTerminalType,
		typename IfcWasteTerminalTypeType,
		typename IfcWasteTerminalTypeEnumType,
		typename IfcWindowType,
		typename IfcWindowLiningPropertiesType,
		typename IfcWindowPanelOperationEnumType,
		typename IfcWindowPanelPositionEnumType,
		typename IfcWindowPanelPropertiesType,
		typename IfcWindowStandardCaseType,
		typename IfcWindowStyleType,
		typename IfcWindowStyleConstructionEnumType,
		typename IfcWindowStyleOperationEnumType,
		typename IfcWindowTypeType,
		typename IfcWindowTypeEnumType,
		typename IfcWindowTypePartitioningEnumType,
		typename IfcWorkCalendarType,
		typename IfcWorkCalendarTypeEnumType,
		typename IfcWorkControlType,
		typename IfcWorkPlanType,
		typename IfcWorkPlanTypeEnumType,
		typename IfcWorkScheduleType,
		typename IfcWorkScheduleTypeEnumType,
		typename IfcWorkTimeType,
		typename IfcZoneType,
		typename IfcZShapeProfileDefType
	>
	struct IfcEntityTypesBridge
	{
		typedef IfcAbsorbedDoseMeasureType IfcAbsorbedDoseMeasure;
		typedef IfcAccelerationMeasureType IfcAccelerationMeasure;
		typedef IfcActionRequestType IfcActionRequest;
		typedef IfcActionRequestTypeEnumType IfcActionRequestTypeEnum;
		typedef IfcActionSourceTypeEnumType IfcActionSourceTypeEnum;
		typedef IfcActionTypeEnumType IfcActionTypeEnum;
		typedef IfcActorType IfcActor;
		typedef IfcActorRoleType IfcActorRole;
		typedef IfcActorSelectType IfcActorSelect;
		typedef IfcActuatorType IfcActuator;
		typedef IfcActuatorTypeType IfcActuatorTType;
		typedef IfcActuatorTypeEnumType IfcActuatorTypeEnum;
		typedef IfcAddressType IfcAddress;
		typedef IfcAddressTypeEnumType IfcAddressTypeEnum;
		typedef IfcAdvancedBrepType IfcAdvancedBrep;
		typedef IfcAdvancedBrepWithVoidsType IfcAdvancedBrepWithVoids;
		typedef IfcAdvancedFaceType IfcAdvancedFace;
		typedef IfcAirTerminalType IfcAirTerminal;
		typedef IfcAirTerminalBoxType IfcAirTerminalBox;
		typedef IfcAirTerminalBoxTypeType IfcAirTerminalBoxTType;
		typedef IfcAirTerminalBoxTypeEnumType IfcAirTerminalBoxTypeEnum;
		typedef IfcAirTerminalTypeType IfcAirTerminalTType;
		typedef IfcAirTerminalTypeEnumType IfcAirTerminalTypeEnum;
		typedef IfcAirToAirHeatRecoveryType IfcAirToAirHeatRecovery;
		typedef IfcAirToAirHeatRecoveryTypeType IfcAirToAirHeatRecoveryTType;
		typedef IfcAirToAirHeatRecoveryTypeEnumType IfcAirToAirHeatRecoveryTypeEnum;
		typedef IfcAlarmType IfcAlarm;
		typedef IfcAlarmTypeType IfcAlarmTType;
		typedef IfcAlarmTypeEnumType IfcAlarmTypeEnum;
		typedef IfcAlignmentElementType IfcAlignmentElement;
		typedef IfcAmountOfSubstanceMeasureType IfcAmountOfSubstanceMeasure;
		typedef IfcAnalysisModelTypeEnumType IfcAnalysisModelTypeEnum;
		typedef IfcAnalysisTheoryTypeEnumType IfcAnalysisTheoryTypeEnum;
		typedef IfcAngularVelocityMeasureType IfcAngularVelocityMeasure;
		typedef IfcAnnotationType IfcAnnotation;
		typedef IfcAnnotationFillAreaType IfcAnnotationFillArea;
		typedef IfcApplicationType IfcApplication;
		typedef IfcAppliedValueType IfcAppliedValue;
		typedef IfcAppliedValueRelationshipType IfcAppliedValueRelationship;
		typedef IfcAppliedValueSelectType IfcAppliedValueSelect;
		typedef IfcApprovalType IfcApproval;
		typedef IfcApprovalRelationshipType IfcApprovalRelationship;
		typedef IfcArbitraryClosedProfileDefType IfcArbitraryClosedProfileDef;
		typedef IfcArbitraryOpenProfileDefType IfcArbitraryOpenProfileDef;
		typedef IfcArbitraryProfileDefWithVoidsType IfcArbitraryProfileDefWithVoids;
		typedef IfcAreaMeasureType IfcAreaMeasure;
		typedef IfcArithmeticOperatorEnumType IfcArithmeticOperatorEnum;
		typedef IfcAssemblyPlaceEnumType IfcAssemblyPlaceEnum;
		typedef IfcAssetType IfcAsset;
		typedef IfcAsymmetricIShapeProfileDefType IfcAsymmetricIShapeProfileDef;
		typedef IfcAudioVisualApplianceType IfcAudioVisualAppliance;
		typedef IfcAudioVisualApplianceTypeType IfcAudioVisualApplianceTType;
		typedef IfcAudioVisualApplianceTypeEnumType IfcAudioVisualApplianceTypeEnum;
		typedef IfcAxis1PlacementType IfcAxis1Placement;
		typedef IfcAxis2PlacementType IfcAxis2Placement;
		typedef IfcAxis2Placement2DType IfcAxis2Placement2D;
		typedef IfcAxis2Placement3DType IfcAxis2Placement3D;
		typedef IfcBeamType IfcBeam;
		typedef IfcBeamStandardCaseType IfcBeamStandardCase;
		typedef IfcBeamTypeType IfcBeamTType;
		typedef IfcBeamTypeEnumType IfcBeamTypeEnum;
		typedef IfcBenchmarkEnumType IfcBenchmarkEnum;
		typedef IfcBendingParameterSelectType IfcBendingParameterSelect;
		typedef IfcBlobTextureType IfcBlobTexture;
		typedef IfcBlockType IfcBlock;
		typedef IfcBoilerType IfcBoiler;
		typedef IfcBoilerTypeType IfcBoilerTType;
		typedef IfcBoilerTypeEnumType IfcBoilerTypeEnum;
		typedef IfcBooleanType IfcBoolean;
		typedef IfcBooleanClippingResultType IfcBooleanClippingResult;
		typedef IfcBooleanOperandType IfcBooleanOperand;
		typedef IfcBooleanOperatorType IfcBooleanOperator;
		typedef IfcBooleanResultType IfcBooleanResult;
		typedef IfcBoundaryConditionType IfcBoundaryCondition;
		typedef IfcBoundaryCurveType IfcBoundaryCurve;
		typedef IfcBoundaryEdgeConditionType IfcBoundaryEdgeCondition;
		typedef IfcBoundaryFaceConditionType IfcBoundaryFaceCondition;
		typedef IfcBoundaryNodeConditionType IfcBoundaryNodeCondition;
		typedef IfcBoundaryNodeConditionWarpingType IfcBoundaryNodeConditionWarping;
		typedef IfcBoundedCurveType IfcBoundedCurve;
		typedef IfcBoundedSurfaceType IfcBoundedSurface;
		typedef IfcBoundingBoxType IfcBoundingBox;
		typedef IfcBoxAlignmentType IfcBoxAlignment;
		typedef IfcBoxedHalfSpaceType IfcBoxedHalfSpace;
		typedef IfcBridgeType IfcBridge;
		typedef IfcBridgeContactElementType IfcBridgeContactElement;
		typedef IfcBridgeContactTypeType IfcBridgeContactType;
		typedef IfcBridgeElementType IfcBridgeElement;
		typedef IfcBridgeMechanicalRoleTypeType IfcBridgeMechanicalRoleType;
		typedef IfcBridgePartType IfcBridgePart;
		typedef IfcBridgePrismaticElementType IfcBridgePrismaticElement;
		typedef IfcBridgePrismaticElementTypeType IfcBridgePrismaticElementTType;
		typedef IfcBridgeSegmentType IfcBridgeSegment;
		typedef IfcBridgeSegmentPartType IfcBridgeSegmentPart;
		typedef IfcBridgeSegmentTypeType IfcBridgeSegmentTType;
		typedef IfcBridgeStructureElementType IfcBridgeStructureElement;
		typedef IfcBridgeStructureElementTypeType IfcBridgeStructureElementTType;
		typedef IfcBridgeStructureIndicatorType IfcBridgeStructureIndicator;
		typedef IfcBridgeStructureTypeType IfcBridgeStructureType;
		typedef IfcBridgeSubPartTypeType IfcBridgeSubPartType;
		typedef IfcBridgeTechnologicalElementTypeType IfcBridgeTechnologicalElementType;
		typedef IfcBSplineCurveType IfcBSplineCurve;
		typedef IfcBSplineCurveFormType IfcBSplineCurveForm;
		typedef IfcBSplineCurveWithKnotsType IfcBSplineCurveWithKnots;
		typedef IfcBSplineSurfaceType IfcBSplineSurface;
		typedef IfcBSplineSurfaceFormType IfcBSplineSurfaceForm;
		typedef IfcBSplineSurfaceWithKnotsType IfcBSplineSurfaceWithKnots;
		typedef IfcBuildingType IfcBuilding;
		typedef IfcBuildingElementType IfcBuildingElement;
		typedef IfcBuildingElementPartType IfcBuildingElementPart;
		typedef IfcBuildingElementPartTypeType IfcBuildingElementPartTType;
		typedef IfcBuildingElementPartTypeEnumType IfcBuildingElementPartTypeEnum;
		typedef IfcBuildingElementProxyType IfcBuildingElementProxy;
		typedef IfcBuildingElementProxyTypeType IfcBuildingElementProxyTType;
		typedef IfcBuildingElementProxyTypeEnumType IfcBuildingElementProxyTypeEnum;
		typedef IfcBuildingElementTypeType IfcBuildingElementTType;
		typedef IfcBuildingStoreyType IfcBuildingStorey;
		typedef IfcBuildingSystemType IfcBuildingSystem;
		typedef IfcBuildingSystemTypeEnumType IfcBuildingSystemTypeEnum;
		typedef IfcBurnerType IfcBurner;
		typedef IfcBurnerTypeType IfcBurnerTType;
		typedef IfcBurnerTypeEnumType IfcBurnerTypeEnum;
		typedef IfcCableCarrierFittingType IfcCableCarrierFitting;
		typedef IfcCableCarrierFittingTypeType IfcCableCarrierFittingTType;
		typedef IfcCableCarrierFittingTypeEnumType IfcCableCarrierFittingTypeEnum;
		typedef IfcCableCarrierSegmentType IfcCableCarrierSegment;
		typedef IfcCableCarrierSegmentTypeType IfcCableCarrierSegmentTType;
		typedef IfcCableCarrierSegmentTypeEnumType IfcCableCarrierSegmentTypeEnum;
		typedef IfcCableFittingType IfcCableFitting;
		typedef IfcCableFittingTypeType IfcCableFittingTType;
		typedef IfcCableFittingTypeEnumType IfcCableFittingTypeEnum;
		typedef IfcCableSegmentType IfcCableSegment;
		typedef IfcCableSegmentTypeType IfcCableSegmentTType;
		typedef IfcCableSegmentTypeEnumType IfcCableSegmentTypeEnum;
		typedef IfcCardinalPointReferenceType IfcCardinalPointReference;
		typedef IfcCartesianPointType IfcCartesianPoint;
		typedef IfcCartesianPointListType IfcCartesianPointList;
		typedef IfcCartesianTransformationOperatorType IfcCartesianTransformationOperator;
		typedef IfcCartesianTransformationOperator2DType IfcCartesianTransformationOperator2D;
		typedef IfcCartesianTransformationOperator2DnonUniformType IfcCartesianTransformationOperator2DnonUniform;
		typedef IfcCartesianTransformationOperator3DType IfcCartesianTransformationOperator3D;
		typedef IfcCartesianTransformationOperator3DnonUniformType IfcCartesianTransformationOperator3DnonUniform;
		typedef IfcCenterLineProfileDefType IfcCenterLineProfileDef;
		typedef IfcChangeActionEnumType IfcChangeActionEnum;
		typedef IfcCharacterStyleSelectType IfcCharacterStyleSelect;
		typedef IfcChillerType IfcChiller;
		typedef IfcChillerTypeType IfcChillerTType;
		typedef IfcChillerTypeEnumType IfcChillerTypeEnum;
		typedef IfcChimneyType IfcChimney;
		typedef IfcChimneyTypeType IfcChimneyTType;
		typedef IfcChimneyTypeEnumType IfcChimneyTypeEnum;
		typedef IfcCircleType IfcCircle;
		typedef IfcCircleHollowProfileDefType IfcCircleHollowProfileDef;
		typedef IfcCircleProfileDefType IfcCircleProfileDef;
		typedef IfcCivilElementType IfcCivilElement;
		typedef IfcCivilElementPartType IfcCivilElementPart;
		typedef IfcCivilSheathType IfcCivilSheath;
		typedef IfcCivilStructureElementType IfcCivilStructureElement;
		typedef IfcCivilVoidType IfcCivilVoid;
		typedef IfcClassificationType IfcClassification;
		typedef IfcClassificationReferenceType IfcClassificationReference;
		typedef IfcClassificationReferenceSelectType IfcClassificationReferenceSelect;
		typedef IfcClassificationSelectType IfcClassificationSelect;
		typedef IfcClosedShellType IfcClosedShell;
		typedef IfcClothoidType IfcClothoid;
		typedef IfcCoilType IfcCoil;
		typedef IfcCoilTypeType IfcCoilTType;
		typedef IfcCoilTypeEnumType IfcCoilTypeEnum;
		typedef IfcColourType IfcColour;
		typedef IfcColourOrFactorType IfcColourOrFactor;
		typedef IfcColourRgbType IfcColourRgb;
		typedef IfcColourRgbListType IfcColourRgbList;
		typedef IfcColourSpecificationType IfcColourSpecification;
		typedef IfcColumnType IfcColumn;
		typedef IfcColumnStandardCaseType IfcColumnStandardCase;
		typedef IfcColumnTypeType IfcColumnTType;
		typedef IfcColumnTypeEnumType IfcColumnTypeEnum;
		typedef IfcCommunicationsApplianceType IfcCommunicationsAppliance;
		typedef IfcCommunicationsApplianceTypeType IfcCommunicationsApplianceTType;
		typedef IfcCommunicationsApplianceTypeEnumType IfcCommunicationsApplianceTypeEnum;
		typedef IfcComplexNumberType IfcComplexNumber;
		typedef IfcComplexPropertyType IfcComplexProperty;
		typedef IfcComplexPropertyTemplateType IfcComplexPropertyTemplate;
		typedef IfcComplexPropertyTemplateTypeEnumType IfcComplexPropertyTemplateTypeEnum;
		typedef IfcCompositeCurveType IfcCompositeCurve;
		typedef IfcCompositeCurveOnSurfaceType IfcCompositeCurveOnSurface;
		typedef IfcCompositeCurveSegmentType IfcCompositeCurveSegment;
		typedef IfcCompositeProfileDefType IfcCompositeProfileDef;
		typedef IfcCompoundPlaneAngleMeasureType IfcCompoundPlaneAngleMeasure;
		typedef IfcCompressorType IfcCompressor;
		typedef IfcCompressorTypeType IfcCompressorTType;
		typedef IfcCompressorTypeEnumType IfcCompressorTypeEnum;
		typedef IfcCondenserType IfcCondenser;
		typedef IfcCondenserTypeType IfcCondenserTType;
		typedef IfcCondenserTypeEnumType IfcCondenserTypeEnum;
		typedef IfcConicType IfcConic;
		typedef IfcConnectedFaceSetType IfcConnectedFaceSet;
		typedef IfcConnectionCurveGeometryType IfcConnectionCurveGeometry;
		typedef IfcConnectionGeometryType IfcConnectionGeometry;
		typedef IfcConnectionPointEccentricityType IfcConnectionPointEccentricity;
		typedef IfcConnectionPointGeometryType IfcConnectionPointGeometry;
		typedef IfcConnectionSurfaceGeometryType IfcConnectionSurfaceGeometry;
		typedef IfcConnectionTypeEnumType IfcConnectionTypeEnum;
		typedef IfcConnectionVolumeGeometryType IfcConnectionVolumeGeometry;
		typedef IfcConstraintType IfcConstraint;
		typedef IfcConstraintEnumType IfcConstraintEnum;
		typedef IfcConstructionEquipmentResourceType IfcConstructionEquipmentResource;
		typedef IfcConstructionEquipmentResourceTypeType IfcConstructionEquipmentResourceTType;
		typedef IfcConstructionEquipmentResourceTypeEnumType IfcConstructionEquipmentResourceTypeEnum;
		typedef IfcConstructionMaterialResourceType IfcConstructionMaterialResource;
		typedef IfcConstructionMaterialResourceTypeType IfcConstructionMaterialResourceTType;
		typedef IfcConstructionMaterialResourceTypeEnumType IfcConstructionMaterialResourceTypeEnum;
		typedef IfcConstructionProductResourceType IfcConstructionProductResource;
		typedef IfcConstructionProductResourceTypeType IfcConstructionProductResourceTType;
		typedef IfcConstructionProductResourceTypeEnumType IfcConstructionProductResourceTypeEnum;
		typedef IfcConstructionResourceType IfcConstructionResource;
		typedef IfcConstructionResourceTypeType IfcConstructionResourceTType;
		typedef IfcContextType IfcContext;
		typedef IfcContextDependentMeasureType IfcContextDependentMeasure;
		typedef IfcContextDependentUnitType IfcContextDependentUnit;
		typedef IfcControlType IfcControl;
		typedef IfcControllerType IfcController;
		typedef IfcControllerTypeType IfcControllerTType;
		typedef IfcControllerTypeEnumType IfcControllerTypeEnum;
		typedef IfcConversionBasedUnitType IfcConversionBasedUnit;
		typedef IfcConversionBasedUnitWithOffsetType IfcConversionBasedUnitWithOffset;
		typedef IfcCooledBeamType IfcCooledBeam;
		typedef IfcCooledBeamTypeType IfcCooledBeamTType;
		typedef IfcCooledBeamTypeEnumType IfcCooledBeamTypeEnum;
		typedef IfcCoolingTowerType IfcCoolingTower;
		typedef IfcCoolingTowerTypeType IfcCoolingTowerTType;
		typedef IfcCoolingTowerTypeEnumType IfcCoolingTowerTypeEnum;
		typedef IfcCoordinateOperationType IfcCoordinateOperation;
		typedef IfcCoordinateReferenceSystemType IfcCoordinateReferenceSystem;
		typedef IfcCoordinateReferenceSystemSelectType IfcCoordinateReferenceSystemSelect;
		typedef IfcCostItemType IfcCostItem;
		typedef IfcCostItemTypeEnumType IfcCostItemTypeEnum;
		typedef IfcCostScheduleType IfcCostSchedule;
		typedef IfcCostScheduleTypeEnumType IfcCostScheduleTypeEnum;
		typedef IfcCostValueType IfcCostValue;
		typedef IfcCountMeasureType IfcCountMeasure;
		typedef IfcCoveringType IfcCovering;
		typedef IfcCoveringTypeType IfcCoveringTType;
		typedef IfcCoveringTypeEnumType IfcCoveringTypeEnum;
		typedef IfcCrewResourceType IfcCrewResource;
		typedef IfcCrewResourceTypeType IfcCrewResourceTType;
		typedef IfcCrewResourceTypeEnumType IfcCrewResourceTypeEnum;
		typedef IfcCsgPrimitive3DType IfcCsgPrimitive3D;
		typedef IfcCsgSelectType IfcCsgSelect;
		typedef IfcCsgSolidType IfcCsgSolid;
		typedef IfcCShapeProfileDefType IfcCShapeProfileDef;
		typedef IfcCurrencyRelationshipType IfcCurrencyRelationship;
		typedef IfcCurtainWallType IfcCurtainWall;
		typedef IfcCurtainWallTypeType IfcCurtainWallTType;
		typedef IfcCurtainWallTypeEnumType IfcCurtainWallTypeEnum;
		typedef IfcCurvatureMeasureType IfcCurvatureMeasure;
		typedef IfcCurveType IfcCurve;
		typedef IfcCurveBoundedPlaneType IfcCurveBoundedPlane;
		typedef IfcCurveBoundedSurfaceType IfcCurveBoundedSurface;
		typedef IfcCurveFontOrScaledCurveFontSelectType IfcCurveFontOrScaledCurveFontSelect;
		typedef IfcCurveInterpolationEnumType IfcCurveInterpolationEnum;
		typedef IfcCurveOnSurfaceType IfcCurveOnSurface;
		typedef IfcCurveOrEdgeCurveType IfcCurveOrEdgeCurve;
		typedef IfcCurveStyleType IfcCurveStyle;
		typedef IfcCurveStyleFontType IfcCurveStyleFont;
		typedef IfcCurveStyleFontAndScalingType IfcCurveStyleFontAndScaling;
		typedef IfcCurveStyleFontPatternType IfcCurveStyleFontPattern;
		typedef IfcCurveStyleFontSelectType IfcCurveStyleFontSelect;
		typedef IfcCylindricalSurfaceType IfcCylindricalSurface;
		typedef IfcDamperType IfcDamper;
		typedef IfcDamperTypeType IfcDamperTType;
		typedef IfcDamperTypeEnumType IfcDamperTypeEnum;
		typedef IfcDataOriginEnumType IfcDataOriginEnum;
		typedef IfcDateType IfcDate;
		typedef IfcDateTimeType IfcDateTime;
		typedef IfcDayInMonthNumberType IfcDayInMonthNumber;
		typedef IfcDayInWeekNumberType IfcDayInWeekNumber;
		typedef IfcDefinedSymbolType IfcDefinedSymbol;
		typedef IfcDefinedSymbolSelectType IfcDefinedSymbolSelect;
		typedef IfcDefinitionSelectType IfcDefinitionSelect;
		typedef IfcDerivedMeasureValueType IfcDerivedMeasureValue;
		typedef IfcDerivedProfileDefType IfcDerivedProfileDef;
		typedef IfcDerivedUnitType IfcDerivedUnit;
		typedef IfcDerivedUnitElementType IfcDerivedUnitElement;
		typedef IfcDerivedUnitEnumType IfcDerivedUnitEnum;
		typedef IfcDescriptiveMeasureType IfcDescriptiveMeasure;
		typedef IfcDimensionalExponentsType IfcDimensionalExponents;
		typedef IfcDimensionCountType IfcDimensionCount;
		typedef IfcDirectionType IfcDirection;
		typedef IfcDirectionListType IfcDirectionList;
		typedef IfcDirectionSenseEnumType IfcDirectionSenseEnum;
		typedef IfcDiscreteAccessoryType IfcDiscreteAccessory;
		typedef IfcDiscreteAccessoryTypeType IfcDiscreteAccessoryTType;
		typedef IfcDiscreteAccessoryTypeEnumType IfcDiscreteAccessoryTypeEnum;
		typedef IfcDistributionChamberElementType IfcDistributionChamberElement;
		typedef IfcDistributionChamberElementTypeType IfcDistributionChamberElementTType;
		typedef IfcDistributionChamberElementTypeEnumType IfcDistributionChamberElementTypeEnum;
		typedef IfcDistributionCircuitType IfcDistributionCircuit;
		typedef IfcDistributionControlElementType IfcDistributionControlElement;
		typedef IfcDistributionControlElementTypeType IfcDistributionControlElementTType;
		typedef IfcDistributionElementType IfcDistributionElement;
		typedef IfcDistributionElementTypeType IfcDistributionElementTType;
		typedef IfcDistributionFlowElementType IfcDistributionFlowElement;
		typedef IfcDistributionFlowElementTypeType IfcDistributionFlowElementTType;
		typedef IfcDistributionPortType IfcDistributionPort;
		typedef IfcDistributionSystemType IfcDistributionSystem;
		typedef IfcDistributionSystemEnumType IfcDistributionSystemEnum;
		typedef IfcDocumentConfidentialityEnumType IfcDocumentConfidentialityEnum;
		typedef IfcDocumentElectronicFormatType IfcDocumentElectronicFormat;
		typedef IfcDocumentInformationType IfcDocumentInformation;
		typedef IfcDocumentInformationRelationshipType IfcDocumentInformationRelationship;
		typedef IfcDocumentReferenceType IfcDocumentReference;
		typedef IfcDocumentSelectType IfcDocumentSelect;
		typedef IfcDocumentStatusEnumType IfcDocumentStatusEnum;
		typedef IfcDoorType IfcDoor;
		typedef IfcDoorLiningPropertiesType IfcDoorLiningProperties;
		typedef IfcDoorPanelOperationEnumType IfcDoorPanelOperationEnum;
		typedef IfcDoorPanelPositionEnumType IfcDoorPanelPositionEnum;
		typedef IfcDoorPanelPropertiesType IfcDoorPanelProperties;
		typedef IfcDoorStandardCaseType IfcDoorStandardCase;
		typedef IfcDoorStyleType IfcDoorStyle;
		typedef IfcDoorStyleConstructionEnumType IfcDoorStyleConstructionEnum;
		typedef IfcDoorStyleOperationEnumType IfcDoorStyleOperationEnum;
		typedef IfcDoorTypeType IfcDoorTType;
		typedef IfcDoorTypeEnumType IfcDoorTypeEnum;
		typedef IfcDoorTypeOperationEnumType IfcDoorTypeOperationEnum;
		typedef IfcDoseEquivalentMeasureType IfcDoseEquivalentMeasure;
		typedef IfcDraughtingPreDefinedColourType IfcDraughtingPreDefinedColour;
		typedef IfcDraughtingPreDefinedCurveFontType IfcDraughtingPreDefinedCurveFont;
		typedef IfcDraughtingPreDefinedTextFontType IfcDraughtingPreDefinedTextFont;
		typedef IfcDuctFittingType IfcDuctFitting;
		typedef IfcDuctFittingTypeType IfcDuctFittingTType;
		typedef IfcDuctFittingTypeEnumType IfcDuctFittingTypeEnum;
		typedef IfcDuctSegmentType IfcDuctSegment;
		typedef IfcDuctSegmentTypeType IfcDuctSegmentTType;
		typedef IfcDuctSegmentTypeEnumType IfcDuctSegmentTypeEnum;
		typedef IfcDuctSilencerType IfcDuctSilencer;
		typedef IfcDuctSilencerTypeType IfcDuctSilencerTType;
		typedef IfcDuctSilencerTypeEnumType IfcDuctSilencerTypeEnum;
		typedef IfcDurationType IfcDuration;
		typedef IfcDynamicViscosityMeasureType IfcDynamicViscosityMeasure;
		typedef IfcEdgeType IfcEdge;
		typedef IfcEdgeCurveType IfcEdgeCurve;
		typedef IfcEdgeLoopType IfcEdgeLoop;
		typedef IfcElectricApplianceType IfcElectricAppliance;
		typedef IfcElectricApplianceTypeType IfcElectricApplianceTType;
		typedef IfcElectricApplianceTypeEnumType IfcElectricApplianceTypeEnum;
		typedef IfcElectricCapacitanceMeasureType IfcElectricCapacitanceMeasure;
		typedef IfcElectricChargeMeasureType IfcElectricChargeMeasure;
		typedef IfcElectricConductanceMeasureType IfcElectricConductanceMeasure;
		typedef IfcElectricCurrentMeasureType IfcElectricCurrentMeasure;
		typedef IfcElectricDistributionBoardType IfcElectricDistributionBoard;
		typedef IfcElectricDistributionBoardTypeType IfcElectricDistributionBoardTType;
		typedef IfcElectricDistributionBoardTypeEnumType IfcElectricDistributionBoardTypeEnum;
		typedef IfcElectricFlowStorageDeviceType IfcElectricFlowStorageDevice;
		typedef IfcElectricFlowStorageDeviceTypeType IfcElectricFlowStorageDeviceTType;
		typedef IfcElectricFlowStorageDeviceTypeEnumType IfcElectricFlowStorageDeviceTypeEnum;
		typedef IfcElectricGeneratorType IfcElectricGenerator;
		typedef IfcElectricGeneratorTypeType IfcElectricGeneratorTType;
		typedef IfcElectricGeneratorTypeEnumType IfcElectricGeneratorTypeEnum;
		typedef IfcElectricMotorType IfcElectricMotor;
		typedef IfcElectricMotorTypeType IfcElectricMotorTType;
		typedef IfcElectricMotorTypeEnumType IfcElectricMotorTypeEnum;
		typedef IfcElectricResistanceMeasureType IfcElectricResistanceMeasure;
		typedef IfcElectricTimeControlType IfcElectricTimeControl;
		typedef IfcElectricTimeControlTypeType IfcElectricTimeControlTType;
		typedef IfcElectricTimeControlTypeEnumType IfcElectricTimeControlTypeEnum;
		typedef IfcElectricVoltageMeasureType IfcElectricVoltageMeasure;
		typedef IfcElementType IfcElement;
		typedef IfcElementarySurfaceType IfcElementarySurface;
		typedef IfcElementAssemblyType IfcElementAssembly;
		typedef IfcElementAssemblyTypeType IfcElementAssemblyTType;
		typedef IfcElementAssemblyTypeEnumType IfcElementAssemblyTypeEnum;
		typedef IfcElementComponentType IfcElementComponent;
		typedef IfcElementComponentTypeType IfcElementComponentTType;
		typedef IfcElementCompositionEnumType IfcElementCompositionEnum;
		typedef IfcElementPartType IfcElementPart;
		typedef IfcElementQuantityType IfcElementQuantity;
		typedef IfcElementTypeType IfcElementTType;
		typedef IfcEllipseType IfcEllipse;
		typedef IfcEllipseProfileDefType IfcEllipseProfileDef;
		typedef IfcEnergyConversionDeviceType IfcEnergyConversionDevice;
		typedef IfcEnergyConversionDeviceTypeType IfcEnergyConversionDeviceTType;
		typedef IfcEnergyMeasureType IfcEnergyMeasure;
		typedef IfcEngineType IfcEngine;
		typedef IfcEngineTypeType IfcEngineTType;
		typedef IfcEngineTypeEnumType IfcEngineTypeEnum;
		typedef IfcEvaporativeCoolerType IfcEvaporativeCooler;
		typedef IfcEvaporativeCoolerTypeType IfcEvaporativeCoolerTType;
		typedef IfcEvaporativeCoolerTypeEnumType IfcEvaporativeCoolerTypeEnum;
		typedef IfcEvaporatorType IfcEvaporator;
		typedef IfcEvaporatorTypeType IfcEvaporatorTType;
		typedef IfcEvaporatorTypeEnumType IfcEvaporatorTypeEnum;
		typedef IfcEventType IfcEvent;
		typedef IfcEventTimeType IfcEventTime;
		typedef IfcEventTriggerTypeEnumType IfcEventTriggerTypeEnum;
		typedef IfcEventTypeType IfcEventTType;
		typedef IfcEventTypeEnumType IfcEventTypeEnum;
		typedef IfcExtendedPropertiesType IfcExtendedProperties;
		typedef IfcExternalInformationType IfcExternalInformation;
		typedef IfcExternallyDefinedHatchStyleType IfcExternallyDefinedHatchStyle;
		typedef IfcExternallyDefinedSurfaceStyleType IfcExternallyDefinedSurfaceStyle;
		typedef IfcExternallyDefinedSymbolType IfcExternallyDefinedSymbol;
		typedef IfcExternallyDefinedTextFontType IfcExternallyDefinedTextFont;
		typedef IfcExternalReferenceType IfcExternalReference;
		typedef IfcExternalReferenceRelationshipType IfcExternalReferenceRelationship;
		typedef IfcExternalSpatialElementType IfcExternalSpatialElement;
		typedef IfcExternalSpatialElementTypeEnumType IfcExternalSpatialElementTypeEnum;
		typedef IfcExternalSpatialStructureElementType IfcExternalSpatialStructureElement;
		typedef IfcExtrudedAreaSolidType IfcExtrudedAreaSolid;
		typedef IfcExtrudedAreaSolidTaperedType IfcExtrudedAreaSolidTapered;
		typedef IfcFaceType IfcFace;
		typedef IfcFaceBasedSurfaceModelType IfcFaceBasedSurfaceModel;
		typedef IfcFaceBoundType IfcFaceBound;
		typedef IfcFaceOuterBoundType IfcFaceOuterBound;
		typedef IfcFaceSurfaceType IfcFaceSurface;
		typedef IfcFacetedBrepType IfcFacetedBrep;
		typedef IfcFacetedBrepWithVoidsType IfcFacetedBrepWithVoids;
		typedef IfcFailureConnectionConditionType IfcFailureConnectionCondition;
		typedef IfcFanType IfcFan;
		typedef IfcFanTypeType IfcFanTType;
		typedef IfcFanTypeEnumType IfcFanTypeEnum;
		typedef IfcFastenerType IfcFastener;
		typedef IfcFastenerTypeType IfcFastenerTType;
		typedef IfcFastenerTypeEnumType IfcFastenerTypeEnum;
		typedef IfcFeatureElementType IfcFeatureElement;
		typedef IfcFeatureElementAdditionType IfcFeatureElementAddition;
		typedef IfcFeatureElementSubtractionType IfcFeatureElementSubtraction;
		typedef IfcFillAreaStyleType IfcFillAreaStyle;
		typedef IfcFillAreaStyleHatchingType IfcFillAreaStyleHatching;
		typedef IfcFillAreaStyleTilesType IfcFillAreaStyleTiles;
		typedef IfcFillAreaStyleTileShapeSelectType IfcFillAreaStyleTileShapeSelect;
		typedef IfcFillAreaStyleTileSymbolWithStyleType IfcFillAreaStyleTileSymbolWithStyle;
		typedef IfcFillStyleSelectType IfcFillStyleSelect;
		typedef IfcFilterType IfcFilter;
		typedef IfcFilterTypeType IfcFilterTType;
		typedef IfcFilterTypeEnumType IfcFilterTypeEnum;
		typedef IfcFireSuppressionTerminalType IfcFireSuppressionTerminal;
		typedef IfcFireSuppressionTerminalTypeType IfcFireSuppressionTerminalTType;
		typedef IfcFireSuppressionTerminalTypeEnumType IfcFireSuppressionTerminalTypeEnum;
		typedef IfcFixedReferenceSweptAreaSolidType IfcFixedReferenceSweptAreaSolid;
		typedef IfcFlowControllerType IfcFlowController;
		typedef IfcFlowControllerTypeType IfcFlowControllerTType;
		typedef IfcFlowDirectionEnumType IfcFlowDirectionEnum;
		typedef IfcFlowFittingType IfcFlowFitting;
		typedef IfcFlowFittingTypeType IfcFlowFittingTType;
		typedef IfcFlowInstrumentType IfcFlowInstrument;
		typedef IfcFlowInstrumentTypeType IfcFlowInstrumentTType;
		typedef IfcFlowInstrumentTypeEnumType IfcFlowInstrumentTypeEnum;
		typedef IfcFlowMeterType IfcFlowMeter;
		typedef IfcFlowMeterTypeType IfcFlowMeterTType;
		typedef IfcFlowMeterTypeEnumType IfcFlowMeterTypeEnum;
		typedef IfcFlowMovingDeviceType IfcFlowMovingDevice;
		typedef IfcFlowMovingDeviceTypeType IfcFlowMovingDeviceTType;
		typedef IfcFlowSegmentType IfcFlowSegment;
		typedef IfcFlowSegmentTypeType IfcFlowSegmentTType;
		typedef IfcFlowStorageDeviceType IfcFlowStorageDevice;
		typedef IfcFlowStorageDeviceTypeType IfcFlowStorageDeviceTType;
		typedef IfcFlowTerminalType IfcFlowTerminal;
		typedef IfcFlowTerminalTypeType IfcFlowTerminalTType;
		typedef IfcFlowTreatmentDeviceType IfcFlowTreatmentDevice;
		typedef IfcFlowTreatmentDeviceTypeType IfcFlowTreatmentDeviceTType;
		typedef IfcFontStyleType IfcFontStyle;
		typedef IfcFontVariantType IfcFontVariant;
		typedef IfcFontWeightType IfcFontWeight;
		typedef IfcFootingType IfcFooting;
		typedef IfcFootingTypeType IfcFootingTType;
		typedef IfcFootingTypeEnumType IfcFootingTypeEnum;
		typedef IfcForceMeasureType IfcForceMeasure;
		typedef IfcFrequencyMeasureType IfcFrequencyMeasure;
		typedef IfcFurnishingElementType IfcFurnishingElement;
		typedef IfcFurnishingElementTypeType IfcFurnishingElementTType;
		typedef IfcFurnitureType IfcFurniture;
		typedef IfcFurnitureTypeType IfcFurnitureTType;
		typedef IfcFurnitureTypeEnumType IfcFurnitureTypeEnum;
		typedef IfcGeographicElementType IfcGeographicElement;
		typedef IfcGeographicElementTypeType IfcGeographicElementTType;
		typedef IfcGeographicElementTypeEnumType IfcGeographicElementTypeEnum;
		typedef IfcGeometricCurveSetType IfcGeometricCurveSet;
		typedef IfcGeometricProjectionEnumType IfcGeometricProjectionEnum;
		typedef IfcGeometricRepresentationContextType IfcGeometricRepresentationContext;
		typedef IfcGeometricRepresentationItemType IfcGeometricRepresentationItem;
		typedef IfcGeometricRepresentationSubContextType IfcGeometricRepresentationSubContext;
		typedef IfcGeometricSetType IfcGeometricSet;
		typedef IfcGeometricSetSelectType IfcGeometricSetSelect;
		typedef IfcGloballyUniqueIdType IfcGloballyUniqueId;
		typedef IfcGlobalOrLocalEnumType IfcGlobalOrLocalEnum;
		typedef IfcGridType IfcGrid;
		typedef IfcGridAxisType IfcGridAxis;
		typedef IfcGridPlacementType IfcGridPlacement;
		typedef IfcGridPlacementDirectionSelectType IfcGridPlacementDirectionSelect;
		typedef IfcGridTypeEnumType IfcGridTypeEnum;
		typedef IfcGroupType IfcGroup;
		typedef IfcHalfSpaceSolidType IfcHalfSpaceSolid;
		typedef IfcHatchLineDistanceSelectType IfcHatchLineDistanceSelect;
		typedef IfcHeatExchangerType IfcHeatExchanger;
		typedef IfcHeatExchangerTypeType IfcHeatExchangerTType;
		typedef IfcHeatExchangerTypeEnumType IfcHeatExchangerTypeEnum;
		typedef IfcHeatFluxDensityMeasureType IfcHeatFluxDensityMeasure;
		typedef IfcHeatingValueMeasureType IfcHeatingValueMeasure;
		typedef IfcHumidifierType IfcHumidifier;
		typedef IfcHumidifierTypeType IfcHumidifierTType;
		typedef IfcHumidifierTypeEnumType IfcHumidifierTypeEnum;
		typedef IfcIdentifierType IfcIdentifier;
		typedef IfcIlluminanceMeasureType IfcIlluminanceMeasure;
		typedef IfcImageTextureType IfcImageTexture;
		typedef IfcIndexedColourMapType IfcIndexedColourMap;
		typedef IfcIndexedTextureMapType IfcIndexedTextureMap;
		typedef IfcIndexedTriangleTextureMapType IfcIndexedTriangleTextureMap;
		typedef IfcInductanceMeasureType IfcInductanceMeasure;
		typedef IfcIntegerType IfcInteger;
		typedef IfcIntegerCountRateMeasureType IfcIntegerCountRateMeasure;
		typedef IfcInterceptorType IfcInterceptor;
		typedef IfcInterceptorTypeType IfcInterceptorTType;
		typedef IfcInterceptorTypeEnumType IfcInterceptorTypeEnum;
		typedef IfcInternalOrExternalEnumType IfcInternalOrExternalEnum;
		typedef IfcInventoryType IfcInventory;
		typedef IfcInventoryTypeEnumType IfcInventoryTypeEnum;
		typedef IfcIonConcentrationMeasureType IfcIonConcentrationMeasure;
		typedef IfcIrregularTimeSeriesType IfcIrregularTimeSeries;
		typedef IfcIrregularTimeSeriesValueType IfcIrregularTimeSeriesValue;
		typedef IfcIShapeProfileDefType IfcIShapeProfileDef;
		typedef IfcIsothermalMoistureCapacityMeasureType IfcIsothermalMoistureCapacityMeasure;
		typedef IfcJunctionBoxType IfcJunctionBox;
		typedef IfcJunctionBoxTypeType IfcJunctionBoxTType;
		typedef IfcJunctionBoxTypeEnumType IfcJunctionBoxTypeEnum;
		typedef IfcKinematicViscosityMeasureType IfcKinematicViscosityMeasure;
		typedef IfcKnotTypeType IfcKnotType;
		typedef IfcLabelType IfcLabel;
		typedef IfcLaborResourceType IfcLaborResource;
		typedef IfcLaborResourceTypeType IfcLaborResourceTType;
		typedef IfcLaborResourceTypeEnumType IfcLaborResourceTypeEnum;
		typedef IfcLagTimeType IfcLagTime;
		typedef IfcLampType IfcLamp;
		typedef IfcLampTypeType IfcLampTType;
		typedef IfcLampTypeEnumType IfcLampTypeEnum;
		typedef IfcLanguageIdType IfcLanguageId;
		typedef IfcLayeredItemType IfcLayeredItem;
		typedef IfcLayerSetDirectionEnumType IfcLayerSetDirectionEnum;
		typedef IfcLengthMeasureType IfcLengthMeasure;
		typedef IfcLibraryInformationType IfcLibraryInformation;
		typedef IfcLibraryReferenceType IfcLibraryReference;
		typedef IfcLibrarySelectType IfcLibrarySelect;
		typedef IfcLightDistributionCurveEnumType IfcLightDistributionCurveEnum;
		typedef IfcLightDistributionDataType IfcLightDistributionData;
		typedef IfcLightDistributionDataSourceSelectType IfcLightDistributionDataSourceSelect;
		typedef IfcLightEmissionSourceEnumType IfcLightEmissionSourceEnum;
		typedef IfcLightFixtureType IfcLightFixture;
		typedef IfcLightFixtureTypeType IfcLightFixtureTType;
		typedef IfcLightFixtureTypeEnumType IfcLightFixtureTypeEnum;
		typedef IfcLightIntensityDistributionType IfcLightIntensityDistribution;
		typedef IfcLightSourceType IfcLightSource;
		typedef IfcLightSourceAmbientType IfcLightSourceAmbient;
		typedef IfcLightSourceDirectionalType IfcLightSourceDirectional;
		typedef IfcLightSourceGoniometricType IfcLightSourceGoniometric;
		typedef IfcLightSourcePositionalType IfcLightSourcePositional;
		typedef IfcLightSourceSpotType IfcLightSourceSpot;
		typedef IfcLineType IfcLine;
		typedef IfcLinearForceMeasureType IfcLinearForceMeasure;
		typedef IfcLinearMomentMeasureType IfcLinearMomentMeasure;
		typedef IfcLinearStiffnessMeasureType IfcLinearStiffnessMeasure;
		typedef IfcLinearVelocityMeasureType IfcLinearVelocityMeasure;
		typedef IfcLoadGroupTypeEnumType IfcLoadGroupTypeEnum;
		typedef IfcLocalPlacementType IfcLocalPlacement;
		typedef IfcLogicalType IfcLogical;
		typedef IfcLogicalOperatorEnumType IfcLogicalOperatorEnum;
		typedef IfcLoopType IfcLoop;
		typedef IfcLShapeProfileDefType IfcLShapeProfileDef;
		typedef IfcLuminousFluxMeasureType IfcLuminousFluxMeasure;
		typedef IfcLuminousIntensityDistributionMeasureType IfcLuminousIntensityDistributionMeasure;
		typedef IfcLuminousIntensityMeasureType IfcLuminousIntensityMeasure;
		typedef IfcMagneticFluxDensityMeasureType IfcMagneticFluxDensityMeasure;
		typedef IfcMagneticFluxMeasureType IfcMagneticFluxMeasure;
		typedef IfcManifoldSolidBrepType IfcManifoldSolidBrep;
		typedef IfcMapConversionType IfcMapConversion;
		typedef IfcMappedItemType IfcMappedItem;
		typedef IfcMassDensityMeasureType IfcMassDensityMeasure;
		typedef IfcMassFlowRateMeasureType IfcMassFlowRateMeasure;
		typedef IfcMassMeasureType IfcMassMeasure;
		typedef IfcMassPerLengthMeasureType IfcMassPerLengthMeasure;
		typedef IfcMaterialType IfcMaterial;
		typedef IfcMaterialClassificationRelationshipType IfcMaterialClassificationRelationship;
		typedef IfcMaterialConstituentType IfcMaterialConstituent;
		typedef IfcMaterialConstituentSetType IfcMaterialConstituentSet;
		typedef IfcMaterialDefinitionType IfcMaterialDefinition;
		typedef IfcMaterialDefinitionRepresentationType IfcMaterialDefinitionRepresentation;
		typedef IfcMaterialLayerType IfcMaterialLayer;
		typedef IfcMaterialLayerSetType IfcMaterialLayerSet;
		typedef IfcMaterialLayerSetUsageType IfcMaterialLayerSetUsage;
		typedef IfcMaterialLayerWithOffsetsType IfcMaterialLayerWithOffsets;
		typedef IfcMaterialListType IfcMaterialList;
		typedef IfcMaterialProfileType IfcMaterialProfile;
		typedef IfcMaterialProfileSetType IfcMaterialProfileSet;
		typedef IfcMaterialProfileSetUsageType IfcMaterialProfileSetUsage;
		typedef IfcMaterialProfileSetUsageTaperingType IfcMaterialProfileSetUsageTapering;
		typedef IfcMaterialProfileWithOffsetsType IfcMaterialProfileWithOffsets;
		typedef IfcMaterialPropertiesType IfcMaterialProperties;
		typedef IfcMaterialRelationshipType IfcMaterialRelationship;
		typedef IfcMaterialSelectType IfcMaterialSelect;
		typedef IfcMaterialUsageDefinitionType IfcMaterialUsageDefinition;
		typedef IfcMeasureValueType IfcMeasureValue;
		typedef IfcMeasureWithUnitType IfcMeasureWithUnit;
		typedef IfcMechanicalFastenerType IfcMechanicalFastener;
		typedef IfcMechanicalFastenerTypeType IfcMechanicalFastenerTType;
		typedef IfcMechanicalFastenerTypeEnumType IfcMechanicalFastenerTypeEnum;
		typedef IfcMedicalDeviceType IfcMedicalDevice;
		typedef IfcMedicalDeviceTypeType IfcMedicalDeviceTType;
		typedef IfcMedicalDeviceTypeEnumType IfcMedicalDeviceTypeEnum;
		typedef IfcMemberType IfcMember;
		typedef IfcMemberStandardCaseType IfcMemberStandardCase;
		typedef IfcMemberTypeType IfcMemberTType;
		typedef IfcMemberTypeEnumType IfcMemberTypeEnum;
		typedef IfcMetricType IfcMetric;
		typedef IfcMetricValueSelectType IfcMetricValueSelect;
		typedef IfcMirroredProfileDefType IfcMirroredProfileDef;
		typedef IfcModulusOfElasticityMeasureType IfcModulusOfElasticityMeasure;
		typedef IfcModulusOfLinearSubgradeReactionMeasureType IfcModulusOfLinearSubgradeReactionMeasure;
		typedef IfcModulusOfRotationalSubgradeReactionMeasureType IfcModulusOfRotationalSubgradeReactionMeasure;
		typedef IfcModulusOfRotationalSubgradeReactionSelectType IfcModulusOfRotationalSubgradeReactionSelect;
		typedef IfcModulusOfSubgradeReactionMeasureType IfcModulusOfSubgradeReactionMeasure;
		typedef IfcModulusOfSubgradeReactionSelectType IfcModulusOfSubgradeReactionSelect;
		typedef IfcModulusOfTranslationalSubgradeReactionSelectType IfcModulusOfTranslationalSubgradeReactionSelect;
		typedef IfcMoistureDiffusivityMeasureType IfcMoistureDiffusivityMeasure;
		typedef IfcMolecularWeightMeasureType IfcMolecularWeightMeasure;
		typedef IfcMomentOfInertiaMeasureType IfcMomentOfInertiaMeasure;
		typedef IfcMonetaryMeasureType IfcMonetaryMeasure;
		typedef IfcMonetaryUnitType IfcMonetaryUnit;
		typedef IfcMonthInYearNumberType IfcMonthInYearNumber;
		typedef IfcMotorConnectionType IfcMotorConnection;
		typedef IfcMotorConnectionTypeType IfcMotorConnectionTType;
		typedef IfcMotorConnectionTypeEnumType IfcMotorConnectionTypeEnum;
		typedef IfcNamedUnitType IfcNamedUnit;
		typedef IfcNonNegativeLengthMeasureType IfcNonNegativeLengthMeasure;
		typedef IfcNormalisedRatioMeasureType IfcNormalisedRatioMeasure;
		typedef IfcNullStyleType IfcNullStyle;
		typedef IfcNumericMeasureType IfcNumericMeasure;
		typedef IfcObjectType IfcObject;
		typedef IfcObjectDefinitionType IfcObjectDefinition;
		typedef IfcObjectiveType IfcObjective;
		typedef IfcObjectiveEnumType IfcObjectiveEnum;
		typedef IfcObjectPlacementType IfcObjectPlacement;
		typedef IfcObjectReferenceSelectType IfcObjectReferenceSelect;
		typedef IfcObjectTypeEnumType IfcObjectTypeEnum;
		typedef IfcOccupantType IfcOccupant;
		typedef IfcOccupantTypeEnumType IfcOccupantTypeEnum;
		typedef IfcOffsetCurve2DType IfcOffsetCurve2D;
		typedef IfcOffsetCurve3DType IfcOffsetCurve3D;
		typedef IfcOneDirectionRepeatFactorType IfcOneDirectionRepeatFactor;
		typedef IfcOpeningElementType IfcOpeningElement;
		typedef IfcOpeningElementTypeEnumType IfcOpeningElementTypeEnum;
		typedef IfcOpeningStandardCaseType IfcOpeningStandardCase;
		typedef IfcOpenShellType IfcOpenShell;
		typedef IfcOrganizationType IfcOrganization;
		typedef IfcOrganizationRelationshipType IfcOrganizationRelationship;
		typedef IfcOrientedEdgeType IfcOrientedEdge;
		typedef IfcOuterBoundaryCurveType IfcOuterBoundaryCurve;
		typedef IfcOutletType IfcOutlet;
		typedef IfcOutletTypeType IfcOutletTType;
		typedef IfcOutletTypeEnumType IfcOutletTypeEnum;
		typedef IfcOwnerHistoryType IfcOwnerHistory;
		typedef IfcParameterizedProfileDefType IfcParameterizedProfileDef;
		typedef IfcParameterValueType IfcParameterValue;
		typedef IfcPathType IfcPath;
		typedef IfcPcurveType IfcPcurve;
		typedef IfcPerformanceHistoryType IfcPerformanceHistory;
		typedef IfcPerformanceHistoryTypeEnumType IfcPerformanceHistoryTypeEnum;
		typedef IfcPermeableCoveringOperationEnumType IfcPermeableCoveringOperationEnum;
		typedef IfcPermeableCoveringPropertiesType IfcPermeableCoveringProperties;
		typedef IfcPermitType IfcPermit;
		typedef IfcPermitTypeEnumType IfcPermitTypeEnum;
		typedef IfcPersonType IfcPerson;
		typedef IfcPersonAndOrganizationType IfcPersonAndOrganization;
		typedef IfcPHMeasureType IfcPHMeasure;
		typedef IfcPhysicalComplexQuantityType IfcPhysicalComplexQuantity;
		typedef IfcPhysicalOrVirtualEnumType IfcPhysicalOrVirtualEnum;
		typedef IfcPhysicalQuantityType IfcPhysicalQuantity;
		typedef IfcPhysicalSimpleQuantityType IfcPhysicalSimpleQuantity;
		typedef IfcPileType IfcPile;
		typedef IfcPileConstructionEnumType IfcPileConstructionEnum;
		typedef IfcPileTypeType IfcPileTType;
		typedef IfcPileTypeEnumType IfcPileTypeEnum;
		typedef IfcPipeFittingType IfcPipeFitting;
		typedef IfcPipeFittingTypeType IfcPipeFittingTType;
		typedef IfcPipeFittingTypeEnumType IfcPipeFittingTypeEnum;
		typedef IfcPipeSegmentType IfcPipeSegment;
		typedef IfcPipeSegmentTypeType IfcPipeSegmentTType;
		typedef IfcPipeSegmentTypeEnumType IfcPipeSegmentTypeEnum;
		typedef IfcPixelTextureType IfcPixelTexture;
		typedef IfcPlacementType IfcPlacement;
		typedef IfcPlanarBoxType IfcPlanarBox;
		typedef IfcPlanarExtentType IfcPlanarExtent;
		typedef IfcPlanarForceMeasureType IfcPlanarForceMeasure;
		typedef IfcPlaneType IfcPlane;
		typedef IfcPlaneAngleMeasureType IfcPlaneAngleMeasure;
		typedef IfcPlateType IfcPlate;
		typedef IfcPlateStandardCaseType IfcPlateStandardCase;
		typedef IfcPlateTypeType IfcPlateTType;
		typedef IfcPlateTypeEnumType IfcPlateTypeEnum;
		typedef IfcPointType IfcPoint;
		typedef IfcPointOnCurveType IfcPointOnCurve;
		typedef IfcPointOnSurfaceType IfcPointOnSurface;
		typedef IfcPointOrVertexPointType IfcPointOrVertexPoint;
		typedef IfcPolygonalBoundedHalfSpaceType IfcPolygonalBoundedHalfSpace;
		typedef IfcPolylineType IfcPolyline;
		typedef IfcPolyLoopType IfcPolyLoop;
		typedef IfcPortType IfcPort;
		typedef IfcPositiveLengthMeasureType IfcPositiveLengthMeasure;
		typedef IfcPositivePlaneAngleMeasureType IfcPositivePlaneAngleMeasure;
		typedef IfcPositiveRatioMeasureType IfcPositiveRatioMeasure;
		typedef IfcPostalAddressType IfcPostalAddress;
		typedef IfcPowerMeasureType IfcPowerMeasure;
		typedef IfcPreDefinedColourType IfcPreDefinedColour;
		typedef IfcPreDefinedCurveFontType IfcPreDefinedCurveFont;
		typedef IfcPreDefinedItemType IfcPreDefinedItem;
		typedef IfcPreDefinedPropertiesType IfcPreDefinedProperties;
		typedef IfcPreDefinedPropertySetType IfcPreDefinedPropertySet;
		typedef IfcPreDefinedSymbolType IfcPreDefinedSymbol;
		typedef IfcPreDefinedTextFontType IfcPreDefinedTextFont;
		typedef IfcPresentableTextType IfcPresentableText;
		typedef IfcPresentationItemType IfcPresentationItem;
		typedef IfcPresentationLayerAssignmentType IfcPresentationLayerAssignment;
		typedef IfcPresentationLayerWithStyleType IfcPresentationLayerWithStyle;
		typedef IfcPresentationStyleType IfcPresentationStyle;
		typedef IfcPresentationStyleAssignmentType IfcPresentationStyleAssignment;
		typedef IfcPresentationStyleSelectType IfcPresentationStyleSelect;
		typedef IfcPressureMeasureType IfcPressureMeasure;
		typedef IfcProcedureType IfcProcedure;
		typedef IfcProcedureTypeType IfcProcedureTType;
		typedef IfcProcedureTypeEnumType IfcProcedureTypeEnum;
		typedef IfcProcessType IfcProcess;
		typedef IfcProcessSelectType IfcProcessSelect;
		typedef IfcProductType IfcProduct;
		typedef IfcProductDefinitionShapeType IfcProductDefinitionShape;
		typedef IfcProductRepresentationType IfcProductRepresentation;
		typedef IfcProductSelectType IfcProductSelect;
		typedef IfcProfileDefType IfcProfileDef;
		typedef IfcProfilePropertiesType IfcProfileProperties;
		typedef IfcProfileTypeEnumType IfcProfileTypeEnum;
		typedef IfcProjectType IfcProject;
		typedef IfcProjectedCRSType IfcProjectedCRS;
		typedef IfcProjectedOrTrueLengthEnumType IfcProjectedOrTrueLengthEnum;
		typedef IfcProjectionElementType IfcProjectionElement;
		typedef IfcProjectionElementTypeEnumType IfcProjectionElementTypeEnum;
		typedef IfcProjectLibraryType IfcProjectLibrary;
		typedef IfcProjectOrderType IfcProjectOrder;
		typedef IfcProjectOrderTypeEnumType IfcProjectOrderTypeEnum;
		typedef IfcPropertyType IfcProperty;
		typedef IfcPropertyAbstractionType IfcPropertyAbstraction;
		typedef IfcPropertyBoundedValueType IfcPropertyBoundedValue;
		typedef IfcPropertyDefinitionType IfcPropertyDefinition;
		typedef IfcPropertyDependencyRelationshipType IfcPropertyDependencyRelationship;
		typedef IfcPropertyEnumeratedValueType IfcPropertyEnumeratedValue;
		typedef IfcPropertyEnumerationType IfcPropertyEnumeration;
		typedef IfcPropertyListValueType IfcPropertyListValue;
		typedef IfcPropertyReferenceValueType IfcPropertyReferenceValue;
		typedef IfcPropertySetType IfcPropertySet;
		typedef IfcPropertySetDefinitionType IfcPropertySetDefinition;
		typedef IfcPropertySetTemplateType IfcPropertySetTemplate;
		typedef IfcPropertySetTemplateTypeEnumType IfcPropertySetTemplateTypeEnum;
		typedef IfcPropertySingleValueType IfcPropertySingleValue;
		typedef IfcPropertyTableValueType IfcPropertyTableValue;
		typedef IfcPropertyTemplateType IfcPropertyTemplate;
		typedef IfcPropertyTemplateDefinitionType IfcPropertyTemplateDefinition;
		typedef IfcProtectiveDeviceType IfcProtectiveDevice;
		typedef IfcProtectiveDeviceTrippingUnitType IfcProtectiveDeviceTrippingUnit;
		typedef IfcProtectiveDeviceTrippingUnitTypeType IfcProtectiveDeviceTrippingUnitTType;
		typedef IfcProtectiveDeviceTrippingUnitTypeEnumType IfcProtectiveDeviceTrippingUnitTypeEnum;
		typedef IfcProtectiveDeviceTypeType IfcProtectiveDeviceTType;
		typedef IfcProtectiveDeviceTypeEnumType IfcProtectiveDeviceTypeEnum;
		typedef IfcProxyType IfcProxy;
		typedef IfcPumpType IfcPump;
		typedef IfcPumpTypeType IfcPumpTType;
		typedef IfcPumpTypeEnumType IfcPumpTypeEnum;
		typedef IfcQuantityAreaType IfcQuantityArea;
		typedef IfcQuantityCountType IfcQuantityCount;
		typedef IfcQuantityLengthType IfcQuantityLength;
		typedef IfcQuantitySetType IfcQuantitySet;
		typedef IfcQuantityTimeType IfcQuantityTime;
		typedef IfcQuantityVolumeType IfcQuantityVolume;
		typedef IfcQuantityWeightType IfcQuantityWeight;
		typedef IfcRadioActivityMeasureType IfcRadioActivityMeasure;
		typedef IfcRailingType IfcRailing;
		typedef IfcRailingTypeType IfcRailingTType;
		typedef IfcRailingTypeEnumType IfcRailingTypeEnum;
		typedef IfcRampType IfcRamp;
		typedef IfcRampFlightType IfcRampFlight;
		typedef IfcRampFlightTypeType IfcRampFlightTType;
		typedef IfcRampFlightTypeEnumType IfcRampFlightTypeEnum;
		typedef IfcRampTypeType IfcRampTType;
		typedef IfcRampTypeEnumType IfcRampTypeEnum;
		typedef IfcRatioMeasureType IfcRatioMeasure;
		typedef IfcRationalBSplineCurveWithKnotsType IfcRationalBSplineCurveWithKnots;
		typedef IfcRationalBSplineSurfaceWithKnotsType IfcRationalBSplineSurfaceWithKnots;
		typedef IfcRealType IfcReal;
		typedef IfcRectangleHollowProfileDefType IfcRectangleHollowProfileDef;
		typedef IfcRectangleProfileDefType IfcRectangleProfileDef;
		typedef IfcRectangularPyramidType IfcRectangularPyramid;
		typedef IfcRectangularTrimmedSurfaceType IfcRectangularTrimmedSurface;
		typedef IfcRecurrencePatternType IfcRecurrencePattern;
		typedef IfcRecurrenceTypeEnumType IfcRecurrenceTypeEnum;
		typedef IfcReferenceCurveType IfcReferenceCurve;
		typedef IfcReferenceCurve3DType IfcReferenceCurve3D;
		typedef IfcReferenceCurveAlignment2DType IfcReferenceCurveAlignment2D;
		typedef IfcReferenceCurvePlacementType IfcReferenceCurvePlacement;
		typedef IfcReferenceCurvePlacementSystemType IfcReferenceCurvePlacementSystem;
		typedef IfcReferencedSectionedSpineType IfcReferencedSectionedSpine;
		typedef IfcReferenceElementType IfcReferenceElement;
		typedef IfcReferencePlacementType IfcReferencePlacement;
		typedef IfcReflectanceMethodEnumType IfcReflectanceMethodEnum;
		typedef IfcRegularTimeSeriesType IfcRegularTimeSeries;
		typedef IfcReinforcementBarPropertiesType IfcReinforcementBarProperties;
		typedef IfcReinforcementDefinitionPropertiesType IfcReinforcementDefinitionProperties;
		typedef IfcReinforcingBarType IfcReinforcingBar;
		typedef IfcReinforcingBarRoleEnumType IfcReinforcingBarRoleEnum;
		typedef IfcReinforcingBarSurfaceEnumType IfcReinforcingBarSurfaceEnum;
		typedef IfcReinforcingBarTypeType IfcReinforcingBarTType;
		typedef IfcReinforcingBarTypeEnumType IfcReinforcingBarTypeEnum;
		typedef IfcReinforcingElementType IfcReinforcingElement;
		typedef IfcReinforcingElementTypeType IfcReinforcingElementTType;
		typedef IfcReinforcingMeshType IfcReinforcingMesh;
		typedef IfcReinforcingMeshTypeType IfcReinforcingMeshTType;
		typedef IfcReinforcingMeshTypeEnumType IfcReinforcingMeshTypeEnum;
		typedef IfcRelAggregatesType IfcRelAggregates;
		typedef IfcRelAssignsType IfcRelAssigns;
		typedef IfcRelAssignsToActorType IfcRelAssignsToActor;
		typedef IfcRelAssignsToControlType IfcRelAssignsToControl;
		typedef IfcRelAssignsToGroupType IfcRelAssignsToGroup;
		typedef IfcRelAssignsToGroupByFactorType IfcRelAssignsToGroupByFactor;
		typedef IfcRelAssignsToProcessType IfcRelAssignsToProcess;
		typedef IfcRelAssignsToProductType IfcRelAssignsToProduct;
		typedef IfcRelAssignsToResourceType IfcRelAssignsToResource;
		typedef IfcRelAssociatesType IfcRelAssociates;
		typedef IfcRelAssociatesApprovalType IfcRelAssociatesApproval;
		typedef IfcRelAssociatesClassificationType IfcRelAssociatesClassification;
		typedef IfcRelAssociatesConstraintType IfcRelAssociatesConstraint;
		typedef IfcRelAssociatesDocumentType IfcRelAssociatesDocument;
		typedef IfcRelAssociatesLibraryType IfcRelAssociatesLibrary;
		typedef IfcRelAssociatesMaterialType IfcRelAssociatesMaterial;
		typedef IfcRelationshipType IfcRelationship;
		typedef IfcRelConnectsType IfcRelConnects;
		typedef IfcRelConnectsElementsType IfcRelConnectsElements;
		typedef IfcRelConnectsPathElementsType IfcRelConnectsPathElements;
		typedef IfcRelConnectsPortsType IfcRelConnectsPorts;
		typedef IfcRelConnectsPortToElementType IfcRelConnectsPortToElement;
		typedef IfcRelConnectsStructuralActivityType IfcRelConnectsStructuralActivity;
		typedef IfcRelConnectsStructuralMemberType IfcRelConnectsStructuralMember;
		typedef IfcRelConnectsWithEccentricityType IfcRelConnectsWithEccentricity;
		typedef IfcRelConnectsWithRealizingElementsType IfcRelConnectsWithRealizingElements;
		typedef IfcRelContainedInSpatialStructureType IfcRelContainedInSpatialStructure;
		typedef IfcRelCoversBldgElementsType IfcRelCoversBldgElements;
		typedef IfcRelCoversSpacesType IfcRelCoversSpaces;
		typedef IfcRelDeclaresType IfcRelDeclares;
		typedef IfcRelDecomposesType IfcRelDecomposes;
		typedef IfcRelDefinesType IfcRelDefines;
		typedef IfcRelDefinesByObjectType IfcRelDefinesByObject;
		typedef IfcRelDefinesByPropertiesType IfcRelDefinesByProperties;
		typedef IfcRelDefinesByTemplateType IfcRelDefinesByTemplate;
		typedef IfcRelDefinesByTypeType IfcRelDefinesByType;
		typedef IfcRelFillsElementType IfcRelFillsElement;
		typedef IfcRelFlowControlElementsType IfcRelFlowControlElements;
		typedef IfcRelInterferesElementsType IfcRelInterferesElements;
		typedef IfcRelNestsType IfcRelNests;
		typedef IfcRelProjectsElementType IfcRelProjectsElement;
		typedef IfcRelReferencedInSpatialStructureType IfcRelReferencedInSpatialStructure;
		typedef IfcRelSequenceType IfcRelSequence;
		typedef IfcRelServicesBuildingsType IfcRelServicesBuildings;
		typedef IfcRelSpaceBoundaryType IfcRelSpaceBoundary;
		typedef IfcRelSpaceBoundary1stLevelType IfcRelSpaceBoundary1stLevel;
		typedef IfcRelSpaceBoundary2ndLevelType IfcRelSpaceBoundary2ndLevel;
		typedef IfcRelVoidsElementType IfcRelVoidsElement;
		typedef IfcReparametrisedCompositeCurveSegmentType IfcReparametrisedCompositeCurveSegment;
		typedef IfcRepresentationType IfcRepresentation;
		typedef IfcRepresentationContextType IfcRepresentationContext;
		typedef IfcRepresentationItemType IfcRepresentationItem;
		typedef IfcRepresentationMapType IfcRepresentationMap;
		typedef IfcResourceType IfcResource;
		typedef IfcResourceApprovalRelationshipType IfcResourceApprovalRelationship;
		typedef IfcResourceConstraintRelationshipType IfcResourceConstraintRelationship;
		typedef IfcResourceConsumptionEnumType IfcResourceConsumptionEnum;
		typedef IfcResourceCostType IfcResourceCost;
		typedef IfcResourceLevelRelationshipType IfcResourceLevelRelationship;
		typedef IfcResourceObjectSelectType IfcResourceObjectSelect;
		typedef IfcResourceSelectType IfcResourceSelect;
		typedef IfcResourceTimeType IfcResourceTime;
		typedef IfcRevolvedAreaSolidType IfcRevolvedAreaSolid;
		typedef IfcRevolvedAreaSolidTaperedType IfcRevolvedAreaSolidTapered;
		typedef IfcRightCircularConeType IfcRightCircularCone;
		typedef IfcRightCircularCylinderType IfcRightCircularCylinder;
		typedef IfcRoleEnumType IfcRoleEnum;
		typedef IfcRoofType IfcRoof;
		typedef IfcRoofTypeType IfcRoofTType;
		typedef IfcRoofTypeEnumType IfcRoofTypeEnum;
		typedef IfcRootType IfcRoot;
		typedef IfcRotationalFrequencyMeasureType IfcRotationalFrequencyMeasure;
		typedef IfcRotationalMassMeasureType IfcRotationalMassMeasure;
		typedef IfcRotationalStiffnessMeasureType IfcRotationalStiffnessMeasure;
		typedef IfcRotationalStiffnessSelectType IfcRotationalStiffnessSelect;
		typedef IfcRoundedRectangleProfileDefType IfcRoundedRectangleProfileDef;
		typedef IfcSanitaryTerminalType IfcSanitaryTerminal;
		typedef IfcSanitaryTerminalTypeType IfcSanitaryTerminalTType;
		typedef IfcSanitaryTerminalTypeEnumType IfcSanitaryTerminalTypeEnum;
		typedef IfcSchedulingTimeType IfcSchedulingTime;
		typedef IfcSectionalAreaIntegralMeasureType IfcSectionalAreaIntegralMeasure;
		typedef IfcSectionedSpineType IfcSectionedSpine;
		typedef IfcSectionModulusMeasureType IfcSectionModulusMeasure;
		typedef IfcSectionPropertiesType IfcSectionProperties;
		typedef IfcSectionReinforcementPropertiesType IfcSectionReinforcementProperties;
		typedef IfcSectionTypeEnumType IfcSectionTypeEnum;
		typedef IfcSensorType IfcSensor;
		typedef IfcSensorTypeType IfcSensorTType;
		typedef IfcSensorTypeEnumType IfcSensorTypeEnum;
		typedef IfcSequenceEnumType IfcSequenceEnum;
		typedef IfcShadingDeviceType IfcShadingDevice;
		typedef IfcShadingDeviceTypeType IfcShadingDeviceTType;
		typedef IfcShadingDeviceTypeEnumType IfcShadingDeviceTypeEnum;
		typedef IfcShapeAspectType IfcShapeAspect;
		typedef IfcShapeModelType IfcShapeModel;
		typedef IfcShapeRepresentationType IfcShapeRepresentation;
		typedef IfcShearModulusMeasureType IfcShearModulusMeasure;
		typedef IfcShellType IfcShell;
		typedef IfcShellBasedSurfaceModelType IfcShellBasedSurfaceModel;
		typedef IfcSimplePropertyType IfcSimpleProperty;
		typedef IfcSimplePropertyTemplateType IfcSimplePropertyTemplate;
		typedef IfcSimplePropertyTemplateTypeEnumType IfcSimplePropertyTemplateTypeEnum;
		typedef IfcSimpleValueType IfcSimpleValue;
		typedef IfcSIPrefixType IfcSIPrefix;
		typedef IfcSiteType IfcSite;
		typedef IfcSIUnitType IfcSIUnit;
		typedef IfcSIUnitNameType IfcSIUnitName;
		typedef IfcSizeSelectType IfcSizeSelect;
		typedef IfcSlabType IfcSlab;
		typedef IfcSlabElementedCaseType IfcSlabElementedCase;
		typedef IfcSlabStandardCaseType IfcSlabStandardCase;
		typedef IfcSlabTypeType IfcSlabTType;
		typedef IfcSlabTypeEnumType IfcSlabTypeEnum;
		typedef IfcSlippageConnectionConditionType IfcSlippageConnectionCondition;
		typedef IfcSolarDeviceType IfcSolarDevice;
		typedef IfcSolarDeviceTypeType IfcSolarDeviceTType;
		typedef IfcSolarDeviceTypeEnumType IfcSolarDeviceTypeEnum;
		typedef IfcSolidAngleMeasureType IfcSolidAngleMeasure;
		typedef IfcSolidModelType IfcSolidModel;
		typedef IfcSolidOrShellType IfcSolidOrShell;
		typedef IfcSoundPowerMeasureType IfcSoundPowerMeasure;
		typedef IfcSoundPressureMeasureType IfcSoundPressureMeasure;
		typedef IfcSpaceType IfcSpace;
		typedef IfcSpaceBoundarySelectType IfcSpaceBoundarySelect;
		typedef IfcSpaceHeaterType IfcSpaceHeater;
		typedef IfcSpaceHeaterTypeType IfcSpaceHeaterTType;
		typedef IfcSpaceHeaterTypeEnumType IfcSpaceHeaterTypeEnum;
		typedef IfcSpaceTypeType IfcSpaceTType;
		typedef IfcSpaceTypeEnumType IfcSpaceTypeEnum;
		typedef IfcSpatialElementType IfcSpatialElement;
		typedef IfcSpatialElementTypeType IfcSpatialElementTType;
		typedef IfcSpatialStructureElementType IfcSpatialStructureElement;
		typedef IfcSpatialStructureElementTypeType IfcSpatialStructureElementTType;
		typedef IfcSpatialZoneType IfcSpatialZone;
		typedef IfcSpatialZoneTypeType IfcSpatialZoneTType;
		typedef IfcSpatialZoneTypeEnumType IfcSpatialZoneTypeEnum;
		typedef IfcSpecificHeatCapacityMeasureType IfcSpecificHeatCapacityMeasure;
		typedef IfcSpecularExponentType IfcSpecularExponent;
		typedef IfcSpecularHighlightSelectType IfcSpecularHighlightSelect;
		typedef IfcSpecularRoughnessType IfcSpecularRoughness;
		typedef IfcSphereType IfcSphere;
		typedef IfcStackTerminalType IfcStackTerminal;
		typedef IfcStackTerminalTypeType IfcStackTerminalTType;
		typedef IfcStackTerminalTypeEnumType IfcStackTerminalTypeEnum;
		typedef IfcStairType IfcStair;
		typedef IfcStairFlightType IfcStairFlight;
		typedef IfcStairFlightTypeType IfcStairFlightTType;
		typedef IfcStairFlightTypeEnumType IfcStairFlightTypeEnum;
		typedef IfcStairTypeType IfcStairTType;
		typedef IfcStairTypeEnumType IfcStairTypeEnum;
		typedef IfcStateEnumType IfcStateEnum;
		typedef IfcStructuralActionType IfcStructuralAction;
		typedef IfcStructuralActivityType IfcStructuralActivity;
		typedef IfcStructuralActivityAssignmentSelectType IfcStructuralActivityAssignmentSelect;
		typedef IfcStructuralAnalysisModelType IfcStructuralAnalysisModel;
		typedef IfcStructuralConnectionType IfcStructuralConnection;
		typedef IfcStructuralConnectionConditionType IfcStructuralConnectionCondition;
		typedef IfcStructuralCurveActionType IfcStructuralCurveAction;
		typedef IfcStructuralCurveActivityTypeEnumType IfcStructuralCurveActivityTypeEnum;
		typedef IfcStructuralCurveConnectionType IfcStructuralCurveConnection;
		typedef IfcStructuralCurveMemberType IfcStructuralCurveMember;
		typedef IfcStructuralCurveMemberTypeEnumType IfcStructuralCurveMemberTypeEnum;
		typedef IfcStructuralCurveMemberVaryingType IfcStructuralCurveMemberVarying;
		typedef IfcStructuralCurveReactionType IfcStructuralCurveReaction;
		typedef IfcStructuralItemType IfcStructuralItem;
		typedef IfcStructuralLinearActionType IfcStructuralLinearAction;
		typedef IfcStructuralLoadType IfcStructuralLoad;
		typedef IfcStructuralLoadCaseType IfcStructuralLoadCase;
		typedef IfcStructuralLoadConfigurationType IfcStructuralLoadConfiguration;
		typedef IfcStructuralLoadGroupType IfcStructuralLoadGroup;
		typedef IfcStructuralLoadLinearForceType IfcStructuralLoadLinearForce;
		typedef IfcStructuralLoadOrResultType IfcStructuralLoadOrResult;
		typedef IfcStructuralLoadPlanarForceType IfcStructuralLoadPlanarForce;
		typedef IfcStructuralLoadSingleDisplacementType IfcStructuralLoadSingleDisplacement;
		typedef IfcStructuralLoadSingleDisplacementDistortionType IfcStructuralLoadSingleDisplacementDistortion;
		typedef IfcStructuralLoadSingleForceType IfcStructuralLoadSingleForce;
		typedef IfcStructuralLoadSingleForceWarpingType IfcStructuralLoadSingleForceWarping;
		typedef IfcStructuralLoadStaticType IfcStructuralLoadStatic;
		typedef IfcStructuralLoadTemperatureType IfcStructuralLoadTemperature;
		typedef IfcStructuralMemberType IfcStructuralMember;
		typedef IfcStructuralPlanarActionType IfcStructuralPlanarAction;
		typedef IfcStructuralPointActionType IfcStructuralPointAction;
		typedef IfcStructuralPointConnectionType IfcStructuralPointConnection;
		typedef IfcStructuralPointReactionType IfcStructuralPointReaction;
		typedef IfcStructuralReactionType IfcStructuralReaction;
		typedef IfcStructuralResultGroupType IfcStructuralResultGroup;
		typedef IfcStructuralSurfaceActionType IfcStructuralSurfaceAction;
		typedef IfcStructuralSurfaceActivityTypeEnumType IfcStructuralSurfaceActivityTypeEnum;
		typedef IfcStructuralSurfaceConnectionType IfcStructuralSurfaceConnection;
		typedef IfcStructuralSurfaceMemberType IfcStructuralSurfaceMember;
		typedef IfcStructuralSurfaceMemberTypeEnumType IfcStructuralSurfaceMemberTypeEnum;
		typedef IfcStructuralSurfaceMemberVaryingType IfcStructuralSurfaceMemberVarying;
		typedef IfcStructuralSurfaceReactionType IfcStructuralSurfaceReaction;
		typedef IfcStyleAssignmentSelectType IfcStyleAssignmentSelect;
		typedef IfcStyledItemType IfcStyledItem;
		typedef IfcStyledRepresentationType IfcStyledRepresentation;
		typedef IfcStyleModelType IfcStyleModel;
		typedef IfcSubContractResourceType IfcSubContractResource;
		typedef IfcSubContractResourceTypeType IfcSubContractResourceTType;
		typedef IfcSubContractResourceTypeEnumType IfcSubContractResourceTypeEnum;
		typedef IfcSubedgeType IfcSubedge;
		typedef IfcSurfaceType IfcSurface;
		typedef IfcSurfaceCurveSweptAreaSolidType IfcSurfaceCurveSweptAreaSolid;
		typedef IfcSurfaceFeatureType IfcSurfaceFeature;
		typedef IfcSurfaceFeatureTypeEnumType IfcSurfaceFeatureTypeEnum;
		typedef IfcSurfaceOfLinearExtrusionType IfcSurfaceOfLinearExtrusion;
		typedef IfcSurfaceOfRevolutionType IfcSurfaceOfRevolution;
		typedef IfcSurfaceOrFaceSurfaceType IfcSurfaceOrFaceSurface;
		typedef IfcSurfaceReinforcementAreaType IfcSurfaceReinforcementArea;
		typedef IfcSurfaceSideType IfcSurfaceSide;
		typedef IfcSurfaceStyleType IfcSurfaceStyle;
		typedef IfcSurfaceStyleElementSelectType IfcSurfaceStyleElementSelect;
		typedef IfcSurfaceStyleLightingType IfcSurfaceStyleLighting;
		typedef IfcSurfaceStyleRefractionType IfcSurfaceStyleRefraction;
		typedef IfcSurfaceStyleRenderingType IfcSurfaceStyleRendering;
		typedef IfcSurfaceStyleShadingType IfcSurfaceStyleShading;
		typedef IfcSurfaceStyleWithTexturesType IfcSurfaceStyleWithTextures;
		typedef IfcSurfaceTextureType IfcSurfaceTexture;
		typedef IfcSweptAreaSolidType IfcSweptAreaSolid;
		typedef IfcSweptDiskSolidType IfcSweptDiskSolid;
		typedef IfcSweptDiskSolidPolygonalType IfcSweptDiskSolidPolygonal;
		typedef IfcSweptSurfaceType IfcSweptSurface;
		typedef IfcSwitchingDeviceType IfcSwitchingDevice;
		typedef IfcSwitchingDeviceTypeType IfcSwitchingDeviceTType;
		typedef IfcSwitchingDeviceTypeEnumType IfcSwitchingDeviceTypeEnum;
		typedef IfcSymbolStyleType IfcSymbolStyle;
		typedef IfcSymbolStyleSelectType IfcSymbolStyleSelect;
		typedef IfcSystemType IfcSystem;
		typedef IfcSystemFurnitureElementType IfcSystemFurnitureElement;
		typedef IfcSystemFurnitureElementTypeType IfcSystemFurnitureElementTType;
		typedef IfcSystemFurnitureElementTypeEnumType IfcSystemFurnitureElementTypeEnum;
		typedef IfcTableType IfcTable;
		typedef IfcTableColumnType IfcTableColumn;
		typedef IfcTableRowType IfcTableRow;
		typedef IfcTankType IfcTank;
		typedef IfcTankTypeType IfcTankTType;
		typedef IfcTankTypeEnumType IfcTankTypeEnum;
		typedef IfcTaskType IfcTask;
		typedef IfcTaskDurationEnumType IfcTaskDurationEnum;
		typedef IfcTaskTimeType IfcTaskTime;
		typedef IfcTaskTimeRecurringType IfcTaskTimeRecurring;
		typedef IfcTaskTypeType IfcTaskTType;
		typedef IfcTaskTypeEnumType IfcTaskTypeEnum;
		typedef IfcTelecomAddressType IfcTelecomAddress;
		typedef IfcTemperatureGradientMeasureType IfcTemperatureGradientMeasure;
		typedef IfcTemperatureRateOfChangeMeasureType IfcTemperatureRateOfChangeMeasure;
		typedef IfcTendonType IfcTendon;
		typedef IfcTendonAnchorType IfcTendonAnchor;
		typedef IfcTendonAnchorTypeType IfcTendonAnchorTType;
		typedef IfcTendonAnchorTypeEnumType IfcTendonAnchorTypeEnum;
		typedef IfcTendonTypeType IfcTendonTType;
		typedef IfcTendonTypeEnumType IfcTendonTypeEnum;
		typedef IfcTessellatedFaceSetType IfcTessellatedFaceSet;
		typedef IfcTessellatedItemType IfcTessellatedItem;
		typedef IfcTextType IfcText;
		typedef IfcTextAlignmentType IfcTextAlignment;
		typedef IfcTextDecorationType IfcTextDecoration;
		typedef IfcTextFontNameType IfcTextFontName;
		typedef IfcTextFontSelectType IfcTextFontSelect;
		typedef IfcTextLiteralType IfcTextLiteral;
		typedef IfcTextLiteralWithExtentType IfcTextLiteralWithExtent;
		typedef IfcTextPathType IfcTextPath;
		typedef IfcTextStyleType IfcTextStyle;
		typedef IfcTextStyleFontModelType IfcTextStyleFontModel;
		typedef IfcTextStyleForDefinedFontType IfcTextStyleForDefinedFont;
		typedef IfcTextStyleSelectType IfcTextStyleSelect;
		typedef IfcTextStyleTextModelType IfcTextStyleTextModel;
		typedef IfcTextStyleWithBoxCharacteristicsType IfcTextStyleWithBoxCharacteristics;
		typedef IfcTextTransformationType IfcTextTransformation;
		typedef IfcTextureCoordinateType IfcTextureCoordinate;
		typedef IfcTextureCoordinateGeneratorType IfcTextureCoordinateGenerator;
		typedef IfcTextureMapType IfcTextureMap;
		typedef IfcTextureVertexType IfcTextureVertex;
		typedef IfcTextureVertexListType IfcTextureVertexList;
		typedef IfcThermalAdmittanceMeasureType IfcThermalAdmittanceMeasure;
		typedef IfcThermalConductivityMeasureType IfcThermalConductivityMeasure;
		typedef IfcThermalExpansionCoefficientMeasureType IfcThermalExpansionCoefficientMeasure;
		typedef IfcThermalResistanceMeasureType IfcThermalResistanceMeasure;
		typedef IfcThermalTransmittanceMeasureType IfcThermalTransmittanceMeasure;
		typedef IfcThermodynamicTemperatureMeasureType IfcThermodynamicTemperatureMeasure;
		typedef IfcTimeType IfcTime;
		typedef IfcTimeMeasureType IfcTimeMeasure;
		typedef IfcTimeOrRatioSelectType IfcTimeOrRatioSelect;
		typedef IfcTimePeriodType IfcTimePeriod;
		typedef IfcTimeSeriesType IfcTimeSeries;
		typedef IfcTimeSeriesDataTypeEnumType IfcTimeSeriesDataTypeEnum;
		typedef IfcTimeSeriesValueType IfcTimeSeriesValue;
		typedef IfcTimeStampType IfcTimeStamp;
		typedef IfcTopologicalRepresentationItemType IfcTopologicalRepresentationItem;
		typedef IfcTopologyRepresentationType IfcTopologyRepresentation;
		typedef IfcTorqueMeasureType IfcTorqueMeasure;
		typedef IfcTransformerType IfcTransformer;
		typedef IfcTransformerTypeType IfcTransformerTType;
		typedef IfcTransformerTypeEnumType IfcTransformerTypeEnum;
		typedef IfcTransitionCodeType IfcTransitionCode;
		typedef IfcTranslationalStiffnessSelectType IfcTranslationalStiffnessSelect;
		typedef IfcTransportElementType IfcTransportElement;
		typedef IfcTransportElementTypeType IfcTransportElementTType;
		typedef IfcTransportElementTypeEnumType IfcTransportElementTypeEnum;
		typedef IfcTrapeziumProfileDefType IfcTrapeziumProfileDef;
		typedef IfcTriangulatedFaceSetType IfcTriangulatedFaceSet;
		typedef IfcTrimmedCurveType IfcTrimmedCurve;
		typedef IfcTrimmingPreferenceType IfcTrimmingPreference;
		typedef IfcTrimmingSelectType IfcTrimmingSelect;
		typedef IfcTShapeProfileDefType IfcTShapeProfileDef;
		typedef IfcTubeBundleType IfcTubeBundle;
		typedef IfcTubeBundleTypeType IfcTubeBundleTType;
		typedef IfcTubeBundleTypeEnumType IfcTubeBundleTypeEnum;
		typedef IfcTwoDirectionRepeatFactorType IfcTwoDirectionRepeatFactor;
		typedef IfcTypeObjectType IfcTypeObject;
		typedef IfcTypeProcessType IfcTypeProcess;
		typedef IfcTypeProductType IfcTypeProduct;
		typedef IfcTypeResourceType IfcTypeResource;
		typedef IfcUnitType IfcUnit;
		typedef IfcUnitaryControlElementType IfcUnitaryControlElement;
		typedef IfcUnitaryControlElementTypeType IfcUnitaryControlElementTType;
		typedef IfcUnitaryControlElementTypeEnumType IfcUnitaryControlElementTypeEnum;
		typedef IfcUnitaryEquipmentType IfcUnitaryEquipment;
		typedef IfcUnitaryEquipmentTypeType IfcUnitaryEquipmentTType;
		typedef IfcUnitaryEquipmentTypeEnumType IfcUnitaryEquipmentTypeEnum;
		typedef IfcUnitAssignmentType IfcUnitAssignment;
		typedef IfcUnitEnumType IfcUnitEnum;
		typedef IfcURIReferenceType IfcURIReference;
		typedef IfcUShapeProfileDefType IfcUShapeProfileDef;
		typedef IfcValueType IfcValue;
		typedef IfcValveType IfcValve;
		typedef IfcValveTypeType IfcValveTType;
		typedef IfcValveTypeEnumType IfcValveTypeEnum;
		typedef IfcVaporPermeabilityMeasureType IfcVaporPermeabilityMeasure;
		typedef IfcVectorType IfcVector;
		typedef IfcVectorOrDirectionType IfcVectorOrDirection;
		typedef IfcVertexType IfcVertex;
		typedef IfcVertexLoopType IfcVertexLoop;
		typedef IfcVertexPointType IfcVertexPoint;
		typedef IfcVibrationIsolatorType IfcVibrationIsolator;
		typedef IfcVibrationIsolatorTypeType IfcVibrationIsolatorTType;
		typedef IfcVibrationIsolatorTypeEnumType IfcVibrationIsolatorTypeEnum;
		typedef IfcVirtualElementType IfcVirtualElement;
		typedef IfcVirtualGridIntersectionType IfcVirtualGridIntersection;
		typedef IfcVoidingFeatureType IfcVoidingFeature;
		typedef IfcVoidingFeatureTypeEnumType IfcVoidingFeatureTypeEnum;
		typedef IfcVolumeMeasureType IfcVolumeMeasure;
		typedef IfcVolumetricFlowRateMeasureType IfcVolumetricFlowRateMeasure;
		typedef IfcWallType IfcWall;
		typedef IfcWallElementedCaseType IfcWallElementedCase;
		typedef IfcWallStandardCaseType IfcWallStandardCase;
		typedef IfcWallTypeType IfcWallTType;
		typedef IfcWallTypeEnumType IfcWallTypeEnum;
		typedef IfcWarpingConstantMeasureType IfcWarpingConstantMeasure;
		typedef IfcWarpingMomentMeasureType IfcWarpingMomentMeasure;
		typedef IfcWarpingStiffnessSelectType IfcWarpingStiffnessSelect;
		typedef IfcWasteTerminalType IfcWasteTerminal;
		typedef IfcWasteTerminalTypeType IfcWasteTerminalTType;
		typedef IfcWasteTerminalTypeEnumType IfcWasteTerminalTypeEnum;
		typedef IfcWindowType IfcWindow;
		typedef IfcWindowLiningPropertiesType IfcWindowLiningProperties;
		typedef IfcWindowPanelOperationEnumType IfcWindowPanelOperationEnum;
		typedef IfcWindowPanelPositionEnumType IfcWindowPanelPositionEnum;
		typedef IfcWindowPanelPropertiesType IfcWindowPanelProperties;
		typedef IfcWindowStandardCaseType IfcWindowStandardCase;
		typedef IfcWindowStyleType IfcWindowStyle;
		typedef IfcWindowStyleConstructionEnumType IfcWindowStyleConstructionEnum;
		typedef IfcWindowStyleOperationEnumType IfcWindowStyleOperationEnum;
		typedef IfcWindowTypeType IfcWindowTType;
		typedef IfcWindowTypeEnumType IfcWindowTypeEnum;
		typedef IfcWindowTypePartitioningEnumType IfcWindowTypePartitioningEnum;
		typedef IfcWorkCalendarType IfcWorkCalendar;
		typedef IfcWorkCalendarTypeEnumType IfcWorkCalendarTypeEnum;
		typedef IfcWorkControlType IfcWorkControl;
		typedef IfcWorkPlanType IfcWorkPlan;
		typedef IfcWorkPlanTypeEnumType IfcWorkPlanTypeEnum;
		typedef IfcWorkScheduleType IfcWorkSchedule;
		typedef IfcWorkScheduleTypeEnumType IfcWorkScheduleTypeEnum;
		typedef IfcWorkTimeType IfcWorkTime;
		typedef IfcZoneType IfcZone;
		typedef IfcZShapeProfileDefType IfcZShapeProfileDef;
	};
}
