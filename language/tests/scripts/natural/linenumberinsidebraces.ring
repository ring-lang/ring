new myclass {
	10
	20
	30
}

class myclass
	func braceExprEval value
		aCallList = ringvm_callList()
		? Value
		? "At Line: " + aCallList[len(aCallList)-1][7]
		? copy("=",20)