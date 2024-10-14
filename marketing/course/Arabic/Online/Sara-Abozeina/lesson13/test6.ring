/*
**	Application:define lines to be executed {even it is in the comment area}
**	Author	   :Sara Abozeina
**	Date       :2017.12.25
*/

Load "stdlib.ring"
$nLines=[]  
eval("?'Enter no of start read line' Give $nStart")
eval("?'Enter no of end read line' Give $nEnd")
new natural{
		goto
}
		
Class Natural
	goto
	func getgoto
		n=0 
		chdir(currentdir())
		fp = fopen(filename(),"r")
		while not feof(fp)	
			Lines=Readline(fp) 
			n++ 
			if n=$nStart-1
				while not feof(fp)
					Lines=Readline(fp) 
					$nLines+Lines  n++
					if n=$nend
						eval(list2str($nLines))
						exit 2
					 ok
				end
			ok					
		end
		fclose(fp)
 		
	return $nLines

### id define lines from 42 to 43 to be executed
/*
see "k" 
see"s"
for x=1 to 10
?x next
for y=11 to 15
	? y next
*/

