cStr = ""
for x = 34 to 300
	cStr+= "func f" + x + char(13) + char(10)
next 
write("test.txt",cstr)