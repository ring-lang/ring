/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.04.14
*/

/*

	Variables Scope 
		Three scopes
			[1] Global scope
			[2] Object scope
			[3] Local scope	

*/

# Conflict between Global variable and local variable
# The Second  way is special mark with global variables
# $globla g_


x=10 y=20		# x,y are global  variables
$nSum= x+y		# nSum is global varaible
? sum(5,6)
? $nSum

func sum x,y		# x,y are global variables
	nSum = x+y	# nSum is expecteed to be local !
	return nSum


