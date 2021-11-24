/*
**  Application : Keywords & Expressions
**  Author      : Osama Ballan
**  Date        : 2018 - 01 - 06
*/

# Project   ----->  Files (*.ring)
# Program   ----->  Statements
# Statement ----->  Keywords + Expressions

# Keyword + Expression
see "Hello World !" + nl

# Statement ----->  "see" <Expression>
# Statement ----->        <Expression>
"Hello World .."
12
# ==============================
see "Welcome" + nl
? "Hello"
see "One" + tab + "Two" + tab + "Three" + nl
see "One" + cr  + "Two" + cr  + "Three"

for x=1 to 10
	see cr
	see x
next
see cr
# ==============================
# NL , TAB , CR		------> Built-in variables

TAB = char(9) + char(9)
? "One" + tab + "Two" + tab + "Three"

nl = windowsnl()		# char(13) + char(10)
cString = "Hello" + nl + "How Are You ? " + nl
write("text30.txt" , cString)
system("notepad text30.txt")
