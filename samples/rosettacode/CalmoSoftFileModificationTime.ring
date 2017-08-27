load "stdlib.ring"
see GetFileInfo( "test.ring" )

func GetFileInfo cFile
     cOutput = systemcmd("dir /T:W " + cFile )
     aList = str2list(cOutput)
     cLine = aList[6]
     aInfo = split(cLine," ")
     return aInfo
