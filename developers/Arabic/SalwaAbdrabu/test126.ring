/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

func main 

	? fact(5)       # 5*4*3*2*1
	? fact2(5)

func fact x
	if x = 0 return 1 ok 
	return x * fact(x-1)
	
func fact2 x

	nResult = 1
	for t = x to 1  step -1
		
		nResult *= t		
	next
	? nResult
