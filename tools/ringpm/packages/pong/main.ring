func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Pong Package"
	? copy("=",C_LINESIZE)
	? "Pong package for the Ring programming language"
	? "See the folder : ring/applications/pong"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/pong")
	system("ring pong.ring")
	chdir(cDir)