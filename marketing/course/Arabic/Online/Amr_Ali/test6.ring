/*
	Application	: string version2
	Author    	: Amr Ali
	Date   		: 07/03/2018
	
*/

# Variables = (string, Number, List, object, c object)

? exefilename()

# binary ===> (8-bit)
# Text ===> (7-bit) 

? read("test6.ring")
str = read(exefilename())

write("pro.exe", str)
write("goodjob.exe", read(exefilename()))
? "Done"


