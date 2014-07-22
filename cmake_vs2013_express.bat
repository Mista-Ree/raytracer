set IMG_WORKROOT=%CD%
set SIM_ROOT=%CD%
set RC_LOCATION=C:\Program Files (x86)\Microsoft Visual Studio 12.0\SDK\v3.5\Bin
set PATH=%PATH%
set VSPATH=C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\


REM - Run Cmake with appropriate generator
mkdir cmake
cd cmake
cmake -G "Visual Studio 12" ..


REM - Confirm Cmake ran properly
IF ERRORLEVEL 1 (
	echo.
	echo CMake configure failed
	echo.
	pause
	exit 1
)


REM - Launch VS2010 full edition
start "" "%VSPATH%\IDE\WDExpress.exe" %SIM_ROOT%\cmake\raytracer.sln

cd ../

