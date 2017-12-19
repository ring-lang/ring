/*
**	Application Name : TAB NL;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-16;		
*/
for x=1 to 10
	see cr 
	see x 
next

#=============
TAB = CHAR(9) + CHAR(9)
SEE "ONE" + TAB + "TWO"
#=============
NL = windowsnl()   # char(13) + char(10)
cStr = "Hello" + nl + "you are welcome" + nl
write("write.txt", cStr)
system("notepad write.txt")
#=============
