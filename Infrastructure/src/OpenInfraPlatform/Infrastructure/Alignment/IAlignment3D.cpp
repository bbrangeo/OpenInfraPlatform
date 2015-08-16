/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "IAlignment3D.h"

void OpenInfraPlatform::Infrastructure::IAlignment3D::setName(const std::string& name)
{
	name_ = buw::String::toWStdString(name);
}

void OpenInfraPlatform::Infrastructure::IAlignment3D::setName(const std::wstring& name)
{
	name_ = name;
}

OpenInfraPlatform::Infrastructure::e3DAlignmentType OpenInfraPlatform::Infrastructure::IAlignment3D::getType() const
{
	return type_;
}

buw::String OpenInfraPlatform::Infrastructure::IAlignment3D::getName() const
{
	return name_;
}

OpenInfraPlatform::Infrastructure::IAlignment3D::~IAlignment3D()
{

}

OpenInfraPlatform::Infrastructure::IAlignment3D::IAlignment3D(const e3DAlignmentType type) :
type_(type)
{

}
