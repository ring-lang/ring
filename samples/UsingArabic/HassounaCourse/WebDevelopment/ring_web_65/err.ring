#!ring -cgi
load "weblib.ring"

see "Content-type: text/html" + nl + nl 
if aPageVars['err']!=null
	see aPageVars['err']
ok
