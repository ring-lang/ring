/*
**	Application:type hints in functions
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
to be more readable in large projects
*/
######

load "typehints.ring"

x=1 y=4

int sum(func (int x,int y){? x+y})

func sum f
	call f(x,y)
