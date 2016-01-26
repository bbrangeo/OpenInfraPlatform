/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_PointCloudProcessing_8b77c948_e060_457a_a3ef_7a546fad37c3_h
#define OpenInfraPlatform_Infrastructure_PointCloudProcessing_8b77c948_e060_457a_a3ef_7a546fad37c3_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/ImageProcessing/color.h"
#include "BlueFramework/Core/Math/vector.h"
#include <vector>
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		struct LaserPoint
		{
			buw::vector3d position;
			buw::vector3f color;
		};

		struct PointCloud
		{
			std::vector<LaserPoint> points;
			buw::vector3d			minPos;
			buw::vector3d			maxPos;
		};

		BLUEINFRASTRUCTURE_API void importLASPointCloud(const char* filename, PointCloud& pointCloud);
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::importLASPointCloud;
	using OpenInfraPlatform::Infrastructure::LaserPoint;
	using OpenInfraPlatform::Infrastructure::PointCloud;
}

#endif // end define OpenInfraPlatform_Infrastructure_PointCloudProcessing_8b77c948_e060_457a_a3ef_7a546fad37c3_h
