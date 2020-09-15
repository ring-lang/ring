func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RingREPL Package"
	? copy("=",C_LINESIZE)
	? "RingREPL package for the Ring programming language"
	? "See the folder : ring/tools/ringrepl"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../tools/ringrepl")
	system("ring replw.ring")
	chdir(cDir)