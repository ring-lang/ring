/*
	Application	: nl, tab, cr
	Author		: Ahmed Mohamed
	Date		: 2019/10/15
*/


// Project ---> Files (*.ring)
// Program ---> Statement
// Statement ---> Keyword + Expressions

see "Hello World" + nl
// Keyword Expression

// Statement ---> "see" <Expression>

// Statement ---> <Expression>

"Hello World"
12345

#================================================#

see "Welcome" + nl

? "Hello"

? "One" + tab + "Two" + tab + "Three"

? ""

/*
load "stdlibcore.ring"
for x = 1 to 10 see x sleep(1) see cr next
*/


for x = 1 to 10
	see cr
	see x 
next


? ""

#================================================#
# NL, TAB, CR =========> Variables

tab = char(9) + char(9)

? "One" + tab + "Two" + tab + "Three"

nl = windowsnl() # char(15) + char(10)

cString = "Hello" + nl + "How are you" + nl

write("myTest.txt", cString)
system("notepad myTest.txt");
