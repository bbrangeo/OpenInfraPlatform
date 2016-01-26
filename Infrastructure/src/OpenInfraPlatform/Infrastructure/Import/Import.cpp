#include "Import.h"

using namespace std;

OpenInfraPlatform::Infrastructure::Import::Import(const string& filename):
	filename_(filename)
{
	alignmentModel_ = buw::makeReferenceCounted<buw::AlignmentModel>();
	digitalElevationModel_ = buw::makeReferenceCounted<buw::DigitalElevationModel>();
}
buw::ReferenceCounted<buw::AlignmentModel> OpenInfraPlatform::Infrastructure::Import::getAlignmentModel()
{
	return alignmentModel_;
}
buw::ReferenceCounted<buw::DigitalElevationModel> OpenInfraPlatform::Infrastructure::Import::getDigitalElevationModel()
{
	return digitalElevationModel_;
}

