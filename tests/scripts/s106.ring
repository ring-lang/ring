for x = 1 to len(date())
	see date()[x]	 
next

see nl

for x = 1 to len("hello world")
	see "hello world"[x] + nl
next

see nl

if isstring("wow") see "True" + nl ok
if isnumber(123) see "True" + nl ok
if islist([1,2,3]) see "True" + nl ok

see nl

aList = [
	"mahmoud",
	28,
	["one","two"]
]

for x = 1 to len(aList)
	see type(aList[x]) + nl
next

see read("tests\s106.nova")