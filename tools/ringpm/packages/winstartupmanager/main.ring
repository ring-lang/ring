func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "WinStartupManager Package"
	? copy("=",C_LINESIZE)
	? "WinStartupManager package for the Ring programming language"
	? "See the folder : ring/applications/winstartupmanager"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/winstartupmanager")
	system("ring WinStartupManager.ring")
	chdir(cDir)