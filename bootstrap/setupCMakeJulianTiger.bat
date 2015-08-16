mkdir C:\build\vs2013\OpenInfraPlatform
cd C:\build\vs2013\OpenInfraPlatform
"C:\Program Files (x86)\CMake\bin\cmake.exe" -G"Visual Studio 12 2013 Win64" -HE:\dev\OpenInfraPlatform -BC:\build\vs2013\OpenInfraPlatform ^
-DQT_DIR="C:\Qt\Qt5.4.0" ^
-DBOOST_ROOT="C:\thirdparty\vs2013\x64\boost_1_57_0" ^
-DVLD_ROOT_DIR="C:\Program Files (x86)\Visual Leak Detector" ^
-DCMAKE_PREFIX_PATH="C:/Qt/Qt5.4.0/5.4/msvc2013_64/lib/cmake" ^
-DBLUEFRAMEWORK_ROOT_DIR="E:\dev\BlueFramework2"
cd E:\dev\OpenInfraPlatform\bootstrap