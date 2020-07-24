#!ring -cgi

Load "weblib.ring"
Import System.Web

Func Main
	New Page 
	{	 
		ulstart([])
			for x = 1 to 10
				listart([])
					text(x)
				liend()
			next
		ulend()	 
		list2ul(["one","two","three","four","five"])
		ulstart([])
			for x = 1 to 10
				listart([])
					cFuncName = "btn"+x+"()"
					button([ :onclick = cFuncName , :value = x])
					script(scriptfuncalert(cFuncName,string(x)))
				liend()
			next
		ulend()
	}
