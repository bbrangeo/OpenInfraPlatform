/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once

#include "buw.BlueCore.h"
#include "buw.BlueImageProcessing.h"
#include "buw.BlueEngine.h"

namespace OpenInfraPlatform
{
	namespace UnitTesting
	{
		struct testDescription
		{
			buw::Path LandXMLFile;
			buw::Path screenshotImageFilename;
			buw::Path referenceImageFilename;
			buw::Path differenceImageFilename;
		};

		class ImageTester
		{
		public:
			ImageTester() :
				allTestSucceeded_(true)
			{

			}

			void writeTestHomepage();

			void createTest(const testDescription& td);

			bool testImage(
				const buw::Path& screenshotImageFilename, 
				const buw::Path& referenceImageFilename,
				const buw::Path& differenceImageFilename);

			bool didAllTestSucceed() const;

		private:
			std::vector<testDescription>	testDesciptions_;
			bool							allTestSucceeded_;

		};
	}
}

namespace buw
{
	using OpenInfraPlatform::UnitTesting::testDescription;
	using OpenInfraPlatform::UnitTesting::ImageTester;
}