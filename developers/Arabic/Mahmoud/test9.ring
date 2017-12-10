/*
	Application 	: Variables (Strings) - Version2
	Author		: Mahmoud Fayed
	Date		: 2017.12.10
*/

# Variable Types (String, Number, List, Object, C Object)

? exefilename()	# ring.exe (console) - ringw.exe (GUI)

# Binary Data (Memory - Bytes (8-bit) )
# CPU - Memory Word - 32bit (4 bytes) (4 * 8 bits)

# Memory ( Data - Code )

# Binary data 	------> Usage (8-bit)
# Text 		------>  7-bit 

# File ( Text or Binary )
# Text (*.txt) 
# Binary (*.exe, *.jpg, *.png, etc)

? read("test9.ring")

mystring = read(exefilename())
write("myfile.exe",mystring)
? "Done"
// ? mystring 

write("myfile2.exe",read(exefilename()))
