/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once

#include "buw.BlueCore.Diagnostics.PerformanceLogger.h"

namespace OpenInfraPlatform
{
	class Benchmark
	{
	public:
		Benchmark();

		virtual ~Benchmark();

		static Benchmark& getInstance();

		void beginStartup();

		void finishStartup();

		void print();

		void start(const char* marker);

		void stop(const char* marker);

	private:
		buw::PerformanceLogger pl_;
	};
}
