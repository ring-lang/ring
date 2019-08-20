/*
	Application : Variables(strings) date & time v.01
	     Author : Khalid Khairy
	       Date : 14/12/2017
*/

#========================================================

cDate = date()
cTime = time()

? cDate
? cTime

cDate2 = adddays(cDate,5)
?cDate2

? diffdays(cDate2, cDate)
