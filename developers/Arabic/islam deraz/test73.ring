/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.15
*/

afiles = dir("c:/ring/islam deraz/15-03-2018")

# get *.ring files
	alist = []
	for afile in afiles
		if right(afile[1],5) = ".ring"
		alist + afile[1]
		ok
	next

# sort the list of files
alist = sort(alist)

# print files as alist
	x=1
	for cfile in alist 

	? " ( " + x + " ) " + cfile
	x++
	next

# get the file number

	give cnumber
	nnumber= 0+cnumber
	nnumber= floor(nnumber)
	if nnumber > 0 and  nnumber <= len(alist)
	? read(alist[nnumber])
ok

