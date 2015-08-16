/*! \verbatim
 *  \copyright		Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author			Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\brief			This file is part of the BlueFramework.
 *	\endverbatim
 */

#pragma once

#include "buw.BlueEngine.h"

namespace OpenInfraPlatform
{
	class RoadDesignVCP : public buw::VertexCachePoint
	{
	public:
		typedef std::shared_ptr<RoadDesignVCP> Ptr;	

		RoadDesignVCP(
			buw::IRenderSystem::Ptr renderer,
			const BlueFramework::Core::String& filename) : VertexCachePoint(renderer, filename)
		{

		}

		RoadDesignVCP(
			buw::IRenderSystem::Ptr renderer,
			const BlueFramework::Core::String& filename,
			const int maxPointCount) :VertexCachePoint(renderer,filename,maxPointCount)
		{

		}

		//---------------------------------------------------------------------------//
		// Points
		//---------------------------------------------------------------------------//

		void drawPointsXZ(const std::vector<buw::vector2d>& points)
		{
			for (int i = 0; i < points.size(); i++)
			{
				drawPointXZ(points[i]);
			}
		}

		void drawPointXZ(const double x, const double y)
		{
			drawPointXZ( buw::vector2d(x,y) );
		}

		void drawPointXZ(const buw::vector2d& position)
		{
			drawPoint(position.x(), 0, position.y());
		}

		void drawPointE(const buw::vector2d& position, const buw::vector2d& offset)
		{
			drawPoint(position - offset);
		}

		void drawPointE(const buw::vector3d& position, const buw::vector3d& offset)
		{
			drawPoint(position - offset);
		}
	};

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

	class RoadDesignVCL : public buw::VertexCacheLine
	{
	public:
		typedef std::shared_ptr<RoadDesignVCL> Ptr;	

		RoadDesignVCL(
			buw::IRenderSystem::Ptr renderer,
			const BlueFramework::Core::String& filename, 
			const int size) : 
		VertexCacheLine(renderer, filename, size)
		{

		}
		
		//---------------------------------------------------------------------------//
		// Lines
		//---------------------------------------------------------------------------//
		void drawLineStrip(const buw::vector2d* list, const int vertexCount )
		{
			buw::vector2d v1 = list[0];
			buw::vector2d v2 = list[0];

			for (int i = 1; i < vertexCount - 1; i++)
			{
				v1 = v2;
				v2 = list[i];
				drawLine(v1, v2);
			}
		}

		void drawLineStrip(const buw::vector2d* list, const int vertexCount, const buw::vector2d& offset )
		{
			buw::vector2d v1 = list[0];
			buw::vector2d v2 = list[0];

			for (int i = 1; i < vertexCount - 1; i++)
			{
				v1 = v2;
				v2 = list[i];
				drawLine(v1 - offset, v2 - offset);
			}
		}
	
		void drawLineStrip(const buw::vector3d* list, const int vertexCount, const buw::vector3d& offset )
		{
			buw::vector3d v1 = list[0];
			buw::vector3d v2 = list[0];

			for (int i = 1; i < vertexCount - 1; i++)
			{
				v1 = v2;
				v2 = list[i];
				drawLine(v1 - offset, v2 - offset);
			}
		}

		//---------------------------------------------------------------------------//
		// Arcs
		//---------------------------------------------------------------------------//
		void drawArcXY(
			const BlueFramework::Core::Math::vector2d& center, 
			const BlueFramework::Core::Math::vector2d& start, 
			const BlueFramework::Core::Math::vector2d& end,
			const eRotationOrder order = eRotationOrder::CounterClockwise)
		{
			buw::vector2d startVec = (start - center);
			buw::vector2d endVec = (end - center);

			float alpha = buw::calculateAngleBetweenVectors(startVec, endVec);
			std::cout << "alpha: " << alpha << std::endl;
			if (order == eRotationOrder::Clockwise)
			{
				alpha = 2.0 * buw::constantsf::pi() - alpha;
			}

			// length of arc
			//float length = radius * alpha;

			int segmentCount = 50;

			buw::vector2d v1 = start;
			buw::vector2d v2 = start;

			for (int segmentIndex = 0; segmentIndex < segmentCount; segmentIndex++)
			{
				v1 = v2;

				float beta = static_cast<float>(segmentIndex)/segmentCount * alpha;

				if (order == eRotationOrder::CounterClockwise)
				{
					buw::matrix44d rotation = buw::createRotationZ44d(beta); 
					v2 = center + buw::transform(rotation, startVec);
				}
				else
				{
					buw::matrix44d rotation = buw::createRotationZ44d(-beta); 
					v2 = center + buw::transform(rotation, startVec);
				}

				drawLine(v1, v2);
			}

			drawLine(v2, end);
		}

		//---------------------------------------------------------------------------//
		// Clothoid
		//---------------------------------------------------------------------------//
		void drawClothideXY(
			const clothoidDescription& clothoid)
		{
			if (clothoid.radiusStart == std::numeric_limits<double>::infinity())
			{
				drawClothideXYStartAngleIsInf(clothoid);
				return;
			}

			if (clothoid.radiusEnd == std::numeric_limits<double>::infinity())
			{
				drawClothideXYEndAngleIsInf(clothoid);
				return;
			}


			int segmentCount = 500;

			buw::vector2d v1 = clothoid.start;
			buw::vector2d v2 = clothoid.start;

			for (int segmentIndex = 0; segmentIndex < segmentCount; segmentIndex++)
			{
				v1 = v2;

				double t = static_cast<float>(segmentIndex)/segmentCount * clothoid.length;

				v2 = clothoid.start + buw::vector2d( CalculateXCoordinate(t), CalculateYCoordinate(t));
				setColor(1,1,0);
				drawLine(v1, v2);
			}

			//drawLine(v2, end);
		}

		//! Draws a line with the given start and end point.
		void drawLineXZ(
			const BlueFramework::Core::Math::vector2d& start, 
			const BlueFramework::Core::Math::vector2d& end)
		{
			drawLine(  
				buw::vector3d(start.x(), 0, start.y()),
				buw::vector3d(end.x(), 0, end.y())
				);
		}
	private:
		void drawClothideXYStartAngleIsInf(
			const clothoidDescription& clothoid)
		{
			
			std::cout << "Start			:" << clothoid.start << std::endl;
			std::cout << "End			:" << clothoid.end << std::endl;
			std::cout << "PI			:"  << clothoid.pi << std::endl;
			std::cout << "RadiusStart	:"  << clothoid.radiusStart << std::endl;
			std::cout << "RadiusEnd 	:"  << clothoid.radiusEnd << std::endl;

			double ClothoidConstantA = std::sqrt( clothoid.length * std::min(clothoid.radiusStart, clothoid.radiusEnd) );

			double signX = 1;
			double signY = 1;

			if      (clothoid.rotationOrder == eRotationOrder::CounterClockwise )			{ signX = 1; signY = -1; }
			else if (clothoid.rotationOrder == eRotationOrder::Clockwise)					{ signX = 1; signY =  1; }
			else throw std::exception("Unknown clothoid rotation");

			double dblBetweenAngleGlobalCoSyAndClothoidCoSy = CalculateClothoidCoSyRotationAngle(clothoid);

			int segmentCount = 500;

			buw::vector2d v1 = clothoid.start;
			buw::vector2d v2 = clothoid.start;

			for (int segmentIndex = 0; segmentIndex < segmentCount; segmentIndex++)
			{
				v1 = v2;

				double t = static_cast<float>(segmentIndex)/segmentCount * clothoid.length;

				buw::vector2d objClPointInClCoSy( signX * CalculateXCoordinate(t, ClothoidConstantA), signY * CalculateYCoordinate(t, ClothoidConstantA));

				buw::matrix44d rotation = buw::createRotationZ44d(-dblBetweenAngleGlobalCoSyAndClothoidCoSy); 
				objClPointInClCoSy = buw::transform(rotation, objClPointInClCoSy);

				v2 = clothoid.start + buw::vector2d(objClPointInClCoSy.x(), objClPointInClCoSy.y());
				drawLine(v1, v2);
			}

			drawLine(v2, clothoid.end);
		}

		void drawClothideXYEndAngleIsInf(
			const clothoidDescription& clothoid)
		{
			double ClothoidConstantA = std::sqrt( clothoid.length * std::min(clothoid.radiusStart, clothoid.radiusEnd) );

			double signX = 1;
			double signY = 1;

			if      (clothoid.rotationOrder == eRotationOrder::CounterClockwise )			{ signX =-1; signY = -1; }
			else if (clothoid.rotationOrder == eRotationOrder::Clockwise)					{ signX =-1; signY =  1; }
			else throw std::exception("Unknown clothoid rotation");

			double dblBetweenAngleGlobalCoSyAndClothoidCoSy = CalculateClothoidCoSyRotationAngle(clothoid);

			int segmentCount = 500;

			buw::vector2d v1 = clothoid.end;
			buw::vector2d v2 = clothoid.end;

			for (int segmentIndex = 0; segmentIndex < segmentCount; segmentIndex++)
			{
				v1 = v2;

				double t = static_cast<float>(segmentIndex)/segmentCount * clothoid.length;

				buw::vector2d objClPointInClCoSy( signX * CalculateXCoordinate(t, ClothoidConstantA), signY * CalculateYCoordinate(t, ClothoidConstantA));

				buw::matrix44d rotation = buw::createRotationZ44d(-dblBetweenAngleGlobalCoSyAndClothoidCoSy); 
				objClPointInClCoSy = buw::transform(rotation, objClPointInClCoSy);

				v2 = clothoid.end + buw::vector2d(objClPointInClCoSy.x(), objClPointInClCoSy.y());
				drawLine(v1, v2);
			}
			drawLine(v2, clothoid.start);
		}

		double CalculateClothoidCoSyRotationAngle(const clothoidDescription& cd)
		{
			buw::vector2d objStartTangent;

			if      (cd.radiusStart == std::numeric_limits<double>::infinity()) objStartTangent = buw::vector2d(cd.pi.x() - cd.start.x(), cd.pi.y() - cd.start.y() );
			else if (cd.radiusEnd   == std::numeric_limits<double>::infinity()) objStartTangent = buw::vector2d(cd.end.x() - cd.pi.x(), cd.end.y() - cd.pi.y() );
			else throw std::exception("Clothoid - clothoid is not implemented yet!");

			return buw::calculateAngleBetweenVectors(objStartTangent, buw::vector2d(1, 0));                    
		}        

		double CalculateXCoordinate(double dblLocalStationing, double ClothoidConstantA = 1)
		{
			int cNumberOfSteps = 500;
			
			double sum = 0;
			double h = dblLocalStationing / (cNumberOfSteps * ClothoidConstantA * std::pow( buw::constantsd::pi(), 0.5));

			for (int i = 1; i < cNumberOfSteps; i++)
				sum += std::cos( buw::constantsd::pi()/2.0 * std::pow( i * h, 2.0));

			sum += 0.5 * (std::cos( buw::constantsd::pi() / 2.0 * std::pow(0.0 * h, 2.0)) + std::cos( buw::constantsd::pi() / 2.0 * std::pow(dblLocalStationing * h, 2.0))); 

			return h * sum *ClothoidConstantA*std::pow(buw::constantsd::pi(),0.5);
		}

		double CalculateYCoordinate(double dblLocalStationing, double ClothoidConstantA = 1)
		{
			int cNumberOfSteps = 500;
			
			double sum = 0;
			double h = dblLocalStationing / (cNumberOfSteps * ClothoidConstantA * std::pow( buw::constantsd::pi(), 0.5));

			for (int i = 1; i < cNumberOfSteps; i++)
				sum += std::sin( buw::constantsd::pi()/2.0 * std::pow( i * h, 2.0));

			sum += 0.5 * (std::sin( buw::constantsd::pi() / 2 * std::pow(0 * h, 2)) + std::sin(buw::constantsd::pi() / 2 * std::pow(dblLocalStationing * h, 2))); 

			return h * sum *ClothoidConstantA*std::pow(buw::constantsd::pi(),0.5);
		}
	};
}

namespace buw
{
	using OpenInfraPlatform::RoadDesignVCL;
	using OpenInfraPlatform::RoadDesignVCP;
	using OpenInfraPlatform::eRotationOrder;
	using OpenInfraPlatform::clothoidDescription;
}


