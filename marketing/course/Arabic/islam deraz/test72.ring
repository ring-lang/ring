/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.13
*/

# eval() and the variable scope

eval(" x=10 ")             # x is global

? x

func main 
	eval(" y=20 ")	   # y is local 
	? y
	test()

func test
	? x
	? y		    # error


