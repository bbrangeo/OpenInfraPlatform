/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_Alignment2DBased3D_dda096bb_11f3_4705_ac2b_3166c5e4a580_h
#define OpenInfraPlatform_Infrastructure_Alignment2DBased3D_dda096bb_11f3_4705_ac2b_3166c5e4a580_h

#include "../CrossSection/CrossSectionStatic.h"
#include "IAlignment3D.h"
#include "buw.BlueCore.h"
#include "buw.BlueEngine.AxisAlignedBoundingBox.h"
#include <boost/noncopyable.hpp>
#include "HorizontalAlignment/HorizontalAlignment2D.h"
#include "VerticalAlignment/VerticalAlignment2D.h"
#include "../CrossSection/CrossSectionStatic.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		//! A 3d alignment based on 2d horizontal and a 2d vertical alignment. This object
		//! is used as a container object.
		class BLUEINFRASTRUCTURE_API Alignment2DBased3D : public IAlignment3D
		{
		public:				
			static Alignment2DBased3D* createFlatCopy(const Alignment2DBased3D& src);

			Alignment2DBased3D(buw::ReferenceCounted<HorizontalAlignment2D> horizontalAlignment = nullptr,
				buw::ReferenceCounted<VerticalAlignment2D> verticalAlignment = nullptr);

			virtual ~Alignment2DBased3D() {}

			//! Computes the 3d position given a stationing.
			buw::vector3d	getPosition(const buw::Stationing station ) const override;

			//! Start station of horizontal alignment
			Stationing		getStartStation() const override;

			Stationing		getEndStation() const override;

			//! Length of horizontal alignment
			double			getLength() const override;	

			//---------------------------------------------------------------------------//
			// Horizontal Alignment
			//---------------------------------------------------------------------------//

			bool						hasHorizontalAlignment() const;

			int							getHorizontalAlignmentElementCount();

			double						getHorizontalAlignmentLength() const;

			//! Computes the 2d position in the horizontal alignment given a stationing.
			buw::vector2d				getHorizontalPosition(const buw::Stationing station ) const;

			buw::ReferenceCounted<HorizontalAlignment2D>	getHorizontalAlignment() const;

			void						setHorizontalAlignment(buw::ReferenceCounted<buw::HorizontalAlignment2D> horizontalAlignment);

			//---------------------------------------------------------------------------//
			// Vertical Alignment
			//---------------------------------------------------------------------------//

			bool						hasVerticalAlignment() const;

			buw::vector2d				getVerticalPosition(const Stationing station ) const;

			buw::ReferenceCounted<VerticalAlignment2D>	getVerticalAlignment() const;

			void						setVerticalAlignment(buw::ReferenceCounted<VerticalAlignment2D> verticalAlignment);

			buw::AxisAlignedBoundingBox3d getVerticalAlignmentExtends() const;
			
			//---------------------------------------------------------------------------//
			// Cross Section
			//---------------------------------------------------------------------------//

			void						addCrossSection(buw::ReferenceCounted<buw::CrossSectionStatic> cs);
			void						sortCrossSectionsByStation();

			int								getCrossSectionCount();
			buw::ReferenceCounted<buw::CrossSectionStatic>	getCrossSection(const int index);

		private:
			std::vector<buw::ReferenceCounted<buw::CrossSectionStatic>>	crossSections_;
			buw::ReferenceCounted<HorizontalAlignment2D>				horizontalAlignment_;
			buw::ReferenceCounted<VerticalAlignment2D>					verticalAlignment_;
		};

		BLUEINFRASTRUCTURE_API buw::AxisAlignedBoundingBox3d getExtends(buw::ReferenceCounted<Alignment2DBased3D> alignment);
		BLUEINFRASTRUCTURE_API buw::AxisAlignedBoundingBox3d getExtends(std::vector<buw::ReferenceCounted<IAlignment3D>> alignments);
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::Alignment2DBased3D;
	using OpenInfraPlatform::Infrastructure::getExtends;
}

#endif // end define OpenInfraPlatform_Infrastructure_Alignment2DBased3D_dda096bb_11f3_4705_ac2b_3166c5e4a580_h
