cStr = "
		class test1
		class test2
		class test3
		o1 = new test1
		o2 = new test2
		o3 = new test3
		see o1
		see o2
		see o3
"

aList = str2list(cStr)
for x in aList
	eval(x)
next