/*
**	Application		:Variables (lists2)
**	Author			:Adel Mahmoud
**	Date			:2018.01.28
*/

#=========================================================

aList = [
	:name	= "Adel Mahmoud",
	:job  	= "pharmacist",
	:country= "Egypt",
	:city	= "Alex"
]

if aList[:city]=null aList[:city]="cairo" ok

? aList[:name]
? aList[:job]
? aList[:country]
? aList[:city]


#=========================================================


