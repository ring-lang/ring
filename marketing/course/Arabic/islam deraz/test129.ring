/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.31
*/

load "stdlib.ring"

alist = 1:10

alist2 = map(alist , func x {
		return x * x
})

? alist
? alist2	
