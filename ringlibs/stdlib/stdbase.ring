# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Class StdBase

	cValue

	Func Init x
		cValue = x

	Func Print
		See cValue

	Func PrintLn
		Print()
		See nl

	Func Size
		return len(cValue)

	Func Value
		return cValue

	Func Set x
		Init(x)
