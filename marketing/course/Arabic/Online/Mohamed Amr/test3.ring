/*
 * Application : Using stdlib
 * Author      : Mohamed Amr Elsayed
 * Date        : 2017-12-20
 */

load "stdlib.ring"

	see "I will use a standard library" + nl

	print("number1:  \n")    number1 = getnumber()
	print("number2:  \n")    number2 = getnumber()
	print("number1 + number2 = \t #{ number1 + number2 }" )

	print("So, what is your name?") name = getstring()
	print("Thanks your name is  #{ name }")
