/*  
 **      Application : Functions & scope & pass by value & pass by reference
 **      Author      : Abdelrahman Adam
 **      Date        : 22/12/2017 
*/ 
#======================================================

func main
		aList=1:10
		test(aList)
		? aList

func test  aList
		aList[1]= :one
