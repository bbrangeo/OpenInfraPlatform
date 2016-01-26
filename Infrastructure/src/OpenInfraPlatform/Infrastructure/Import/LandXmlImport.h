/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_LandXmlParser_60c637f8_9478_44a4_bd52_cfa2ffa2dc4c_h
#define OpenInfraPlatform_Infrastructure_LandXmlParser_60c637f8_9478_44a4_bd52_cfa2ffa2dc4c_h

#include "OpenInfraPlatform/Infrastructure/Import/Import.h"
#include "OpenInfraPlatform/Infrastructure/Import/LandXMLBaseTypes.h"
#include "BlueFramework/Core/PropertySet.h"
#include <buw.BlueCore.Math.h>
#include "BlueFramework/Core/class.h"
#include <stack>
#include <map>

namespace OpenInfraPlatform
{	
	namespace Infrastructure
	{
		typedef int LandXMLPointIdType;

		struct BLUEINFRASTRUCTURE_API LandXMLSurfacePoint
		{
			LandXMLPointIdType	id;			// unique id referenced by faces
			buw::vector3d		position;
		};

		class BLUEINFRASTRUCTURE_API LandXMLSurface
		{
		public:
			LandXMLSurface()
			{

			}

			virtual ~LandXMLSurface()
			{

			}
			
			void addSurfacePoint(const LandXMLSurfacePoint& point)
			{
				points_.push_back(point);
				idToPosition_[point.id] = point.position;
			}

			const std::vector<LandXMLSurfacePoint>&		getPoints() const
			{
				return points_;
			}

			int											getPointCount() const
			{
				return static_cast<int>(points_.size());
			}

			const std::vector<buw::vector3i>&			getTriangeFaces() const
			{
				return triangeFaces_;
			}

			int											getTriangleCount() const
			{
				return static_cast<int>(triangeFaces_.size());
			}

			void setName(const char* str)
			{
				name_ = str;
			}

			const char* getName() const
			{
				return name_.c_str();
			}

			void addTriangle(const buw::vector3i& indices)
			{
				triangeFaces_.push_back(indices);
			}

			bool doesSurfacePointExist(const LandXMLPointIdType pointId) const
			{
				auto pos = idToPosition_.find(pointId);
				if (pos == idToPosition_.end())
				{
					return false;
				}
				else
				{
					return true;
				}
			}

			buw::vector3d getSurfacePointPositonById(const LandXMLPointIdType pointId) const
			{
				BLUE_ASSERT(doesSurfacePointExist(pointId));

				auto pos = idToPosition_.find(pointId);
				if (pos == idToPosition_.end())
				{
					return buw::vector3d(0.0, 0.0, 0.0);
				}
				else
				{
					return pos->second;
				}
			}

		private:
			std::vector<LandXMLSurfacePoint>		points_;
			std::vector<buw::vector3i>				triangeFaces_;
			std::string								name_;

			// faster access to positions
			std::map<LandXMLPointIdType, buw::vector3d>	idToPosition_;
		};

		class BLUEINFRASTRUCTURE_API LandXMLDataBuilder : boost::noncopyable
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(LandXMLDataBuilder);

			typedef buw::PropertySet PropertySet;

			LandXMLDataBuilder() {}

			virtual ~LandXMLDataBuilder() {}

			//! Create an empty alignment
			virtual void createAlignment(const PropertySet& /*parameters*/) {};

			//---------------------------------------------------------------------------//
			// Horizontal alignment
			//---------------------------------------------------------------------------//

			//! Create an empty horizontal alignment
			virtual void createCoordGeom() {};

			//! A LandXML horizontal line segment
			virtual void createLine(const PropertySet& /*parameters*/) {};

			//! A LandXML horizontal arc segment
			virtual void createCurve(const PropertySet& /*parameters*/) {};

			//! A LandXML horizontal spiral
			virtual void createSpiral(const PropertySet& /*parameters*/) {};

			//---------------------------------------------------------------------------//
			// Vertical alignment
			//---------------------------------------------------------------------------//

			//! Create an empty vertical alignment
			virtual void createProfAlign(const PropertySet& /*parameters*/) {};

			//! Create a vertical PVI point
			virtual void createPVI(const PropertySet& /*parameters*/) {};

			//! Create a vertical parabola segment
			virtual void createParaCurve(const PropertySet& /*parameters*/) {};

			//! Create a vertical arc segment
			virtual void createCircCurve(const PropertySet& /*parameters*/) {};

			//---------------------------------------------------------------------------//
			// Terrain
			//---------------------------------------------------------------------------//

			//! Create a surface element
			virtual void createSurface(const PropertySet& /*parameters*/, const LandXMLSurface& /*surface*/) {};

			//---------------------------------------------------------------------------//
			// Cross Sections
			//---------------------------------------------------------------------------//

			virtual void createCrossSectionSurf(const PropertySet& /*parameters*/) {};

			virtual void createDesignCrossSectSurf(const PropertySet& /*parameters*/) {};

			virtual void createCrossSectPnt(const PropertySet& /*parameters*/) {};
		}; // end class LandXMLDataBuilder

		class BLUEINFRASTRUCTURE_API LandXMLImportDirector
		{
		public:
			void setLandXMLDataBuilder(LandXMLDataBuilder* builder)
			{
				builder_ = builder;
			}

			virtual void construct() = 0;

		private:
			LandXMLDataBuilder* builder_;
		};

		BLUEINFRASTRUCTURE_API void constructLandXMLData(
			const std::string& filename,
			LandXMLDataBuilder* builder);

		BLUEINFRASTRUCTURE_API buw::ReferenceCounted<buw::VerticalAlignment2D> createVerticalAlignmentFromProfAlign(const std::vector<profAlignElement>& profAlignElements_);

		BLUEINFRASTRUCTURE_API std::vector<profAlignElement> createProfAlignElements(buw::ReferenceCounted<buw::VerticalAlignment2D> v);

		class BLUEINFRASTRUCTURE_API LandXmlImport : public Import
		{
		public:
			LandXmlImport(const std::string& filename);
		};
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::LandXMLDataBuilder;
	using OpenInfraPlatform::Infrastructure::eProfAlignType;
	using OpenInfraPlatform::Infrastructure::profAlignElement;
	using OpenInfraPlatform::Infrastructure::LandXmlImport;
	using OpenInfraPlatform::Infrastructure::createVerticalAlignmentFromProfAlign;
	using OpenInfraPlatform::Infrastructure::createProfAlignElements;
}

#endif // end define OpenInfraPlatform_Infrastructure_LandXmlParser_60c637f8_9478_44a4_bd52_cfa2ffa2dc4c_h
