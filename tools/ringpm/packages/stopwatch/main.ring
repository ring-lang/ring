func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "StopWatch Package"
	? copy("=",C_LINESIZE)
	? "StopWatch package for the Ring programming language"
	? "See the folder : ring/applications/stopwatch"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/stopwatch")
	system("ring stopwatchController.ring")
	chdir(cDir)