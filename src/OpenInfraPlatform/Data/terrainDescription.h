/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once

namespace OpenInfraPlatform
{
	namespace Data
	{
		struct terrainDescription
		{
			int noOfOctaves; 
			int noiseFrequency;
			int terrainSize;
			int tileSize;
		};
	} // end namespace Data
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Data::terrainDescription;
}