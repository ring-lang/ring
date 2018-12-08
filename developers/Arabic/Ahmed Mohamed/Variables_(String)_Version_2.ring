/*
	Application : Variables (String) Version_2
	Author 	    : Ahmed Mohamed
	Date	    : 2018/12/8
*/

# Variables Types (String, Number, List, C Object)

? exefilename() # ring.exe (Console) - ringw.exe (GUI)

# Binary Data (Memory - Bytes(8-bits) )
#CPU - Memory Word - 32bit (4 bytes) (4 * 8 bits)

# Memory (Data - Code)

# Binary Data   -------> Usage (8 bits)
# Text 		-------> 7-bit

# File (Text Or Binary)
# Text (*.txt)
# Binary (*.exe, *.jpg, etc)

? read("test1.ring");

myString = read(exefilename())

write("myfile.exe", myString)

? "Done"

//? myString

write("myfile2.exe", read(exefilename()))




