#!ring -cgi

Load "weblib.ring"
Import System.Web

New page 
{
	boxstart()
		text( "Cookie Test" )
		newline()
	boxend()
	newline()
	link([ :url = "ex11.ring", :title = "Use Cookies" ]) 	
	cookie("custname","Mahmoud Fayed")
	cookie("custage",28)	
}
 
