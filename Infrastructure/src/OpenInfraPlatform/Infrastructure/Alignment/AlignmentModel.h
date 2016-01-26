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
		class BLUEINFRASTRUCTURE_API AlignmentModel
		{
		public:
			AlignmentModel();

			virtual ~AlignmentModel();

			int getAlignmentCount() const;

			buw::ReferenceCounted<buw::IAlignment3D> getAlignment(const int index) const;

			std::vector<buw::ReferenceCounted<buw::IAlignment3D>> getAlignments();

			void addAlignment(buw::ReferenceCounted<buw::IAlignment3D> alignment);

			void deleteAlignment(buw::ReferenceCounted<buw::IAlignment3D> alignment);

			static AlignmentModel* createFlatCopy(const AlignmentModel& src);

			buw::AxisAlignedBoundingBox3d getExtends() const;

			buw::AxisAlignedBoundingBox3d getVerticalAlignmentExtends();

		private:				
			std::vector<buw::ReferenceCounted<buw::IAlignment3D>> alignments_;
		}; // end class AlignmentModel
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::AlignmentModel;
}

#endif // end define OpenInfraPlatform_Data_AlignmentModel_6922ea21_8578_4afc_965a_b368145f716d_h
