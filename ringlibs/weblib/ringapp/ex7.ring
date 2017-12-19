#!ring -cgi

Load "weblib.ring"
Import System.Web
New Page 
{
	boxstart()
		text( "Post Result" )
		newline()
	boxend()
	divstart([ :style = styleFloatLeft()+styleWidth("200px") ])
		newline()
		text( "Number1 : " + aPageVars["Number1"] )  	
		newline() newline()
		text( "Number2 : " + aPageVars["Number2"] )  	
		newline() newline()
		text( "Sum : " + (0 + aPageVars["Number1"] + aPageVars["Number2"] ) )
		newline()
	divend()		
}	
