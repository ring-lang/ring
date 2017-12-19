/*
    Application: Variables (Strings) - Version2 
    Author     : Ahmed Khalifa
    Date       : 2017.12.11
*/

? exefilename()  # ring.exe (console) - Ringw.exe (GUI)

? read("example8.ring")

mystring = read(exefilename())
?mystring
write("myfile.exe",mystring)

? "done"

