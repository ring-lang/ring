#!ring -cgi

Load "weblib.ring"
Import System.Web

New Page 
{
	boxstart()
		text( "URLEncode" )
		newline()
	boxend()
	link([ :url = "ex5.ring?Name="+URLEncode("-*{Mahmoud}*-")+
		      "&Address=Egypt&Phone=123456&Age=28&Notes=Programmer", 
		      :title = "Test URL Encode" ])
}
