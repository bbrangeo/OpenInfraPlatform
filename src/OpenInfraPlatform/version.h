/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\author			Daniel Below <daniel.below@tum.de>
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_version_8381e70b_23e7_421b_aebc_017552d70cec_h
#define OpenInfraPlatform_version_8381e70b_23e7_421b_aebc_017552d70cec_h

#include <boost/noncopyable.hpp>
#include <string>

namespace OpenInfraPlatform
{
	
static const std::string	NAME         		= std::string("TUM Open Infra Platfrom");

static const int      		VERSION_MAJOR		= 1;
static const int      		VERSION_MINOR		= 0;
static const int            VERSION_BUILD 		= 0; // 0 for alpha, 1 for beta, 2 for release candidate, 3 for (final) release
static const int			VERSION_REVISION    = 1269;

static const std::string	VERSION_STR = std::string { 
										std::to_string(VERSION_MAJOR) + "." + 
										std::to_string(VERSION_MINOR) + "." + 
										std::to_string(VERSION_BUILD) + "." + 
										std::to_string(VERSION_REVISION) 
							};

#if BLUE_DEBUG
static const std::string    VERSION_BUILD_TAG   = std::string("debug");
#else
static const std::string    VERSION_BUILD_TAG   = std::string("release");
#endif

#if   BLUE_ARCHITECTURE_TYPE == BLUE_ARCHITECTURE_32
static const std::string    VERSION_ARCH_TAG   = std::string("x86");
#elif BLUE_ARCHITECTURE_TYPE == BLUE_ARCHITECTURE_64
static const std::string    VERSION_ARCH_TAG   = std::string("x64");
#endif

} // end namespace OpenInfraPlatform

// namespace buw already contains those (from BlueFramework-2.4.624\Core\src\BlueFramework\Core\version.h)
/*
namespace buw
{
	using OpenInfraPlatform::NAME;
	using OpenInfraPlatform::VERSION_MAJOR;
	using OpenInfraPlatform::VERSION_MINOR;
	using OpenInfraPlatform::VERSION_REVISION;
	using OpenInfraPlatform::VERSION_STR;
	using OpenInfraPlatform::VERSION_ARCH_TAG;
	using OpenInfraPlatform::VERSION_BUILD_TAG;
}
*/

#endif // end define OpenInfraPlatform_version_8381e70b_23e7_421b_aebc_017552d70cec_h