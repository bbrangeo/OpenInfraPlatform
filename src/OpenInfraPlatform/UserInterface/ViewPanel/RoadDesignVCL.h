/*! \verbatim
 *  \copyright		Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author			Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\brief			This file is part of the BlueFramework.
 *	\endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_RoadDesignVCL_3bc259a4_0b37_4496_83cc_4374f3e41963_h
#define OpenInfraPlatform_UserInterface_RoadDesignVCL_3bc259a4_0b37_4496_83cc_4374f3e41963_h

#include "buw.BlueEngine.h"
#include "VertexCacheLineT.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		enum class eRotationOrder
		{
			Clockwise,
			CounterClockwise
		};

		struct clothoidDescription
		{
			BlueFramework::Core::Math::vector2d start;
			BlueFramework::Core::Math::vector2d end;
			BlueFramework::Core::Math::vector2d pi;
			double length;
			double radiusStart;
			double radiusEnd;
			eRotationOrder rotationOrder;
		};

		class RoadDesignVCL : public buw::VertexCacheLineT<buw::VertexPosition3Color3Size1ID1>
		{
		public:
			typedef std::shared_ptr<RoadDesignVCL> Ptr;
			typedef  buw::VertexCacheLineT<buw::VertexPosition3Color3Size1ID1> base;

			RoadDesignVCL(
				buw::ReferenceCounted<buw::IRenderSystem> renderer,
				const BlueFramework::Core::String& shaderFilename,
				const BlueFramework::Core::String& pickShaderFilename,
				const int size);

			void drawLine(const buw::vector3f& start, const buw::vector3f& end);

			void drawLine(const buw::vector2f& start, const buw::vector2f& end);

			void drawLine(const buw::vector3d& start, const buw::vector3d& end);

			void drawLine(const buw::vector2d& start, const buw::vector2d& end);

			void setColor(const buw::color3f& color);

			void setColor(float r, float g, float b);

			void setWidth(float width);

			void setID(unsigned int id);

			void flush(const buw::vertexCacheLineShaderData& vcsd, int selected, int hovered);

			void flushPickShader(const buw::vertexCacheLineShaderData& vcsd);

			//---------------------------------------------------------------------------//
			// Lines
			//---------------------------------------------------------------------------//
			void drawLineStrip(const buw::vector2d* list, const int vertexCount);

			void drawLineStrip(const buw::vector2d* list, const int vertexCount, const buw::vector2d& offset);

			void drawLineStrip(const buw::vector3d* list, const int vertexCount, const buw::vector3d& offset);

			//---------------------------------------------------------------------------//
			// Arcs
			//---------------------------------------------------------------------------//
			void drawArcXY(
				const BlueFramework::Core::Math::vector2d& center,
				const BlueFramework::Core::Math::vector2d& start,
				const BlueFramework::Core::Math::vector2d& end,
				const eRotationOrder order = eRotationOrder::CounterClockwise);

			//---------------------------------------------------------------------------//
			// Clothoid
			//---------------------------------------------------------------------------//
			void drawClothideXY(
				const clothoidDescription& clothoid);

			//! Draws a line with the given start and end point.
			void drawLineXZ(
				const BlueFramework::Core::Math::vector2d& start,
				const BlueFramework::Core::Math::vector2d& end);
		private:
			void drawClothideXYStartAngleIsInf(
				const clothoidDescription& clothoid);

			void drawClothideXYEndAngleIsInf(
				const clothoidDescription& clothoid);

			double CalculateClothoidCoSyRotationAngle(const clothoidDescription& cd);

			double CalculateXCoordinate(double dblLocalStationing, double ClothoidConstantA = 1);

			double CalculateYCoordinate(double dblLocalStationing, double ClothoidConstantA = 1);

		private:
			float width_;
			buw::color3f color_;
			unsigned int id_;

			buw::ReferenceCounted<buw::IShader> lineShader_;
			buw::ReferenceCounted<buw::IShader> pickShader_;
		};
	}
}

namespace buw
{
	using OpenInfraPlatform::UserInterface::RoadDesignVCL;
	using OpenInfraPlatform::UserInterface::eRotationOrder;
	using OpenInfraPlatform::UserInterface::clothoidDescription;
}

#endif // end define OpenInfraPlatform_UserInterface_RoadDesignVCL_3bc259a4_0b37_4496_83cc_4374f3e41963_h