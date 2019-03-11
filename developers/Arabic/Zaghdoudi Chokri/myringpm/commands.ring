/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/10
*/

# Charger les commandes
	load "commands/install.ring"
	load "commands/list.ring"
	load "commands/remove.ring"
func ExecCmds
	# Verifier si on n'a pas de commande
		if len(aCmds) < 1 return ok
	cCommand = lower(trim(aCmds[1]))
	# Exécuter la commande
		switch cCommand
			on "install"
				if len(aCmds) < 2
					? C_ERR_NOPCKGNAME 
					return
				ok
				cPckgName = aCmds[2]
				InstallPckg(cPckgName)
			on "list"
				AffichPckgsInstallE()
			on "remove"
				cPckgName = aCmds[2]
				RemovePckg(cPckgName)
		off
