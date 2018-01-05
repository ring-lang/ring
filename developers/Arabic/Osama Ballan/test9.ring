/*
	Application  	: Variables  (Strings)  Version 2 .
	Author 	    	: Osama Ballan .
	Date			: 2017 - 12 - 29 .
*/
# Variable Types (String, Number, List, Object, c Object)

# ? exefilename() 	# ring.exe ( console ) - ringw.exe ( GUI )

# Binary Data ( Memory - Bytes ( 8 Bits ) )
# CPU - Memory Word - 32 Bit (4 Bytes ) (4 * 8 Bits )
# Memory ( Data - Code ) 
# Binary Data 	   	------> 	Usage ( 8 - Bits )
# Text Data	    		------>    Usage ( 7 - Bits ) 
# File ( Text Or Binary )
# Text (*.txt )
# Binary ( *.exe, *.jpg, *.png, *.mp3, ... etc )

# ? read("test9.ring")

myString = read(exefilename())
# ? mystring
write("myFile.exe", myString)
? "Done"


