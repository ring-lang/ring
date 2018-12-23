load "stdlib.ring"

func main
	o1 = new point {
		x=10 y=20 z=30
		TEST
		SEE test
	}


class point x y z
	func braceerror
		see "Handle Error!" + nl
		SEE "Message :" + cCatchError + nl
		if startswith(cCatchError,"Error (R24)") and not isattribute(self,"test")
			see "add attribute" + nl
			addattribute(self,"test")
			test = 10
		ok
		puts("done")
		return 