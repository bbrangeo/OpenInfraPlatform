/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universit�t M�nchen
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_IfcRoadStepFileWriter_h
#define OpenInfraPlatform_Infrastructure_IfcRoadStepFileWriter_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/DigitalElevationModel.h"

#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>
#include <vector>
#include <memory>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		struct IfcRoadExportDescription
		{
			bool exportTerrain = true;
			bool exportAlignment = true;
			bool useRadiansInsteadOfDegrees = true;
		};

		class BLUEINFRASTRUCTURE_API IfcRoadExport : private boost::noncopyable
		{
		public:
			
			BLUE_DEFINE_SHARED_POINTER(IfcRoadExport);

			//! Default constructor.
			IfcRoadExport();

			//! Virtual destructor.
			virtual ~IfcRoadExport();
			
			void convert(const IfcRoadExportDescription& desc, 
				buw::DigitalElevationModel::Ptr dem,
				std::vector<buw::IAlignment3D::Ptr> alignments, 
				const std::string& filename);

		private:
			class IfcRoadExportImpl;					// Forward declaration of internal class
			std::shared_ptr<IfcRoadExportImpl> impl_;	// Opaque pointer to implementation
		}; // end class IfcAlignmenBuildingSmartP6StepFileWriter
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::IfcRoadExport;
	using OpenInfraPlatform::Infrastructure::IfcRoadExportDescription;
}

#endif // end define OpenInfraPlatform_Infrastructure_IfcRoadStepFileWriter_h
