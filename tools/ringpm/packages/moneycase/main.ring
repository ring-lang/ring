func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "MoneyCase Package"
	? copy("=",C_LINESIZE)
	? "MoneyCase package for the Ring programming language"
	? "See the folder : ring/applications/moneycase"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/moneycase")
	system("ring MoneyCaseGame.ring")
	chdir(cDir)