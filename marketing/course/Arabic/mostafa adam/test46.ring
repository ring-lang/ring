/*
	Application : test46.ring
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
	test(alist)
	? alist

func test alist2
	alist2[2] = :two
#========================End Of Lesson====================
