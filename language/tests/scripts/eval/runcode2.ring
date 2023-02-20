ringvm_runcode("? :before test() ? :after")
? :great
? :ilovering

func test
	? :start
	try
		eval( "vvvv")
	catch
		? cCatchError
	done
	? :done
