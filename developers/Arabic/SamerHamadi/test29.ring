/*
**	Application    : Object
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

# project ----> files (*.ring)
# program ----> statements
# statement --> Keywords + Expressions

see "Hello, world!" + nl
# Keyword Expression

# statement ----> 'see' <Expression>
# statement ----> <Expression>

"Hello, World!"
12

#=============================================

see "Welcome" + nl
? "Hello"

? "one" +tab+ "two" +tab+ "three" 

? ""
for x=1 to 10
	see cr
	see x
next
? ""

#=============================================
# NL, TAB & CR ----> Variables
TAB = char(9)+char(9)
? "one" +tab+ "two" +tab+ "three"

nl= windowsnl()		#char(13) + char(10)
cString = "Hello" + nl +"how are you" + nl
write("mytest.txt",cString)
system("notepad mytest.txt")

