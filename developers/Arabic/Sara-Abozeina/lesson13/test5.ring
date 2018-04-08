/*
**	Application:define lines to be executed
**	Author	   :Sara Abozeina
**	Date       :2017.12.25
*/

Load "stdlib.ring"
$nLines=[]  
eval("?'Enter no of start read line' Give $nStart")
eval("?'Enter no of end read line' Give $nend")
New Natural{
		goto
}
		
Class Natural
	goto
	func getgoto
		n=0 
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



