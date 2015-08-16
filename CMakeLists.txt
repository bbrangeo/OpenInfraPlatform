# Copyright (c) 2015 Julian Amann <vertexwahn@gmx.de>
cmake_minimum_required(VERSION 3.1.0)

option(OIP_USE_PREBUILD_EARLYBINDING_LIBS "Set to OFF to build early binding by yourself" OFF)

project(OpenInfraPlatform)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_definitions(-D_UNICODE # Unicode rules; No qt keywords; Export bluecore
				-DQT_NO_KEYWORDS 
				-D_VARIADIC_MAX=10 # Visual Studio 2012 set VARIDAIC_MAX default to 5 which is not enough for googletest to build
				)  # -DNOMINMAX does not work because GDI+ needs these macros
				
# Compiler settings			
if (WIN32)
	# Standard:          /DWIN32 /D_WINDOWS /W3 /Zm1000 /EHsc /GR
	set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W4 /Zi /EHsc /GR /MP /openmp /bigobj") 
endif (WIN32)

# tell cmake where to look for our scripts
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)

# Visual Studio expected
set(Boost_USE_STATIC_LIBS   ON)
find_package(Boost				1.57.0 COMPONENTS signals system filesystem thread program_options python3 REQUIRED)
find_package(VLD 					   REQUIRED)
find_package(BlueFramework 			   REQUIRED)

find_package(PythonLibs 		3.4.2  REQUIRED)

# Find the QtWidgets library
cmake_policy(SET CMP0020 NEW)
find_package( Qt5Core 			5.4.0 REQUIRED)
find_package( Qt5Xml 			5.4.0 REQUIRED)
find_package( Qt5XmlPatterns 	5.4.0 REQUIRED)
find_package( Qt5Declarative 	5.4.0 REQUIRED)
find_package( Qt5WebKit		 	5.4.0 REQUIRED)
find_package( Qt5WebKitWidgets 	5.4.0 REQUIRED)
find_package( Qt5Widgets	 	5.4.0 REQUIRED)
find_package( Qt5Network	 	5.4.0 REQUIRED)
find_package( Qt5Svg		 	5.4.0 REQUIRED)
find_package( Qt5PrintSupport 	5.4.0 REQUIRED)
find_package( Qt5LinguistTools	5.4.0 REQUIRED)

# macro for precompiled header - see also http://stackoverflow.com/questions/148570/using-pre-compiled-headers-with-cmake
#MACRO(ADD_MSVC_PRECOMPILED_HEADER PrecompiledHeader PrecompiledSource SourcesVar)
#  IF(MSVC)
#    GET_FILENAME_COMPONENT(PrecompiledBasename ${PrecompiledHeader} NAME_WE)
#    SET(PrecompiledBinary "${CMAKE_CURRENT_BINARY_DIR}/${PrecompiledBasename}.pch")
#    SET(Sources ${${SourcesVar}})
#
#    SET_SOURCE_FILES_PROPERTIES(${PrecompiledSource}
#                                PROPERTIES COMPILE_FLAGS "/Yc\"${PrecompiledHeader}\" /Fp\"${PrecompiledBinary}\""
#                                           OBJECT_OUTPUTS "${PrecompiledBinary}")
#    SET_SOURCE_FILES_PROPERTIES(${Sources}
#                                PROPERTIES COMPILE_FLAGS "/Yu\"${PrecompiledHeader}\" /FI\"${PrecompiledHeader}\" /Fp\"${PrecompiledBinary}\""
#                                           OBJECT_DEPENDS "${PrecompiledBinary}")  
#    # Add precompiled header to SourcesVar
#    LIST(APPEND ${SourcesVar} ${PrecompiledSource})
#  ENDIF(MSVC)
#ENDMACRO(ADD_MSVC_PRECOMPILED_HEADER)

# BUWFramework Copy Binaries
BLUEFRAMEWORK_COPY_BINARIES2(${CMAKE_BINARY_DIR})

# Fervor: Simple multiplatform (Qt-based) application update tool inspired by Sparkle
set(FERVOR_APP_NAME "TUM Open Infra Platform 2015")
set(FERVOR_APP_VERSION "0.1.0")
add_subdirectory(external/fervor)

# QtXlsxWriter
add_subdirectory(external/QtXlsxWriter)

# QSimpleUpdater
add_subdirectory(external/QSimpleUpdater)

# libLAS
add_subdirectory(external/libLAS-1.7.0)

add_subdirectory(external/qhull)
include_directories(external/qhull/src)

#zlib
add_subdirectory(external/zlib/src)
include_directories(external/zlib/src)

#####################################################################################################
# add carve
#####################################################################################################

#add_definitions(-DCARVE_SYSTEM_BOOST) # use system boost directories

include_directories(external/carve/include)
include_directories(${CMAKE_BINARY_DIR}/external/carve/include) #for out of source builds
include_directories(external/carve/common)
add_subdirectory(external/carve)
set_target_properties(carve 								PROPERTIES FOLDER "ThirdParty/carve")

function(add_carve_target_to_thirdparty tgt)
	if(TARGET ${tgt})
		set_target_properties(${tgt}						PROPERTIES FOLDER "ThirdParty/carve")
	endif()
endfunction()

function(add_carve_test_target_to_thirdparty tgt)
	if(TARGET ${tgt})
		set_target_properties(${tgt}						PROPERTIES FOLDER "ThirdParty/carve/test")
	endif()
endfunction()

add_carve_target_to_thirdparty(carve_fileformats)
add_carve_target_to_thirdparty(carve_misc)
add_carve_target_to_thirdparty(close_manifold)
add_carve_target_to_thirdparty(cutgraph)					
add_carve_target_to_thirdparty(convert)							
add_carve_target_to_thirdparty(extrude)							
add_carve_target_to_thirdparty(face_merge)
add_carve_target_to_thirdparty(gloop_model)
add_carve_target_to_thirdparty(gloop_image)
add_carve_target_to_thirdparty(gloop_math)
add_carve_target_to_thirdparty(intersect)
#add_carve_target_to_thirdparty(mesh_simplify)
#add_carve_target_to_thirdparty(selfintersect)
add_carve_target_to_thirdparty(slice)
add_carve_target_to_thirdparty(test_eigen)
add_carve_target_to_thirdparty(test_aabb)
add_carve_target_to_thirdparty(test_geom)
add_carve_target_to_thirdparty(test_rescale)
add_carve_target_to_thirdparty(test_spacetree)
add_carve_target_to_thirdparty(test_carve_polyhedrons_2)
add_carve_target_to_thirdparty(tetrahedron)
add_carve_target_to_thirdparty(triangulate)

# Earlybinding
if(OIP_USE_PREBUILD_EARLYBINDING_LIBS)
	include_directories(
		Ifc2x3/src
		Ifc4/src
		IfcAlignment/src
		IfcBridge/src
		IfcRoad/src
		ExpressBinding/src
		IfcTunnel/src
	)	
	
	link_directories(	
		prebuild_libs/vs2013/x64
	)	
else(OIP_USE_PREBUILD_EARLYBINDING_LIBS)
	# add Ifc2x3
	add_subdirectory(Ifc2x3)
	include_directories(Ifc2x3/src)

	# add Ifc4
	add_subdirectory(Ifc4)
	include_directories(Ifc4/src)
	
	# add IfcAlignment
	add_subdirectory(IfcAlignment)
	include_directories(IfcAlignment/src)
	
	# add IfcBridge
	add_subdirectory(IfcBridge)
	include_directories(IfcBridge/src)
	
	# add IfcRoad
	add_subdirectory(IfcRoad)
	include_directories(IfcRoad/src)
	
	# add ExpressBinding
	add_subdirectory(ExpressBinding)
	include_directories(ExpressBinding/src)
	
	# add IfcTunnel
	add_subdirectory(IfcTunnel)
	include_directories(IfcTunnel/src)
endif(OIP_USE_PREBUILD_EARLYBINDING_LIBS)

# add source directory
add_subdirectory(Infrastructure)
include_directories(Infrastructure/src)

add_subdirectory(UnitTesting)

add_definitions(-DNOMINMAX)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

file(GLOB OpenInfraPlatform_QtPropertyBrowser_Source 				src/QtPropertyBrowser/*.*)
		
file(GLOB OpenInfraPlatform_Data_Source 							src/OpenInfraPlatform/Data/*.*)	
file(GLOB OpenInfraPlatform_DataManagement_Command_Source 			src/OpenInfraPlatform/DataManagement/Command/*.*)						
file(GLOB OpenInfraPlatform_DataManagement_Source 					src/OpenInfraPlatform/DataManagement/*.*)		
file(GLOB OpenInfraPlatform_IfcGeometryConverter_Source  			src/OpenInfraPlatform/IfcGeometryConverter/*.*)		
file(GLOB OpenInfraPlatform_Shader_D3D11_Source 					src/OpenInfraPlatform/Shader/D3D11/*.*)			
file(GLOB OpenInfraPlatform_Shader_GL4x_Source 						src/OpenInfraPlatform/Shader/GL4x/*.*)			
file(GLOB OpenInfraPlatform_Shader_Source 							src/OpenInfraPlatform/Shader/*.*)		
file(GLOB OpenInfraPlatform_Source									src/OpenInfraPlatform/*.*)
file(GLOB OpenInfraPlatform_UnitTesting_Source						src/OpenInfraPlatform/UnitTesting/*.*)			
file(GLOB OpenInfraPlatform_UserInterface_ColorPicker_Source		src/OpenInfraPlatform/UserInterface/ColorPicker/*.*)						
file(GLOB OpenInfraPlatform_UserInterface_Tools_Source				src/OpenInfraPlatform/UserInterface/Tools/*.*)	
file(GLOB OpenInfraPlatform_UserInterface_Source 					src/OpenInfraPlatform/UserInterface/*.*)				
file(GLOB OpenInfraPlatform_UserInterface_View2DWindow			 	src/OpenInfraPlatform/UserInterface/View2DWindow/*.*)					
file(GLOB OpenInfraPlatform_UserInterface_ViewPanel_Source 			src/OpenInfraPlatform/UserInterface/ViewPanel/*.*)						

source_group(OpenInfraPlatform										FILES ${OpenInfraPlatform_Source})						
source_group(OpenInfraPlatform\\Data								FILES ${OpenInfraPlatform_Data_Source})			
source_group(OpenInfraPlatform\\DataManagement						FILES ${OpenInfraPlatform_DataManagement_Source})						
source_group(OpenInfraPlatform\\DataManagement\\Command				FILES ${OpenInfraPlatform_DataManagement_Command_Source})
source_group(OpenInfraPlatform\\IfcGeometryConverter				FILES ${OpenInfraPlatform_IfcGeometryConverter_Source})								
source_group(OpenInfraPlatform\\Shader								FILES ${OpenInfraPlatform_Shader_Source})				
source_group(OpenInfraPlatform\\Shader\\D3D11						FILES ${OpenInfraPlatform_Shader_D3D11_Source})						
source_group(OpenInfraPlatform\\Shader\\GL4x						FILES ${OpenInfraPlatform_Shader_GL4x_Source})					
source_group(OpenInfraPlatform\\UnitTesting  						FILES ${OpenInfraPlatform_UnitTesting_Source})						
source_group(OpenInfraPlatform\\UserInterface						FILES ${OpenInfraPlatform_UserInterface_Source})						
source_group(OpenInfraPlatform\\UserInterface\\ColorPicker			FILES ${OpenInfraPlatform_UserInterface_ColorPicker_Source})									
source_group(OpenInfraPlatform\\UserInterface\\Tools				FILES ${OpenInfraPlatform_UserInterface_Tools_Source})	
source_group(OpenInfraPlatform\\UserInterface\\View2DWindow			FILES ${OpenInfraPlatform_UserInterface_View2DWindow})									
source_group(OpenInfraPlatform\\UserInterface\\ViewPanel			FILES ${OpenInfraPlatform_UserInterface_ViewPanel_Source})								
source_group(QtPropertyBrowser										FILES ${OpenInfraPlatform_QtPropertyBrowser_Source})

set_property(SOURCE ${OpenInfraPlatform_Shader_D3D11_Source} PROPERTY VS_SHADER_TYPE Vertex)
set_property(SOURCE ${OpenInfraPlatform_Shader_D3D11_Source} PROPERTY VS_SHADER_ENTRYPOINT VS_main)
set_property(SOURCE ${OpenInfraPlatform_Shader_D3D11_Source} PROPERTY VS_SHADER_MODEL 5.0)
set_property(SOURCE ${OpenInfraPlatform_Shader_D3D11_Source} PROPERTY PS_SHADER_TYPE PIXEL)
set_property(SOURCE ${OpenInfraPlatform_Shader_D3D11_Source} PROPERTY PS_SHADER_ENTRYPOINT PS_main)
set_property(SOURCE ${OpenInfraPlatform_Shader_D3D11_Source} PROPERTY PS_SHADER_MODEL 5.0)

file(GLOB BlueFramework_GraphicsEngine_Source 					src/BlueFramework/GraphicsEngine/*.*)
source_group(BlueFramework\\GraphicsEngine						FILES ${BlueFramework_GraphicsEngine_Source})

file(GLOB BlueFramework_Core_Source 							src/BlueFramework/Core/*.*)
source_group(BlueFramework\\Core								FILES ${BlueFramework_Core_Source})

IF(NOT QT_LRELEASE_EXECUTABLE AND NOT Qt5_LRELEASE_EXECUTABLE)
	MESSAGE(WARNING "Could not find lrelease. Your build won't contain translations.")
ENDIF(NOT QT_LRELEASE_EXECUTABLE AND NOT Qt5_LRELEASE_EXECUTABLE)

#ADD_MSVC_PRECOMPILED_HEADER(
#	"precompiled.h" 
#	"src/OpenInfraPlatform/precompiled.cpp" 
#	OpenInfraPlatform_UserInterface_Source)

include_directories(
	${BLUEFRAMEWORK_INCLUDE_DIR}
	${PYTHON_INCLUDE_DIRS}
	${Boost_INCLUDE_DIR}
	${CMAKE_CURRENT_BINARY_DIR} # Qt generated files will be located here
	${VLD_INCLUDE_DIR}
	external/fervor
	src
	external/QtXlsxWriter/src/xlsx
	external/QSimpleUpdater/src
	external/QSimpleUpdater/dialogs
	Infrastructure/canonicalHeaders
	external/zlib/include
)

link_directories(	
	${Boost_LIBRARY_DIRS} 
	${VLD_LIBRARIES_DIR}
	external/Oklabi
	${CMAKE_CURRENT_BINARY_DIR}/external/zlib/src
)

# Qt related stuff
set(OpenInfraPlatform_UIS
	src/OpenInfraPlatform/Forms/CodeEditorWindow.ui
	src/OpenInfraPlatform/Forms/MainWindow.ui
	src/OpenInfraPlatform/Forms/PreferencesDialog.ui
	src/OpenInfraPlatform/Forms/XYZImportDialog.ui
	src/OpenInfraPlatform/Forms/GenerateTerrain.ui
	src/OpenInfraPlatform/Forms/VerticalAlignmentWindow.ui
	src/OpenInfraPlatform/Forms/CurvatureWindow.ui
	src/OpenInfraPlatform/Forms/ExportIfcAlignmentDialog.ui
	src/OpenInfraPlatform/Forms/ExportExcel.ui
	src/OpenInfraPlatform/Forms/ExportIfcZipDialog.ui
	src/OpenInfraPlatform/Forms/CreateClothoid.ui
	src/OpenInfraPlatform/Forms/CreateLineClothoidClothoidLine.ui
	src/OpenInfraPlatform/Forms/CreateLineClothoidArcClothoidLine.ui
	src/OpenInfraPlatform/Forms/CreateLineArcArcLine.ui
	src/OpenInfraPlatform/Forms/CreateLineArcArcArcLine.ui
	src/OpenInfraPlatform/Forms/CreateArcClothoidArc.ui
	src/OpenInfraPlatform/Forms/CreateArcClothoidClothoidArc.ui
	src/OpenInfraPlatform/Forms/CreateClothoidParallel.ui
	src/OpenInfraPlatform/Forms/CreateArcClothoidArcMeth2.ui
	src/OpenInfraPlatform/Forms/CreateArcClothoidClothoidArcMeth2.ui
	
	external/QSimpleUpdater/src/dialogs/download_dialog.ui
) 

source_group(OpenInfraPlatform\\UserInterface\\Forms					FILES ${OpenInfraPlatform_UIS})

set(OpenInfraPlatform_RC
	src/OpenInfraPlatform/Resources/OpenInfraPlatform.qrc
	src/QtPropertyBrowser/qtpropertybrowser.qrc
)

QT5_ADD_RESOURCES(OpenInfraPlatform_RC_SRCS ${OpenInfraPlatform_RC})
QT5_WRAP_UI(OpenInfraPlatform_UIS_H ${OpenInfraPlatform_UIS})

# Tell CMake to create the Qt5HelloWorld executable
add_executable(OpenInfraPlatform.UI
	${OpenInfraPlatform_QtPropertyBrowser_Source}
	${OpenInfraPlatform_UIS_H}
	${OpenInfraPlatform_RC_SRCS}
	${OpenInfraPlatform_Source}
	${OpenInfraPlatform_UserInterface_Source}
	${OpenInfraPlatform_UserInterface_ColorPicker_Source}
	${OpenInfraPlatform_UserInterface_Tools_Source}
	${OpenInfraPlatform_UserInterface_ViewPanel_Source}
	${OpenInfraPlatform_UserInterface_View2DWindow}
	${OpenInfraPlatform_UnitTesting_Source}
	${OpenInfraPlatform_Data_Source}
	${OpenInfraPlatform_DataManagement_Source}
	${OpenInfraPlatform_DataManagement_Command_Source}
	${OpenInfraPlatform_IfcGeometryConverter_Source}
	${OpenInfraPlatform_Shader_Source}
	${OpenInfraPlatform_Shader_D3D11_Source}
	${OpenInfraPlatform_Shader_GL4x_Source}
	${BlueFramework_GraphicsEngine_Source}
	${BlueFramework_Core_Source}
)
set(CMAKE_DEBUG_POSTFIX "d")
# Use the Widgets module from Qt 5.
qt5_use_modules(OpenInfraPlatform.UI Widgets Xml XmlPatterns WebKit WebKitWidgets Svg PrintSupport)

if(OIP_USE_PREBUILD_EARLYBINDING_LIBS)

	set(OpenInfraPlatform_Ifc2x3_LIBRARY_RELEASE	OpenInfraPlatform.Ifc2x3.lib)
	set(OpenInfraPlatform_Ifc2x3_LIBRARY_DEBUG		OpenInfraPlatform.Ifc2x3d.lib)
	
	set(OpenInfraPlatform_Ifc2x3_LIBRARY
		optimized 	${OpenInfraPlatform_Ifc2x3_LIBRARY_RELEASE}
		debug		${OpenInfraPlatform_Ifc2x3_LIBRARY_DEBUG})
		
	set(OpenInfraPlatform_Ifc4_LIBRARY_RELEASE		OpenInfraPlatform.Ifc4.lib)
	set(OpenInfraPlatform_Ifc4_LIBRARY_DEBUG		OpenInfraPlatform.Ifc4d.lib)
	
	set(OpenInfraPlatform_Ifc4_LIBRARY
		optimized 	${OpenInfraPlatform_Ifc4_LIBRARY_RELEASE}
		debug		${OpenInfraPlatform_Ifc4_LIBRARY_DEBUG})
	
	set(OpenInfraPlatform_IfcAlignment_LIBRARY_RELEASE	OpenInfraPlatform.IfcAlignment.lib)
	set(OpenInfraPlatform_IfcAlignment_LIBRARY_DEBUG	OpenInfraPlatform.IfcAlignmentd.lib)
	
	set(OpenInfraPlatform_IfcAlignment_LIBRARY
		optimized 	${OpenInfraPlatform_IfcAlignment_LIBRARY_RELEASE}
		debug		${OpenInfraPlatform_IfcAlignment_LIBRARY_DEBUG})
	
	set(OpenInfraPlatform_IfcBridge_LIBRARY_RELEASE	OpenInfraPlatform.IfcBridge.lib)
	set(OpenInfraPlatform_IfcBridge_LIBRARY_DEBUG	OpenInfraPlatform.IfcBridged.lib)
	
	set(OpenInfraPlatform_IfcBridge_LIBRARY
		optimized 	${OpenInfraPlatform_IfcBridge_LIBRARY_RELEASE}
		debug		${OpenInfraPlatform_IfcBridge_LIBRARY_DEBUG})
	
	set(OpenInfraPlatform_IfcRoad_LIBRARY_RELEASE	OpenInfraPlatform.IfcRoad.lib)
	set(OpenInfraPlatform_IfcRoad_LIBRARY_DEBUG		OpenInfraPlatform.IfcRoadd.lib)
	
	set(OpenInfraPlatform_IfcRoad_LIBRARY
		optimized 	${OpenInfraPlatform_IfcRoad_LIBRARY_RELEASE}
		debug		${OpenInfraPlatform_IfcRoad_LIBRARY_DEBUG})
		
	set(OpenInfraPlatform_IfcTunnel_LIBRARY_RELEASE	OpenInfraPlatform.IfcTunnel.lib)
	set(OpenInfraPlatform_IfcTunnel_LIBRARY_DEBUG	OpenInfraPlatform.IfcTunneld.lib)
	
	set(OpenInfraPlatform_IfcTunnel_LIBRARY
		optimized 	${OpenInfraPlatform_IfcTunnel_LIBRARY_RELEASE}
		debug		${OpenInfraPlatform_IfcTunnel_LIBRARY_DEBUG})
	
	target_link_libraries( OpenInfraPlatform.UI
		OpenInfraPlatform.Infrastructure
		# Early bindings
		${OpenInfraPlatform_Ifc2x3_LIBRARY}
		${OpenInfraPlatform_Ifc4_LIBRARY}
		${OpenInfraPlatform_IfcAlignment_LIBRARY}
		${OpenInfraPlatform_IfcBridge_LIBRARY}
		${OpenInfraPlatform_IfcRoad_LIBRARY}
		${OpenInfraPlatform_IfcTunnel_LIBRARY}
		# Qt
		Qt5::WinMain  # New target available via find_package ( Qt5Core )
		# BlueFramework
		${BLUEFRAMEWORK_BLUECORE_LIBRARY}
		${BLUEFRAMEWORK_BLUEIMAGEPROCESSING_LIBRARY}
		${BLUEFRAMEWORK_BLUERASTERIZER_LIBRARY}
		${BLUEFRAMEWORK_BLUEENGINE_LIBRARY}
		${BLUEFRAMEWORK_BLUEGL4XRENDERER_LIBRARY}
		${BLUEFRAMEWORK_BLUEAPPLICATION_LIBRARY}
		# External libs
		Fervor
		QtXlsxWriter
		QSimpleUpdater
		liblas
		carve
		${LAS_READER_LIB_NAME}
		# Python
		${PYTHON_LIBRARIES}
		zlibstatic
	)
elseif(OIP_USE_PREBUILD_EARLYBINDING_LIBS)
	target_link_libraries( OpenInfraPlatform.UI
		OpenInfraPlatform.Infrastructure
		# Early bindings
		OpenInfraPlatform.Ifc2x3
		OpenInfraPlatform.IfcAlignment
		OpenInfraPlatform.IfcBridge
		OpenInfraPlatform.IfcRoad
		# Qt
		Qt5::WinMain  # New target available via find_package ( Qt5Core )
		# BlueFramework
		${BLUEFRAMEWORK_BLUECORE_LIBRARY}
		${BLUEFRAMEWORK_BLUEIMAGEPROCESSING_LIBRARY}
		${BLUEFRAMEWORK_BLUERASTERIZER_LIBRARY}
		${BLUEFRAMEWORK_BLUEENGINE_LIBRARY}
		${BLUEFRAMEWORK_BLUEGL4XRENDERER_LIBRARY}
		${BLUEFRAMEWORK_BLUEAPPLICATION_LIBRARY}
		# External libs
		Fervor
		QtXlsxWriter
		QSimpleUpdater
		liblas
		carve
		${LAS_READER_LIB_NAME}
		# Python
		${PYTHON_LIBRARIES}
		zlibstatic
	)
endif(OIP_USE_PREBUILD_EARLYBINDING_LIBS)

target_link_libraries( OpenInfraPlatform.UI
	OpenInfraPlatform.Infrastructure
	OpenInfraPlatform.IfcBridge
	OpenInfraPlatform.IfcRoad
	OpenInfraPlatform.IfcAlignment
	OpenInfraPlatform.Ifc2x3
	Qt5::WinMain  # New target available via find_package ( Qt5Core )
	# BlueFramework
	${BLUEFRAMEWORK_BLUECORE_LIBRARY}
	${BLUEFRAMEWORK_BLUEIMAGEPROCESSING_LIBRARY}
	${BLUEFRAMEWORK_BLUERASTERIZER_LIBRARY}
	${BLUEFRAMEWORK_BLUEENGINE_LIBRARY}
	${BLUEFRAMEWORK_BLUEGL4XRENDERER_LIBRARY}
	${BLUEFRAMEWORK_BLUEAPPLICATION_LIBRARY}
	# External libs
	Fervor
	QtXlsxWriter
	QSimpleUpdater
	liblas
	carve
	${LAS_READER_LIB_NAME}
	# Python
	${PYTHON_LIBRARIES}
	zlibstatic
)

# OklabiCopyBinaries
add_custom_target(OklabiCopyBinaries
	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiGdal1264.dll		${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiGeos1264_c.dll	${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiKern1264.dll		${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiProj1264.dll		${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiZlib1264.dll		${CMAKE_BINARY_DIR}/Debug

	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiGdal1264.dll		${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiGeos1264_c.dll	${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiKern1264.dll		${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiProj1264.dll		${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/OklabiZlib1264.dll		${CMAKE_BINARY_DIR}/Release
	
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/res			${CMAKE_BINARY_DIR}/res
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/schema		${CMAKE_BINARY_DIR}/schema
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi/fbliste		${CMAKE_BINARY_DIR}/fbliste
	
	# Output Message
	COMMENT "Copying Oklabi binaries from ' ${CMAKE_CURRENT_SOURCE_DIR}/external/Oklabi' to '${CMAKE_BINARY_DIR}'" VERBATIM
)

# QtCopyBinaries
add_custom_target(Qt5CopyBinaries
	# todo: check if debug and release folder exist
	# debug version	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/libEGLd.dll				${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/libGLESv2d.dll				${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Cored.dll 				${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Guid.dll 				${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Declaratived.dll 		${CMAKE_BINARY_DIR}/Debug			
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Networkd.dll 			${CMAKE_BINARY_DIR}/Debug		
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5OpenGLd.dll 			${CMAKE_BINARY_DIR}/Debug		
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Scriptd.dll 			${CMAKE_BINARY_DIR}/Debug		
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Sqld.dll 				${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Widgetsd.dll 			${CMAKE_BINARY_DIR}/Debug		
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Xmld.dll 				${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5XmlPatternsd.dll 		${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5WebChanneld.dll			${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5WebKitd.dll				${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5WebKitWidgetsd.dll		${CMAKE_BINARY_DIR}/Debug			
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Multimediad.dll			${CMAKE_BINARY_DIR}/Debug		
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5MultimediaWidgetsd.dll	${CMAKE_BINARY_DIR}/Debug				
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5PrintSupportd.dll		${CMAKE_BINARY_DIR}/Debug			
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Sensorsd.dll			${CMAKE_BINARY_DIR}/Debug		
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Quickd.dll				${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Qmld.dll				${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Positioningd.dll		${CMAKE_BINARY_DIR}/Debug	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Svgd.dll				${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/icudt53.dll 				${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/icuin53.dll 				${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/icuuc53.dll 				${CMAKE_BINARY_DIR}/Debug
	
	# release version
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/libEGL.dll 				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/libGLESv2.dll				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Core.dll 				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Gui.dll 				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Declarative.dll 		${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Network.dll 			${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5OpenGL.dll 				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Script.dll 				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Sql.dll 				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Widgets.dll 			${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Xml.dll 				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5XmlPatterns.dll 		${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5WebChannel.dll			${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5WebKit.dll				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5WebKitWidgets.dll		${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Multimedia.dll			${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5MultimediaWidgets.dll	${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5PrintSupport.dll		${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Sensors.dll				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Quick.dll				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Qml.dll					${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Positioning.dll			${CMAKE_BINARY_DIR}/Release	
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Svg.dll					${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/icudt53.dll 				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/icuin53.dll 				${CMAKE_BINARY_DIR}/Release
	COMMAND	${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/icuuc53.dll 				${CMAKE_BINARY_DIR}/Release
	
	# Output Message
	COMMENT "Copying Ot binaries from '${Qt5Core_DIR}/../../bin/' to '${CMAKE_BINARY_DIR}'" VERBATIM
)

# Collect all translation files
FILE(GLOB Translation_TS Data/translations/*.ts)
QT5_ADD_TRANSLATION(OpenInfra_QMS ${Translation_TS})

add_custom_target(CopyOpenInfraPlatformUIResources
	ALL DEPENDS ${OpenInfra_QMS}
		
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/src/OpenInfraPlatform/Shader		${CMAKE_BINARY_DIR}/Shader
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/src/OpenInfraPlatform/Shader		${CMAKE_BINARY_DIR}/RoadXMLViewer/Shader
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/src/OpenInfraPlatform/Shader		${CMAKE_BINARY_DIR}/LandXMLViewer/Shader
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/testdata									${CMAKE_BINARY_DIR}/LandXMLViewer/testdata
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/src/OpenInfraPlatform/Style			${CMAKE_BINARY_DIR}/Style
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/UnitTesting								${CMAKE_BINARY_DIR}/UnitTesting
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/Data										${CMAKE_BINARY_DIR}/Data
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/testdata									${CMAKE_BINARY_DIR}/testdata
	COMMAND	${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/Data/DesignAutomation						${CMAKE_BINARY_DIR}/UnitTesting/Data/DesignAutomation
		
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Deutsch.qm								${CMAKE_BINARY_DIR}/Data/translations/Deutsch.qm
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/English.qm								${CMAKE_BINARY_DIR}/Data/translations/English.qm
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Espanol.qm								${CMAKE_BINARY_DIR}/Data/translations/Espanol.qm
	
	# QM files are generated in ${CMAKE_BINARY_DIR}, but we want to move them to /Data/translations
	# therefore we will delete them after they're copied
	COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Deutsch.qm ${CMAKE_BINARY_DIR}/English.qm ${CMAKE_BINARY_DIR}/Espanol.qm	
)

# DirectX
add_custom_target(DirectXCopyBinaries
	COMMAND	${CMAKE_COMMAND} -E copy "C:/Program Files (x86)/Windows Kits/8.1/Redist/D3D/x64/d3dcompiler_47.dll" ${CMAKE_BINARY_DIR}/Debug
	COMMAND	${CMAKE_COMMAND} -E copy "C:/Program Files (x86)/Windows Kits/8.1/Redist/D3D/x64/d3dcompiler_47.dll" ${CMAKE_BINARY_DIR}/Release
)

# QSimpleUpdater
add_custom_target(QSimpleUpdaterCopyBinaries
	COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/external/QSimpleUpdater/libeay32.dll	${CMAKE_BINARY_DIR}/Debug
	COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/external/QSimpleUpdater/libeay32.dll	${CMAKE_BINARY_DIR}/Release
	
	COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/external/QSimpleUpdater/ssleay32.dll	${CMAKE_BINARY_DIR}/Debug
	COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/external/QSimpleUpdater/ssleay32.dll	${CMAKE_BINARY_DIR}/Release
	
)

add_subdirectory(EXPRESS2Source)
add_subdirectory(RoadXMLViewer)
add_subdirectory(LandXMLViewer)
add_subdirectory(IfcBridgeGenerator)
add_subdirectory(IfcTunnelGenerator)
add_subdirectory(oip)

if (WIN32)

if(NOT OIP_USE_PREBUILD_EARLYBINDING_LIBS)
	set_target_properties(OpenInfraPlatform.Ifc2x3		 			PROPERTIES FOLDER "EarlyBinding")
	set_target_properties(OpenInfraPlatform.Ifc4		 			PROPERTIES FOLDER "EarlyBinding")
	set_target_properties(OpenInfraPlatform.IfcAlignment 			PROPERTIES FOLDER "EarlyBinding")
	set_target_properties(OpenInfraPlatform.IfcBridge	 			PROPERTIES FOLDER "EarlyBinding")
	set_target_properties(OpenInfraPlatform.IfcRoad		 			PROPERTIES FOLDER "EarlyBinding")
	set_target_properties(OpenInfraPlatform.IfcTunnel	 			PROPERTIES FOLDER "EarlyBinding")
endif(NOT OIP_USE_PREBUILD_EARLYBINDING_LIBS)

set_target_properties(OpenInfraPlatform.ExpressBinding		 	PROPERTIES FOLDER "EarlyBinding")
set_target_properties(OpenInfraPlatform.EXPRESS2Source		 	PROPERTIES FOLDER "EarlyBinding")

set_target_properties(CopyOpenInfraPlatformUIResources 			PROPERTIES FOLDER "Copy")
set_target_properties(OklabiCopyBinaries						PROPERTIES FOLDER "Copy")
set_target_properties(BlueFrameworkCopyBinaries 				PROPERTIES FOLDER "Copy")
set_target_properties(Qt5CopyBinaries			 				PROPERTIES FOLDER "Copy")
set_target_properties(DirectXCopyBinaries		 				PROPERTIES FOLDER "Copy")
set_target_properties(QSimpleUpdaterCopyBinaries				PROPERTIES FOLDER "Copy")
endif (WIN32)

# http://annealingtechnologies.blogspot.de/2010/02/wix-and-cpack-integration.html
# http://www.cmake.org/cmake/help/cmake_tutorial.html
# http://stackoverflow.com/questions/18457044/what-is-the-cmake-configuration-for-wixproject
# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE  
	 "${CMAKE_CURRENT_SOURCE_DIR}/docs/licenses.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "0")
set (CPACK_PACKAGE_VERSION_MINOR "1")
set (CPACK_GENERATOR "WIX")
set (CPACK_WIX_XSL ${YOUR_PACKAGE_SOURCE_DIR}/win.xsl)
include (CPack)

macro ( addliblas test_project )    
	if(TARGET ${test_project})
		set_target_properties(${test_project}					PROPERTIES FOLDER "ThirdParty/libLAS")
	endif()
endmacro()

if(WIN32)
	if(MSVC12 OR MSVC14)
			if (MSVC12)
				set(BIN_DIR "${PROJECT_SOURCE_DIR}/bin/vs2013/x64/")
				set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib/vs2013/x64/")
			elseif(MSVC14)
				set(BIN_DIR "${PROJECT_SOURCE_DIR}/bin/vs2015/x64/")
				set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib/vs2015/x64/")
			endif(MSVC12)
			
			add_custom_target(UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs
				COMMENT "Copying BlueFramework Libraries ..." VERBATIM
			)	
				
			add_custom_command(TARGET UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Release/OpenInfraPlatform.Infrastructure.dll 			${BIN_DIR}OpenInfraPlatform.Infrastructure.dll VERBATIM)
			add_custom_command(TARGET UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Release/OpenInfraPlatform.Infrastructure.exp 			${LIB_DIR}OpenInfraPlatform.Infrastructure.exp VERBATIM)
			add_custom_command(TARGET UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Release/OpenInfraPlatform.Infrastructure.lib 			${LIB_DIR}OpenInfraPlatform.Infrastructure.lib VERBATIM)
			add_custom_command(TARGET UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs COMMAND ${CMAKE_COMMAND} -E copy   ${CMAKE_BINARY_DIR}/Debug/OpenInfraPlatform.Infrastructured.dll 		${BIN_DIR}OpenInfraPlatform.Infrastructured.dll VERBATIM)
			add_custom_command(TARGET UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs COMMAND ${CMAKE_COMMAND} -E copy   ${CMAKE_BINARY_DIR}/Debug/OpenInfraPlatform.Infrastructured.exp 		${LIB_DIR}OpenInfraPlatform.Infrastructured.exp VERBATIM)
			add_custom_command(TARGET UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs COMMAND ${CMAKE_COMMAND} -E copy   ${CMAKE_BINARY_DIR}/Debug/OpenInfraPlatform.Infrastructured.ilk 		${LIB_DIR}OpenInfraPlatform.Infrastructured.ilk VERBATIM)
			add_custom_command(TARGET UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs COMMAND ${CMAKE_COMMAND} -E copy   ${CMAKE_BINARY_DIR}/Debug/OpenInfraPlatform.Infrastructured.lib 		${LIB_DIR}OpenInfraPlatform.Infrastructured.lib VERBATIM)
			add_custom_command(TARGET UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs COMMAND ${CMAKE_COMMAND} -E copy   ${CMAKE_BINARY_DIR}/Debug/OpenInfraPlatform.Infrastructured.pdb 		${LIB_DIR}OpenInfraPlatform.Infrastructured.pdb VERBATIM)
			
			add_dependencies(UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs
				OpenInfraPlatform.Infrastructure
			)
			
			set_target_properties(UpdateOpenInfraPlatformLibsDebugSymbolsAndDLLs	PROPERTIES FOLDER "Copy")
	endif()		
endif()	

# Thirdparty
if (WIN32)
	set_target_properties(QtXlsxWriter							PROPERTIES FOLDER "ThirdParty")
	set_target_properties(QSimpleUpdater						PROPERTIES FOLDER "ThirdParty")
	set_target_properties(Fervor 								PROPERTIES FOLDER "ThirdParty")
	set_target_properties(zlib								PROPERTIES FOLDER "ThirdParty/zlib")
	set_target_properties(zlibstatic							PROPERTIES FOLDER "ThirdParty/zlib")
	set_target_properties(example								PROPERTIES FOLDER "ThirdParty/zlib")
	set_target_properties(minigzip								PROPERTIES FOLDER "ThirdParty/zlib")
	# libLAS
	addliblas(liblas 								)
	addliblas(lasinfo-old 							)
	addliblas(las2las 								)
	addliblas(lasinfo 								)
	addliblas(lasmerge 								)
	addliblas(las2las-old 							)
	addliblas(las2txt-old 							)
	addliblas(las2txt 								)
	addliblas(txt2las 								)
	addliblas(lasblock 								)
	addliblas(ts2las 								)
	addliblas(lasindex_test 						)
	addliblas(liblas_c 								)
	addliblas(liblas_test							)
	addliblas(bigfile_test							)
	addliblas(dist      							)
	# gtest
	set_target_properties(gtest 								PROPERTIES FOLDER "ThirdParty/gtest")
	set_target_properties(gtest_main 							PROPERTIES FOLDER "ThirdParty/gtest")
	# qhull
	set_target_properties(libqhull								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(qconvex 								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(qdelaunay								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(qhalf									PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(qhull 								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(qhull_p								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(qhullcpp 								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(qhullstatic							PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(qhullstatic_p							PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(qvoronoi								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(rbox									PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(testqset								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(user_eg								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(user_eg2								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(user_eg3								PROPERTIES FOLDER "ThirdParty/qhull")
	set_target_properties(carve 								PROPERTIES FOLDER "ThirdParty/carve")
	
	add_carve_target_to_thirdparty(carve_fileformats)
	add_carve_target_to_thirdparty(carve_misc)
	add_carve_target_to_thirdparty(close_manifold)
	add_carve_target_to_thirdparty(cutgraph)					
	add_carve_target_to_thirdparty(convert)							
	add_carve_target_to_thirdparty(extrude)							
	add_carve_target_to_thirdparty(face_merge)
	add_carve_target_to_thirdparty(gloop_model)
	add_carve_target_to_thirdparty(gloop_image)
	add_carve_target_to_thirdparty(gloop_math)
	add_carve_target_to_thirdparty(intersect)
	#add_carve_target_to_thirdparty(mesh_simplify)
	#add_carve_target_to_thirdparty(selfintersect)
	add_carve_target_to_thirdparty(slice)
	add_carve_target_to_thirdparty(tetrahedron)
	add_carve_target_to_thirdparty(triangulate)
endif (WIN32)