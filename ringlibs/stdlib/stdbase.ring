# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Class StdBase

	cValue

	Func Init x
		cValue = x

	Func Print
		See cValue
		See nl

	Func Size
		return len(cValue)
	
