/*
	name	:	Darsh Adam
	Lesson	:	دروس رينج
	Date 	:	18/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================

# Eval 

func main 
	while true 
		? " Enter Expression" give Expr
		if left(lower(trim(Expr)),4)= "exit" 
			exit 
		ok 
		? eval("return " + Expr)
	end
