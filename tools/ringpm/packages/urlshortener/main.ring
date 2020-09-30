func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "URLShortener Package"
	? copy("=",C_LINESIZE)
	? "URLShortener package for the Ring programming language"
	? "See the folder : ring/applications/urlshortener"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/urlshortener")
	system("ring urlshortenermain.ring")
	chdir(cDir)