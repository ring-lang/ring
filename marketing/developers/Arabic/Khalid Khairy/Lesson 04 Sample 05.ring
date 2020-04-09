/*
	Application : Variables(Lists)  v.02
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

?aList [:name] 
?aList[:job]
if aList[:city] = null alist[:city] = "Alex" ok
?aList[:city]
