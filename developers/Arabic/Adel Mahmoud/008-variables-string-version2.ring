/*
	Application	:variables (String)version2
	Author		:Adel Mahmoud
	Date		:2017.12.11
*/

# variables Types(string, number, list, object, c object)
? exefilename()		# ring.exe(console),ringw.exe(GUI)
# Binary Data (memory,byte(8bit))
# CPU - memory word (32bit)--->(4byte--->(4*8bit))
# CPU - memory word (64bit)--->(8byte--->(8*8bit))

# Memory (Data - Code)
# Binary Data ---> use all 8 bit of each byte
# Text        ---> use only 7 bit of each byte
# File (Text - Binary)
# Text (*.txt)
# Binary ( *.exe, *.jpg, *.png, *.mp4, ....)

? read("008-variables-string-version2.ring")
mystring = read(exefilename())
write("file1.exe",mystring)
? "Done"
read("file1.exe")
? "Done"




