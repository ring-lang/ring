#!b:\ring\bin\ring.exe -cgi

Load "weblib.ring"

Import System.Web

WebPage()
{
        Text("Hello World!")
}