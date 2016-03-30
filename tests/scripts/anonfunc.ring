test( func x,y {
	see "hello" + nl
	see "Sum : " + (x+y) + nl
	} )

times(3, func { see "hello world" + nl } )

new great { f1() }

func test x
	eval(x+"(4,5)")
	see "wow!" + nl

func times n,x
	for t=1 to n
		eval(x+"()")
	next

Class great
	func f1

		f2( func { see "Message from f1" + nl } )

	func f2 x
		eval(x+"()")
