/*
	name	:	Darsh Adam
	Lesson	:	دروس رينج
	Date 	:	23/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================

# Eval 

func main 
	while true 
		? " Enter Expression" give Expr
		if lower(trim(Expr)) = "exit" 
			exit 
		ok 
		try
			? eval("return " + Expr)
		catch 
			? "Error!"
		Done
	end
