see copy("=",30) + nl
see "Command Line Parameters" + nl
see "Size : " + len(sysargv) + nl
see sysargv
see copy("=",30) + nl
nStart = sysargv[3]
nEnd = sysargv[4]
for x = nStart to nEnd
	see x + nl
next
