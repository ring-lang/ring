	#o1 = new test
	#o1.self = 0

	new test { f1() } 

	func test x
		x = 0

	class test
		func f1

			# test(Self)

			see "welcome" + nl
			self = 0 # here the bug
			f2()	 # now the crash
		func f2
			see "what!" + nl