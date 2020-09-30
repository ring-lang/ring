func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "TowersOfHanoi Package"
	? copy("=",C_LINESIZE)
	? "TowersOfHanoi package for the Ring programming language"
	? "See the folder : ring/applications/towersofhanoi"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/towersofhanoi")
	system("ring TowersOfHanoi.ring")
	chdir(cDir)