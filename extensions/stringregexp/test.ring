? "Loading Library"
load "stringregexp.ring"

//zio=StringRegExp("s","+PUBLISH:0,/a1FgtnpfTdI/deviceA/get,12, hello world\r\n","%*[^:]:%d,%*[^,],%d,%[^\n]","64")   // sscanf "style"  with sscanf , use C style for match or similar (set how many char return in this case 64)
//zio=StringRegExp("p","<title>Hello World</title>","<title>(.*)</title>"."0") // perl style with PCRE
//zio=StringRegExp("p","+PUBLISH:012,/a1FgtnpfTdI/deviceA/get,12, hello world\r\n","12,(.*)","0") // perl style with PCRE
//zio=StringRegExp("p","move(123,12252)","move\(([^)]*)\)","0") // perl style with PCRE
zio=StringRegExp('p','{"timezone":"UTC","serverTime":1644393841460,"rateLimits":','[a-zA-Z0-9_.]+','0') // perl style with PCRE
//zio=StringRegExp("c","mik(ko mi)kko","\((.*)\)"."0")                         // c style  with regex.h
?zio
