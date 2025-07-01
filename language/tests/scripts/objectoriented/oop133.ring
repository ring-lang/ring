func main 

	o1 = new RetItemValue(1:10) 	for m in o1 m *= 100 next 	? o1.data

	o2 = new RetItemRef(1:10)   	for m in o2 m *= 100 next 	? o2.data

	o3 = new RetItemValue(1:10) 	for m in o3 m *= 100 next 	? o3.data

class RetItemRef

	data  

	func init val 

		data = val

        func operator cOperator,Para

		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return & data[Para]  
		off

 class RetItemValue

	data  

	func init val 

		data = val

        func operator cOperator,Para

		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return data[Para]
		off
