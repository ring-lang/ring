/*
	Application	: Variables (Lists) - Version 2
	Author		: Ahmed Mohamed
	Date		: 2019/10/14
*/


# Variables Types (Strings, Number, List, Object, C Object)

aList = [
	
	:name 		= "Ahmed Mohamed",
	:job 		= "Developer",
	:country 	= "Egypt",
	:city		= "Alexandria"
]

? aList[:name]
? aList[:job]
? aList[:country]

if aList[:city] = null aList[:city] = "Cairo" ok

? aList[:city]
