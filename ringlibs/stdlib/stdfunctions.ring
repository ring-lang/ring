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

