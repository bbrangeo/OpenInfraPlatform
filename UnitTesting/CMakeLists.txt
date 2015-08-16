project(UnitTests)

# For make-based builds, defines make target named test.
# For Visual Studio builds, defines Visual Studio project named RUN_TESTS.
enable_testing()

# Google Test
set(gtest_force_shared_crt ON CACHE INTERNAL "")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/external/gtest-1.6.0)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/build/)

set(CMAKE_DEBUG_POSTFIX  "d")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	../Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	../Release)

link_directories(	
	${Boost_LIBRARY_DIRS} 
	${VLD_LIBRARIES_DIR}
	../external/Oklabi
)

include_directories(
	${BLUEFRAMEWORK_INCLUDE_DIR}
	../Infrastructure/canonicalHeaders
	${Boost_INCLUDE_DIR}
	external/gtest-1.6.0/include
)

file(GLOB BlueFramework_BLUE_TEST src/*.*)
source_group(BlueTest FILES ${BlueFramework_BLUE_TEST})

add_executable(OpenInfraPlatform.UnitTests
	${BlueFramework_BLUE_TEST}
)

target_link_libraries(OpenInfraPlatform.UnitTests
	# BlueFramework
	${BLUEFRAMEWORK_BLUECORE_LIBRARY}
	${BLUEFRAMEWORK_BLUEIMAGEPROCESSING_LIBRARY}
	${BLUEFRAMEWORK_BLUERASTERIZER_LIBRARY}
	${BLUEFRAMEWORK_BLUEENGINE_LIBRARY}
	${BLUEFRAMEWORK_BLUEAPPLICATION_LIBRARY}
	
	# OpenInfraPlatform
	OpenInfraPlatform.Infrastructure
	
	# Boost
	${Boost_FILESYSTEM_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
	
	# Googletest
	gtest			
)
