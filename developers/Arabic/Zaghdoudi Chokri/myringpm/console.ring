/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/10
*/

func Titre
	# Si on a une commande on n'affiche pas les Cmds
		if len(aCmds) >= 1 return ok
	Line()
	? "Ring Package Manager (RingPM)"
	? "2109 - Zaghdoudi Chokri"
	Line()

func Line 
	? copy("=",30)

func Cmds
	# Si on a une commande on n'affiche pas les Cmds
		if len(aCmds) >= 1 return ok
	? "Usage  : ringpm  <command>"
	? "Command: install <packagename>"
	? "Command: remove  <packagename>"
	? "Command: list"
