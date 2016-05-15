# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Class String

	cValue 

	Func Init x
		cValue = x

	Func Lower
		return new string( lower(cValue) )

	Func Upper
		return new string( upper(cValue) )
	
	Func Left x
		return new string( left(cValue,x) )
	
