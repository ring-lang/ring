load "stdlib.ring"

new point {
	x=10 y=20 z=30
	test()
	see "mmm..." + NL
}

class point x y z
	func braceerror
		see "Handle Error!" + nl
		SEE "Message :" + cCatchError + nl
		see self
		see "Done" + NL