/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Data_AlignmentModel_6922ea21_8578_4afc_965a_b368145f716d_h
#define OpenInfraPlatform_Data_AlignmentModel_6922ea21_8578_4afc_965a_b368145f716d_h

#include "buw.BlueCore.class.h"
#include <boost/noncopyable.hpp>
#include "buw.BlueEngine.AxisAlignedBoundingBox.h"

#include "OpenInfraPlatform/Infrastructure/Alignment/IAlignment3D.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		//! \class AlignmentModel
		//! \brief brief description
		class BLUEINFRASTRUCTURE_API AlignmentModel
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(AlignmentModel)

			//! Default constructor.
			AlignmentModel();

			//! Virtual destructor.
			virtual ~AlignmentModel();

			int getAlignmentCount() const;

			buw::IAlignment3D::Ptr getAlignment( const int index ) const;

			std::vector<buw::IAlignment3D::Ptr> getAlignments();

			void addAlignment(buw::IAlignment3D::Ptr alignment);

			void deleteAlignment(buw::IAlignment3D::Ptr alignment);

			static AlignmentModel* createFlatCopy(const AlignmentModel& src);

			buw::AxisAlignedBoundingBox3d getExtends() const;

			buw::AxisAlignedBoundingBox3d getVerticalAlignmentExtends();

		private:				
			std::vector<buw::IAlignment3D::Ptr> alignments_;
		}; // end class AlignmentModel
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::AlignmentModel;
}

#endif // end define OpenInfraPlatform_Data_AlignmentModel_6922ea21_8578_4afc_965a_b368145f716d_h
