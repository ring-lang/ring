/*
	Application 	: Variables (Lists) - version 2
	Author		: Mahmoud Fayed
	Date		: 2017.12.13
*/

# Variable Types (String, Number, List, Object, C Object)
 
aList = [

	:name 	= "Mahmoud Fayed",
	:job	= "Programmer",
	:Country= "Egypt",
	:city	= "Alex"

]

? aList[:name]
? aList[:job] ? aList[:country]

if aList[:city] = NULL aList[:city] = "Cairo" ok
? aList[:city]
