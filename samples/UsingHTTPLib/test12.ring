load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/lists"
oServer.route(:Get,"/lists",:lists)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func lists

	oPage = New HTMLPageFunctions
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
	oServer.setHTMLPage(oPage)

