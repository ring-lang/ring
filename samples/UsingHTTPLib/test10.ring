load "httplib.ring"
Load "openssllib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/hash"
oServer.route(:Get,"/hash",:hash)
oServer.route(:Post,"/hashresponse",:hashresponse)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func hash

	oPage = New HTMLPageFunctions
	{
		boxstart()
			text( "Hash Test")
			newline()
		boxend()
		divstart([:style = StyleFloatLeft() + StyleWidth("100px") ])
			newline()
			text( "Value : " )  	
			newline() newline()
		divend()
		formpost("/hashresponse")
			divstart([:style = StyleFloatLeft() + StyleWidth("300px") ])
				newline()
				textbox([ :name = "Value" ]) 	
				newline() newline()
				submit([ :value = "Send" ])
			divend()
		formend()
	}		
	oServer.setHTMLPage(oPage)

func hashresponse

	oPage = New HTMLPageFunctions
	{
		boxstart()
			text( "Hash Result" )
			newline()
		boxend()
		divstart([:style = styleFloatLeft() + styleWidth("100%") ])
			newline()
			text( "Value : " + oServer["Value"] )  	
			newline()
			text( "MD5 : " + md5(oServer["Value"]) )  	
			newline()
			text( "SHA1 : " + SHA1(oServer["Value"]) )
			newline()
			text( "SHA256 : " + SHA256(oServer["Value"]) )
			newline()
			text( "SHA224 : " + SHA224(oServer["Value"]) )
			newline()
			text( "SHA384 : " + SHA384(oServer["Value"]) )
			newline()
			text( "SHA512 : " + SHA512(oServer["Value"]) )
			newline()
		divend()
	}	

	oServer.setHTMLPage(oPage)
