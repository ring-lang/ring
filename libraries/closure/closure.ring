# The Ring Closure Library
# 2026, Mahmoud Fayed <msfclipper@yahoo.com>

CLOSURELIB_TEMPVAR = NULL

func closure aVars, fFunc

	if ! isList(aVars) raise("The first parameter is not a list") ok

	if ! ( isString(fFunc) and isFunction(fFunc) ) 
		raise("The second parameter is not a function")
	ok

    # Create a fresh scope for each closure
    tempclosureObject = new closureObject
	tempclosureObject.fFunc = fFunc 

    # Bind variables into the scope
    for vAttr in aVars
		if isList(vAttr) and len(vAttr)=2
       		addAttribute(tempclosureObject, vAttr[1])
        	setAttribute(tempclosureObject, vAttr[1], vAttr[2])
		but isString(vAttr)
			addAttribute(tempclosureObject, vAttr[1])
			nScope = ringvm_scopescount() - 1
			ringvm_evalinscope(nScope,"CLOSURELIB_TEMPVAR = " + vAttr)
        	setAttribute(tempclosureObject, vAttr, CLOSURELIB_TEMPVAR)
		else 
			raise("Unexpected item in the list of variables")
		ok
    next

    return tempclosureObject

func invoke oClosure return oClosure.invoke()

func isClosure oVar  return isObject(oVar) and className(oVar) = :closureObject

class closureObject
	fFunc 
	func invoke 
		return call { fFunc() }
