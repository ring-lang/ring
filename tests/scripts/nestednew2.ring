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
		#see "welcome" + nl
		see x

Class point
	pObject
	x=10 y=20 
	func init p1
		pObject = GetObjectPointerFromRingObject(p1)
		see pObject
		#p1.one()
		#two()
		return self

	func two
		see "two" + nl

class point3d
	pObject
	x=30 y=40 z=50
	func init v
		pObject = GetObjectPointerFromRingObject(v)
		#see "para : " + v + nl
		return self
	func one 
		see "3d" + nl