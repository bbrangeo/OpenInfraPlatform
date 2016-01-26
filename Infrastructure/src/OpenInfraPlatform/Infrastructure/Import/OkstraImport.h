/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_OkstraImport_10fa5edb_cffa_4650_b56c_4ff3c1851c8d_h
#define OpenInfraPlatform_Infrastructure_OkstraImport_10fa5edb_cffa_4650_b56c_4ff3c1851c8d_h

#include "OpenInfraPlatform/Infrastructure/Import/Import.h"

#include <buw.BlueCore.h>
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API OkstraImport : public Import
		{
		public:
			//! Default constructor.
			OkstraImport(const std::string& filename);

		private:
			class OkstraImportImpl;						// Forward declaration of internal class
			std::shared_ptr<OkstraImportImpl> impl_;	// Opaque pointer to implementation
		}; // end class OkstraImport

	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::OkstraImport;
}

#endif // end define OpenInfraPlatform_Infrastructure_OkstraImport_10fa5edb_cffa_4650_b56c_4ff3c1851c8d_h
