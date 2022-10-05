/*  
 **      Application : Revised version
 **      Author      : Abdelrahman Adam
 **      Date        : 21/12/2017 
*/ 
#======================================================

# test30
see "Hello, World ! " + nL
"Hello , World ! "
2017
? "Welcome"

? "one" + tab + "two" + tab + "three"
? Null
for x = 1 to 10
		 see cr
		 see x   # +nL
		
next
#====================================================

tab = char(9) + char(9)
? "one" + tab + "two" + tab + "three"

nL = windowsnl()			# = char(13) + char(10)
cString = "Hello !" + nL + "How are you?" + nL
write("MyTest.txt", cString )
system("notepad MyTest.txt")
? cString
