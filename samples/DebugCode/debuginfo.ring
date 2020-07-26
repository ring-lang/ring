cDebugInfo 	= ""
lUseDebugInfo 	= True

for x = 1 to 10
	? "x = " + x + " , (x*x) = " + (x*x)
	DebugInfo("x value = " + x)
	DebugInfo("x*x value = " + (x*x))
next

WriteDebugInfo()

func DebugInfo cText
	if !lUseDebugInfo return ok
	cDebugInfo += cText + WindowsNL()

func WriteDebugInfo
	if !lUseDebugInfo return ok
	write("debug.txt",cDebugInfo)