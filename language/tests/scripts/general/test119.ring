load "general/filenameinclassregion2.ring"

myobj = new test

if right(myobj.cFile, len("filenameinclassregion2.ring") ) = "filenameinclassregion2.ring"
	? "True"
else
	? "False"
ok