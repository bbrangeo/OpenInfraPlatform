#include "buw.BlueInfrastructure.h"
#include "buw.BlueCore.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>

using namespace std;

namespace
{
	TEST(Okstra, ExportImport)
	{
		buw::LandXmlImport LandXMLImporter("../testdata/LandXML/Mainbruecke_Klingenberg.xml");
		
		buw::OkstraExport OkstraExporter(
			2, 
			16,
			LandXMLImporter.getAlignmentModel(),
			LandXMLImporter.getDigitalElevationModel(), 
			"test.xml"
		);

		buw::OkstraImport OkstraImporter("test.xml");

		int alignmentCount1 = LandXMLImporter.getAlignmentModel()->getAlignmentCount();
		int alignmentCount2 = OkstraImporter.getAlignmentModel()->getAlignmentCount();

		buw::ReferenceCounted<buw::Alignment2DBased3D> a1 = std::static_pointer_cast<buw::Alignment2DBased3D>(LandXMLImporter.getAlignmentModel()->getAlignment(0));
		int alignmentElementCount1 = a1->getHorizontalAlignment()->getAlignmentElementCount();

		buw::ReferenceCounted<buw::Alignment2DBased3D> a2 = std::static_pointer_cast<buw::Alignment2DBased3D>(OkstraImporter.getAlignmentModel()->getAlignment(0));
		int alignmentElementCount2 = a2->getHorizontalAlignment()->getAlignmentElementCount();

		EXPECT_EQ(alignmentCount1, alignmentCount2);
		EXPECT_EQ(alignmentElementCount1, alignmentElementCount2);
	}
}