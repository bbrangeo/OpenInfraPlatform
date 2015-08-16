/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_IfcAlignmentImport_793bf9e2_b78a_4b91_9fbf_7fe73a844d9f_h
#define OpenInfraPlatform_Infrastructure_IfcAlignmentImport_793bf9e2_b78a_4b91_9fbf_7fe73a844d9f_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment3DBased3D.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/surface.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API IfcAlignmentImport : private boost::noncopyable
		{
		public:
			//! Default constructor.
			IfcAlignmentImport(const std::string& filename);

			//! Virtual destructor.
			virtual ~IfcAlignmentImport();

			int	getAlignmentCount() const;
			int	getAlignmentCount3D() const;

			std::vector<buw::Alignment2DBased3D::Ptr> getAlignments();
			std::vector<buw::Alignment3DBased3D::Ptr> getAlignments3D();

			std::vector<buw::Surface::Ptr>	getSurfaces();

			int							getSurfaceCount();

		private:
			class IfcAlignmenImportImpl;						// Forward declaration of internal class
			std::shared_ptr<IfcAlignmenImportImpl> impl_;	// Opaque pointer to implementation
		}; // end class IfcAlignmentImport
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::IfcAlignmentImport;
}

#endif // end define OpenInfraPlatform_Infrastructure_IfcAlignmentImport_793bf9e2_b78a_4b91_9fbf_7fe73a844d9f_h
