t1 = clock()

c = copy("A", 1000000)
for i = 1 to 2000 
	n = myfunc(c, i) 
next

s = "few characters"
for i = 1 to 1000000 
	n = myfunc(s, i) 
next

t2 = clock() 

if (t2-t1)/clockspersecond() < 1
	? "PASS"
else
	? "FAIL"
ok

func myfunc cStr, nPos
	return substr(cStr, nPos, 1)
