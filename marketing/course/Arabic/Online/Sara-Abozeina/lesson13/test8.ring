/*
**	Application:define lines to be executed {even it is in the comment area}
**	Author	   :Sara Abozeina
**	Date       :2017.12.25
*/
changeringkeyword to _to
Load "stdlib.ring"

$nLines=[]  

new natural{
		 51  52 goto
}
		
Class Natural
	goto   jump=0 n=0 
	func braceexpreval values
		alist+values
	return alist


	func getgoto
		if jump=0 jump=1
		fp = fopen(filename(),"r")
		while not feof(fp)	
			Lines=Readline(fp) 
			n++ 
			if n=alist[1]-1
				while not feof(fp)
					Lines=Readline(fp) 
					$nLines+Lines  n++
					if n=alist[2]
						eval(list2str($nLines))
						exit 2
					 ok
				end
			ok					
		end
		fclose(fp)		
		ok

private
	alist=[]

### i define lines from 42 to 43 to be executed
/*
see "k" 
see"s"
for x=1 to 10
?x next
for y=11 to 15
	? y next
*/

