#include "OpenInfraPlatform/Infrastructure/Export/Export.h"

OpenInfraPlatform::Infrastructure::Export::Export(buw::ReferenceCounted<buw::AlignmentModel> am, buw::ReferenceCounted<buw::DigitalElevationModel> dem, const std::string& filename) :
	alignmentModel_(am),
	digitalElevationModel_(dem),
	filename_(filename)
{}