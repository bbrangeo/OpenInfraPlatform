/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_SpeedProfile_83fb17c8_9228_4176_bf77_968ed2a9abbe_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_SpeedProfile_83fb17c8_9228_4176_bf77_968ed2a9abbe_h

#include "OpenInfraPlatform/Infrastructure/EnergyConsumption/Profiles/Profile.h"
#include "BlueFramework/Core/class.h"
#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			class BLUEINFRASTRUCTURE_API SpeedProfile : public Profile
			{
			public:
				//! Default constructor.
				SpeedProfile();

				SpeedProfile(const std::string &strPath, const std::string &strTitle) : 
					Profile(strPath, strTitle)
				{

				}

				SpeedProfile(std::vector<double> &stationing, std::vector<double> &attribute, const std::string &Title) : 
					Profile(stationing, attribute, Title)
				{

				}

				void RefineByInterpolationEveryTwoPoints()
				{
					std::vector<StationingPoint> newStationing;
					for (int i = 0; i < StationingPoints_.size(); i++)
					{
						newStationing.push_back(StationingPoints_[i]);

						if (i < StationingPoints_.size() - 1)
						{
							double newX = 0.5*(StationingPoints_[i].getX1() + StationingPoints_[i + 1].getX1());
							double newY = 0.5*(StationingPoints_[i].getY1() + StationingPoints_[i + 1].getY1());

							StationingPoint newPoint = StationingPoint(newX, newY);
							newStationing.push_back(newPoint);
						}
					}

					StationingPoints_ = newStationing;
				}

				//! Virtual destructor.
				virtual ~SpeedProfile()
				{
				}

			private:
			}; // end class SpeedProfile
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::SpeedProfile;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_SpeedProfile_83fb17c8_9228_4176_bf77_968ed2a9abbe_h
