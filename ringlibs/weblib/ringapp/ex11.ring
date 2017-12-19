#!ring -cgi

Load "weblib.ring"
Import System.Web

New Page 
{
	boxstart()
		text( "Cookies Values" )
		newline()
	boxend()
	link([ :url = "ex10.ring", :title = "back" ]) 			
	newline() 
	divstart([:style="float:left;width:200px"])
		text( "Name : " + aPageVars["custname"] )
		newline()
		text( "Age : " + aPageVars["custage"] )
		newline()
	divend()
}	
