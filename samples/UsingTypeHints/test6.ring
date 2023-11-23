load "typehints.ring"

o = new MyNewLib {
	? isGreaterThanTwo(10)
	? isGreaterThanTwo(1)
}

class MyLib {
	boolean func isGreaterThanTwo(int x) {
		if x > 2
			return true
		else
			return false
		ok
	}
}

class MyNewLib < MyLib {
	@override
	boolean func isGreaterThanTwo(int x) {
		? "Using override"
		return x > 2
	}
}