/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/05
*/

# Charger les bibliotheques
	load "stdlibcore.ring"
	load "libcurl.ring"
	load "internetlib.ring"

# Dossier du package
	cPckgLocation = "https://raw.githubusercontent.com/zaghtechnologies"
# Les paramétre de notre commandes
	aCmds = []
# Les erreurs
	C_ERR_NOPCKGNAME          = 
		"Erreur(1): No Package Name !"
	C_ERR_NOPCKGINFO          = 
		"Erreur(2): No Package Info !"
	C_ERR_PCKGNEXISTEPAS      = 
		"Erreur(3): Package introuvable !"
	C_ERR_PCKGINFONOTCORRECT  = 
		"Erreur(4): Packageinfo not correct !"
	C_ERR_CANTDOWNLOADPCKFILE = 
		"Impossible de telecharger le fichier du package!"
# Les dossier
	cPckgsFolder = "/packages"
	cPckgUrl = ""

	func Main
		GetParams()
		Titre()
		Instructions()
		ExecInstructions()

	func Titre
		# Si on a une commande on n'affiche pas les instructions
			if len(aCmds) >= 1 return ok
		Line()
		? "Ring Package Manager (RingPM)"
		? "2109 - Zaghdoudi Chokri"
		Line()

	func Line 
		? copy("=",30)

	func Instructions
		# Si on a une commande on n'affiche pas les instructions
			if len(aCmds) >= 1 return ok
		? "Usage  : ringpm  <command>"
		? "Command: install <packagename>"
		? "Command: remove  <packagename>"
		? "Command: list"

	func GetParams
		# sysargv = C:\Ring\bin\ringw.exe & C:/Ring/learning/myringpm/ringpm.ring
			aParams = sysargv
		if len(aParams) > 2
			for x = 3 to len(aParams)
				aCmds + aParams[x]
			next
		ok

	func ExecInstructions
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

	func InstallPckg cPckgName
		? "Installation du package: " + cPckgName
		cPckgUrl 	= cPckgLocation + "/" + cPckgName + "/master/"
		cPckgFileUrl 	= cPckgUrl + "package.ring"
		cPckInfo 	=
		# retourne le contenue du fichier (ici package.ring) 
			DownLoad(cPckgFileUrl)
		cPckInfo = substr(cPckInfo,nl,WindowsNl())
		if substr(cPckInfo,"404")
			? C_ERR_CANTDOWNLOADPCKFILE
			return
		ok
		# Exécute le code du fichier et ammene le tableau (aPckgInfo) de notre 
		# fichier en locale
			try
				eval(cPckInfo)
			catch
				? C_ERR_PCKGINFONOTCORRECT
				return
			done
		if !islocal(:aPckgInfo)
			? C_ERR_NOPCKGINFO 
			return
		ok
		DisplayPckgInfo(aPckgInfo)
		DownloadPckgFile(aPckgInfo,cPckInfo)

	# Récupere notre tableau (aPckgInfo)
	func DisplayPckgInfo aPckgInfo
		? "Nom du Package         : " + aPckgInfo[:name]
		? "Description            : " + aPckgInfo[:description]
		? "Developpeur            : " + aPckgInfo[:developer]
		? "Version                : " + aPckgInfo[:version]
		? "Licence                : " + aPckgInfo[:license]

	func DownloadPckgFile aPckgInfo,cPckInfo
		cCurrDir = CurrentDir()
		# Creation du dossier du package
			chdir("packages")
			OSCreateOpenFolder(aPckgInfo[:folder])
		# Ecrire le fichier du package
			write("package.ring",cPckInfo)
		# Télécharger le fichier du package (test.ring)
			for cFileName in aPckgInfo[:files]
				? "Telechargement du fichier: " + cFileName
				cFileUrl 	= cPckgUrl + cFileName
				cFileContent 	= DownLoad(cFileUrl)
				write(cFileName,cFileContent)
			next
			? "Operation terminee!"
		chdir(cCurrDir)

	func AffichPckgsInstallE
		aFiles 		= ListAllFiles("packages","ring")
		aPckgsInfoFiles = []
		for cFile in aFiles
			if JustFileName(cFile) = "package.ring"
				aPckgsInfoFiles + cFile
			ok
		next
		for cFile in aPckgsInfoFiles
			eval(read(cFile))
			? "Nom du Package: " + aPckgInfo[:name]
		next
		if len(aPckgsInfoFiles) = 0
			? "Acun package nest installe !"
			return
		ok

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
