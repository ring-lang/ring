aData = [
"Welcome to the Ring programming language!",
"123456789 10 11 12 13 14 15 16",
"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
"abcdefghijklmnopqrstuvwxyz",
"!@#$%^&*()_+-/\><~",
"a","1","$","?"," ","%"
]

? "Using Str2Hex() function"
aOutput = []
for cData in aData
	aOutput + str2hex(cData)
next
? aOutput

? "Using Hex2Str() function"
for cData in aOutput
	? hex2str(cData)
next


