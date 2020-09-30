#---------------------------------------------#
# Application 	: ColorStone from CodeForces  #
# Author	: Tawfik Yasser Tawfik        #
# Date		: 16-09-2020                  #
#---------------------------------------------# 

changeringkeyword see print

? "Welcome to Colorful Stone example for Codeforces"
? "Enter the string of colors"		give s
? "Enter the string of instructions"	give t

c = 1
for i = 1 to len(t)
	if s[c] = t[i] 
		c++
	ok
next

print "Result: " + c