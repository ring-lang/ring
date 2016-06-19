# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	system_class_test()
ok

func System_class_test
	
	oSystem = new System

	See "Test the System Class Methods" + nl
 	
	oSystem.system("dir")

Class System
 
	Func system cCommand
		std_system(cCommand)

	Func get cVariable
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
