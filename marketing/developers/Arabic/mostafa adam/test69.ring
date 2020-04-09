/*
	name	:	Darsh Adam
	Lesson	:	دروس رينج
	Date 	:	18/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================

# Eval 

? "Welcome to ring language"
while true 
	? "code:>" give ccode 
	try 
		eval(ccode)
	catch 
		? ccatcherror
	end 
	? "" 
end 
