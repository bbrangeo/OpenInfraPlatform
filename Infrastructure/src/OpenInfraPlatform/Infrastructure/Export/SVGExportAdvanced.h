/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author			Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#include "SVGExport.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		//! SVG Exporter for alignments
		class BLUEINFRASTRUCTURE_API SVGExportAdvanced : public Export
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(SVGExportAdvanced);

			SVGExportAdvanced(buw::ReferenceCounted<buw::AlignmentModel> am, buw::ReferenceCounted<buw::DigitalElevationModel> dem, const std::string& filename);

		private:
			void addPath(FILE *fp, const buw::vector2d& a, const buw::vector2d& b, const buw::vector2d& c);
			void outputToSVG(FILE *fp, buw::ReferenceCounted<buw::HorizontalAlignment2D> horizontalAlignment);
		}; // end class SVGExportAdvanced
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::SVGExportAdvanced;
}

