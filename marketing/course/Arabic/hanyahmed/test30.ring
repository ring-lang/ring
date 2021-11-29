/*
 * Application       : Object
 * Author            : Hany Ibrahim Ahmed
 * Date              : 22/12/2017
 */
# Variables types (string, number, list, object, c object) 
# Project ----> Files (*.ring)
# program ----> Statements
# Statement --> Keyword + Expressions
 
#=============================================
"hello,world!"
12
#=============================================
see "Welcome" + nl

? "hello"

? "one" + tab + "two" + tab + "three"

? ""
for x=1 to 10
see cr
see x+nl
next
? ""
tab=char(9)+char(9)
? "one" + tab + "two" + tab + "three"
#============================================
nl = windowsnl()
cstring = "hello" + nl + "how are you" + nl
write("mytest.text", cstring)
system("notepade mytest.txt")
