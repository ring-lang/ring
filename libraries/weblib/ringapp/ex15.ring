#!ring -cgi

Load "weblib.ring"
Import System.Web

New Page 
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
	formpost("ex16.ring")
		divstart([:style = StyleFloatLeft() + StyleWidth("300px") ])
			newline()
			textbox([ :name = "Value" ]) 	
			newline() newline()
			submit([ :value = "Send" ])
		divend()
	formend()
}
