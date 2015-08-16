// visual studio
#pragma once
// unix
#ifndef CONVERTERBUW_H
#define CONVERTERBUW_H

#include <unordered_map>

#include <buw.BlueEngine.h>
#include "CarveHeaders.h"

/***********************************************************************************************/

typedef buw::VertexPosition3Color3Normal3 VertexLayout;
typedef std::unordered_map<std::string, uint32_t> VertexMap;

namespace OpenInfraPlatform
{
	namespace IfcGeometryConverter
	{
		struct IndexedMeshDescription
		{
			//BLUE_DEFINE_SHARED_POINTER(IndexedMeshDescription);

			std::vector<uint32_t>		indices;
			std::vector<VertexLayout>	vertices;
		};

		struct PolylineDescription
		{
			//BLUE_DEFINE_SHARED_POINTER(PolylineDescription);

			std::vector<uint32_t>					indices;
			std::vector<buw::vector3f> vertices;
		};

		struct IfcGeometryModel
		{
			BLUE_DEFINE_SHARED_POINTER(IfcGeometryModel);

			IndexedMeshDescription meshDescription_;
			PolylineDescription    polylineDescription_;

		};


		class ConverterBuwUtil
		{
		public:
			ConverterBuwUtil() {}
			~ConverterBuwUtil() {}

			static VertexMap vertexMap_;
		};

		template <
			class IfcEntityTypesT
		>
		class ConverterBuwT
		{
		public:
			//static const float FullyOpaqueAlphaThreshold;
			//static const float FullyTransparentAlphaThreshold;

			ConverterBuwT() {}

			virtual ~ConverterBuwT() {}

			static bool insertFaceIntoBuffers(const std::shared_ptr<typename IfcEntityTypesT::IfcProduct>& product,
				const carve::mesh::Face<3>* face,
				std::vector<VertexLayout>& vertices,
				std::vector<uint32_t>& indices)
			{
				const int32_t numVertices = face->nVertices();

				if (numVertices > 4)
				{
					std::cout << "Error\t| Detected face with more than 4 vertices."
						<< " This is not handled by now" << std::endl;
					return false;
				}

				//determine color
				buw::vector3f color = determineColorFromBaseTypes(product);
				//if (color.w() <= FullyTransparentAlphaThreshold) {
				//	return false; //skip fully transparent vertices
				//}

				// obtain vertices from face
				std::vector<buw::vector3f> faceVertices;
				faceVertices.resize(numVertices);
				carve::mesh::Edge<3>* edge = face->edge;

				for (int i = 0; i < numVertices; ++i)
				{
					faceVertices[i] = buw::vector3f(edge->v1()->v.x,
						edge->v1()->v.y,
						edge->v1()->v.z);
					edge = edge->next;
				}

				uint32_t indexOffset = vertices.size();

				buw::vector3f normal = (faceVertices[1] - faceVertices[0])
					^ (faceVertices[2] - faceVertices[0]);

				//normal.normalize();



				// omit spaces
				if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcSpace>(product))
				{
					return false;//color.w() <= FullyOpaqueAlphaThreshold;
				}

				if (numVertices == 3)
				{
					VertexLayout v0, v1, v2;

					v0 = VertexLayout::create(faceVertices[0], color, normal);
					v1 = VertexLayout::create(faceVertices[1], color, normal);
					v2 = VertexLayout::create(faceVertices[2], color, normal);

					std::string keyV0 = createVertexKey(v0);
					std::string keyV1 = createVertexKey(v1);
					std::string keyV2 = createVertexKey(v2);

					if (ConverterBuwUtil::vertexMap_.find(keyV0) == ConverterBuwUtil::vertexMap_.end()) {
						vertices.push_back(v0);
						ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV0, indexOffset++));
					}
					if (ConverterBuwUtil::vertexMap_.find(keyV1) == ConverterBuwUtil::vertexMap_.end()) {
						vertices.push_back(v1);
						ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV1, indexOffset++));
					}
					if (ConverterBuwUtil::vertexMap_.find(keyV2) == ConverterBuwUtil::vertexMap_.end()) {
						vertices.push_back(v2);
						ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV2, indexOffset++));
					}

					indices.push_back(ConverterBuwUtil::vertexMap_[keyV0]);
					indices.push_back(ConverterBuwUtil::vertexMap_[keyV1]);
					indices.push_back(ConverterBuwUtil::vertexMap_[keyV2]);
				}

				else if (numVertices == 4)
				{
					VertexLayout v0, v1, v2, v3;

					v0 = VertexLayout::create(faceVertices[0], color, normal);
					v1 = VertexLayout::create(faceVertices[1], color, normal);
					v2 = VertexLayout::create(faceVertices[2], color, normal);
					v3 = VertexLayout::create(faceVertices[3], color, normal);

					std::string keyV0 = createVertexKey(v0);
					std::string keyV1 = createVertexKey(v1);
					std::string keyV2 = createVertexKey(v2);
					std::string keyV3 = createVertexKey(v3);

					if (ConverterBuwUtil::vertexMap_.find(keyV0) == ConverterBuwUtil::vertexMap_.end()) {
						vertices.push_back(v0);
						ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV0, indexOffset++));
					}
					if (ConverterBuwUtil::vertexMap_.find(keyV1) == ConverterBuwUtil::vertexMap_.end()) {
						vertices.push_back(v1);
						ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV1, indexOffset++));
					}
					if (ConverterBuwUtil::vertexMap_.find(keyV2) == ConverterBuwUtil::vertexMap_.end()) {
						vertices.push_back(v2);
						ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV2, indexOffset++));
					}
					if (ConverterBuwUtil::vertexMap_.find(keyV3) == ConverterBuwUtil::vertexMap_.end()) {
						vertices.push_back(v3);
						ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV3, indexOffset++));
					}

					indices.push_back(ConverterBuwUtil::vertexMap_[keyV0]);
					indices.push_back(ConverterBuwUtil::vertexMap_[keyV1]);
					indices.push_back(ConverterBuwUtil::vertexMap_[keyV2]);

					indices.push_back(ConverterBuwUtil::vertexMap_[keyV0]);
					indices.push_back(ConverterBuwUtil::vertexMap_[keyV2]);
					indices.push_back(ConverterBuwUtil::vertexMap_[keyV3]);
				}

				return true;//color.w() <= FullyOpaqueAlphaThreshold;
			}

			static bool insertMeshIntoBuffers(const std::shared_ptr<typename IfcEntityTypesT::IfcProduct>& product,
				const carve::mesh::Mesh<3>* mesh,
				std::vector<VertexLayout>& vertices,
				std::vector<uint32_t>& indices)
			{
				// walk through all faces of the mesh
				bool ret = false;
				for (const auto& face : mesh->faces)
				{
					if (face->nVertices() > 4)
					{
						std::cout << "Error\t| Detected face with more than 4 vertices -> "
							<< face->nVertices() << " This is not handled by now" << std::endl;
						continue;
					}

					ret |= insertFaceIntoBuffers(product, face, vertices, indices);
				}
				return ret;
			}

			static bool insertMeshSetIntoBuffers(const std::shared_ptr<typename IfcEntityTypesT::IfcProduct>& product,
				const carve::mesh::MeshSet<3>* meshSet,
				std::vector<VertexLayout>& vertices,
				std::vector<uint32_t>& indices)
			{
				bool ret = false;
				if (!meshSet)
				{
					return ret;
				}

				// walk through all meshes of the mesh set
				for (const auto& mesh : meshSet->meshes)
				{
					ret |= insertMeshIntoBuffers(product, mesh, vertices, indices);
				}
				return ret;
			}

			static bool insertOpenMeshIntoBuffers(const std::shared_ptr<typename IfcEntityTypesT::IfcProduct>& product,
				const carve::input::PolyhedronData* polyData,
				std::vector<VertexLayout>& vertices,
				std::vector<uint32_t>& indices)
			{
				const buw::vector3f color(0, 1, 0);//, 1);
				//if (color.w() <= FullyTransparentAlphaThreshold) {
				//	return false; //skip fully transparent vertices
				//}

				std::vector<buw::vector3f> polyVertices;

				for (const auto& vertex : polyData->points)
				{
					polyVertices.push_back(buw::vector3f(vertex.x, vertex.y, vertex.z));
				}

				int32_t indexOffset = vertices.size();

				// walk through all indices
				for (auto it = polyData->faceIndices.cbegin(); it != polyData->faceIndices.cend(); ++it)
				{
					const int32_t numIndices = *it;

					if (numIndices == 3)
					{
						VertexLayout v0, v1, v2;

						buw::vector3f* pos0, *pos1, *pos2;

						++it;
						pos0 = &polyVertices.at(*it);
						++it;
						pos1 = &polyVertices.at(*it);
						++it;
						pos2 = &polyVertices.at(*it);

						const buw::vector3f normal((pos2 - pos0) ^ (pos1 - pos0));

						v0 = VertexLayout::create(*pos0, color, normal);
						v1 = VertexLayout::create(*pos1, color, normal);
						v2 = VertexLayout::create(*pos2, color, normal);

						std::string keyV0 = createVertexKey(v0);
						std::string keyV1 = createVertexKey(v1);
						std::string keyV2 = createVertexKey(v2);

						if (ConverterBuwUtil::vertexMap_.find(keyV0) == ConverterBuwUtil::vertexMap_.end()) {
							vertices.push_back(v0);
							ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV0, indexOffset++));
						}
						if (ConverterBuwUtil::vertexMap_.find(keyV1) == ConverterBuwUtil::vertexMap_.end()) {
							vertices.push_back(v1);
							ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV1, indexOffset++));
						}
						if (ConverterBuwUtil::vertexMap_.find(keyV2) == ConverterBuwUtil::vertexMap_.end()) {
							vertices.push_back(v2);
							ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV2, indexOffset++));
						}

						indices.push_back(ConverterBuwUtil::vertexMap_[keyV0]);
						indices.push_back(ConverterBuwUtil::vertexMap_[keyV1]);
						indices.push_back(ConverterBuwUtil::vertexMap_[keyV2]);

					}
					else if (numIndices == 4)
					{
						VertexLayout v0, v1, v2, v3;

						buw::vector3f* pos0, *pos1, *pos2, *pos3;

						++it;
						pos0 = &polyVertices.at(*it);
						++it;
						pos1 = &polyVertices.at(*it);
						++it;
						pos2 = &polyVertices.at(*it);
						++it;
						pos3 = &polyVertices.at(*it);

						const buw::vector3f normal((pos2 - pos0) ^ (pos1 - pos0));

						v0 = VertexLayout::create(*pos0, color, normal);
						v1 = VertexLayout::create(*pos1, color, normal);
						v2 = VertexLayout::create(*pos2, color, normal);
						v3 = VertexLayout::create(*pos3, color, normal);

						std::string keyV0 = createVertexKey(v0);
						std::string keyV1 = createVertexKey(v1);
						std::string keyV2 = createVertexKey(v2);
						std::string keyV3 = createVertexKey(v3);

						if (ConverterBuwUtil::vertexMap_.find(keyV0) == ConverterBuwUtil::vertexMap_.end()) {
							vertices.push_back(v0);
							ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV0, indexOffset++));
						}
						if (ConverterBuwUtil::vertexMap_.find(keyV1) == ConverterBuwUtil::vertexMap_.end()) {
							vertices.push_back(v1);
							ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV1, indexOffset++));
						}
						if (ConverterBuwUtil::vertexMap_.find(keyV2) == ConverterBuwUtil::vertexMap_.end()) {
							vertices.push_back(v2);
							ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV2, indexOffset++));
						}
						if (ConverterBuwUtil::vertexMap_.find(keyV3) == ConverterBuwUtil::vertexMap_.end()) {
							vertices.push_back(v3);
							ConverterBuwUtil::vertexMap_.insert(std::pair<std::string, uint32_t>(keyV3, indexOffset++));
						}

						indices.push_back(ConverterBuwUtil::vertexMap_[keyV0]);
						indices.push_back(ConverterBuwUtil::vertexMap_[keyV1]);
						indices.push_back(ConverterBuwUtil::vertexMap_[keyV2]);

						indices.push_back(ConverterBuwUtil::vertexMap_[keyV0]);
						indices.push_back(ConverterBuwUtil::vertexMap_[keyV2]);
						indices.push_back(ConverterBuwUtil::vertexMap_[keyV3]);
					}
					else
					{
						std::cout << "Error\t| Detected face with more than 4 vertices."
							<< " This is not handled by now" << std::endl;

						for (int32_t i = 0; i < numIndices; ++i)
						{
							++it;
						}
					}
				}
				return true; // color.w() <= FullyOpaqueAlphaThreshold;
			}

			static bool insertPolyhedronIntoBuffers(const std::shared_ptr<typename IfcEntityTypesT::IfcProduct>& product,
				const carve::poly::Polyhedron* polyhedron,
				std::vector<VertexLayout>& vertices,
				std::vector<uint32_t>& indices)
			{
				std::shared_ptr<carve::mesh::MeshSet<3>> meshSet(carve::meshFromPolyhedron(polyhedron, -1));
				bool ret = false;
				for (const auto& mesh : meshSet->meshes)
				{
					ret |= insertMeshIntoBuffers(product, mesh, vertices, indices);
				}
				return ret;
			}

			static bool insertPolylineIntoBuffers(const std::shared_ptr<typename IfcEntityTypesT::IfcProduct>& product,
				const carve::input::PolylineSetData* polylineData,
				std::vector<VertexLayout>& vertices,
				std::vector<uint32_t>& indices)
			{
				td::cout << "TODO: implement polyline visualization" << std::endl;
				return false;
			}

		protected:

			static buw::vector3f determineColorFromBaseTypes(
				const std::shared_ptr<typename IfcEntityTypesT::IfcProduct>& product)
			{
				if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcWindow>(product))
				{
					return buw::vector3f(0.1f, 0.6f, 1.0f);//, 0.4f);
				}

				// Balken
				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcBeam>(product)
					|| dynamic_pointer_cast<typename IfcEntityTypesT::IfcColumn>(product))
				{
					return buw::vector3f(0.4f, 0.4f, 0.4f);//, 1.0f);
				}

				// ignore spaces!
				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcSpace>(product))
				{
					return buw::vector3f(0.1, 0.2f, 1.0f);//, 1.0f);
				}

				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcDoor>(product))
				{
					return buw::vector3f(0.8f, 0.6f, 0.2f);//, 0.5f);
				}

				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcRoof>(product))
				{
					return buw::vector3f(0.6f, 0.15f, 0.15f);//, 1.0f);
				}

				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcStair>(product)
					|| dynamic_pointer_cast<typename IfcEntityTypesT::IfcStairFlight>(product))
				{
					return buw::vector3f(0.8f, 0.4f, 0.4f);//, 1.0f);
				}

				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcRamp>(product)
					|| dynamic_pointer_cast<typename IfcEntityTypesT::IfcRampFlight>(product))
				{
					return buw::vector3f(0.6f, 0.6f, 0.4f);//, 1.0f);
				}

				// Geländer
				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcRailing>(product))
				{
					return buw::vector3f(0.7f, 0.7f, 0.2f);//, 1.0f);
				}

				// Geländer
				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcPile>(product))
				{
					return buw::vector3f(0.15f, 0.7f, 0.0f);//, 1.0f);
				}

				// Möbel
				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcFurnishingElement>(product))
				{
					return buw::vector3f(0.8f, 0.6f, 0.2f);//, 1.0f);
				}
				// Land
				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcSite>(product))
				{
					return buw::vector3f(0.1f, 0.5f, 0.1f);//, 1.0f);
				}
				// Wasser/Gas Elemente
				else if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcFlowTerminal>(product)
					|| dynamic_pointer_cast<typename IfcEntityTypesT::IfcDistributionFlowElement>(product))
				{
					return buw::vector3f(0.4f, 0.4f, 0.6f);//, 1.0f);
				}
				// Platte als Dach oder Geländer?
				else if (std::dynamic_pointer_cast<typename IfcEntityTypesT::IfcSlab>(product))
				{
					const std::shared_ptr<typename IfcEntityTypesT::IfcSlab>& slab = 
						std::dynamic_pointer_cast<typename IfcEntityTypesT::IfcSlab>(product);

					if (slab->m_PredefinedType)
					{
						// Dach
						if (slab->m_PredefinedType->m_enum == IfcEntityTypesT::IfcSlabTypeEnum::ENUM_ROOF)
						{
							return buw::vector3f(0.6f, 0.15f, 0.15f);//, 1.0f);
						}

						// Treppenabsatz
						else if (slab->m_PredefinedType->m_enum == IfcEntityTypesT::IfcSlabTypeEnum::ENUM_LANDING)
						{
							return buw::vector3f(0.8f, 0.4f, 0.4f);//, 1.0f);
						}

						else if (slab->m_PredefinedType->m_enum == IfcEntityTypesT::IfcSlabTypeEnum::ENUM_FLOOR ||
							slab->m_PredefinedType->m_enum == IfcEntityTypesT::IfcSlabTypeEnum::ENUM_BASESLAB ||
							slab->m_PredefinedType->m_enum == IfcEntityTypesT::IfcSlabTypeEnum::ENUM_NOTDEFINED)
						{
							return buw::vector3f(1.0f, 0.95f, 0.9f);//, 1.0f);
						}
					}
				}

				return buw::vector3f(1, 1, 1);//, 1);
			}

			static std::string createVertexKey(VertexLayout& v)
			{
				return std::to_string(v.position.x()) + " " + std::to_string(v.position.y()) + " " + std::to_string(v.position.z()) + " "
					+ std::to_string(v.normal.x()) + " " + std::to_string(v.normal.y()) + " " + std::to_string(v.normal.z());
			};

		};
	}
}

#endif
