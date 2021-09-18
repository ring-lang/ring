# This test is based on a report written by Ilir Liburn

str = "test"

? "h in hybrid = new Hybrid(str)"
hybrid = new Hybrid(str)
for h in hybrid
	? h
next
? "------------------"
? h
? len(h)
? "------------------"

? "i in lst = [0, 1, 2, 3]"
lst = [0, 1, 2, 3]
for i in lst
? i
i = i + 1
next
? "------------------"
? lst
? lst[1] 
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

