/*
	Application : Conversion between List and String
 	     Author : Khalid Khairy
	       Date : 14/12/2017
*/

#========================================================

aList = [:one , :two, :three, :four, :five]

?aList
?len(aList)

cString = list2str(aList)

?len(cString)
?cString

aList2 = str2list(cString)
?len(aList2)
?aList2


