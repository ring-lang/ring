/*
	name	:	Darsh Adam
	Lesson	:	test47.ring
	Date 	:	16/12/2017
*/

#=====================================================
			# Functions
#=====================================================
/*
	String | Number ----> pass by Value 
	List | Object 	----> pass by refrance 
*/
#====================================================

func main
	alist = 1:10
	alist2 = alist 	# copy by Value 

		alist[1]= :One
	? alist[1]
	? alist2[1]
	
#========================Enf Of Lesson====================
