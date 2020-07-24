load "stdlib.ring"

if isWindows()

	Write("mycmd.bat","
	@echo off
	    timeout 1 2>nul >nul
	    if errorlevel 1 (
        	echo input redirected
	    ) else (
	        echo input is console
	    )
	")

	? SystemCmd("mycmd.bat")

ok