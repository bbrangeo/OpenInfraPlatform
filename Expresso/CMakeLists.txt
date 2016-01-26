cmake_minimum_required(VERSION 3.3.0)
project(Expresso)

find_package(BISON)
find_package(FLEX)

bison_target(Parser ${CMAKE_CURRENT_SOURCE_DIR}/ExpressBinding/src/OpenInfraPlatform/ExpressBinding/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner ${CMAKE_CURRENT_SOURCE_DIR}/ExpressBinding/src/OpenInfraPlatform/ExpressBinding/tokens.l  ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
add_flex_bison_dependency(Scanner Parser)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB OpenInfraPlatform_ExpressBinding_Source	ExpressBinding/src/OpenInfraPlatform/ExpressBinding/*.*)	

source_group(OpenInfraPlatform\\ExpressBinding								FILES ${OpenInfraPlatform_ExpressBinding_Source})	

add_executable(Expresso
	${OpenInfraPlatform_ExpressBinding_Source}
	${FLEX_Scanner_OUTPUTS} 
	${BISON_Parser_OUTPUTS}
)
