See "Enter string:" give cString

for x in cString
	see hex(asci(x))
next

see nl

see str2hex(cString) + nl

/*
cString = read("tests\mahmoud.jpg")

for x in cString
	if len(x) = 1
		see hex(asci(x))
	ok
next

*/