###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           :01.02.2018                  
###################################

/*
		(1) -----Desktop 
		(2) -----Web 
		(3) -----Mobile 
		(4) -----Games 
*/

/*
	(1)------Functions/Methods Scope 
	(2) -----Type Hints 
	(3)----- Trace Library (Debugging) 
*/

load "typehints.ring"

? sum(3,4)

number func sum(number x,number y) {
	number nSum = x + y
	return nSum
}
