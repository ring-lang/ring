/*
**	Application:define lines of code to be executed in another file
**	Author	   :Sara Abozeina
**	Date       :2017.12.25
*/
Load "stdlib.ring"
$nLines=[]	
eval("?'Enter the name of file you want read it: 'Give $name")
eval("?'Enter the name of file you want copy to it: 'Give $newfilename")
eval("?'Enter no of end line of code' Give $nend")
StartAndEnd($nend)
	func StartAndEnd  $nend
	n=0
	fp = fopen($name,"r")
	while not feof(fp) 
		Lines=Readline(fp) 
		$nLines+Lines	
		n++
		if n=$nend  exit ok
	end
	fclose(fp)
 	?$nLines
	editfile() copyfile($nLines)

	func editfile
		$nLines[2]="**	define start and end lines of code"
		$nLines[1]="/*"  #eval line replaced by /*
	
	
	func copyfile $nLines		
		return  write($newfilename,list2str($nLines))

		
