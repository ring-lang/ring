# Create a class that define keywords like async and await

load "stdlibcore.ring"

new reactive {
	async func { ? "one" }
	await func { ? "two" }
	async f1 func { ? "test1"} 
}

class reactive

	async   await  cKeywordBeforeFunction  cIdentifier = NULL

	func getAsync
		cKeywordBeforeFunction = :async

	func getAwait
		cKeywordBeforeFunction = :await

	func braceExprEval vExpr

		if isString(vExpr) and startsWith(vExpr,"_ring_anonymous_func_")
			? "We have anonymous function"
			? "After " + cKeywordBeforeFunction
			if cIdentifier
				? "Name: " + cIdentifier
				cIdentifier = NULL
			ok
		ok
	
	func braceError 
		cError =  cCatchError
		if startsWith(cError,"Error (R24) : Using uninitialized variable:")
			cIdentifier = substr(cError,44)
		ok	
