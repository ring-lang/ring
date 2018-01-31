Load "foxring.ring"


mf = new frFunctions

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
