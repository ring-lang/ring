/*
	Application : Lists  Version2
	Author      : Salwa Abdrabu
*/

# Variables Type( String, Number, List, Object, C Object )

aList = [
	:name    = "Salwa Abdrabu",
	:job     = "Programmer",
	:Country = "Egypt",
	:City    = "Alex"

]
? aList[:name]
? aList [:job]
? aList [:country]

if aList[:City] = NULL aList[:City] = "Cairo" ok
? aList[:City]
