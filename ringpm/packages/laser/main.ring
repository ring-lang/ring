func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Laser game Package"
	? copy("=",C_LINESIZE)
	? "Laser game package for the Ring programming language"
	? "See the folder : ring/applications/laser"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/laser")
	system("ring laser.ring")
	chdir(cDir)