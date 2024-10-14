/*
	name 		: Mostafa Abdullah Adam 
	App 		: Test 26 (List Functions) 
	Date 		: 2017-12-13 
*/ 
#=======================================================
     // Variables types (string , number, list , obj , c obj )
#=======================================================

		#===============================#
#  		           ( Lists ) 
		      #==================#
alist = 1:10
	? alist 
del(alist,5)
	? alist
alist + "egypt"
alist + "Ksa"
alist + "Wardan"
? "Wardan position : " + find(alist,"Wardan")

//------------------------------------------------------
alist = [
	["Darh"		,100],
	["Abdo"		,200],
	["Mahmoud"	,300],
	["Fayed"	,400]
]
	#  ? alist
//? find(alist,"Fayed",1)
? alist[find(alist,"Fayed",1)][2]



#========================= End Of Lesson 17 =============


	   		/* End of program */	
##======================================================##
