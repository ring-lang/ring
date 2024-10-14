/*
	Application	: Variables (Strings) - Version 2
	Author		: Khaled ABID
	Date		: 18/12/2017
*/

# Variable Types (String, Number, List, Object, C Object)

? exefilename() # Ring.exe (console) - ringw.exe (GUI)

# Binary Data (Memory - Bytes (8-bit))
# CPU - Memory Word - 32bit (4 Bytes) (4 * 8 bits)

# Memory ( Data - Code )

# Binary Data 	-----> Usage (8-bit)
# Text 		-----> 7-bit 

# File ( Text or Binary )
# Text (*.txt)
# Binary (*.exe, *.jpg, *.png, ... ect)

? Read("test9.ring")

mystring = read(exefilename())
write("myfile.exe",mystring)
? "Done"
//? mystring

write("myfile2.exe",read(exefilename()))
