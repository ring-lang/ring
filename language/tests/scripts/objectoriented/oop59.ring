# This test is based on a report written by Ilir Liburn

str = "test"

# replace by /* to get last line printed
? "h in hybrid = new Hybrid(str)"
hybrid = new Hybrid(str)
for h in hybrid
	? h
next
? "------------------"
? h[1] // just h prints NULL, while h[1] prints N ???
? "------------------"
# replace by */ to get last line printed

? "i in lst = [0, 1, 2, 3]"
lst = [0, 1, 2, 3]
for i in lst
? i
i = i + 1
next
? "------------------"
? lst
? lst[1] // unless commented above, prints nothing because of the RetItemByReference
? "------------------"

class Hybrid
	data
	func init val 
		data = val

        func operator cOperator,Para
		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return &data[Para]
		off

