/*
 * Application : variables(string) version2
 * Author      : heba atef
 * Date        : 25.12.2017
*/

? read("lesson3-1.ring")
mystring=read(exefilename())
write("myfile.exe",mystring)

? "done"
write("myfile2.exe", read(exefilename()))

/* string(null) */
mystring  = ""
mystring2 =  null 
mystring3 = "null"
? ISNULL(mystring)
? ISNULL(mystring2)
? ISNULL(mystring3)
