/*
**	Application:func scope -$name is global
**	Author	   :Sara Abozeina
**	Date       :2017.12.24
*/
Load "stdlib.ring"

	eval("Give $name")
	readfile()

func readfile
	fp = fopen($name,"r")
	while not feof(fp)
		See Readline(fp) 
	end
	fclose(fp)


