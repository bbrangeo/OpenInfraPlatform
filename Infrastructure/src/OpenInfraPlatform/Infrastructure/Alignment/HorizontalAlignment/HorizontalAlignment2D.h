/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_HorizontalAlignment2D_fad49764_c3d4_45f4_8be4_8a6465f85631_h
#define OpenInfraPlatform_Infrastructure_HorizontalAlignment2D_fad49764_c3d4_45f4_8be4_8a6465f85631_h

#include "../types.h"
#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "HorizontalAlignmentElement2D.h"
#include "buw.BlueCore.class.h"
#include "buw.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		//! A connected line that describes a 2d alignment. 
		class BLUEINFRASTRUCTURE_API HorizontalAlignment2D
		{
		public:
			HorizontalAlignment2D(const Stationing startStationing = 0.0);

			//! Computes the 2d position in the horizontal alignment given a stationing.
			buw::vector2d getPosition(const Stationing station) const;

			int getAlignmentElementCount() const;

			//! Computes the length of the horizontal alignment
			double getLength() const;
			
			buw::ReferenceCounted<HorizontalAlignmentElement2D> getAlignmentElementByIndex(int index);

			//! Add an horizontal alignment segment.
			void addElement(buw::ReferenceCounted<HorizontalAlignmentElement2D> he);

			//! Start stationing of nth horizontal alignment element
			Stationing getStartStation(const int index = 0) const;

			//! End station of last horizontal alignment segment.
			Stationing getEndStation() const;

			//! station is assumed to be between [0;getLength]
			buw::ReferenceCounted<HorizontalAlignmentElement2D> getAlignmentElementByStationing(
				const Stationing station, 
				double* lerpParameter = nullptr) const;

			bool hasSuccessor(buw::ReferenceCounted<HorizontalAlignmentElement2D> element);

			//! Get the successor element if it exists, otherwise nullptr.
			buw::ReferenceCounted<HorizontalAlignmentElement2D> getSuccessor(buw::ReferenceCounted<HorizontalAlignmentElement2D> element);

		private:
			Stationing																startStationing_;
			std::vector<buw::ReferenceCounted<HorizontalAlignmentElement2D>>		horizontalElements_;	// the order of the elements is important here
		};
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::HorizontalAlignment2D;
}

#endif // end define OpenInfraPlatform_Infrastructure_HorizontalAlignment2D_fad49764_c3d4_45f4_8be4_8a6465f85631_h