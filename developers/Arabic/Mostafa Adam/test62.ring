/*
	name	:	Darsh Adam
	Lesson	:	test62.ring
	Date 	:	18/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================


afiles=  dir("C:\Users\Adam\Downloads\Programs\ring\my new Work\lesson7")


# Get Ring files 
	alist = []
	for afile in afiles 
		if right(afile[1],5) = ".ring"
			alist + afile[1]
		ok
	next 
#sort the list 
	alist = sort(alist)
# print files as alist 
	x=1
	for cfile in alist
		? "("+ x +")" + cfile
		x++
	end
# choose the file to open 
	give cnum
	nnum = 0 + cnum
	if nnum <= len(alist)
		? read(alist[nnum])
	else ? " Bad Option " 
	ok

