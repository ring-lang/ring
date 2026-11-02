# Running the same call instruction with different function names 
# After the instruction calls a C function (like len()) We try a Ring function

func main
	? "Test 1: Ring function then Ring function"
	test1(:f1)
	test1(:f2)

	? "Test 2: Ring function then C function"
	test2(:f1)
	test2(:len)

	? "Test 3: C function then C function"
	test3(:len)
	test3(:upper)

	? "Test 4: C function then Ring function"
	test4(:len)
	test4(:f1)

	? "Done"

# Each test uses its own function, so each one has its own call instruction

func test1 cName
	? call cName("abc")

func test2 cName
	? call cName("abc")

func test3 cName
	? call cName("abc")

func test4 cName
	? call cName("abc")

func f1 cText
	return "f1() called"

func f2 cText
	return "f2() called"
