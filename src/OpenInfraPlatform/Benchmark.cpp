/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "Benchmark.h"

#include <iostream>

OpenInfraPlatform::Benchmark::Benchmark()
{

}

OpenInfraPlatform::Benchmark::~Benchmark()
{

}

void OpenInfraPlatform::Benchmark::print()
{
	pl_.print(std::cout);
}

void OpenInfraPlatform::Benchmark::finishStartup()
{
	pl_.stop("Startup");
}

void OpenInfraPlatform::Benchmark::beginStartup()
{
	pl_.start("Startup");
}

OpenInfraPlatform::Benchmark& OpenInfraPlatform::Benchmark::getInstance()
{
	static Benchmark instance;
	return instance;
}

void OpenInfraPlatform::Benchmark::start(const char* marker)
{
	pl_.start(marker);
}

void OpenInfraPlatform::Benchmark::stop(const char* marker)
{
	pl_.stop(marker);
}




