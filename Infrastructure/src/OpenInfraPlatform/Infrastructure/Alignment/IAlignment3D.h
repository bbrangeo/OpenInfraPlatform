/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_IAlignment3D_f30b6bea_bf6e_4892_acc4_2b1f1952fe60_h
#define OpenInfraPlatform_Infrastructure_IAlignment3D_f30b6bea_bf6e_4892_acc4_2b1f1952fe60_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "types.h"
#include <buw.BlueCore.class.h>
#include <buw.BlueCore.Math.h>
#include <boost/noncopyable.hpp>
#include <string>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		enum class e3DAlignmentType
		{
			e2DBased,
			e3DBased,
			Unknown
		};

		class BLUEINFRASTRUCTURE_API IAlignment3D
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(IAlignment3D);

			IAlignment3D(const e3DAlignmentType type);

			virtual ~IAlignment3D();

			virtual buw::vector3d	getPosition(const buw::Stationing station ) const = 0;
			virtual Stationing		getStartStation() const = 0;
			virtual Stationing		getEndStation() const = 0;
			virtual double			getLength() const = 0;

			//! Retrieve name of alignment
			buw::String				getName() const;

			//! Assign a name to the alignment
			void					setName(const std::string& name);
			void					setName(const std::wstring& name);

			e3DAlignmentType		getType() const;

		protected:
			e3DAlignmentType			type_;

		private:
			buw::String					name_;
		}; // end class IAlignment3D
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::e3DAlignmentType;
	using OpenInfraPlatform::Infrastructure::IAlignment3D;
}

#endif // end define OpenInfraPlatform_Infrastructure_IAlignment3D_f30b6bea_bf6e_4892_acc4_2b1f1952fe60_h
