load "typehints.ring"

? isgreaterthantwo(10)
? isgreaterthantwo(1)

o = new mynewlib {
	? isgreaterthantwo(10)
	? isgreaterthantwo(1)
}

boolean func isgreaterthantwo(int x) {
	return x>2
}

class mylib {
	boolean func isgreaterthantwo(int x) {
		if x>2
			return true
		else
			return false
		ok
	}
}

class mynewlib < mylib {
	@override
	boolean func isgreaterthantwo(int x) {
		? "using override"
		return x>2
	}
}