/*
	Bug ID : 193
	Description : Syntax Error in Sub Files must terminate execution
	Status : Fixed
*/

see "what !" + nl
new myclass

class myclass

	obj = new myclass2
	obj2 = new myclass2

	addfirststep()

	func addfirststep
	
		AddStep(0,[:name = T_GD_FirstStep ,
			      :active = True , 
			      :code = "" , 
			      :interactionid = 5 } ])
		 
	func AddStep n,list

class myclass2