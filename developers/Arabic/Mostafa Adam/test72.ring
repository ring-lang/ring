/*
	name	:	Darsh Adam
	Lesson	:	دروس رينج
	Date 	:	18/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================

# Eval () and scope of variables 


eval("x = 10")		# x = global
? x 

func main
	eval("y=20")
	? y		# Local 
	test()
func test
	? x 
	? y
