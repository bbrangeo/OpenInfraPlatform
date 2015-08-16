/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_OutputStreamLandXMLDataBuilder_829f8d4c_5a1b_4a3a_9876_c554e355d6e5_h
#define OpenInfraPlatform_Infrastructure_OutputStreamLandXMLDataBuilder_829f8d4c_5a1b_4a3a_9876_c554e355d6e5_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "OpenInfraPlatform/Infrastructure/Import/LandXmlImport.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/IAlignment3D.h"
#include <boost/noncopyable.hpp>
#include <ostream>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API OutputStreamLandXMLDataBuilder : public OpenInfraPlatform::Infrastructure::LandXMLDataBuilder
		{
		public:
			OutputStreamLandXMLDataBuilder(std::ostream& out);

			virtual void createAlignment(const PropertySet& parameters) override;

			virtual void createCoordGeom() override;

			virtual void createLine(const PropertySet& parameters) override;

			virtual void createCurve(const PropertySet& parameters) override;

			virtual void createSpiral(const PropertySet& parameters) override;

			virtual void createProfAlign(const PropertySet& parameters) override;

			virtual void createPVI(const PropertySet& parameters) override;

			virtual void createParaCurve(const PropertySet& parameters) override;

			virtual void createCircCurve(const PropertySet& parameters) override;

			virtual void createSurface(const PropertySet& parameters, const LandXMLSurface& surface) override;

			virtual void createCrossSectionSurf(const PropertySet& parameters) override;

			virtual void createDesignCrossSectSurf(const PropertySet& parameters) override;

			virtual void createCrossSectPnt(const PropertySet& parameters) override;

		private:
			std::ostream& out;
		};
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder;
}

#endif // end define OpenInfraPlatform_Infrastructure_OutputStreamLandXMLDataBuilder_829f8d4c_5a1b_4a3a_9876_c554e355d6e5_h
