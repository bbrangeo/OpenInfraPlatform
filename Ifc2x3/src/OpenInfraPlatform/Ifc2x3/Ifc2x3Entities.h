/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include "entity//include/Ifc2DCompositeCurve.h"
#include "entity//include/IfcActionRequest.h"
#include "entity//include/IfcActor.h"
#include "entity//include/IfcActorRole.h"
#include "entity//include/IfcActuatorType.h"
#include "entity//include/IfcAddress.h"
#include "entity//include/IfcAirTerminalBoxType.h"
#include "entity//include/IfcAirTerminalType.h"
#include "entity//include/IfcAirToAirHeatRecoveryType.h"
#include "entity//include/IfcAlarmType.h"
#include "entity//include/IfcAngularDimension.h"
#include "entity//include/IfcAnnotation.h"
#include "entity//include/IfcAnnotationCurveOccurrence.h"
#include "entity//include/IfcAnnotationFillArea.h"
#include "entity//include/IfcAnnotationFillAreaOccurrence.h"
#include "entity//include/IfcAnnotationOccurrence.h"
#include "entity//include/IfcAnnotationSurface.h"
#include "entity//include/IfcAnnotationSurfaceOccurrence.h"
#include "entity//include/IfcAnnotationSymbolOccurrence.h"
#include "entity//include/IfcAnnotationTextOccurrence.h"
#include "entity//include/IfcApplication.h"
#include "entity//include/IfcAppliedValue.h"
#include "entity//include/IfcAppliedValueRelationship.h"
#include "entity//include/IfcApproval.h"
#include "entity//include/IfcApprovalActorRelationship.h"
#include "entity//include/IfcApprovalPropertyRelationship.h"
#include "entity//include/IfcApprovalRelationship.h"
#include "entity//include/IfcArbitraryClosedProfileDef.h"
#include "entity//include/IfcArbitraryOpenProfileDef.h"
#include "entity//include/IfcArbitraryProfileDefWithVoids.h"
#include "entity//include/IfcAsset.h"
#include "entity//include/IfcAsymmetricIShapeProfileDef.h"
#include "entity//include/IfcAxis1Placement.h"
#include "entity//include/IfcAxis2Placement2D.h"
#include "entity//include/IfcAxis2Placement3D.h"
#include "entity//include/IfcBSplineCurve.h"
#include "entity//include/IfcBeam.h"
#include "entity//include/IfcBeamType.h"
#include "entity//include/IfcBezierCurve.h"
#include "entity//include/IfcBlobTexture.h"
#include "entity//include/IfcBlock.h"
#include "entity//include/IfcBoilerType.h"
#include "entity//include/IfcBooleanClippingResult.h"
#include "entity//include/IfcBooleanResult.h"
#include "entity//include/IfcBoundaryCondition.h"
#include "entity//include/IfcBoundaryEdgeCondition.h"
#include "entity//include/IfcBoundaryFaceCondition.h"
#include "entity//include/IfcBoundaryNodeCondition.h"
#include "entity//include/IfcBoundaryNodeConditionWarping.h"
#include "entity//include/IfcBoundedCurve.h"
#include "entity//include/IfcBoundedSurface.h"
#include "entity//include/IfcBoundingBox.h"
#include "entity//include/IfcBoxedHalfSpace.h"
#include "entity//include/IfcBuilding.h"
#include "entity//include/IfcBuildingElement.h"
#include "entity//include/IfcBuildingElementComponent.h"
#include "entity//include/IfcBuildingElementPart.h"
#include "entity//include/IfcBuildingElementProxy.h"
#include "entity//include/IfcBuildingElementProxyType.h"
#include "entity//include/IfcBuildingElementType.h"
#include "entity//include/IfcBuildingStorey.h"
#include "entity//include/IfcCShapeProfileDef.h"
#include "entity//include/IfcCableCarrierFittingType.h"
#include "entity//include/IfcCableCarrierSegmentType.h"
#include "entity//include/IfcCableSegmentType.h"
#include "entity//include/IfcCalendarDate.h"
#include "entity//include/IfcCartesianPoint.h"
#include "entity//include/IfcCartesianTransformationOperator.h"
#include "entity//include/IfcCartesianTransformationOperator2D.h"
#include "entity//include/IfcCartesianTransformationOperator2DnonUniform.h"
#include "entity//include/IfcCartesianTransformationOperator3D.h"
#include "entity//include/IfcCartesianTransformationOperator3DnonUniform.h"
#include "entity//include/IfcCenterLineProfileDef.h"
#include "entity//include/IfcChamferEdgeFeature.h"
#include "entity//include/IfcChillerType.h"
#include "entity//include/IfcCircle.h"
#include "entity//include/IfcCircleHollowProfileDef.h"
#include "entity//include/IfcCircleProfileDef.h"
#include "entity//include/IfcClassification.h"
#include "entity//include/IfcClassificationItem.h"
#include "entity//include/IfcClassificationItemRelationship.h"
#include "entity//include/IfcClassificationNotation.h"
#include "entity//include/IfcClassificationNotationFacet.h"
#include "entity//include/IfcClassificationReference.h"
#include "entity//include/IfcClosedShell.h"
#include "entity//include/IfcCoilType.h"
#include "entity//include/IfcColourRgb.h"
#include "entity//include/IfcColourSpecification.h"
#include "entity//include/IfcColumn.h"
#include "entity//include/IfcColumnType.h"
#include "entity//include/IfcComplexProperty.h"
#include "entity//include/IfcCompositeCurve.h"
#include "entity//include/IfcCompositeCurveSegment.h"
#include "entity//include/IfcCompositeProfileDef.h"
#include "entity//include/IfcCompressorType.h"
#include "entity//include/IfcCondenserType.h"
#include "entity//include/IfcCondition.h"
#include "entity//include/IfcConditionCriterion.h"
#include "entity//include/IfcConic.h"
#include "entity//include/IfcConnectedFaceSet.h"
#include "entity//include/IfcConnectionCurveGeometry.h"
#include "entity//include/IfcConnectionGeometry.h"
#include "entity//include/IfcConnectionPointEccentricity.h"
#include "entity//include/IfcConnectionPointGeometry.h"
#include "entity//include/IfcConnectionPortGeometry.h"
#include "entity//include/IfcConnectionSurfaceGeometry.h"
#include "entity//include/IfcConstraint.h"
#include "entity//include/IfcConstraintAggregationRelationship.h"
#include "entity//include/IfcConstraintClassificationRelationship.h"
#include "entity//include/IfcConstraintRelationship.h"
#include "entity//include/IfcConstructionEquipmentResource.h"
#include "entity//include/IfcConstructionMaterialResource.h"
#include "entity//include/IfcConstructionProductResource.h"
#include "entity//include/IfcConstructionResource.h"
#include "entity//include/IfcContextDependentUnit.h"
#include "entity//include/IfcControl.h"
#include "entity//include/IfcControllerType.h"
#include "entity//include/IfcConversionBasedUnit.h"
#include "entity//include/IfcCooledBeamType.h"
#include "entity//include/IfcCoolingTowerType.h"
#include "entity//include/IfcCoordinatedUniversalTimeOffset.h"
#include "entity//include/IfcCostItem.h"
#include "entity//include/IfcCostSchedule.h"
#include "entity//include/IfcCostValue.h"
#include "entity//include/IfcCovering.h"
#include "entity//include/IfcCoveringType.h"
#include "entity//include/IfcCraneRailAShapeProfileDef.h"
#include "entity//include/IfcCraneRailFShapeProfileDef.h"
#include "entity//include/IfcCrewResource.h"
#include "entity//include/IfcCsgPrimitive3D.h"
#include "entity//include/IfcCsgSolid.h"
#include "entity//include/IfcCurrencyRelationship.h"
#include "entity//include/IfcCurtainWall.h"
#include "entity//include/IfcCurtainWallType.h"
#include "entity//include/IfcCurve.h"
#include "entity//include/IfcCurveBoundedPlane.h"
#include "entity//include/IfcCurveStyle.h"
#include "entity//include/IfcCurveStyleFont.h"
#include "entity//include/IfcCurveStyleFontAndScaling.h"
#include "entity//include/IfcCurveStyleFontPattern.h"
#include "entity//include/IfcDamperType.h"
#include "entity//include/IfcDateAndTime.h"
#include "entity//include/IfcDefinedSymbol.h"
#include "entity//include/IfcDerivedProfileDef.h"
#include "entity//include/IfcDerivedUnit.h"
#include "entity//include/IfcDerivedUnitElement.h"
#include "entity//include/IfcDiameterDimension.h"
#include "entity//include/IfcDimensionCalloutRelationship.h"
#include "entity//include/IfcDimensionCurve.h"
#include "entity//include/IfcDimensionCurveDirectedCallout.h"
#include "entity//include/IfcDimensionCurveTerminator.h"
#include "entity//include/IfcDimensionPair.h"
#include "entity//include/IfcDimensionalExponents.h"
#include "entity//include/IfcDirection.h"
#include "entity//include/IfcDiscreteAccessory.h"
#include "entity//include/IfcDiscreteAccessoryType.h"
#include "entity//include/IfcDistributionChamberElement.h"
#include "entity//include/IfcDistributionChamberElementType.h"
#include "entity//include/IfcDistributionControlElement.h"
#include "entity//include/IfcDistributionControlElementType.h"
#include "entity//include/IfcDistributionElement.h"
#include "entity//include/IfcDistributionElementType.h"
#include "entity//include/IfcDistributionFlowElement.h"
#include "entity//include/IfcDistributionFlowElementType.h"
#include "entity//include/IfcDistributionPort.h"
#include "entity//include/IfcDocumentElectronicFormat.h"
#include "entity//include/IfcDocumentInformation.h"
#include "entity//include/IfcDocumentInformationRelationship.h"
#include "entity//include/IfcDocumentReference.h"
#include "entity//include/IfcDoor.h"
#include "entity//include/IfcDoorLiningProperties.h"
#include "entity//include/IfcDoorPanelProperties.h"
#include "entity//include/IfcDoorStyle.h"
#include "entity//include/IfcDraughtingCallout.h"
#include "entity//include/IfcDraughtingCalloutRelationship.h"
#include "entity//include/IfcDraughtingPreDefinedColour.h"
#include "entity//include/IfcDraughtingPreDefinedCurveFont.h"
#include "entity//include/IfcDraughtingPreDefinedTextFont.h"
#include "entity//include/IfcDuctFittingType.h"
#include "entity//include/IfcDuctSegmentType.h"
#include "entity//include/IfcDuctSilencerType.h"
#include "entity//include/IfcEdge.h"
#include "entity//include/IfcEdgeCurve.h"
#include "entity//include/IfcEdgeFeature.h"
#include "entity//include/IfcEdgeLoop.h"
#include "entity//include/IfcElectricApplianceType.h"
#include "entity//include/IfcElectricDistributionPoint.h"
#include "entity//include/IfcElectricFlowStorageDeviceType.h"
#include "entity//include/IfcElectricGeneratorType.h"
#include "entity//include/IfcElectricHeaterType.h"
#include "entity//include/IfcElectricMotorType.h"
#include "entity//include/IfcElectricTimeControlType.h"
#include "entity//include/IfcElectricalBaseProperties.h"
#include "entity//include/IfcElectricalCircuit.h"
#include "entity//include/IfcElectricalElement.h"
#include "entity//include/IfcElement.h"
#include "entity//include/IfcElementAssembly.h"
#include "entity//include/IfcElementComponent.h"
#include "entity//include/IfcElementComponentType.h"
#include "entity//include/IfcElementQuantity.h"
#include "entity//include/IfcElementType.h"
#include "entity//include/IfcElementarySurface.h"
#include "entity//include/IfcEllipse.h"
#include "entity//include/IfcEllipseProfileDef.h"
#include "entity//include/IfcEnergyConversionDevice.h"
#include "entity//include/IfcEnergyConversionDeviceType.h"
#include "entity//include/IfcEnergyProperties.h"
#include "entity//include/IfcEnvironmentalImpactValue.h"
#include "entity//include/IfcEquipmentElement.h"
#include "entity//include/IfcEquipmentStandard.h"
#include "entity//include/IfcEvaporativeCoolerType.h"
#include "entity//include/IfcEvaporatorType.h"
#include "entity//include/IfcExtendedMaterialProperties.h"
#include "entity//include/IfcExternalReference.h"
#include "entity//include/IfcExternallyDefinedHatchStyle.h"
#include "entity//include/IfcExternallyDefinedSurfaceStyle.h"
#include "entity//include/IfcExternallyDefinedSymbol.h"
#include "entity//include/IfcExternallyDefinedTextFont.h"
#include "entity//include/IfcExtrudedAreaSolid.h"
#include "entity//include/IfcFace.h"
#include "entity//include/IfcFaceBasedSurfaceModel.h"
#include "entity//include/IfcFaceBound.h"
#include "entity//include/IfcFaceOuterBound.h"
#include "entity//include/IfcFaceSurface.h"
#include "entity//include/IfcFacetedBrep.h"
#include "entity//include/IfcFacetedBrepWithVoids.h"
#include "entity//include/IfcFailureConnectionCondition.h"
#include "entity//include/IfcFanType.h"
#include "entity//include/IfcFastener.h"
#include "entity//include/IfcFastenerType.h"
#include "entity//include/IfcFeatureElement.h"
#include "entity//include/IfcFeatureElementAddition.h"
#include "entity//include/IfcFeatureElementSubtraction.h"
#include "entity//include/IfcFillAreaStyle.h"
#include "entity//include/IfcFillAreaStyleHatching.h"
#include "entity//include/IfcFillAreaStyleTileSymbolWithStyle.h"
#include "entity//include/IfcFillAreaStyleTiles.h"
#include "entity//include/IfcFilterType.h"
#include "entity//include/IfcFireSuppressionTerminalType.h"
#include "entity//include/IfcFlowController.h"
#include "entity//include/IfcFlowControllerType.h"
#include "entity//include/IfcFlowFitting.h"
#include "entity//include/IfcFlowFittingType.h"
#include "entity//include/IfcFlowInstrumentType.h"
#include "entity//include/IfcFlowMeterType.h"
#include "entity//include/IfcFlowMovingDevice.h"
#include "entity//include/IfcFlowMovingDeviceType.h"
#include "entity//include/IfcFlowSegment.h"
#include "entity//include/IfcFlowSegmentType.h"
#include "entity//include/IfcFlowStorageDevice.h"
#include "entity//include/IfcFlowStorageDeviceType.h"
#include "entity//include/IfcFlowTerminal.h"
#include "entity//include/IfcFlowTerminalType.h"
#include "entity//include/IfcFlowTreatmentDevice.h"
#include "entity//include/IfcFlowTreatmentDeviceType.h"
#include "entity//include/IfcFluidFlowProperties.h"
#include "entity//include/IfcFooting.h"
#include "entity//include/IfcFuelProperties.h"
#include "entity//include/IfcFurnishingElement.h"
#include "entity//include/IfcFurnishingElementType.h"
#include "entity//include/IfcFurnitureStandard.h"
#include "entity//include/IfcFurnitureType.h"
#include "entity//include/IfcGasTerminalType.h"
#include "entity//include/IfcGeneralMaterialProperties.h"
#include "entity//include/IfcGeneralProfileProperties.h"
#include "entity//include/IfcGeometricCurveSet.h"
#include "entity//include/IfcGeometricRepresentationContext.h"
#include "entity//include/IfcGeometricRepresentationItem.h"
#include "entity//include/IfcGeometricRepresentationSubContext.h"
#include "entity//include/IfcGeometricSet.h"
#include "entity//include/IfcGrid.h"
#include "entity//include/IfcGridAxis.h"
#include "entity//include/IfcGridPlacement.h"
#include "entity//include/IfcGroup.h"
#include "entity//include/IfcHalfSpaceSolid.h"
#include "entity//include/IfcHeatExchangerType.h"
#include "entity//include/IfcHumidifierType.h"
#include "entity//include/IfcHygroscopicMaterialProperties.h"
#include "entity//include/IfcIShapeProfileDef.h"
#include "entity//include/IfcImageTexture.h"
#include "entity//include/IfcInventory.h"
#include "entity//include/IfcIrregularTimeSeries.h"
#include "entity//include/IfcIrregularTimeSeriesValue.h"
#include "entity//include/IfcJunctionBoxType.h"
#include "entity//include/IfcLShapeProfileDef.h"
#include "entity//include/IfcLaborResource.h"
#include "entity//include/IfcLampType.h"
#include "entity//include/IfcLibraryInformation.h"
#include "entity//include/IfcLibraryReference.h"
#include "entity//include/IfcLightDistributionData.h"
#include "entity//include/IfcLightFixtureType.h"
#include "entity//include/IfcLightIntensityDistribution.h"
#include "entity//include/IfcLightSource.h"
#include "entity//include/IfcLightSourceAmbient.h"
#include "entity//include/IfcLightSourceDirectional.h"
#include "entity//include/IfcLightSourceGoniometric.h"
#include "entity//include/IfcLightSourcePositional.h"
#include "entity//include/IfcLightSourceSpot.h"
#include "entity//include/IfcLine.h"
#include "entity//include/IfcLinearDimension.h"
#include "entity//include/IfcLocalPlacement.h"
#include "entity//include/IfcLocalTime.h"
#include "entity//include/IfcLoop.h"
#include "entity//include/IfcManifoldSolidBrep.h"
#include "entity//include/IfcMappedItem.h"
#include "entity//include/IfcMaterial.h"
#include "entity//include/IfcMaterialClassificationRelationship.h"
#include "entity//include/IfcMaterialDefinitionRepresentation.h"
#include "entity//include/IfcMaterialLayer.h"
#include "entity//include/IfcMaterialLayerSet.h"
#include "entity//include/IfcMaterialLayerSetUsage.h"
#include "entity//include/IfcMaterialList.h"
#include "entity//include/IfcMaterialProperties.h"
#include "entity//include/IfcMeasureWithUnit.h"
#include "entity//include/IfcMechanicalConcreteMaterialProperties.h"
#include "entity//include/IfcMechanicalFastener.h"
#include "entity//include/IfcMechanicalFastenerType.h"
#include "entity//include/IfcMechanicalMaterialProperties.h"
#include "entity//include/IfcMechanicalSteelMaterialProperties.h"
#include "entity//include/IfcMember.h"
#include "entity//include/IfcMemberType.h"
#include "entity//include/IfcMetric.h"
#include "entity//include/IfcMonetaryUnit.h"
#include "entity//include/IfcMotorConnectionType.h"
#include "entity//include/IfcMove.h"
#include "entity//include/IfcNamedUnit.h"
#include "entity//include/IfcObject.h"
#include "entity//include/IfcObjectDefinition.h"
#include "entity//include/IfcObjectPlacement.h"
#include "entity//include/IfcObjective.h"
#include "entity//include/IfcOccupant.h"
#include "entity//include/IfcOffsetCurve2D.h"
#include "entity//include/IfcOffsetCurve3D.h"
#include "entity//include/IfcOneDirectionRepeatFactor.h"
#include "entity//include/IfcOpenShell.h"
#include "entity//include/IfcOpeningElement.h"
#include "entity//include/IfcOpticalMaterialProperties.h"
#include "entity//include/IfcOrderAction.h"
#include "entity//include/IfcOrganization.h"
#include "entity//include/IfcOrganizationRelationship.h"
#include "entity//include/IfcOrientedEdge.h"
#include "entity//include/IfcOutletType.h"
#include "entity//include/IfcOwnerHistory.h"
#include "entity//include/IfcParameterizedProfileDef.h"
#include "entity//include/IfcPath.h"
#include "entity//include/IfcPerformanceHistory.h"
#include "entity//include/IfcPermeableCoveringProperties.h"
#include "entity//include/IfcPermit.h"
#include "entity//include/IfcPerson.h"
#include "entity//include/IfcPersonAndOrganization.h"
#include "entity//include/IfcPhysicalComplexQuantity.h"
#include "entity//include/IfcPhysicalQuantity.h"
#include "entity//include/IfcPhysicalSimpleQuantity.h"
#include "entity//include/IfcPile.h"
#include "entity//include/IfcPipeFittingType.h"
#include "entity//include/IfcPipeSegmentType.h"
#include "entity//include/IfcPixelTexture.h"
#include "entity//include/IfcPlacement.h"
#include "entity//include/IfcPlanarBox.h"
#include "entity//include/IfcPlanarExtent.h"
#include "entity//include/IfcPlane.h"
#include "entity//include/IfcPlate.h"
#include "entity//include/IfcPlateType.h"
#include "entity//include/IfcPoint.h"
#include "entity//include/IfcPointOnCurve.h"
#include "entity//include/IfcPointOnSurface.h"
#include "entity//include/IfcPolyLoop.h"
#include "entity//include/IfcPolygonalBoundedHalfSpace.h"
#include "entity//include/IfcPolyline.h"
#include "entity//include/IfcPort.h"
#include "entity//include/IfcPostalAddress.h"
#include "entity//include/IfcPreDefinedColour.h"
#include "entity//include/IfcPreDefinedCurveFont.h"
#include "entity//include/IfcPreDefinedDimensionSymbol.h"
#include "entity//include/IfcPreDefinedItem.h"
#include "entity//include/IfcPreDefinedPointMarkerSymbol.h"
#include "entity//include/IfcPreDefinedSymbol.h"
#include "entity//include/IfcPreDefinedTerminatorSymbol.h"
#include "entity//include/IfcPreDefinedTextFont.h"
#include "entity//include/IfcPresentationLayerAssignment.h"
#include "entity//include/IfcPresentationLayerWithStyle.h"
#include "entity//include/IfcPresentationStyle.h"
#include "entity//include/IfcPresentationStyleAssignment.h"
#include "entity//include/IfcProcedure.h"
#include "entity//include/IfcProcess.h"
#include "entity//include/IfcProduct.h"
#include "entity//include/IfcProductDefinitionShape.h"
#include "entity//include/IfcProductRepresentation.h"
#include "entity//include/IfcProductsOfCombustionProperties.h"
#include "entity//include/IfcProfileDef.h"
#include "entity//include/IfcProfileProperties.h"
#include "entity//include/IfcProject.h"
#include "entity//include/IfcProjectOrder.h"
#include "entity//include/IfcProjectOrderRecord.h"
#include "entity//include/IfcProjectionCurve.h"
#include "entity//include/IfcProjectionElement.h"
#include "entity//include/IfcProperty.h"
#include "entity//include/IfcPropertyBoundedValue.h"
#include "entity//include/IfcPropertyConstraintRelationship.h"
#include "entity//include/IfcPropertyDefinition.h"
#include "entity//include/IfcPropertyDependencyRelationship.h"
#include "entity//include/IfcPropertyEnumeratedValue.h"
#include "entity//include/IfcPropertyEnumeration.h"
#include "entity//include/IfcPropertyListValue.h"
#include "entity//include/IfcPropertyReferenceValue.h"
#include "entity//include/IfcPropertySet.h"
#include "entity//include/IfcPropertySetDefinition.h"
#include "entity//include/IfcPropertySingleValue.h"
#include "entity//include/IfcPropertyTableValue.h"
#include "entity//include/IfcProtectiveDeviceType.h"
#include "entity//include/IfcProxy.h"
#include "entity//include/IfcPumpType.h"
#include "entity//include/IfcQuantityArea.h"
#include "entity//include/IfcQuantityCount.h"
#include "entity//include/IfcQuantityLength.h"
#include "entity//include/IfcQuantityTime.h"
#include "entity//include/IfcQuantityVolume.h"
#include "entity//include/IfcQuantityWeight.h"
#include "entity//include/IfcRadiusDimension.h"
#include "entity//include/IfcRailing.h"
#include "entity//include/IfcRailingType.h"
#include "entity//include/IfcRamp.h"
#include "entity//include/IfcRampFlight.h"
#include "entity//include/IfcRampFlightType.h"
#include "entity//include/IfcRationalBezierCurve.h"
#include "entity//include/IfcRectangleHollowProfileDef.h"
#include "entity//include/IfcRectangleProfileDef.h"
#include "entity//include/IfcRectangularPyramid.h"
#include "entity//include/IfcRectangularTrimmedSurface.h"
#include "entity//include/IfcReferencesValueDocument.h"
#include "entity//include/IfcRegularTimeSeries.h"
#include "entity//include/IfcReinforcementBarProperties.h"
#include "entity//include/IfcReinforcementDefinitionProperties.h"
#include "entity//include/IfcReinforcingBar.h"
#include "entity//include/IfcReinforcingElement.h"
#include "entity//include/IfcReinforcingMesh.h"
#include "entity//include/IfcRelAggregates.h"
#include "entity//include/IfcRelAssigns.h"
#include "entity//include/IfcRelAssignsTasks.h"
#include "entity//include/IfcRelAssignsToActor.h"
#include "entity//include/IfcRelAssignsToControl.h"
#include "entity//include/IfcRelAssignsToGroup.h"
#include "entity//include/IfcRelAssignsToProcess.h"
#include "entity//include/IfcRelAssignsToProduct.h"
#include "entity//include/IfcRelAssignsToProjectOrder.h"
#include "entity//include/IfcRelAssignsToResource.h"
#include "entity//include/IfcRelAssociates.h"
#include "entity//include/IfcRelAssociatesAppliedValue.h"
#include "entity//include/IfcRelAssociatesApproval.h"
#include "entity//include/IfcRelAssociatesClassification.h"
#include "entity//include/IfcRelAssociatesConstraint.h"
#include "entity//include/IfcRelAssociatesDocument.h"
#include "entity//include/IfcRelAssociatesLibrary.h"
#include "entity//include/IfcRelAssociatesMaterial.h"
#include "entity//include/IfcRelAssociatesProfileProperties.h"
#include "entity//include/IfcRelConnects.h"
#include "entity//include/IfcRelConnectsElements.h"
#include "entity//include/IfcRelConnectsPathElements.h"
#include "entity//include/IfcRelConnectsPortToElement.h"
#include "entity//include/IfcRelConnectsPorts.h"
#include "entity//include/IfcRelConnectsStructuralActivity.h"
#include "entity//include/IfcRelConnectsStructuralElement.h"
#include "entity//include/IfcRelConnectsStructuralMember.h"
#include "entity//include/IfcRelConnectsWithEccentricity.h"
#include "entity//include/IfcRelConnectsWithRealizingElements.h"
#include "entity//include/IfcRelContainedInSpatialStructure.h"
#include "entity//include/IfcRelCoversBldgElements.h"
#include "entity//include/IfcRelCoversSpaces.h"
#include "entity//include/IfcRelDecomposes.h"
#include "entity//include/IfcRelDefines.h"
#include "entity//include/IfcRelDefinesByProperties.h"
#include "entity//include/IfcRelDefinesByType.h"
#include "entity//include/IfcRelFillsElement.h"
#include "entity//include/IfcRelFlowControlElements.h"
#include "entity//include/IfcRelInteractionRequirements.h"
#include "entity//include/IfcRelNests.h"
#include "entity//include/IfcRelOccupiesSpaces.h"
#include "entity//include/IfcRelOverridesProperties.h"
#include "entity//include/IfcRelProjectsElement.h"
#include "entity//include/IfcRelReferencedInSpatialStructure.h"
#include "entity//include/IfcRelSchedulesCostItems.h"
#include "entity//include/IfcRelSequence.h"
#include "entity//include/IfcRelServicesBuildings.h"
#include "entity//include/IfcRelSpaceBoundary.h"
#include "entity//include/IfcRelVoidsElement.h"
#include "entity//include/IfcRelationship.h"
#include "entity//include/IfcRelaxation.h"
#include "entity//include/IfcRepresentation.h"
#include "entity//include/IfcRepresentationContext.h"
#include "entity//include/IfcRepresentationItem.h"
#include "entity//include/IfcRepresentationMap.h"
#include "entity//include/IfcResource.h"
#include "entity//include/IfcRevolvedAreaSolid.h"
#include "entity//include/IfcRibPlateProfileProperties.h"
#include "entity//include/IfcRightCircularCone.h"
#include "entity//include/IfcRightCircularCylinder.h"
#include "entity//include/IfcRoof.h"
#include "entity//include/IfcRoot.h"
#include "entity//include/IfcRoundedEdgeFeature.h"
#include "entity//include/IfcRoundedRectangleProfileDef.h"
#include "entity//include/IfcSIUnit.h"
#include "entity//include/IfcSanitaryTerminalType.h"
#include "entity//include/IfcScheduleTimeControl.h"
#include "entity//include/IfcSectionProperties.h"
#include "entity//include/IfcSectionReinforcementProperties.h"
#include "entity//include/IfcSectionedSpine.h"
#include "entity//include/IfcSensorType.h"
#include "entity//include/IfcServiceLife.h"
#include "entity//include/IfcServiceLifeFactor.h"
#include "entity//include/IfcShapeAspect.h"
#include "entity//include/IfcShapeModel.h"
#include "entity//include/IfcShapeRepresentation.h"
#include "entity//include/IfcShellBasedSurfaceModel.h"
#include "entity//include/IfcSimpleProperty.h"
#include "entity//include/IfcSite.h"
#include "entity//include/IfcSlab.h"
#include "entity//include/IfcSlabType.h"
#include "entity//include/IfcSlippageConnectionCondition.h"
#include "entity//include/IfcSolidModel.h"
#include "entity//include/IfcSoundProperties.h"
#include "entity//include/IfcSoundValue.h"
#include "entity//include/IfcSpace.h"
#include "entity//include/IfcSpaceHeaterType.h"
#include "entity//include/IfcSpaceProgram.h"
#include "entity//include/IfcSpaceThermalLoadProperties.h"
#include "entity//include/IfcSpaceType.h"
#include "entity//include/IfcSpatialStructureElement.h"
#include "entity//include/IfcSpatialStructureElementType.h"
#include "entity//include/IfcSphere.h"
#include "entity//include/IfcStackTerminalType.h"
#include "entity//include/IfcStair.h"
#include "entity//include/IfcStairFlight.h"
#include "entity//include/IfcStairFlightType.h"
#include "entity//include/IfcStructuralAction.h"
#include "entity//include/IfcStructuralActivity.h"
#include "entity//include/IfcStructuralAnalysisModel.h"
#include "entity//include/IfcStructuralConnection.h"
#include "entity//include/IfcStructuralConnectionCondition.h"
#include "entity//include/IfcStructuralCurveConnection.h"
#include "entity//include/IfcStructuralCurveMember.h"
#include "entity//include/IfcStructuralCurveMemberVarying.h"
#include "entity//include/IfcStructuralItem.h"
#include "entity//include/IfcStructuralLinearAction.h"
#include "entity//include/IfcStructuralLinearActionVarying.h"
#include "entity//include/IfcStructuralLoad.h"
#include "entity//include/IfcStructuralLoadGroup.h"
#include "entity//include/IfcStructuralLoadLinearForce.h"
#include "entity//include/IfcStructuralLoadPlanarForce.h"
#include "entity//include/IfcStructuralLoadSingleDisplacement.h"
#include "entity//include/IfcStructuralLoadSingleDisplacementDistortion.h"
#include "entity//include/IfcStructuralLoadSingleForce.h"
#include "entity//include/IfcStructuralLoadSingleForceWarping.h"
#include "entity//include/IfcStructuralLoadStatic.h"
#include "entity//include/IfcStructuralLoadTemperature.h"
#include "entity//include/IfcStructuralMember.h"
#include "entity//include/IfcStructuralPlanarAction.h"
#include "entity//include/IfcStructuralPlanarActionVarying.h"
#include "entity//include/IfcStructuralPointAction.h"
#include "entity//include/IfcStructuralPointConnection.h"
#include "entity//include/IfcStructuralPointReaction.h"
#include "entity//include/IfcStructuralProfileProperties.h"
#include "entity//include/IfcStructuralReaction.h"
#include "entity//include/IfcStructuralResultGroup.h"
#include "entity//include/IfcStructuralSteelProfileProperties.h"
#include "entity//include/IfcStructuralSurfaceConnection.h"
#include "entity//include/IfcStructuralSurfaceMember.h"
#include "entity//include/IfcStructuralSurfaceMemberVarying.h"
#include "entity//include/IfcStructuredDimensionCallout.h"
#include "entity//include/IfcStyleModel.h"
#include "entity//include/IfcStyledItem.h"
#include "entity//include/IfcStyledRepresentation.h"
#include "entity//include/IfcSubContractResource.h"
#include "entity//include/IfcSubedge.h"
#include "entity//include/IfcSurface.h"
#include "entity//include/IfcSurfaceCurveSweptAreaSolid.h"
#include "entity//include/IfcSurfaceOfLinearExtrusion.h"
#include "entity//include/IfcSurfaceOfRevolution.h"
#include "entity//include/IfcSurfaceStyle.h"
#include "entity//include/IfcSurfaceStyleLighting.h"
#include "entity//include/IfcSurfaceStyleRefraction.h"
#include "entity//include/IfcSurfaceStyleRendering.h"
#include "entity//include/IfcSurfaceStyleShading.h"
#include "entity//include/IfcSurfaceStyleWithTextures.h"
#include "entity//include/IfcSurfaceTexture.h"
#include "entity//include/IfcSweptAreaSolid.h"
#include "entity//include/IfcSweptDiskSolid.h"
#include "entity//include/IfcSweptSurface.h"
#include "entity//include/IfcSwitchingDeviceType.h"
#include "entity//include/IfcSymbolStyle.h"
#include "entity//include/IfcSystem.h"
#include "entity//include/IfcSystemFurnitureElementType.h"
#include "entity//include/IfcTShapeProfileDef.h"
#include "entity//include/IfcTable.h"
#include "entity//include/IfcTableRow.h"
#include "entity//include/IfcTankType.h"
#include "entity//include/IfcTask.h"
#include "entity//include/IfcTelecomAddress.h"
#include "entity//include/IfcTendon.h"
#include "entity//include/IfcTendonAnchor.h"
#include "entity//include/IfcTerminatorSymbol.h"
#include "entity//include/IfcTextLiteral.h"
#include "entity//include/IfcTextLiteralWithExtent.h"
#include "entity//include/IfcTextStyle.h"
#include "entity//include/IfcTextStyleFontModel.h"
#include "entity//include/IfcTextStyleForDefinedFont.h"
#include "entity//include/IfcTextStyleTextModel.h"
#include "entity//include/IfcTextStyleWithBoxCharacteristics.h"
#include "entity//include/IfcTextureCoordinate.h"
#include "entity//include/IfcTextureCoordinateGenerator.h"
#include "entity//include/IfcTextureMap.h"
#include "entity//include/IfcTextureVertex.h"
#include "entity//include/IfcThermalMaterialProperties.h"
#include "entity//include/IfcTimeSeries.h"
#include "entity//include/IfcTimeSeriesReferenceRelationship.h"
#include "entity//include/IfcTimeSeriesSchedule.h"
#include "entity//include/IfcTimeSeriesValue.h"
#include "entity//include/IfcTopologicalRepresentationItem.h"
#include "entity//include/IfcTopologyRepresentation.h"
#include "entity//include/IfcTransformerType.h"
#include "entity//include/IfcTransportElement.h"
#include "entity//include/IfcTransportElementType.h"
#include "entity//include/IfcTrapeziumProfileDef.h"
#include "entity//include/IfcTrimmedCurve.h"
#include "entity//include/IfcTubeBundleType.h"
#include "entity//include/IfcTwoDirectionRepeatFactor.h"
#include "entity//include/IfcTypeObject.h"
#include "entity//include/IfcTypeProduct.h"
#include "entity//include/IfcUShapeProfileDef.h"
#include "entity//include/IfcUnitAssignment.h"
#include "entity//include/IfcUnitaryEquipmentType.h"
#include "entity//include/IfcValveType.h"
#include "entity//include/IfcVector.h"
#include "entity//include/IfcVertex.h"
#include "entity//include/IfcVertexBasedTextureMap.h"
#include "entity//include/IfcVertexLoop.h"
#include "entity//include/IfcVertexPoint.h"
#include "entity//include/IfcVibrationIsolatorType.h"
#include "entity//include/IfcVirtualElement.h"
#include "entity//include/IfcVirtualGridIntersection.h"
#include "entity//include/IfcWall.h"
#include "entity//include/IfcWallStandardCase.h"
#include "entity//include/IfcWallType.h"
#include "entity//include/IfcWasteTerminalType.h"
#include "entity//include/IfcWaterProperties.h"
#include "entity//include/IfcWindow.h"
#include "entity//include/IfcWindowLiningProperties.h"
#include "entity//include/IfcWindowPanelProperties.h"
#include "entity//include/IfcWindowStyle.h"
#include "entity//include/IfcWorkControl.h"
#include "entity//include/IfcWorkPlan.h"
#include "entity//include/IfcWorkSchedule.h"
#include "entity//include/IfcZShapeProfileDef.h"
#include "entity//include/IfcZone.h"
