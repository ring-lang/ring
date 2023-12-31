func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "PlanetaryOrbits Package"
	? copy("=",C_LINESIZE)
	? "PlanetaryOrbits package for the Ring programming language"
	? "See the folder : ring/applications/planetaryorbits"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/planetaryorbits")
	system("ring Planetary-Orbits.ring")
	chdir(cDir)