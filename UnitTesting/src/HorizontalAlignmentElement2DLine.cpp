#include "buw.BlueInfrastructure.h"
#include "buw.BlueCore.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>

using namespace std;

namespace
{
	TEST(HorizontalAlignmentElement2DLine, getLength)
	{
		buw::vector2d a(0, 0);
		buw::vector2d b(1, 0);
		buw::vector2d c(2, 0);

		buw::HorizontalAlignmentElement2DLine::Ptr line1 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(a, b);
		buw::HorizontalAlignmentElement2DLine::Ptr line2 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(b, c);

		buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
		ha->addElement(line1);
		ha->addElement(line2);

		EXPECT_NEAR(ha->getLength(), 2, 0.001);

		for (double s = 0.0f; s < ha->getLength(); s += 0.1)
		{
			EXPECT_NEAR(ha->getPosition(s).x(), s, 0.001);
		}
	}

	TEST(HorizontalAlignmentElement2DLine, getLength2)
	{
		buw::vector2d a(0, 0);
		buw::vector2d b(0, 1);
		buw::vector2d c(0, 2);

		buw::HorizontalAlignmentElement2DLine::Ptr line1 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(a, b);
		buw::HorizontalAlignmentElement2DLine::Ptr line2 = std::make_shared<buw::HorizontalAlignmentElement2DLine>(b, c);

		buw::HorizontalAlignment2D::Ptr ha = std::make_shared<buw::HorizontalAlignment2D>();
		ha->addElement(line1);
		ha->addElement(line2);

		EXPECT_NEAR(ha->getLength(), 2, 0.001);

		for (double s = 0.0f; s < ha->getLength(); s += 0.1)
		{
			EXPECT_NEAR(ha->getPosition(s).y(), s, 0.001);
		}
	}
}