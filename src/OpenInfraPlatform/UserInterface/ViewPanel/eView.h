/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_eView_b7fc0b5d_e69a_43ab_9197_79a8301f2c49_h
#define OpenInfraPlatform_UserInterface_eView_b7fc0b5d_e69a_43ab_9197_79a8301f2c49_h

#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		enum class eView
		{
			HorizontalAlignment,
			VerticalAlignment,
			ThreeDimensional
		};
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	//using OpenInfraPlatform::UserInterface::eView;
}

#endif // end define OpenInfraPlatform_UserInterface_eView_b7fc0b5d_e69a_43ab_9197_79a8301f2c49_h
