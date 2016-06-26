# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

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
