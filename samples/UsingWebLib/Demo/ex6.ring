#!ring -cgi

Load "weblib.ring"
Import System.Web
New Page 
{
	boxstart()
		text( "Post Test")
	 	newline()
	boxend()
	divstart([:style=StyleFloatLeft()+StyleWidth("100px") ])
		newline()
		text( "Number1 : " )  	newline() newline()
		text( "Number2 : " ) 	newline() newline()
	divend()
	formpost("ex7.ring")
		divstart([ :style = styleFloatLeft()+StyleWidth("200px") ])
			newline()
			textbox([ :name = "Number1" ]) 	newline() newline()
			textbox([ :name = "Number2" ]) 	newline() newline()
			submit([ :value = "Send" ] )
		divend()
	formend()
}		
