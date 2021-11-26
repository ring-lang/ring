/*  
 **      Application : Functions recursion
 **      Author      : Abdelrahman Adam
 **      Date        : 22/12/2017 
*/ 
#======================================================

func main
		test(10)


func test    nNum
		? nNum
		if nNum = 0 return   ok
		return test( nNum - 1 )
