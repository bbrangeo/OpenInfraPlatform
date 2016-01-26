/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once

#include "OpenInfraPlatform/Infrastructure/Alignment/AlignmentModel.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/DigitalElevationModel.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{	
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API Import : private boost::noncopyable
		{
		public:
			Import(const std::string& filename);

			buw::ReferenceCounted<buw::AlignmentModel>			getAlignmentModel();
			buw::ReferenceCounted<buw::DigitalElevationModel>	getDigitalElevationModel();

		protected:
			std::string											filename_;
			buw::ReferenceCounted<buw::AlignmentModel>			alignmentModel_;
			buw::ReferenceCounted<buw::DigitalElevationModel>	digitalElevationModel_;
		};
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::Import;
}
