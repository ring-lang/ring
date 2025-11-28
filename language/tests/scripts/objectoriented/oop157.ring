new mytest {
	@10, 10 say "Hello, World!"
	@11, 10 say "I Love Programming!"
}

class mytest 

	func braceError 
		? getVarName(cCatchError)

	func getVarName cError 
		if left(cError,11) = "Error (R24)"
			return substr(cError,45)
		ok

	func braceExprEval vValue
		if vValue ? vValue ok