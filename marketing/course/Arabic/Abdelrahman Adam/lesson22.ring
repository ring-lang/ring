/*  
 **      Application : variables ( Lists ) , version 3
 **      Author      : Abdelrahman Adam
 **      Date        : 20/12/2017 
*/ 
#======================================================

# variables type ( string , number , list , object , cobject )

#test22

aList = [
	:Name            = "  Abdelrahman Adam ",
	:Job             = "  Lab technician "  ,
	:favoritepastime = "  Programming "     ,
	:Country         = "  Egypt "           ,
	:City			 = "  Cairo"             
]

? "Size  : "  + len(aList)

for aItem in aList
	? aItem[2]
next
