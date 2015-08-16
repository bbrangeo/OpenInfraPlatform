/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\author			Daniel Below <daniel.below@tum.de>
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "HorizontalAlignmentElement2D.h"

#include "qapplication.h"

OpenInfraPlatform::Infrastructure::eHorizontalAlignmentType
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2D::getAlignmentType() const
{
	return eHorizontalAlignmentType::Unknown;
}

bool OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2D::genericQuery(const int /*id*/, void* /*result*/) const
{
	return false;
}

std::string OpenInfraPlatform::Infrastructure::horizontalAlignmentTypeToString(const eHorizontalAlignmentType type)
{
	switch (type)
	{
	case eHorizontalAlignmentType::Line:
		return QApplication::tr("Line").toStdString();

	case eHorizontalAlignmentType::Arc:
		return QApplication::tr("Arc").toStdString();

	case eHorizontalAlignmentType::Clothoid:
		return QApplication::tr("Clothoid").toStdString();

	case eHorizontalAlignmentType::Unknown:
		return QApplication::tr("Unknown").toStdString();

	default:
		break;
	}

	return QApplication::tr("Unknown").toStdString();
}

std::ostream& OpenInfraPlatform::Infrastructure::operator<<(std::ostream& os, const  OpenInfraPlatform::Infrastructure::eHorizontalAlignmentType hat)
{
	os << horizontalAlignmentTypeToString(hat);
	return os;
}