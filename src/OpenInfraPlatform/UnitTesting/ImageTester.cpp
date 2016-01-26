/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "ImageTester.h"

#include "buw.BlueCore.Diagnostics.GraphicsCardInfo.h"

void OpenInfraPlatform::UnitTesting::ImageTester::writeTestHomepage()
{
	std::ofstream htmlPage("test_report.html");

	buw::GraphicsCardInfo gci;
	

	htmlPage << "<head>";
	htmlPage << "</head>";
	htmlPage << "<body>";
	
	htmlPage << "<h2>Current graphics card</h2> <br/>" << std::endl;
	htmlPage << "<b>Name: </b>" << gci.getName().toCString() << "<br/>" << std::endl;

	for (int i = 0; i < testDesciptions_.size(); i++)
	{
		htmlPage << "<h2>" << testDesciptions_[i].LandXMLFile << "</h2> <br/>" << std::endl;
		htmlPage << "<img src=\"" << testDesciptions_[i].referenceImageFilename << "\"> " << std::endl;
		htmlPage << "<img src=\"" << testDesciptions_[i].screenshotImageFilename << "\">" << std::endl;
		htmlPage << "<img src=\"" << testDesciptions_[i].differenceImageFilename << "\"> <br/>" << std::endl;
	}

	htmlPage << "Test";
	htmlPage << "</body>";

	htmlPage.close();
}

void OpenInfraPlatform::UnitTesting::ImageTester::createTest(const testDescription& td)
{
	testDesciptions_.push_back(td);
	testImage(td.screenshotImageFilename, td.referenceImageFilename, td.differenceImageFilename);
}

bool OpenInfraPlatform::UnitTesting::ImageTester::testImage(const buw::Path& screenshotImageFilename, const buw::Path& referenceImageFilename, const buw::Path& differenceImageFilename)
{
	buw::ReferenceCounted<buw::Image_3b> screenshotImage = buw::loadImageFromFile<buw::Image_3b>(screenshotImageFilename);
	buw::ReferenceCounted<buw::Image_3b> referenceImage = buw::loadImageFromFile<buw::Image_3b>(referenceImageFilename);
	buw::color3b diffColor(255, 0, 0);
	buw::ReferenceCounted<buw::Image_3b> diffImage = buw::createDifferenceImage(screenshotImage, referenceImage, &diffColor[0]);

	buw::storeImageAsFile(differenceImageFilename, diffImage.get());

	float mse = buw::MSE_PerceptionBased(referenceImage, screenshotImage);

	if (mse > 0.00001f)
	{
		BLUE_LOG_STREAM_EX("UnitTest", buw::eLogSeverityLevel::Error) << "Screenshot is not equal to reference image.";

		allTestSucceeded_ = false;

		return false;
	}
	else
		return true;
}

bool OpenInfraPlatform::UnitTesting::ImageTester::didAllTestSucceed() const
{
	return allTestSucceeded_;
}
