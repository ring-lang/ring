ringvm_runcode("? :before test() ? :after")
? :great
? :ilovering

func test
	? :start
	try
		1/0
	catch
		? cCatchError
	done
	? :done
