project(OpenInfraPlatform.Infrastructure)

add_definitions(-DBLUEINFRASTRUCTURE_EXPORT)
set(CMAKE_DEBUG_POSTFIX "d")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	../Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	../Release)
set(CMAKE_PDB_OUTPUT_DIRECTORY_DEBUG 	    ../Debug)
set(CMAKE_PDB_OUTPUT_DIRECTORY_RELEASE 	    ../Release)

# Unicode rules!
add_definitions(-D_UNICODE)
add_definitions(-DNOMINMAX)

file(GLOB OpenInfraPlatform_Infrastructure_Alignment_HorizontalAlignment_Source 	src/OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/*.*)								
file(GLOB OpenInfraPlatform_Infrastructure_Alignment_Source 						src/OpenInfraPlatform/Infrastructure/Alignment/*.*)			
file(GLOB OpenInfraPlatform_Infrastructure_Alignment_VerticalAlignment_Source 		src/OpenInfraPlatform/Infrastructure/Alignment/VerticalAlignment/*.*)			
file(GLOB OpenInfraPlatform_Infrastructure_Bindings_Source 							src/OpenInfraPlatform/Infrastructure/Bindings/*.*)		
file(GLOB OpenInfraPlatform_Infrastructure_Core_Source 								src/OpenInfraPlatform/Infrastructure/Core/*.*)	
file(GLOB OpenInfraPlatform_Infrastructure_CrossSection_Source 						src/OpenInfraPlatform/Infrastructure/CrossSection/*.*)			
file(GLOB OpenInfraPlatform_Infrastructure_DigitalElevationModel_Source 			src/OpenInfraPlatform/Infrastructure/DigitalElevationModel/*.*)						
file(GLOB OpenInfraPlatform_Infrastructure_EnergyConsumption_Source 				src/OpenInfraPlatform/Infrastructure/EnergyConsumption/*.*)						
file(GLOB OpenInfraPlatform_Infrastructure_EnergyConsumption_Calculators_Source 	src/OpenInfraPlatform/Infrastructure/EnergyConsumption/Calculators/*.*)	
file(GLOB OpenInfraPlatform_Infrastructure_EnergyConsumption_Calculators_Parameters_Source 	src/OpenInfraPlatform/Infrastructure/EnergyConsumption/Calculators/Parameters/*.*)	
file(GLOB OpenInfraPlatform_Infrastructure_EnergyConsumption_Profiles_Source 		src/OpenInfraPlatform/Infrastructure/EnergyConsumption/Profiles/*.*)	
file(GLOB OpenInfraPlatform_Infrastructure_Export_Source 							src/OpenInfraPlatform/Infrastructure/Export/*.*)		
file(GLOB OpenInfraPlatform_Infrastructure_IfcPL_Source 							src/OpenInfraPlatform/Infrastructure/IfcPL/*.*)		
file(GLOB OpenInfraPlatform_Infrastructure_Import_Source 							src/OpenInfraPlatform/Infrastructure/Import/*.*)		
file(GLOB OpenInfraPlatform_Infrastructure_PointCloudProcessing_Source				src/OpenInfraPlatform/Infrastructure/PointCloudProcessing/*.*)					
file(GLOB OpenInfraPlatform_Infrastructure_Source 									src/OpenInfraPlatform/Infrastructure/*.*)	

source_group(OpenInfraPlatform\\Infrastructure										FILES ${OpenInfraPlatform_Infrastructure_Source})
source_group(OpenInfraPlatform\\Infrastructure\\Alignment							FILES ${OpenInfraPlatform_Infrastructure_Alignment_Source})			
source_group(OpenInfraPlatform\\Infrastructure\\Alignment\\HorizontalAlignment		FILES ${OpenInfraPlatform_Infrastructure_Alignment_HorizontalAlignment_Source})								
source_group(OpenInfraPlatform\\Infrastructure\\Alignment\\VerticalAlignment		FILES ${OpenInfraPlatform_Infrastructure_Alignment_VerticalAlignment_Source})													
source_group(OpenInfraPlatform\\Infrastructure\\Bindings							FILES ${OpenInfraPlatform_Infrastructure_Bindings_Source})			
source_group(OpenInfraPlatform\\Infrastructure\\Core								FILES ${OpenInfraPlatform_Infrastructure_Core_Source})		
source_group(OpenInfraPlatform\\Infrastructure\\CrossSection						FILES ${OpenInfraPlatform_Infrastructure_CrossSection_Source})				
source_group(OpenInfraPlatform\\Infrastructure\\DigitalElevationModel  				FILES ${OpenInfraPlatform_Infrastructure_DigitalElevationModel_Source})						
source_group(OpenInfraPlatform\\Infrastructure\\EnergyConsumption					FILES ${OpenInfraPlatform_Infrastructure_EnergyConsumption_Source})
source_group(OpenInfraPlatform\\Infrastructure\\EnergyConsumption\\Calculators 		FILES ${OpenInfraPlatform_Infrastructure_EnergyConsumption_Calculators_Source_Source})
source_group(OpenInfraPlatform\\Infrastructure\\EnergyConsumption\\Calculators\\Parameters_Source 	FILES ${OpenInfraPlatform_Infrastructure_EnergyConsumption_Calculators_Parameters_Source})
source_group(OpenInfraPlatform\\Infrastructure\\EnergyConsumption\\Profiles 		FILES ${OpenInfraPlatform_Infrastructure_EnergyConsumption_Profiles_Source})
source_group(OpenInfraPlatform\\Infrastructure\\Export								FILES ${OpenInfraPlatform_Infrastructure_Export_Source})		
source_group(OpenInfraPlatform\\Infrastructure\\IfcPL								FILES ${OpenInfraPlatform_Infrastructure_IfcPL_Source})		
source_group(OpenInfraPlatform\\Infrastructure\\Import								FILES ${OpenInfraPlatform_Infrastructure_Import_Source})		
source_group(OpenInfraPlatform\\Infrastructure\\PointCloudProcessing				FILES ${OpenInfraPlatform_Infrastructure_PointCloudProcessing_Source})				

include_directories(
	${Boost_INCLUDE_DIR} 
	${PYTHON_INCLUDE_DIRS}
	${VLD_INCLUDE_DIR}
	${BLUEFRAMEWORK_INCLUDE_DIR}
	src
	../external/libLAS-1.7.0/include
	../external/QtXlsxWriter/src/xlsx
	../external/Oklabi/Kern-C++
	../external/Oklabi/Dienst
)
					
link_directories(	
	${Boost_LIBRARY_DIRS} 
	${VLD_LIBRARIES_DIR}
	# Python
	${PYTHON_LIBRARIES}
	../external/Oklabi
)

# Create a target for the library
add_library(OpenInfraPlatform.Infrastructure SHARED 
	${OpenInfraPlatform_Infrastructure_Alignment_HorizontalAlignment_Source}
	${OpenInfraPlatform_Infrastructure_Alignment_Source}
	${OpenInfraPlatform_Infrastructure_Alignment_VerticalAlignment_Source}
	${OpenInfraPlatform_Infrastructure_Bindings_Source}
	${OpenInfraPlatform_Infrastructure_Core_Source}
	${OpenInfraPlatform_Infrastructure_CrossSection_Source}
	${OpenInfraPlatform_Infrastructure_DigitalElevationModel_Source}
	${OpenInfraPlatform_Infrastructure_EnergyConsumption_Source}
	${OpenInfraPlatform_Infrastructure_EnergyConsumption_Calculators_Source_Source}
	${OpenInfraPlatform_Infrastructure_EnergyConsumption_Calculators_Parameters_Source}
	${OpenInfraPlatform_Infrastructure_EnergyConsumption_Profiles_Source}
	${OpenInfraPlatform_Infrastructure_Export_Source}
	${OpenInfraPlatform_Infrastructure_IfcPL_Source}
	${OpenInfraPlatform_Infrastructure_Import_Source}
	${OpenInfraPlatform_Infrastructure_PointCloudProcessing_Source}
	${OpenInfraPlatform_Infrastructure_Source}
)

if(OIP_USE_PREBUILD_EARLYBINDING_LIBS)	
	set(BLUEFRAMEWORK_IfcAlignment_LIBRARY_RELEASE	OpenInfraPlatform.IfcAlignment.lib)
	set(BLUEFRAMEWORK_IfcAlignment_LIBRARY_DEBUG	OpenInfraPlatform.IfcAlignmentd.lib)
	
	set(BLUEFRAMEWORK_IfcAlignment_LIBRARY
		optimized 	${BLUEFRAMEWORK_IfcAlignment_LIBRARY_RELEASE}
		debug		${BLUEFRAMEWORK_IfcAlignment_LIBRARY_DEBUG})
	
	set(BLUEFRAMEWORK_Ifc2x3_LIBRARY_RELEASE	OpenInfraPlatform.Ifc2x3.lib)
	set(BLUEFRAMEWORK_Ifc2x3_LIBRARY_DEBUG		OpenInfraPlatform.Ifc2x3d.lib)
	
	set(BLUEFRAMEWORK_Ifc2x3_LIBRARY
		optimized 	${BLUEFRAMEWORK_Ifc2x3_LIBRARY_RELEASE}
		debug		${BLUEFRAMEWORK_Ifc2x3_LIBRARY_DEBUG})
		
	set(BLUEFRAMEWORK_IfcRoad_LIBRARY_RELEASE	OpenInfraPlatform.IfcRoad.lib)
	set(BLUEFRAMEWORK_IfcRoad_LIBRARY_DEBUG		OpenInfraPlatform.IfcRoadd.lib)
	
	set(BLUEFRAMEWORK_IfcRoad_LIBRARY
		optimized 	${BLUEFRAMEWORK_IfcRoad_LIBRARY_RELEASE}
		debug		${BLUEFRAMEWORK_IfcRoad_LIBRARY_DEBUG})
	
	target_link_libraries( OpenInfraPlatform.Infrastructure
		#${BLUEFRAMEWORK_Ifc2x3_LIBRARY}
		${BLUEFRAMEWORK_IfcAlignment_LIBRARY}
		${BLUEFRAMEWORK_IfcRoad_LIBRARY}
		Rpcrt4.lib
		# Boost
		${Boost_LIBRARIES}
		# BlueFramework
		${BLUEFRAMEWORK_BLUECORE_LIBRARY}
		${BLUEFRAMEWORK_BLUEIMAGEPROCESSING_LIBRARY}
		${BLUEFRAMEWORK_BLUERASTERIZER_LIBRARY}
		${BLUEFRAMEWORK_BLUEENGINE_LIBRARY}
		${BLUEFRAMEWORK_BLUEGL4XRENDERER_LIBRARY}
		${BLUEFRAMEWORK_BLUEAPPLICATION_LIBRARY}	
		# Python
		${PYTHON_LIBRARIES}
		# External libs
		QtXlsxWriter
		liblas
		# Oklabi
		Oklabi_JNI1264.lib
		OklabiCOM1264.lib
		OklabiGdal1264_i.lib
		OklabiGeos1264_c_i.lib
		OklabiKern1264.lib
		OklabiProj1264_i.lib
		OklabiStdC1264.lib
		OklabiUtil1264.lib		
		OklabiZlib1264.lib
		#
		qhullstatic
	)
else(OIP_USE_PREBUILD_EARLYBINDING_LIBS)
	target_link_libraries( OpenInfraPlatform.Infrastructure
		OpenInfraPlatform.IfcAlignment
		OpenInfraPlatform.IfcRoad
		# Boost
		${Boost_LIBRARIES}		
		# BlueFramework
		${BLUEFRAMEWORK_BLUECORE_LIBRARY}
		${BLUEFRAMEWORK_BLUEIMAGEPROCESSING_LIBRARY}
		${BLUEFRAMEWORK_BLUERASTERIZER_LIBRARY}
		${BLUEFRAMEWORK_BLUEENGINE_LIBRARY}
		${BLUEFRAMEWORK_BLUEGL4XRENDERER_LIBRARY}
		${BLUEFRAMEWORK_BLUEAPPLICATION_LIBRARY}	
		# Python
		${PYTHON_LIBRARIES}
		# External libs
		QtXlsxWriter
		liblas
		# Oklabi
		Oklabi_JNI1264.lib
		OklabiCOM1264.lib
		OklabiGdal1264_i.lib
		OklabiGeos1264_c_i.lib
		OklabiKern1264.lib
		OklabiProj1264_i.lib
		OklabiStdC1264.lib
		OklabiUtil1264.lib		
		OklabiZlib1264.lib
		#
		qhullstatic
	)
endif(OIP_USE_PREBUILD_EARLYBINDING_LIBS)

# Use the Widgets module from Qt 5.
qt5_use_modules(OpenInfraPlatform.Infrastructure Xml XmlPatterns)