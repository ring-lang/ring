/*
**	Application Name : variables (string V.2);
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-11;		
*/
? read("test8.ring")

myStr = read(exefilename())
write("new.exe", myStr)
? "Done"

#============================

/* you can also do that on one line :
**	write("new.exe", read(exefilename())
*/
