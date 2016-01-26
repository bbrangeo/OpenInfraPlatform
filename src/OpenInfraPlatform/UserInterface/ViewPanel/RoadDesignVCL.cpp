/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#include "RoadDesignVCL.h"

double OpenInfraPlatform::UserInterface::RoadDesignVCL::CalculateYCoordinate(double dblLocalStationing, double ClothoidConstantA /*= 1*/)
{
	int cNumberOfSteps = 500;

	double sum = 0;
	double h = dblLocalStationing / (cNumberOfSteps * ClothoidConstantA * std::pow(buw::constantsd::pi(), 0.5));

	for (int i = 1; i < cNumberOfSteps; i++)
		sum += std::sin(buw::constantsd::pi() / 2.0 * std::pow(i * h, 2.0));

	sum += 0.5 * (std::sin(buw::constantsd::pi() / 2 * std::pow(0 * h, 2)) + std::sin(buw::constantsd::pi() / 2 * std::pow(dblLocalStationing * h, 2)));

	return h * sum *ClothoidConstantA*std::pow(buw::constantsd::pi(), 0.5);
}

double OpenInfraPlatform::UserInterface::RoadDesignVCL::CalculateXCoordinate(double dblLocalStationing, double ClothoidConstantA /*= 1*/)
{
	int cNumberOfSteps = 500;

	double sum = 0;
	double h = dblLocalStationing / (cNumberOfSteps * ClothoidConstantA * std::pow(buw::constantsd::pi(), 0.5));

	for (int i = 1; i < cNumberOfSteps; i++)
		sum += std::cos(buw::constantsd::pi() / 2.0 * std::pow(i * h, 2.0));

	sum += 0.5 * (std::cos(buw::constantsd::pi() / 2.0 * std::pow(0.0 * h, 2.0)) + std::cos(buw::constantsd::pi() / 2.0 * std::pow(dblLocalStationing * h, 2.0)));

	return h * sum *ClothoidConstantA*std::pow(buw::constantsd::pi(), 0.5);
}

double OpenInfraPlatform::UserInterface::RoadDesignVCL::CalculateClothoidCoSyRotationAngle(const clothoidDescription& cd)
{
	buw::vector2d objStartTangent;

	if (cd.radiusStart == std::numeric_limits<double>::infinity()) objStartTangent = buw::vector2d(cd.pi.x() - cd.start.x(), cd.pi.y() - cd.start.y());
	else if (cd.radiusEnd == std::numeric_limits<double>::infinity()) objStartTangent = buw::vector2d(cd.end.x() - cd.pi.x(), cd.end.y() - cd.pi.y());
	else throw std::exception("Clothoid - clothoid is not implemented yet!");

	return buw::calculateAngleBetweenVectors(objStartTangent, buw::vector2d(1, 0));
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawClothideXYEndAngleIsInf(const clothoidDescription& clothoid)
{
	double ClothoidConstantA = std::sqrt(clothoid.length * std::min(clothoid.radiusStart, clothoid.radiusEnd));

	double signX = 1;
	double signY = 1;

	if (clothoid.rotationOrder == eRotationOrder::CounterClockwise)			{ signX = -1; signY = -1; }
	else if (clothoid.rotationOrder == eRotationOrder::Clockwise)					{ signX = -1; signY = 1; }
	else throw std::exception("Unknown clothoid rotation");

	double dblBetweenAngleGlobalCoSyAndClothoidCoSy = CalculateClothoidCoSyRotationAngle(clothoid);

	int segmentCount = 500;

	buw::vector2d v1 = clothoid.end;
	buw::vector2d v2 = clothoid.end;

	for (int segmentIndex = 0; segmentIndex < segmentCount; segmentIndex++)
	{
		v1 = v2;

		double t = static_cast<float>(segmentIndex) / segmentCount * clothoid.length;

		buw::vector2d objClPointInClCoSy(signX * CalculateXCoordinate(t, ClothoidConstantA), signY * CalculateYCoordinate(t, ClothoidConstantA));

		buw::matrix44d rotation = buw::createRotationZ44d(-dblBetweenAngleGlobalCoSyAndClothoidCoSy);
		objClPointInClCoSy = buw::transform(rotation, objClPointInClCoSy);

		v2 = clothoid.end + buw::vector2d(objClPointInClCoSy.x(), objClPointInClCoSy.y());
		drawLine(v1, v2);
	}
	drawLine(v2, clothoid.start);
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawClothideXYStartAngleIsInf(const clothoidDescription& clothoid)
{
	std::cout << "Start			:" << clothoid.start << std::endl;
	std::cout << "End			:" << clothoid.end << std::endl;
	std::cout << "PI			:" << clothoid.pi << std::endl;
	std::cout << "RadiusStart	:" << clothoid.radiusStart << std::endl;
	std::cout << "RadiusEnd 	:" << clothoid.radiusEnd << std::endl;

	double ClothoidConstantA = std::sqrt(clothoid.length * std::min(clothoid.radiusStart, clothoid.radiusEnd));

	double signX = 1;
	double signY = 1;

	if (clothoid.rotationOrder == eRotationOrder::CounterClockwise)			{ signX = 1; signY = -1; }
	else if (clothoid.rotationOrder == eRotationOrder::Clockwise)					{ signX = 1; signY = 1; }
	else throw std::exception("Unknown clothoid rotation");

	double dblBetweenAngleGlobalCoSyAndClothoidCoSy = CalculateClothoidCoSyRotationAngle(clothoid);

	int segmentCount = 500;

	buw::vector2d v1 = clothoid.start;
	buw::vector2d v2 = clothoid.start;

	for (int segmentIndex = 0; segmentIndex < segmentCount; segmentIndex++)
	{
		v1 = v2;

		double t = static_cast<float>(segmentIndex) / segmentCount * clothoid.length;

		buw::vector2d objClPointInClCoSy(signX * CalculateXCoordinate(t, ClothoidConstantA), signY * CalculateYCoordinate(t, ClothoidConstantA));

		buw::matrix44d rotation = buw::createRotationZ44d(-dblBetweenAngleGlobalCoSyAndClothoidCoSy);
		objClPointInClCoSy = buw::transform(rotation, objClPointInClCoSy);

		v2 = clothoid.start + buw::vector2d(objClPointInClCoSy.x(), objClPointInClCoSy.y());
		drawLine(v1, v2);
	}

	drawLine(v2, clothoid.end);
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawLineXZ(const BlueFramework::Core::Math::vector2d& start, const BlueFramework::Core::Math::vector2d& end)
{
	drawLine(
		buw::vector3d(start.x(), 0, start.y()),
		buw::vector3d(end.x(), 0, end.y())
		);
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawClothideXY(const clothoidDescription& clothoid)
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

		double t = static_cast<float>(segmentIndex) / segmentCount * clothoid.length;

		v2 = clothoid.start + buw::vector2d(CalculateXCoordinate(t), CalculateYCoordinate(t));
		setColor(1, 1, 0);
		drawLine(v1, v2);
	}

	//drawLine(v2, end);
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawArcXY(const BlueFramework::Core::Math::vector2d& center, const BlueFramework::Core::Math::vector2d& start, const BlueFramework::Core::Math::vector2d& end, const eRotationOrder order /*= eRotationOrder::CounterClockwise*/)
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

		float beta = static_cast<float>(segmentIndex) / segmentCount * alpha;

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

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawLineStrip(const buw::vector3d* list, const int vertexCount, const buw::vector3d& offset)
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

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawLineStrip(const buw::vector2d* list, const int vertexCount, const buw::vector2d& offset)
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

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawLineStrip(const buw::vector2d* list, const int vertexCount)
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

void OpenInfraPlatform::UserInterface::RoadDesignVCL::flushPickShader(const buw::vertexCacheLineShaderData& vcsd)
{
	pickShader_->setValue("ortho", vcsd.ortho);
	pickShader_->setValue("WorldViewProjection", vcsd.projection *  vcsd.view * vcsd.world);
	pickShader_->setValue("Viewport", vcsd.viewport);

	if (!vcsd.ortho)
	{
		pickShader_->setValue("Frustum", vcsd.frustum);
	}

	VertexCacheLineT::flush(pickShader_);
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::flush(const buw::vertexCacheLineShaderData& vcsd, int selected, int hovered)
{
	lineShader_->setValue("ortho", vcsd.ortho);
	lineShader_->setValue("WorldViewProjection", vcsd.projection *  vcsd.view * vcsd.world);
	lineShader_->setValue("Viewport", vcsd.viewport);
	lineShader_->setValue("selectedIndex", selected);
	lineShader_->setValue("hoveredIndex", hovered);

	if (!vcsd.ortho)
	{
		lineShader_->setValue("Frustum", vcsd.frustum);
	}

	VertexCacheLineT::flush(lineShader_);
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::setID(unsigned int id)
{
	id_ = id;
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::setWidth(float width)
{
	width_ = width;
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::setColor(float r, float g, float b)
{
	color_ = buw::color3f(r, g, b);
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::setColor(const buw::color3f& color)
{
	color_ = color;
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawLine(const buw::vector2d& start, const buw::vector2d& end)
{
	drawLine(buw::vector2f(start), buw::vector2f(end));
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawLine(const buw::vector3d& start, const buw::vector3d& end)
{
	drawLine(buw::vector3f(start), buw::vector3f(end));
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawLine(const buw::vector2f& start, const buw::vector2f& end)
{
	drawLine(buw::vector3f(start, 0), buw::vector3f(end, 0));
}

void OpenInfraPlatform::UserInterface::RoadDesignVCL::drawLine(const buw::vector3f& start, const buw::vector3f& end)
{
	buw::VertexPosition3Color3Size1ID1 s, e;
	s.position = start;
	s.color = buw::vector3f(&color_[0]);
	s.size = width_;
	s.id = id_;

	e.position = end;
	e.color = buw::vector3f(&color_[0]);
	e.size = width_;
	e.id = id_;

	VertexCacheLineT::drawLine(s, e);
}

OpenInfraPlatform::UserInterface::RoadDesignVCL::RoadDesignVCL(buw::ReferenceCounted<buw::IRenderSystem> renderer, const BlueFramework::Core::String& shaderFilename, const BlueFramework::Core::String& pickShaderFilename, const int size) :
base(renderer, size),
width_(1.5f),
color_(1.f, 0, 0)
{
	lineShader_ = renderer->createShader(shaderFilename);
	pickShader_ = renderer->createShader(pickShaderFilename);
	base::createLayoutandBuffer(lineShader_);
}
