/*
**	Date   : 2020.02.15
**	Author : Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "globals.ring"
load "uilib.ring"
load "scanner.ring"

func main

	oScanner = new Scanner {
		setFileName("hello.ring")
		Start()
		PrintTokens()
	}
