/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "ImportXYZ.h"
#include "../Data.h"

OpenInfraPlatform::DataManagement::Command::ImportXYZ::ImportXYZ(const std::vector<buw::vector3d>& positions)
{
	positions_ = positions;
}

OpenInfraPlatform::DataManagement::Command::ImportXYZ::~ImportXYZ()
{

}

void OpenInfraPlatform::DataManagement::Command::ImportXYZ::execute()
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().importXYZ(positions_);
}

void OpenInfraPlatform::DataManagement::Command::ImportXYZ::unexecute()
{

}
