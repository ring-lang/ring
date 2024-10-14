/*  
 **      Application : variables ( Lists ) , version 2
 **      Author      : Abdelrahman Adam
 **      Date        : 20/12/2017 
*/ 
#======================================================

# variables type ( string , number , list , object , cobject )

#test21

aList = [
	:Name            = "  Abdelrahman Adam ",
	:Job             = "  Lab technician "  ,
	:favoritepastime = "  Programming "     ,
	:Country         = "  Egypt "           ,
	:City            = "  Cairo"             
]

? aList[:Name]
? aList[:Country]

? aList[:City]       
if aList[:City] = NULL  aList [:City] = "  Alex "  ? aList[:City]  ok
 
