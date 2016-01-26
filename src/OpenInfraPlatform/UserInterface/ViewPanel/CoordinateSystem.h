/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_CoordinateSystem_f0e6b71a_ce6f_4804_a4b8_8bf9fcc15f55_h
#define OpenInfraPlatform_UserInterface_CoordinateSystem_f0e6b71a_ce6f_4804_a4b8_8bf9fcc15f55_h

#include "buw.BlueEngine.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		enum class eCoordinateSystemType
		{
			OpenGL,
			Autodesk
		};

		void drawCoordinateSystem(
			buw::ReferenceCounted<buw::VertexCacheLine> vertexCacheLine,
			float scale = 1.0f, 
			eCoordinateSystemType type = eCoordinateSystemType::Autodesk);

		enum class eGridOrientation
		{
			POSITIV_X_ORIENTATION,
			POSITIV_Y_ORIENTATION,
			POSITIV_Z_ORIENTATION
		};

		struct drawGridDescription
		{
			float width;
			float height; 
			buw::vector3f center;
			int widthSegments;
			int heightSegments; 
			eGridOrientation orientation;
			bool leaveCoodinateSystemBlank;
		};
		
		void drawGrid( 
			buw::ReferenceCounted<buw::VertexCacheLine> vertexCacheLine,
			const drawGridDescription& dgd);
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::drawCoordinateSystem;
	using OpenInfraPlatform::UserInterface::eGridOrientation;
	using OpenInfraPlatform::UserInterface::drawGridDescription;
	using OpenInfraPlatform::UserInterface::drawGrid;
}

#endif // end define OpenInfraPlatform_UserInterface_CoordinateSystem_f0e6b71a_ce6f_4804_a4b8_8bf9fcc15f55_h