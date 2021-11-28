/*
	name	:	Darsh Adam
	Lesson	:	test31.ring
	Date 	:	16/12/2017
*/
		// if , For , While 

#=====================================================
	/* Condition ----> True \ False */
#=====================================================

alist = [:one, :two, :three]

for iitem in alist 

	? iitem 
	switch iitem
	on :one			iitem = 1
	on :two 		iitem = 2
	on :three		iitem = 3
	other 			iitem = 0
	off
next
	? alist

#=================End Of Lesson===================#

#=================End Of Program==================#
