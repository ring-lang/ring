/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.13
*/

afiles = dir("c:/ring/islam deraz/02-03-2018")

for afile in afiles
	if right(afile[1],5) = ".ring"
	? "file: " + afile[1]
	ok
next

