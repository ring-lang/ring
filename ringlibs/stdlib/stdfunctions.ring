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
