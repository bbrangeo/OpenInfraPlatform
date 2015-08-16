/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_DataManagement_Data_3ff08224_6d48_4517_a691_b3ed20f3ca74_h
#define OpenInfraPlatform_DataManagement_Data_3ff08224_6d48_4517_a691_b3ed20f3ca74_h

#include "OpenInfraPlatform/Data/terrainDescription.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/DigitalElevationModel.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/AlignmentModel.h"
#include "OpenInfraPlatform/Infrastructure/Export/IfcAlignmentExport.h"
#include "buw.BlueApplication.h"
#include "OpenInfraPlatform/Infrastructure/PointCloudProcessing/PointCloudProcessing.h"
#include "BlueFramework/ImageProcessing/color.h"
#include "BlueFramework/Core/Math/vector.h"
#include <boost/signals2.hpp>
#include <map>

#include "OpenInfraPlatform/IfcGeometryConverter/ConverterBuw.h"


namespace OpenInfraPlatform
{
	namespace DataManagement
	{
		class Data;
		typedef BlueFramework::Application::DataManagement::DocumentManager<Data> DocumentManager;

		enum DataModifierFlag : unsigned int
		{
			None = 0,
			AlignmentModel_READ = 1 << 0,
			DigitalElevationModel_READ = 1 << 1,
			IFCGeometry_READ = 1 << 2,
			PointCloud_READ = 1 << 3,
			AlignmentModel_WRITE = 1 << 4,
			DigitalElevationModel_WRITE = 1 << 5,
			IFCGeometry_WRITE = 1 << 6,
			PointCloud_WRITE = 1 << 7
		};

		inline DataModifierFlag operator|(DataModifierFlag a, DataModifierFlag b)
		{
			return static_cast<DataModifierFlag>(static_cast<unsigned int>(a) | static_cast<unsigned int>(b));
		}

		inline bool operator&(DataModifierFlag a, DataModifierFlag b)
		{
			return (static_cast<unsigned int>(a) & static_cast<unsigned int>(b)) != 0;
		}

		//! \class Data
		//! \brief This is the data layer/data model of the application. 
		//!
		//! All application data is contained in this class. The data is just manipulated in/through this class. 
		//! This is necessary because the data model is responsible for sending events/signals if the event listers/observers if the data has changed.
		//! The manipulator functions (functions that change the application data) should only be called from IActions.
		class Data : public BlueFramework::Application::DataManagement::Data
		{
		public:		
			//! Constructor.
			Data();

			//! Virtual destructor.
			virtual ~Data();
				
			void save( const std::string & filename );

			//! Clears the date model
			void clear(const bool notifyObservers);
			
			void clear();

			//Retrieve the name of the last imported files
			QString recentFileName;

			// Retrieve the name of the application
			virtual const char* getApplicationName();

			// Retrieve the version string
			virtual const char* getApplicationVersionString();

			// Retrieve the name of the application
			virtual const char* getApplicationOpenFileFilter() override;

			virtual const char* getApplicationSaveFileFilter() override;

			virtual const char* getApplicationImportFileFilter() override;

			// Retrive string for xml file - the standard implementation of save saves all entity objects in an xml file. This string is
			// stored as application string in the xml file. It can be reused when loading a file to check if a file is compatible with this
			// version 
			virtual const char* getApplicationNameXML();

			//---------------------------------------------------------------------------//
			// Loading/Saving and Import
			//---------------------------------------------------------------------------//

			//! Loads a file.
			/*
				\param[in] filename	Path to the file which should be opened.
			*/
			void open(const std::string & filename);

			void import(const std::string & filename, bool async = true);

			/*void importLandXML(const std::string &filename);
			void importOKSTRA(const std::string &filename);
			void importStepFile(const std::string &filename);
			void importIfcStepFile(const std::string &filename);
			void importIfcAlignment(const std::string &filename);
			void importIfcRoad(const std::string &filename);
			void importRoadXML(const std::string &filename);*/

			void importLAS(const std::string& filename);

			void exportIfcRoadTUMProposal(const std::string & filename);
			void exportIfcAlignment(const buw::ifcAlignmentExportDescription& desc, const std::string & filename);
			void exportSVG( const std::string& filename );
			void exportLandXML( const std::string& filename );
			void exportOkstra(const std::string& filename, const std::string& version);
			void export3DAlignmentAsTextfile(const std::string& filename);
			
			//---------------------------------------------------------------------------//
			// Alignment
			//---------------------------------------------------------------------------//

			void addAlignment(buw::IAlignment3D::Ptr alignment);
			void deleteAlignment(buw::IAlignment3D::Ptr alignment);

			void computeSurfaceProfile();

			//---------------------------------------------------------------------------//
			// Digital Elevation Model
			//---------------------------------------------------------------------------//
			
			void addSurface(buw::Surface::Ptr surface);
			void deleteSurface(buw::Surface::Ptr surface);

			buw::vector3d getOffset() const;

			void createRandomTerrain(const buw::terrainDescription& td);
			void createTerrainFromHeightMap(const std::string& filename);

			void importXYZ( const std::vector<buw::vector3d>& positions );

			OpenInfraPlatform::Infrastructure::DigitalElevationModel::Ptr getDigitalElevationModel() const;

			OpenInfraPlatform::Infrastructure::AlignmentModel::Ptr getAlignmentModel() const;


			//---------------------------------------------------------------------------//
			// IFCx Model
			//---------------------------------------------------------------------------//

			IfcGeometryConverter::IfcGeometryModel::Ptr getIfcGeometryModel() const;

			//---------------------------------------------------------------------------//
			// Point Cloud
			//---------------------------------------------------------------------------//
			const int getPointCloudPointCount() const;

			const std::vector<buw::LaserPoint>& getPointCloud() const;

			//---------------------------------------------------------------------------//
			// Preferences
			//---------------------------------------------------------------------------//

			void setClearColor(const buw::color3f& color);
			buw::color3f getClearColor();

			void enableGradientClear(const bool enable);
			bool isGradientClearEnabled() const;

			bool isDrawGridEnabled() const;
			void enableDrawGrid(bool val);

			void enableShowReferenceCoordinateSystem(bool enable);
			bool isShowReferenceCoordinateSystemEnabled() const;

			void enableSkybox(const bool enable);
			bool isSkyboxEnabled() const;

			void showViewCube(const bool enable);

			bool isViewCubeEnabled();

			void setAlignmentLineWidth(const int width);
			float getAlignmentLineWidth() const { return alignmentLineWidth_; }

			void setShowFrameTimes(const bool enable);

			bool showFrameTimes() const;

		private:
			void createDigitalElevationModel( const buw::vector3d& offsetViewArea );
			OpenInfraPlatform::Infrastructure::AlignmentModel::Ptr readBICFile(const std::string & filename);

			void prepareJob(DataModifierFlag flag);
			void jobFinished(int jobID, bool completed);
			
		private:	
			// Preferences
			buw::color3f	clearColor_;
			bool			enableGradientClear_                = true;
			bool			bDrawGrid_							= false;
			bool			bShowReferenceCoordinateSystem		= true;
			bool			bDrawSkybox_						= false;
			bool			bShowViewCube_						= true;
			bool			bShowFrameTime_						= false;
			float			alignmentLineWidth_;
			

			buw::DigitalElevationModel::Ptr 					digitalElevationModel_;
			buw::AlignmentModel::Ptr							alignmentModel_;
			IfcGeometryConverter::IfcGeometryModel::Ptr			ifcGeometryModel_;

			// class PointCloud
			std::vector<buw::LaserPoint>*		pointCloud_;
			int									chachedPointCloudCount_ = 0;
			buw::vector3d						minPosPointCloud_;
			buw::vector3d						maxPosPointCloud_;



			// temporary data for asynchronous opertations
			buw::DigitalElevationModel::Ptr 					temporaryDigitalElevationModel_;
			buw::AlignmentModel::Ptr							temporaryAlignmentModel_;
			IfcGeometryConverter::IfcGeometryModel::Ptr			temporaryIfcGeometryModel_;

			std::vector<buw::LaserPoint>*		temporaryPointCloud_;
			int									temporaryChachedPointCloudCount_ = 0;
			buw::vector3d						temporaryMinPosPointCloud_;
			buw::vector3d						temporaryMaxPosPointCloud_;


			DataModifierFlag	modifierFlag_;
			int					currentJobID_;

			//! Determines the notification behavior of this class.
			BlueFramework::Application::DataManagement::NotificationState *m_pNotifiactionState;
		}; // end class Data
	} // end namespace DataManagement
} // end namespace OpenInfraPlatform

#endif // end define OpenInfraPlatform_DataManagement_Data_3ff08224_6d48_4517_a691_b3ed20f3ca74_h
