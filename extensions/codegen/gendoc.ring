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


aList = str2list(cFile)

cOutput = ".. index:: " + windowsnl() 
cOutput += "     single: "+C_CHAPTERNAME+"; Introduction" + windowsnl() + windowsnl()
cOutput += copy("=",len(C_CHAPTERNAME)) + windowsnl()
cOutput += C_CHAPTERNAME + windowsnl()
cOutput += copy("=",len(C_CHAPTERNAME)) + windowsnl() + windowsnl()


for x = 1 to len(aList) 
	cLine = trim(aList[x])
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
	if left(lower(cLine),9)="<comment>"		 
		x++
		do 
			cLine = trim(aList[x])
			x++
		again left(lower(cLine),10) !="</comment>"
		loop
	ok
	avoidblock("code")
	avoidblock("funcstart")
	avoidblock("runcode")
	avoidblock("struct")
	avoidblock("constant")

	avoidline("register")
	avoidline("filter")

	if lStart
		if (cLine != NULL ) and len(cLine) > 1
			cLine = substr(cLine,"@","_")
			cOutput += "* " + cLine + windowsnl()
		ok
	ok
next

write(C_OUTPUTFILE,cOutput)
system(C_OUTPUTFILE)


func avoidblock cStr

	if left(lower(cLine),len(cStr)+2)="<"+cStr +">"		 
		x++
		do 
			cLine = trim(aList[x])
			x++
		again left(lower(cLine),len(cStr)+3) !="</"+cStr+">"
		loop
	ok

func avoidline cStr
	if ( left(lower(cLine),len(cStr)+2)="<"+cStr + ">" ) or ( left(lower(cLine),len(cStr)+3)="</"+cStr + ">"  )
		loop
	ok
