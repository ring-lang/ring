cStr = ""
aList = ["IF","TO","OR","AND","NOT","FOR","NEW","FUNC",
"FROM","NEXT","LOAD","ELSE","SEE","WHILE","OK","CLASS","BREAK","RETURN","BUT",
"END","GIVE","BYE","EXIT","TRY","CATCH","DONE","SWITCH","ON","OTHER","OFF",
"IN","LOOP","PACKAGE","IMPORT","PRIVATE","STEP","DO","AGAIN","CALL"]
for x = 1 to len(aLisT)
	cStr += aList[x]
	cStr += "|"
	cStr += lower(aList[x])
	cStr += "|"
	cStr += aList[x][1]+lower(substr(aList[x],2))
	if x != len(aList)
		cStr += "|"
	ok
next
write("keywords.txt",cStr)