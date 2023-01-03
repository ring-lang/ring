# Application : Folder to qrc
# Create resource file (project.qrc) contains the folder files 

load "stdlibcore.ring"

func main
	aPara = sysargv
	nParaCount = len(aPara)
	if (nParaCount > 2) or ( nParaCount = 2 and aPara[1] != "ring" )
		cMainFile  = aPara[nParaCount]
	else 
		drawline()
		see "Application : Folder 2 qrc " + nl
		see "Author      : 2017-2023, Mahmoud Fayed <msfclipper@yahoo.com>" + nl
		see "Usage       : folder2qrc <MainAppFile.ring>" + nl
		drawline()
		bye
	ok
	
	cMainFile 	= substr(cMainFile,".ring",".ringo")
	cFolder 	= CurrentDir()
	cOutputFile  	= "project.qrc"
	see cFolder + nl
	aList = listallfiles(cFolder,"")
	cText = ""
	
	for cFile in aList 
		if substr(cFile,".git") or substr(cFile,".ring") or
		   substr(cFile,".qrc") or substr(cFile,".exe")  loop ok
		cFile = substr(cFile,len(cFolder)+2)
		see "Add File: " + cFile + nl
		cText += (char(9)+char(9)+"<file>" + cFile + "</file>"+windowsnl())
	next 
	
	cText = "<RCC>" + windowsnl() + char(9) + "<qresource>" + windowsnl() +
		char(9)+char(9)+"<file>" + cMainFile + "</file>"+windowsnl()+
		cText + char(9) + "</qresource>" + windowsnl() +
		"</RCC>" + windowsnl()

	write (cOutputFile,cText)
	
	See "File " + cOutputFile + " created!" + nl
	
func DrawLine 
	see copy("=",70) + nl
