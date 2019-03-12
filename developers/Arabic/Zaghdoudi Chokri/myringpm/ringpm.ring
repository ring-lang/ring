/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/05
*/

# Charger les bibliotheques
	load "stdlibcore.ring"
	load "internetlib.ring" # Telecharge auto la bib. libcurl.ring

	# Télécharger les fichiers de l'application
		load "globals.ring"
		load "console.ring"
		load "getparams.ring"
		load "commands.ring"

	func Main
		aCmds = GetParams("ringpm")
		Titre()
		Cmds()
		ExecCmds()
