func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "JulianDayCalendar Package"
	? copy("=",C_LINESIZE)
	? "JulianDayCalendar package for the Ring programming language"
	? "See the folder : ring/applications/juliandaycalendar"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/juliandaycalendar")
	system("ring JulianDayCalendar.ring")
	chdir(cDir)