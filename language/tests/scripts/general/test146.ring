# Author: Ilir Liburn

func main

	str = "test"

	hybrid = new Hybrid(str)

	hybrid2 = new Hybrid2(hybrid)
	for h2 in hybrid2
		? h2
	next

	data = hybrid2.value().value()
	? data
	? "Done"

class Hybrid
	data
	func init val 
		data = val

	func value
		return new Hybrid3(data)

        func operator cOperator,Para
		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return &data[Para]
		off


class Hybrid2
	data
	func init val 
		data = val

	func value
		return data

        func operator cOperator,Para
		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return data[Para]
		off

class Hybrid3
	data
	func init val 
		data = val

        func operator cOperator,Para
		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return &data
		off
