func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Pong2Game Package"
	? copy("=",C_LINESIZE)
	? "Pong2Game package for the Ring programming language"
	? "See the folder : ring/applications/pong2"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/pong2")
	system("ring pong.ring")
	chdir(cDir)