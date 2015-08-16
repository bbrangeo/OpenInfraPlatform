import sys
import os
import shutil
import zipfile

# get the directory the script is in	
current_dir = os.path.dirname(sys.argv[0]) + '\\'
deploy_dir  = 'TUM Open Infra Platform'
deploy_path = current_dir + deploy_dir

def DeleteFiles(directory, extension):
	for root, dirs, files in os.walk(directory):
		for file in files:
			if file.endswith(extension):
				print(os.path.join(root, file))
				os.remove(os.path.join(root, file))

def DetermineCurrentRevison():
	text = os.popen('hg log -l 1').read()
	revision = text[13:17] # extract revision number
	irev = int(revision) + 1
	return str(irev)	
	
def clean():
	shutil.rmtree(deploy_path)
	shutil.rmtree(deploy_path + '_' + DetermineCurrentRevison())
	
def deploy():
	os.environ["LANGUAGE"] = "en_US.UTF-8"
	
	# check if the build directory was passed
	if len(sys.argv) != 2:	
		print('No build directory was passed!')
		return
	
	build_dir = sys.argv[1] # "C:/build/vs2013/OpenInfraPlatform/"
	if not build_dir.endswith('\\'):
		build_dir = build_dir + '\\'
	
	# clean if the path already exists
	if os.path.isdir(deploy_path):
		shutil.rmtree(deploy_path)	
				
	# create the directory
	os.mkdir(deploy_path)
	
	# OpenInfraPlatform
	shutil.copy(build_dir + 'Release/OpenInfraPlatform.UI.exe', 					deploy_path + '/TUM Open Infra Platform.exe')
	shutil.copy(build_dir + 'Release/OpenInfraPlatform.CommandLineUtilities.exe', 	deploy_path + '/OpenInfraPlatform.CommandLineUtilities.exe')
	shutil.copy(build_dir + 'Release/OpenInfraPlatform.Infrastructure.dll',			deploy_path + '/OpenInfraPlatform.Infrastructure.dll')
	
	# BlueFramework
	shutil.copy(build_dir + 'Release/BlueFramework.Core.dll',	 			deploy_path + '/BlueFramework.Core.dll')
	shutil.copy(build_dir + 'Release/BlueFramework.ImageProcessing.dll',	deploy_path + '/BlueFramework.ImageProcessing.dll')
	shutil.copy(build_dir + 'Release/BlueFramework.Rasterizer.dll',			deploy_path + '/BlueFramework.Rasterizer.dll')
	shutil.copy(build_dir + 'Release/BlueFramework.Engine.dll',				deploy_path + '/BlueFramework.Engine.dll')
	shutil.copy(build_dir + 'Release/BlueFramework.Application.dll',		deploy_path + '/BlueFramework.Application.dll')			
	shutil.copy(build_dir + 'Release/BlueFramework.D3D11RenderSystem.dll',	deploy_path + '/BlueFramework.D3D11RenderSystem.dll')
	shutil.copy(build_dir + 'Release/BlueFramework.GL4xRenderSystem.dll',	deploy_path + '/BlueFramework.GL4xRenderSystem.dll')
	
	# ThirdParty
	shutil.copy(build_dir + 'Release/QtXlsxWriter.dll',						deploy_path + '/QtXlsxWriter.dll')
	shutil.copy(build_dir + 'Release/liblas.dll',							deploy_path + '/liblas.dll')
	
	# Zlib
	shutil.copy(build_dir + 'Release/zlib1.dll',							deploy_path + '/zlib1.dll')
	
	# Qt
	shutil.copy(build_dir + 'Release/Qt5Core.dll',							deploy_path + '/Qt5Core.dll')
	shutil.copy(build_dir + 'Release/Qt5Widgets.dll',						deploy_path + '/Qt5Widgets.dll')
	shutil.copy(build_dir + 'Release/Qt5Declarative.dll',					deploy_path + '/Qt5Declarative.dll')
	shutil.copy(build_dir + 'Release/Qt5Gui.dll',							deploy_path + '/Qt5Gui.dll')
	shutil.copy(build_dir + 'Release/Qt5Network.dll',						deploy_path + '/Qt5Network.dll')
	shutil.copy(build_dir + 'Release/Qt5OpenGL.dll',						deploy_path + '/Qt5OpenGL.dll')
	shutil.copy(build_dir + 'Release/Qt5Script.dll',						deploy_path + '/Qt5Script.dll')
	shutil.copy(build_dir + 'Release/Qt5Xml.dll',							deploy_path + '/Qt5Xml.dll')
	shutil.copy(build_dir + 'Release/Qt5XmlPatterns.dll',					deploy_path + '/Qt5XmlPatterns.dll')
	shutil.copy(build_dir + 'Release/Qt5Sql.dll',							deploy_path + '/Qt5Sql.dll')	
	shutil.copy(build_dir + 'Release/Qt5WebChannel.dll',					deploy_path + '/Qt5WebChannel.dll')	
	shutil.copy(build_dir + 'Release/Qt5WebKit.dll',						deploy_path + '/Qt5WebKit.dll')		
	shutil.copy(build_dir + 'Release/Qt5WebKitWidgets.dll',					deploy_path + '/Qt5WebKitWidgets.dll')
	shutil.copy(build_dir + 'Release/Qt5Multimedia.dll',					deploy_path + '/Qt5Multimedia.dll')
	shutil.copy(build_dir + 'Release/Qt5MultimediaWidgets.dll',				deploy_path + '/Qt5MultimediaWidgets.dll')
	shutil.copy(build_dir + 'Release/Qt5PrintSupport.dll',					deploy_path + '/Qt5PrintSupport.dll')
	shutil.copy(build_dir + 'Release/Qt5Sensors.dll',						deploy_path + '/Qt5Sensors.dll')
	shutil.copy(build_dir + 'Release/Qt5Svg.dll',							deploy_path + '/Qt5Svg.dll')
	shutil.copy(build_dir + 'Release/Qt5Quick.dll',							deploy_path + '/Qt5Quick.dll')
	shutil.copy(build_dir + 'Release/Qt5Qml.dll',							deploy_path + '/Qt5Qml.dll')
	shutil.copy(build_dir + 'Release/Qt5Positioning.dll',					deploy_path + '/Qt5Positioning.dll')
	shutil.copy(build_dir + 'Release/libGLESv2.dll',						deploy_path + '/libGLESv2.dll')
	shutil.copy(build_dir + 'Release/libEGL.dll',                           deploy_path + '/libEGL.dll')
	shutil.copy(build_dir + 'Release/icudt53.dll',							deploy_path + '/icudt53.dll')
	shutil.copy(build_dir + 'Release/icuin53.dll',							deploy_path + '/icuin53.dll')
	shutil.copy(build_dir + 'Release/icuuc53.dll',                          deploy_path + '/icuuc53.dll')
	
	shutil.copytree(current_dir + 'platforms',								deploy_path + '/platforms')
	
	# Oklabi
	shutil.copy(build_dir + 'Release/OklabiGdal1264.dll',					deploy_path + '/OklabiGdal1264.dll')
	shutil.copy(build_dir + 'Release/OklabiGeos1264_c.dll',					deploy_path + '/OklabiGeos1264_c.dll')
	shutil.copy(build_dir + 'Release/OklabiKern1264.dll',					deploy_path + '/OklabiKern1264.dll')
	shutil.copy(build_dir + 'Release/OklabiProj1264.dll',					deploy_path + '/OklabiProj1264.dll')
	shutil.copy(build_dir + 'Release/OklabiZlib1264.dll',					deploy_path + '/OklabiZlib1264.dll')
	
	shutil.copytree(build_dir + 'res',										deploy_path + '/res')
	shutil.copytree(build_dir + 'schema',									deploy_path + '/schema')
	shutil.copytree(build_dir + 'fbliste',									deploy_path + '/fbliste')
	
	# Zlib
	shutil.copy(build_dir + 'Release/zlib1.dll',							deploy_path + '/zlib1.dll')
	
	# DirectX
	shutil.copy(current_dir + 'D3DRedist/D3D/x64/d3dcompiler_47.dll',						deploy_path + '/d3dcompiler_47.dll')
	
	# QSimpleUpdater
	shutil.copy(build_dir + 'Release/libeay32.dll',								deploy_path + '/libeay32.dll')
	shutil.copy(build_dir + 'Release/ssleay32.dll',								deploy_path + '/ssleay32.dll')
	
	# VS2013 Redist x64
	shutil.copy(current_dir + 'VC2013/redist/x64/Microsoft.VC120.CRT/msvcp120.dll',		deploy_path + '/msvcp120.dll')		# Standard C++ library for native code
	shutil.copy(current_dir + 'VC2013/redist/x64/Microsoft.VC120.CRT/msvcr120.dll',		deploy_path + '/msvcr120.dll')   	# C runtime library (CRT) for native code
	shutil.copy(current_dir + 'VC2013/redist/x64/Microsoft.VC120.CRT/vccorlib120.dll',	deploy_path + '/vccorlib120.dll')	# WinRT core library
	shutil.copy(current_dir + 'VC2013/redist/x64/Microsoft.VC120.OpenMP/vcomp120.dll',	deploy_path + '/vcomp120.dll') 		# OpenMP
	
	# Python
	shutil.copy(current_dir + 'python/python34.dll',										deploy_path + '/python34.dll') 
	
	# data, shaders, etc.
	shutil.copytree(build_dir + 'Data', 									deploy_path + '/Data')
	# Remove data files that are not needed
	DeleteFiles(deploy_path + "/Data", ".svg") # textures
	DeleteFiles(deploy_path + "/Data/translations", ".ts") # linguist files
	# Shader
	os.mkdir(deploy_path + '/Shader')
	os.mkdir(deploy_path + '/Shader/D3D11')
	#os.mkdir(deploy + '/Shader/GL4x')
	
	shutil.copy(build_dir + 'Shader/D3D11/compileFXC.bat',						deploy_path + '/Shader/D3D11/compileFXC.bat');
	
	shutil.copy(build_dir + 'Shader/D3D11/DigitalElevationModel.hlsl',			deploy_path + '/Shader/D3D11/DigitalElevationModel.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/drawQuad.hlsl',						deploy_path + '/Shader/D3D11/drawQuad.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/GBuffer.hlsl',						deploy_path + '/Shader/D3D11/GBuffer.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/GradientQuad.hlsl',					deploy_path + '/Shader/D3D11/GradientQuad.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/LaserScanPoint.hlsl',					deploy_path + '/Shader/D3D11/LaserScanPoint.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/ViewCube.hlsl',						deploy_path + '/Shader/D3D11/ViewCube.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/Skybox.hlsl',							deploy_path + '/Shader/D3D11/Skybox.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/SkyboxPT.hlsl',						deploy_path + '/Shader/D3D11/SkyboxPT.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/SkyboxPT.hlsl',						deploy_path + '/Shader/D3D11/SpriteBatch.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/Text.hlsl',							deploy_path + '/Shader/D3D11/Text.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/VertexCacheLine.hlsl',				deploy_path + '/Shader/D3D11/VertexCacheLine.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/VertexCachePoint.hlsl',				deploy_path + '/Shader/D3D11/VertexCachePoint.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/VertexCacheTriangle.hlsl',			deploy_path + '/Shader/D3D11/VertexCacheTriangle.hlsl');
	shutil.copy(build_dir + 'Shader/D3D11/VertexCacheTriangleTextured.hlsl',	deploy_path + '/Shader/D3D11/VertexCacheTriangleTextured.hlsl');
	
	shutil.copytree(build_dir + 'Shader/GL4x/',									deploy_path + '/Shader/GL4x')

	# now compile shaders
	os.chdir(deploy_path)
	os.chdir('Shader')
	os.chdir('D3D11')
	os.system('compileFXC.bat')
	os.chdir('..')
	os.chdir('..')
	os.chdir('..')

	# remove shader source files
	os.remove(deploy_path + '/Shader/D3D11/compileFXC.bat')
	os.remove(deploy_path + '/Shader/D3D11/DigitalElevationModel.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/drawQuad.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/GBuffer.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/GradientQuad.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/ViewCube.hlsl')	
	os.remove(deploy_path + '/Shader/D3D11/Skybox.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/SkyboxPT.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/SpriteBatch.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/Text.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/VertexCacheLine.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/VertexCachePoint.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/VertexCacheTriangle.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/VertexCacheTriangleTextured.hlsl')
	os.remove(deploy_path + '/Shader/D3D11/LaserScanPoint.hlsl')
	
	# copy BlueEffect files.
	shutil.copy(build_dir + 'Shader/DigitalElevationModel.be',				deploy_path + '/Shader/DigitalElevationModel.be');
	shutil.copy(build_dir + 'Shader/LaserScanPoint.be',						deploy_path + '/Shader/LaserScanPoint.be');
	shutil.copy(build_dir + 'Shader/Skybox.be',								deploy_path + '/Shader/Skybox.be');
	shutil.copy(build_dir + 'Shader/VertexCacheLine.be',					deploy_path + '/Shader/VertexCacheLine.be');
	shutil.copy(build_dir + 'Shader/VertexCachePoint.be',					deploy_path + '/Shader/VertexCachePoint.be');
	shutil.copy(build_dir + 'Shader/VertexCacheTriangle.be',				deploy_path + '/Shader/VertexCacheTriangle.be');
		
	# Style folder
	os.mkdir(deploy_path + '/Style')
	shutil.copy(build_dir + 'Style/blueform.qss', 							deploy_path + '/Style/blueform.qss')
	
	# testdata
	os.mkdir(deploy_path + '/testdata')
	os.mkdir(deploy_path + '/testdata/LandXML')
	os.mkdir(deploy_path + '/testdata/IfcAlignment')
	
	shutil.copy(build_dir + 'testdata/LandXML/Mainbruecke_Klingenberg.xml', deploy_path + '/testdata/LandXML/Mainbruecke_Klingenberg.xml')
	shutil.copy(build_dir + 'testdata/LandXML/AutoCAD Civil 3D/Land1.xml', 	deploy_path + '/testdata/LandXML/Land1.xml')

	# License file
	shutil.copy('../docs/licenses.txt',										deploy_path + '/licenses.txt')
	
	# Zip file
	zipFilename = deploy_dir + '_' + DetermineCurrentRevison()	
	newFilename  = zipFilename + "\\" + zipFilename
	
	shutil.copytree(deploy_path, newFilename) 
	shutil.make_archive(zipFilename, "zip", zipFilename)
	
	# Clean
	clean()
		
deploy()