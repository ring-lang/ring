/*
	Functions that could be used by the Generated Code
	2022, Mahmoud Fayed
*/

Func GetObjectPointerFromRingObject pObj
     if isobject(pObj)
	if isattribute(pObj,'pObject')
		return pObj.pObject
	else 
		raise('Error, The parameter is not a GUI object!')
	ok
     ok	
     return pObj		
