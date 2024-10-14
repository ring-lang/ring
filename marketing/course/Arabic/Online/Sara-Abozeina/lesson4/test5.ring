/*
**	Application:many goto & theend & execute by the numbers of expression
**	Author	   :Sara Abozeina
**	Date       :2017.12.31
*/
Load "stdlib.ring"

New ExecuteLines{ 
goto 0

?"sara"
goto 1
?"sara sara sara"
theend 1
?"again"
execute 1
?"12345"
# execute 2
for x=1 to 5
? x next
# execute 2
?"ok"
}
	

Class addValues
	 n=0  goto=0 theend=0 execute alist=[] 


Class ExecuteLines from addValues
	func getgoto	
		if n=0 n++ ok

	func gettheend	
		if n=1 n++ ok

	func getexecute 
		if n=2 n++ open()  ok	

/*
	func braceexpreval value
		if n=3 n=0
		   nexpr=value  			
		 ok
*/	

	func open 	
		fp = fopen(self.fileName,"r")
			while not feof(fp)
				Lines=Readline(fp) 
				alist=str2list(Lines)										
				for x in alist 
					x=TrimAll(x)
					x=lower(x)
					oString = new string(x) 
					if oString.startswith("goto") and oString.endswith("1") 
							while not feof(fp)
								Lines=Readline(fp)
								alist=str2list(Lines)										
								for x in alist 
									x=TrimAll(x)
									x=lower(x)
									nLines+Lines 
									oString = new string(x)
									if oString.startswith("theend") and oString.endswith("1") 
										
										eval(list2str(nLines))		
										exit 2 
									else  loop
									ok 
								next					
							end
					else loop
						
					ok
				next				
			end
		fclose(fp)
			


private 	
	filename=filename()
	nLines=[] 
