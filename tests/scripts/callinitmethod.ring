new ssother {
	see "wow" + nl
	t = new myclass("nice") # { x = 20 }
	see "wow2" + nl
}

Class myclass
	x = 10
	see "wow3" + nl
	func init  r
		see "wow5" + nl
		see "init" + nl + r + nl
		see "wow4" + nl

Class ssother
	func init r
		see "ssother init " + r+ nl