/*
	Application    : variables (strings) - version 2
	Author 	       : Samer Hammadi
	Date           : 13/12/2017
*/

? exefilename() #ring.exe (console) - ringw.exe (GUI) 

? read("test2.ring")

mystring = read(exefilename())

write("myfile.exe" , mystring)
? "Done"
//? mystring
write("myfile2.exe" , read(exefilename()))
