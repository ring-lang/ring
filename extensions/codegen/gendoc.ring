# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2016.09.22

#==========   Expect the next input
# C_OUTPUTFILE = "qtclassesdoc.txt"		# Output File Name
# C_CHAPTERNAME = "RingQt Classes Reference"	# Chapter Name
# cFile = read("qt.cf")				# Input File
# lStart = False		# False = Classes Doc.   True = Functions Doc.
# funcAfterClass = func cClassName { return string }     # function to call 
#===============================================

load "stdlibcore.ring"

aList = str2list(cFile)

cOutput = ".. index:: " + windowsnl() 
cOutput += "     single: "+C_CHAPTERNAME+"; Introduction" + windowsnl() + windowsnl()
cOutput += copy("=",len(C_CHAPTERNAME)) + windowsnl()
cOutput += C_CHAPTERNAME + windowsnl()
cOutput += copy("=",len(C_CHAPTERNAME)) + windowsnl() + windowsnl()

cOutput += "
Introduction
============

In this chapter we have a list of the supported functions by this extension "

cOutput += "

Reference
=========

"

process_file(aList)

write(C_OUTPUTFILE,cOutput)
system(C_OUTPUTFILE)


func process_file(aList)

	for x = 1 to len(aList) 
		cLine = trim(aList[x])
		if left(lower(cLine),10)="<loadfile>"		 
			cSubFileName = trim(substr(cLine,11))
			cSubFileText = read(cSubFileName)
			cCurrentDir = currentdir()
			chdir(justfilepath(cSubFileName))
			process_file(str2list(cSubFileText))
			chdir(cCurrentDir)
			loop
		ok
		if left(lower(cLine),7)="<class>"		 
			lStart = True
			x++
			do 
				cLine = trim(aList[x])
				if left(cLine,5) = "name:"
					cClassNameAlone = trim(substr(cLine,6)) 
					cClassName = cClassNameAlone + " Class"
					cOutput += Windowsnl() + ".. index::" + windowsnl()  
					cOutput +="	pair: "+C_CHAPTERNAME+"; "
					cOutput += cClassName + WindowsNl()
	
					cOutput += windowsnl() + cClassName + windowsnl()
					cOutput += Copy("=",len(cClassName)) + windowsnl() + windowsnl()
					if funcAfterClass != NULL
						cOutput += call funcAfterClass(cClassNameAlone)
					ok
				ok
				if left(cLine,7) = "parent:"
					cClassName = trim(substr(cLine,8)) 
					cOutput += windowsnl() + "Parent Class : " + cClassName + WindowsNl() + WindowsNl()
				ok
				if left(cLine,5) = "para:"
					cClassName = trim(substr(cLine,6)) 
					cOutput += windowsnl() + "Parameters : " + cClassName + WindowsNl() + WindowsNl()
				ok
	
				x++
			again left(lower(cLine),8) !="</class>"
			loop
		ok
		aAvoidBlocks = ["comment","code","funcstart","runcode","struct"]
		for cAvoid in aAvoidBlocks
			if left(lower(cLine),len(cAvoid)+2)="<"+cAvoid+">"		 
				x++
				do 
					cLine = trim(aList[x])
					x++
				again left(lower(cLine),len(cAvoid)+3) !="</"+cAvoid+">"
				loop
			ok
		next
		avoidline("constant",cLine)
		avoidline("ignorecpointertype",cLine)
		avoidline("register",cLine)
		avoidline("filter",cLine)
		
		avoidline("/comment",cLine)
		avoidline("/code",cLine)
		avoidline("/runcode",cLine)
		avoidline("/struct",cLine)

		if lStart
			if (cLine != NULL ) and len(cLine) > 1
				cLine = substr(cLine,"@","_")
				cOutput += "* " + cLine + windowsnl()
			ok
		ok
	next
	
func avoidline cStr,cLine
	if ( left(lower(cLine),len(cStr)+2)="<"+cStr + ">" ) or ( left(lower(cLine),len(cStr)+3)="</"+cStr + ">"  )
		loop
	ok
