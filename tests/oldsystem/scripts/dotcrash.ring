/*
	Bug ID : 192
	Description : Using ..
	Status : Fixed
*/


oObj = new myclass
oObj.myfunc()
cStr = "oObj..myfunc()"
eval(cStr)
$objectname = "oObj"
cStr = $objectname+"..myfunc()"
eval(cStr)
class myclass
	func myfunc
		see "welcome" + nl