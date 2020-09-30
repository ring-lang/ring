# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	math_class_test()
ok

func math_class_test
	
	oMath = new Math

	See "Test the Math Class Methods" + nl
	See "Sin(0) = " + oMath.sin(0) + nl
	See "Sin(90) radians = " + oMath.sin(90) + nl
	See "Sin(90) degree = " + oMath.sin(90*3.14/180) + nl

	See "Cos(0) = " + oMath.cos(0) + nl
	See "Cos(90) radians = " + oMath.cos(90) + nl
	See "Cos(90) degree = " +oMath. cos(90*3.14/180) + nl

	See "Tan(0) = " + oMath.tan(0) + nl
	See "Tan(90) radians = " + oMath.tan(90) + nl
	See "Tan(90) degree = " + oMath.tan(90*3.14/180) + nl

	See "asin(0) = " + oMath.asin(0) + nl
	See "acos(0) = " + oMath.acos(0) + nl
	See "atan(0) = " + oMath.atan(0) + nl
	See "atan2(1,1) = " +oMath. atan2(1,1) + nl

	See "sinh(0) = " + oMath.sinh(0) + nl
	See "sinh(1) = " + oMath.sinh(1) + nl
	See "cosh(0) = " + oMath.cosh(0) + nl
	See "cosh(1) = " + oMath.cosh(1) + nl
	See "tanh(0) = " + oMath.tanh(0) + nl
	See "tanh(1) = " + oMath.tanh(1) + nl

	See "exp(0) = " + oMath.exp(0) + nl
	See "exp(1) = " + oMath.exp(1) + nl
	See "log(1) = " + oMath.log(1) + nl
	See "log(2) = " + oMath.log(2) + nl
	See "log10(1) = " + oMath.log10(1) + nl
	See "log10(2) = " + oMath.log10(2) + nl
	See "log10(10) = " + oMath.log10(10) + nl

	See "Ceil(1.12) = " + oMath.Ceil(1.12) + nl
	See "Ceil(1.72) = " + oMath.Ceil(1.72) + nl

	See "Floor(1.12) = " + oMath.floor(1.12) + nl
	See "Floor(1.72) = " + oMath.floor(1.72) + nl

	See "fabs(1.12) = " + oMath.fabs(1.12) + nl
	See "fabs(1.72) = " + oMath.fabs(1.72) + nl

	See "pow(2,3) = " + oMath.pow(2,3) + nl

	see "sqrt(16) = " + oMath.sqrt(16) + nl

	for x = 1 to 20
        		see "Random number Max (100) : " + oMath.random(100) + nl
	next

	x = 1.1234567890123
	for d = 0 to 14
	        oMath.decimals(d)
	        see x + nl
	next

	cKey = "hello"

 	h = 0
	for x in cKey
		h = oMath.unsigned(h,ascii(x),"+")
		h = oMath.unsigned(h,oMath.unsigned(h,10,"<<"),"+")
		r = oMath.unsigned(h,6,">>")
		h = oMath.unsigned(h, r,"^")
	next
	h = oMath.unsigned(h,oMath.unsigned(h,3,"<<"),"+")
	h = oMath.unsigned(h,oMath.unsigned(h,11,">>"),"^")
	h = oMath.unsigned(h,oMath.unsigned(h,15,"<<"),"+")

	see "Hash : " + h


Class Math 

	Func sin x
		return std_sin(x)

	Func cos x
		return std_cos(x)

	Func tan x
		return std_tan(x)

	Func asin x
		return std_asin(x)

	Func acos x
		return std_acos(x)

	Func atan x
		return std_atan(x)
	
	Func atan2 x,y
		return std_atan2(x,y)

	Func sinh x
		return std_sinh(x)
	
	Func cosh x
		return std_cosh(x)

	Func tanh x
		return std_tanh(x)

	Func exp x
		return std_exp(x)

	Func log x
		return std_log(x)

	Func log10 x
		return std_log10(x)

	Func ceil x
		return std_ceil(x)

	Func floor x
		return std_floor(x)

	Func fabs x
		return std_fabs(x)

	Func pow x,y
		return std_pow(x,y)

	Func sqrt x
		return std_sqrt(x)

	Func random x
		return std_random(x)

	Func unsigned n1,n2,c
		return std_unsigned(n1,n2,c)

	Func decimals x
		return std_decimals(x)
