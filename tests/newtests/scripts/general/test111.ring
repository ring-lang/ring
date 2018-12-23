func main
	oList = new list([1,2,3])
	? oList.first()
	? oList.last()
	oList[2] =  "two"

Class StdBase

	vValue

	Func Init x
		vValue = x

	Func Print
		See vValue

	Func PrintLn
		Print()
		See nl

	Func Size
		return len(vValue)

	Func Value
		return vValue

	Func Set x
		Init(x)

Class List From StdBase

	vValue  = []

	Func Init x
		if isstring(x) or isnumber(x)
			super.init([x])
		but islist(x)
			super.init(x)
		else
			raise("Error: List Class - Init Method - Bad Parameter")
		ok

	Func Add x
		std_add( vValue , x)

	Func Delete x
		std_del( vValue , x)
			
	Func Item x
		return vValue[x]

	Func First		
		return vValue[1]

	Func Last
		return vValue[len(vValue)]

	Func Set nIndex,Value
		vValue[nIndex] = value

	Func Find value
		return std_find(vValue,value)

	Func FindinColumn nCol,value
		return std_findincolumn(vValue,value,nCol)

	Func Sort
		return new list ( std_sort(vValue) )
	
	Func Reverse
		return new list ( std_reverse(vValue) )

	Func Insert nIndex,Item
		std_insert(vValue,nIndex,Item)	

	Func operator cOperator,Para
		result = new list
		switch cOperator
			on "+"
				if isobject(para)
					for t in Para.vValue
						vValue + t
					next
				but islist(para)
					for t in Para
						vValue + t
					next
				ok
			on "len"
				return len( vValue )
			on "[]"
				return vValue[para]
		off
		return result

	Func swap nItem1,nItem2
		std_swap(vValue,nItem1,nItem2)
