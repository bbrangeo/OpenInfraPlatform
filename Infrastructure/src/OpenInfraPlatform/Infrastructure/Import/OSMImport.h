/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_OSMImport_cb390352_9e34_4971_a173_eab046fe8eec_h
#define OpenInfraPlatform_Infrastructure_OSMImport_cb390352_9e34_4971_a173_eab046fe8eec_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/AlignmentModel.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/surface.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/DigitalElevationModel.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		struct OSMNode 
		{
			int id;
			double lat;
			double lon;
		};

		struct OSMWay
		{
			std::vector<int> ids;
		};
		
		class OSMImport : private boost::noncopyable
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(OSMImport);

			//! Default constructor.
			OSMImport();

			//! Virtual destructor.
			virtual ~OSMImport();
			
			std::vector<buw::IAlignment3D::Ptr> getAlignments();

			int	getAlignmentCount();

			buw::DigitalElevationModel::Ptr getDigitalElevationModel();

		private:
			buw::AlignmentModel::Ptr		alignmentModel_;
			buw::DigitalElevationModel::Ptr digitalElevationModel;
		}; // end class OSMImport
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::OSMImport;
}

#endif // end define OpenInfraPlatform_Infrastructure_OSMImport_cb390352_9e34_4971_a173_eab046fe8eec_h
