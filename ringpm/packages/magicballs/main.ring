func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "MagicBalls game Package"
	? copy("=",C_LINESIZE)
	? "MagicBalls game package for the Ring programming language"
	? "See the folder : ring/applications/magicballs"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/magicballs")
	system("ring MagicBalls.ring")
	chdir(cDir)