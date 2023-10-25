x = ref(test()) 
? x

func test
	mylist = [1,2,3,ref(mylist)]
	return mylist