/*
**	Application:goto  execute lines of code "lines in the file"
**	Author	   :Sara Abozeina
**	Date       :2017.12.29
*/
changeringkeyword to _to
Load "stdlib.ring"	
$nLines=[] 	
Class defineLines
	goto   jump=0 n=0 
	nStart=0   nEnd=0
changeringkeyword _to to
			
	func getgoto
		if jump=0 jump++ ok
	func BraceExprEval value
		if jump=1 and isNumber(value)
			nStart=value
			jump++

		but jump=2 and isNumber(value)
			nEnd=value
			jump=0
			open()
		ok
		
		func open 
			fp = fopen(self.fileName,"r")
			while not feof(fp)	
				Lines=Readline(fp) 
				n++ 
				if n=nStart-1
					while not feof(fp)
						Lines=Readline(fp) 
						$nLines+Lines  n++
						if n=nEnd
							eval(list2str($nLines))
							exit 2
						 ok
					end
				ok					
			end
			fclose(fp)	
private 	
	filename=filename()


