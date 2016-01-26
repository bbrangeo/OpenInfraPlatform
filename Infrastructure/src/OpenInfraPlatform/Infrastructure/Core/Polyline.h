/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once

#include "BlueFramework/Core/Math/vector.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		template<typename T>
		class Polyline
		{
			typedef T ScalarType;
			typedef BlueFramework::Core::Math::vector<ScalarType, 3> VectorType;

		public:
			Polyline():
				delta_t(0)
			{}

			void AddPoint(const VectorType& p)
			{
				points.push_back(p);
				delta_t = (ScalarType)1 / (ScalarType)(points.size() - 1);
			}

			void AddPoints(const std::vector<VectorType>& ps)
			{
				for (auto& p : ps)
				{
					points.push_back(p);
				}
				delta_t = (ScalarType)1 / (ScalarType)(points.size() - 1);
			}

			VectorType Interpolate(const ScalarType t) const
			{
				int p0 = (int)(t / delta_t);
				int p1 = p0 + 1;

				ScalarType lt = (t - delta_t * p0) / delta_t;
				return (points[p1] - points[p0]) * lt + points[p0];
			}

			size_t GetNumPoints() const
			{
				return points.size();
			}

			const VectorType& GetNthPoint(const int n) const
			{
				return points[n];
			}

			ScalarType Length() const
			{
				ScalarType sum = 0;
				if (points.size() == 0)
					return 0;

				VectorType last = points[0];
				for (int i = 1; i < points.size(); i++)
				{
					VectorType delta = points[i] - last;
					sum += delta.length();
					last = points[i];
				}

				return sum;
			}

		private:
			std::vector<VectorType> points;
			ScalarType delta_t;
		};

		typedef Polyline<float> Polyline3f;
		typedef Polyline<double> Polyline3d;
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::Polyline3f;
	using OpenInfraPlatform::Infrastructure::Polyline3d;
}