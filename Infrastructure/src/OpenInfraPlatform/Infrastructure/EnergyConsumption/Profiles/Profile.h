/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */
 
#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_Profile_d932490c_7b8a_4295_a79a_fdd0d3049967_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_Profile_d932490c_7b8a_4295_a79a_fdd0d3049967_h

#include "StationingPoint.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>
#include <iostream>
#include <vector>
#include <string>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class Profile
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API Profile : private boost::noncopyable
			{
			public:
				//! Default constructor.
				Profile();

				Profile(const std::string &path, const std::string &Title)
				{
					setTitle(Title);
					path_ = path;
					SetProfileTxt(path);
				}

				Profile(std::vector<double> &stationing, std::vector<double> &attribute, 
					const std::string &Title)
				{
					setTitle(Title);
					path_ = "Default";
					SetProfile(stationing, attribute);
				}

				//! Virtual destructor.
				virtual ~Profile()
				{
				}

				std::string getId() const { return Id_; }
				void setId(std::string val) { Id_ = val; }

				std::string getTitle() const { return Title_; }
				void setTitle(std::string val) { Title_ = val; }

				void SetProfileTxt(const std::string &strFileName)
				{
				}

				void SetProfile(std::vector<double> &lstStationingPoints, std::vector<double> &AttributePoints)
				{
					if (lstStationingPoints.size() == AttributePoints.size())
					{
						double x_new, y_new;
						StationingPoint StationingPointread;

						for (int i = 0; i <= lstStationingPoints.size() - 1; ++i)
						{
							x_new = lstStationingPoints[i];
							y_new = AttributePoints[i];
							StationingPointread = StationingPoint(x_new, y_new);
							StationingPoints_.push_back(StationingPointread);
						}
					}
					else
					{
						std::cout << "\nERROR: While reading the Track Profile\n The number of stationing points does not match the number of attribute points!" << std::endl;
					}
				}

				double getElementX1(int i)
				{
					return StationingPoints_[i].getX1();
				}

				double getElementY1(int i)
				{
					return StationingPoints_[i].getY1();
				}

				void setElementX1(int i, double stationing)
				{
					StationingPoints_[i].setX1(stationing);
				}

				void setElementY1(int i, double attribute)
				{
					StationingPoints_[i].setY1(attribute);
				}

				int getSize()
				{
					return StationingPoints_.size();
				}

				int getClosestStationingPoint(double percentage)
				{
					int count = StationingPoints_.size();
					double end = StationingPoints_[count - 1].Station;
					double StationingPoint = percentage * end;
					double current = StationingPoints_[0].Station;
					double next = StationingPoints_[1].Station;
					int point = 0;

					// finding the closest match
					for (int i = 0; i < count - 1; i++)
					{

						double diff1 = std::abs(StationingPoint - current);
						double diff2 = std::abs(next - StationingPoint);

						if (diff1 > diff2)
						{
							current = StationingPoints_[i + 1].Station;
							next = StationingPoints_[i + 2].Station;
						}
						else
						{
							point = i;
							break;
						}

					}

					return point;
				}

			protected:
				std::vector<StationingPoint> StationingPoints_;
				std::string Id_;
				std::string Title_;
				std::string path_;
			}; // end class Profile
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::Profile;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_Profile_d932490c_7b8a_4295_a79a_fdd0d3049967_h
