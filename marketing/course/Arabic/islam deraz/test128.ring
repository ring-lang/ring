/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.31
*/

load "stdlib.ring"

alist = 1:10

map(alist , func x {
		? x
})

alist2 = filter(alist,func x {
	
	if x % 2 = 0 
		return True
	else
		return False
	ok
})

? alist2	
