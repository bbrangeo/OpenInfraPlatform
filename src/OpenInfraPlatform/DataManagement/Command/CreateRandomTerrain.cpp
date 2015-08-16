/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CreateRandomTerrain.h"

#include "../Data.h"

OpenInfraPlatform::DataManagement::Command::CreateRandomTerrain::CreateRandomTerrain(const buw::terrainDescription& td) :
	td_(td)
{

}

OpenInfraPlatform::DataManagement::Command::CreateRandomTerrain::~CreateRandomTerrain()
{

}

void OpenInfraPlatform::DataManagement::Command::CreateRandomTerrain::unexecute()
{

}

void OpenInfraPlatform::DataManagement::Command::CreateRandomTerrain::execute()
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().createRandomTerrain(td_);
}