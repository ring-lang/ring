/*
          Application : Object
          Author      : Mahmoud Kibreet
          Date        : 2018.01.26
*/


# Project   ----> Files (*.ring)
# Program  ----> Statements
# Statement ----> Keywords + Expressions

see "Hello , World!"
# Keyword Expression

# Statement ----> 'See' <Expression>
# Statement ----> <Expression>

"Hello , World!"
12

#===========================================

see "Welcome" + nl
? "Hello"

? "One" + Tab + "Two" + Tab + "Three"

? ""
for x=1 to 10
        see cr
	see x 
next
? ""

#===========================================
# NL , TAB & CR ----> Variables
TAB = CHAr(9)+CHAR(9)
? "One" + Tab + "Two" + Tab + "Three"

//nl=windowsnl()    #char(13)+char(10)
cString = "Hello" + nl + "How are you" + nl
write("mytest.txt",cString)
system("notepad mytest.txt")

#============================================
