/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "ImportXYZ.h"
#include "OpenInfraPlatform/DataManagement/Data.h"

OpenInfraPlatform::DataManagement::Command::ImportXYZ::ImportXYZ(const std::string& filename, const buw::vector2d& start, const buw::vector2d& end)
{
	filename_ = filename;
	start_ = start;
	end_ = end;
}

OpenInfraPlatform::DataManagement::Command::ImportXYZ::~ImportXYZ()
{

}

void OpenInfraPlatform::DataManagement::Command::ImportXYZ::execute()
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().importXYZ(filename_, start_, end_);
}

void OpenInfraPlatform::DataManagement::Command::ImportXYZ::unexecute()
{

}
