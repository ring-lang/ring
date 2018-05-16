# ------------ Variables (Strings) Part2 ------------
/*
 - exefilename() Function Displays Ring Language exe File Name/Address
 - Types Of This exe File :
    1. ring.exe (Display Result In console window)
    2. ringw.exe (Display Result In GUI window) 
 - Ring Can Deal With Binary Data
 - Two Types Of Storing Files : 
    1. Text (ex : .txt files) -> Usage 7-bit
    2. Binary (ex : .exe, .jpg files) -> Usage 8-bit
*/
? exefilename() 
? read("test5.ring")
// Store A Copy Of Content Of exe File In A String
myString = read("test6.ring")
? myString 
myString = read(exefilename())
write("storeContent.exe",myString)
? "Done"
# We Can Combine All Of This In One Statement
write("storeContent2.exe",read("test6.ring"))
