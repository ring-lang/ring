func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "BMICalculator Package"
	? copy("=",C_LINESIZE)
	? "BMICalculator package for the Ring programming language"
	? "See the folder : ring/applications/bmicalculator"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/bmicalculator")
	system("ring BMI_Calculator.ring")
	chdir(cDir)