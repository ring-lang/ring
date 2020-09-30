# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	system_class_test()
ok

func System_class_test
	
	oSystem = new System

	See "Test the System Class Methods" + nl
 	
	oSystem.system("dir")
	see oSystem.sysget("path") + nl
	see oSystem.ismsdos() + nl
	see oSystem.iswindows() + nl
	see oSystem.iswindows64() + nl
	see oSystem.isunix() + nl
	see oSystem.ismacosx() + nl
	see oSystem.islinux() + nl
	see oSystem.isfreebsd() + nl
	see oSystem.isandroid() + nl
	see oSystem.windowsnl() + nl
	see oSystem.sysargv() + nl
	see oSystem.filename() + nl


Class System
 
	Func system cCommand
		std_system(cCommand)

	Func sysget cVariable
		return std_get(cVariable)

	Func ismsdos
		return std_ismsdos()

	Func iswindows
		return std_iswindows()

	Func iswindows64
		return std_iswindows64()

	Func isunix
		return std_isunix()

	Func ismacosx
		return std_ismacosx()

	Func islinux
		return std_islinux()

	Func isfreebsd
		return std_isfreebsd()

	Func isandroid
		return std_isandroid()

	Func windowsnl
		return std_windowsnl()

	Func sysargv
		return std_sysargv()

	Func filename
		return std_filename()
