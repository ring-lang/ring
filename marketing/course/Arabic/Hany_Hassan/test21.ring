/*
**  Application: Variables (Lists)- version 2
**  Author     : Hany Hassan
**  Date       : 2017.12.13
*/
#=========================================================================================
# Variable Types (String, Number, List, Object, C Object)
aList = [

	:name 	= "Hany Hassan",
	:job	= "Programmer",
	:Country= "Egypt",
	:city	= "Sohag"

]

? aList[:name]
? aList[:job] ? aList[:country]

if aList[:city] = NULL aList[:city] = "Sohag" ok
? aList[:city]
#=========================================================================================
