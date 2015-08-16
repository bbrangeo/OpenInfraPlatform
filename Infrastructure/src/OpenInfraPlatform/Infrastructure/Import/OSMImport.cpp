/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "OSMImport.h"

OpenInfraPlatform::Infrastructure::OSMImport::OSMImport()
{

}

OpenInfraPlatform::Infrastructure::OSMImport::~OSMImport()
{

}

buw::DigitalElevationModel::Ptr OpenInfraPlatform::Infrastructure::OSMImport::getDigitalElevationModel()
{
	return digitalElevationModel;
}

int OpenInfraPlatform::Infrastructure::OSMImport::getAlignmentCount()
{
	BLUE_ASSERT(alignmentModel_ != nullptr, "Invalid alingment model");
	return static_cast<int>(alignmentModel_->getAlignmentCount());
}

std::vector<buw::IAlignment3D::Ptr> OpenInfraPlatform::Infrastructure::OSMImport::getAlignments()
{
	BLUE_ASSERT(alignmentModel_ != nullptr, "Invalid alingment model");
	return alignmentModel_->getAlignments();
}
