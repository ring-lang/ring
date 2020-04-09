/*
**	Application    : variables (lists) - version2
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
? alist[:name]
? alist[:job]
? alist[:country]

if alist[:city] = null alist[:city] = "Damascus" ok
? alist[:city]

