# بسم الله الرحمن الرحيم
// this is Lesson7 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  functions: dir()
  Author     :  S.BOURROU
  Date       :  18.12.2017  
*/

myfile = dir("E:\ring\developers\arabic\S.Bourrou") 


# get'.ring files..
	aList = [] 
	for afile in myFile 
		if right(afile[1],5) = ".ring"
			aList + afile[1]
		ok
	next 
# SORT THE LIST OF FILE 
	aList = sort(aList)		

// print file as a list !
	x = 1
	for cfile in aList
		?"(" + x +  ")" + cfile
		x++
	next
// get the file Number 
	give cNumber 
	nNumber = 0 + cNumber
	if nNumber < len(alist) 
		? read(alist[nNumber])
	ok


	

