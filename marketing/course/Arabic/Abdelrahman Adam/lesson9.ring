/*     Application : variables (strings) , Version 2
       Author      : Abdelrahman Adam
       Date        : 19\12\2017 
*/
# variables type ( string , number , list , object , cobject )
# test 9
? exefilename()
? read ("lesson9.ring")
mystring = read(exefilename())
write("myfile.exe" , "mystring")
? "Done"
# ? mystring
write("myfile2.exe" , read(exefilename()))
