C_LINESIZE = 40

cFile = read("ringo/app.ringo")

aList = ringvm_ringolists(cFile)

? copy("=",C_LINESIZE)
? "List Size: " + len(aList)
? copy("=",C_LINESIZE)
? "Files count: " + len(aList[1])
? "Functions count: " + len(aList[2])
? "Classes count: " + len(aList[3])
? "Packages count: " + len(aList[4])
? "Instructions count: " + len(aList[5])
? copy("=",C_LINESIZE)
