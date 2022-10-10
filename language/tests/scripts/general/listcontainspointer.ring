C_RANGERROR = "Can't access the character - outside range"

? "Define a number"
n1 = 12553523

? "Create a pointer to the number"
ptr = varptr("n1",:int)

? "Check the pointer"
? "Is pointer : " + ispointer(ptr)
? "List Size  : " + len(ptr)

? "Get a string using the pointer"
cStr = ptr2str(ptr,0,4)

? "String Size: " + len(cStr)

? "Print the ASCII code for each character"
for c in cStr ? ascii(c) next

? "Print character outsize range"
try
	? ptr2str(ptr,0,4)[5]
catch
	? C_RANGERROR
done

? "Print each item in pointer list"
for e in ptr
	if isString(e) and e = ptr[1]
		? "We have a pointer here!"
	else
		? e 			
	ok
next

? "Check the pointer value"
cPtrStr = ptr[1]
? type(cPtrStr)

? "Call function that return a string"
? mystr()			# String (4 Characters)

? "Access character outside range"
try
	? mystr()[5]			
catch
	? C_RANGERROR
done

func mystr
	return "1234"