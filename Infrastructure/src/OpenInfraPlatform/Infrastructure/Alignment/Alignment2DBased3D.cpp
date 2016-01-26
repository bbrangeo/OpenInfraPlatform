/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "Alignment2DBased3D.h"

buw::AxisAlignedBoundingBox3d OpenInfraPlatform::Infrastructure::getExtends(buw::ReferenceCounted<Alignment2DBased3D> alignment)
{
	// we run along along all alignments an determine the corresponding position
	// this my seem stupid at first glance, but in this way we have not to introduce
	// additional methods in the 2D alignment element class.
	if (alignment == nullptr)
	{
		return buw::AxisAlignedBoundingBox3d();
	}

	buw::vector3d min_ = alignment->getPosition(0);
	buw::vector3d max_ = alignment->getPosition(0);

	for(double s = alignment->getStartStation(); s < alignment->getEndStation(); s+= 1.0)
	{
		auto p = alignment->getPosition(s);
		min_ = buw::getMinimizedVector(min_, p);
		max_ = buw::getMaximizedVector(max_, p);
	}

	return buw::AxisAlignedBoundingBox3d(min_, max_);
}

buw::AxisAlignedBoundingBox3d OpenInfraPlatform::Infrastructure::getExtends(std::vector<buw::ReferenceCounted<IAlignment3D>> alignments)
{
	// we run along along all alignments an determine the corresponding position
	// this my seem stupid at first glance, but in this way we have not to introduce
	// additional methods in the 2D alignment element class.
	if (alignments.size() == 0)
	{
		return buw::AxisAlignedBoundingBox3d();
	}

	buw::vector3d min_ = alignments[0]->getPosition(0);
	buw::vector3d max_ = alignments[0]->getPosition(0);

	for (int i = 0; i < alignments.size(); i++)
	{
		for(double s = alignments[i]->getStartStation(); s < alignments[i]->getEndStation(); s+= 1.0)
		{
			auto p = alignments[i]->getPosition(s);
			min_ = buw::getMinimizedVector(min_, p);
			max_ = buw::getMaximizedVector(max_, p);
		}
	}

	return buw::AxisAlignedBoundingBox3d(min_, max_);
}

buw::ReferenceCounted<buw::CrossSectionStatic> OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getCrossSection(const int index)
{
	return crossSections_[index];
}

int OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getCrossSectionCount()
{
	return static_cast<int>(crossSections_.size());
}

void OpenInfraPlatform::Infrastructure::Alignment2DBased3D::addCrossSection(buw::ReferenceCounted<buw::CrossSectionStatic> cs)
{
	crossSections_.push_back(cs);
}

buw::AxisAlignedBoundingBox3d OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getVerticalAlignmentExtends() const
{
	if (!hasVerticalAlignment())
	{
		return buw::AxisAlignedBoundingBox3d();
	}

	auto startStation = verticalAlignment_->getStartStation();
	buw::vector3d min_ = buw::vector3d(verticalAlignment_->getPosition(startStation).xy(), 0.0).xzy();
	buw::vector3d max_ = min_;

	for(double s = verticalAlignment_->getStartStation(); s < verticalAlignment_->getEndStation(); s+= 1.0)
	{
		auto p = verticalAlignment_->getPosition(s);
		min_ = buw::getMinimizedVector( min_, buw::vector3d(p.x(), 0.0, p.y()) );
		max_ = buw::getMaximizedVector( max_, buw::vector3d(p.x(), 0.0, p.y()) );
	}

	return buw::AxisAlignedBoundingBox3d(min_, max_);
}

void OpenInfraPlatform::Infrastructure::Alignment2DBased3D::setVerticalAlignment(buw::ReferenceCounted<VerticalAlignment2D> verticalAlignment)
{
	verticalAlignment_ = verticalAlignment;
}

buw::ReferenceCounted<OpenInfraPlatform::Infrastructure::VerticalAlignment2D> OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getVerticalAlignment() const
{
	return verticalAlignment_;
}

buw::vector2d OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getVerticalPosition( const Stationing station ) const
{
	if (verticalAlignment_ == nullptr )
	{
		return buw::vector2d(0, 0);
	}

	return verticalAlignment_->getPosition(station);
}

bool OpenInfraPlatform::Infrastructure::Alignment2DBased3D::hasVerticalAlignment() const
{
	return (verticalAlignment_ != nullptr);
}

void OpenInfraPlatform::Infrastructure::Alignment2DBased3D::setHorizontalAlignment(buw::ReferenceCounted<buw::HorizontalAlignment2D> horizontalAlignment)
{
	horizontalAlignment_ = horizontalAlignment;
}

buw::ReferenceCounted<OpenInfraPlatform::Infrastructure::HorizontalAlignment2D> OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getHorizontalAlignment() const
{
	return horizontalAlignment_;
}

buw::vector2d OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getHorizontalPosition( const buw::Stationing station ) const
{
	return horizontalAlignment_->getPosition(station);
}

double OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getHorizontalAlignmentLength() const
{
	if (horizontalAlignment_)
	{
		return horizontalAlignment_->getLength();
	}
	else
	{
		return 0;
	}
}

int OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getHorizontalAlignmentElementCount()
{
	if (horizontalAlignment_)
	{
		return horizontalAlignment_->getAlignmentElementCount();
	}
	else
		return 0;
}

bool OpenInfraPlatform::Infrastructure::Alignment2DBased3D::hasHorizontalAlignment() const
{
	return (horizontalAlignment_ != nullptr);
}

double OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getLength() const 
{
	return horizontalAlignment_->getEndStation() - horizontalAlignment_->getStartStation();
}

OpenInfraPlatform::Infrastructure::Stationing OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getEndStation() const 
{
	return horizontalAlignment_->getEndStation();
}

OpenInfraPlatform::Infrastructure::Stationing OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getStartStation() const 
{
	return horizontalAlignment_->getStartStation();
}

buw::vector3d OpenInfraPlatform::Infrastructure::Alignment2DBased3D::getPosition( const buw::Stationing station ) const 
{
	buw::vector2d hp = getHorizontalPosition( station );
	buw::vector2d vp = getVerticalPosition( station );

	if (verticalAlignment_)
	{
		if(	station < verticalAlignment_->getStartStation() ||
			station > verticalAlignment_->getEndStation())
		{
			vp.y() = verticalAlignment_->getPosition( verticalAlignment_->getStartStation() ).y();
		}
	}

	return buw::vector3d(hp.x(), hp.y(), vp.y());
}

OpenInfraPlatform::Infrastructure::Alignment2DBased3D::Alignment2DBased3D(buw::ReferenceCounted<HorizontalAlignment2D> horizontalAlignment /*= nullptr*/,
	buw::ReferenceCounted<VerticalAlignment2D> verticalAlignment /*= nullptr*/) :
horizontalAlignment_(horizontalAlignment),
verticalAlignment_(verticalAlignment),
IAlignment3D(e3DAlignmentType::e2DBased)
{

}

void OpenInfraPlatform::Infrastructure::Alignment2DBased3D::sortCrossSectionsByStation()
{
	std::sort(crossSections_.begin(),crossSections_.end(),buw::CrossSectionStatic::smallerStation);
}

OpenInfraPlatform::Infrastructure::Alignment2DBased3D* OpenInfraPlatform::Infrastructure::Alignment2DBased3D::createFlatCopy(const Alignment2DBased3D& src)
{
	return new Alignment2DBased3D(src.horizontalAlignment_, src.verticalAlignment_);
}
