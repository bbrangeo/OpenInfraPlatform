/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_VerticalAlignment2D_6e6b8d09_8c39_42b0_ac49_9cf8e13ca522_h
#define OpenInfraPlatform_Infrastructure_VerticalAlignment2D_6e6b8d09_8c39_42b0_ac49_9cf8e13ca522_h

#include <buw.BlueCore.class.h>
#include <buw.BlueCore.Math.h>
#include <buw.Bluecore.assert.h>
#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "VerticalAlignmentElement2D.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API VerticalAlignment2D : boost::noncopyable
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(VerticalAlignment2D)

			//! Computes the 2d position in the horizontal alignment given a stationing.
			buw::vector2d							getPosition(const Stationing station) const;

			int										getAlignmentElementCount() const;

			VerticalAlignmentElement2D::ConstPtr	getAlignmentElementByIndex(int index);

			Stationing								getStartStation() const;

			Stationing								getEndStation() const;

			void									addElement(VerticalAlignmentElement2D::Ptr ve);

			VerticalAlignmentElement2D::Ptr			getAlignmentElementByStationing(const Stationing station) const;

			bool									hasElements() const;

		private:
			std::vector<VerticalAlignmentElement2D::Ptr>		verticalElements_;	// the order of the elements is important here
		};
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::VerticalAlignment2D;
}

#endif // end define OpenInfraPlatform_Infrastructure_VerticalAlignment2D_6e6b8d09_8c39_42b0_ac49_9cf8e13ca522_h
