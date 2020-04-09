/*
	Application	:search {name}in specific path
	Author		:Sara Abozeina
	Date		:21/12/2017
*/

while 5  #=1=true
	Tab=Char(9) #Char(9)+Char(9)+.........
	see "Enter the suitable name  you want to search it :"+Tab  eval("Give cName")   
	see cr	
	?"Enter the path you want to search in it :"   
	eval("Give cPath" )
	cFiles=dir(cPath)
	alist1=[]
	alist2=[]
	for cFile in cFiles	
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
				?"the name is found in that path"+TAB+msg1
			elseif find(alist2,lower(cName))	
				?"the name is found in that path"+TAB+msg2
			else
				
				?"the file not found in that path"		
			end

end
