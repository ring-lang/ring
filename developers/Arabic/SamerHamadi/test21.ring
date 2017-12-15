/*
**	Application    : variables (lists) - version3
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

alist = [

	:name	 = "Samer Hamadi",
	:job  	 = "programmer",
	:Country = "Syria",
	:city	 = "Alex"
]
? "size: " + len(alist)
for aItem in alist
	? aItem[1]
next
