	aList = duplicate( [1,2,3,4,5] )
	see aList[10] + nl

	see mylist()
	
	func duplicate list
		nMax = len(list)
		for x = 1 to nMax
			list + list[x]
		next
		return list

	func mylist return [10,20,30,40,50]