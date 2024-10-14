/*
	Application : test47.ring
	Author      : Darsh Adam
	Date        : 16/12/2017
*/

#=====================================================
			# Functions
#=====================================================
/*
	String | Number ----> pass by Value 
	List | Object 	----> pass by reference 
*/
#====================================================

func main
	alist = 1:10
	alist2 = alist 	# copy by Value 

		alist[1]= :One
	? alist[1]
	? alist2[1]
	
#========================End Of Lesson====================
