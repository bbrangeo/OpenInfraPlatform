/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universit�t M�nchen
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "AbstractSyntaxTree.h"

std::ostream& OpenInfraPlatform::Infrastructure::operator << (std::ostream& os, AbstractSyntaxTree::Ptr& ast)
{
	ast->write(os);
	return os;
}