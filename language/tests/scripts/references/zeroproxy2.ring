# Author: Ilir Liburn

test()

func test
        aList = [ref(aList)]

        aZList = ZProxy(aList)
       	aList + ref(aList)
        ? aList

func ZProxy vValue
	if isList(vValue)
		return new ZeroProxyList(vValue)
	else
		throw("ZProxy requires List!");
	ok

class ZeroProxyList

	ZB_aItems = []

	func init(aList) 
		ZB_aItems = ref(aList) 

