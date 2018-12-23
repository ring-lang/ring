Load "private/weblib.ring"


new test { f1() text("ok")}

func great x
	see "great" + nl	
	return x

Class base
	func mmm
		see "mmm...." + nl


Class test	from base

	cOutput = ""

		Func text x
			see " iam here " + nl
			if isstring(x)
				see " iam here 2" + nl
				see attributes(self)
				cOutput += nl+GetTabs() + htmlspecialchars("wow")
				see " iam here 3 " + nl
				 myhtml(x)
				see " iam here 4 " + nl
				great(3)
				see " iam here 5 " + nl


			but isnumber(x)
				cOutput += nl+GetTabs() + htmlspecialchars(string(x))
			ok

	func myhtml r
			return r

	func f1
		see "hello" + nl
		f2()
		mmm()
		great(3)
		see "how are you" + nl
		f3()

	func f2
		see "f2" + nl


	private

		pVar = 0

		nTabs = 1

		func  f3
			see "f3" + nl

	
		Func TabPush
			nTabs++

		Func TabPOP
			nTabs--

		Func GetTabs
			return copy(char(9),nTabs)

