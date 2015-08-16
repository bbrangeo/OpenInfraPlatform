
#pragma once

#ifndef IFC_IMPORTER_H
#define IFC_IMPORTER_H

#include "CarveHeaders.h"

#include "RepresentationConverter.h"

namespace OpenInfraPlatform
{
	namespace IfcGeometryConverter
	{
		class GeometrySettings;

		template <
			class IfcEntityTypesT,
			class IfcUnitConverterT,
			class IfcModelT,
			class IfcStepReaderT,
			class IfcExceptionT,
			class IfcEntityT
		>
		class IfcImporterT
		{
		public:
			IfcImporterT()
			: m_progress(0.0f)
			{
				m_ifcModel = std::make_shared<IfcModelT>();
				m_geomSettings = std::make_shared<GeometrySettings>();
				m_unitConverter = std::make_shared<IfcUnitConverterT>();
				m_repConverter = std::make_shared<RepresentationConverterT<IfcEntityTypesT, IfcUnitConverterT, IfcEntityT>>(m_geomSettings, m_unitConverter);
				m_ifcStepReader = std::make_shared<IfcStepReaderT>();
			}

			virtual ~IfcImporterT()
			{

			}

			bool readStepFile(const char* filename)
			{
				const unsigned found = std::string(filename).find_last_of("/\\");
				m_filename = std::string(filename).substr(found + 1);

				// parse step file *.ifc or *.stp
				std::string name(filename);
				std::string extension = name.substr(name.find_last_of(".") + 1);

				if (extension != "ifc" && extension != "stp")
				{
					std::cout << "Error:\t| Extension of step file is not supported." << std::endl;
					return false;
				}

				std::ifstream file(filename);

				if (!file.is_open())
				{
					std::cout << "Error:\t| Could not open file <" << filename << ">." << std::endl;
					return false;
				}

				file.seekg(0, std::ios::end);
				uint64_t fileSize = static_cast<uint64_t>(file.tellg());
				file.seekg(0, std::ios::beg);

				std::string buffer(fileSize, '\0');

				std::cout << "Info\t| Read ifc file...";
				file.read(&buffer[0], fileSize);
				std::cout << " done." << std::endl;

				file.close();

				// create a new ifc model, so clear the current model
				m_ifcModel->clearIfcModel();

				try
				{
					std::cout << "Info\t| \t-> parsing ifc header..." << std::endl;
					// read the header of the step file
					m_ifcStepReader->readStreamHeader(buffer, m_ifcModel);
				}
				catch (IfcExceptionT& e)
				{
					std::cerr << "Exception\t| " << e.what() << std::endl;
					return false;
				}

				m_version = m_ifcModel->getFileSchema();

				std::cout << " done." << std::endl;
				std::cout << "Info\t| ifc scheme: " << m_version << std::endl;
				std::cout << "Info\t| \t-> parsing ifc data...";

				std::map< int, shared_ptr<IfcEntityT>> ifcMap;

				try
				{
					// read the stream data and convert the entities into a map
					m_ifcStepReader->readStreamData(buffer, ifcMap);
				}
				catch (...)//IfcException& e)
				{
					//std::cerr << "Exception\t| " << e.what() << std::endl;
				}

				std::cout << " done." << std::endl;
				std::cout << "Info\t| create corresponding ifc model and resolve attributes..." << std::endl;


				//IfcImporter::updateProgress(-1, "Creating ifc model and resolve attributes...");

				// add the parsed entities into the model

				for (auto it = ifcMap.begin(); it != ifcMap.end(); ++it)
				{
					shared_ptr<IfcEntityT>& entity = it->second;
					try
					{
						m_ifcModel->insertEntity(entity);
					}
					catch (IfcExceptionT& e)
					{
						std::cout << e.what() << std::endl;
						return false;
					}
				}

				m_ifcModel->resolveInverseAttributes();
				m_ifcModel->updateCache();

				// set unit converter and create new representation converter
				m_unitConverter = m_ifcModel->getUnitConverter();
				m_repConverter = std::make_shared<RepresentationConverterT<IfcEntityTypesT, IfcUnitConverterT, IfcEntityT>>(m_geomSettings, m_unitConverter);

				std::cout << " done." << std::endl;
				return true;
			}

			bool collectGeometryData()
			{
				// first get the ifc project
				shared_ptr<typename IfcEntityTypesT::IfcProject> project = m_ifcModel->getIfcProject();

				if (!project)
				{
					std::cerr << "Warning\t| No standard/valid IFC project in loaded IFC model. This may cause problems" << std::endl;
					//return false;
				}

				std::cout << "Info\t| collecting geometry data of all IFC products ...";

				// clear all shape input data and cache
				m_shapeInputData.clear();
				m_repConverter->getProfileCache()->clearProfileCache();

				// geometry settings
				double length_to_meter_factor = m_ifcModel->getUnitConverter()->getLengthInMeterFactor();
				carve::setEpsilon(1.4901161193847656e-08*length_to_meter_factor);

				const std::map<int, shared_ptr<IfcEntityT>>& map = m_ifcModel->getMapIfcObjects();

				for (auto it = map.begin(); it != map.end(); ++it)
				{
					std::shared_ptr<IfcEntityT> entity = it->second;

					std::shared_ptr<typename IfcEntityTypesT::IfcProduct> product = 
						dynamic_pointer_cast<typename IfcEntityTypesT::IfcProduct>(entity);

					const uint32_t entityID = entity->getId();

					// if there are any IFC products, try to extract their geometry
					if (product)
					{
						// if product is a substraction element, 
						// continue as geometry will be created in subtract openings
						if (dynamic_pointer_cast<typename IfcEntityTypesT::IfcFeatureElementSubtraction>(product))
						{
							continue;
						}

#ifdef _DEBUG
						std::cout << "Product: " << entity->classname() << " #" << entityID << std::endl;
#endif

						// if product has no representations, then omit it
						if (!product->m_Representation)
						{
#ifdef _DEBUG
							std::cout << "This product has no representations: " << product->classname()
								<< "  #" << entityID << std::endl;
#endif
							continue;
						}

						// create new shape input data for product
						shared_ptr<ShapeInputDataT<IfcEntityTypesT>> productShape(new ShapeInputDataT<IfcEntityTypesT>());
						productShape->ifc_product = product;

						// convert ifc product info to shape data
						try
						{
							convertIfcProduct(product, productShape);
						}
						catch (IfcExceptionT& e)
						{
							std::cerr << "Error\t| " << e.what() << std::endl;
							return false;
						}
						catch (carve::exception& e)
						{
							std::cerr << "Error\t| " << e.str() << std::endl;
							return false;
						}

						// insert shape data into global shape datas
						m_shapeInputData.insert(std::make_pair(entityID, productShape));
					}
				}

				std::cout << " done." << std::endl;
				return true;
			}

			// getter and setter
			void setIfcModel(std::shared_ptr<IfcModelT> model)
			{
				if (m_ifcModel)
				{
					m_ifcModel->clearIfcModel();
				}

				m_ifcModel = model;

				m_unitConverter = m_ifcModel->getUnitConverter();
				m_repConverter = std::make_shared<RepresentationConverterT<IfcEntityTypesT, IfcUnitConverterT, IfcEntityT>>(m_geomSettings, m_unitConverter);
			}

			const std::string& getIfcVersion() const { return m_version; }

			std::shared_ptr<IfcModelT>& getIfcModel() { return m_ifcModel; }
			std::shared_ptr<GeometrySettings>& getGeomSettings() { return m_geomSettings; }
			std::shared_ptr<IfcUnitConverterT>& getUnitConverter() { return m_unitConverter; }
			std::map<int, std::shared_ptr<ShapeInputDataT<IfcEntityTypesT>>>& getShapeDatas() { return m_shapeInputData; }

		protected:

			void convertIfcProduct(const std::shared_ptr<typename IfcEntityTypesT::IfcProduct>& product,
				std::shared_ptr<ShapeInputDataT<IfcEntityTypesT>>& productShape)
			{
				// get id of product
				const uint32_t productId = product->getId();

				double lengthFactor = m_unitConverter->getLengthInMeterFactor();
				carve::math::Matrix matProduct(carve::math::Matrix::IDENT());

				// check if there's any global object placement for this product
				// if yes, then apply the placement
				if (product->m_ObjectPlacement)
				{
					std::set<int> placementAlreadyApplied;
					PlacementConverterT<IfcEntityTypesT>::convertIfcObjectPlacement(product->m_ObjectPlacement,
						matProduct, lengthFactor,
						placementAlreadyApplied);
				}

				// error string
				std::stringstream strerr;

				// go through all representations of the product
				std::shared_ptr<typename IfcEntityTypesT::IfcProductRepresentation>& representation = product->m_Representation;
				// so evaluate its geometry
				for (auto& rep : representation->m_Representations)
				{
					// convert each shape of the represenation
					m_repConverter->convertIfcRepresentation(rep, matProduct, productShape, strerr);
				}

				computeMeshsetsFromPolyhedrons(product, productShape, strerr);

#ifdef _DEBUG

				if (strerr.tellp() <= 0) return;

				std::stringstream ss;
				ss << "log/" << m_filename << "-" << product->classname()
					<< "#" << product->getId() << ".txt";

				std::ofstream debugLog(ss.str());

				debugLog << strerr.str();

				debugLog.close();

#endif
			}

			void computeMeshsetsFromPolyhedrons(const std::shared_ptr<IfcEntityT>& entity,
				std::shared_ptr<ShapeInputDataT<IfcEntityTypesT>>& productShape,
				std::stringstream& strerr)
			{
				// now examine the opening data of the product representation
				std::vector<shared_ptr<ShapeInputDataT<IfcEntityTypesT>>> openingDatas;

				// check if the prodcut is an ifcElement, then it may contain opening data
				shared_ptr<typename IfcEntityTypesT::IfcElement> element =
					dynamic_pointer_cast<typename IfcEntityTypesT::IfcElement>(entity);

				if (element)
				{
					// then collect opening data
					m_repConverter->convertOpenings(element, openingDatas, strerr);
				}

				// go through all shapes and convert them to meshsets
				for (auto& itemData : productShape->vec_item_data)
				{
					// convert closed polyhedrons to meshsets
					itemData->createMeshSetsFromClosedPolyhedrons();

					// if product is IfcElement, then subtract openings like windows, doors, etc.
					if (element)
					{
						m_repConverter->subtractOpenings(element, itemData, openingDatas, strerr);
					}

					// convert all open polyhedrons to meshsets
					for (auto& openPoly : itemData->open_polyhedrons)
					{

						if (openPoly->getVertexCount() < 3)
						{
							continue;
						}

						shared_ptr<carve::mesh::MeshSet<3>> openMeshset(openPoly->createMesh(carve::input::opts()));
						itemData->meshsets.push_back(openMeshset);
					}

					// convert all open or closed polyhedrons to meshsets
					for (auto& openClosedPoly : itemData->open_or_closed_polyhedrons)
					{

						if (openClosedPoly->getVertexCount() < 3)
						{
							continue;
						}

						shared_ptr<carve::mesh::MeshSet<3>> openMeshset(
							openClosedPoly->createMesh(carve::input::opts()));
						itemData->meshsets.push_back(openMeshset);
					}

					// simplify geometry of all meshsets
					for (auto& meshset : itemData->meshsets)
					{
						m_repConverter->getSolidConverter()->simplifyMesh(meshset);
					}
					// polylines are handled by rendering engine
				}

				productShape->computeAABB();
			}

			std::shared_ptr<IfcModelT>				m_ifcModel;
			std::shared_ptr<IfcStepReaderT>			m_ifcStepReader;
			std::shared_ptr<GeometrySettings>		m_geomSettings;
			std::shared_ptr<RepresentationConverterT<IfcEntityTypesT, IfcUnitConverterT, IfcEntityT>> m_repConverter;
			std::shared_ptr<IfcUnitConverterT>		m_unitConverter;
			std::string								m_filename;
			std::string								m_version;

			float									m_progress;

			// shape input data of all products
			std::map<int, std::shared_ptr<ShapeInputDataT<IfcEntityTypesT>> > m_shapeInputData;
		};
	}
}

#endif
