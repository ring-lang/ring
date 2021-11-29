# variables types 
/*
 * Application       : variables strings ver 2
 * Author            : Hany Ibrahim Ahmed
 * Date              : 17/12/2017
 */
# variables types (string, number, list, object, c object)
? exefilename() #ring.exe

# binary data
read("test7.ring")
mystring = read(exefilename())
write("myfile.exe", mystring)
? "Done"
? mystring
