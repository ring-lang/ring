/*
	Application	: Trace Library
	Author		: Ahmed Mohamed
	Date		: 23-11-2019
*/

/*
	(1) Desktop
	(2) Web
	(3) Mobile
	(4) Games
*/

/*
	(1) Functions/Methods Scope
	(2) Type Hints
	(3) Trace Library (Debugging)
*/

load "tracelib.ring"

func main
	x = 10
	y = 20
	breakpoint()
	? x + y
