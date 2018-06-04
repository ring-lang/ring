/*
		Application	: Variables (Lists) V.2
		Author		: Sherif Abdelhay
		Date		: 2018.6.1

*/

# Lists ---> Array, List, Nested List, MD Array, Hash|Dict


aList = [

			:Name = "Sherif Abdelhay",
			:Job = "Programmer",
			:Country = "Egypt"
			#:City = Null
]

? "Size: " + len(aList)

for aItem in aList
	? aItem[2]
next