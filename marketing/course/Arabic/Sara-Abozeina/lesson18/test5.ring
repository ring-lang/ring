/*
**	Application:type hints in classes
**	Author	   :Sara Abozeina
**	Date       :2018.01.04
*/
######
/*
to be more readable in large projects
support types for class and function and variables.
support outside functions. and the code inside it { parameters }
need to use "()" around parameters.
*/
######
load "typehints.ring"

	
new person {string msg()}	
new person2{msg()}

int sum(5,6)
func sum (int y,int x){
		sum=y+x ?sum
		return new person 
}	

public Class person
	name="A" age=123 			
	func msg
		?"Hello world!"



Class person2				
	name age job

	public static void func msg
		?"msg from second class!"
