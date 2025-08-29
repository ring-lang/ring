/*
**        Name: RingFmt Tool
**      Author: Mahmoud Fayed
** Prototyping: Bert Mariani & Azzeddine Remmal
*/ 

load "stdlibcore.ring"

func main

	aPara	   = AppArguments()

	nParaCount = len(aPara)
	if ! nParaCount showHelp() return ok

func showhelp

	line ()
	? "RingFmt (Source code formatter and beautifier)"
	line ()
	? "2025, Mahmoud Fayed <msfclipper@yahoo.com>"
	? "Prototyping: Bert Mariani & Azzeddine Remmal"
	line ()
	? "Usage: ringfmt <filename.ring>"
	line ()

func line

	? copy("=",75)
