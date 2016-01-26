/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_RoadDesignVCP_5d78a1e5_0e37_49f9_b30c_7ef45534783b_h
#define OpenInfraPlatform_UserInterface_RoadDesignVCP_5d78a1e5_0e37_49f9_b30c_7ef45534783b_h

#include "buw.BlueEngine.h"
#include "VertexCacheLineT.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class RoadDesignVCP : public buw::VertexCachePoint
		{
		public:
			typedef std::shared_ptr<RoadDesignVCP> Ptr;

			RoadDesignVCP(
				buw::ReferenceCounted<buw::IRenderSystem> renderer,
				const BlueFramework::Core::String& filename);

			RoadDesignVCP(
				buw::ReferenceCounted<buw::IRenderSystem> renderer,
				const BlueFramework::Core::String& filename,
				const int maxPointCount);

			//---------------------------------------------------------------------------//
			// Points
			//---------------------------------------------------------------------------//

			void drawPointsXZ(const std::vector<buw::vector2d>& points);

			void drawPointXZ(const double x, const double y);

			void drawPointXZ(const buw::vector2d& position);

			void drawPointE(const buw::vector2d& position, const buw::vector2d& offset);

			void drawPointE(const buw::vector3d& position, const buw::vector3d& offset);
		};

	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::RoadDesignVCP;
}

#endif // end define OpenInfraPlatform_UserInterface_RoadDesignVCP_5d78a1e5_0e37_49f9_b30c_7ef45534783b_h