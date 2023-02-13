for t=1 to 10
	test()
	? copy("=",60)
next

func test
	? :start
	try
		? :before
		test2()
		? :after
	catch
		? cCatchError
	done
	? :done

func test2
	justaname	# Produce Error