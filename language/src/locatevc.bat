echo off
cls

if exist "C:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" (
	call "C:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" (
	call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" (
	call "C:\Program Files\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x86
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat" (
	set VSCMD_START_DIR=%cd%
	call "C:\Program Files\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat"
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat" (
	set VSCMD_START_DIR=%cd%
	call "C:\Program Files\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat"
	exit /b
)

if exist "C:\Program Files\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat" (
	set VSCMD_START_DIR=%cd%
	call "C:\Program Files\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat"
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat" (
	set VSCMD_START_DIR=%cd%
	call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat"
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat" (
	set VSCMD_START_DIR=%cd%
	call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat"
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat" (
	set VSCMD_START_DIR=%cd%
	call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat"
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\VsDevCmd.bat" (
	set VSCMD_START_DIR=%cd%
	call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\Tools\VsDevCmd.bat"
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\VsDevCmd.bat" (
	set VSCMD_START_DIR=%cd%
	call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\VsDevCmd.bat"
	exit /b
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat" (
	set VSCMD_START_DIR=%cd%
	call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat"
	exit /b
)
