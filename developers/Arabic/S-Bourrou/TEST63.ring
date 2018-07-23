
// this is Lesson9 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  functions: dir() (edit lesson)
  Author     :  S.BOURROU
  Date       :  25.06.2018  
*/

myfile = dir("E:\ring\developers\arabic\S.Bourrou") 


# get'.ring files..
	aList = [] 
	for afile in myFile 
		if right(afile[1],5) = ".ring"
			aList + afile[1]
		ok
	next 
# SORT THE LIST OF THE FILE 
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
        nNumber = floor(nNumber)
	if nNumber > 0 and nNumber <= len(alist) 
		? read(alist[nNumber])
	ok

