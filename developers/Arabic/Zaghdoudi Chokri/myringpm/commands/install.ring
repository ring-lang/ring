/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/10
*/
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
	DownloadRelatePckg(aPckgInfo,cPckInfo)

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

func DownloadRelatePckg aPckgInfo,cPckInfo
	for aRelatepckg in aPckgInfo[:relatepcks]
		InstallPckg(aRelatepckg[:name])
	next
