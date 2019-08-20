/*
**	Application:goto  execute lines from goto to end of lines
**	Author	   :Sara Abozeina
**	Date       :2017.12.29
*/
Load "stdlib.ring"
##Ever execute will execute the all execute with it##
##the priority of execution depends on the priority of execute##  
New Executelines{ 

for x=1 to 10
	?x
next


goto
?"sara"
theend
execute

for y=11 to 15
	? y 
next


execute
?"soooooo"
execute
}


	#####==========================================#####	
	#when write execute i call goto & end in any place
	#####==========================================#####	
	
Class Executelines
	goto=0 theEnd=0 n=0  nStart=0 nEnd=0 execute=0
	func getexecute
		open()

	#####==========================================#####	
	#search in all the file for start and end indexes
	#####==========================================#####									
	func open 
	fp = fopen(self.fileName,"r")

	while not feof(fp)	
			Lines=Readline(fp)
			n++
			alist=str2list(Lines)										
			for x in alist 
				x=TrimAll(x)
				x=lower(x)
				if x="goto"    nStart=n   ok
				if x="theend"   nEnd=n   ok
			next
				if n=nStart
					while not feof(fp)
						Lines=Readline(fp) 
						n++ 
						nLines+Lines
						alist=str2list(Lines)										
						for x in alist 
						x=TrimAll(x)
						x=lower(x)
						if x="theend"   nEnd=n   ok
						next   
						if n=nEnd
							eval(list2str(nLines))
							exit 2 
						ok
					end
				ok					
				
	end

			fclose(fp)
private 	
	filename=filename()
	alist=[] nLines=[] aindexes=[]
