/*
**	Application:control file in another file
**	Author	   :Sara Abozeina
**	Date       :2017.12.25
*/
Load "stdlib.ring"
$nLines = []
eval("? 'Enter the name of file you want read it   : ' Give $name       ")
eval("? 'Enter the name of file you want copy to it: ' Give $newfilename")
func main
	n=0
	fp = fopen($name,"r")
	while not feof(fp) 
		Lines = Readline(fp) 
		$nLines + Lines
		n++
		if n=29  exit ok
	end
	fclose(fp)
	$nLines[2] = "**	Application: pass by values in list"
	$nLines[1] = "/*"  # eval line replaced by /*
 	?$nLines

	editfile() copyfile($nLines)

	func editfile
		$nLines[2] = "**	Application: pass by values in list"
		$nLines[1] = "/*"  #eval line replaced by /*
	
	
	func copyfile $nLines		
	return  write($newfilename,list2str($nLines))
