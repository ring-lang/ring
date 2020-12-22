func main
	test1(1234567890)
	test2("123456790")
	test1(123456789012345)
	test2("123456789012345")
	
func test1 x
	? "Number to String"
	? "Number: " + x
	? "Number: " + string(x)

func test2 c
	? "String to Number"
	? "String: " + c
	? "Number plus one: " + (number(c)+1)
