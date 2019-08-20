/*
          Application : Variables(strings) version2
          Author      : Mahmoud Kibreet
          Date        : 2018.01.22
*/

# Variables types (String , Number , List , Object , C Object)

? exefilename() # ring.exe (console) - ringw.exe (GUI)

# Binary Data (Memory - Bytes(8-bit))
# CPU - Memory Word -32bits(4bytes) (4*8bits)

# Memory (Data - Code)

# Binary data ----->usage (8-bit)
# Text        -----> 7-bit

# File (Text-Binary)
# Text (*.txt)
# Binary (*.exe , *.jpg , *.png , etc)

? read("Test8.ring")

mystring=read(exefilename())
write("myfile.exe",mystring)
? "Done"
//? mystring

write("myfile2.exe",read(exefilename()))
