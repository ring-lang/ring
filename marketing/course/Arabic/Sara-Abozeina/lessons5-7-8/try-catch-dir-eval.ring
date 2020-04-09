/*
	Application	:search {name}in specific path
	Author		:Sara Abozeina
	Date		:21/12/2017
*/
Load "stdlib.ring"
while 5  #=1=true
	try
			see "Enter the name  you want to search it :"+Tab  eval("Give cName")   
			see cr	
			?"Enter the path you want to search in it :"+Tab   
			eval("Give cPath" )
			cFiles=dir(cPath)
			if iswindows()
				searchpath=""
				apaths=splitmany(cPath,"/")
				for x in apaths
					searchpath=searchpath+(x+"/")			
					searchdirs=dir(searchpath)
					alist1=[]
					alist2=[]
					for cFile in searchdirs	
							if cFile[2]=1
								alist1+lower(cFile[1])
								msg1="and it is folder"
							else
								npos1=substr(cFile[1],".")
								cStrings=left(cFile[1],npos1-1)
								alist2+lower(cStrings)+lower(cFile[1])
								msg2="and it is file"
							ok	
					next	
					
							if find(alist1,lower(cName))	
								?"the name is found in the path"+tab+searchpath+TAB+msg1
							but find(alist2,lower(cName))	
								?"the name is found in the path"+tab+searchpath+TAB+msg2
							else
								
									?"the file not found in the path"+tab+searchpath		
							ok
				next				
	
			ok
	
	
	catch
		? ccatcherror
		loop
	
	Done
	
end
