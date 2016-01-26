/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Dominic Singer <dominic.singer@tum.de> (https://www.cms.bgu.tum.de/de/team/singer)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CrossSectionStatic.h"

// ---------------------------------------------------------------------------------------------------------------------------
// Cross section methods
// ---------------------------------------------------------------------------------------------------------------------------
void OpenInfraPlatform::Infrastructure::CrossSectionStatic::addCrossSectionSurface(buw::ReferenceCounted<buw::CrossSectionSurface> csSurface)
{
	crossSectSurfaceList_.push_back(csSurface);
}

int OpenInfraPlatform::Infrastructure::CrossSectionStatic::getCrossSectionSurfaceCount()
{
	return static_cast<int>(crossSectSurfaceList_.size());
}

buw::ReferenceCounted<buw::CrossSectionSurface> OpenInfraPlatform::Infrastructure::CrossSectionStatic::getCrossSectionSurface(const int index)
{
	return crossSectSurfaceList_[index];
}

// ---------------------------------------------------------------------------------------------------------------------------
// Design cross section methods
// ---------------------------------------------------------------------------------------------------------------------------
void OpenInfraPlatform::Infrastructure::CrossSectionStatic::addDesignCrossSectionSurface(buw::ReferenceCounted<DesignCrossSectionSurface> csDesignSurface)
{
	if(csDesignSurface->closedArea)
	{ 
		closedDesignCrossSectSurfaceList_.push_back(csDesignSurface);
	}
	else
	{
		if(csDesignSurface->crossSectionsPoints.size()==2)
		{
			if(buw::round((csDesignSurface->crossSectionsPoints[1]->position-csDesignSurface->crossSectionsPoints[0]->position).length(),5)!=0.0)
				openDesignCrossSectSurfaceList_.push_back(csDesignSurface);
		}
		else
		{ 
			openDesignCrossSectSurfaceList_.push_back(csDesignSurface);
		}
	}
}

int OpenInfraPlatform::Infrastructure::CrossSectionStatic::getDesignCrossSectionSurfaceCount()
{
	return static_cast<int>((closedDesignCrossSectSurfaceList_.size()+openDesignCrossSectSurfaceList_.size()));
}

buw::ReferenceCounted<buw::DesignCrossSectionSurface> OpenInfraPlatform::Infrastructure::CrossSectionStatic::getDesignCrossSectionSurface(const int index)
{
	if(index<closedDesignCrossSectSurfaceList_.size()) 
		return closedDesignCrossSectSurfaceList_[index];
	else 
		return openDesignCrossSectSurfaceList_[index-closedDesignCrossSectSurfaceList_.size()];
}

// ---------------------------------------------------------------------------------------------------------------------------
// Closed design cross section methods
// ---------------------------------------------------------------------------------------------------------------------------
int OpenInfraPlatform::Infrastructure::CrossSectionStatic::getClosedDesignCrossSectionSurfaceCount()
{
	return static_cast<int>(closedDesignCrossSectSurfaceList_.size());
}

buw::ReferenceCounted<buw::DesignCrossSectionSurface> OpenInfraPlatform::Infrastructure::CrossSectionStatic::getClosedDesignCrossSectionSurface(const int index)
{
	return closedDesignCrossSectSurfaceList_[index];
}


// ---------------------------------------------------------------------------------------------------------------------------
// Open design cross section methods
// ---------------------------------------------------------------------------------------------------------------------------
int OpenInfraPlatform::Infrastructure::CrossSectionStatic::getOpenDesignCrossSectionSurfaceCount()
{
	return static_cast<int>(openDesignCrossSectSurfaceList_.size());
}

buw::ReferenceCounted<buw::DesignCrossSectionSurface> OpenInfraPlatform::Infrastructure::CrossSectionStatic::getOpenDesignCrossSectionSurface(const int index)
{
	return openDesignCrossSectSurfaceList_[index];
}

bool OpenInfraPlatform::Infrastructure::CrossSectionStatic::smallerStation(const buw::ReferenceCounted<CrossSectionStatic>& a, const buw::ReferenceCounted<CrossSectionStatic>& b)
{
	return a->stationing < b->stationing;
}

OpenInfraPlatform::Infrastructure::CrossSectionStatic::CrossSectionStatic()
{

}
