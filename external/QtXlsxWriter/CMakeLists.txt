project(QtXlsxWriter)

add_definitions(-DNOMINMAX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	../../Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	../../Release)
set(CMAKE_PDB_OUTPUT_DIRECTORY_DEBUG 	    ../../Debug)
set(CMAKE_PDB_OUTPUT_DIRECTORY_RELEASE 	    ../../Release)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_MODULE_PATH ${PROJECT_Source_DIR}/build/)
# Compiler settings
if (WIN32)
	# Standard:          /DWIN32 /D_WINDOWS /W3 /Zm1000 /EHsc /GR
	set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W4 /Zi /EHsc /GR- /MP /openmp /bigobj")
endif (WIN32)

if (UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++0x -g -Wall -fPIC")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_UNIX_DEBUG")
endif (UNIX)

set(CMAKE_DEBUG_POSTFIX  "d")



# Unicode rules!
ADD_DEFINITIONS(-D_UNICODE -DQT_NO_KEYWORDS -DQT_BUILD_XLSX_LIB)

if (WIN32)
    # TODO: for now this only works on windows. Change BlueApplication.h to support GCC
    #ADD_DEFINITIONS(-DBLUEAPPLICATION_EXPORT)
endif(WIN32)

file(GLOB QtXlsxWriter_Source			src/xlsx/*.cpp src/xlsx/*.h)

# Qt related stuff

source_group(QtXlsxWriter	FILES ${QtXlsxWriter_Source})

include_directories(
					${CMAKE_CURRENT_BINARY_DIR} # Qt generated files will be located here
					
)

ADD_LIBRARY(QtXlsxWriter SHARED
	${QtXlsxWriter_Source}
)

target_link_libraries(QtXlsxWriter
	# Qt5
	${Qt5Core_QTMAIN_LIBRARIES}  # <-- New target available via find_package ( Qt5Core ) 
) 

# Use the Widgets module from Qt 5.
qt5_use_modules(QtXlsxWriter Xml XmlPatterns Widgets)
