/*
**	Application:goto  execute lines from goto to end of lines
**	Author	   :Sara Abozeina
**	Date       :2017.12.26
*/
#one execution and every execution take ones before it
#it ignore expression 1
Load "stdlib.ring"
 
New Executelines{ 

for x=1 to 10
	?x
next


goto

?"sara"
theend 1
for y=11 to 15
	? y 
next


?"aaaaaaaaaaa"
execute 1
?"hello in ring"
execute 1
}

	
Class Executelines
	goto theend=0 n=0  Execute=0
	func getgoto
	func gettheend
	func getexecute	
		open()	
												
	func open 
	
		fp = fopen(self.fileName,"r")
			while not feof(fp)
				Lines=Readline(fp)
				oString = new string(Lines)
				if oString.startswith("goto")
					while not feof(fp)
						Lines=Readline(fp)
						nLines+Lines
						oString = new string(Lines)
						if oString.startswith("theend") 
							eval(list2str(nLines))		
							exit 2  					
						ok
					end
				ok				
			end
		fclose(fp)
private 	
	filename=filename()
	nLines=[]
