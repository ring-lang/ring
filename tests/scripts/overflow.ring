x = "999999999999.11" 
see "size " + len(x) + nl
y = 1 + x
see y + nl

try
x = "9999999999999.11"
see "size " + len(x) + nl
y = 1 + x
catch
	see "Error passed!" + nl
done

x = "99999999999999999999999999"

try
	if x = 10
		see "nice"
	ok
catch
	see "Another error passed!" + nl
done

T = 123456789012.34
SEE T

cCode = "
T = 123456789012.345
SEE T
"

eval(cCode)

see "end of test"