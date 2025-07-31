load "stdlibcore.ring"

if ! fexists(JustFilePath(EXEFileName()) + "/load/ringregex.ring")
	? "Package: RingRegex is not installed!"
	? "Using: ringpm install ringregex from ringpackages"
	system("ringpm install ringregex from ringpackages")
ok

system("ring HTMLExtract.ring")