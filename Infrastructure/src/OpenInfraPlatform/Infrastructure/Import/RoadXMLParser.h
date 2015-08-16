/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_RoadXMLParser_70745c8f_e75e_40d8_94a8_ae27429bd59d_h
#define OpenInfraPlatform_RoadXMLParser_70745c8f_e75e_40d8_94a8_ae27429bd59d_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"
#include <buw.BlueCore.h>
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
	
		class BLUEINFRASTRUCTURE_API RoadXMLParser
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(RoadXMLParser);

			RoadXMLParser(const std::string& filename);

			std::vector<buw::Alignment2DBased3D::Ptr> getAlignments();

			int	getAlignmentCount();

		private:
			std::vector<buw::Alignment2DBased3D::Ptr> alignments_;
		};
	}

} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::RoadXMLParser;
}

#endif // end define OpenInfraPlatform_RoadXMLParser_70745c8f_e75e_40d8_94a8_ae27429bd59d_h
