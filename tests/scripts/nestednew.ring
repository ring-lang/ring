my = new great 
test(my,"wow")

func test pObj,cData
	pObj.good(new point(new point3d(cData)))

Func GetObjectPointerFromRingObject pObj
     if isobject(pObj)
	if isattribute(pObj,'pObject')
		return pObj.pObject
	ok
     ok	
     return pObj		


Class Great
func good x
	see "welcome" + nl

Class point
	pObject
	x y 
	func init p1
		pObject = GetObjectPointerFromRingObject(p1)
		p1.one()
		two()

	func two
		see "two" + nl

class point3d
	pObject
	x y z
	func init v
		pObject = GetObjectPointerFromRingObject(v)
		see "para : " + v + nl
	func one 
		see "3d" + nl