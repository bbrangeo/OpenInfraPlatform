/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#include "PointCloudProcessing.h"
#include "buw.BlueCore.h"
#include <liblas/liblas.hpp>

BLUEINFRASTRUCTURE_API void OpenInfraPlatform::Infrastructure::importLASPointCloud(
	const char* filename,
	std::vector<OpenInfraPlatform::Infrastructure::LaserPoint>& pointCloud)
{
	// see http://www.liblas.org/tutorial/cpp.html
	std::ifstream ifs;

	ifs.open(filename, std::ios::in | std::ios::binary);

	liblas::ReaderFactory f;
	liblas::Reader reader = f.CreateWithStream(ifs);

	liblas::Header const& header = reader.GetHeader();

	std::cout << "Compressed: " << (header.Compressed() == true) ? "true" : "false";
	std::cout << "Signature: " << header.GetFileSignature() << '\n';
	std::cout << "Points count: " << header.GetPointRecordsCount() << '\n';

	while (reader.ReadNextPoint())
	{
		liblas::Point const& p = reader.GetPoint();

		float colorRange = std::numeric_limits<liblas::Color::value_type>::max();
		//p.GetColor()
		pointCloud.push_back({
			buw::vector3d(p.GetX(), p.GetY(), p.GetZ()),
			buw::color3f(p.GetColor().GetRed() / colorRange, p.GetColor().GetGreen() / colorRange, p.GetColor().GetBlue() / colorRange) });

	}
}