/*
**	Application	: Ring lessons - Type Hints .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 26 .
*/

/*
		(1) Desktop
		(2) Web
		(3) Mobile
		(4) Games
*/
/*
		(1) Functions and Methods Scope .
		(2) Type Hints .
		(3) The Trace Library (Debugger) .
*/
load "typehints.ring"

? sum(1,2)

number Func sum(number x,number y) {
	number sum = x + y
	return sum
}
