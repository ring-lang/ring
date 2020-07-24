? "We can compare between numbers and strings!"
see '? 0 = "0" ---> '
see 0 = "0" 
if 0 = "0" 
	? " (True)" 
ok
? "We can't compare between other different types!"
try
	? 0 = [0]
catch
	? '? 0 = [0] is not allowed!'
done
try
	? "0" = []
catch
	? '? "0" = [] is not allowed!'
done 
