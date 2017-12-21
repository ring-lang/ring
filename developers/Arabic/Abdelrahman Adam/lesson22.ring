/*  
 **      Application : variables ( Lists ) , version 3
 **      name        : Abdelrahman Adam
 **      Date        : 20\12\2017 
*/ 
#======================================================

# variables type ( string , number , list , object , cobject )

#test22

aList = [
			:Name                 = "  Abdelrahman Adam ",
			:Jop         	           = "  Lab technetian ",
			:favoritepastime  = "  Programming ",
			:Country              = "  Egypt ",
			:City			 = "  Cairo"
]

? "size  : "  + len(aList)

for aItem in aList

			?aItem[2]

next
