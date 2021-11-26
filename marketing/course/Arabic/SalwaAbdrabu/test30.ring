/*
	Application : Object
	Author      : Salwa Abdrabu
*/

# Variables Type( String, Number, List, Object, C Object )

# Project    ---> Fileslist()
# Program    ---> Statements
# Statements -->  Keywords + Expression

see      "Hello World!"
# Keyword  Expression 

# Statement ----> 'See' <Expression>
# Statement ---->       <Expression>

"Hello World!"
12
1:10

#=======================================================

see "Welcome" + nl
? "Hello"

? "One" + Tab + "Two" + Tab + "Three"
/*
load "stdlibcore.ring"
for x = 1 to 10 
see x
sleep(1)
see cr
next
*/
for x=1 to 10
	see cr
	see x
next
? ""
#========================================================

# NL , Tab & Cr  -----> variables 
Tab = char(9) + char(9)
? "One" + Tab + "Two" + Tab + "Three"

// nl = windowsnl()     # chr(13) + char(10)
cString = "Hello" + nl + "How Are You?" + nl
write("myTest.txt",cString)
system("notepad mytest.txt")
 
