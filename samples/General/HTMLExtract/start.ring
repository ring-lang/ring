load "stdlibcore.ring"

cRingBinFolder = JustFilePath(EXEFileName())
if ! fexists(cRingBinFolder + "/load/ringregex.ring")
	? "Package: RingRegex is not installed!"
	? "Using: ringpm install ringregex from ringpackages"
	# Take in mind if ring/bin is not added to the PATH
		cDir = CurrentDir()
		ChDir(cRingBinFolder)
		System("ringpm install ringregex from ringpackages")
		ChDir(cDir)
ok

System("ring HTMLExtract.ring")