/*
	Application : Variables(Lists)  v.03
	     Author : Khalid Khairy
	       Date : 14/12/2017
*/

#========================================================

aList = [
	:name 	 = "Khalid Khairy",
	:job  	 = "Developer",
	:Country = "Egypt",
	:city    = "KFS"
]

? "Size: " + len(aList)
for aItem in aList
? aItem[2]
next
