/*
**	Application:read all lines from file
**	Author	   :Sara Abozeina
**	Date       :2017.12.24
*/
Load "stdlib.ring"

readlinesfromfile()

func readlinesfromfile
	fp = fopen("tests.ring","r")
	while not feof(fp)
		See Readline(fp) 
	end
	fclose(fp)
