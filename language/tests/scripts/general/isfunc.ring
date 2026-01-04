for n=1 to 1000
	eval("func mytest"+n+" ? :test")
next
 
? isfunction(:test)
? isfunction(:test2)
? isfunction(:f1)
? isfunction(:f2)
? isfunction(:f3)

for n=1 to 100
	? isfunction("mytest"+n)
next

for n=990 to 1010
	? isfunction("mytest"+n)
next


func f1
func f2
func test