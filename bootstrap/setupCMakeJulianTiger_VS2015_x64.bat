mkdir C:\build\vs2015\OpenInfraPlatform
cd C:\build\vs2015\OpenInfraPlatform
"C:\Program Files (x86)\CMake\bin\cmake.exe" -G"Visual Studio 14 2015 Win64" -HE:\dev\OpenInfraPlatform -BC:\build\vs2015\OpenInfraPlatform ^
-DBOOST_ROOT="C:\thirdparty\vs2015\x64\boost_1_60_0" ^
-DVLD_ROOT_DIR="C:\Program Files (x86)\Visual Leak Detector" ^
-DCMAKE_PREFIX_PATH="C:\Qt\Qt5.6.0\5.6\msvc2015_64\lib\cmake" ^
-DBLUEFRAMEWORK_ROOT_DIR="E:\dev\BlueFramework2"
cd E:\dev\OpenInfraPlatform\bootstrap