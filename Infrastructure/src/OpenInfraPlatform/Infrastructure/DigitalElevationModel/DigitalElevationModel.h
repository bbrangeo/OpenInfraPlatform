/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_DigitalElevationModel_8b94f7d0_a5fc_4ba4_ab63_f15df1bd6515_h
#define OpenInfraPlatform_Infrastructure_DigitalElevationModel_8b94f7d0_a5fc_4ba4_ab63_f15df1bd6515_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/IAlignment3D.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/Surface.h"
#include "buw.BlueCore.class.h"
#include "buw.BlueCore.Math.vector.h"
#include <boost/noncopyable.hpp>
#include <vector>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		//! A digital terrain model exists of a number of surfaces.
		class BLUEINFRASTRUCTURE_API DigitalElevationModel
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(DigitalElevationModel)
			
			static DigitalElevationModel* createFlatCopy(const DigitalElevationModel& src);

			//! Default constructor.
			DigitalElevationModel();

			//! Virtual destructor.
			virtual ~DigitalElevationModel();

			void addSurface(buw::ReferenceCounted<buw::Surface> surface);
			
			//! A digital terrain model can 
			int getSurfaceCount() const;

			buw::ReferenceCounted<buw::Surface> getSurface(const int index) const;

			const std::vector<buw::ReferenceCounted<buw::Surface>> &getSurfaces() const;

			void getSurfacesExtend( buw::vector3d& minimalPosition, buw::vector3d& maximalPosition ) const;

			buw::vector3d getCenterPoint() const;

			std::vector<std::pair<double, double>> getSurfaceProfile(buw::ReferenceCounted<buw::IAlignment3D> a) const;
			double getHeightAtPosition(buw::vector2d position) const;

			double getMinimumHeight() const;
	
			double getMaximumHeight() const;

			void deleteSurface(buw::ReferenceCounted<buw::Surface> s);

			void addBreakLine(const std::vector<buw::vector3d>& breakLine);

			const std::vector<std::vector<buw::vector3d>>& getBreakLines() const;

		private:
			void updateMinMax( const buw::vector3d& position, buw::vector3d &minPos, buw::vector3d &maxPos ) const;
		
		private:
			std::vector<buw::ReferenceCounted<buw::Surface>>			surfaces_;
			std::vector<std::vector<buw::vector3d>> breakLines_;
		}; // end class DigitalElevationModel

		BLUEINFRASTRUCTURE_API buw::ReferenceCounted<OpenInfraPlatform::Infrastructure::Surface> createSurfaceFromXYZPoints(const std::vector<buw::vector3d>& positions);
	} // end namespace Data
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::DigitalElevationModel;
	using OpenInfraPlatform::Infrastructure::createSurfaceFromXYZPoints;
}

#endif // end define OpenInfraPlatform_Infrastructure_DigitalElevationModel_8b94f7d0_a5fc_4ba4_ab63_f15df1bd6515_h
