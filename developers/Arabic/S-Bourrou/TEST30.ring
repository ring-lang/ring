# بسم الله الرحمن الرحيم
// this is Lesson5 -  thanks to Mr.MAHMOUD Fayed
/*
  Application:  Object
  Author     :  S.BOURROU
  Date       :  16.12.2017  
*/

load "stdlibcore.ring"

"START" 
788
?"A" + Tab + "B" + Tab + "C" // tab is variable
? ""
for a=1 to 10
see a sleep(1)
see cr # carriage return is variable !
next   
? ""
#==============================================#
TAB = CHAR(9) + CHAR(9)
nl = windowsnl()  # CHAR(13) + CHAR(10)
?"A" + Tab + "B" + Tab + "C"
cStr = "HI!" + nl + "Everyone!" + nl
write("myfile.txt",cStr)
system("notepad,myfile.txt")
