/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "HorizontalAlignment2D.h"

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2D::Ptr 
OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::getAlignmentElementByStationing(
	const Stationing station, 
	double* lerpParameter /*= nullptr*/) const
{
	if (horizontalElements_.size() == 0)
	{
		return nullptr;
	}

	// If station is out of range return nullptr
	if (station < getStartStation() ||
		station > getEndStation() )
	{
		// std::cout << "invalid station" << std::endl;

		if ( station < getStartStation() )
		{
			// first alignment
			return horizontalElements_[0];
		}

		if ( station > getEndStation() )
		{
			// last alignment
			return horizontalElements_[horizontalElements_.size()-1];
		}

		return nullptr;
	}

	double currentStationT3 = startStationing_;
	double previousStationT1 = 0;

	for (HorizontalAlignmentElement2D::Ptr a : horizontalElements_)
	{
		previousStationT1 = currentStationT3;
		currentStationT3 += a->getLength();

		if ( currentStationT3 > station)
		{
			if (lerpParameter)
			{
				*lerpParameter = ((station - previousStationT1) / (currentStationT3 - previousStationT1));

				BLUE_ASSERT(*lerpParameter >= 0.0 , "Invalid value.");
				BLUE_ASSERT(*lerpParameter <= 1.0, "Invalid value.");
			}

			return a;
		}
	}

	return nullptr;
}

OpenInfraPlatform::Infrastructure::Stationing OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::getEndStation() const
{
	return startStationing_ + getLength();
}

OpenInfraPlatform::Infrastructure::Stationing OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::getStartStation(const int index /*= 0*/) const
{
	BLUE_ASSERT(index >= 0, "Invalid index.");
	BLUE_ASSERT(index < horizontalElements_.size(), "Invalid index.");

	Stationing s = startStationing_;

	for (int i = 0; i < index; i++)
	{
		s += horizontalElements_[i]->getLength();
	}

	return s;
}

void OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::addElement(HorizontalAlignmentElement2D::Ptr he)
{
	horizontalElements_.push_back(he);
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2D::ConstPtr 
OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::getAlignmentElementByIndex(int index)
{
	BLUE_ASSERT(index >= 0, "Invalid index.");
	BLUE_ASSERT(index < horizontalElements_.size(), "Invalid index.");
	return horizontalElements_[index];
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::getLength() const
{
	double sum = 0;

	for (HorizontalAlignmentElement2D::Ptr a : horizontalElements_)
	{
		sum += a->getLength();
	}

	return sum;
}

int OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::getAlignmentElementCount() const
{
	return static_cast<int>(horizontalElements_.size());
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::getPosition(const Stationing station) const
{
	double s = station;

	double lerpScalar = 0.0;
	HorizontalAlignmentElement2D::Ptr a = getAlignmentElementByStationing(s, &lerpScalar);

	BLUE_ASSERT(lerpScalar >= 0.0, "Invalid lerp paramter.");
	BLUE_ASSERT(lerpScalar <= 1.0, "Invalid lerp paramter.");

	BLUE_ASSERT(a != nullptr, "Invalid alignment element.");
	return a->getPosition(lerpScalar);
}

OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::HorizontalAlignment2D(const Stationing startStationing /*= 0.0*/) :
	startStationing_(startStationing)
{

}

bool OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::hasSuccessor(HorizontalAlignmentElement2D::Ptr element)
{
	for (int i = 0; i < horizontalElements_.size(); i++)
	{
		if (element == horizontalElements_[i])
		{
			return true;
		}
	}

	return false;
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2D::Ptr OpenInfraPlatform::Infrastructure::HorizontalAlignment2D::getSuccessor(HorizontalAlignmentElement2D::Ptr element)
{
	for (int i = 0; i < horizontalElements_.size(); i++)
	{
		if (element == horizontalElements_[i])
		{
			return horizontalElements_[i];
		}
	}
	return nullptr;
}
