# Dependency Injection using the ref()/reference() function

func main

	v1 = new myclass1
	v2 = new myclass2

	oCont = new Cont(v1,v2)

	v1.value = "one"
	v2.value = "two"

	oCont.test()

	V1 = 10
	V2 = 20
	? V1
	? V2

	oCont.test()

class myclass1

	value

	func test 

		? :myclass1

class myclass2

	value

	func test 

		? :myclass2

class cont

	o1
	o2

	func init (myo1,myo2)

		o1 = ref(myo1)
		o2 = ref(myo2)

	func test

		o1.test()
		o2.test()
		? o1.value
		? o2.value

