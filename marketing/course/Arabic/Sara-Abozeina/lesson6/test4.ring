/*
**	Application:func scope func 1 can't reach name
**	Author	   :Sara Abozeina
**	Date       :2017.12.24
*/
Load "stdlib.ring"
$nLines=[]
eval("?'Enter the name of file you want read it: 'Give $name")
eval("?'Enter the name of file you want copy to it: 'Give newfilename")
func main
	fp = fopen($name,"r")
	while not feof(fp)
		Lines=Readline(fp) 
		$nLines+Lines
	end
	fclose(fp)
	editfile($nLines) ?$nLines
func editfile $nLines
#the eval command will take a line.
	$nLines[2]="**	Application: pass by reference in list"
	$nLines[1]="/*"  # eval line replaced by /*
	cStrings=list2str($nLines)	
	write(newfilename,cStrings)
