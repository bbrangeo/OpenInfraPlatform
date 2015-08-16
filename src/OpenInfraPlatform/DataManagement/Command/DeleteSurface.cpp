/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#include "DeleteSurface.h"
#include "OpenInfraPlatform/DataManagement/Data.h"

OpenInfraPlatform::DataManagement::Command::DeleteSurface::DeleteSurface(buw::Surface::Ptr surface) :
surface_(surface)
{

}

OpenInfraPlatform::DataManagement::Command::DeleteSurface::~DeleteSurface()
{

}

void OpenInfraPlatform::DataManagement::Command::DeleteSurface::execute()
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().deleteSurface(surface_);
}

void OpenInfraPlatform::DataManagement::Command::DeleteSurface::unexecute()
{
	OpenInfraPlatform::DataManagement::DocumentManager::getInstance().getData().addSurface(surface_);
}
