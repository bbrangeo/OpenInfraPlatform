#pragma once

#include "OpenInfraPlatform/Infrastructure/Import/Import.h"
#include "OpenInfraPlatform/Data/terrainDescription.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace DataManagement
	{

		class BLUEINFRASTRUCTURE_API MeshImport : public buw::Import
		{
		public:
			MeshImport(const std::string& filename, const buw::vector3d& offsetViewArea);

		};
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::DataManagement::MeshImport;
}

