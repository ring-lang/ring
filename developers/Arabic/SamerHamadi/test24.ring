/*
**	Application    : SubStr() 
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

cString = "Welcome To The Ring Programming Language (ring)"

? cstring

? substr(cstring,16,4)			#get Number Of Characters
? substr(cstring,"Ring")		#get Position of substrstring
? substr(cstring,"Ring","***Ring***")	#replace substring
#Not case sinsetive
            ? substr(cstring,"Ring","***Ring***",true)	#replace substring
