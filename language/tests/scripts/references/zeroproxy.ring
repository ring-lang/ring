# Author: Ilir Liburn

load "stdfunctions.ring"

aList = [ref(aList),2,3]
aZList = ZProxy(aList)

for i = 0 to len(aZList)-1
	? aZList[i]
	aZList[i] = 0
next
aList = NULL
for i = 0 to len(aZList)-1
	? aZList[i]
next

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

	func operator(cOperator,vValue)
		result = new ZeroProxyList
		switch cOperator
			on "+"
				if isobject(vValue)
					for t in vValue.vValue
						ZB_aItems + t
					next
				but islist(vValue)
					for t in vValue
						ZB_aItems + t
					next
				ok
			on "[]"  
				return &ZB_aItems[vValue+1]
			on "len"
				return len(ZB_aItems)
      		off
		return result

	func add(Value)
		std_add(ZB_aItems,Value)

	func insert(nPos,Value)
		std_insert(ZB_aItems,nPos,Value)

	func find(Value)
		return std_find(ZB_aItems,Value)-1

	func delete(ind)
		std_del(ZB_aItems,ind+1)

	func Item x
		return ZB_aItems[x+1]

	func First		
		return ZB_aItems[1]

	func Last
		return ZB_aItems[len(ZB_aItems)]

	func Set nIndex,Value
		ZB_aItems[nIndex+1] = value

	func FindinColumn nCol,value
		return std_findincolumn(ZB_aItems,value,nCol+1)-1

	func Sort
		return new ZeroProxyList( std_sort(ZB_aItems) )
	
	func Reverse
		return new ZeroProxyList( std_reverse(ZB_aItems) )

	func swap nItem1,nItem2
		std_swap(ZB_aItems,nItem1+1,nItem2+1)

