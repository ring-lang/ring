/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/10
*/

func RemovePckg cPckgName
	cCurrDir = CurrentDir()
	# Verifier si on a le package
		cPckgFolder = "packages/"+cPckgName
		if ! fexists(cPckgFolder + "/package.ring")
			? C_ERR_PCKGNEXISTEPAS
			return
		ok
	# Supprimer le package
		? "Supression du package: " + cPckgName
		chdir("packages")
		OSDeleteFolder(cPckgName)
		chdir(cCurrDir)
		? "Suppression terminee!"
