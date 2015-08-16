/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

// see also: http://tirania.org/blog/archive/2011/Dec-19.html

#include "CSharpWrapper.h"

#include "OpenInfraPlatform/Infrastructure/Import/LandXmlImport.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DLine.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DClothoid.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/DigitalElevationModel.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/AlignmentModel.h"

extern "C" 
{
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// LandXml Parser
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	BLUEINFRASTRUCTURE_API buw::LandXmlImport* LandXmlParser_Create(char* fileName)
	{
		buw::LandXmlImport parser(fileName);
		buw::LandXmlImport *p = buw::LandXmlImport::createFlatCopy(parser);
		return p;
	}

	BLUEINFRASTRUCTURE_API buw::DigitalElevationModel* LandXmlParser_GetDigitalElevationModel(buw::LandXmlImport* p)
	{
		buw::DigitalElevationModel* digitalElevationModel = p->getDigitalElevationModel();
		buw::DigitalElevationModel *dm = buw::DigitalElevationModel::createFlatCopy(*digitalElevationModel);
		return dm;
	}

	BLUEINFRASTRUCTURE_API buw::AlignmentModel* LandXmlParser_GetAlignmentModel(buw::LandXmlImport* p)
	{
		buw::AlignmentModel* alignmentModel = p->getAlignmentModel();
		buw::AlignmentModel *a = buw::AlignmentModel::createFlatCopy(*alignmentModel);
		return a;
	}

	BLUEINFRASTRUCTURE_API buw::vector3d LandXmlParser_GetModelCenter(buw::LandXmlImport* p)
	{
		buw::vector3d minPos;
		buw::vector3d maxPos;

		buw::DigitalElevationModel* digitalElevationModel = LandXmlParser_GetDigitalElevationModel(p);
		buw::AlignmentModel* alignmentModel = LandXmlParser_GetAlignmentModel(p);

		digitalElevationModel->getSurfacesExtend(minPos, maxPos);

		if (alignmentModel->getAlignmentCount() > 0)
		{
			auto aabb = alignmentModel->getExtends();

			if (digitalElevationModel->getSurfaceCount() > 0)
			{
				minPos = getMinimizedVector(minPos, aabb.getMinimum());
				maxPos = getMinimizedVector(maxPos, aabb.getMaximum());
			}
			else
			{
				minPos = aabb.getMinimum();
				maxPos = aabb.getMaximum();
			}
		}

		buw::vector3d offsetViewArea = minPos + 0.5 * (maxPos - minPos);

		return offsetViewArea;
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// AlignmentModel
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	BLUEINFRASTRUCTURE_API int AlignmentModel_AlignmentsCount(buw::AlignmentModel* a)
	{
		return a->getAlignmentCount();
	}

	BLUEINFRASTRUCTURE_API buw::Alignment2DBased3D* AlignmentModel_GetAlignmentByIndex(buw::AlignmentModel* a, int index)
	{
		buw::IAlignment3D::Ptr alignment3d = a->getAlignments()[index];

		if (alignment3d->getType() == buw::e3DAlignmentType::e2DBased)
		{
			buw::Alignment2DBased3D::Ptr a = std::static_pointer_cast<buw::Alignment2DBased3D>(alignment3d);

			buw::Alignment2DBased3D *ap = buw::Alignment2DBased3D::createFlatCopy(*a.get());

			return ap;
		}

		return nullptr;
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// DigitalElevationModel
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	BLUEINFRASTRUCTURE_API int DigitalElevationModel_SurfaceCount(buw::DigitalElevationModel* d)
	{
		return d->getSurfaceCount();
	}

	BLUEINFRASTRUCTURE_API buw::Surface* DigitalElevationModel_GetSurface(buw::DigitalElevationModel* d, int index)
	{
		buw::Surface::Ptr surface = d->getSurface(index);
		buw::Surface *s = buw::Surface::createFlatCopy(*surface.get());

		return s;
	}

	BLUEINFRASTRUCTURE_API double DigitalElevationModel_getHeightAtPosition(buw::DigitalElevationModel* d, double x, double y)
	{
		return d->getHeightAtPosition(buw::vector2d(x, y));
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// Surface
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	BLUEINFRASTRUCTURE_API int Surface_GetPointsCount(buw::Surface* s)
	{
		return s->getPointCount();
	}

	BLUEINFRASTRUCTURE_API int Surface_GetFaceCount(buw::Surface* s)
	{
		return s->getTriangleCount();
	}

	BLUEINFRASTRUCTURE_API buw::vector3d Surface_GetPoint(buw::Surface* s, int index)
	{
		return s->getPoints()[index];
	}

	BLUEINFRASTRUCTURE_API buw::vector3d Surface_GetFace(buw::Surface* s, int index)
	{
		return buw::vector3d(
			s->getTriangeFaces()[index][0], 
			s->getTriangeFaces()[index][1], 
			s->getTriangeFaces()[index][2]
		);
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// Alignment
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	BLUEINFRASTRUCTURE_API buw::Alignment2DBased3D* Alignment2DBased3D_Create()
	{
		buw::LandXmlImport parser("C:/Users/Dominic/Desktop/Studium/MA4/Master-Thesis/Implementierung/OpenInfraPlatform/testdata/LandXML/Mainbruecke_Klingenberg.xml");

		buw::IAlignment3D::Ptr alignment3d = parser.getAlignments()[0];
		
		if (alignment3d->getType() == buw::e3DAlignmentType::e2DBased)
		{
			buw::Alignment2DBased3D::Ptr a = std::static_pointer_cast<buw::Alignment2DBased3D>(alignment3d);

			buw::Alignment2DBased3D *ap = buw::Alignment2DBased3D::createFlatCopy(*a.get());
		
			return ap;
		}

		return nullptr;
	}

	BLUEINFRASTRUCTURE_API void Alignment2DBased3D_Destroy(buw::Alignment2DBased3D* a)
	{
		delete a;
	}

	BLUEINFRASTRUCTURE_API double Alignment2DBased3D_getStartStation(buw::Alignment2DBased3D* a)
	{
		return a->getStartStation();
	}

	BLUEINFRASTRUCTURE_API double Alignment2DBased3D_getEndStation(buw::Alignment2DBased3D* a)
	{
		return a->getEndStation();
	}

	BLUEINFRASTRUCTURE_API buw::vector3d Alignment2DBased3D_getPosition(buw::Alignment2DBased3D* a, double station)
	{
		
		return a->getPosition(station);
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// HorizontalAlignmentElement2DLine
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	BLUEINFRASTRUCTURE_API buw::HorizontalAlignmentElement2DLine* HorizontalAlignmentElement2DLine_Create()
	{
		buw::vector2d start(0, 0);
		buw::vector2d endP(1, 0);

		buw::HorizontalAlignmentElement2DLine* line = new buw::HorizontalAlignmentElement2DLine(start, endP);

		return line;
	}

	BLUEINFRASTRUCTURE_API void HorizontalAlignmentElement2DLine_Destroy(buw::HorizontalAlignmentElement2DLine *p)
	{
		delete p;
	}

	BLUEINFRASTRUCTURE_API double HorizontalAlignmentElement2DLine_getLength(buw::HorizontalAlignmentElement2DLine *p)
	{
		return p->getLength();
	}

	BLUEINFRASTRUCTURE_API buw::vector2d HorizontalAlignmentElement2DLine_getPositon(buw::HorizontalAlignmentElement2DLine *p, double lerpParameter)
	{
		return p->getPosition(lerpParameter);
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// HorizontalAlignmentElement2DClothoid
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	BLUEINFRASTRUCTURE_API buw::HorizontalAlignmentElement2DClothoid* HorizontalAlignmentElement2DClothoid_Create()
	{ 
		buw::vector2d start = buw::vector2d(861.369007, 537.722476);
		buw::vector2d end	= buw::vector2d(930.775243, 503.483954);
		buw::vector2d pi	= buw::vector2d(896.290146, 516.54507);
		
		double length		= 77.500241;
		double radiusStart	= 500;
		double radiusEnd	= 367;
		bool clockwise		= false;

		/*<Spiral length="77.500241" radiusEnd="367.000000" radiusStart="500.000000" rot="ccw" spiType="clothoid" constant="326.996979" dirEnd="4.3503375925" dirStart="4.1672511921" theta="0.1830864004" totalY="7.435685" totalX="-77.033840" staStart="628.971429" tanLong="40.840770" tanShort="36.875665">
			<Start>5333537.722476 4467861.369007</Start>
			<PI>5333516.54507 4467896.290146</PI>
			<End>5333503.483954 </End>
			</Spiral>*/

		double startCurvature = 0;
		if (radiusStart != 0 || radiusStart != std::numeric_limits<double>::infinity())
			startCurvature = 1 / radiusStart;

		double endCurvature = 0;
		if (radiusEnd != 0 || radiusEnd != std::numeric_limits<double>::infinity())
			endCurvature = 1 / radiusEnd;

		double startDirection = buw::HorizontalAlignmentElement2DClothoid::computeStartDirection(start, pi);
		double clothoidConstant = buw::HorizontalAlignmentElement2DClothoid::computeClothoidConstant(length, startCurvature, endCurvature);
		bool entry = buw::HorizontalAlignmentElement2DClothoid::computeEntry(startCurvature, endCurvature);

		buw::HorizontalAlignmentElement2DClothoid* clothoid = new buw::HorizontalAlignmentElement2DClothoid(start, startDirection, startCurvature, !clockwise, clothoidConstant, entry, length);

		return clothoid; 
	}

	BLUEINFRASTRUCTURE_API void HorizontalAlignmentElement2DClothoid_Destroy(buw::HorizontalAlignmentElement2DClothoid *p)
	{ 
		delete p; 
	}

	BLUEINFRASTRUCTURE_API buw::vector2d HorizontalAlignmentElement2DClothoid_getPosition(buw::HorizontalAlignmentElement2DClothoid *p, double lerpParameter)
	{
		return p->getPosition(lerpParameter);
	}

	BLUEINFRASTRUCTURE_API double HorizontalAlignmentElement2DClothoid_getLength(buw::HorizontalAlignmentElement2DClothoid *p)
	{
		return p->getLength();
	}
}; // end extern "C"
