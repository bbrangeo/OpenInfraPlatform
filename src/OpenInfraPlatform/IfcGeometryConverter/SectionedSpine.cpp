///* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com  - Copyright (C) 2011 Fabian Gerold
// *
// * This library is open source and may be redistributed and/or modified under  
// * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
// * (at your option) any later version.  The full license is in LICENSE file
// * included with this distribution, and on the openscenegraph.org website.
// * 
// * This library is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// * OpenSceneGraph Public License for more details.
//*/
//
//#include "CarveHeaders.h"
//#include "ReaderSettings.h"
//
//#ifdef IFC4_READER
//#include <BlueFramework/Ifc4/entity/include/IfcSectionedSpine.h>
//#include <BlueFramework/Ifc4/entity/include/IfcCompositeCurve.h>
//#include <BlueFramework/Ifc4/entity/include/IfcRationalBSplineCurveWithKnots.h>
//#include <BlueFramework/Ifc4/entity/include/IfcProfileDef.h>
//
//#include <BlueFramework/Ifc4/entity/include/IfcCartesianPoint.h>
//#include <BlueFramework/Ifc4/entity/include/IfcArbitraryClosedProfileDef.h>
//#include <BlueFramework/Ifc4/entity/include/IfcPolyline.h>
//#include <BlueFramework/Ifc4/entity/include/IfcParameterValue.h>
//#include <BlueFramework/Ifc4/entity/include/IfcCartesianPoint.h>
//#include <BlueFramework/Ifc4/entity/include/IfcLengthMeasure.h>
//#include <BlueFramework/Ifc4/entity/include/IfcDirection.h>
//#include <BlueFramework/Ifc4/entity/include/IfcArbitraryProfileDefWithVoids.h>
//#include <BlueFramework/Ifc4/entity/include/IfcRationalBSplineSurfaceWithKnots.h>
//
//#include <BlueFramework/Ifc4/model/Ifc4Model.h>
//#include <BlueFramework/Ifc4/model/UnitConverter.h>
//#include <BlueFramework/Ifc4/model/Ifc4Exception.h>
//
//
//using namespace BlueFramework::Ifc4;
//#endif
//
//#ifdef IFC2X3_READER
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcSectionedSpine.h>
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcCompositeCurve.h>
////#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcRationalBSplineCurveWithKnots.h>
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcProfileDef.h>
//
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcCartesianPoint.h>
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcArbitraryClosedProfileDef.h>
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcPolyline.h>
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcParameterValue.h>
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcCartesianPoint.h>
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcLengthMeasure.h>
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcDirection.h>
//#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcArbitraryProfileDefWithVoids.h>
////#include <OpenInfraPlatform/Ifc2x3/entity/include/IfcRationalBSplineSurfaceWithKnots.h>
//
//#include <OpenInfraPlatform/Ifc2x3/model/Ifc2x3Model.h>
//#include <OpenInfraPlatform/Ifc2x3/model/UnitConverter.h>
//#include <OpenInfraPlatform/Ifc2x3/model/Ifc2x3Exception.h>
//
//using namespace OpenInfraPlatform::Ifc2x3;
//#endif
//
//#include "CurveConverter.h"
//
//#include "RepresentationConverter.h"
//
//using namespace OpenInfraPlatform::IfcGeometryConverter;
//
//void RepresentationConverter::convertIfcSectionedSpine( 
//												const std::shared_ptr<IfcSectionedSpine>& spine,
//													   const carve::math::Matrix& pos,
//													   std::shared_ptr<ItemData> item_data,
//													   std::stringstream& strs_err )
//{
//	const std::shared_ptr<IfcCompositeCurve> spine_curve = spine->m_SpineCurve;
//	if( !spine_curve )
//	{
//		return;
//	}
//	const std::vector<std::shared_ptr<IfcProfileDef> >& vec_cross_sections = spine->m_CrossSections;
//	const std::vector<std::shared_ptr<IfcAxis2Placement3D> >& vec_cross_section_positions = spine->m_CrossSectionPositions;
//
//	std::vector<std::shared_ptr<IfcProfileDef> >::iterator it_cross_sections;
//
//	unsigned int num_cross_sections = vec_cross_sections.size();
//	if( vec_cross_section_positions.size() < num_cross_sections )
//	{
//		num_cross_sections = vec_cross_section_positions.size();
//	}
//
//	std::vector<std::shared_ptr<IfcCompositeCurveSegment> > segements = spine_curve->m_Segments;
//	int num_segments = segements.size();
//	if( vec_cross_section_positions.size() < num_segments + 1 )
//	{
//		num_segments = vec_cross_section_positions.size() - 1;
//	}
//
//	std::vector<carve::geom::vector<3> > curve_polygon;
//	std::vector<carve::geom::vector<3> > segment_start_points;
//
//	m_curve_converter->convertIfcCurve( spine_curve, curve_polygon, segment_start_points );
//
//	std::cout << "IfcSectionedSpine not implemented." << std::endl;
//}
