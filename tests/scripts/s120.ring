great = "welcome "

cCode = "
x = 1
see x+5+NL
func nice
	see great
"

see cCode
eval(cCode)
SEE "NICE WORK!" + nl
see "x value is : " + x + nl
see "call function nice ..." + nl
nice()
