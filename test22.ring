/*
	Application : Lists  Version3
	Author      : Salwa Abdrabu
*/

# Variables Type( String, Number, List, Object, C Object )

aList = [
	:name    = "Salwa Abdrabu",
	:job     = "Programmer",
	:Country = "Egypt",
	:City    = "Alex"
]
? "Size :" + len(aList)
for aItem in aList
	? aItem[2]
next 
