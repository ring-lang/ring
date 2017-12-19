/*
	name	:	Darsh Adam
	Lesson	:	test61.ring
	Date 	:	18/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================


afiles=  dir("C:\Users\Adam\Downloads\Programs\ring\my new Work\lesson7")


	# X=0
for afile in afiles 
	if right(afile[1],5) = ".ring"
		? " file :" + afile[1]
		? read(afile[1])
	ok

next 
