func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Employee Package"
	? copy("=",C_LINESIZE)
	? "Employee package for the Ring programming language"
	? "See the folder : ring/applications/employee"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/employee")
	system("ring Emp.ring")
	chdir(cDir)