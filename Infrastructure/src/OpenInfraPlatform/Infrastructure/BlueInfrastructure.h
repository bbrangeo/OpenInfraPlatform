/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_16452b8b_ee1f_4293_ac34_7c7e66b5395c_h
#define OpenInfraPlatform_Infrastructure_16452b8b_ee1f_4293_ac34_7c7e66b5395c_h

#include "BlueFramework/Core/platform.h"
       
#ifdef BLUEINFRASTRUCTURE_EXPORT
#	if BLUE_PLATFORM == BLUE_PLATFORM_WINDOWS
#		define BLUEINFRASTRUCTURE_API __declspec(dllexport)
#	else
#		define BLUEINFRASTRUCTURE_API
#	endif
#else
#	define BLUEINFRASTRUCTURE_API
#	if BLUE_PLATFORM == BLUE_PLATFORM_WINDOWS && BLUE_ARCHITECTURE_TYPE == BLUE_ARCHITECTURE_64 && BLUE_COMPILER == BLUE_COMPILER_MSVC
// try to link library automatically on Visual Studio 2010/2012/2013
// todo: find out which compiler we are using
// todo: find out if we use debug or release mode 
//#	pragma comment(lib, "BlueCored.lib")  
//#	pragma comment(lib, "BlueCore.lib")  
#   endif
#endif

#endif // end define OpenInfraPlatform_Infrastructure_BlueInfrastructure_16452b8b_ee1f_4293_ac34_7c7e66b5395c_h




