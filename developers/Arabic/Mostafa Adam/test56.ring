/*
	name	:	Darsh Adam
	Lesson	:	test56.ring
	Date 	:	18/12/2017
*/

#=====================================================
			# functions 
#=====================================================

t1 = clock()

for x=1 to 1000000
next 

? (clock()-t1) / clockspersecond()
