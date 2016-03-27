func main

	obj1 = new Rect
	obj1.top = 10
	obj1.left = 10
	obj1.width = 200
	obj1.height = 200
	obj1.show()

	obj2 = obj1
	obj2.top = 5
	obj2.left = 5
	obj2.width = 100
	obj2.height = 50
	obj2.show()

	obj1.show()

	display(obj2)

	see "Object Width : " + width(obj2) + nl

	see "object Height : " + myobj().height + nl

	see "object top : " + myobj2()[2].top + nl

func display obj
	obj.show()

func width obj
	return obj.width

func myobj
	obj1 = new Rect
	obj1.top = 100
	obj1.left = 200
	obj1.width = 300
	obj1.height = 400
	return obj1

func myobj2

	aObjs = [new Rect,new Rect]

	aobjs[1].top = 100
	aobjs[1].left = 200
	aobjs[1].width = 300
	aobjs[1].height = 400

	aobjs[2].top = 500
	aobjs[2].left = 600
	aobjs[2].width = 700
	aobjs[2].height = 800

	return aObjs

Class Rect
	top = 0 left = 0 width = 0 height = 0
	func show
		see "Top : " + top + nl
		see "Left : " + left + nl
		see "Width : " + width + nl
		see "Height : " + height + nl
