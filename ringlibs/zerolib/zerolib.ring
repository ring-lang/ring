load "stdfunctions.ring"

func Z vValue
	if isString(vValue)
		return new ZeroBasedString(vValue)
	but isList(vValue)
		return new ZeroBasedList(vValue)
	ok

class ZeroBasedList

	ZB_aItems = []

	func init(aList) 
		ZB_aItems = aList 

	func operator(cOperator,vValue)
		result = new ZeroBasedList
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
		return new ZeroBasedList( std_sort(ZB_aItems) )
	
	func Reverse
		return new ZeroBasedList( std_reverse(ZB_aItems) )

	func swap nItem1,nItem2
		std_swap(ZB_aItems,nItem1+1,nItem2+1)


class ZeroBasedString
	ZB_cString = ""
	func init(vValue)
		if isString(vValue)
			ZB_cString = vValue
		but isNumber(vValue)
			ZB_cString = "" + vValue
		else 
			raise("Bad parameter to the init() method in ZeroBasedString class")
		ok
	func operator(cOperator,cValue) 
		result = new ZeroBasedString
		switch cOperator
			on "+"
		  		result.ZB_cString = ZB_cString + Para.ZB_cString
			on "*"
				result.ZB_cString = std_copy(ZB_cString,Para)
			on "[]"
				return ZB_cString[cValue+1]
			on "len"
				return len(ZB_cString)
		off
		return result
	func Lower
		return new ZeroBasedString( std_lower(ZB_cString) )

	func Upper
		return new ZeroBasedString( std_upper(ZB_cString) )

	func Left x
		return new ZeroBasedString( std_left(ZB_cString,x) )

	func Right x
		return new ZeroBasedString( std_right(ZB_cString,x) )

	func Lines
		return std_lines(ZB_cString)

	func Trim
		return new ZeroBasedString( std_trim(ZB_cString) )

	func Copy x
		return new ZeroBasedString( std_copy(ZB_cString,x) )

	func strcmp cStr
		return std_strcmp(ZB_cString,cStr)

	func tolist
		return std_str2list(ZB_cString)

	func tofile cFile
		write(cFile,ZB_cString)

	func mid nPos1,nPos2
		nPos1++
		nPos2++
		return new ZeroBasedString( std_getsubstr(ZB_cString,nPos1,nPos2) )

	func getfrom nPos1
		nPos1++
		return new ZeroBasedString( std_getsubstrfrom(ZB_cString,nPos1) )

	func pos cStr
		return std_substrpos(ZB_cString,cStr)

	func replace cStr1,cStr2,lCase
		if lCase
			return new ZeroBasedString( std_substrreplace(ZB_cString,cStr1,cStr2) )
		else
			return new ZeroBasedString(std_substrreplace_notcasesensitive(ZB_cString,cStr1,cStr2))
		ok

	func Split
		return str2list( substr(ZB_cString," ",nl) )

	func startswith substr
		if std_left(std_trim(ZB_cString) , len(substr)) = substr return 1 else return 0 ok   

	func endswith substr
		if std_right(std_trim(ZB_cString), len(substr)) = substr return 1 else return 0 ok 

