/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_ExcelReport2_c3889228_51c2_4ead_99cb_96ccb5cb735d_h
#define OpenInfraPlatform_Infrastructure_ExcelReport2_c3889228_51c2_4ead_99cb_96ccb5cb735d_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include <string>
#include <memory>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		struct LandXMLHorizontalAlignmentReportSettings
		{
			LandXMLHorizontalAlignmentReportSettings()
			{
				alignmentName = true;
				type = true;
				startPosition = true;
				endPosition = true;
				centerPosition = true;
				pi = true;
				length = true;
				radius = true;
				radiusStart = true;
				radiusEnd = true;
				dirStart = true;
				dirEnd = true;
				rot = true;
				spiType = true;
			}

			// LandXML
			bool alignmentName;
			bool type;
			bool startPosition;
			bool endPosition;
			bool centerPosition;
			bool pi;
			bool length;
			bool radius;
			bool radiusStart;
			bool radiusEnd;
			bool dirStart;
			bool dirEnd;
			bool rot;
			bool spiType;
		};

		struct P6IfcHorizontalAlignmentReportSettings
		{
			P6IfcHorizontalAlignmentReportSettings()
			{
				alignmentName = true;
				type = true;
				startPosition = true;
				startDirection = true;
				segmentLength = true;
				radius = true;
				startRadius = true;
				isCcw = true;
				IsEntry = true;
				ClothoidConstant = true;
				check = true;
			}

			bool alignmentName;
			bool type;
			bool startPosition;
			bool startDirection;
			bool segmentLength;
			bool radius;
			bool startRadius;
			bool isCcw;
			bool IsEntry;
			bool ClothoidConstant;
			bool check;
		};

		struct P6IfcVerticalAlignmentReportSettings
		{
			P6IfcVerticalAlignmentReportSettings()
			{
				alignmentName = true;
				type = true;	
				check = true;
			}

			bool alignmentName;
			bool type;
			bool check;
		};

		class BLUEINFRASTRUCTURE_API ExcelReport
		{
		public:
			ExcelReport(
				const char* excelExportFilename, 
				const char* landXMLFilename, 
				const char* ifcP6ExportFilename);

		private:
			class ExcelReportImpl;						// Forward declaration of internal class
			std::shared_ptr<ExcelReportImpl> impl_;	// Opaque pointer to implementation
		}; // end class ExcelReport2
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::P6IfcVerticalAlignmentReportSettings;
	using OpenInfraPlatform::Infrastructure::LandXMLHorizontalAlignmentReportSettings;
	using OpenInfraPlatform::Infrastructure::P6IfcHorizontalAlignmentReportSettings;
	using OpenInfraPlatform::Infrastructure::ExcelReport;
}

#endif // end define OpenInfraPlatform_Infrastructure_ExcelReport2_c3889228_51c2_4ead_99cb_96ccb5cb735d_h
