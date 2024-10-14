/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.31
*/

load "stdlib.ring"
alist = 1:10
test(value(alist))
? alist


func test alist	
	for x = 1 to len(alist)
		alist[x] = alist[x] + 1
	next	
