# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	math_class_test()
ok

func math_class_test

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
