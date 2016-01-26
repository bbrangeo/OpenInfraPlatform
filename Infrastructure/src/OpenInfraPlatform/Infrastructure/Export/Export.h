#pragma once

#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/DigitalElevationModel.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/AlignmentModel.h"
#include <boost/noncopyable.hpp>
namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API Export : private boost::noncopyable
		{
		public:
			Export(buw::ReferenceCounted<buw::AlignmentModel> am, buw::ReferenceCounted<buw::DigitalElevationModel> dem, const std::string& filename);

		protected:
			buw::ReferenceCounted<buw::AlignmentModel>			alignmentModel_;
			buw::ReferenceCounted<buw::DigitalElevationModel>	digitalElevationModel_;
			std::string filename_;
		};

	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::Export;
}