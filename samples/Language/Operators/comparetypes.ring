? "We can compare between numbers and strings!"
see '? 0 = "0" ---> '
see 0 = "0" 
if 0 = "0" 
	? " (True)" 
ok
? "Comparing between other types return false!"
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
