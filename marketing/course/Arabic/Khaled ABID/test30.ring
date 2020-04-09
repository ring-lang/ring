/*
	Application	: Course of Essentials
	Author		: Khaled ABID
	Date		: 01/01/2018
*/

# Project   ----> Files (*.ring)
# Program   ----> Statements
# Statement ----> Keywords + Expressions

see "Hello, World!" + nl
# Keyword Expression

# Statement ----> "See" <Expression>
# Statement ----> <Expression>

"Hello, World"
109
# [1,2,3,4]
#==========================================

see "Welcome" + nl
? "Hello"

? "one" + tab + "two" + tab + "three"

? ""
for x=1 to 10
	see cr
	see x
next

? ""
#==========================================

# NL, TAB & CR	-------> Variables
tab=char(9)+char(9)
? "one" + tab + "two" + tab + "three"

nl = windowsnl()	# char(13) + char(10)
cString = "hello" + nl + "how are you?" + nl
write("mytest.txt",cString)
system("notepad mytest.txt")
#==========================================
