func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "GetQuotesHistory Package"
	? copy("=",C_LINESIZE)
	? "GetQuotesHistory package for the Ring programming language"
	? "See the folder : ring/applications/getquoteshistory"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/getquoteshistory")
	system("ring GetQuotesHistoryDraw.ring")
	chdir(cDir)