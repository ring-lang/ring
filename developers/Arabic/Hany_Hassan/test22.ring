/*
**  Application: Variables (Lists)- version 3
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

? "Size: " + len(aList)
for aitem in aList 
	? aitem[2]
next
#=========================================================================================
