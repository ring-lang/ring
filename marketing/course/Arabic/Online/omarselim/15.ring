
test(func{
? "hi"
}

)
cfunc="test2"
call cfunc()
test2()
FUNC TEST f1
	? "hello"
call 	f1()

func test2
	?"hh"


myfunc=func{
	?"xmen"
}
call myfunc()


myfunc2=func x,y {
	? x*y
}

call myfunc2(3,5)

f3= myt()
? f3
call f3()
func myt
	return func {
	? "welcome"

}









func main  

	alist =1:9

	my(alist)


func my alist
	alist2=alist
	alist2[1]="one"
	? alist2
