Load "foxring.ring"


mf = new frFunctions

?mf.frAbs(-45)      
?mf.frAbs(10-30)    
?mf.frAbs(30-10)    

lcNumber1 = 40
lcNumber2 = 2

?mf.frAbs(lcNumber2-lcNumber1)  




lcCompletFileName = "C:\ring\docs\source\contribute.txt"

?mf.frFile(lcCompletFileName, Null)
if mf.frFile(lcCompletFileName, Null) {
  ?mf.frFileToStr(lcCompletFileName)
else
  ?"File does not exist"
}

lcNewPath = "C:\ring_2\docs\source\"

?mf.frJustExt(lcCompletFileName)
?mf.frJustDrive(lcCompletFileName)
?mf.frJustStem(lcCompletFileName)
?mf.frForcePath(lcCompletFileName, lcNewPath)




?mf.frTransform("    Ring is a good language    ", "@! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!") 
?mf.frAllTrim("    Ring is a good language    ", Null) 

?mf._version

lnValue = 3125.54
?mf.frTransform(lnValue, "@B")+ "Euros"
?mf.frTransform(lnValue, "@C 9999,999,999,999.999")

mf.frSetSeparatorTo(" ")
?mf.frTransform(lnValue, "9999,999,999,999.999")
?mf.frInt(lnValue)

?mf.frForceExt("teste", "dbf")

// Format "@L" Added into frTransform() function
?mf.frTransform("123", "@L 999999")
?mf.frTransform(123, "@L 999999")
