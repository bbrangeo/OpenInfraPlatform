/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_IfcRoadImport_793bf9e2_b78a_4b91_9fbf_7fe73a844d9f_h
#define OpenInfraPlatform_Infrastructure_IfcRoadImport_793bf9e2_b78a_4b91_9fbf_7fe73a844d9f_h

#include "OpenInfraPlatform/Infrastructure/Import/Import.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API IfcRoadImport : public Import
		{
		public:
			//! Default constructor.
			IfcRoadImport(const std::string& filename);

		private:
			class IfcRoadImportImpl;					// Forward declaration of internal class
			std::shared_ptr<IfcRoadImportImpl> impl_;	// Opaque pointer to implementation
		}; // end class IfcRoadImport
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::IfcRoadImport;
}

#endif // end define OpenInfraPlatform_Infrastructure_IfcRoadImport_793bf9e2_b78a_4b91_9fbf_7fe73a844d9f_h
