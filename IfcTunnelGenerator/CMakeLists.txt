set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	../Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	../Release)
set(CMAKE_PDB_OUTPUT_DIRECTORY_DEBUG 	    ../Debug)
set(CMAKE_PDB_OUTPUT_DIRECTORY_RELEASE 	    ../Release)

file(GLOB IfcTunnelGenerator_Source			src/*.*)

include_directories(
	${BLUEFRAMEWORK_INCLUDE_DIR}
	${Boost_INCLUDE_DIR}
	${CMAKE_CURRENT_BINARY_DIR} # Qt generated files will be located here
	../Ifc2x3/src
	../Ifc4/src
	../IfcAlignment/src
	../IfcBridge/src
	../IfcRoad/src
	../IfcTunnel/src
)	

add_executable(OpenInfraPlatform.IfcTunnelGenerator
	${IfcTunnelGenerator_Source}
)

if(OIP_USE_PREBUILD_EARLYBINDING_LIBS)
	target_link_libraries(OpenInfraPlatform.IfcTunnelGenerator
		${OpenInfraPlatform_Ifc4_LIBRARY}
		${OpenInfraPlatform_IfcTunnel_LIBRARY}
		Rpcrt4.lib
		# BlueFramework
		${BLUEFRAMEWORK_BLUECORE_LIBRARY}
		${BLUEFRAMEWORK_BLUEIMAGEPROCESSING_LIBRARY}
		${BLUEFRAMEWORK_BLUERASTERIZER_LIBRARY}
		${BLUEFRAMEWORK_BLUEENGINE_LIBRARY}
		${BLUEFRAMEWORK_BLUEGL4XRENDERER_LIBRARY}
		${BLUEFRAMEWORK_BLUEAPPLICATION_LIBRARY}
	)

elseif()
	target_link_libraries(OpenInfraPlatform.IfcTunnelGenerator
		OpenInfraPlatform.Ifc4
		OpenInfraPlatform.IfcTunnel
		# BlueFramework
		${BLUEFRAMEWORK_BLUECORE_LIBRARY}
		${BLUEFRAMEWORK_BLUEIMAGEPROCESSING_LIBRARY}
		${BLUEFRAMEWORK_BLUERASTERIZER_LIBRARY}
		${BLUEFRAMEWORK_BLUEENGINE_LIBRARY}
		${BLUEFRAMEWORK_BLUEGL4XRENDERER_LIBRARY}
		${BLUEFRAMEWORK_BLUEAPPLICATION_LIBRARY}	
	)
endif()