load "tokenslib.ring"

/*
	checkRingCode() is used for security
	It expected to be called before eval() 
	When the input is just a Ring List 
	It doesn't accept code that contains 
	* Ring Keywords 
	* Specific operators like ( ) { } . ?
	i.e. no statements, function calls or object access 
	Also, no output using ?
*/

func main

	cCode = `mylist = [1,2,3,:one,:two,:three]`
	? checkRingCode([:code = cCode])	// 1 (True)

	cCode = `? "hello world"`
	? checkRingCode([:code = cCode])	// 0 (False)
	? checkRingCode([:code = cCode, :safeoperators="?"])	// 1 (True)


	cCode = `test(1)`
	? checkRingCode([:code = cCode])	// 0 (False)
	? checkRingCode([:code = cCode, :safeoperators="()"])	// 1 (True)

	cCode = `myobj { x=10 }`
	? checkRingCode([:code = cCode])	// 0 (False)
	? checkRingCode([:code = cCode, :safeoperators="{}"])	// 1 (True)

	cCode = `see 'hi'`
	? checkRingCode([:code = cCode])	// 0 (False)
