// Here we test passing temp. list as parameter
// Then we assign another value to this parameter
// from the called function
// This test program is inspired by SoftanzaLib (Developed by Mansour Ayouni)

func main

	mylist = :In = :Seconds 
	mylist2 = [:In = :Seconds]

	test( :In = :Seconds  )
	test2( mylist  )
	test2( mylist2  )
	? len(mylist2)	# killed by prev. function call

	mylist2 = [:In = :Seconds]
	test2( mylist2[1]  )
	test2( genlist()  )
	v = genlist()
	test2( v )

func test pIn
	? pIn
	? type(pIn)
	pIn = pIn[2]
	? type(pIn)

func test2 pIn
	? copy("*",10)
	? type(pIn)
	pIn = NULL
	? type(pIn)

func genlist
	return :In = :Seconds 
