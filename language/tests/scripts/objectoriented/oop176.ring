cFunc = func { ? :test }

try
	call { cFunc() }
catch
	? cCatchError
done

test()

new point {
	test()
}

func test

	try
		call { cFunc() }
	catch
		? cCatchError
	done

class point x y z