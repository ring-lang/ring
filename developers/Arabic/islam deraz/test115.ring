/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.31
*/

new counter {
	first count  1 5
	second count 10 15 
	count 
		20
		25

}

class counter

	count 
	
	ncountcmd = 0
	nstart    = 0
	nend      = 0
	func getcount 
		if ncountcmd = 0
			ncountcmd++
		ok

	func braceexpreval value
		if ncountcmd = 1 and isnumber(value)
			nstart = value
			ncountcmd++
		but ncountcmd = 2 and isnumber(value)
			nend = value
			ncountcmd = 0
			counter()
		ok

	func counter

		for x= nstart to nend
			? x
		next	

	func braceerror	
	

