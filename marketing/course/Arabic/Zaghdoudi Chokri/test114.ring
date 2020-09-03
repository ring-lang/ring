/**
 * Application Ring learning
 * Autheur     : Zaghdoudi Chokri
 * Date        : 02/09/2020
*/
# =====================================

/*
	Ring 
		Natural
		Declaratives (Nested Structure)
		OOP Functional
*/

# Natural
ChangeRingKeyword       and  _and
ChangeRingOperator	=	is

New App{
# Je veux une fenêtre et le titre de la fenêtre est hello world
	I want window and the window title is "hello world"
}

ChangeRingOperator	is	=

Class App
	# Attributs de l’instruction i want windows
	i want window
	nIwantwindow = 0
	# Attributs de l’instruction Window title
	# Ici, nous ne définissons plus l’attribut de fenêtre
	title
	nWindowTitle = 0
	# Mots-clés à ignorer, il suffit de leur donner n’importe quelle valeur
	the=0  and=0

ChangeRingKeyword	_and	and

	func geti
		if nIwantwindow = 0
			nIwantwindow++
		ok

	func getwant
		if nIwantwindow = 1
			nIwantwindow++
		ok

	func getwindow
		if nIwantwindow = 2
			nIwantwindow= 0
			? "Instruction : I want window"
		ok
		if nWindowTitle = 0
			nWindowTitle++
		ok

	func settitle cValue
		if nWindowTitle = 1
 			nWindowTitle=0
			? "Instruction : Window Title = " + cValue
		ok
