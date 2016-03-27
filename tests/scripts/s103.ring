see "Enter string : " give cStr
process (cStr)
see "----------------------------" + nl
process (upper(cStr))

func process cStr
	for x = 1 to len(cStr)
		see x 
		see " - "
		see cStr[x]
		see " - "
		see asci(cStr[x])
		see " - "
		see char( asci(cStr[x]) )
		see nl
	next