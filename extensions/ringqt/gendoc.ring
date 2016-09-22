# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2016.09.22

C_OUTPUTFILE = "qtclassesdoc.txt"

cFile = read("qt.cf")
cFile = substr(cFile,windowsnl(),char(10))
aList = str2list(cFile)

cOutput = ".. index:: " + windowsnl() 
cOutput += "     single: RingQt Classes Reference; Introduction" + windowsnl() + windowsnl()
cOutput += "========================" + windowsnl()
cOutput += "RingQt Classes Reference" + windowsnl()
cOutput += "========================" + windowsnl() + windowsnl()

lStart = False
for x = 1 to len(aList) 
	cLine = trim(aList[x])
	if left(lower(cLine),7)="<class>"		 
		lStart = True
		x++
		do 
			cLine = trim(aList[x])
			if left(cLine,5) = "name:"
				cClassName = trim(substr(cLine,6)) + " Class"
				cOutput += Windowsnl() + ".. index::" + windowsnl()  
				cOutput +="	pair: RingQt Classes Reference; "
				cOutput += cClassName + WindowsNl()

				cOutput += windowsnl() + cClassName + windowsnl()
				cOutput += Copy("=",len(cClassName)-1) + windowsnl() + windowsnl()
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
