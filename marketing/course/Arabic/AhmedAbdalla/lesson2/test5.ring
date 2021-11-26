/*
 * Application : strings and number  -version3:  "stdlib.ring"
 * Author      : Ahmed Abdalla
 * Date        : 2017-12-14
 */

load "stdlib.ring"

	see "now, I will use a standard library"+nl
	
	print("number1:  \n")    number1 = getnumber()
	print("number2:  \n")    number2 = getnumber()
	print("number1 + number2=\t #{ number1 + number2 }" )  
	
	print("so, what is your name?") name = getstring()  
	print("thanks #{ name }")

