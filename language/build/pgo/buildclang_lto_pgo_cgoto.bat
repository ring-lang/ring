@echo off
rem =========================================================================
rem  Build Ring (ring.dll, ring.exe, ringw.exe) using Clang + LTO + PGO
rem  (computed goto dispatcher: ..\vmcgoto\vmcgoto.c)
rem
rem  Usage:
rem     buildclang_lto_pgo_cgoto.bat
rem
rem  Uses:
rem     ..\..\src, ..\..\include      Ring sources (built as they are)
rem     ..\..\tests                   Training programs (tests.ring + scripts)
rem     pgotrain.ring                 Training script (in this folder)
rem     ..\vmcgoto\vmcgoto.c          The computed goto dispatcher (ring_vm_computedgoto)
rem
rem  The computed goto is enabled by -DRING_VM_COMPUTEDGOTO (what ..\vmcgoto\rconfig_updated.h
rem  does): include\rconfig.h is not changed
rem
rem  Output (the same places as ..\buildvc.bat):
rem     ..\..\..\lib\ring.dll, ..\..\..\lib\ring.lib (import library)
rem     ..\..\..\bin\ring.dll, ..\..\..\bin\ring.exe, ..\..\..\bin\ringw.exe
rem
rem  Steps:
rem     1. Compile + link an instrumented build (-flto -fprofile-instr-generate)
rem     2. Training run: execute all tests\tests.ring programs (pgotrain.ring)
rem     3. Merge the profile (llvm-profdata) and rebuild with LTO + PGO (-fprofile-instr-use)
rem
rem  Requirements: clang.exe, lld-link.exe and llvm-profdata.exe (LLVM for Windows)
rem
rem  Optional environment variables:
rem     RINGCLANGPATH  Folder of clang.exe        (default: c:\pl\llvm\bin if it exists)
rem     RINGOUT        Output folder for exe/dll  (default: ..\..\..\bin)
rem     RINGLIBOUT     Output folder for ring.dll + ring.lib (default: ..\..\..\lib)
rem     RINGCFLAGS     Optimization flags         (default: -O2)
rem     RINGKEEPWORK   If defined, keep the temp folder workcgoto (profile data, training copy)
rem =========================================================================
setlocal enableextensions

if not "%~1"=="" (
	echo Error: this script takes no options
	exit /b 1
)

set "PGODIR=%~dp0"
set "LANGDIR=%PGODIR%..\.."
set "SRCDIR=%LANGDIR%\src"
set "INCDIR=%LANGDIR%\include"
set "TESTDIR=%LANGDIR%\tests"
set "CGOTOFILE=%LANGDIR%\build\vmcgoto\vmcgoto.c"
rem if not defined RINGCLANGPATH if exist "c:\pl\llvm\bin\clang.exe" set "RINGCLANGPATH=c:\pl\llvm\bin"
rem if defined RINGCLANGPATH set "PATH=%RINGCLANGPATH%;%PATH%"
if not defined RINGOUT set "RINGOUT=%LANGDIR%\..\bin"
if not defined RINGLIBOUT set "RINGLIBOUT=%LANGDIR%\..\lib"
if not defined RINGCFLAGS set "RINGCFLAGS=-O2"

rem ---- Check the requirements ---------------------------------------------
for %%t in (clang.exe lld-link.exe llvm-profdata.exe) do (
	where %%t >nul 2>nul
	if errorlevel 1 (
		echo Error: %%t not found. Set RINGCLANGPATH to the LLVM bin folder.
		exit /b 1
	)
)
if not exist "%SRCDIR%\ring.c" (
	echo Error: Ring sources not found: %SRCDIR%
	exit /b 1
)
if not exist "%CGOTOFILE%" (
	echo Error: the computed goto dispatcher not found: %CGOTOFILE%
	exit /b 1
)
if not exist "%PGODIR%pgotrain.ring" (
	echo Error: pgotrain.ring not found in %PGODIR%
	exit /b 1
)
if not exist "%TESTDIR%\tests.ring" (
	echo Error: training programs not found: %TESTDIR%\tests.ring
	exit /b 1
)

set "WORK=%PGODIR%workcgoto"
set "PROF=%WORK%\prof"
set "STAGE1=%WORK%\stage1"
if exist "%WORK%" rmdir /s /q "%WORK%"
if exist "%WORK%" (
	echo Error: cannot delete %WORK% ^(is a program or a console using it?^)
	exit /b 1
)
mkdir "%PROF%" "%STAGE1%"
if not exist "%RINGOUT%" mkdir "%RINGOUT%"
if not exist "%RINGLIBOUT%" mkdir "%RINGLIBOUT%"
echo Building Ring from %SRCDIR% (computed goto)

rem ---- Source files of ring.dll (everything except ring.c and ringw.c) ---
set "FILES="
for %%f in ("%SRCDIR%\*.c") do (
	if /i not "%%~nxf"=="ring.c" if /i not "%%~nxf"=="ringw.c" call set "FILES=%%FILES%% "%%f""
)
rem The computed goto dispatcher: ring_vm_mainloop() (vm.c) calls ring_vm_computedgoto()
set "FILES=%FILES% "%CGOTOFILE%""
set "CGOTO=-DRING_VM_COMPUTEDGOTO=1"
set "LIBS=-ladvapi32 -lshell32 -luser32"

rem ---- (1): instrumented build ---------------------------------------
echo.
echo (1) Instrumented build (-flto -fprofile-instr-generate)
clang %RINGCFLAGS% %CGOTO% -w -flto -fuse-ld=lld -fprofile-instr-generate -shared -I"%INCDIR%" %FILES% -o "%STAGE1%\ring.dll" %LIBS%
if errorlevel 1 goto failed
clang %RINGCFLAGS% %CGOTO% -w -I"%INCDIR%" "%SRCDIR%\ring.c" "%STAGE1%\ring.lib" -o "%STAGE1%\ring.exe" -Wl,/STACK:8388608
if errorlevel 1 goto failed

rem ---- (2): training run ---------------------------------------------
echo.
echo (2) Training run (tests\tests.ring programs)
xcopy /e /i /q "%TESTDIR%\scripts" "%WORK%\train" >nul
rem One profile file per process (%%p = process id): the training starts one ring.exe per test
set "LLVM_PROFILE_FILE=%PROF%\r_%%p.profraw"
"%STAGE1%\ring.exe" "%PGODIR%pgotrain.ring" "%STAGE1%\ring.exe" "%WORK%\train" "%TESTDIR%\tests.ring"
set "LLVM_PROFILE_FILE="
if not exist "%PROF%\*.profraw" (
	echo Error: no profile data was generated
	exit /b 1
)
rem llvm-profdata does not expand wildcards on Windows: pass the list of profile files
dir /b /s "%PROF%\*.profraw" > "%WORK%\profiles.txt"
llvm-profdata merge -f "%WORK%\profiles.txt" -o "%WORK%\ring.profdata"
if errorlevel 1 goto failed

rem ---- (3): optimized build (LTO + PGO) ------------------------------
echo.
echo (3) Optimized build (-flto -fprofile-instr-use)
rem ring.dll and its import library ring.lib go to lib (as ..\buildvc.bat), then ring.dll is copied to bin
clang %RINGCFLAGS% %CGOTO% -w -flto -fuse-ld=lld -fprofile-instr-use="%WORK%\ring.profdata" -Wno-profile-instr-unprofiled -shared -I"%INCDIR%" %FILES% -o "%WORK%\ring.dll" %LIBS%
if errorlevel 1 goto failed
copy /y "%WORK%\ring.dll" "%RINGLIBOUT%\ring.dll" >nul
if errorlevel 1 goto copyfailed
copy /y "%WORK%\ring.lib" "%RINGLIBOUT%\ring.lib" >nul
if errorlevel 1 goto copyfailed
copy /y "%WORK%\ring.dll" "%RINGOUT%\ring.dll" >nul
if errorlevel 1 goto copyfailed
clang %RINGCFLAGS% %CGOTO% -w -flto -fuse-ld=lld -I"%INCDIR%" "%SRCDIR%\ring.c" "%WORK%\ring.lib" -o "%WORK%\ring.exe" -Wl,/STACK:8388608
if errorlevel 1 goto failed
clang %RINGCFLAGS% %CGOTO% -w -flto -fuse-ld=lld -I"%INCDIR%" "%SRCDIR%\ringw.c" "%WORK%\ring.lib" -o "%WORK%\ringw.exe" -Wl,/STACK:8388608 -Wl,/SUBSYSTEM:WINDOWS %LIBS%
if errorlevel 1 goto failed
copy /y "%WORK%\ring.exe" "%RINGOUT%\ring.exe" >nul
if errorlevel 1 goto copyfailed
copy /y "%WORK%\ringw.exe" "%RINGOUT%\ringw.exe" >nul
if errorlevel 1 goto copyfailed

echo.
echo Done:
echo    %RINGLIBOUT%\ring.dll
echo    %RINGLIBOUT%\ring.lib
echo    %RINGOUT%\ring.dll
echo    %RINGOUT%\ring.exe
echo    %RINGOUT%\ringw.exe
rem Remove the temporary work folder (profile data, training copy, intermediate files)
if not defined RINGKEEPWORK rmdir /s /q "%WORK%"
endlocal
exit /b 0

:copyfailed
echo.
echo Error: cannot write to the output folders ^(is ring.exe, ringw.exe or ring.dll in use?^)
echo The built files are in %WORK%
exit /b 1

:failed
echo.
echo Error: build failed
exit /b 1
