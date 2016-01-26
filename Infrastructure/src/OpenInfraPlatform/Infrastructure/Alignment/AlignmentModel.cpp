/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "AlignmentModel.h"


buw::AlignmentModel::AlignmentModel()
{

}

OpenInfraPlatform::Infrastructure::AlignmentModel::~AlignmentModel()
{

}

buw::AxisAlignedBoundingBox3d OpenInfraPlatform::Infrastructure::AlignmentModel::getExtends() const
{
	// we run along along all alignments an determine the corresponding position
	// this my seem stupid at first glance, but in this way we have not to introduce
	// additional methods in the 2D alignment element class.
	if (alignments_.size() == 0)
	{
		return buw::AxisAlignedBoundingBox3d();
	}

	buw::vector3d min_ = alignments_[0]->getPosition(0);
	buw::vector3d max_ = alignments_[0]->getPosition(0);

	for (int i = 0; i < alignments_.size(); i++)
	{
		for (double s = alignments_[i]->getStartStation(); s < alignments_[i]->getEndStation(); s += 1.0)
		{
			auto p = alignments_[i]->getPosition(s);
			min_ = buw::getMinimizedVector(min_, p);
			max_ = buw::getMaximizedVector(max_, p);
		}
	}

	return buw::AxisAlignedBoundingBox3d(min_, max_);
}

void OpenInfraPlatform::Infrastructure::AlignmentModel::deleteAlignment(buw::ReferenceCounted<buw::IAlignment3D> alignment)
{
	auto iterator = std::find(alignments_.begin(), alignments_.end(), alignment);

	BLUE_ASSERT(iterator != alignments_.end(), "Invalid alignment");

	if (iterator != alignments_.end())
	{
		alignments_.erase(iterator);
	}
	else
	{
		throw std::runtime_error("Deltion of alignment failed.");
	}
}

void OpenInfraPlatform::Infrastructure::AlignmentModel::addAlignment(buw::ReferenceCounted<buw::IAlignment3D> alignment)
{
	alignments_.push_back(alignment);
}

std::vector<buw::ReferenceCounted<buw::IAlignment3D>> OpenInfraPlatform::Infrastructure::AlignmentModel::getAlignments()
{
	return alignments_;
}

buw::ReferenceCounted<buw::IAlignment3D> OpenInfraPlatform::Infrastructure::AlignmentModel::getAlignment(const int index) const
{
	return alignments_[index];
}

int OpenInfraPlatform::Infrastructure::AlignmentModel::getAlignmentCount() const
{
	return static_cast<int>(alignments_.size());
}

buw::AxisAlignedBoundingBox3d buw::AlignmentModel::getVerticalAlignmentExtends()
{
	buw::AxisAlignedBoundingBox3d b;

	bool firstFound = true;

	for (int i = 0; i < alignments_.size(); i++)
	{
		if (alignments_[i]->getType() == buw::e3DAlignmentType::e2DBased)
		{
			buw::ReferenceCounted<buw::Alignment2DBased3D> a = std::static_pointer_cast<buw::Alignment2DBased3D>(alignments_[i]);

			if (firstFound)
			{
				firstFound = false;
				b = a->getVerticalAlignmentExtends();
			}
			else
			{
				auto u = buw::getMinimizedVector( b.getMinimum(), a->getVerticalAlignmentExtends().getMinimum() );
				auto v = buw::getMaximizedVector( b.getMaximum(), a->getVerticalAlignmentExtends().getMaximum() );
				b.setMinimum(u);
				b.setMaximum(v);
			}
		}
	}

	return b;
}

buw::AlignmentModel* buw::AlignmentModel::createFlatCopy(const AlignmentModel& src)
{
	return new AlignmentModel(src);
}
