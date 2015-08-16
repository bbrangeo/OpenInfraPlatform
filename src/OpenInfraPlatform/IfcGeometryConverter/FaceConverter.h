// visual studio
#pragma once
// unix
#ifndef FACECONVERTER_H
#define FACECONVERTER_H

#include "CarveHeaders.h"

#include <memory>

//#include "ProfileConverter.h"
#include "GeometrySettings.h"
#include "GeomUtils.h"
#include "UnhandledRepresentationException.h"
#include "PlacementConverter.h"
#include "CurveConverter.h"
//#include "FaceConverter.h"
#include "GeometryInputData.h"


namespace OpenInfraPlatform
{
	namespace IfcGeometryConverter
	{
		class ItemData;

		template <
			class IfcEntityTypesT, 
			class IfcUnitConverterT
		>
 		class FaceConverterT
 		{
		public:
			FaceConverterT(std::shared_ptr<GeometrySettings> geomSettings,
				std::shared_ptr<IfcUnitConverterT> unitConverter,
				std::shared_ptr<CurveConverterT<IfcEntityTypesT, IfcUnitConverterT>> cc)
				: 
			m_geom_settings(geomSettings), 
			m_unit_converter(unitConverter), 
			m_curve_converter(cc)
			{
			}

			virtual ~FaceConverterT()
			{

			}

			void convertIfcSurface(const std::shared_ptr<typename IfcEntityTypesT::IfcSurface>& surface,
				const carve::math::Matrix& pos,
				std::shared_ptr<carve::input::PolylineSetData>& polyline_data)
			{
				double length_factor = m_unit_converter->getLengthInMeterFactor();
				std::shared_ptr<typename IfcEntityTypesT::IfcBoundedSurface> bounded_surface =
					dynamic_pointer_cast<typename IfcEntityTypesT::IfcBoundedSurface>(surface);

				if (bounded_surface)
				{
					if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcCurveBoundedPlane>(bounded_surface))
					{
						// ENTITY IfcCurveBoundedPlane SUBTYPE OF IfcBoundedSurface;
						shared_ptr<typename IfcEntityTypesT::IfcCurveBoundedPlane> curve_bounded_plane =
							dynamic_pointer_cast<typename IfcEntityTypesT::IfcCurveBoundedPlane>(bounded_surface);
						carve::math::Matrix curve_bounded_plane_matrix(pos);
						shared_ptr<typename IfcEntityTypesT::IfcPlane>& basis_surface = curve_bounded_plane->m_BasisSurface;
						if (basis_surface)
						{
							shared_ptr<typename IfcEntityTypesT::IfcAxis2Placement3D>& basis_surface_placement = basis_surface->m_Position;

							if (basis_surface_placement)
							{
								PlacementConverterT<IfcEntityTypesT>::convertIfcAxis2Placement3D(basis_surface_placement,
									curve_bounded_plane_matrix,
									length_factor);
								curve_bounded_plane_matrix = pos*curve_bounded_plane_matrix;
							}
						}
						
						shared_ptr<typename IfcEntityTypesT::IfcCurve>& outer_boundary = curve_bounded_plane->m_OuterBoundary;
						if (outer_boundary)
						{

						}
						std::vector<shared_ptr<typename IfcEntityTypesT::IfcCurve> >& vec_inner_boundaries = curve_bounded_plane->m_InnerBoundaries;
						for (unsigned int i = 0; i < vec_inner_boundaries.size(); ++i)
						{
							shared_ptr<typename IfcEntityTypesT::IfcCurve>& inner_curve = vec_inner_boundaries[i];

						}
						std::cout << "IfcCurveBoundedPlane not implemented." << std::endl;
					}
					else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcRectangularTrimmedSurface>(bounded_surface))
					{
						shared_ptr<typename IfcEntityTypesT::IfcRectangularTrimmedSurface> rectengular_trimmed_surface =
							dynamic_pointer_cast<typename IfcEntityTypesT::IfcRectangularTrimmedSurface>(bounded_surface);

						shared_ptr<typename IfcEntityTypesT::IfcSurface>& basis_surface = rectengular_trimmed_surface->m_BasisSurface;
						if (basis_surface)
						{
							convertIfcSurface(basis_surface, pos, polyline_data);
						}

						shared_ptr<typename IfcEntityTypesT::IfcParameterValue>& u1 = rectengular_trimmed_surface->m_U1;
						shared_ptr<typename IfcEntityTypesT::IfcParameterValue>& v1 = rectengular_trimmed_surface->m_V1;
						shared_ptr<typename IfcEntityTypesT::IfcParameterValue>& u2 = rectengular_trimmed_surface->m_U2;
						shared_ptr<typename IfcEntityTypesT::IfcParameterValue>& v2 = rectengular_trimmed_surface->m_V2;
						bool u_sense = rectengular_trimmed_surface->m_Usense;
						bool v_sense = rectengular_trimmed_surface->m_Vsense;
						// TODO: implement
						std::cout << "IfcRectangularTrimmedSurface not implemented." << std::endl;
					}
					return;
				}

				shared_ptr<typename IfcEntityTypesT::IfcElementarySurface> elementary_surface =
					dynamic_pointer_cast<typename IfcEntityTypesT::IfcElementarySurface>(surface);
				if (elementary_surface)
				{
					//ENTITY IfcElementarySurface	ABSTRACT SUPERTYPE OF(ONEOF(IfcCylindricalSurface, IfcPlane))
					shared_ptr<typename IfcEntityTypesT::IfcAxis2Placement3D>& elementary_surface_placement =
						elementary_surface->m_Position;

					carve::math::Matrix elementary_surface_matrix(pos);
					if (elementary_surface_placement)
					{
						PlacementConverterT<IfcEntityTypesT>::convertIfcAxis2Placement3D(elementary_surface_placement,
							elementary_surface_matrix,
							length_factor);
						elementary_surface_matrix = pos*elementary_surface_matrix;
					}

					shared_ptr<typename IfcEntityTypesT::IfcPlane> elementary_surface_plane =
						dynamic_pointer_cast<typename IfcEntityTypesT::IfcPlane>(elementary_surface);
					if (elementary_surface_plane)
					{
						//  1----0     create big rectangular plane
						//  |    |     ^ y
						//  |    |     |
						//  2----3     ---> x
						{
							double plane_span = HALF_SPACE_BOX_SIZE;
							polyline_data->beginPolyline();
							polyline_data->addVertex(elementary_surface_matrix *
								carve::geom::VECTOR(plane_span, plane_span, 0.0));
							polyline_data->addVertex(elementary_surface_matrix *
								carve::geom::VECTOR(-plane_span, plane_span, 0.0));
							polyline_data->addVertex(elementary_surface_matrix *
								carve::geom::VECTOR(-plane_span, -plane_span, 0.0));
							polyline_data->addVertex(elementary_surface_matrix *
								carve::geom::VECTOR(plane_span, -plane_span, 0.0));

							polyline_data->addPolylineIndex(0);
							polyline_data->addPolylineIndex(1);
							polyline_data->addPolylineIndex(2);
							polyline_data->addPolylineIndex(3);
						}
						return;
					}

					throw UnhandledRepresentationException<IfcEntityTypesT>(surface);
				}

				shared_ptr<typename IfcEntityTypesT::IfcSweptSurface> swept_surface = dynamic_pointer_cast<typename IfcEntityTypesT::IfcSweptSurface>(surface);

				if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcSweptSurface>(surface))
				{
					// ENTITY IfcSweptSurface	ABSTRACT SUPERTYPE OF(ONEOF(IfcSurfaceOfLinearExtrusion, IfcSurfaceOfRevolution))
					shared_ptr<typename IfcEntityTypesT::IfcProfileDef>& swept_surface_profile = swept_surface->m_SweptCurve;
					shared_ptr<typename IfcEntityTypesT::IfcAxis2Placement3D>& swept_surface_placement = swept_surface->m_Position;

					carve::math::Matrix swept_surface_matrix(pos);
					if (swept_surface_placement)
					{
						PlacementConverterT<IfcEntityTypesT>::convertIfcAxis2Placement3D(swept_surface_placement,
							swept_surface_matrix,
							length_factor);
						swept_surface_matrix = pos*swept_surface_matrix;
					}

					shared_ptr<typename IfcEntityTypesT::IfcSurfaceOfLinearExtrusion> linear_extrusion =
						dynamic_pointer_cast<typename IfcEntityTypesT::IfcSurfaceOfLinearExtrusion>(swept_surface);
					if (linear_extrusion)
					{
						shared_ptr<typename IfcEntityTypesT::IfcDirection>& linear_extrusion_direction =
							linear_extrusion->m_ExtrudedDirection;
						shared_ptr<typename IfcEntityTypesT::IfcLengthMeasure>& linear_extrusion_depth = linear_extrusion->m_Depth;
						// TODO: implement
						std::cout << "IfcSurfaceOfLinearExtrusion not implemented." << std::endl;
						return;
					}

					shared_ptr<typename IfcEntityTypesT::IfcSurfaceOfRevolution> suface_of_revolution =
						dynamic_pointer_cast<typename IfcEntityTypesT::IfcSurfaceOfRevolution>(swept_surface);
					if (suface_of_revolution)
					{
						// TODO: implement
						std::cout << "IfcSurfaceOfRevolution not implemented." << std::endl;
						return;
					}

					throw UnhandledRepresentationException<IfcEntityTypesT>(surface);
				}
				throw UnhandledRepresentationException<IfcEntityTypesT>(surface);
			}

			void convertIfcFaceList(const std::vector<std::shared_ptr<typename IfcEntityTypesT::IfcFace> >& faces,
				const carve::math::Matrix& pos,
				std::shared_ptr<ItemData> item_data,
				std::stringstream& strs_err)
			{
				// indicates if convertion has failed
				bool convertionFailed = false;
				// carve polygon of the converted face list
				std::shared_ptr<carve::input::PolyhedronData> polygon(new carve::input::PolyhedronData());
				// contains polygon indices of vertices (x,y,z converted to string)
				std::map<std::string, uint32_t> polygonIndices;


				// loop through all faces
				for (const auto& face : faces)
				{
					// id of face in step file
					const uint32_t faceID = face->getId();
					// all bound definitions of the face (normal bound or outer bound)
					std::vector<std::shared_ptr<typename IfcEntityTypesT::IfcFaceBound>>& bounds = face->m_Bounds;
					// to triangulate the mesh, carve needs 2D polygons
					// we collect the data in 2D and 3D for every bound
					std::vector<std::vector<carve::geom2d::P2>> faceVertices2D;
					std::vector<std::vector<carve::geom::vector<3>>> faceVertices3D;

					// save polygon indices of merged vertices
					std::map<uint32_t, uint32_t> mergedIndices;

					std::vector<std::shared_ptr<typename IfcEntityTypesT::IfcFaceBound>> modBounds;

					bool faceLoopReversed = false;

					// loop through all boundary definitions
					int boundID = -1;

					// if polygon has more than 3 vertices, 
					// then we have to project polygon into 2D, so that carve can triangulate the mesh
					ProjectionPlane plane = UNDEFINED;

					// as carve expects outer boundary of face to be at first index,
					// outer boundary has index 0 and inner boundary has index 1
					for (const auto& bound : bounds)
					{
						std::shared_ptr<typename IfcEntityTypesT::IfcFaceOuterBound> outerBound =
							std::dynamic_pointer_cast<typename IfcEntityTypesT::IfcFaceOuterBound>(bound);

						if (outerBound)  modBounds.insert(modBounds.begin(), outerBound);
						else modBounds.push_back(bound);
					}

					for (const auto& bound : modBounds)
					{
						boundID++;

						/*********************************************************************************/
						//	IfcLoop <- IfcEdgeLoop, IfcPolyLoop, IfcVertexLoop
						/*********************************************************************************/

						std::shared_ptr<typename IfcEntityTypesT::IfcLoop>& loop = bound->m_Bound;
						const bool polyOrientation = bound->m_Orientation;

						if (!loop)
						{
							strs_err << "FaceConverter Problem with Face #" << faceID
								<< ": IfcLoop #" << loop->getId() << " no valid loop." << std::endl;

							if (boundID == 0) break;
							else continue;
						}

						// collect all vertices of the current loop
						std::vector<carve::geom::vector<3>> loopVertices3D;
						m_curve_converter->convertIfcLoop(loop, loopVertices3D);

						for (auto& vertex : loopVertices3D)
						{
							vertex = pos * vertex;
						}

						if (loopVertices3D.size() < 3)
						{
							strs_err << "FaceConverter Problem with Face #" << faceID
								<< ": IfcLoop #" << loop->getId() << " Number of vertices < 2."
								<< std::endl;

							if (boundID == 0) break;
							else continue;
						}

						// check for orientation and reverse vertices order if FALSE
						if (!polyOrientation) {
							std::reverse(loopVertices3D.begin(), loopVertices3D.end());
						}

						/*********************************************************************************/
						//	3 Vertices Triangle
						/*********************************************************************************/
						if (loopVertices3D.size() == 3)
						{
							std::vector<uint32_t> triangleIndices;
							triangleIndices.reserve(3);

							int pointID = -1;
							for (const auto& vertex3D : loopVertices3D)
							{
								pointID++;

								// apply global transformation to vertex
								const carve::geom::vector<3> v = vertex3D;

								// set string id and search for existing vertex in polygon
								std::stringstream vertexString;
								vertexString << v.x << " " << v.y << " " << v.z;

								auto itFound = polygonIndices.find(vertexString.str());

								uint32_t index = 0;

								if (itFound != polygonIndices.end())
								{
									index = itFound->second;
								}
								else {
									index = polygon->addVertex(v);
									polygonIndices[vertexString.str()] = index;
								}

								triangleIndices.push_back(index);

								mergedIndices[pointID] = index;
							}

							polygon->addFace(triangleIndices.at(0),
								triangleIndices.at(1),
								triangleIndices.at(2));

							//continue;
						}

						/*********************************************************************************/
						//	> 3 Vertices Triangle
						/*********************************************************************************/

						// compute normal of polygon 
						carve::geom::vector<3> normal = GeomUtils::computePolygonNormal(loopVertices3D);

						if (boundID == 0)
						{
							const double nx = std::abs(normal.x);
							const double ny = std::abs(normal.y);
							const double nz = std::abs(normal.z);

							const double nMax = std::max(std::max(nx, ny), nz);

							if (nMax == nx) plane = ProjectionPlane::YZ_PLANE;
							else if (nMax == ny) plane = ProjectionPlane::XZ_PLANE;
							else if (nMax == nz) plane = ProjectionPlane::XY_PLANE;
							else
							{
								convertionFailed = true;
								strs_err << "#" << loop->getId() << " = IfcPolyLoop: " << loop->getId()
									<< " unable to project to plane: nx = " << nx
									<< " ny = " << ny
									<< " nz =" << nz << std::endl;
								continue;
							}
						}

						// now collect all vertices in 2D
						std::vector<carve::geom2d::P2> loopVertices2D;
						loopVertices2D.reserve(loopVertices3D.size());

						for (const auto& vertex : loopVertices3D)
						{
							if (plane == ProjectionPlane::YZ_PLANE) {
								loopVertices2D.push_back(carve::geom::VECTOR(vertex.y, vertex.z));
							}

							else if (plane == ProjectionPlane::XZ_PLANE) {
								loopVertices2D.push_back(carve::geom::VECTOR(vertex.x, vertex.z));
							}

							else if (plane == ProjectionPlane::XY_PLANE) {
								loopVertices2D.push_back(carve::geom::VECTOR(vertex.x, vertex.y));
							}
							else
							{
								std::cout << "ERROR: plane is undefined, what??" << std::endl;
							}
						}

						// check winding order of 2D polygon
						carve::geom3d::Vector normal2D = GeomUtils::computePolygon2DNormal(loopVertices2D);

						if (boundID == 0)
						{
							if (normal2D.z < 0) {
								std::reverse(loopVertices2D.begin(), loopVertices2D.end());
								std::reverse(loopVertices3D.begin(), loopVertices3D.end());

								faceLoopReversed = true;
							}
						}
						else {
							if (normal2D.z > 0) {
								std::reverse(loopVertices2D.begin(), loopVertices2D.end());
								std::reverse(loopVertices3D.begin(), loopVertices3D.end());

								//faceLoopReversed = true;
							}
						}

						if (loopVertices2D.size() < 3)
						{
							convertionFailed = true;
							strs_err << "FaceConverter::convertIfcFaceList: #" << faceID
								<< "= IfcFace: path_loop.size() < 3" << std::endl;
							continue;
						}

						// push back vertices to all faceVertices
						faceVertices2D.push_back(loopVertices2D);
						faceVertices3D.push_back(loopVertices3D);
					}

					// if no faceVertices were collected, no carve operations are required
					if (faceVertices2D.empty()) continue;

					// result after incorporating holes in polygons if defined
					std::vector<std::pair<size_t, size_t>> incorporatedIndices;
					// merged vertices after incorporating of holes
					std::vector<carve::geom2d::P2> mergedVertices2D;
					std::vector<carve::geom::vector<3>> mergedVertices3D;
					// indices after carve triangulation of merged vertices
					std::vector<carve::triangulate::tri_idx> triangulatedIndices;

					try
					{
						incorporatedIndices =
							carve::triangulate::incorporateHolesIntoPolygon(faceVertices2D);

						mergedVertices2D.reserve(incorporatedIndices.size());
						mergedVertices3D.reserve(incorporatedIndices.size());

						for (const auto& incorpIndex : incorporatedIndices)
						{
							size_t loopIndex = incorpIndex.first;
							size_t vertexIndex = incorpIndex.second;

							carve::geom2d::P2& point2D = faceVertices2D[loopIndex][vertexIndex];
							carve::geom::vector<3>& point3D = faceVertices3D[loopIndex][vertexIndex];

							// add vertices to merged results
							mergedVertices2D.push_back(point2D);
							mergedVertices3D.push_back(point3D);
						}

					}
					catch (...) // catch carve error if holes cannot be incorporated 
					{
						convertionFailed = true;
						strs_err << "convertIfcFaceList: #" << faceID
							<< " = IfcFace: carve::triangulate::incorporateHolesIntoPolygon failed "
							<< std::endl;
						//continue;

						mergedVertices2D = faceVertices2D.at(0);
						mergedVertices3D = faceVertices3D.at(0);
					}

					// triangulate 2D polygon and improve triangulation by carve
					carve::triangulate::triangulate(mergedVertices2D, triangulatedIndices);
					carve::triangulate::improve(mergedVertices2D, triangulatedIndices);


					// add new vertices to polygon or get index of existing vertex
					for (uint32_t i = 0; i < mergedVertices3D.size(); ++i)
					{
						const carve::geom::vector<3> v = mergedVertices3D[i];

						// set string id and search for existing vertex in polygon
						std::stringstream vertexString;
						vertexString << v.x << " " << v.y << " " << v.z;

						auto itFound = polygonIndices.find(vertexString.str());

						uint32_t index = 0;

						if (itFound != polygonIndices.end())
						{
							index = itFound->second;
						}
						else {
							index = polygon->addVertex(v);
							polygonIndices[vertexString.str()] = index;
						}

						mergedIndices[i] = index;
					}

					// go through triangulated result and add new faces to polygon
					for (const auto& triangle : triangulatedIndices)
					{
						const uint32_t i0 = triangle.a;
						const uint32_t i1 = triangle.b;
						const uint32_t i2 = triangle.c;

						const uint32_t v0 = mergedIndices[i0];
						const uint32_t v1 = mergedIndices[i1];
						const uint32_t v2 = mergedIndices[i2];

						if (faceLoopReversed) polygon->addFace(v0, v2, v1);
						else polygon->addFace(v0, v1, v2);
					}

				}

				// IfcFaceList can be a closed or open shell, 
				// so let the calling function decide where to put it
				item_data->open_or_closed_polyhedrons.push_back(polygon);

				if (convertionFailed)
				{
					std::stringstream text;
					text << "Exception\t| IFC Face convertion failed with faces #"
						<< faces.at(0)->getId() << "-" << faces.at(faces.size() - 1)->getId();

					throw std::runtime_error(text.str().c_str());
				}
			}

		protected:
			std::shared_ptr<GeometrySettings>	m_geom_settings;
			std::shared_ptr<IfcUnitConverterT>	m_unit_converter;
			std::shared_ptr<CurveConverterT<IfcEntityTypesT, IfcUnitConverterT>> m_curve_converter;
 		};
	}
}

#endif
