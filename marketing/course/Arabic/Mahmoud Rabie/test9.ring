/*

   	Application    :variables (Strings virsion2)
   	author         :Mahmoud Rabie 
	Date           :2017/12/11  
#Variables Types (String, Number, list, Object, c Object )
*/
exefilename() # Ring.exe (Console) Ringw.exe ()GUI  
# Binary Data (Memory - Bytes (8bit) )
# CPU - Memory word - 32bit(4bytes) (4*8 bit)
# Memory ( Data - Code )
# Binary Data -------> using (8 bit)
# text        -------> using (7 bit)
# File ( text or binary)
# Text (*.txt)
# Binary (*.exe, *.jpg *.png etc....)
? read("test9.ring")
mystring = read(exefilename())
write("myfile.exe",mystring)
? "Done"
//? mystring
write("myfile2.exe",read(exefilename()))
