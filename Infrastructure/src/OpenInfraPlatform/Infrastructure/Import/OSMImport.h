/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_OSMImport_cb390352_9e34_4971_a173_eab046fe8eec_h
#define OpenInfraPlatform_Infrastructure_OSMImport_cb390352_9e34_4971_a173_eab046fe8eec_h

#include "OpenInfraPlatform/Infrastructure/Import/Import.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API OSMImport : public Import
		{
		public:
			OSMImport(const std::string& filename);
			OSMImport(const std::string& filename, const std::vector<std::string>& filter, int mode);
			
			static std::vector<std::string> getDefaultFilter();
			static std::vector<std::string> getModeNames();
		}; // end class OSMImport
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::OSMImport;
}

#endif // end define OpenInfraPlatform_Infrastructure_OSMImport_cb390352_9e34_4971_a173_eab046fe8eec_h
