/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universit�t M�nchen
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_Alignment3DBased3D_361647d9_ca33_4ef1_827e_ede8fb1f0a1e_h
#define OpenInfraPlatform_Infrastructure_Alignment3DBased3D_361647d9_ca33_4ef1_827e_ede8fb1f0a1e_h

#include "IAlignment3D.h"
#include "types.h"
#include "../Core/CatmullRomSpline.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API Alignment3DBased3D : public buw::IAlignment3D
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(Alignment3DBased3D);

			Alignment3DBased3D(const Stationing startSation);

			virtual ~Alignment3DBased3D();

			//! Computes the 3d position given a stationing.
			buw::vector3d	getPosition(const Stationing station ) const override;

			buw::Stationing getStartStation() const override;

			buw::Stationing getEndStation() const override;

			//! Length of horizontal alignment
			double			getLength() const override;	

			void			addPoint(const buw::vector3d& p);

		private:
			buw::Stationing	startSation_;

			CatmullRomSpline3d crs_;
		};
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::Alignment3DBased3D;
}

#endif // end define OpenInfraPlatform_Infrastructure_Alignment3DBased3D_361647d9_ca33_4ef1_827e_ede8fb1f0a1e_h
