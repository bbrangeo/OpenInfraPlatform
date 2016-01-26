/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "SelectAlignment.h"
#include "../Data.h"

OpenInfraPlatform::DataManagement::Command::SelectAlignment::SelectAlignment(int selectedIndex)
{
	selectedIndex_ = selectedIndex;
}

OpenInfraPlatform::DataManagement::Command::SelectAlignment::~SelectAlignment()
{

}

void OpenInfraPlatform::DataManagement::Command::SelectAlignment::execute()
{
	prevSelectedIndex_ = OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().getSelectedAlignment();
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().setSelectedAlignment(selectedIndex_);
}

void OpenInfraPlatform::DataManagement::Command::SelectAlignment::unexecute()
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().setSelectedAlignment(prevSelectedIndex_);
}
