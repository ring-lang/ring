#!ring -cgi

load "weblib.ring"
import System.Web
new Page
{
	text("Path: ")
	text(sysget("PATH_INFO"))
}
