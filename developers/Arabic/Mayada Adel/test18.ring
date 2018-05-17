# ------------ Variables (Lists) Part 4 ------------
aList = [
	:name = "Mayada",
	:Job  = "Programmer"
]
# It Do The Same Result As aList2
aList2 = [
	["name", "Mayada"],
	["Job",  "Programmer"]
]
? aList
? aList2

? aList[:name]
? aList[:Job]
if aList[:city] = Null aList[:city] = "Cairo" ok
? aList[:city] 

