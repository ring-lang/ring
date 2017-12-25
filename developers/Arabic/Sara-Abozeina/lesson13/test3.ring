/*
**	Application:braceend & bracestrat
**	Author	   :Sara Abozeina
**	Date       :2017.12.25
*/
Load "stdlib.ring"
$nLines=[]	
$name=""

New getstart{ }
		
Class getstart
	
	func braceend
		fp = fopen($name,"r")
		while not feof(fp) 
			Lines=Readline(fp) 
			$nLines+Lines	
		end
		fclose(fp)
 		?$nLines

	func bracestart
		eval("?'Enter the name of file you want read it: 'Give $name")
		eval("?'Enter the name of file you want copy to it: 'Give $newfilename")
		eval("?'Enter no of end line of code' Give $nend")
		
