/*  
 **      Application : variables ( Lists ) , version 2
 **      name        : Abdelrahman Adam
 **      Date        : 20\12\2017 
*/ 
#======================================================

# variables type ( string , number , list , object , cobject )

#test21

aList = [
			:Name                 = "  Abdelrahman Adam ",
			:Jop         	           = "  Lab technetian ",
			:favoritepastime  = "  Programming ",
			:Country              = "  Egypt ",
			:City			 = "  Cairo"
]

? aList[:Name]
?aList [:Country]

? aList[:City]       
if aList[:City] = NULL  aList [:City] = "  Alex "  ? aList[:City]  ok
 
