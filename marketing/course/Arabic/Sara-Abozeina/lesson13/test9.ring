/*
**	Application:define lines to be executed {even it is in the commentation area}
**	Author	   :Sara Abozeina
**	Date       :2017.12.25
*/
changeringkeyword to _to
Load "stdlib.ring"

$nLines=[]  

new natural{
			go= 51  to= 52 execute
}

Class Natural
	go  to execute jump=0 n=0  sure

 
	func setgo value1
		if jump=0 jump++ alist+value1 ok
	func setto value2
		if jump=1 jump++ alist+value2 ok

	func getexecute
		if jump=3  jump=0  ok
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
		
private 
	alist=[] value1=0 value2=0
	

### i define lines from 42 to 43 to be executed
/*
see "k" 
see"s"
for x=1 to 10
?x next
for y=11 to 15
	? y next
*/

