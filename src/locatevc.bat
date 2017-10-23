rem The First Method
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86

rem The Second Method
set VSCMD_START_DIR=%cd%
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat"
