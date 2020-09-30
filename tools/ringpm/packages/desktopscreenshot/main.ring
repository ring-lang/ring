func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "DesktopScreenShot Package"
	? copy("=",C_LINESIZE)
	? "DesktopScreenShot package for the Ring programming language"
	? "See the folder : ring/applications/desktopscreenshot"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/desktopscreenshot")
	system("ring desktopscreenshotController.ring")
	chdir(cDir)