# ------------ Variables (Lists) Part 4 ------------
# ------------  Lists Functions Part 1  ------------
aList = 1:10
? aList
del(aList, 5)
? aList
aList + "Egypt"
aList + "KSA"
aList + "France"

? "Egypt Position : " + find(aList, "Egypt")

aList2 = [
	["Mohammed",  100],
	["Mahmoud",  200],
	["Ali",      300],
	["Mazen",    400]
]
? aList2[find(aList2, "Mohammed", 1)][2]
