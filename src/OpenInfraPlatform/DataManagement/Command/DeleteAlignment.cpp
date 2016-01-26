/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "DeleteAlignment.h"
#include "OpenInfraPlatform/DataManagement/Data.h"

OpenInfraPlatform::DataManagement::Command::DeleteAlignment::DeleteAlignment(buw::ReferenceCounted<buw::IAlignment3D> alignment) :
alignment_(alignment)
{

}

OpenInfraPlatform::DataManagement::Command::DeleteAlignment::~DeleteAlignment()
{

}

void OpenInfraPlatform::DataManagement::Command::DeleteAlignment::unexecute()
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addAlignment(alignment_);
}

void OpenInfraPlatform::DataManagement::Command::DeleteAlignment::execute()
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().deleteAlignment(alignment_);
}
