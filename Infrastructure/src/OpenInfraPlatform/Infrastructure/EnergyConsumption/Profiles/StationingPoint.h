/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_StationingPoint_b1c2fb53_98ca_429e_8088_7ae6ceaa3acd_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_StationingPoint_b1c2fb53_98ca_429e_8088_7ae6ceaa3acd_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class StationingPoint
			//! \brief brief description
			struct BLUEINFRASTRUCTURE_API StationingPoint
			{
				//! Default constructor.
				StationingPoint();

				StationingPoint(const double x1, const double y1)
				{
					Station = x1;
					Property = y1;
				}
				//! Virtual destructor.
				virtual ~StationingPoint()
				{
				}
								
				double Station = 0;
				double Property = 0;
				
				double getX1() const { return Station; }
				double getY1() const { return Property; }
				void setX1(double value) { Station = value; }
				void setY1(double value) { Property = value; }

			private:
			}; // end class StationingPoint
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::StationingPoint;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_StationingPoint_b1c2fb53_98ca_429e_8088_7ae6ceaa3acd_h
