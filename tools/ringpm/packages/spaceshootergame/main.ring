func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "SpaceShooterGame Package"
	? copy("=",C_LINESIZE)
	? "SpaceShooterGame package for the Ring programming language"
	? "See the folder : ring/applications/spaceshooter"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/spaceshooter")
	system("ring SpaceShooter.ring")
	chdir(cDir)