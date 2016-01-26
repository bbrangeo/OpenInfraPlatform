/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Michael Kern <kernm@in.tum.de> (https://www.cms.bgu.tum.de/en/)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

// visual studio
#pragma once
// unix
#ifndef IFCPEEKSTEPREADER_H
#define IFCPEEKSTEPREADER_H

#include <string>

namespace OpenInfraPlatform
{
	namespace IfcGeometryConverter
	{
		class IfcPeekStepReader
		{
		public:
			explicit IfcPeekStepReader();
			virtual ~IfcPeekStepReader();

			enum class IfcSchema : short { IFC_2, IFC_4, IFC_4x1, IFC_ROAD, IFC_BRIDGE, UNKNOWN };
			static IfcSchema parseIfcHeader(const std::string& filename);
		};
	}
}

#endif