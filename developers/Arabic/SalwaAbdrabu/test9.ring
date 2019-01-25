/*
	Application : Variables (Strings) Version 2
	Author      : Salwa Abdrabu
*/

#Variables Type( String, Number, List, Object, C Object )

? exefilename()       # ring.exe  (console) ringw.exe (GUI)

# Binary Data (Memory - Bytes (8 Bit)
# CPU - Memory Word - 32bit(4 bytes (4*8bits))

# Memory (Data - Code )
# Binary Data ----------> usage (8bit)
# Text -----------------> 7Bit

# File    (Text or Binary)
# Text    (*.txt)
# Binary  (*.exe , *.jpg , *.png , etc)

? read ("test9.ring")
myString = read (exefilename())
write ("myfile.exe",myString)
? "Done"
write ("myfile2.exe",read (exefilename()))
// ? myString 
