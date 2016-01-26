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

#include "OpenInfraPlatform/Infrastructure/Export/Export.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"

#include "BlueFramework/Core/class.h"
#include <vector>
#include <memory>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		enum class eIfcSchemaVersion
		{
			IFC2x3,
			IFC4,
			IFC4x1
		};
		
		struct ifcAlignmentExportDescription
		{
			eIfcSchemaVersion schemaVersion = eIfcSchemaVersion::IFC4x1;
			bool exportTerrain = true;
			bool exportAlignment = true;
			bool useRadiansInsteadOfDegrees = true;
			bool useFixedEntityIdForGeometry = false;
			int startId = 4000;
		};

		class BLUEINFRASTRUCTURE_API IfcAlignmentExport : public Export
		{
		public:			
			BLUE_DEFINE_SHARED_POINTER(IfcAlignmentExport);

			//! Default constructor.
			IfcAlignmentExport(const ifcAlignmentExportDescription& desc, buw::ReferenceCounted<buw::AlignmentModel> am, buw::ReferenceCounted<buw::DigitalElevationModel> dem, const std::string& filename);

			//! Virtual destructor.
			virtual ~IfcAlignmentExport();

		private:
			class IfcAlignmentP6ExportImpl;						// Forward declaration of internal class
			buw::ReferenceCounted<IfcAlignmentP6ExportImpl> impl_;	// Opaque pointer to implementation
		}; // end class IfcAlignmenBuildingSmartP6StepFileWriter
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::eIfcSchemaVersion;
	using OpenInfraPlatform::Infrastructure::IfcAlignmentExport;
	using OpenInfraPlatform::Infrastructure::ifcAlignmentExportDescription;
}

#endif // end define OpenInfraPlatform_Infrastructure_IfcAlignmenBuildingSmartP6StepFileWriter_85a9dc90_3db8_49d4_a197_2ac34a429c2f_h
