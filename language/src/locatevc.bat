echo off
cls
set RINGSCRIPTPATH=%~dp0
set RINGEXEPATH="%RINGSCRIPTPATH%..\..\bin\ring.exe"
set RINGARCHPATH="%RINGSCRIPTPATH%..\..\bin\buildarch.ring"

rem default values for build flags
set ringbuildtarget=x86
set ringcflags=/O2
set ringldflags=
set ringdebug=0
set ringsubsystem=5.01


if /I ["%1"]==["x64"] (
	set ringbuildtarget=x64
)
if /I ["%1"]==["arm64"] (
	set ringbuildtarget=arm64
)
if /I ["%1"]==["arm"] (
	set ringbuildtarget=arm
)
if /I ["%1"]==["arm32"] (
	set ringbuildtarget=arm
)
if /I ["%1"]==["auto"] (
	if exist %RINGEXEPATH% (
		rem run buildarch.ring to get ring.exe architecture
		rem we use trick documented at https://devblogs.microsoft.com/oldnewthing/20120731-00/?p=7003
		for /f %%i in ('call %RINGEXEPATH% %RINGARCHPATH%') do set ringbuildtarget=%%i
	)
)

if /I ["%ringbuildtarget%"]==["x64"] (
	set ringsubsystem=5.02
)
if /I ["%ringbuildtarget%"]==["arm64"] (
	set ringsubsystem=6.03
)
if /I ["%ringbuildtarget%"]==["arm"] (
	set ringsubsystem=6.03
)



if /I ["%1"]==["debug"] (
	set ringdebug=1
)

if /I ["%2"]==["debug"] (
	set ringdebug=1
)

if %ringdebug% EQU 1 (
	set ringcflags=/Od /DEBUG:FULL /Z7
	set ringldflags=/DEBUG
)

if exist "C:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" (
	call "C:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" %ringbuildtarget%
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" (
	call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" %ringbuildtarget%
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" (
	call "C:\Program Files\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" %ringbuildtarget%
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%" 
	call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd   
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2019\Enterprise\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files\Microsoft Visual Studio\2019\Enterprise\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat" (
	pushd "%cd%"
	call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat" -arch=%ringbuildtarget%
	popd
	exit /b
)
