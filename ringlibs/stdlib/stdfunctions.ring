# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

# Standard Functions Wrapper
# To be called from classes contains methods with the same name

Func std_upper x
	return upper(x)

Func std_lower x
	return lower(x)

Func std_left cStr,x
	return left(cStr,x)

Func std_right cStr,x
	return right(cStr,x)

Func std_lines cStr
	return lines(cStr)

Func std_trim cStr
	return trim(cStr)

Func std_copy cStr,nCount
	return copy(cStr,nCount)

Func std_strcmp cStr1,cStr2
	return strcmp(cStr1,cStr2)

Func std_str2list cStr
	return str2list(cStr)

Func std_list2str aList
	return list2str(aList)

Func std_getsubstr cStr,nPos1,nPos2
	return substr(cStr,nPos1,nPos2)

Func std_getsubstrfrom cStr,nPos1
	return substr(cStr,nPos1)
	
Func std_substrpos cStr,cSubStr
	return substr(cStr,cSubStr)

Func std_substrreplace cStr,cSubStr1,cSubStr2
	return substr(cStr,cSubStr1,cSubStr2)

Func std_substrreplace_notcasesensitive cStr,cSubStr1,cSubStr2
	return substr(cStr,cSubStr1,cSubStr2,true)

Func std_add aList,vValue
	Add(aList , vValue)

Func std_del aList,nIndex
	Del(aList,nIndex)

Func std_find aList,vValue
	return Find(aList,vValue)

Func std_findincolumn aList,nCol,vValue
	return Find(aList,nCol,vValue)

Func std_sort aList
	return sort(aList)

Func std_reverse aList
	return reverse(aList)

Func std_insert aList,nIndex,Item
	Insert(aList,nIndex,Item)

Func std_sin x
	return sin(x)

