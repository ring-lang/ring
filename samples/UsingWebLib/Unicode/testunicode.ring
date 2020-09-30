#!ring -cgi
load "weblib.ring"
import system.web

new page {
	text(" Hello World ")
	text( hex2str("e29da4" ) )
	html("&#x2764;")
}
