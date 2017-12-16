/*
	name	:	Darsh Adam
	Lesson	:	test30.ring
	Date 	:	16/12/2017
*/
#=====================================================


"Hello, world!" 		# لن يؤثر على البرنامج 
25				# exp without order 

#=====================================================

see "Hello, World ! " + nl 
? "Hello" 
? "one" + tab + "Two" + tab + "Three" 
?""

for x=1 to 10 
	see cr
	see x
//	see time()
next 
? "" 
#==================================================
	# NL , Tab , CR ----> Variables
TAB = char(9)+char(9)
? "one" +tab+"two"+tab+"three"
 
NL = Windowsnl()
cstring = " Hello! " + nl + " Darsh " + nl 
write("mytest.txt",cstring)
system("notepad mytest.txt")

#=================End Of Lesson===================#

#=================End Of Program==================#
