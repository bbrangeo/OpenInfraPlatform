/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_Surface_f463f8cf_46d8_48e6_960a_4d45f66a5771_h
#define OpenInfraPlatform_Infrastructure_Surface_f463f8cf_46d8_48e6_960a_4d45f66a5771_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "buw.BlueCore.Math.vector.h"
#include <map>

#include "BlueFramework/Rasterizer/IRenderSystem.h"

namespace OpenInfraPlatform
{	
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API Surface
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(Surface);

			Surface();
			virtual ~Surface();

			void clear();

			static Surface* createFlatCopy(const Surface& src);

			//! Checks if a point is within the bounds of this specific surface element.
			bool contains(buw::vector2d& p) const;

			double getZ(buw::vector2d& xy) const;				

			// checks if all indices are valid
			bool validate() const;

			buw::vector3d getBoundsMax() const;
			buw::vector3d getBoundsMin() const;
			
			//---------------------------------------------------------------------------//
			// Name
			//---------------------------------------------------------------------------//

			void setName(const char* str);

			const char* getName() const;
			
			//---------------------------------------------------------------------------//
			// Points
			//---------------------------------------------------------------------------//

			void setPoints(const std::vector<buw::vector3d>& points);

			void addPoint(const buw::vector3d& p);

			int getPointCount() const;
			
			const std::vector<buw::vector3d>& getPoints() const;

			//---------------------------------------------------------------------------//
			// Triangles
			//---------------------------------------------------------------------------//

			void setTriangles(const std::vector<buw::vector3i>& indices);

			void addTriangle(const buw::vector3i& indices);

			int getTriangleCount() const;
			
			const std::vector<buw::vector3i>&			getTriangeFaces() const;

		private:
			double zRay(buw::vector2d& xy, int faceID) const;

			bool pointInTriangle(buw::vector2d& pt, int faceID) const;

			double sign(buw::vector2d p1, buw::vector2d p2, buw::vector2d p3) const;

			void updateBounds(const buw::vector3d& p);

		private:
			std::vector<buw::vector3d>			points_;
			std::vector<buw::vector3i>			triangeIndices_;
			std::string							name_;

			// cached data
			buw::vector3d						boundsMax_;
			buw::vector3d						boundsMin_;
		};	
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::Surface;
}			
			
#endif // end define OpenInfraPlatform_Infrastructure_Surface_f463f8cf_46d8_48e6_960a_4d45f66a5771_h
