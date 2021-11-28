/*
	Application : test49.ring
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
	dec(20)
	


func dec nnum
	? nnum
	if nnum = 0 return end 
	dec(nnum-1)
	
#========================End Of Lesson====================
