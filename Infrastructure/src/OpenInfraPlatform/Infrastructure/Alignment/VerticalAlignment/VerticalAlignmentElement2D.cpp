/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "VerticalAlignmentElement2D.h"

OpenInfraPlatform::Infrastructure::eVerticalAlignmentType
OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2D::getAlignmentType() const
{
	return eVerticalAlignmentType::Unknown;
}

bool OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2D::genericQuery(const int /*id*/, void* /*result*/) const
{
	return false;
}

std::ostream& OpenInfraPlatform::Infrastructure::operator<<(std::ostream& os, VerticalAlignmentElement2D::ConstPtr vae)
{
	os << "[";

	switch (vae->getAlignmentType())
	{
	case buw::eVerticalAlignmentType::Line:
		os << "VAElement2DLine    ";
		break;
	case buw::eVerticalAlignmentType::Arc:
		os << "VAElement2DArc     ";
		break;
	case buw::eVerticalAlignmentType::Parabola:
		os << "VAElement2DParabola";
		break;
	default:
		break;
	}

	os << " " << vae->getStartPosition() << " " << vae->getEndPosition();

	os << "]";

	return os;
}

std::ostream& OpenInfraPlatform::Infrastructure::operator<<(std::ostream& os, const OpenInfraPlatform::Infrastructure::eVerticalAlignmentType vat)
{
	switch (vat)
	{
	case eVerticalAlignmentType::Line:
		os << "Line";
		break;
	case eVerticalAlignmentType::Arc:
		os << "Arc";
		break;
	case eVerticalAlignmentType::Parabola:
		os << "Parabola";
		break;
	default:
		os << "Unknown";
		break;
	}

	return os;
}

std::string OpenInfraPlatform::Infrastructure::verticalAlignmentTypeToString(const OpenInfraPlatform::Infrastructure::eVerticalAlignmentType type)
{
	std::stringstream ss;
	ss << type;
	return ss.str();
}
