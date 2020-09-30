func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "FlappyBird3000 Package"
	? copy("=",C_LINESIZE)
	? "FlappyBird3000 package for the Ring programming language"
	? "See the folder : ring/applications/flappybird3000"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/flappybird3000")
	system("ring flappybird3000.ring")
	chdir(cDir)