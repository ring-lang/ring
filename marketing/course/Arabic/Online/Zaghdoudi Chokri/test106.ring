/**
 * Application Ring learning
 * Autheur     : Zaghdoudi Chokri
 * Date        : 01/09/2020
*/
# =====================================

# Natural
/*
	Ring 
		Natural
		Declaratives (Nested Structure)
		OOP Functional
*/

? "Bienvenue!" give message

new Natural{
	cMsg = message
	eval(cMsg)
}

class Natural

	bonjour comment vas tu
	nCommentVastu = 0

	func getBonjour
		? "Bonjour Le Monde!"
	func getComment 
		if nCommentVastu = 0 nCommentVastu++ ok
	func getVas
		if nCommentVastu = 1 
			nCommentVastu++
		ok

	func getTu
		if nCommentVastu = 2 
			nCommentVastu = 0
			? "Je vais bien merci"
		ok
	func braceError
		if cErr ? cErr ok
