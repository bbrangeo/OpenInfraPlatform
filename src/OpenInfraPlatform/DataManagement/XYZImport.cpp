#include "OpenInfraPlatform/DataManagement/XYZImport.h"

#include <iostream>
#include "buw.BlueEngine.h"

OpenInfraPlatform::DataManagement::XYZImport::XYZImport(const std::string& filename, const buw::vector2d& start, const buw::vector2d& end) :
	buw::Import(filename)
{
	// read the data
	double x, y, z;
	std::vector<buw::vector3d> positions;

	buw::SimpleLexer sl(filename.c_str());

	if (!filename.empty())
	{
		sl.SetIgnoreWhitespace(true);
		buw::Token token;

		// read token
		bool eof = false;
		while (sl.ReadToken(token))
		{
			while (token.GetType() == buw::eTokenType::New_Line)
			{
				if (!sl.ReadToken(token))
				{
					eof = true;
					break;
				}
			}

			if (eof)
			{
				break;
			}

			BLUE_ASSERT(token.GetType() == buw::eTokenType::Float ||
				token.GetType() == buw::eTokenType::Integer,
				"Invalid token");
			x = token.GetDoubleValue();

			sl.ReadToken(token);
			BLUE_ASSERT(token.GetType() == buw::eTokenType::Float ||
				token.GetType() == buw::eTokenType::Integer,
				"Invalid token");
			y = token.GetDoubleValue();

			sl.ReadToken(token);
			BLUE_ASSERT(token.GetType() == buw::eTokenType::Float ||
				token.GetType() == buw::eTokenType::Integer,
				"Invalid token");
			z = token.GetDoubleValue();

			buw::vector3d tempv(x, y, z);
			if (tempv.x() < start.x() || tempv.y() < start.y() ||
				tempv.x() > end.x() || tempv.y() > end.y())
				continue;

			positions.push_back(tempv);
		}

		buw::ReferenceCounted<buw::Surface> surface = buw::createSurfaceFromXYZPoints(positions);
		digitalElevationModel_->addSurface(surface);
	}
}