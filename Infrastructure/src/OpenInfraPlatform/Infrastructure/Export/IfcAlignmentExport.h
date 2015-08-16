/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_IfcAlignmenBuildingSmartP6StepFileWriter_85a9dc90_3db8_49d4_a197_2ac34a429c2f_h
#define OpenInfraPlatform_Infrastructure_IfcAlignmenBuildingSmartP6StepFileWriter_85a9dc90_3db8_49d4_a197_2ac34a429c2f_h

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
		struct ifcAlignmentExportDescription
		{
			bool exportTerrain = true;
			bool exportAlignment = true;
			bool useRadiansInsteadOfDegrees = true;
		};

		class BLUEINFRASTRUCTURE_API IfcAlignmentExport : private boost::noncopyable
		{
		public:
			
			BLUE_DEFINE_SHARED_POINTER(IfcAlignmentExport);

			//! Default constructor.
			IfcAlignmentExport();

			//! Virtual destructor.
			virtual ~IfcAlignmentExport();
			
			void convert(const ifcAlignmentExportDescription& desc, 
				buw::DigitalElevationModel::Ptr dem,
				std::vector<buw::IAlignment3D::Ptr> alignments, 
				const std::string& filename);

		private:
			class IfcAlignmentP6ExportImpl;						// Forward declaration of internal class
			std::shared_ptr<IfcAlignmentP6ExportImpl> impl_;	// Opaque pointer to implementation
		}; // end class IfcAlignmenBuildingSmartP6StepFileWriter
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::IfcAlignmentExport;
	using OpenInfraPlatform::Infrastructure::ifcAlignmentExportDescription;
}

#endif // end define OpenInfraPlatform_Infrastructure_IfcAlignmenBuildingSmartP6StepFileWriter_85a9dc90_3db8_49d4_a197_2ac34a429c2f_h
