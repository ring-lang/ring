# Author: Ilir Liburn

str = "test"
lst = [substr("str",2),[0]]
? str[2]
? lst[2][1]
lst[1][2] = "hr"	# Runtime Error
? lst[1][2]
hybrid = new Hybrid(lst)
? hybrid[1][1]

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

