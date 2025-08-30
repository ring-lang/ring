/*
**        Name: RingFmt Tool
**      Author: Mahmoud Fayed
** Prototyping: Bert Mariani & Azzeddine Remmal
*/ 

load "stdlibcore.ring"
load "tokenslib.ring"

func main

	aPara	   = AppArguments()

	nParaCount = len(aPara)
	if ! nParaCount showHelp() return ok

	processArguments(aPara)

func processArguments aPara 

	for cArg in aPara 
		if fexists(cArg)
			processFile(cArg)
		else 
			? "Unknown argument: " + cArg
		ok
	next  

func processFile cFileName
	
	? "Process file: " + cFileName

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
