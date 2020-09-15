func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "LotteryGame Package"
	? copy("=",C_LINESIZE)
	? "LotteryGame package for the Ring programming language"
	? "See the folder : ring/applications/lottery"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/lottery")
	system("ring lottery.ring")
	chdir(cDir)