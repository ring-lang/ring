/*
**	Application:func scope func 1 can't reach name
**	Author	   :Sara Abozeina
**	Date       :2017.12.24
*/
Load "stdlib.ring"
$nLines=[]
eval("?'Enter the name of file you want read it: 'Give $name")
eval("?'Enter the name of file you want copy to it: 'Give $newfilename")
func main
	fp = fopen($name,"r")
	while not feof(fp)
		Lines=Readline(fp) 
		$nLines+Lines
	end
	fclose(fp)
	$nLines[2]="**	Application: pass by values in list"
	$nLines[1]="/*"  #eval line replaced by /*
	editfile() copyfile($nLines)
 	?$nLines

func editfile
	$nLines[2]="**	Application: pass by values in list"
	$nLines[1]="/*"  #eval line replaced by /*


func copyfile $nLines		
return  write($newfilename,list2str($nLines))
