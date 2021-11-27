/*
          Application        :Test30
          Author             :Islam Deraz
          Date               :2018.02.28
          Application Number :1
*/

# project  ----> files (*.ring)
# program ----> statements
# statement ---> keywords + expressions

see "Hello world!" + nl
# keyword + expressions

# statement ----> 'see' <expression>
# statement ----> <expression>

"Hello world"
12

#=======================================

see "Hello world" + nl
? "Hello"

? "one" + tab + "two" + tab + "three"

? "" 
for x=1 to 10
	see cr
	see x 
next
? ""

#=========================================

# NL, tab, cr ----> variables

tab = char(9) + char(9)
? "one" + tab + "two" + tab + "three"

nl = windowsnl()       # char(13)+char(10)
cstring = "Hello" + nl + "How are you" + nl 
write("mytest.txt" ,cstring)
system("notepad mytest.txt")

#==========================================
