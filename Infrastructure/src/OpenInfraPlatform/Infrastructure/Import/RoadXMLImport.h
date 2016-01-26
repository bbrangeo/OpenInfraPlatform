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

#include "OpenInfraPlatform/Infrastructure/Import/Import.h"
#include <buw.BlueCore.h>
#include <buw.h>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API RoadXMLImport : public Import
		{
		public:
			RoadXMLImport(const std::string& filename);
		};
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::RoadXMLImport;
}

#endif // end define OpenInfraPlatform_RoadXMLParser_70745c8f_e75e_40d8_94a8_ae27429bd59d_h
