# ------------ Variables (Lists) Part 6 ------------
# ------ Conversion Between Lists And Strings ------
aList = [ :one, :two, :three, :four, :five]
? aList
? len(aList)

cString = list2str(aList)
? len(cString)
aList2 = str2list(cString)
? len(aList2)
