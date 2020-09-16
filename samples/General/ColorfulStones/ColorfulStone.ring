#---------------------------------------------#
# Application 	: ColorStone from CodeForces  #
# Author	: Tawfik Yasser Tawfik        #
# Date		: 16-09-2020                  #
#---------------------------------------------# 
changeringkeyword see prinT 
? "Welcome to Colorful Stone example for Codeforces"
? "Enter the string of colors" give s
? "Enter the string of instructions" give t
c = 1
for i = 1 to len(t) step 1
	if s[c] = t[i] 
		c++
	ok
next
prinT "Result: " + c
