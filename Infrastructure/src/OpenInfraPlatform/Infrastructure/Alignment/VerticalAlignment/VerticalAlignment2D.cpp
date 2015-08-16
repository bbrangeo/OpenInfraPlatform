/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "VerticalAlignment2D.h"

OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2D::Ptr
OpenInfraPlatform::Infrastructure::VerticalAlignment2D::getAlignmentElementByStationing(const Stationing station) const
{
	if (verticalElements_.size() == 0)
	{
		return nullptr;
	}

	for (int i = 0; i < verticalElements_.size(); i++)
	{
		if (station >= verticalElements_[i]->getStartStation() &&
			station < verticalElements_[i]->getEndStation())
		{
			return verticalElements_[i];
		}
	}

	return nullptr;
}

void OpenInfraPlatform::Infrastructure::VerticalAlignment2D::addElement(VerticalAlignmentElement2D::Ptr ve)
{
	verticalElements_.push_back(ve);
}

OpenInfraPlatform::Infrastructure::Stationing 
OpenInfraPlatform::Infrastructure::VerticalAlignment2D::getEndStation() const
{
	if (verticalElements_.size() == 0)
	{
		return 0;
	}
	return verticalElements_[verticalElements_.size() - 1]->getEndStation();
}

OpenInfraPlatform::Infrastructure::Stationing 
OpenInfraPlatform::Infrastructure::VerticalAlignment2D::getStartStation() const
{
	if (verticalElements_.size() == 0)
	{
		return 0;
	}
	return verticalElements_[0]->getStartStation();
}

OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2D::ConstPtr
OpenInfraPlatform::Infrastructure::VerticalAlignment2D::getAlignmentElementByIndex(int index)
{
	BLUE_ASSERT(index >= 0, "Invalid index.");
	BLUE_ASSERT(index < verticalElements_.size(), "Invalid index.");
	return verticalElements_[index];
}

int OpenInfraPlatform::Infrastructure::VerticalAlignment2D::getAlignmentElementCount() const
{
	return static_cast<int>(verticalElements_.size());
}

buw::vector2d OpenInfraPlatform::Infrastructure::VerticalAlignment2D::getPosition(const Stationing station) const
{
	VerticalAlignmentElement2D::Ptr v = getAlignmentElementByStationing(station);

	if (v == nullptr)
	{
		return buw::vector2d(station, 0);
	}

	return v->getPosition(station);
}

bool OpenInfraPlatform::Infrastructure::VerticalAlignment2D::hasElements() const
{
	return verticalElements_.size() > 0;
}
