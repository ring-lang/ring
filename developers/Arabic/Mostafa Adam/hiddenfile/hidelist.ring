/*
	name	:	Darsh Adam
	Lesson	:	Hide  2
	Date 	:	25/12/2017
*/

#=====================================================
			# Hide Program
		# "To Hide Rar Files In Jpg Files 
#=====================================================
? currentdir()
afiles = dir(currentdir())
alist = []
	for afile in afiles 
			alist + afile[1]
	next 
		alist = sort(alist)
jpg2 = ""
rar2 = ""
#===============================================
rety()
func files 
	x=1 
	? "#==============================================="
	for ss in alist
		? "("+ x +")" + ss
		x++
	next
	? "#==============================================="
#============================
func rety
files()
? Upper("               To close program priny "+"**Exit**")
?""
? "Pls ! Choose the photo Number"
give cnum
#------------------------------------------
		if cnum = "exit" 
			? "Good Bye "
			bye 
		ok
#------------------------------------------
	nnum = 0 + cnum
	if nnum >0 and nnum <= len(alist)
		sname = alist[nnum]
		? "Your file is : " + sname
		len = len(sname)
		?type(sname)
		post = substr(sname , ".")
		? post 
		nn = len - post
		?type(post)
			if Post != 0
				ddd= substr(sname,post,(nn+1))
				? ddd
		#------------------------------------------
					if ddd != ".jpg"
						? " The File you have choose isn't photo"
						rety()
					ok
		#------------------------------------------
				fff=substr(sname,ddd,"")
				jpg2 = fff
				? " Photo Done " 
				bodo()
			ok 
	else 
		? " Bad Option : File Not Found !" 
		rety()
	ok

?""
#===============================================
#===============================================
func bodo
files()
? "#'''''''''''''''''''''''''''''''''''''''''''#"
? "Pls ! Choose the RarFile Number"
give cnum
#------------------------------------------
		if cnum = "exit" 
			? "Good Bye "
			bye 
		ok
#------------------------------------------
	nnum = 0 + cnum
#	if nnum <= len(alist)
	if nnum >0 and nnum <= len(alist)
		sname = alist[nnum]
		?sname
		len = len(sname)
		?type(sname)
		post = substr(sname , ".")
		? post 
			nn = len - post
		?type(post)
			if Post != 0
				ddd= substr(sname,post,(nn+1))
				? ddd
		#------------------------------------------
					if ddd != ".rar" 
						? " The File you have choose isn't Rar"
						bodo()
					ok
		#------------------------------------------
				fff=substr(sname,ddd,"")
				rar2 = fff
				tota()
			ok 
	else 
		? " Bad Option : File Not Found !" 
		bodo()
	ok
#===============================================
func tota
	darsh = "copy /b "+jpg2+".jpg"+" + "+Rar2+".rar "+"new.jpg"
	if rar2 or jpg2 = "" 
		 ? "Program Dameged"
	else
		write("myhidden2.bat",darsh)  
		system("myhidden2.bat")	
		? "Done"		
		bye 
	ok
