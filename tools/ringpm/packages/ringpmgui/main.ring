func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "ringpmgui Package"
	? copy("=",C_LINESIZE)
	? "ringpmgui package for the Ring programming language"
	? "See the folder : ring/tools/ringpmgui"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../tools/ringpmgui")
	system("ring ringpmguiController.ring")
	chdir(cDir)