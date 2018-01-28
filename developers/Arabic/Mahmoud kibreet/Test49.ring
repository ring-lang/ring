/*
          Application : Functions
          Author      : Mahmoud Kibreet
          Date        : 2018.01.27
*/


# Functions - Recursion

func main
	dec(10)


func dec nNum
	? nNum
	if nNum = 0 return ok
	return dec(nNum-1)
