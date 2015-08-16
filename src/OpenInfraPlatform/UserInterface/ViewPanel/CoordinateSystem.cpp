/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CoordinateSystem.h"

void OpenInfraPlatform::UserInterface::drawCoordinateSystem(
	buw::VertexCacheLine::Ptr vertexCacheLine,
	float scale/* = 1.0f*/, 
	eCoordinateSystemType type/* = eCoordinateSystemType::Autodesk*/)
{
	// draw axes
	
	/// X
	// draw x-Axis 
	vertexCacheLine->setColor(153.0f / 255.0f, 30.0f / 255.0f, 30.0f / 255.0f); // red color
	vertexCacheLine->drawLine( buw::vector3f(-0.4f,0.0f,0.0f) * 100.0f * scale, buw::vector3f(0.4f,0.0f,0.0f) * 100.0f * scale);

	// draw arrowhead
	vertexCacheLine->drawLine( buw::vector3f(0.4f,0.0f,0.0f) * 100.0f * scale, buw::vector3f(0.375f,0.0f,0.025f) * 100.0f * scale);
	vertexCacheLine->drawLine( buw::vector3f(0.4f,0.0f,0.0f) * 100.0f * scale, buw::vector3f(0.375f,0.0f,-0.025f) * 100.0f * scale);

	// draw x character
	buw::vector3f offsetX(3.5, 0.0f, 0.0f);
	offsetX *= scale;

	vertexCacheLine->drawLine( offsetX + buw::vector3f(0.4f,0.0f,0.0f) * 100.0f * scale, offsetX + buw::vector3f(0.375f,0.0f,0.025f) * 100.0f * scale);
	vertexCacheLine->drawLine( offsetX + buw::vector3f(0.4f,0.0f,0.0f) * 100.0f * scale, offsetX + buw::vector3f(0.375f,0.0f,-0.025f) * 100.0f * scale);

	vertexCacheLine->drawLine( offsetX + buw::vector3f(0.4f,0.0f,0.0f) * 100.0f * scale, offsetX + buw::vector3f(2*(0.4f-0.375f) + 0.375f,0.0f,0.025f) * 100.0f * scale);
	vertexCacheLine->drawLine( offsetX + buw::vector3f(0.4f,0.0f,0.0f) * 100.0f * scale, offsetX + buw::vector3f(2*(0.4f-0.375f) + 0.375f,0.0f,-0.025f) * 100.0f * scale);

	/// Y

	// draw y-Axis
	vertexCacheLine->setColor(30.0f / 255.0f, 153.0f / 255.0f, 30.0f / 255.0f);  // green color
	vertexCacheLine->drawLine( buw::vector3f(0.0f,-0.4f,0.0f) * 100.0f * scale, buw::vector3f(0.0f,0.4f,0.0f) * 100.0f * scale);

	// draw arrowhead
	vertexCacheLine->drawLine( buw::vector3f(0.0f,0.4f,0.0f) * 100.0f * scale, buw::vector3f(0.0f,0.375f,0.025f) * 100.0f * scale);
	vertexCacheLine->drawLine( buw::vector3f(0.0f,0.4f,0.0f) * 100.0f * scale, buw::vector3f(0.0f,0.375f,-0.025f) * 100.0f * scale);

	buw::vector3f offsetY(0.0, 3.5f, 0.0f);
	offsetY *= scale;
	
	if(type == eCoordinateSystemType::OpenGL)
	{
		// draw y character
		vertexCacheLine->drawLine(offsetY + buw::vector3f(0.0f,0.375f,0.0f) * 100.0f * scale,offsetY + buw::vector3f(0.0f,0.400f,0.0f) * 100.0f * scale);
		vertexCacheLine->drawLine(offsetY + buw::vector3f(0.0f,0.400f,0.0f) * 100.0f * scale,offsetY + buw::vector3f(0.0f,0.425f,0.025f) * 100.0f * scale);
		vertexCacheLine->drawLine(offsetY + buw::vector3f(0.0f,0.400f,0.0f) * 100.0f * scale,offsetY + buw::vector3f(0.0f,0.425f,-0.025f) * 100.0f * scale);
	}
	else // type == eCoordinateSystemType::Autodesk
	{
		// draw z character
		vertexCacheLine->drawLine(offsetY + buw::vector3f(0.0f,0.375f,-0.025f) * 100.0f * scale,offsetY + buw::vector3f(0.0f,0.375f,0.025f) * 100.0f * scale);
		vertexCacheLine->drawLine(offsetY + buw::vector3f(0.0f,0.425f,-0.025f) * 100.0f * scale,offsetY + buw::vector3f(0.0f,0.375f,0.025f) * 100.0f * scale);
		vertexCacheLine->drawLine(offsetY + buw::vector3f(0.0f,0.425f,-0.025f) * 100.0f * scale,offsetY + buw::vector3f(0.0f,0.425f,0.025f) * 100.0f * scale);
	}

	/// Z

	buw::vector3f offsetZ(0.0, 0.0f, -3.5f);
	offsetZ *= scale;

	// draw z-Axis
	vertexCacheLine->setColor(30.0f / 255.0f, 30.0f / 255.0f, 153.0f / 255.0f); // blue color
	vertexCacheLine->drawLine( buw::vector3f(0.0f,0.0f,-0.4f) * 100.0f * scale, buw::vector3f(0.0f,0.0f,0.4f) * 100.0f * scale);

	// draw arrowhead
	vertexCacheLine->drawLine( buw::vector3f(0.0f,0.0f,-0.4f) * 100.0f * scale, buw::vector3f( 0.025f, 0.0f,-0.375f) * 100.0f * scale);
	vertexCacheLine->drawLine( buw::vector3f(0.0f,0.0f,-0.4f) * 100.0f * scale, buw::vector3f(-0.025f,0.0f,-0.375f) * 100.0f * scale);

	if(type == eCoordinateSystemType::OpenGL)
	{
		// draw z character
		vertexCacheLine->drawLine( offsetZ + buw::vector3f(-0.025f,0.0f,-0.375f) * 100.0f * scale, offsetZ + buw::vector3f(0.025f,0.0f,-0.425f) * 100.0f * scale);
		vertexCacheLine->drawLine( offsetZ + buw::vector3f(-0.025f,0.0f,-0.425f) * 100.0f * scale, offsetZ + buw::vector3f(0.025f,0.0f,-0.425f) * 100.0f * scale);
		vertexCacheLine->drawLine( offsetZ + buw::vector3f(-0.025f,0.0f,-0.375f) * 100.0f * scale, offsetZ + buw::vector3f(0.025f,0.0f,-0.375f) * 100.0f * scale);
	}
	else // type == eCoordinateSystemType::Autodesk
	{
		//	draw y character
		vertexCacheLine->drawLine( offsetZ + buw::vector3f(0.0f,0.0f,-0.4f) * 100.0f * scale, offsetZ + buw::vector3f( 0.025f,0.0f, -0.375f - 2*0.025) * 100.0f * scale);
		vertexCacheLine->drawLine( offsetZ + buw::vector3f(0.0f,0.0f,-0.4f) * 100.0f * scale, offsetZ + buw::vector3f(-0.025f,0.0f, -0.375f - 2*0.025) * 100.0f * scale);
		vertexCacheLine->drawLine( offsetZ + buw::vector3f(0.0f,0.0f,-0.4f + 0.025) * 100.0f * scale, offsetZ + buw::vector3f(0.0f,0.0f,-0.4f) * 100.0f * scale);
	}
}

void OpenInfraPlatform::UserInterface::drawGrid( 
	buw::VertexCacheLine::Ptr vertexCacheLine,
	const buw::drawGridDescription& dgd )
{
	float fPGridRed = 61.0f/255.0f;
	float fPGridGreen = 61.0f/255.0f;
	float fPGridBlue = 61.0f/255.0f;

	float fSGridRed = 99.0f/255.0f;
	float fSGridGreen = 99.0f/255.0f;
	float fSGridBlue = 99.0f/255.0f;
	/*

		TopLeft               TopRight
		+---------+---------+
		|         |         |
		|         |         |
		|         |         |
		|         |         |
		|---------+---------|
		|         |         |
		|         |         |
		|         |         |
		+---------+---------+
		BottomLeft            BottomRight
	*/

	float segementWidth = dgd.width / dgd.widthSegments;
	float segementHeight = dgd.height / dgd.widthSegments;

	buw::vector3f bottomLeft;
	buw::vector3f bottomRight;
	buw::vector3f topLeft;
	buw::vector3f topRight;
				
	buw::vector3f incrementalWidthStep;
	buw::vector3f incrementalHeightStep;

	switch (dgd.orientation)
	{
	case eGridOrientation::POSITIV_Z_ORIENTATION:
 		topLeft = dgd.center + buw::vector3f(-dgd.width/2.0f, dgd.height/2.0f, 0.0f);
		bottomLeft = dgd.center + buw::vector3f(-dgd.width/2.0f, -dgd.height/2.0f, 0.0f);
		topRight = dgd.center + buw::vector3f(dgd.width/2.0f, dgd.height/2.0f, 0.0f);
		bottomRight = dgd.center + buw::vector3f(dgd.width/2.0f, -dgd.height/2.0f, 0.0f);
		incrementalWidthStep = buw::vector3f(segementWidth, 0.0f, 0.0f);
		incrementalHeightStep = buw::vector3f(0.0f, -segementHeight, 0.0f);
		break;

	case eGridOrientation::POSITIV_Y_ORIENTATION:
		topLeft = dgd.center + buw::vector3f(-dgd.width/2.0f, 0.0f, dgd.height/2.0f);
		bottomLeft = dgd.center + buw::vector3f(-dgd.width/2.0f, 0.0f, -dgd.height/2.0f);
		topRight = dgd.center + buw::vector3f(dgd.width/2.0f, 0.0f,  dgd.height/2.0f);
		bottomRight = dgd.center + buw::vector3f(dgd.width/2.0f, 0.0f, -dgd.height/2.0f);
		incrementalWidthStep = buw::vector3f(segementWidth, 0.0f, 0.0f);
		incrementalHeightStep = buw::vector3f(0.0f, 0.0f, -segementHeight);
		break;

	case eGridOrientation::POSITIV_X_ORIENTATION:
		topLeft = dgd.center + buw::vector3f(0.0f, dgd.height/2.0f, -dgd.width/2.0f);
		bottomLeft = dgd.center + buw::vector3f(0.0f, -dgd.height/2.0f, -dgd.width/2.0f);
		topRight = dgd.center + buw::vector3f(0.0f,  dgd.height/2.0f, dgd.width/2.0f);
		bottomRight = dgd.center + buw::vector3f(0.0f, -dgd.height/2.0f, dgd.width/2.0f);
		incrementalWidthStep = buw::vector3f(0.0f, 0.0f, segementWidth);
		incrementalHeightStep = buw::vector3f(0.0f, -segementHeight, 0.0f);
		break;

	default:
		break;
	};

					
	// draw height/horizontal lines - run from leftTop to rightTop
	buw::vector3f currentPositionLeftTop = topLeft;
	buw::vector3f currentPositionRightTop = topRight;
	for (int iRows = 0; iRows < dgd.widthSegments+1; iRows++)
	{
		if(iRows == 20 && dgd.leaveCoodinateSystemBlank) // special treatment for middle lines
		{
			vertexCacheLine->setColor(fPGridRed, fPGridGreen, fPGridBlue);

			buw::vector3f ir = currentPositionLeftTop + 0.4f * (currentPositionRightTop - currentPositionLeftTop);

			vertexCacheLine->drawLine(
				buw::vector3f(currentPositionLeftTop.x(), currentPositionLeftTop.y(), currentPositionLeftTop.z()),
				buw::vector3f(ir .x(), ir.y(), ir.z())
			);

			ir = currentPositionLeftTop + 0.6f * (currentPositionRightTop - currentPositionLeftTop);

			vertexCacheLine->drawLine(
				buw::vector3f(ir .x(), ir.y(), ir.z()),
				buw::vector3f(currentPositionRightTop.x(), currentPositionRightTop.y(), currentPositionRightTop.z())
			);
					
			currentPositionLeftTop += incrementalHeightStep;
			currentPositionRightTop += incrementalHeightStep;
			continue;
		}

		if((iRows % 5) == 0)
			vertexCacheLine->setColor(fPGridRed, fPGridGreen, fPGridBlue);
		else
			vertexCacheLine->setColor(fSGridRed, fSGridGreen, fSGridBlue);
				
		vertexCacheLine->drawLine(
			buw::vector3f(currentPositionLeftTop.x(), currentPositionLeftTop.y(), currentPositionLeftTop.z()),
			buw::vector3f(currentPositionRightTop.x(), currentPositionRightTop.y(), currentPositionRightTop.z())
		);
				
		currentPositionLeftTop += incrementalHeightStep;
		currentPositionRightTop += incrementalHeightStep;
	}

	// draw width/vertical lines - run from leftTop to leftBottom
	buw::vector3f currentPositionTop = topLeft;
	buw::vector3f currentPositionBottom = bottomLeft;
	for (int iCols = 0; iCols < dgd.widthSegments+1; iCols++)
	{
		if(iCols == 20 && dgd.leaveCoodinateSystemBlank) // special treatment for middle lines
		{
			vertexCacheLine->setColor(fPGridRed, fPGridGreen, fPGridBlue);

			buw::vector3f ir = currentPositionTop + 0.4f * (currentPositionBottom - currentPositionTop);

			vertexCacheLine->drawLine(
				buw::vector3f(currentPositionTop.x(), currentPositionTop.y(), currentPositionTop.z()),
				buw::vector3f(ir .x(), ir.y(), ir.z())
			);

			ir = currentPositionTop + 0.6f * (currentPositionBottom - currentPositionTop);

			vertexCacheLine->drawLine(
				buw::vector3f(ir .x(), ir.y(), ir.z()),
				buw::vector3f(currentPositionBottom.x(), currentPositionBottom.y(), currentPositionBottom.z())
			);
						

			currentPositionTop += incrementalWidthStep;
			currentPositionBottom += incrementalWidthStep;
			continue;
		}

		if((iCols % 5) == 0)
			vertexCacheLine->setColor(fPGridRed, fPGridGreen, fPGridBlue);
		else
			vertexCacheLine->setColor(fSGridRed, fSGridGreen, fSGridBlue);
					
		vertexCacheLine->drawLine(
			buw::vector3f(currentPositionTop.x(), currentPositionTop.y(), currentPositionTop.z()),
			buw::vector3f(currentPositionBottom.x(), currentPositionBottom.y(), currentPositionBottom.z())
		);

		currentPositionTop += incrementalWidthStep;
		currentPositionBottom += incrementalWidthStep;
	}
}