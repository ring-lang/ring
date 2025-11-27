new mytest {
	replace x with y 
}

class mytest 

	func braceError 
		? getVarName(cCatchError)

	func getVarName cError 
		if left(cError,11) = "Error (R24)"
			return substr(cError,45)
		ok
