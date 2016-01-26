#pragma once

#include "OpenInfraPlatform/Infrastructure/Import/Import.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace DataManagement
	{
		class BLUEINFRASTRUCTURE_API XYZImport : public buw::Import
		{
		public:
			XYZImport(const std::string& filename, const buw::vector2d& start, const buw::vector2d& end);

		};
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::DataManagement::XYZImport;
}

